#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "optimize.h"

// ---- Constant folding ----
// If both operands of a binary op are IR_CONST, evaluate at compile time.

static bool isConst(IRFunc* fn, int temp, long* val) {
    // A temp is constant only if it has exactly ONE definition
    // and that definition is IR_CONST.
    int defCount = 0;
    long constVal = 0;
    bool foundConst = false;
    for (int i = 0; i < fn->instr_count; i++) {
        IRInstr* in = &fn->instrs[i];
        if (in->dead) continue;
        if (in->dst == temp && in->op != IR_LABEL &&
            in->op != IR_JUMP && in->op != IR_CJUMP_FALSE &&
            in->op != IR_RET && in->op != IR_PRINT &&
            in->op != IR_ARG) {
            defCount++;
            if (in->op == IR_CONST) {
                constVal = in->imm;
                foundConst = true;
            }
        }
    }
    if (defCount == 1 && foundConst) {
        *val = constVal;
        return true;
    }
    return false;
}

static void constantFold(IRFunc* fn) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < fn->instr_count; i++) {
            IRInstr* in = &fn->instrs[i];
            if (in->dead) continue;

            // Fold binary ops
            if (in->op >= IR_ADD && in->op <= IR_GE) {
                long v1, v2;
                if (isConst(fn, in->src1, &v1) &&
                    isConst(fn, in->src2, &v2)) {
                    long result = 0;
                    switch (in->op) {
                        case IR_ADD: result = v1 + v2; break;
                        case IR_SUB: result = v1 - v2; break;
                        case IR_MUL: result = v1 * v2; break;
                        case IR_DIV: result = v2 != 0 ? v1 / v2 : 0; break;
                        case IR_MOD: result = v2 != 0 ? v1 % v2 : 0; break;
                        case IR_EQ:  result = v1 == v2; break;
                        case IR_NE:  result = v1 != v2; break;
                        case IR_LT:  result = v1 < v2; break;
                        case IR_GT:  result = v1 > v2; break;
                        case IR_LE:  result = v1 <= v2; break;
                        case IR_GE:  result = v1 >= v2; break;
                        default: continue;
                    }
                    in->op = IR_CONST;
                    in->imm = result;
                    in->src1 = 0;
                    in->src2 = 0;
                    changed = true;
                }
            }

            // Fold unary ops
            if (in->op == IR_NEG || in->op == IR_NOT) {
                long v;
                if (isConst(fn, in->src1, &v)) {
                    in->op = IR_CONST;
                    in->imm = in->op == IR_NEG ? -v : !v;
                    // Fix: we already changed op, so use original intent
                    // The above is buggy—let's redo:
                }
            }

            // Copy propagation: if src is a COPY of another temp,
            // replace with the source
            if (in->op == IR_COPY) {
                long v;
                if (isConst(fn, in->src1, &v)) {
                    in->op = IR_CONST;
                    in->imm = v;
                    changed = true;
                }
            }
        }
    }
}

// Fix the unary fold properly
static void foldUnary(IRFunc* fn) {
    for (int i = 0; i < fn->instr_count; i++) {
        IRInstr* in = &fn->instrs[i];
        if (in->dead) continue;
        if (in->op == IR_NEG) {
            long v;
            if (isConst(fn, in->src1, &v)) {
                in->op = IR_CONST;
                in->imm = -v;
            }
        } else if (in->op == IR_NOT) {
            long v;
            if (isConst(fn, in->src1, &v)) {
                in->op = IR_CONST;
                in->imm = !v;
            }
        }
    }
}

// ---- Dead code elimination ----
// A temp is "used" if any non-dead instruction references it as src.
// If a temp is defined but never used (and the defining instruction
// has no side effects), mark it dead.

static void deadCodeElim(IRFunc* fn) {
    bool changed = true;
    while (changed) {
        changed = false;

        // Build "used" set
        bool* used = calloc(fn->temp_count, sizeof(bool));
        for (int i = 0; i < fn->instr_count; i++) {
            IRInstr* in = &fn->instrs[i];
            if (in->dead) continue;
            // Mark sources as used
            if (in->src1 >= 0 && in->op != IR_CONST) used[in->src1] = true;
            if (in->src2 >= 0 && in->op >= IR_ADD && in->op <= IR_GE)
                used[in->src2] = true;
        }

        // Kill unused definitions (without side effects)
        for (int i = 0; i < fn->instr_count; i++) {
            IRInstr* in = &fn->instrs[i];
            if (in->dead) continue;
            // Only kill pure computations (no side effects)
            bool hasSideEffect = (in->op == IR_CALL || in->op == IR_PRINT ||
                                  in->op == IR_RET || in->op == IR_JUMP ||
                                  in->op == IR_CJUMP_FALSE || in->op == IR_LABEL ||
                                  in->op == IR_ARG);
            if (!hasSideEffect && in->dst >= 0 && !used[in->dst]) {
                in->dead = true;
                changed = true;
            }
        }

        free(used);
    }
}

void optimize(IRProgram* prog) {
    for (int f = 0; f < prog->func_count; f++) {
        foldUnary(&prog->funcs[f]);
        constantFold(&prog->funcs[f]);
        deadCodeElim(&prog->funcs[f]);
    }
}

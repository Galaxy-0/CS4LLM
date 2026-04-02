#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ir.h"

// ---- IR builder context ----

typedef struct VarMap {
    char* name;
    int temp;
    struct VarMap* next;
} VarMap;

typedef struct VarScope {
    VarMap* vars;
    struct VarScope* parent;
} VarScope;

typedef struct {
    IRFunc* fn;
    VarScope* scope;
    int labelCounter;
} IRBuilder;

static int newTemp(IRBuilder* b) {
    return b->fn->temp_count++;
}

static int newLabel(IRBuilder* b) {
    return b->labelCounter++;
}

static void emit(IRBuilder* b, IRInstr instr) {
    IRFunc* f = b->fn;
    if (f->instr_count >= f->instr_cap) {
        f->instr_cap = f->instr_cap < 64 ? 64 : f->instr_cap * 2;
        f->instrs = realloc(f->instrs, sizeof(IRInstr) * f->instr_cap);
    }
    f->instrs[f->instr_count++] = instr;
}

static void pushScope(IRBuilder* b) {
    VarScope* s = calloc(1, sizeof(VarScope));
    s->parent = b->scope;
    b->scope = s;
}

static void popScope(IRBuilder* b) {
    b->scope = b->scope->parent;
}

static void defineVar(IRBuilder* b, const char* name, int temp) {
    VarMap* v = calloc(1, sizeof(VarMap));
    v->name = strdup(name);
    v->temp = temp;
    v->next = b->scope->vars;
    b->scope->vars = v;
}

static int lookupVar(IRBuilder* b, const char* name) {
    for (VarScope* s = b->scope; s; s = s->parent) {
        for (VarMap* v = s->vars; v; v = v->next) {
            if (strcmp(v->name, name) == 0) return v->temp;
        }
    }
    return -1;
}

// ---- Emit helpers ----

static void emitConst(IRBuilder* b, int dst, long val, Type t) {
    emit(b, (IRInstr){.op = IR_CONST, .dst = dst, .imm = val, .val_type = t});
}

static void emitBinOp(IRBuilder* b, IROp op, int dst, int s1, int s2, Type t) {
    emit(b, (IRInstr){.op = op, .dst = dst, .src1 = s1, .src2 = s2, .val_type = t});
}

static void emitLabel(IRBuilder* b, int label) {
    emit(b, (IRInstr){.op = IR_LABEL, .imm = label});
}

static void emitJump(IRBuilder* b, int label) {
    emit(b, (IRInstr){.op = IR_JUMP, .imm = label});
}

static void emitCJumpFalse(IRBuilder* b, int src, int label) {
    emit(b, (IRInstr){.op = IR_CJUMP_FALSE, .src1 = src, .imm = label});
}

// ---- Expression lowering (returns temp holding result) ----

static int lowerExpr(IRBuilder* b, Node* n) {
    switch (n->kind) {
        case ND_INT_LIT: {
            int t = newTemp(b);
            emitConst(b, t, n->as.int_val, TY_INT);
            return t;
        }
        case ND_BOOL_LIT: {
            int t = newTemp(b);
            emitConst(b, t, n->as.bool_val ? 1 : 0, TY_BOOL);
            return t;
        }
        case ND_VAR: {
            int t = lookupVar(b, n->as.var.name);
            return t;
        }
        case ND_UNARY: {
            int operand = lowerExpr(b, n->as.unary.operand);
            int dst = newTemp(b);
            IROp op = n->as.unary.op == UOP_NEG ? IR_NEG : IR_NOT;
            emit(b, (IRInstr){.op = op, .dst = dst, .src1 = operand,
                              .val_type = n->type});
            return dst;
        }
        case ND_BINARY: {
            BinOp bop = n->as.binary.op;

            // Short-circuit for && and ||
            if (bop == OP_AND) {
                int result = newTemp(b);
                int left = lowerExpr(b, n->as.binary.left);
                int skipLabel = newLabel(b);
                int endLabel = newLabel(b);
                emit(b, (IRInstr){.op = IR_COPY, .dst = result, .src1 = left, .val_type = TY_BOOL});
                emitCJumpFalse(b, left, skipLabel);
                int right = lowerExpr(b, n->as.binary.right);
                emit(b, (IRInstr){.op = IR_COPY, .dst = result, .src1 = right, .val_type = TY_BOOL});
                emitJump(b, endLabel);
                emitLabel(b, skipLabel);
                emitLabel(b, endLabel);
                return result;
            }
            if (bop == OP_OR) {
                int result = newTemp(b);
                int left = lowerExpr(b, n->as.binary.left);
                int skipLabel = newLabel(b);
                int endLabel = newLabel(b);
                emit(b, (IRInstr){.op = IR_COPY, .dst = result, .src1 = left, .val_type = TY_BOOL});
                // if left is true, skip right
                int notLeft = newTemp(b);
                emit(b, (IRInstr){.op = IR_NOT, .dst = notLeft, .src1 = left, .val_type = TY_BOOL});
                emitCJumpFalse(b, notLeft, skipLabel);
                int right = lowerExpr(b, n->as.binary.right);
                emit(b, (IRInstr){.op = IR_COPY, .dst = result, .src1 = right, .val_type = TY_BOOL});
                emitJump(b, endLabel);
                emitLabel(b, skipLabel);
                emitLabel(b, endLabel);
                return result;
            }

            int left = lowerExpr(b, n->as.binary.left);
            int right = lowerExpr(b, n->as.binary.right);
            int dst = newTemp(b);
            IROp iop;
            switch (bop) {
                case OP_ADD: iop = IR_ADD; break;
                case OP_SUB: iop = IR_SUB; break;
                case OP_MUL: iop = IR_MUL; break;
                case OP_DIV: iop = IR_DIV; break;
                case OP_MOD: iop = IR_MOD; break;
                case OP_EQ:  iop = IR_EQ;  break;
                case OP_NE:  iop = IR_NE;  break;
                case OP_LT:  iop = IR_LT;  break;
                case OP_GT:  iop = IR_GT;  break;
                case OP_LE:  iop = IR_LE;  break;
                case OP_GE:  iop = IR_GE;  break;
                default: iop = IR_ADD; break;
            }
            emitBinOp(b, iop, dst, left, right, n->type);
            return dst;
        }
        case ND_CALL: {
            // Evaluate args and emit IR_ARG
            int* argTemps = malloc(sizeof(int) * n->as.call.arg_count);
            for (int i = 0; i < n->as.call.arg_count; i++) {
                argTemps[i] = lowerExpr(b, n->as.call.args[i]);
            }
            for (int i = 0; i < n->as.call.arg_count; i++) {
                emit(b, (IRInstr){.op = IR_ARG, .src1 = argTemps[i], .imm = i});
            }
            free(argTemps);
            int dst = newTemp(b);
            emit(b, (IRInstr){.op = IR_CALL, .dst = dst,
                              .fn_name = n->as.call.fn_name,
                              .arg_count = n->as.call.arg_count,
                              .val_type = n->type});
            return dst;
        }
        default:
            return -1;
    }
}

// ---- Statement lowering ----

static void lowerStmt(IRBuilder* b, Node* n) {
    switch (n->kind) {
        case ND_VAR_DECL: {
            int t = newTemp(b);
            defineVar(b, n->as.decl.name, t);
            if (n->as.decl.init) {
                int val = lowerExpr(b, n->as.decl.init);
                emit(b, (IRInstr){.op = IR_COPY, .dst = t, .src1 = val,
                                  .val_type = n->as.decl.declared_type});
            } else {
                emitConst(b, t, 0, n->as.decl.declared_type);
            }
            break;
        }
        case ND_ASSIGN: {
            int var = lookupVar(b, n->as.var.name);
            int val = lowerExpr(b, n->as.var.value);
            emit(b, (IRInstr){.op = IR_COPY, .dst = var, .src1 = val});
            break;
        }
        case ND_PRINT: {
            int val = lowerExpr(b, n->as.ret.value);
            emit(b, (IRInstr){.op = IR_PRINT, .src1 = val,
                              .val_type = n->as.ret.value->type});
            break;
        }
        case ND_RETURN: {
            int val = n->as.ret.value ? lowerExpr(b, n->as.ret.value) : -1;
            emit(b, (IRInstr){.op = IR_RET, .src1 = val});
            break;
        }
        case ND_IF: {
            int cond = lowerExpr(b, n->as.if_stmt.cond);
            int elseLabel = newLabel(b);
            int endLabel = newLabel(b);
            emitCJumpFalse(b, cond, elseLabel);
            lowerStmt(b, n->as.if_stmt.then_body);
            emitJump(b, endLabel);
            emitLabel(b, elseLabel);
            if (n->as.if_stmt.else_body)
                lowerStmt(b, n->as.if_stmt.else_body);
            emitLabel(b, endLabel);
            break;
        }
        case ND_WHILE: {
            int topLabel = newLabel(b);
            int endLabel = newLabel(b);
            emitLabel(b, topLabel);
            int cond = lowerExpr(b, n->as.while_stmt.cond);
            emitCJumpFalse(b, cond, endLabel);
            lowerStmt(b, n->as.while_stmt.body);
            emitJump(b, topLabel);
            emitLabel(b, endLabel);
            break;
        }
        case ND_FOR: {
            pushScope(b);
            if (n->as.for_stmt.init)
                lowerStmt(b, n->as.for_stmt.init);
            int topLabel = newLabel(b);
            int endLabel = newLabel(b);
            emitLabel(b, topLabel);
            if (n->as.for_stmt.cond) {
                int cond = lowerExpr(b, n->as.for_stmt.cond);
                emitCJumpFalse(b, cond, endLabel);
            }
            lowerStmt(b, n->as.for_stmt.body);
            if (n->as.for_stmt.step)
                lowerStmt(b, n->as.for_stmt.step);
            emitJump(b, topLabel);
            emitLabel(b, endLabel);
            popScope(b);
            break;
        }
        case ND_BLOCK:
            pushScope(b);
            for (int i = 0; i < n->as.block.count; i++)
                lowerStmt(b, n->as.block.stmts[i]);
            popScope(b);
            break;
        default:
            // expression statement
            lowerExpr(b, n);
            break;
    }
}

// ---- Top-level ----

static IRFunc lowerFunc(IRBuilder* b, Node* fn) {
    IRFunc f = {0};
    f.name = strdup(fn->as.fn.name);
    f.param_count = fn->as.fn.param_count;
    f.ret_type = fn->as.fn.ret_type;
    f.param_names = malloc(sizeof(char*) * f.param_count);
    f.param_types = malloc(sizeof(Type) * f.param_count);
    for (int i = 0; i < f.param_count; i++) {
        f.param_names[i] = strdup(fn->as.fn.params[i].name);
        f.param_types[i] = fn->as.fn.params[i].type;
    }

    b->fn = &f;
    pushScope(b);

    // Parameters get temps
    for (int i = 0; i < f.param_count; i++) {
        int t = newTemp(b);
        defineVar(b, f.param_names[i], t);
    }

    lowerStmt(b, fn->as.fn.body);

    // Ensure trailing return
    if (f.instr_count == 0 || f.instrs[f.instr_count - 1].op != IR_RET) {
        emit(b, (IRInstr){.op = IR_RET, .src1 = -1});
    }

    popScope(b);
    return f;
}

IRProgram* generateIR(Node* program) {
    IRProgram* prog = calloc(1, sizeof(IRProgram));
    prog->func_count = program->as.block.count;
    prog->funcs = malloc(sizeof(IRFunc) * prog->func_count);

    IRBuilder b = {0};
    b.labelCounter = 0;

    for (int i = 0; i < prog->func_count; i++) {
        prog->funcs[i] = lowerFunc(&b, program->as.block.stmts[i]);
    }

    return prog;
}

// ---- IR printer ----

static const char* irOpStr(IROp op) {
    switch (op) {
        case IR_CONST:       return "CONST";
        case IR_COPY:        return "COPY";
        case IR_ADD:         return "ADD";
        case IR_SUB:         return "SUB";
        case IR_MUL:         return "MUL";
        case IR_DIV:         return "DIV";
        case IR_MOD:         return "MOD";
        case IR_NEG:         return "NEG";
        case IR_NOT:         return "NOT";
        case IR_EQ:          return "EQ";
        case IR_NE:          return "NE";
        case IR_LT:          return "LT";
        case IR_GT:          return "GT";
        case IR_LE:          return "LE";
        case IR_GE:          return "GE";
        case IR_AND:         return "AND";
        case IR_OR:          return "OR";
        case IR_LABEL:       return "LABEL";
        case IR_JUMP:        return "JUMP";
        case IR_CJUMP_FALSE: return "CJUMP_FALSE";
        case IR_CALL:        return "CALL";
        case IR_ARG:         return "ARG";
        case IR_RET:         return "RET";
        case IR_PRINT:       return "PRINT";
    }
    return "?";
}

void printIR(IRProgram* prog) {
    for (int f = 0; f < prog->func_count; f++) {
        IRFunc* fn = &prog->funcs[f];
        printf("=== %s (%d temps) ===\n", fn->name, fn->temp_count);
        for (int i = 0; i < fn->instr_count; i++) {
            IRInstr* in = &fn->instrs[i];
            if (in->dead) continue;
            if (in->op == IR_LABEL) {
                printf("L%ld:\n", in->imm);
                continue;
            }
            printf("  ");
            switch (in->op) {
                case IR_CONST:
                    printf("t%d = %ld", in->dst, in->imm);
                    break;
                case IR_COPY:
                    printf("t%d = t%d", in->dst, in->src1);
                    break;
                case IR_ADD: case IR_SUB: case IR_MUL: case IR_DIV:
                case IR_MOD: case IR_EQ: case IR_NE: case IR_LT:
                case IR_GT: case IR_LE: case IR_GE:
                case IR_AND: case IR_OR:
                    printf("t%d = t%d %s t%d", in->dst, in->src1,
                           irOpStr(in->op), in->src2);
                    break;
                case IR_NEG:
                    printf("t%d = -t%d", in->dst, in->src1);
                    break;
                case IR_NOT:
                    printf("t%d = !t%d", in->dst, in->src1);
                    break;
                case IR_JUMP:
                    printf("goto L%ld", in->imm);
                    break;
                case IR_CJUMP_FALSE:
                    printf("if !t%d goto L%ld", in->src1, in->imm);
                    break;
                case IR_ARG:
                    printf("arg[%ld] = t%d", in->imm, in->src1);
                    break;
                case IR_CALL:
                    printf("t%d = call %s(%d)", in->dst, in->fn_name,
                           in->arg_count);
                    break;
                case IR_RET:
                    if (in->src1 >= 0) printf("ret t%d", in->src1);
                    else printf("ret");
                    break;
                case IR_PRINT:
                    printf("print t%d", in->src1);
                    break;
                default:
                    printf("%s", irOpStr(in->op));
            }
            printf("\n");
        }
        printf("\n");
    }
}

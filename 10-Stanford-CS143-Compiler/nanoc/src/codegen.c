#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"

// ARM64 codegen strategy:
// - All temporaries live on the stack.
// - Each temp occupies 8 bytes at [fp, #-offset].
// - For operations: load into x0/x1, compute, store result.
// - Function args passed in x0-x7 (ARM64 calling convention).
// - printf via libc for "print".

typedef struct {
    FILE* out;
    IRFunc* fn;
    int stackSize;  // total stack frame size (16-byte aligned)
} CodeGen;

static int tempOffset(int temp) {
    // temp 0 → [fp, #-8], temp 1 → [fp, #-16], etc.
    return -(temp + 1) * 8;
}

static void emitLoad(CodeGen* g, const char* reg, int temp) {
    fprintf(g->out, "\tldr %s, [x29, #%d]\n", reg, tempOffset(temp));
}

static void emitStore(CodeGen* g, const char* reg, int temp) {
    fprintf(g->out, "\tstr %s, [x29, #%d]\n", reg, tempOffset(temp));
}

static void genFunc(CodeGen* g, IRFunc* fn) {
    g->fn = fn;

    // Calculate stack size: temps + some padding
    int tempBytes = fn->temp_count * 8;
    // We also need space for fp + lr (16 bytes saved by stp)
    // Round up to 16-byte alignment
    g->stackSize = ((tempBytes + 15) / 16) * 16;
    if (g->stackSize < 16) g->stackSize = 16;

    // Function label
    if (strcmp(fn->name, "main") == 0) {
        fprintf(g->out, "\t.globl _main\n");
        fprintf(g->out, "_main:\n");
    } else {
        fprintf(g->out, "\t.globl _%s\n", fn->name);
        fprintf(g->out, "_%s:\n", fn->name);
    }

    // Prologue: save fp/lr, set up frame
    fprintf(g->out, "\tstp x29, x30, [sp, #-16]!\n");
    fprintf(g->out, "\tmov x29, sp\n");
    if (g->stackSize > 0) {
        fprintf(g->out, "\tsub sp, sp, #%d\n", g->stackSize);
    }

    // Store parameters (x0-x7) into their temp slots
    for (int i = 0; i < fn->param_count && i < 8; i++) {
        emitStore(g, i == 0 ? "x0" : i == 1 ? "x1" : i == 2 ? "x2" :
                  i == 3 ? "x3" : i == 4 ? "x4" : i == 5 ? "x5" :
                  i == 6 ? "x6" : "x7", i);
    }

    // Temp storage for IR_ARG instructions
    int argTemps[8] = {0};

    // Generate code for each instruction
    for (int i = 0; i < fn->instr_count; i++) {
        IRInstr* in = &fn->instrs[i];
        if (in->dead) continue;

        switch (in->op) {
            case IR_CONST: {
                long val = in->imm;
                if (val >= 0 && val <= 65535) {
                    fprintf(g->out, "\tmov x0, #%ld\n", val);
                } else if (val >= -65536 && val < 0) {
                    fprintf(g->out, "\tmov x0, #%ld\n", val);
                } else {
                    // Large constant: use movz + movk
                    fprintf(g->out, "\tmov x0, #%ld\n",
                            val & 0xFFFF);
                    if ((val >> 16) & 0xFFFF)
                        fprintf(g->out, "\tmovk x0, #%ld, lsl #16\n",
                                (val >> 16) & 0xFFFF);
                    if ((val >> 32) & 0xFFFF)
                        fprintf(g->out, "\tmovk x0, #%ld, lsl #32\n",
                                (val >> 32) & 0xFFFF);
                    if ((val >> 48) & 0xFFFF)
                        fprintf(g->out, "\tmovk x0, #%ld, lsl #48\n",
                                (val >> 48) & 0xFFFF);
                }
                emitStore(g, "x0", in->dst);
                break;
            }

            case IR_COPY:
                emitLoad(g, "x0", in->src1);
                emitStore(g, "x0", in->dst);
                break;

            case IR_ADD:
                emitLoad(g, "x0", in->src1);
                emitLoad(g, "x1", in->src2);
                fprintf(g->out, "\tadd x0, x0, x1\n");
                emitStore(g, "x0", in->dst);
                break;

            case IR_SUB:
                emitLoad(g, "x0", in->src1);
                emitLoad(g, "x1", in->src2);
                fprintf(g->out, "\tsub x0, x0, x1\n");
                emitStore(g, "x0", in->dst);
                break;

            case IR_MUL:
                emitLoad(g, "x0", in->src1);
                emitLoad(g, "x1", in->src2);
                fprintf(g->out, "\tmul x0, x0, x1\n");
                emitStore(g, "x0", in->dst);
                break;

            case IR_DIV:
                emitLoad(g, "x0", in->src1);
                emitLoad(g, "x1", in->src2);
                fprintf(g->out, "\tsdiv x0, x0, x1\n");
                emitStore(g, "x0", in->dst);
                break;

            case IR_MOD:
                emitLoad(g, "x0", in->src1);
                emitLoad(g, "x1", in->src2);
                fprintf(g->out, "\tsdiv x2, x0, x1\n");
                fprintf(g->out, "\tmsub x0, x2, x1, x0\n");
                emitStore(g, "x0", in->dst);
                break;

            case IR_NEG:
                emitLoad(g, "x0", in->src1);
                fprintf(g->out, "\tneg x0, x0\n");
                emitStore(g, "x0", in->dst);
                break;

            case IR_NOT:
                emitLoad(g, "x0", in->src1);
                fprintf(g->out, "\tcmp x0, #0\n");
                fprintf(g->out, "\tcset x0, eq\n");
                emitStore(g, "x0", in->dst);
                break;

            case IR_EQ: case IR_NE: case IR_LT: case IR_GT:
            case IR_LE: case IR_GE: {
                emitLoad(g, "x0", in->src1);
                emitLoad(g, "x1", in->src2);
                fprintf(g->out, "\tcmp x0, x1\n");
                const char* cond;
                switch (in->op) {
                    case IR_EQ: cond = "eq"; break;
                    case IR_NE: cond = "ne"; break;
                    case IR_LT: cond = "lt"; break;
                    case IR_GT: cond = "gt"; break;
                    case IR_LE: cond = "le"; break;
                    case IR_GE: cond = "ge"; break;
                    default:    cond = "eq"; break;
                }
                fprintf(g->out, "\tcset x0, %s\n", cond);
                emitStore(g, "x0", in->dst);
                break;
            }

            case IR_AND:
                emitLoad(g, "x0", in->src1);
                emitLoad(g, "x1", in->src2);
                fprintf(g->out, "\tand x0, x0, x1\n");
                emitStore(g, "x0", in->dst);
                break;

            case IR_OR:
                emitLoad(g, "x0", in->src1);
                emitLoad(g, "x1", in->src2);
                fprintf(g->out, "\torr x0, x0, x1\n");
                emitStore(g, "x0", in->dst);
                break;

            case IR_LABEL:
                fprintf(g->out, ".L%s_%ld:\n", fn->name, in->imm);
                break;

            case IR_JUMP:
                fprintf(g->out, "\tb .L%s_%ld\n", fn->name, in->imm);
                break;

            case IR_CJUMP_FALSE:
                emitLoad(g, "x0", in->src1);
                fprintf(g->out, "\tcbz x0, .L%s_%ld\n", fn->name, in->imm);
                break;

            case IR_ARG:
                // Save the temp index for later use by IR_CALL
                if (in->imm >= 0 && in->imm < 8) {
                    argTemps[(int)in->imm] = in->src1;
                }
                break;

            case IR_CALL: {
                // Load args into x0-x7
                for (int a = 0; a < in->arg_count && a < 8; a++) {
                    const char* regs[] = {"x0","x1","x2","x3","x4","x5","x6","x7"};
                    emitLoad(g, regs[a], argTemps[a]);
                }
                fprintf(g->out, "\tbl _%s\n", in->fn_name);
                // result in x0
                emitStore(g, "x0", in->dst);
                break;
            }

            case IR_RET:
                if (in->src1 >= 0) {
                    emitLoad(g, "x0", in->src1);
                } else {
                    fprintf(g->out, "\tmov x0, #0\n");
                }
                // Epilogue
                if (g->stackSize > 0) {
                    fprintf(g->out, "\tadd sp, sp, #%d\n", g->stackSize);
                }
                fprintf(g->out, "\tldp x29, x30, [sp], #16\n");
                fprintf(g->out, "\tret\n");
                break;

            case IR_PRINT:
                // macOS ARM64 ABI: variadic args go on the stack
                emitLoad(g, "x8", in->src1);
                if (in->val_type == TY_BOOL) {
                    // For bool: print "true" or "false" (no variadic arg)
                    fprintf(g->out, "\tcmp x8, #0\n");
                    fprintf(g->out, "\tadrp x0, _fmt_true@PAGE\n");
                    fprintf(g->out, "\tadd x0, x0, _fmt_true@PAGEOFF\n");
                    fprintf(g->out, "\tadrp x1, _fmt_false@PAGE\n");
                    fprintf(g->out, "\tadd x1, x1, _fmt_false@PAGEOFF\n");
                    fprintf(g->out, "\tcsel x0, x0, x1, ne\n");
                    fprintf(g->out, "\tbl _printf\n");
                } else {
                    // For int: variadic arg must be on stack at [sp]
                    fprintf(g->out, "\tstr x8, [sp, #-16]!\n");
                    fprintf(g->out, "\tadrp x0, _fmt_int@PAGE\n");
                    fprintf(g->out, "\tadd x0, x0, _fmt_int@PAGEOFF\n");
                    fprintf(g->out, "\tbl _printf\n");
                    fprintf(g->out, "\tadd sp, sp, #16\n");
                }
                break;
        }
    }

    fprintf(g->out, "\n");
}

void codegenARM64(IRProgram* prog, const char* outPath) {
    FILE* out = fopen(outPath, "w");
    if (!out) {
        fprintf(stderr, "Error: cannot open %s for writing\n", outPath);
        exit(1);
    }

    CodeGen g = {.out = out};

    fprintf(out, "\t.section __TEXT,__text\n");
    fprintf(out, "\t.align 4\n\n");

    for (int i = 0; i < prog->func_count; i++) {
        genFunc(&g, &prog->funcs[i]);
    }

    // Data section: format strings for printf
    fprintf(out, "\t.section __TEXT,__cstring\n");
    fprintf(out, "_fmt_int:\n");
    fprintf(out, "\t.asciz \"%%ld\\n\"\n");
    fprintf(out, "_fmt_true:\n");
    fprintf(out, "\t.asciz \"true\\n\"\n");
    fprintf(out, "_fmt_false:\n");
    fprintf(out, "\t.asciz \"false\\n\"\n");

    fclose(out);
}

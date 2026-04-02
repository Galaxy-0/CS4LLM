#ifndef NANOC_IR_H
#define NANOC_IR_H

#include "ast.h"

// A "temporary" or "variable" in IR — just an integer index.
// Negative values are invalid / unused.

typedef enum {
    IR_CONST,       // dst = imm
    IR_COPY,        // dst = src1
    IR_ADD,         // dst = src1 + src2
    IR_SUB, IR_MUL, IR_DIV, IR_MOD,
    IR_NEG,         // dst = -src1
    IR_NOT,         // dst = !src1
    IR_EQ, IR_NE, IR_LT, IR_GT, IR_LE, IR_GE,
    IR_AND, IR_OR,
    IR_LABEL,       // label:
    IR_JUMP,        // goto label
    IR_CJUMP_FALSE, // if !src1 goto label
    IR_CALL,        // dst = call fn_name(arg_count args on stack)
    IR_ARG,         // push arg src1 (arg_index in imm)
    IR_RET,         // return src1 (-1 if void)
    IR_PRINT,       // print src1
} IROp;

typedef struct {
    IROp op;
    int dst;        // destination temp
    int src1;       // source temp 1
    int src2;       // source temp 2
    long imm;       // immediate value (for IR_CONST, label id, arg index)
    char* fn_name;  // for IR_CALL
    int arg_count;  // for IR_CALL
    Type val_type;  // type of result (TY_INT or TY_BOOL)
    bool dead;      // marked dead by optimizer
} IRInstr;

typedef struct {
    char* name;
    char** param_names;
    Type* param_types;
    int param_count;
    Type ret_type;

    IRInstr* instrs;
    int instr_count;
    int instr_cap;

    int temp_count;  // how many temporaries used
} IRFunc;

typedef struct {
    IRFunc* funcs;
    int func_count;
} IRProgram;

IRProgram* generateIR(Node* program);
void printIR(IRProgram* prog);

#endif

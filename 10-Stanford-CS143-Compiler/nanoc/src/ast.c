#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

const char* typeStr(Type t) {
    switch (t) {
        case TY_INT:   return "int";
        case TY_BOOL:  return "bool";
        case TY_VOID:  return "void";
        case TY_ERROR: return "<error>";
    }
    return "?";
}

const char* binOpStr(BinOp op) {
    switch (op) {
        case OP_ADD: return "+";  case OP_SUB: return "-";
        case OP_MUL: return "*";  case OP_DIV: return "/";
        case OP_MOD: return "%";
        case OP_EQ:  return "=="; case OP_NE: return "!=";
        case OP_LT:  return "<";  case OP_GT: return ">";
        case OP_LE:  return "<="; case OP_GE: return ">=";
        case OP_AND: return "&&"; case OP_OR: return "||";
    }
    return "?";
}

const char* unaryOpStr(UnaryOp op) {
    switch (op) {
        case UOP_NEG: return "-";
        case UOP_NOT: return "!";
    }
    return "?";
}

static Node* allocNode(NodeKind kind, int line) {
    Node* n = calloc(1, sizeof(Node));
    n->kind = kind;
    n->line = line;
    n->type = TY_ERROR;
    return n;
}

Node* newIntLit(int line, long val) {
    Node* n = allocNode(ND_INT_LIT, line);
    n->as.int_val = val;
    return n;
}

Node* newBoolLit(int line, bool val) {
    Node* n = allocNode(ND_BOOL_LIT, line);
    n->as.bool_val = val;
    return n;
}

Node* newVar(int line, char* name) {
    Node* n = allocNode(ND_VAR, line);
    n->as.var.name = name;
    n->as.var.value = NULL;
    return n;
}

Node* newUnary(int line, UnaryOp op, Node* operand) {
    Node* n = allocNode(ND_UNARY, line);
    n->as.unary.op = op;
    n->as.unary.operand = operand;
    return n;
}

Node* newBinary(int line, BinOp op, Node* left, Node* right) {
    Node* n = allocNode(ND_BINARY, line);
    n->as.binary.op = op;
    n->as.binary.left = left;
    n->as.binary.right = right;
    return n;
}

Node* newCall(int line, char* name, Node** args, int count) {
    Node* n = allocNode(ND_CALL, line);
    n->as.call.fn_name = name;
    n->as.call.args = args;
    n->as.call.arg_count = count;
    return n;
}

Node* newVarDecl(int line, char* name, Type type, Node* init) {
    Node* n = allocNode(ND_VAR_DECL, line);
    n->as.decl.name = name;
    n->as.decl.declared_type = type;
    n->as.decl.init = init;
    return n;
}

Node* newAssign(int line, char* name, Node* value) {
    Node* n = allocNode(ND_ASSIGN, line);
    n->as.var.name = name;
    n->as.var.value = value;
    return n;
}

Node* newPrint(int line, Node* value) {
    Node* n = allocNode(ND_PRINT, line);
    n->as.ret.value = value;
    return n;
}

Node* newReturn(int line, Node* value) {
    Node* n = allocNode(ND_RETURN, line);
    n->as.ret.value = value;
    return n;
}

Node* newIf(int line, Node* cond, Node* then_b, Node* else_b) {
    Node* n = allocNode(ND_IF, line);
    n->as.if_stmt.cond = cond;
    n->as.if_stmt.then_body = then_b;
    n->as.if_stmt.else_body = else_b;
    return n;
}

Node* newWhile(int line, Node* cond, Node* body) {
    Node* n = allocNode(ND_WHILE, line);
    n->as.while_stmt.cond = cond;
    n->as.while_stmt.body = body;
    return n;
}

Node* newFor(int line, Node* init, Node* cond, Node* step, Node* body) {
    Node* n = allocNode(ND_FOR, line);
    n->as.for_stmt.init = init;
    n->as.for_stmt.cond = cond;
    n->as.for_stmt.step = step;
    n->as.for_stmt.body = body;
    return n;
}

Node* newBlock(int line, Node** stmts, int count) {
    Node* n = allocNode(ND_BLOCK, line);
    n->as.block.stmts = stmts;
    n->as.block.count = count;
    return n;
}

Node* newFnDecl(int line, char* name, Param* params, int pcount,
                Type ret, Node* body) {
    Node* n = allocNode(ND_FN_DECL, line);
    n->as.fn.name = name;
    n->as.fn.params = params;
    n->as.fn.param_count = pcount;
    n->as.fn.ret_type = ret;
    n->as.fn.body = body;
    return n;
}

Node* newProgram(Node** fns, int count) {
    Node* n = allocNode(ND_PROGRAM, 0);
    n->as.block.stmts = fns;
    n->as.block.count = count;
    return n;
}

// ---- Pretty printer ----

static void pad(int indent) {
    for (int i = 0; i < indent; i++) printf("  ");
}

void printAST(Node* node, int indent) {
    if (!node) { pad(indent); printf("(null)\n"); return; }
    pad(indent);
    switch (node->kind) {
        case ND_INT_LIT:
            printf("IntLit(%ld)\n", node->as.int_val);
            break;
        case ND_BOOL_LIT:
            printf("BoolLit(%s)\n", node->as.bool_val ? "true" : "false");
            break;
        case ND_VAR:
            printf("Var(%s)\n", node->as.var.name);
            break;
        case ND_UNARY:
            printf("Unary(%s)\n", unaryOpStr(node->as.unary.op));
            printAST(node->as.unary.operand, indent + 1);
            break;
        case ND_BINARY:
            printf("Binary(%s)\n", binOpStr(node->as.binary.op));
            printAST(node->as.binary.left, indent + 1);
            printAST(node->as.binary.right, indent + 1);
            break;
        case ND_CALL:
            printf("Call(%s, %d args)\n", node->as.call.fn_name,
                   node->as.call.arg_count);
            for (int i = 0; i < node->as.call.arg_count; i++)
                printAST(node->as.call.args[i], indent + 1);
            break;
        case ND_VAR_DECL:
            printf("VarDecl(%s: %s)\n", node->as.decl.name,
                   typeStr(node->as.decl.declared_type));
            if (node->as.decl.init) printAST(node->as.decl.init, indent + 1);
            break;
        case ND_ASSIGN:
            printf("Assign(%s)\n", node->as.var.name);
            printAST(node->as.var.value, indent + 1);
            break;
        case ND_PRINT:
            printf("Print\n");
            printAST(node->as.ret.value, indent + 1);
            break;
        case ND_RETURN:
            printf("Return\n");
            if (node->as.ret.value) printAST(node->as.ret.value, indent + 1);
            break;
        case ND_IF:
            printf("If\n");
            printAST(node->as.if_stmt.cond, indent + 1);
            printAST(node->as.if_stmt.then_body, indent + 1);
            if (node->as.if_stmt.else_body)
                printAST(node->as.if_stmt.else_body, indent + 1);
            break;
        case ND_WHILE:
            printf("While\n");
            printAST(node->as.while_stmt.cond, indent + 1);
            printAST(node->as.while_stmt.body, indent + 1);
            break;
        case ND_FOR:
            printf("For\n");
            printAST(node->as.for_stmt.init, indent + 1);
            printAST(node->as.for_stmt.cond, indent + 1);
            printAST(node->as.for_stmt.step, indent + 1);
            printAST(node->as.for_stmt.body, indent + 1);
            break;
        case ND_BLOCK:
        case ND_PROGRAM:
            printf("%s(%d)\n",
                   node->kind == ND_BLOCK ? "Block" : "Program",
                   node->as.block.count);
            for (int i = 0; i < node->as.block.count; i++)
                printAST(node->as.block.stmts[i], indent + 1);
            break;
        case ND_FN_DECL:
            printf("FnDecl(%s, %d params, -> %s)\n",
                   node->as.fn.name, node->as.fn.param_count,
                   typeStr(node->as.fn.ret_type));
            printAST(node->as.fn.body, indent + 1);
            break;
    }
}

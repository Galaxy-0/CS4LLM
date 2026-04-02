#ifndef NANOC_AST_H
#define NANOC_AST_H

#include <stdbool.h>

// ---- Types ----

typedef enum { TY_INT, TY_BOOL, TY_VOID, TY_ERROR } Type;

const char* typeStr(Type t);

// ---- AST node kinds ----

typedef enum {
    // Expressions
    ND_INT_LIT,     // integer literal
    ND_BOOL_LIT,    // true / false
    ND_VAR,         // variable reference
    ND_UNARY,       // -expr, !expr
    ND_BINARY,      // expr op expr
    ND_CALL,        // fn(args...)
    // Statements
    ND_VAR_DECL,    // var x: int = expr;
    ND_ASSIGN,      // x = expr;
    ND_PRINT,       // print expr;
    ND_RETURN,      // return expr;
    ND_IF,          // if (cond) then_body else_body
    ND_WHILE,       // while (cond) body
    ND_FOR,         // for (init; cond; step) body
    ND_BLOCK,       // { stmts... }
    // Top-level
    ND_FN_DECL,     // fn name(params): ret_type { body }
    ND_PROGRAM,     // list of fn decls
} NodeKind;

// ---- Binary/Unary operators ----

typedef enum {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD,
    OP_EQ, OP_NE, OP_LT, OP_GT, OP_LE, OP_GE,
    OP_AND, OP_OR,
} BinOp;

typedef enum {
    UOP_NEG,   // -
    UOP_NOT,   // !
} UnaryOp;

const char* binOpStr(BinOp op);
const char* unaryOpStr(UnaryOp op);

// ---- AST nodes ----

typedef struct Node Node;
typedef struct Param Param;

struct Param {
    char* name;
    Type type;
};

struct Node {
    NodeKind kind;
    int line;
    Type type;  // filled by type checker

    union {
        // ND_INT_LIT
        long int_val;

        // ND_BOOL_LIT
        bool bool_val;

        // ND_VAR, ND_ASSIGN
        struct { char* name; Node* value; } var;

        // ND_UNARY
        struct { UnaryOp op; Node* operand; } unary;

        // ND_BINARY
        struct { BinOp op; Node* left; Node* right; } binary;

        // ND_CALL
        struct { char* fn_name; Node** args; int arg_count; } call;

        // ND_VAR_DECL
        struct { char* name; Type declared_type; Node* init; } decl;

        // ND_PRINT, ND_RETURN
        struct { Node* value; } ret;

        // ND_IF
        struct { Node* cond; Node* then_body; Node* else_body; } if_stmt;

        // ND_WHILE
        struct { Node* cond; Node* body; } while_stmt;

        // ND_FOR
        struct { Node* init; Node* cond; Node* step; Node* body; } for_stmt;

        // ND_BLOCK, ND_PROGRAM
        struct { Node** stmts; int count; } block;

        // ND_FN_DECL
        struct {
            char* name;
            Param* params;
            int param_count;
            Type ret_type;
            Node* body;
        } fn;
    } as;
};

// ---- Constructors ----

Node* newIntLit(int line, long val);
Node* newBoolLit(int line, bool val);
Node* newVar(int line, char* name);
Node* newUnary(int line, UnaryOp op, Node* operand);
Node* newBinary(int line, BinOp op, Node* left, Node* right);
Node* newCall(int line, char* name, Node** args, int count);
Node* newVarDecl(int line, char* name, Type type, Node* init);
Node* newAssign(int line, char* name, Node* value);
Node* newPrint(int line, Node* value);
Node* newReturn(int line, Node* value);
Node* newIf(int line, Node* cond, Node* then_b, Node* else_b);
Node* newWhile(int line, Node* cond, Node* body);
Node* newFor(int line, Node* init, Node* cond, Node* step, Node* body);
Node* newBlock(int line, Node** stmts, int count);
Node* newFnDecl(int line, char* name, Param* params, int pcount,
                Type ret, Node* body);
Node* newProgram(Node** fns, int count);

void printAST(Node* node, int indent);

#endif

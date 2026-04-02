#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typecheck.h"

// ---- Symbol table (scoped) ----

typedef struct VarSym {
    char* name;
    Type type;
    struct VarSym* next;
} VarSym;

typedef struct FnSym {
    char* name;
    Type ret_type;
    Type* param_types;
    int param_count;
    struct FnSym* next;
} FnSym;

typedef struct Scope {
    VarSym* vars;
    struct Scope* parent;
} Scope;

typedef struct {
    Scope* scope;
    FnSym* functions;
    Type current_ret_type;
    bool hadError;
} Checker;

static void error(Checker* c, int line, const char* msg) {
    fprintf(stderr, "[line %d] Type error: %s\n", line, msg);
    c->hadError = true;
}

static void errorf(Checker* c, int line, const char* fmt, ...) {
    fprintf(stderr, "[line %d] Type error: ", line);
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
    c->hadError = true;
}

static void pushScope(Checker* c) {
    Scope* s = calloc(1, sizeof(Scope));
    s->parent = c->scope;
    c->scope = s;
}

static void popScope(Checker* c) {
    c->scope = c->scope->parent;
}

static void defineVar(Checker* c, const char* name, Type type) {
    VarSym* v = calloc(1, sizeof(VarSym));
    v->name = strdup(name);
    v->type = type;
    v->next = c->scope->vars;
    c->scope->vars = v;
}

static Type lookupVar(Checker* c, const char* name) {
    for (Scope* s = c->scope; s; s = s->parent) {
        for (VarSym* v = s->vars; v; v = v->next) {
            if (strcmp(v->name, name) == 0) return v->type;
        }
    }
    return TY_ERROR;
}

static void defineFn(Checker* c, Node* fn) {
    FnSym* f = calloc(1, sizeof(FnSym));
    f->name = strdup(fn->as.fn.name);
    f->ret_type = fn->as.fn.ret_type;
    f->param_count = fn->as.fn.param_count;
    f->param_types = malloc(sizeof(Type) * f->param_count);
    for (int i = 0; i < f->param_count; i++) {
        f->param_types[i] = fn->as.fn.params[i].type;
    }
    f->next = c->functions;
    c->functions = f;
}

static FnSym* lookupFn(Checker* c, const char* name) {
    for (FnSym* f = c->functions; f; f = f->next) {
        if (strcmp(f->name, name) == 0) return f;
    }
    return NULL;
}

// ---- Type checking ----

static Type checkExpr(Checker* c, Node* node);
static void checkStmt(Checker* c, Node* node);

static Type checkExpr(Checker* c, Node* n) {
    switch (n->kind) {
        case ND_INT_LIT:
            n->type = TY_INT;
            return TY_INT;

        case ND_BOOL_LIT:
            n->type = TY_BOOL;
            return TY_BOOL;

        case ND_VAR: {
            Type t = lookupVar(c, n->as.var.name);
            if (t == TY_ERROR) {
                errorf(c, n->line, "undefined variable '%s'",
                       n->as.var.name);
            }
            n->type = t;
            return t;
        }

        case ND_UNARY: {
            Type operand = checkExpr(c, n->as.unary.operand);
            if (n->as.unary.op == UOP_NEG) {
                if (operand != TY_INT)
                    error(c, n->line, "'-' requires int operand");
                n->type = TY_INT;
            } else {
                if (operand != TY_BOOL)
                    error(c, n->line, "'!' requires bool operand");
                n->type = TY_BOOL;
            }
            return n->type;
        }

        case ND_BINARY: {
            Type lt = checkExpr(c, n->as.binary.left);
            Type rt = checkExpr(c, n->as.binary.right);
            BinOp op = n->as.binary.op;

            if (op >= OP_ADD && op <= OP_MOD) {
                if (lt != TY_INT || rt != TY_INT)
                    error(c, n->line, "arithmetic requires int operands");
                n->type = TY_INT;
            } else if (op == OP_EQ || op == OP_NE) {
                if (lt != rt)
                    error(c, n->line, "'==' / '!=' requires same types");
                n->type = TY_BOOL;
            } else if (op >= OP_LT && op <= OP_GE) {
                if (lt != TY_INT || rt != TY_INT)
                    error(c, n->line, "comparison requires int operands");
                n->type = TY_BOOL;
            } else {
                // AND, OR
                if (lt != TY_BOOL || rt != TY_BOOL)
                    error(c, n->line, "'&&' / '||' requires bool operands");
                n->type = TY_BOOL;
            }
            return n->type;
        }

        case ND_CALL: {
            FnSym* fn = lookupFn(c, n->as.call.fn_name);
            if (!fn) {
                errorf(c, n->line, "undefined function '%s'",
                       n->as.call.fn_name);
                n->type = TY_ERROR;
                return TY_ERROR;
            }
            if (n->as.call.arg_count != fn->param_count) {
                errorf(c, n->line, "'%s' expects %d args, got %d",
                       fn->name, fn->param_count, n->as.call.arg_count);
            }
            int limit = n->as.call.arg_count < fn->param_count
                        ? n->as.call.arg_count : fn->param_count;
            for (int i = 0; i < limit; i++) {
                Type at = checkExpr(c, n->as.call.args[i]);
                if (at != fn->param_types[i]) {
                    errorf(c, n->line,
                           "arg %d of '%s': expected %s, got %s",
                           i + 1, fn->name,
                           typeStr(fn->param_types[i]), typeStr(at));
                }
            }
            n->type = fn->ret_type;
            return fn->ret_type;
        }

        default:
            n->type = TY_ERROR;
            return TY_ERROR;
    }
}

static void checkStmt(Checker* c, Node* n) {
    switch (n->kind) {
        case ND_VAR_DECL: {
            Type declared = n->as.decl.declared_type;
            if (n->as.decl.init) {
                Type init = checkExpr(c, n->as.decl.init);
                if (init != declared && init != TY_ERROR) {
                    errorf(c, n->line,
                           "initializer type %s doesn't match declared %s",
                           typeStr(init), typeStr(declared));
                }
            }
            defineVar(c, n->as.decl.name, declared);
            break;
        }

        case ND_ASSIGN: {
            Type var_t = lookupVar(c, n->as.var.name);
            if (var_t == TY_ERROR) {
                errorf(c, n->line, "undefined variable '%s'",
                       n->as.var.name);
            }
            Type val_t = checkExpr(c, n->as.var.value);
            if (var_t != TY_ERROR && val_t != var_t) {
                errorf(c, n->line, "cannot assign %s to %s variable",
                       typeStr(val_t), typeStr(var_t));
            }
            break;
        }

        case ND_PRINT: {
            Type t = checkExpr(c, n->as.ret.value);
            if (t != TY_INT && t != TY_BOOL)
                error(c, n->line, "print requires int or bool");
            break;
        }

        case ND_RETURN: {
            if (n->as.ret.value) {
                Type t = checkExpr(c, n->as.ret.value);
                if (c->current_ret_type == TY_VOID) {
                    error(c, n->line, "void function cannot return a value");
                } else if (t != c->current_ret_type && t != TY_ERROR) {
                    errorf(c, n->line, "return type %s doesn't match %s",
                           typeStr(t), typeStr(c->current_ret_type));
                }
            } else {
                if (c->current_ret_type != TY_VOID)
                    error(c, n->line, "non-void function must return a value");
            }
            break;
        }

        case ND_IF:
            if (checkExpr(c, n->as.if_stmt.cond) != TY_BOOL)
                error(c, n->line, "if condition must be bool");
            checkStmt(c, n->as.if_stmt.then_body);
            if (n->as.if_stmt.else_body)
                checkStmt(c, n->as.if_stmt.else_body);
            break;

        case ND_WHILE:
            if (checkExpr(c, n->as.while_stmt.cond) != TY_BOOL)
                error(c, n->line, "while condition must be bool");
            checkStmt(c, n->as.while_stmt.body);
            break;

        case ND_FOR:
            pushScope(c);
            if (n->as.for_stmt.init) checkStmt(c, n->as.for_stmt.init);
            if (n->as.for_stmt.cond) {
                if (checkExpr(c, n->as.for_stmt.cond) != TY_BOOL)
                    error(c, n->line, "for condition must be bool");
            }
            if (n->as.for_stmt.step) checkStmt(c, n->as.for_stmt.step);
            checkStmt(c, n->as.for_stmt.body);
            popScope(c);
            break;

        case ND_BLOCK:
            pushScope(c);
            for (int i = 0; i < n->as.block.count; i++)
                checkStmt(c, n->as.block.stmts[i]);
            popScope(c);
            break;

        default:
            // expression statement
            checkExpr(c, n);
            break;
    }
}

static void checkFn(Checker* c, Node* fn) {
    c->current_ret_type = fn->as.fn.ret_type;
    pushScope(c);
    for (int i = 0; i < fn->as.fn.param_count; i++) {
        defineVar(c, fn->as.fn.params[i].name,
                  fn->as.fn.params[i].type);
    }
    checkStmt(c, fn->as.fn.body);
    popScope(c);
}

bool typecheck(Node* program) {
    Checker c = {0};
    pushScope(&c);

    // First pass: register all functions
    for (int i = 0; i < program->as.block.count; i++) {
        defineFn(&c, program->as.block.stmts[i]);
    }

    // Second pass: check function bodies
    for (int i = 0; i < program->as.block.count; i++) {
        checkFn(&c, program->as.block.stmts[i]);
    }

    // Check main exists
    if (!lookupFn(&c, "main")) {
        fprintf(stderr, "Error: no 'main' function defined\n");
        c.hadError = true;
    }

    popScope(&c);
    return !c.hadError;
}

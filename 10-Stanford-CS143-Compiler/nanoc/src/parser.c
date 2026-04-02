#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "lexer.h"

typedef struct {
    Lexer lex;
    Token cur;
    Token prev;
    bool hadError;
} Parser;

static void advance(Parser* p) {
    p->prev = p->cur;
    p->cur = lexerNext(&p->lex);
    if (p->cur.kind == TOK_ERROR) {
        fprintf(stderr, "[line %d] Lexer error: %.*s\n",
                p->cur.line, p->cur.length, p->cur.start);
        p->hadError = true;
    }
}

static bool check(Parser* p, TokKind k) { return p->cur.kind == k; }

static bool match(Parser* p, TokKind k) {
    if (!check(p, k)) return false;
    advance(p);
    return true;
}

static void expect(Parser* p, TokKind k, const char* msg) {
    if (p->cur.kind == k) { advance(p); return; }
    fprintf(stderr, "[line %d] Error: %s (got '%.*s')\n",
            p->cur.line, msg, p->cur.length, p->cur.start);
    p->hadError = true;
}

static char* tokStr(Token t) {
    char* s = malloc(t.length + 1);
    memcpy(s, t.start, t.length);
    s[t.length] = '\0';
    return s;
}

// ---- Forward declarations ----

static Node* expression(Parser* p);
static Node* statement(Parser* p);

// ---- Type parsing ----

static Type parseType(Parser* p) {
    if (match(p, TOK_INT))  return TY_INT;
    if (match(p, TOK_BOOL)) return TY_BOOL;
    if (match(p, TOK_VOID)) return TY_VOID;
    fprintf(stderr, "[line %d] Error: expected type\n", p->cur.line);
    p->hadError = true;
    advance(p);
    return TY_ERROR;
}

// ---- Expression parsing (precedence climbing) ----

static Node* primary(Parser* p) {
    int line = p->cur.line;

    if (match(p, TOK_INT_LIT)) {
        return newIntLit(line, p->prev.int_val);
    }
    if (match(p, TOK_TRUE))  return newBoolLit(line, true);
    if (match(p, TOK_FALSE)) return newBoolLit(line, false);

    if (match(p, TOK_IDENT)) {
        char* name = tokStr(p->prev);
        // function call?
        if (match(p, TOK_LPAREN)) {
            int cap = 8;
            Node** args = malloc(sizeof(Node*) * cap);
            int count = 0;
            if (!check(p, TOK_RPAREN)) {
                do {
                    if (count >= cap) {
                        cap *= 2;
                        args = realloc(args, sizeof(Node*) * cap);
                    }
                    args[count++] = expression(p);
                } while (match(p, TOK_COMMA));
            }
            expect(p, TOK_RPAREN, "expected ')' after arguments");
            return newCall(line, name, args, count);
        }
        return newVar(line, name);
    }

    if (match(p, TOK_LPAREN)) {
        Node* expr = expression(p);
        expect(p, TOK_RPAREN, "expected ')'");
        return expr;
    }

    fprintf(stderr, "[line %d] Error: expected expression (got '%s')\n",
            p->cur.line, tokKindStr(p->cur.kind));
    p->hadError = true;
    advance(p);
    return newIntLit(line, 0);
}

static Node* unary(Parser* p) {
    int line = p->cur.line;
    if (match(p, TOK_MINUS)) return newUnary(line, UOP_NEG, unary(p));
    if (match(p, TOK_NOT))   return newUnary(line, UOP_NOT, unary(p));
    return primary(p);
}

static Node* factor(Parser* p) {
    Node* left = unary(p);
    while (check(p, TOK_STAR) || check(p, TOK_SLASH) || check(p, TOK_PERCENT)) {
        int line = p->cur.line;
        BinOp op = p->cur.kind == TOK_STAR ? OP_MUL :
                   p->cur.kind == TOK_SLASH ? OP_DIV : OP_MOD;
        advance(p);
        left = newBinary(line, op, left, unary(p));
    }
    return left;
}

static Node* term(Parser* p) {
    Node* left = factor(p);
    while (check(p, TOK_PLUS) || check(p, TOK_MINUS)) {
        int line = p->cur.line;
        BinOp op = p->cur.kind == TOK_PLUS ? OP_ADD : OP_SUB;
        advance(p);
        left = newBinary(line, op, left, factor(p));
    }
    return left;
}

static Node* comparison(Parser* p) {
    Node* left = term(p);
    while (check(p, TOK_LT) || check(p, TOK_GT) ||
           check(p, TOK_LE) || check(p, TOK_GE)) {
        int line = p->cur.line;
        BinOp op = p->cur.kind == TOK_LT ? OP_LT :
                   p->cur.kind == TOK_GT ? OP_GT :
                   p->cur.kind == TOK_LE ? OP_LE : OP_GE;
        advance(p);
        left = newBinary(line, op, left, term(p));
    }
    return left;
}

static Node* equality(Parser* p) {
    Node* left = comparison(p);
    while (check(p, TOK_EQ) || check(p, TOK_NE)) {
        int line = p->cur.line;
        BinOp op = p->cur.kind == TOK_EQ ? OP_EQ : OP_NE;
        advance(p);
        left = newBinary(line, op, left, comparison(p));
    }
    return left;
}

static Node* logicAnd(Parser* p) {
    Node* left = equality(p);
    while (match(p, TOK_AND)) {
        int line = p->prev.line;
        left = newBinary(line, OP_AND, left, equality(p));
    }
    return left;
}

static Node* logicOr(Parser* p) {
    Node* left = logicAnd(p);
    while (match(p, TOK_OR)) {
        int line = p->prev.line;
        left = newBinary(line, OP_OR, left, logicAnd(p));
    }
    return left;
}

static Node* expression(Parser* p) {
    return logicOr(p);
}

// ---- Statement parsing ----

static Node* blockStmt(Parser* p) {
    int line = p->prev.line;
    int cap = 16;
    Node** stmts = malloc(sizeof(Node*) * cap);
    int count = 0;

    while (!check(p, TOK_RBRACE) && !check(p, TOK_EOF)) {
        if (count >= cap) {
            cap *= 2;
            stmts = realloc(stmts, sizeof(Node*) * cap);
        }
        stmts[count++] = statement(p);
    }
    expect(p, TOK_RBRACE, "expected '}'");
    return newBlock(line, stmts, count);
}

static Node* statement(Parser* p) {
    int line = p->cur.line;

    // var declaration: var x: int = expr;
    if (match(p, TOK_VAR)) {
        expect(p, TOK_IDENT, "expected variable name");
        char* name = tokStr(p->prev);
        expect(p, TOK_COLON, "expected ':' after variable name");
        Type type = parseType(p);
        Node* init = NULL;
        if (match(p, TOK_ASSIGN)) {
            init = expression(p);
        }
        expect(p, TOK_SEMI, "expected ';'");
        return newVarDecl(line, name, type, init);
    }

    // print expr;
    if (match(p, TOK_PRINT)) {
        Node* val = expression(p);
        expect(p, TOK_SEMI, "expected ';'");
        return newPrint(line, val);
    }

    // return expr;
    if (match(p, TOK_RETURN)) {
        Node* val = NULL;
        if (!check(p, TOK_SEMI)) val = expression(p);
        expect(p, TOK_SEMI, "expected ';'");
        return newReturn(line, val);
    }

    // if (cond) { ... } else { ... }
    if (match(p, TOK_IF)) {
        expect(p, TOK_LPAREN, "expected '(' after 'if'");
        Node* cond = expression(p);
        expect(p, TOK_RPAREN, "expected ')'");
        expect(p, TOK_LBRACE, "expected '{'");
        Node* then_b = blockStmt(p);
        Node* else_b = NULL;
        if (match(p, TOK_ELSE)) {
            if (check(p, TOK_IF)) {
                else_b = statement(p); // else if
            } else {
                expect(p, TOK_LBRACE, "expected '{'");
                else_b = blockStmt(p);
            }
        }
        return newIf(line, cond, then_b, else_b);
    }

    // while (cond) { ... }
    if (match(p, TOK_WHILE)) {
        expect(p, TOK_LPAREN, "expected '(' after 'while'");
        Node* cond = expression(p);
        expect(p, TOK_RPAREN, "expected ')'");
        expect(p, TOK_LBRACE, "expected '{'");
        Node* body = blockStmt(p);
        return newWhile(line, cond, body);
    }

    // for (init; cond; step) { ... }
    if (match(p, TOK_FOR)) {
        expect(p, TOK_LPAREN, "expected '(' after 'for'");
        // init
        Node* init = NULL;
        if (check(p, TOK_VAR)) {
            init = statement(p); // var decl with ;
        } else if (!check(p, TOK_SEMI)) {
            // assignment: ident = expr ;
            Node* expr = expression(p);
            if (expr->kind == ND_VAR && match(p, TOK_ASSIGN)) {
                char* name = expr->as.var.name;
                Node* val = expression(p);
                init = newAssign(line, name, val);
            } else {
                init = expr;
            }
            expect(p, TOK_SEMI, "expected ';'");
        } else {
            advance(p); // skip ;
        }
        // cond
        Node* cond = NULL;
        if (!check(p, TOK_SEMI)) cond = expression(p);
        expect(p, TOK_SEMI, "expected ';'");
        // step
        Node* step = NULL;
        if (!check(p, TOK_RPAREN)) {
            // parse as ident = expr
            expect(p, TOK_IDENT, "expected identifier");
            char* sname = tokStr(p->prev);
            expect(p, TOK_ASSIGN, "expected '='");
            Node* sval = expression(p);
            step = newAssign(line, sname, sval);
        }
        expect(p, TOK_RPAREN, "expected ')'");
        expect(p, TOK_LBRACE, "expected '{'");
        Node* body = blockStmt(p);
        return newFor(line, init, cond, step, body);
    }

    // block
    if (match(p, TOK_LBRACE)) {
        return blockStmt(p);
    }

    // assignment or expression statement
    Node* expr = expression(p);
    if (expr->kind == ND_VAR && match(p, TOK_ASSIGN)) {
        char* name = expr->as.var.name;
        Node* val = expression(p);
        expect(p, TOK_SEMI, "expected ';'");
        return newAssign(line, name, val);
    }
    expect(p, TOK_SEMI, "expected ';'");
    return expr;
}

// ---- Top-level ----

static Node* fnDecl(Parser* p) {
    int line = p->cur.line;
    expect(p, TOK_FN, "expected 'fn'");
    expect(p, TOK_IDENT, "expected function name");
    char* name = tokStr(p->prev);

    expect(p, TOK_LPAREN, "expected '('");
    int cap = 8;
    Param* params = malloc(sizeof(Param) * cap);
    int pcount = 0;
    if (!check(p, TOK_RPAREN)) {
        do {
            if (pcount >= cap) {
                cap *= 2;
                params = realloc(params, sizeof(Param) * cap);
            }
            expect(p, TOK_IDENT, "expected parameter name");
            params[pcount].name = tokStr(p->prev);
            expect(p, TOK_COLON, "expected ':'");
            params[pcount].type = parseType(p);
            pcount++;
        } while (match(p, TOK_COMMA));
    }
    expect(p, TOK_RPAREN, "expected ')'");

    expect(p, TOK_COLON, "expected ':' before return type");
    Type ret = parseType(p);

    expect(p, TOK_LBRACE, "expected '{' for function body");
    Node* body = blockStmt(p);

    return newFnDecl(line, name, params, pcount, ret, body);
}

Node* parse(const char* source) {
    Parser p;
    lexerInit(&p.lex, source);
    p.hadError = false;
    advance(&p);

    int cap = 16;
    Node** fns = malloc(sizeof(Node*) * cap);
    int count = 0;

    while (!check(&p, TOK_EOF)) {
        if (count >= cap) {
            cap *= 2;
            fns = realloc(fns, sizeof(Node*) * cap);
        }
        fns[count++] = fnDecl(&p);
    }

    if (p.hadError) return NULL;
    return newProgram(fns, count);
}

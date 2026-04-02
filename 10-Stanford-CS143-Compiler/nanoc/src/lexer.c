#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"

void lexerInit(Lexer* lex, const char* source) {
    lex->start = source;
    lex->current = source;
    lex->line = 1;
}

static char peek(Lexer* lex) { return *lex->current; }
static char peekNext(Lexer* lex) {
    if (*lex->current == '\0') return '\0';
    return lex->current[1];
}
static char advance(Lexer* lex) { return *lex->current++; }
static int isAtEnd(Lexer* lex) { return *lex->current == '\0'; }

static void skipWhitespace(Lexer* lex) {
    for (;;) {
        char c = peek(lex);
        if (c == ' ' || c == '\r' || c == '\t') {
            advance(lex);
        } else if (c == '\n') {
            lex->line++;
            advance(lex);
        } else if (c == '/' && peekNext(lex) == '/') {
            while (peek(lex) != '\n' && !isAtEnd(lex)) advance(lex);
        } else {
            return;
        }
    }
}

static Token makeToken(Lexer* lex, TokKind kind) {
    Token t;
    t.kind = kind;
    t.start = lex->start;
    t.length = (int)(lex->current - lex->start);
    t.line = lex->line;
    t.int_val = 0;
    return t;
}

static Token errorToken(Lexer* lex, const char* msg) {
    Token t;
    t.kind = TOK_ERROR;
    t.start = msg;
    t.length = (int)strlen(msg);
    t.line = lex->line;
    t.int_val = 0;
    return t;
}

static TokKind checkKeyword(Lexer* lex, int start, int len,
                            const char* rest, TokKind kind) {
    if (lex->current - lex->start == start + len &&
        memcmp(lex->start + start, rest, len) == 0) {
        return kind;
    }
    return TOK_IDENT;
}

static TokKind identifierKind(Lexer* lex) {
    switch (lex->start[0]) {
        case 'b': return checkKeyword(lex, 1, 3, "ool", TOK_BOOL);
        case 'e': return checkKeyword(lex, 1, 3, "lse", TOK_ELSE);
        case 'f':
            if (lex->current - lex->start > 1) {
                switch (lex->start[1]) {
                    case 'a': return checkKeyword(lex, 2, 3, "lse", TOK_FALSE);
                    case 'n': if (lex->current - lex->start == 2) return TOK_FN;
                              break;
                    case 'o': return checkKeyword(lex, 2, 1, "r", TOK_FOR);
                }
            }
            break;
        case 'i':
            if (lex->current - lex->start > 1) {
                switch (lex->start[1]) {
                    case 'f': if (lex->current - lex->start == 2) return TOK_IF;
                              break;
                    case 'n': return checkKeyword(lex, 2, 1, "t", TOK_INT);
                }
            }
            break;
        case 'p': return checkKeyword(lex, 1, 4, "rint", TOK_PRINT);
        case 'r': return checkKeyword(lex, 1, 5, "eturn", TOK_RETURN);
        case 't': return checkKeyword(lex, 1, 3, "rue", TOK_TRUE);
        case 'v':
            if (lex->current - lex->start > 2) {
                switch (lex->start[1]) {
                    case 'a': return checkKeyword(lex, 2, 1, "r", TOK_VAR);
                    case 'o': return checkKeyword(lex, 2, 2, "id", TOK_VOID);
                }
            }
            break;
        case 'w': return checkKeyword(lex, 1, 4, "hile", TOK_WHILE);
    }
    return TOK_IDENT;
}

static Token scanNumber(Lexer* lex) {
    while (isdigit(peek(lex))) advance(lex);
    Token t = makeToken(lex, TOK_INT_LIT);
    t.int_val = strtol(t.start, NULL, 10);
    return t;
}

static Token scanIdentifier(Lexer* lex) {
    while (isalpha(peek(lex)) || isdigit(peek(lex)) || peek(lex) == '_')
        advance(lex);
    return makeToken(lex, identifierKind(lex));
}

Token lexerNext(Lexer* lex) {
    skipWhitespace(lex);
    lex->start = lex->current;

    if (isAtEnd(lex)) return makeToken(lex, TOK_EOF);

    char c = advance(lex);

    if (isdigit(c)) return scanNumber(lex);
    if (isalpha(c) || c == '_') return scanIdentifier(lex);

    switch (c) {
        case '(': return makeToken(lex, TOK_LPAREN);
        case ')': return makeToken(lex, TOK_RPAREN);
        case '{': return makeToken(lex, TOK_LBRACE);
        case '}': return makeToken(lex, TOK_RBRACE);
        case ',': return makeToken(lex, TOK_COMMA);
        case ':': return makeToken(lex, TOK_COLON);
        case ';': return makeToken(lex, TOK_SEMI);
        case '+': return makeToken(lex, TOK_PLUS);
        case '-': return makeToken(lex, TOK_MINUS);
        case '*': return makeToken(lex, TOK_STAR);
        case '/': return makeToken(lex, TOK_SLASH);
        case '%': return makeToken(lex, TOK_PERCENT);
        case '!':
            if (peek(lex) == '=') { advance(lex); return makeToken(lex, TOK_NE); }
            return makeToken(lex, TOK_NOT);
        case '=':
            if (peek(lex) == '=') { advance(lex); return makeToken(lex, TOK_EQ); }
            return makeToken(lex, TOK_ASSIGN);
        case '<':
            if (peek(lex) == '=') { advance(lex); return makeToken(lex, TOK_LE); }
            return makeToken(lex, TOK_LT);
        case '>':
            if (peek(lex) == '=') { advance(lex); return makeToken(lex, TOK_GE); }
            return makeToken(lex, TOK_GT);
        case '&':
            if (peek(lex) == '&') { advance(lex); return makeToken(lex, TOK_AND); }
            return errorToken(lex, "Expected '&&'.");
        case '|':
            if (peek(lex) == '|') { advance(lex); return makeToken(lex, TOK_OR); }
            return errorToken(lex, "Expected '||'.");
    }
    return errorToken(lex, "Unexpected character.");
}

const char* tokKindStr(TokKind kind) {
    switch (kind) {
        case TOK_INT_LIT: return "INT_LIT";
        case TOK_IDENT:   return "IDENT";
        case TOK_FN:      return "fn";
        case TOK_RETURN:  return "return";
        case TOK_IF:      return "if";
        case TOK_ELSE:    return "else";
        case TOK_WHILE:   return "while";
        case TOK_FOR:     return "for";
        case TOK_VAR:     return "var";
        case TOK_PRINT:   return "print";
        case TOK_TRUE:    return "true";
        case TOK_FALSE:   return "false";
        case TOK_INT:     return "int";
        case TOK_BOOL:    return "bool";
        case TOK_VOID:    return "void";
        case TOK_PLUS:    return "+";
        case TOK_MINUS:   return "-";
        case TOK_STAR:    return "*";
        case TOK_SLASH:   return "/";
        case TOK_PERCENT: return "%";
        case TOK_EQ:      return "==";
        case TOK_NE:      return "!=";
        case TOK_LT:      return "<";
        case TOK_GT:      return ">";
        case TOK_LE:      return "<=";
        case TOK_GE:      return ">=";
        case TOK_AND:     return "&&";
        case TOK_OR:      return "||";
        case TOK_NOT:     return "!";
        case TOK_ASSIGN:  return "=";
        case TOK_LPAREN:  return "(";
        case TOK_RPAREN:  return ")";
        case TOK_LBRACE:  return "{";
        case TOK_RBRACE:  return "}";
        case TOK_COMMA:   return ",";
        case TOK_COLON:   return ":";
        case TOK_SEMI:    return ";";
        case TOK_EOF:     return "EOF";
        case TOK_ERROR:   return "ERROR";
    }
    return "?";
}

#ifndef NANOC_LEXER_H
#define NANOC_LEXER_H

typedef enum {
    // Literals & identifiers
    TOK_INT_LIT, TOK_IDENT,
    // Keywords
    TOK_FN, TOK_RETURN, TOK_IF, TOK_ELSE, TOK_WHILE, TOK_FOR,
    TOK_VAR, TOK_PRINT, TOK_TRUE, TOK_FALSE,
    // Types
    TOK_INT, TOK_BOOL, TOK_VOID,
    // Operators
    TOK_PLUS, TOK_MINUS, TOK_STAR, TOK_SLASH, TOK_PERCENT,
    TOK_EQ, TOK_NE, TOK_LT, TOK_GT, TOK_LE, TOK_GE,
    TOK_AND, TOK_OR, TOK_NOT,
    TOK_ASSIGN,
    // Delimiters
    TOK_LPAREN, TOK_RPAREN, TOK_LBRACE, TOK_RBRACE,
    TOK_COMMA, TOK_COLON, TOK_SEMI,
    // Special
    TOK_EOF, TOK_ERROR
} TokKind;

typedef struct {
    TokKind kind;
    const char* start;
    int length;
    int line;
    long int_val;  // valid when kind == TOK_INT_LIT
} Token;

typedef struct {
    const char* start;
    const char* current;
    int line;
} Lexer;

void lexerInit(Lexer* lex, const char* source);
Token lexerNext(Lexer* lex);
const char* tokKindStr(TokKind kind);

#endif

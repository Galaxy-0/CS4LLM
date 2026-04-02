#include <stdio.h>
#include <ctype.h>  // 用于判断 isdigit()，即是不是数字
#include <string.h>

// 1. 定义极其严谨的 Token 类型枚举
typedef enum {
    TOKEN_NUMBER,   // 数字
    TOKEN_PLUS,     // +
    TOKEN_MINUS,    // -
    TOKEN_MUL,      // *
    TOKEN_DIV,      // /
    TOKEN_LPAREN,   // 左括号 (
    TOKEN_RPAREN,   // 右括号 )
    TOKEN_EOF       // 文件/字符串结束标记 (End Of File)
} TokenType;

// 2. Token 的数据结构
typedef struct {
    TokenType type;
    int value; // 如果 type 是 TOKEN_NUMBER，这里就存具体的数字大小
} Token;

// 简单实现一个获取 Token 的函数（词法分析器核心）
// 输入是一个字符串的指针的指针 (为了能移动它)，返回解析出的 Token
Token get_next_token(const char **source) {
    Token token;
    
    // 忽略所有空格
    while (isspace(**source)) {
        (*source)++;
    }
    
    // 如果走到字符串尽头，返回 EOF
    if (**source == '\0') {
        token.type = TOKEN_EOF;
        return token;
    }
    
    // 解析数字 (这一步是状态机的一小步：把连在一起的字符'1''2''3'变成整型 123)
    if (isdigit(**source)) {
        token.type = TOKEN_NUMBER;
        int num = 0;
        while (isdigit(**source)) {
            num = num * 10 + (**source - '0'); // ASCII码转数字公式
            (*source)++;
        }
        token.value = num;
        return token;
    }
    
    // 解析单字符操作符
    char c = **source;
    (*source)++; // 把指针移到下一个字符
    switch (c) {
        case '+': token.type = TOKEN_PLUS; break;
        case '-': token.type = TOKEN_MINUS; break;
        case '*': token.type = TOKEN_MUL; break;
        case '/': token.type = TOKEN_DIV; break;
        case '(': token.type = TOKEN_LPAREN; break;
        case ')': token.type = TOKEN_RPAREN; break;
        default:
            printf("Lexer 报错：遇到不认识的字符 '%c'！\n", c);
            token.type = TOKEN_EOF; // 发生错误，强行结束
    }
    return token;
}

// 辅助打印函数
void print_token(Token t) {
    switch(t.type) {
        case TOKEN_NUMBER: printf("TOKEN_NUMBER(%d) ", t.value); break;
        case TOKEN_PLUS:   printf("TOKEN_PLUS "); break;
        case TOKEN_MINUS:  printf("TOKEN_MINUS "); break;
        case TOKEN_MUL:    printf("TOKEN_MUL "); break;
        case TOKEN_DIV:    printf("TOKEN_DIV "); break;
        case TOKEN_LPAREN: printf("TOKEN_LPAREN "); break;
        case TOKEN_RPAREN: printf("TOKEN_RPAREN "); break;
        case TOKEN_EOF:    printf("TOKEN_EOF\n"); break;
    }
}

int main() {
    // 假设这是用户敲出来的一段毫无生命力的字符串
    const char *source_code = " 124 +  (45 * 2) / 10 ";
    const char *current_char = source_code;
    
    printf("===== 编译原理第一战：词法分析器 (Lexer) =====\n");
    printf(">> 正在解析人类输入的乱码文本: \"%s\"\n", source_code);
    printf(">> 提取出的 Tokens 流：\n   ");
    
    Token current_token;
    do {
        // 让词法分析器一口一口吃掉字符串，吐出严谨的 Token
        current_token = get_next_token(&current_char);
        print_token(current_token);
    } while (current_token.type != TOKEN_EOF);

    return 0;
}

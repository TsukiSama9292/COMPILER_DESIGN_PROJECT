%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
int yylex(void);
void yyerror(const char *s);

%}

%union {
    int num;
    char *str;
}

%token <str> IDENTIFIER
%token <str> STRING_LITERAL
%token <num> NUMBER
%token <num> FLOAT
%token SIZEOF
%token INT RETURN IF ELSE FOR WHILE PRINTF
%token EQ NEQ GE LE GT LT ASSIGN PLUS MINUS MULT DIV INC DEC DOT
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET

%start program

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program
    : declarations {
        printf("✅ 程式語法分析成功，共 %d 行\n", yylineno);
    }
    ;

declarations
    : declarations declaration
    | declaration
    ;

declaration
    : INT IDENTIFIER SEMICOLON
    | INT IDENTIFIER ASSIGN expression SEMICOLON
    | INT IDENTIFIER LBRACKET RBRACKET SEMICOLON
    | INT IDENTIFIER LBRACKET RBRACKET ASSIGN array_initializer SEMICOLON
    | function_definition
    ;

function_definition
    : INT IDENTIFIER LPAREN RPAREN compound_statement
    ;

compound_statement
    : LBRACE statements RBRACE
    ;

statements
    : statements statement
    | statement
    ;

statement
    : expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    ;

expression_statement
    : expression SEMICOLON
    | SEMICOLON
    ;

selection_statement
    : IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
    | IF LPAREN expression RPAREN statement ELSE statement
    ;

iteration_statement
    : FOR LPAREN expression_statement expression_statement expression RPAREN statement
    | WHILE LPAREN expression RPAREN statement
    ;

jump_statement
    : RETURN expression SEMICOLON
    ;

expression
    : IDENTIFIER ASSIGN expression
    | function_call
    | simple_expression
    | SIZEOF LPAREN expression RPAREN
    ;

function_call
    : IDENTIFIER LPAREN argument_list_opt RPAREN
    ;

simple_expression
    : simple_expression PLUS term
    | simple_expression MINUS term
    | term
    ;

term
    : term MULT factor
    | term DIV factor
    | factor
    ;

factor
    : LPAREN expression RPAREN
    | IDENTIFIER
    | IDENTIFIER LBRACKET expression RBRACKET
    | NUMBER
    | STRING_LITERAL
    | FLOAT
    ;

argument_list_opt
    : /* empty */
    | argument_list
    ;

argument_list
    : expression
    | argument_list COMMA expression
    ;

array_initializer
    : LBRACE initializer_list RBRACE
    ;

initializer_list
    : expression
    | initializer_list COMMA expression
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "❌ 語法錯誤：%s 在第 %d 行\n", s, yylineno);
}

// 添加 main 函数
int main() {
    yyparse();  // 调用解析器
    return 0;
}
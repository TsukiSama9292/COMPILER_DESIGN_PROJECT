%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(const char *s);
extern int yylineno;

%}

%union {
    int num;
    char *str;
}

%token <str> IDENTIFIER
%token <str> STRING_LITERAL
%token <num> NUMBER
%token <num> FLOAT
%token INT RETURN IF ELSE FOR WHILE PRINTF
%token EQ NEQ GE LE GT LT ASSIGN PLUS MINUS MULT DIV INC DEC DOT
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET

%start program

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program
    : declarations
    ;

declarations
    : declarations declaration
    | declaration
    ;

declaration
    : INT IDENTIFIER SEMICOLON
    | INT IDENTIFIER ASSIGN expression SEMICOLON
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
    | simple_expression
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
    | NUMBER
    | STRING_LITERAL
    | FLOAT           // 添加浮點數處理
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "語法錯誤：%s 在第 %d 行\n", s, yylineno);
}

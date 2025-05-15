%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
int yylex(void);
void yyerror(const char *s);
%}

%define parse.error verbose

%union {
    int num;
    char *str;
}

/* Tokens */
%token <str> IDENTIFIER STRING_LITERAL
%token <num> NUMBER FLOAT
%token SIZEOF INT RETURN IF ELSE FOR WHILE
/* Treat printf as normal identifier */
%token EQ NEQ GE LE GT LT ASSIGN PLUS MINUS MULT DIV
%token INC DEC SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET

/* Precedence and associativity */
%left PLUS MINUS
%left MULT DIV
%nonassoc GT LT GE LE EQ NEQ
%right ASSIGN
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start program

%%

program:
    declarations                { printf("✅ 程式語法分析成功，共 %d 行\n", yylineno); }
;

declarations:
    declarations declaration
  | declaration
;

declaration:
    INT IDENTIFIER SEMICOLON
  | INT IDENTIFIER ASSIGN expression SEMICOLON
  | INT IDENTIFIER LBRACKET RBRACKET SEMICOLON
  | INT IDENTIFIER LBRACKET RBRACKET ASSIGN array_initializer SEMICOLON
  | function_definition
  | error SEMICOLON           { yyerror("語法錯誤，已跳過到 ;"); yyerrok; }
;

function_definition:
    INT IDENTIFIER LPAREN parameter_list_opt RPAREN compound_statement
;

parameter_list_opt:
    /* empty */
  | parameter_list
;

parameter_list:
    INT IDENTIFIER
  | parameter_list COMMA INT IDENTIFIER
;

compound_statement:
    LBRACE statements RBRACE
;

statements:
    statements statement
  | /* empty */
;

statement:
    expression_statement
  | compound_statement
  | selection_statement
  | iteration_statement
  | jump_statement
  | error SEMICOLON           { yyerror("語法錯誤，已跳過到 ;"); yyerrok; }
;

expression_statement:
    expression SEMICOLON
  | SEMICOLON
;

selection_statement:
    IF LPAREN expression RPAREN statement        %prec LOWER_THAN_ELSE
  | IF LPAREN expression RPAREN statement ELSE statement
;

iteration_statement:
    FOR LPAREN expression_statement expression_statement expression RPAREN statement
  | WHILE LPAREN expression RPAREN statement
;

jump_statement:
    RETURN expression SEMICOLON
;

expression:
    IDENTIFIER ASSIGN expression
  | function_call
  | simple_expression
  | SIZEOF LPAREN expression RPAREN
;

function_call:
    IDENTIFIER LPAREN argument_list_opt RPAREN
;

simple_expression:
    simple_expression PLUS term
  | simple_expression MINUS term
  | simple_expression EQ term
  | simple_expression NEQ term
  | simple_expression GT term
  | simple_expression LT term
  | simple_expression GE term
  | simple_expression LE term
  | term
;

term:
    term MULT factor
  | term DIV factor
  | factor
;

factor:
    LPAREN expression RPAREN
  | IDENTIFIER
  | IDENTIFIER INC
  | IDENTIFIER DEC
  | INC IDENTIFIER
  | DEC IDENTIFIER
  | IDENTIFIER LBRACKET expression RBRACKET
  | NUMBER
  | STRING_LITERAL
  | FLOAT
;

argument_list_opt:
    /* empty */
  | argument_list
;

argument_list:
    expression
  | argument_list COMMA expression
;

array_initializer:
    LBRACE initializer_list RBRACE
;

initializer_list:
    expression
  | initializer_list COMMA expression
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "❌ 語法錯誤：%s 在第 %d 行\n", s, yylineno);
}

int main() {
    yyparse();
    return 0;
}
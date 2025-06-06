%{
#include "example.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
char c;
%}

DIGIT      [0-9]+
FLOAT      [0-9]+\.[0-9]+
ID         [a-zA-Z_][a-zA-Z0-9_]*
STRING     \"([^\"\\]|\\.)*\"

%%

[ \t\r]+            ;   // 忽略空白
\n                  { yylineno++; }

"if"                { return IF; }
"else"              { return ELSE; }
"for"               { return FOR; }
"while"             { return WHILE; }
"sizeof"            { return SIZEOF; }
"return"            { return RETURN; }

"int"               { return TYPES; }
"float"             { return TYPES; }
"long"              { return TYPES; }
"char"              { return TYPES; }
"double"            { return TYPES; }

"=="                { return EQ; }
"!="                { return NEQ; }
">="                { return GE; }
"<="                { return LE; }
">"                 { return GT; }
"<"                 { return LT; }

"="                 { return ASSIGN; }
"++"                { return INC; }
"--"                { return DEC; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MULT; }
"/"                 { return DIV; }

";"                 { return SEMICOLON; }
","                 { return COMMA; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }

{FLOAT}             { yylval.dbl = atof(yytext); return FLOAT; }
{DIGIT}             { yylval.num = atoi(yytext); return NUMBER; }
{STRING}            { yylval.str = strdup(yytext); return STRING_LITERAL; }
{ID}                { yylval.str = strdup(yytext); return IDENTIFIER; }

"#"                 ;   // 忽略 preprocessor 的 #
.                   { printf("非法字元: %s (第 %d 行)\n", yytext, yylineno); }

%%
int yywrap() { return 1; }

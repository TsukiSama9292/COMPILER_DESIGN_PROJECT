%{
#include "translate.tab.h"
#include <stdio.h>
#include <stdlib.h>
extern int yylineno;
%}

%%
"int"               { return INT; }
"return"            { return RETURN; }
"if"                { return IF; }
"else"              { return ELSE; }
"for"               { return FOR; }
"while"             { return WHILE; }
"printf"            { return PRINTF; }

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
"."                 { return DOT; }

";"                 { return SEMICOLON; }
","                 { return COMMA; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
"sizeof"            { return SIZEOF; }
"printf"   { return IDENTIFIER; }
[0-9]+\.[0-9]+      { yylval.num = atof(yytext); return FLOAT; }
[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }

\"([^\"\\]|\\.)*\"  { yylval.str = strdup(yytext); return STRING_LITERAL; }

[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFIER; }

"#"                 { /* 忽略注釋符號 # */ }

\n                  { yylineno++; }
[ \t\r]+            { /* skip whitespace */ }

.                   { printf("非法字元: %s\n", yytext); }
%%
int yywrap() { return 1; }

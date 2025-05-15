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
"sizeof"            { return SIZEOF; }

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

[0-9]+\.[0-9]+      { yylval.num = atof(yytext); return FLOAT; }
[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }
\"([^\"\\]|\\.)*\"  { yylval.str = strdup(yytext); return STRING_LITERAL; }

[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFIER; }

"#"                 { /* skip */ }
[ \t\r]+            { /* skip whitespace */ }
\n                  { yylineno++; }
.                   { printf("非法字元: %s\n", yytext); }
%%
int yywrap() { return 1; }
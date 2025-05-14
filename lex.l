%{
#include <stdio.h>
int lineno = 1;

int count_keyword = 0;
int count_boolean = 0;
int count_none = 0;
int count_float = 0;
int count_integer = 0;
int count_string = 0;
int count_identifier = 0;
int count_operator = 0;
int count_symbol = 0;
int count_unknown = 0;

void print_summary();
%}


%%
"def"|"if"|"else"|"return"     { count_keyword++;   printf("<KEYWORD: %s>\n", yytext); }
"True"|"False"                 { count_boolean++;   printf("<BOOLEAN: %s>\n", yytext); }
"None"                         { count_none++;      printf("<NONE: %s>\n", yytext); }

[0-9]+\.[0-9]+                 { count_float++;     printf("<FLOAT: %s>\n", yytext); }
[0-9]+                         { count_integer++;   printf("<INTEGER: %s>\n", yytext); }

\"([^\"\\]|\\.)*\"             { count_string++;    printf("<STRING: %s>\n", yytext); }
\'([^\'\\]|\\.)*\'             { count_string++;    printf("<STRING: %s>\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*         { count_identifier++;printf("<IDENTIFIER: %s>\n", yytext); }

"->"|"=="|">="|"<="|"!="       { count_operator++;  printf("<OPERATOR: %s>\n", yytext); }
[=:\-,\.\#><\+\*/%]            { count_symbol++;    printf("<SYMBOL: %s>\n", yytext); }
[()]                           { count_symbol++;    printf("<SYMBOL: %s>\n", yytext); }
[\[\]]                         { count_symbol++;    printf("<SYMBOL: %s>\n", yytext); }
[{}]                           { count_symbol++;    printf("<SYMBOL: %s>\n", yytext); }

[\n]                           { lineno++; }
[ \t\r]+                       { /* skip whitespace */ }
.                              { count_unknown++;   printf("<UNKNOWN: %s>\n", yytext); }
%%

void print_summary() {
    printf("\n========== 詞彙統整表 ==========\n");
    printf("| Type         | Times\t|\n");
    printf("|--------------|--------|\n");
    printf("| KEYWORD      | %d\t|\n", count_keyword);
    printf("| BOOLEAN      | %d\t|\n", count_boolean);
    printf("| NONE         | %d\t|\n", count_none);
    printf("| FLOAT        | %d\t|\n", count_float);
    printf("| INTEGER      | %d\t|\n", count_integer);
    printf("| STRING       | %d\t|\n", count_string);
    printf("| IDENTIFIER   | %d\t|\n", count_identifier);
    printf("| OPERATOR     | %d\t|\n", count_operator);
    printf("| SYMBOL       | %d\t|\n", count_symbol);
    printf("| UNKNOWN      | %d\t|\n", count_unknown);
    printf("================================\n");
}

int main(int argc, char **argv) {
    yylex();
    print_summary();    
    return 0;
}
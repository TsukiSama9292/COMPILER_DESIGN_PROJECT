%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
int yylex(void);
void yyerror(const char *s);

/* Expr 結構：code = 這個節點產生的 TAC, place = 運算式結果暫存器 */
typedef struct {
    char *code;
    char *place;
} Expr;

/* Helper：產生新的暫存器名稱 (t0, t1, ...) */
static int temp_count = 0;
char *newTemp() {
    char buf[32];
    sprintf(buf, "t%d", temp_count++);
    return strdup(buf);
}

/* Helper：產生新的標籤 (L0, L1, ...) */
static int label_count = 0;
char *newLabel() {
    char buf[32];
    sprintf(buf, "L%d", label_count++);
    return strdup(buf);
}

/* 串接兩段 TAC，並自動在中間加換行 */
char *concatCode(const char *a, const char *b) {
    size_t la = a ? strlen(a) : 0;
    size_t lb = b ? strlen(b) : 0;
    char *res = malloc(la + lb + 2);
    if (a) strcpy(res, a);
    else    res[0] = '\0';
    if (b)  strcat(res, b);
    strcat(res, "\n");
    return res;
}

/* 串接三段 TAC (a + b + c)，中間都加換行 */
char *concat3(const char *a, const char *b, const char *c) {
    char *tmp = concatCode(a, b);
    char *res = concatCode(tmp, c);
    free(tmp);
    return res;
}
%}

%define parse.error verbose

/*=== Token、union  與 非終結式型別 宣告 ===*/
%union {
    int    num;
    char  *str;
    Expr   expr;
}

/* Token */
%token <str> IDENTIFIER STRING_LITERAL
%token <num> NUMBER FLOAT
%token SIZEOF INT RETURN IF ELSE FOR WHILE
%token EQ NEQ GE LE GT LT ASSIGN PLUS MINUS MULT DIV
%token INC DEC SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET

/* 把這些 nonterminal 都設定為 Expr 型別 */
%type <expr> program declarations declaration
%type <expr> function_definition parameter_list_opt parameter_list
%type <expr> compound_statement statements statement
%type <expr> expression_statement selection_statement iteration_statement jump_statement
%type <expr> expression simple_expression term factor function_call argument_list_opt argument_list
%type <expr> array_initializer initializer_list

/* Precedence & Associativity */
%left PLUS MINUS
%left MULT DIV
%nonassoc GT LT GE LE EQ NEQ
%right ASSIGN
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start program

%%

/*======================================================
  program: 最外層，把所有 declarations 累積起來印出
======================================================*/
program:
    declarations {
        /* 印出整段 TAC */
        printf("%s", $1.code ? $1.code : "");
        printf("✅ 程式語法分析成功，共 %d 行\n", yylineno);
        free($1.code);
    }
;

/*======================================================
  declarations: 多個 declaration 串起來
  $$.code = 先印左邊，再印右邊
======================================================*/
declarations:
    declarations declaration {
        char *tmp = concatCode($1.code ? $1.code : "", $2.code ? $2.code : "");
        free($1.code);
        free($2.code);
        $$.code = tmp;
        $$.place = NULL;
    }
  | declaration {
        $$.code = $1.code ? strdup($1.code) : strdup("");
        $$.place = NULL;
    }
;

/*======================================================
  declaration: 變數宣告、初始化、或函式定義
======================================================*/
declaration:
    INT IDENTIFIER SEMICOLON {
        /* int x; 不產生 TAC */
        $$.code = strdup("");
        $$.place = NULL;
    }
  | INT IDENTIFIER ASSIGN expression SEMICOLON {
        /* int x = expr; */
        char *expr_code  = $4.code;
        char *expr_place = $4.place;
        char buf[128];
        sprintf(buf, "%s = %s", $2, expr_place);
        char *tmp = concatCode(expr_code, buf);
        $$.code = tmp;
        $$.place = NULL;
        free(expr_code);
        free(expr_place);
    }
  | INT IDENTIFIER LBRACKET RBRACKET SEMICOLON {
        /* int arr[]; (暫不實作) */
        $$.code = strdup("");
        $$.place = NULL;
    }
  | INT IDENTIFIER LBRACKET RBRACKET ASSIGN array_initializer SEMICOLON {
        /* int arr[] = { ... }; (暫不實作) */
        $$.code = strdup("");
        $$.place = NULL;
    }
  | function_definition {
        /* 函式定義：直接把 body code 傳上來 */
        $$.code = $1.code ? strdup($1.code) : strdup("");
        $$.place = NULL;
        free($1.code);
    }
;

/*======================================================
  function_definition: int foo(params) { body }
  $$.code = "foo:" + body_code
======================================================*/
function_definition:
    INT IDENTIFIER LPAREN parameter_list_opt RPAREN compound_statement {
        char buf[128];
        sprintf(buf, "%s:", $2);          /* foo: */
        char *tmp = concatCode(buf, $6.code);
        $$.code = tmp;
        $$.place = NULL;
        free($6.code);
    }
;

/* parameter_list_opt / parameter_list: 暫不在 TAC 中做事 */
parameter_list_opt:
    /* empty */ {
        $$.code = strdup("");
        $$.place = NULL;
    }
  | parameter_list {
        $$.code = strdup("");
        $$.place = NULL;
    }
;

parameter_list:
    INT IDENTIFIER {
        $$.code = strdup("");
        $$.place = NULL;
    }
  | parameter_list COMMA INT IDENTIFIER {
        $$.code = strdup("");
        $$.place = NULL;
    }
;

/*======================================================
  compound_statement: { statements }
  $$.code = statements.code
======================================================*/
compound_statement:
    LBRACE statements RBRACE {
        $$.code  = $2.code ? strdup($2.code) : strdup("");
        $$.place = NULL;
        free($2.code);
    }
;

/*======================================================
  statements: 多個 statement 串起來
  $$.code = 左邊 + 右邊
======================================================*/
statements:
    statements statement {
        char *tmp = concatCode($1.code ? $1.code : "", $2.code ? $2.code : "");
        free($1.code);
        free($2.code);
        $$.code = tmp;
        $$.place = NULL;
    }
  | /* empty */ {
        $$.code = strdup("");
        $$.place = NULL;
    }
;

/*======================================================
  statement: 
    - declaration
    - expression_statement
    - compound_statement
    - selection_statement (if / if-else)
    - iteration_statement (while + for 簡易)
    - jump_statement (return)
======================================================*/
statement:
    declaration {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = NULL;
        free($1.code);
    }
  | expression_statement {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = NULL;
        free($1.code);
    }
  | compound_statement {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = NULL;
        free($1.code);
    }
  | selection_statement {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = NULL;
        free($1.code);
    }
  | iteration_statement {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = NULL;
        free($1.code);
    }
  | jump_statement {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = NULL;
        free($1.code);
    }
  | error SEMICOLON {
        yyerror("語法錯誤");
        $$.code = strdup("");
        $$.place = NULL;
        yyerrok;
    }
;

/*======================================================
  expression_statement:
  - expression ;
  - ;
  $$.code = expression.code 或空
======================================================*/
expression_statement:
    expression SEMICOLON {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = NULL;
        free($1.code);
        free($1.place);
    }
  | SEMICOLON {
        $$.code = strdup("");
        $$.place = NULL;
    }
;

/*======================================================
  selection_statement: if / if-else
======================================================*/
selection_statement:
    IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
        /* if (cond) stmt; */
        char *label_true  = newLabel();
        char *label_end   = newLabel();

        char *cond_code  = $3.code;
        char *cond_place = $3.place;

        /* if cond goto label_true
           goto label_end
           label_true: stmt.code
           label_end: */
        char buf1[128], buf2[128], buf3[128];
        sprintf(buf1, "if %s goto %s", cond_place, label_true);
        sprintf(buf2, "goto %s", label_end);
        sprintf(buf3, "%s:", label_true);

        /* cond_code + if + goto + label_true + stmt.code + label_end */
        char *part1 = concat3(cond_code, buf1, buf2);
        char *part2 = concatCode(part1, buf3);
        free(part1);

        char *part3 = concatCode(part2, $5.code);
        free(part2);

        char buf_end[32];
        sprintf(buf_end, "%s:", label_end);
        char *whole = concatCode(part3, buf_end);
        free(part3);

        $$.code  = whole;
        $$.place = NULL;

        free(cond_code);
        free(cond_place);
        free($5.code);
        free(label_true);
        free(label_end);
    }
  | IF LPAREN expression RPAREN statement ELSE statement {
        /* if (cond) stmt1; else stmt2; */
        char *label_true  = newLabel();
        char *label_false = newLabel();
        char *label_end   = newLabel();

        char *cond_code  = $3.code;
        char *cond_place = $3.place;

        char buf1[128], buf2[128];
        sprintf(buf1, "if %s goto %s", cond_place, label_true);
        sprintf(buf2, "goto %s", label_false);

        /* cond_code + if + goto label_true + goto label_false */
        char *tmp1 = concatCode(cond_code, buf1);
        char *tmp2 = concatCode(tmp1, buf2);
        free(tmp1);

        /* label_true: stmt1; goto label_end */
        char buf_lt[32], buf_goto_end[32];
        sprintf(buf_lt, "%s:", label_true);
        sprintf(buf_goto_end, "goto %s", label_end);

        char *seg1 = concatCode(buf_lt, $5.code);
        char *seg2 = concatCode(seg1, buf_goto_end);
        free(seg1);

        /* label_false: stmt2 */
        char buf_lf[32];
        sprintf(buf_lf, "%s:", label_false);
        char *seg3 = concatCode(buf_lf, $7.code);

        /* label_end: */
        char buf_le[32];
        sprintf(buf_le, "%s:", label_end);

        /* 串接所有片段 */
        char *tmp3 = concatCode(tmp2, seg2);
        free(tmp2);
        char *tmp4 = concatCode(tmp3, seg3);
        free(tmp3);
        char *whole = concatCode(tmp4, buf_le);
        free(tmp4);

        $$.code  = whole;
        $$.place = NULL;

        free(cond_code);
        free(cond_place);
        free($5.code);
        free($7.code);
        free(label_true);
        free(label_false);
        free(label_end);
    }
;

/*======================================================
  iteration_statement: 支援簡易 FOR、完整 WHILE
======================================================*/
iteration_statement:
    FOR LPAREN statement statement expression RPAREN statement {
        /* 只是把 init, second, cond, body 的 code 串起來，不做真實 for-loop 轉換 */
        char *c1 = $3.code ? strdup($3.code) : strdup("");
        char *c2 = $4.code ? strdup($4.code) : strdup("");
        char *c3 = $5.code ? strdup($5.code) : strdup("");
        char *c4 = $7.code ? strdup($7.code) : strdup("");

        char *t12  = concatCode(c1, c2); free(c1); free(c2);
        char *t123 = concatCode(t12, c3); free(t12); free(c3);
        char *whole = concatCode(t123, c4); free(t123); free(c4);

        $$.code  = whole;
        $$.place = NULL;
    }
  | WHILE LPAREN expression RPAREN statement {
        /* while (cond) stmt; 轉成：
             Lstart:
               cond_code
               if cond_place goto Lbody
               goto Lend
             Lbody:
               stmt_code
               goto Lstart
             Lend:
        */
        char *label_start = newLabel();
        char *label_body  = newLabel();
        char *label_end   = newLabel();

        char *cond_code  = $3.code;
        char *cond_place = $3.place;

        char buf_if[128], buf_goto_end[128];
        sprintf(buf_if, "if %s goto %s", cond_place, label_body);
        sprintf(buf_goto_end, "goto %s", label_end);

        /* Lstart: */
        char buf_ls[32];
        sprintf(buf_ls, "%s:", label_start);
        char *part1 = concatCode(buf_ls, cond_code);
        char *part2 = concatCode(part1, buf_if);
        free(part1);
        char *part3 = concatCode(part2, buf_goto_end);
        free(part2);

        /* Lbody: stmt_code; goto Lstart */
        char buf_lb[32], buf_gs[32];
        sprintf(buf_lb, "%s:", label_body);
        sprintf(buf_gs, "goto %s", label_start);

        char *part4 = concatCode(buf_lb, $5.code);
        char *part5 = concatCode(part4, buf_gs);
        free(part4);

        /* Lend: */
        char buf_le[32];
        sprintf(buf_le, "%s:", label_end);

        /* 最後串接： part3 + part5 + buf_le */
        char *tmp1 = concatCode(part3, part5);
        free(part3);
        free(part5);
        char *whole = concatCode(tmp1, buf_le);
        free(tmp1);

        $$.code  = whole;
        $$.place = NULL;

        free(cond_code);
        free(cond_place);
        free($5.code);
        free(label_start);
        free(label_body);
        free(label_end);
    }
;

/*======================================================
  jump_statement: return expr;
  $$.code = expr.code + "return expr.place"
======================================================*/
jump_statement:
    RETURN expression SEMICOLON {
        char *expr_code  = $2.code;
        char *expr_place = $2.place;
        char buf[128];
        sprintf(buf, "return %s", expr_place);
        char *whole = concatCode(expr_code, buf);
        $$.code  = whole;
        $$.place = NULL;
        free(expr_code);
        free(expr_place);
    }
;

/*======================================================
  expression: 
   - ID = expression
   - function_call
   - simple_expression
   - sizeof(expr)
======================================================*/
expression:
    IDENTIFIER ASSIGN expression {
        char *rhs_code  = $3.code;
        char *rhs_place = $3.place;
        char buf[128];
        sprintf(buf, "%s = %s", $1, rhs_place);
        char *whole = concatCode(rhs_code, buf);
        $$.code  = whole;
        $$.place = strdup($1);
        free(rhs_code);
        free(rhs_place);
    }
  | function_call {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = $1.place ? strdup($1.place) : NULL;
        free($1.code);
        free($1.place);
    }
  | simple_expression {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = $1.place ? strdup($1.place) : NULL;
        free($1.code);
        free($1.place);
    }
  | SIZEOF LPAREN expression RPAREN {
        /* sizeof(E) 示範返回常數 4 */
        char *expr_code  = $3.code;
        char *expr_place = $3.place;
        char *t        = newTemp();
        char buf[128];
        sprintf(buf, "%s = 4  /* sizeof(%s) */", t, expr_place);
        char *whole = concatCode(expr_code, buf);
        $$.code  = whole;
        $$.place = strdup(t);
        free(expr_code);
        free(expr_place);
        free(t);
    }
;

/*======================================================
  function_call: ID ( args )
  回傳 place=newTemp(), code = 所有 args.code + call 指令
======================================================*/
function_call:
    IDENTIFIER LPAREN argument_list_opt RPAREN {
        char *args_code = $3.code;
        char *t = newTemp();
        char buf[128];
        if ($3.place) {
            sprintf(buf, "%s = call %s, %s", t, $1, $3.place);
        } else {
            sprintf(buf, "%s = call %s", t, $1);
        }
        char *whole = concatCode(args_code, buf);
        $$.code  = whole;
        $$.place = strdup(t);
        free(args_code);
        free($3.place);
        free(t);
    }
;

/*======================================================
  simple_expression: 加減與比較運算
======================================================*/
simple_expression:
    simple_expression PLUS term {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s + %s", t, $1.place, $3.place);
        char *c1 = concat3($1.code, $3.code, buf_op);
        $$.code  = c1;
        $$.place = strdup(t);
        free($1.code); free($1.place);
        free($3.code); free($3.place);
        free(t);
    }
  | simple_expression MINUS term {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s - %s", t, $1.place, $3.place);
        char *c1 = concat3($1.code, $3.code, buf_op);
        $$.code  = c1;
        $$.place = strdup(t);
        free($1.code); free($1.place);
        free($3.code); free($3.place);
        free(t);
    }
  | simple_expression EQ term {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s == %s", t, $1.place, $3.place);
        char *c1 = concat3($1.code, $3.code, buf_op);
        $$.code  = c1;
        $$.place = strdup(t);
        free($1.code); free($1.place);
        free($3.code); free($3.place);
        free(t);
    }
  | simple_expression NEQ term {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s != %s", t, $1.place, $3.place);
        char *c1 = concat3($1.code, $3.code, buf_op);
        $$.code  = c1;
        $$.place = strdup(t);
        free($1.code); free($1.place);
        free($3.code); free($3.place);
        free(t);
    }
  | simple_expression GT term {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s > %s", t, $1.place, $3.place);
        char *c1 = concat3($1.code, $3.code, buf_op);
        $$.code  = c1;
        $$.place = strdup(t);
        free($1.code); free($1.place);
        free($3.code); free($3.place);
        free(t);
    }
  | simple_expression LT term {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s < %s", t, $1.place, $3.place);
        char *c1 = concat3($1.code, $3.code, buf_op);
        $$.code  = c1;
        $$.place = strdup(t);
        free($1.code); free($1.place);
        free($3.code); free($3.place);
        free(t);
    }
  | simple_expression GE term {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s >= %s", t, $1.place, $3.place);
        char *c1 = concat3($1.code, $3.code, buf_op);
        $$.code  = c1;
        $$.place = strdup(t);
        free($1.code); free($1.place);
        free($3.code); free($3.place);
        free(t);
    }
  | simple_expression LE term {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s <= %s", t, $1.place, $3.place);
        char *c1 = concat3($1.code, $3.code, buf_op);
        $$.code  = c1;
        $$.place = strdup(t);
        free($1.code); free($1.place);
        free($3.code); free($3.place);
        free(t);
    }
  | term {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = $1.place ? strdup($1.place) : NULL;
        free($1.code);
        free($1.place);
    }
;

/*======================================================
  term: 乘除運算
======================================================*/
term:
    term MULT factor {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s * %s", t, $1.place, $3.place);
        char *c1 = concat3($1.code, $3.code, buf_op);
        $$.code  = c1;
        $$.place = strdup(t);
        free($1.code); free($1.place);
        free($3.code); free($3.place);
        free(t);
    }
  | term DIV factor {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s / %s", t, $1.place, $3.place);
        char *c1 = concat3($1.code, $3.code, buf_op);
        $$.code  = c1;
        $$.place = strdup(t);
        free($1.code); free($1.place);
        free($3.code); free($3.place);
        free(t);
    }
  | factor {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = $1.place ? strdup($1.place) : NULL;
        free($1.code);
        free($1.place);
    }
;

/*======================================================
  factor: 
   - (expression)
   - IDENTIFIER
   - x++ / x-- / ++x / --x
   - IDENTIFIER [ expression ]
   - NUMBER / STRING_LITERAL / FLOAT
======================================================*/
factor:
    LPAREN expression RPAREN {
        $$.code  = $2.code ? strdup($2.code) : strdup("");
        $$.place = $2.place ? strdup($2.place) : NULL;
        free($2.code);
        free($2.place);
    }
  | IDENTIFIER {
        $$.code  = strdup("");
        $$.place = strdup($1);
    }
  | IDENTIFIER INC {
        /* x++: 先把 x 放到 t，再 x = x+1 */
        char *t1 = newTemp();
        char buf1[128], buf2[128];
        sprintf(buf1, "%s = %s", t1, $1);
        sprintf(buf2, "%s = %s + 1", $1, $1);
        char *c1 = concatCode(buf1, buf2);
        $$.code  = c1;
        $$.place = strdup(t1);
        free(t1);
    }
  | IDENTIFIER DEC {
        /* x-- */
        char *t1 = newTemp();
        char buf1[128], buf2[128];
        sprintf(buf1, "%s = %s", t1, $1);
        sprintf(buf2, "%s = %s - 1", $1, $1);
        char *c1 = concatCode(buf1, buf2);
        $$.code  = c1;
        $$.place = strdup(t1);
        free(t1);
    }
  | INC IDENTIFIER {
        /* ++x: x = x+1, 然後把 x 放到 t */
        char *t1 = newTemp();
        char buf1[128], buf2[128];
        sprintf(buf1, "%s = %s + 1", $2, $2);
        sprintf(buf2, "%s = %s", t1, $2);
        char *c1 = concatCode(buf1, buf2);
        $$.code  = c1;
        $$.place = strdup(t1);
        free(t1);
    }
  | DEC IDENTIFIER {
        /* --x */
        char *t1 = newTemp();
        char buf1[128], buf2[128];
        sprintf(buf1, "%s = %s - 1", $2, $2);
        sprintf(buf2, "%s = %s", t1, $2);
        char *c1 = concatCode(buf1, buf2);
        $$.code  = c1;
        $$.place = strdup(t1);
        free(t1);
    }
  | IDENTIFIER LBRACKET expression RBRACKET {
        /* arr[E] 簡單假設：t = arr [ index ] */
        char *t1 = newTemp();
        char buf[128];
        sprintf(buf, "%s = %s [ %s ]", t1, $1, $3.place);
        char *c1 = concatCode($3.code, buf);
        $$.code  = c1;
        $$.place = strdup(t1);
        free($3.code);
        free($3.place);
        free(t1);
    }
  | NUMBER {
        $$.code  = strdup("");
        char buf[32];
        sprintf(buf, "%d", $1);
        $$.place = strdup(buf);
    }
  | STRING_LITERAL {
        $$.code  = strdup("");
        $$.place = strdup($1);
        free($1);
    }
  | FLOAT {
        $$.code  = strdup("");
        char buf[32];
        sprintf(buf, "%g", $1);
        $$.place = strdup(buf);
    }
;

/*======================================================
  argument_list_opt: (empty) 或 argument_list
  $$.place = 最後一個 argument 的 place；$$.code = 所有 args.code
======================================================*/
argument_list_opt:
    /* empty */ {
        $$.code  = strdup("");
        $$.place = NULL;
    }
  | argument_list {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = $1.place ? strdup($1.place) : NULL;
        free($1.code);
        free($1.place);
    }
;

/*======================================================
  argument_list: 多個 expression (右遞迴)
  $$.place = 最後一個 expr.place；$$.code = 左 + 右
======================================================*/
argument_list:
    expression {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = $1.place ? strdup($1.place) : NULL;
        free($1.code);
        free($1.place);
    }
  | argument_list COMMA expression {
        char *tmp = concatCode($1.code ? $1.code : "", $3.code ? $3.code : "");
        free($1.code);
        free($3.code);
        $$.code  = tmp;
        $$.place = strdup($3.place);
        free($3.place);
    }
;

/*======================================================
  array_initializer: 暫不做實作，只回傳空字串
======================================================*/
array_initializer:
    LBRACE initializer_list RBRACE {
        $$.code  = strdup("");
        $$.place = NULL;
    }
;

/*======================================================
  initializer_list: 暫不做實作，只串 expression
  $$.place 回傳最後一個 expression 的 place
======================================================*/
initializer_list:
    expression {
        $$.code  = $1.code ? strdup($1.code) : strdup("");
        $$.place = $1.place ? strdup($1.place) : NULL;
        free($1.code);
        free($1.place);
    }
  | initializer_list COMMA expression {
        char *tmp = concatCode($1.code ? $1.code : "", $3.code ? $3.code : "");
        free($1.code);
        free($3.code);
        $$.code  = tmp;
        $$.place = strdup($3.place);
        free($3.place);
    }
;

%%

/*======================================================
  錯誤處理
======================================================*/
void yyerror(const char *s) {
    int report_line = yylineno;
    fprintf(stderr, "❌ 語法錯誤：%s 在第 %d 行\n", s, report_line);
}

int main(int argc, char **argv) {
    yyparse();
    return 0;
}

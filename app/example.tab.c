/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "example.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
int yylex(void);
void yyerror(const char *s);

/* Expr 結構：code = 這個節點產生的 TAC，place = 運算式結果暫存器 */
struct exprType {
    char *code;
    char *place;
};

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



#line 124 "example.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "example.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 4,             /* STRING_LITERAL  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_SIZEOF = 7,                     /* SIZEOF  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_NEQ = 15,                       /* NEQ  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_ASSIGN = 20,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MINUS = 22,                     /* MINUS  */
  YYSYMBOL_MULT = 23,                      /* MULT  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_INC = 25,                       /* INC  */
  YYSYMBOL_DEC = 26,                       /* DEC  */
  YYSYMBOL_SEMICOLON = 27,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_LPAREN = 29,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 30,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 31,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 32,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 33,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 34,                  /* RBRACKET  */
  YYSYMBOL_LOWER_THAN_ELSE = 35,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_declarations = 38,              /* declarations  */
  YYSYMBOL_declaration = 39,               /* declaration  */
  YYSYMBOL_function_definition = 40,       /* function_definition  */
  YYSYMBOL_parameter_list_opt = 41,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 42,            /* parameter_list  */
  YYSYMBOL_compound_statement = 43,        /* compound_statement  */
  YYSYMBOL_statements = 44,                /* statements  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_expression_statement = 46,      /* expression_statement  */
  YYSYMBOL_selection_statement = 47,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 48,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 49,            /* jump_statement  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_function_call = 51,             /* function_call  */
  YYSYMBOL_simple_expression = 52,         /* simple_expression  */
  YYSYMBOL_term = 53,                      /* term  */
  YYSYMBOL_factor = 54,                    /* factor  */
  YYSYMBOL_argument_list_opt = 55,         /* argument_list_opt  */
  YYSYMBOL_argument_list = 56,             /* argument_list  */
  YYSYMBOL_array_initializer = 57,         /* array_initializer  */
  YYSYMBOL_initializer_list = 58           /* initializer_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,   109,   118,   130,   136,   149,   155,   161,
     175,   188,   193,   201,   206,   218,   231,   239,   256,   262,
     268,   273,   279,   285,   291,   307,   314,   325,   364,   425,
     440,   510,   531,   542,   548,   554,   575,   597,   608,   619,
     630,   641,   652,   663,   674,   685,   697,   708,   719,   736,
     742,   746,   757,   768,   779,   790,   802,   809,   814,   828,
     832,   845,   851,   865,   876,   882
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "STRING_LITERAL", "NUMBER", "FLOAT", "SIZEOF", "INT", "RETURN", "IF",
  "ELSE", "FOR", "WHILE", "EQ", "NEQ", "GE", "LE", "GT", "LT", "ASSIGN",
  "PLUS", "MINUS", "MULT", "DIV", "INC", "DEC", "SEMICOLON", "COMMA",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "LOWER_THAN_ELSE", "$accept", "program", "declarations", "declaration",
  "function_definition", "parameter_list_opt", "parameter_list",
  "compound_statement", "statements", "statement", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "expression", "function_call", "simple_expression", "term", "factor",
  "argument_list_opt", "argument_list", "array_initializer",
  "initializer_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-107)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,    25,    45,    15,  -107,  -107,    44,  -107,  -107,    37,
    -107,    29,    16,   -11,  -107,  -107,  -107,    27,    62,    71,
      37,    48,  -107,    96,    -4,  -107,    73,    59,    50,    34,
      37,  -107,  -107,    37,    37,    37,  -107,  -107,    63,  -107,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
    -107,    61,    87,    65,  -107,  -107,  -107,    67,    74,    72,
      69,  -107,   -20,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,  -107,  -107,  -107,  -107,    98,    37,    89,  -107,    37,
    -107,  -107,    26,  -107,  -107,   -25,  -107,  -107,   100,    37,
      99,   101,   102,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,   105,    37,  -107,  -107,   106,    37,    78,    37,
    -107,  -107,  -107,   104,    78,   107,    78,    37,    78,   118,
     108,  -107,    78,    78,  -107,  -107
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     9,     0,     1,     3,     0,
       5,    11,     0,    50,    57,    56,    58,     0,     0,     0,
       0,     0,    33,    34,    45,    48,     0,     0,    12,     0,
       0,    51,    52,    59,     0,     0,    53,    54,     0,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     7,    32,    61,     0,    60,     0,
       0,    49,    50,    39,    40,    43,    44,    41,    42,    37,
      38,    46,    47,    17,    10,     0,     0,     0,    36,     0,
      55,    35,     0,    14,    64,     0,     8,    62,     0,     0,
       0,     0,     0,    26,    15,    18,    20,    16,    19,    21,
      22,    23,     0,     0,    63,    24,     0,     0,     0,     0,
      25,    65,    31,     0,     0,     0,     0,     0,     0,    27,
       0,    30,     0,     0,    28,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -107,  -107,  -107,     1,  -107,  -107,  -107,    84,  -107,  -106,
    -107,  -107,  -107,  -107,    -9,  -107,  -107,    79,    11,  -107,
    -107,  -107,  -107
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    95,     5,    27,    28,    96,    82,    97,
      98,    99,   100,   101,   102,    22,    23,    24,    25,    57,
      58,    77,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      21,     4,   114,   103,     8,    31,    32,   104,   117,    30,
     119,    38,   121,    34,    31,    32,   124,   125,    33,    48,
      49,    55,    34,     1,    56,    59,    60,    88,     6,    13,
      14,    15,    16,    17,     1,    89,    90,    26,    91,    92,
      13,    14,    15,    16,    17,     7,    62,    14,    15,    16,
      29,    18,    19,    93,    53,    20,    35,    73,    94,    71,
      72,    54,    18,    19,     9,    36,    20,    84,    18,    19,
      87,    10,    20,    11,    37,    39,    50,    12,    52,    88,
     106,    13,    14,    15,    16,    17,     1,    89,    90,    51,
      91,    92,    73,    61,   111,    75,    76,    78,   113,    81,
     115,    83,    79,    18,    19,    93,    80,    20,   120,    73,
      40,    41,    42,    43,    44,    45,    86,    46,    47,    63,
      64,    65,    66,    67,    68,    69,    70,   105,   107,   122,
     108,   109,   110,   112,   116,    74,     0,   118,   123
};

static const yytype_int8 yycheck[] =
{
       9,     0,   108,    28,     3,    25,    26,    32,   114,    20,
     116,    20,   118,    33,    25,    26,   122,   123,    29,    23,
      24,    30,    33,     8,    33,    34,    35,     1,     3,     3,
       4,     5,     6,     7,     8,     9,    10,     8,    12,    13,
       3,     4,     5,     6,     7,     0,     3,     4,     5,     6,
      34,    25,    26,    27,    20,    29,    29,    31,    32,    48,
      49,    27,    25,    26,    20,     3,    29,    76,    25,    26,
      79,    27,    29,    29,     3,    27,     3,    33,    28,     1,
      89,     3,     4,     5,     6,     7,     8,     9,    10,    30,
      12,    13,    31,    30,   103,     8,    31,    30,   107,    30,
     109,     3,    28,    25,    26,    27,    34,    29,   117,    31,
      14,    15,    16,    17,    18,    19,    27,    21,    22,    40,
      41,    42,    43,    44,    45,    46,    47,    27,    29,    11,
      29,    29,    27,    27,    30,    51,    -1,    30,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    37,    38,    39,    40,     3,     0,    39,    20,
      27,    29,    33,     3,     4,     5,     6,     7,    25,    26,
      29,    50,    51,    52,    53,    54,     8,    41,    42,    34,
      20,    25,    26,    29,    33,    29,     3,     3,    50,    27,
      14,    15,    16,    17,    18,    19,    21,    22,    23,    24,
       3,    30,    28,    20,    27,    50,    50,    55,    56,    50,
      50,    30,     3,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    31,    43,     8,    31,    57,    30,    28,
      34,    30,    44,     3,    50,    58,    27,    50,     1,     9,
      10,    12,    13,    27,    32,    39,    43,    45,    46,    47,
      48,    49,    50,    28,    32,    27,    50,    29,    29,    29,
      27,    50,    27,    50,    45,    50,    30,    45,    30,    45,
      50,    45,    11,    30,    45,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    39,    39,
      40,    41,    41,    42,    42,    43,    44,    44,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    50,    50,    50,    50,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     5,     5,     7,     1,
       6,     0,     1,     2,     4,     3,     2,     0,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     5,     7,     7,
       5,     3,     3,     1,     1,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     0,
       1,     1,     3,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declarations  */
#line 96 "example.y"
                 {
        /* 印出整段 TAC */
        printf("%s", (yyvsp[0].EXPRTYPE)->code ? (yyvsp[0].EXPRTYPE)->code : "");
        printf("✅ 程式語法分析成功，共 %d 行\n", yylineno);
        free((yyvsp[0].EXPRTYPE)->code);
    }
#line 1528 "example.tab.c"
    break;

  case 3: /* declarations: declarations declaration  */
#line 109 "example.y"
                             {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        char *tmp = concatCode((yyvsp[-1].EXPRTYPE)->code ? (yyvsp[-1].EXPRTYPE)->code : "", (yyvsp[0].EXPRTYPE)->code ? (yyvsp[0].EXPRTYPE)->code : "");
        free((yyvsp[-1].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->code);
        (yyval.EXPRTYPE)->code = tmp;
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1542 "example.tab.c"
    break;

  case 4: /* declarations: declaration  */
#line 118 "example.y"
                {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1553 "example.tab.c"
    break;

  case 5: /* declaration: INT IDENTIFIER SEMICOLON  */
#line 130 "example.y"
                             {
        /* int x; 不產生 TAC */
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1564 "example.tab.c"
    break;

  case 6: /* declaration: INT IDENTIFIER ASSIGN expression SEMICOLON  */
#line 136 "example.y"
                                               {
        /* int x = expr; */
        char *expr_code  = (yyvsp[-1].EXPRTYPE)->code;
        char *expr_place = (yyvsp[-1].EXPRTYPE)->place;
        char buf[128];
        sprintf(buf, "%s = %s", (yyvsp[-3].str), expr_place);
        char *tmp = concatCode(expr_code, buf);
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code = tmp;
        (yyval.EXPRTYPE)->place = NULL;
        free(expr_code);
        free(expr_place);
    }
#line 1582 "example.tab.c"
    break;

  case 7: /* declaration: INT IDENTIFIER LBRACKET RBRACKET SEMICOLON  */
#line 149 "example.y"
                                               {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        /* int arr[]; (暫不實作) */
        (yyval.EXPRTYPE)->code = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1593 "example.tab.c"
    break;

  case 8: /* declaration: INT IDENTIFIER LBRACKET RBRACKET ASSIGN array_initializer SEMICOLON  */
#line 155 "example.y"
                                                                        {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        /* int arr[] = { ... }; (暫不實作) */
        (yyval.EXPRTYPE)->code = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1604 "example.tab.c"
    break;

  case 9: /* declaration: function_definition  */
#line 161 "example.y"
                        {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        /* 函式定義：直接把 body code 傳上來 */
        (yyval.EXPRTYPE)->code = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = NULL;
        free((yyvsp[0].EXPRTYPE)->code);
    }
#line 1616 "example.tab.c"
    break;

  case 10: /* function_definition: INT IDENTIFIER LPAREN parameter_list_opt RPAREN compound_statement  */
#line 175 "example.y"
                                                                       {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        char buf[128];
        sprintf(buf, "%s:", (yyvsp[-4].str));          /* foo: */
        char *tmp = concatCode(buf, (yyvsp[0].EXPRTYPE)->code);
        (yyval.EXPRTYPE)->code = tmp;
        (yyval.EXPRTYPE)->place = NULL;
        free((yyvsp[0].EXPRTYPE)->code);
    }
#line 1630 "example.tab.c"
    break;

  case 11: /* parameter_list_opt: %empty  */
#line 188 "example.y"
                {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1640 "example.tab.c"
    break;

  case 12: /* parameter_list_opt: parameter_list  */
#line 193 "example.y"
                   {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1650 "example.tab.c"
    break;

  case 13: /* parameter_list: INT IDENTIFIER  */
#line 201 "example.y"
                   {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1660 "example.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA INT IDENTIFIER  */
#line 206 "example.y"
                                        {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1670 "example.tab.c"
    break;

  case 15: /* compound_statement: LBRACE statements RBRACE  */
#line 218 "example.y"
                             {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code  = (yyvsp[-1].EXPRTYPE)->code ? strdup((yyvsp[-1].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = NULL;
        free((yyvsp[-1].EXPRTYPE)->code);
    }
#line 1681 "example.tab.c"
    break;

  case 16: /* statements: statements statement  */
#line 231 "example.y"
                         {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        char *tmp = concatCode((yyvsp[-1].EXPRTYPE)->code ? (yyvsp[-1].EXPRTYPE)->code : "", (yyvsp[0].EXPRTYPE)->code ? (yyvsp[0].EXPRTYPE)->code : "");
        free((yyvsp[-1].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->code);
        (yyval.EXPRTYPE)->code = tmp;
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1694 "example.tab.c"
    break;

  case 17: /* statements: %empty  */
#line 239 "example.y"
                {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1704 "example.tab.c"
    break;

  case 18: /* statement: declaration  */
#line 256 "example.y"
                {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = NULL;
        free((yyvsp[0].EXPRTYPE)->code);
    }
#line 1715 "example.tab.c"
    break;

  case 19: /* statement: expression_statement  */
#line 262 "example.y"
                         {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = NULL;
        free((yyvsp[0].EXPRTYPE)->code);
    }
#line 1726 "example.tab.c"
    break;

  case 20: /* statement: compound_statement  */
#line 268 "example.y"
                       {
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = NULL;
        free((yyvsp[0].EXPRTYPE)->code);
    }
#line 1736 "example.tab.c"
    break;

  case 21: /* statement: selection_statement  */
#line 273 "example.y"
                        {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = NULL;
        free((yyvsp[0].EXPRTYPE)->code);
    }
#line 1747 "example.tab.c"
    break;

  case 22: /* statement: iteration_statement  */
#line 279 "example.y"
                        {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = NULL;
        free((yyvsp[0].EXPRTYPE)->code);
    }
#line 1758 "example.tab.c"
    break;

  case 23: /* statement: jump_statement  */
#line 285 "example.y"
                   {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = NULL;
        free((yyvsp[0].EXPRTYPE)->code);
    }
#line 1769 "example.tab.c"
    break;

  case 24: /* statement: error SEMICOLON  */
#line 291 "example.y"
                    {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        yyerror("語法錯誤");
        (yyval.EXPRTYPE)->code = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
        yyerrok;
    }
#line 1781 "example.tab.c"
    break;

  case 25: /* expression_statement: expression SEMICOLON  */
#line 307 "example.y"
                         {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code  = (yyvsp[-1].EXPRTYPE)->code ? strdup((yyvsp[-1].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = NULL;
        free((yyvsp[-1].EXPRTYPE)->code);
        free((yyvsp[-1].EXPRTYPE)->place);
    }
#line 1793 "example.tab.c"
    break;

  case 26: /* expression_statement: SEMICOLON  */
#line 314 "example.y"
              {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        (yyval.EXPRTYPE)->code = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1803 "example.tab.c"
    break;

  case 27: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 325 "example.y"
                                                                {
        /* if (cond) stmt; */
        char *label_true  = newLabel();
        char *label_end   = newLabel();

        char *cond_code  = (yyvsp[-2].EXPRTYPE)->code;
        char *cond_place = (yyvsp[-2].EXPRTYPE)->place;

        /* if cond goto label_true
           goto label_end
           label_true: stmt->code
           label_end: */
        char buf1[128], buf2[128], buf3[128];
        sprintf(buf1, "if %s goto %s", cond_place, label_true);
        sprintf(buf2, "goto %s", label_end);
        sprintf(buf3, "%s:", label_true);

        /* cond_code + if + goto + label_true + stmt->code + label_end */
        char *part1 = concat3(cond_code, buf1, buf2);
        char *part2 = concatCode(part1, buf3);
        free(part1);

        char *part3 = concatCode(part2, (yyvsp[0].EXPRTYPE)->code);
        free(part2);

        char buf_end[32];
        sprintf(buf_end, "%s:", label_end);
        char *whole = concatCode(part3, buf_end);
        free(part3);

        (yyval.EXPRTYPE)->code  = whole;
        (yyval.EXPRTYPE)->place = NULL;

        free(cond_code);
        free(cond_place);
        free((yyvsp[0].EXPRTYPE)->code);
        free(label_true);
        free(label_end);
    }
#line 1847 "example.tab.c"
    break;

  case 28: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 364 "example.y"
                                                         {
        /* if (cond) stmt1; else stmt2; */
        char *label_true  = newLabel();
        char *label_false = newLabel();
        char *label_end   = newLabel();

        char *cond_code  = (yyvsp[-4].EXPRTYPE)->code;
        char *cond_place = (yyvsp[-4].EXPRTYPE)->place;

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

        char *seg1 = concatCode(buf_lt, (yyvsp[-2].EXPRTYPE)->code);
        char *seg2 = concatCode(seg1, buf_goto_end);
        free(seg1);

        /* label_false: stmt2 */
        char buf_lf[32];
        sprintf(buf_lf, "%s:", label_false);
        char *seg3 = concatCode(buf_lf, (yyvsp[0].EXPRTYPE)->code);

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

        (yyval.EXPRTYPE)->code  = whole;
        (yyval.EXPRTYPE)->place = NULL;

        free(cond_code);
        free(cond_place);
        free((yyvsp[-2].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->code);
        free(label_true);
        free(label_false);
        free(label_end);
    }
#line 1907 "example.tab.c"
    break;

  case 29: /* iteration_statement: FOR LPAREN statement statement expression RPAREN statement  */
#line 425 "example.y"
                                                               {
        (yyval.EXPRTYPE) = malloc(sizeof(struct exprType));
        /* 只是把 init, second, cond, body 的 code 串起來，不做真實 for-loop 轉換 */
        char *c1 = (yyvsp[-4].EXPRTYPE)->code ? strdup((yyvsp[-4].EXPRTYPE)->code) : strdup("");
        char *c2 = (yyvsp[-3].EXPRTYPE)->code ? strdup((yyvsp[-3].EXPRTYPE)->code) : strdup("");
        char *c3 = (yyvsp[-2].EXPRTYPE)->code ? strdup((yyvsp[-2].EXPRTYPE)->code) : strdup("");
        char *c4 = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");

        char *t12  = concatCode(c1, c2); free(c1); free(c2);
        char *t123 = concatCode(t12, c3); free(t12); free(c3);
        char *whole = concatCode(t123, c4); free(t123); free(c4);

        (yyval.EXPRTYPE)->code  = whole;
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 1927 "example.tab.c"
    break;

  case 30: /* iteration_statement: WHILE LPAREN expression RPAREN statement  */
#line 440 "example.y"
                                             {
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

        char *cond_code  = (yyvsp[-2].EXPRTYPE)->code;
        char *cond_place = (yyvsp[-2].EXPRTYPE)->place;

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

        /* 這裡原本用錯 $6->code，正確應為 $5->code */
        char *part4 = concatCode(buf_lb, (yyvsp[0].EXPRTYPE)->code);
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

        (yyval.EXPRTYPE)->code  = whole;
        (yyval.EXPRTYPE)->place = NULL;

        /* 對應地，free 也要改成 $5->code */
        free(cond_code);
        free(cond_place);
        free((yyvsp[0].EXPRTYPE)->code);
        free(label_start);
        free(label_body);
        free(label_end);
    }
#line 1995 "example.tab.c"
    break;

  case 31: /* jump_statement: RETURN expression SEMICOLON  */
#line 510 "example.y"
                                {
        char *expr_code  = (yyvsp[-1].EXPRTYPE)->code;
        char *expr_place = (yyvsp[-1].EXPRTYPE)->place;
        char buf[128];
        sprintf(buf, "return %s", expr_place);
        char *whole = concatCode(expr_code, buf);
        (yyval.EXPRTYPE)->code  = whole;
        (yyval.EXPRTYPE)->place = NULL;
        free(expr_code);
        free(expr_place);
    }
#line 2011 "example.tab.c"
    break;

  case 32: /* expression: IDENTIFIER ASSIGN expression  */
#line 531 "example.y"
                                 {
        char *rhs_code  = (yyvsp[0].EXPRTYPE)->code;
        char *rhs_place = (yyvsp[0].EXPRTYPE)->place;
        char buf[128];
        sprintf(buf, "%s = %s", (yyvsp[-2].str), rhs_place);
        char *whole = concatCode(rhs_code, buf);
        (yyval.EXPRTYPE)->code  = whole;
        (yyval.EXPRTYPE)->place = strdup((yyvsp[-2].str));
        free(rhs_code);
        free(rhs_place);
    }
#line 2027 "example.tab.c"
    break;

  case 33: /* expression: function_call  */
#line 542 "example.y"
                  {
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = (yyvsp[0].EXPRTYPE)->place ? strdup((yyvsp[0].EXPRTYPE)->place) : NULL;
        free((yyvsp[0].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->place);
    }
#line 2038 "example.tab.c"
    break;

  case 34: /* expression: simple_expression  */
#line 548 "example.y"
                      {
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = (yyvsp[0].EXPRTYPE)->place ? strdup((yyvsp[0].EXPRTYPE)->place) : NULL;
        free((yyvsp[0].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->place);
    }
#line 2049 "example.tab.c"
    break;

  case 35: /* expression: SIZEOF LPAREN expression RPAREN  */
#line 554 "example.y"
                                    {
        /* sizeof(E) 示範返回常數 4 */
        char *expr_code  = (yyvsp[-1].EXPRTYPE)->code;
        char *expr_place = (yyvsp[-1].EXPRTYPE)->place;
        char *t        = newTemp();
        char buf[128];
        sprintf(buf, "%s = 4  /* sizeof(%s) */", t, expr_place);
        char *whole = concatCode(expr_code, buf);
        (yyval.EXPRTYPE)->code  = whole;
        (yyval.EXPRTYPE)->place = strdup(t);
        free(expr_code);
        free(expr_place);
        free(t);
    }
#line 2068 "example.tab.c"
    break;

  case 36: /* function_call: IDENTIFIER LPAREN argument_list_opt RPAREN  */
#line 575 "example.y"
                                               {
        char *args_code = (yyvsp[-1].EXPRTYPE)->code;
        char *t = newTemp();
        char buf[128];
        if ((yyvsp[-1].EXPRTYPE)->place) {
            sprintf(buf, "%s = call %s, %s", t, (yyvsp[-3].str), (yyvsp[-1].EXPRTYPE)->place);
        } else {
            sprintf(buf, "%s = call %s", t, (yyvsp[-3].str));
        }
        char *whole = concatCode(args_code, buf);
        (yyval.EXPRTYPE)->code  = whole;
        (yyval.EXPRTYPE)->place = strdup(t);
        free(args_code);
        free((yyvsp[-1].EXPRTYPE)->place);
        free(t);
    }
#line 2089 "example.tab.c"
    break;

  case 37: /* simple_expression: simple_expression PLUS term  */
#line 597 "example.y"
                                {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s + %s", t, (yyvsp[-2].EXPRTYPE)->place, (yyvsp[0].EXPRTYPE)->place);
        char *c1 = concat3((yyvsp[-2].EXPRTYPE)->code, (yyvsp[0].EXPRTYPE)->code, buf_op);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t);
        free((yyvsp[-2].EXPRTYPE)->code); free((yyvsp[-2].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->code); free((yyvsp[0].EXPRTYPE)->place);
        free(t);
    }
#line 2105 "example.tab.c"
    break;

  case 38: /* simple_expression: simple_expression MINUS term  */
#line 608 "example.y"
                                 {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s - %s", t, (yyvsp[-2].EXPRTYPE)->place, (yyvsp[0].EXPRTYPE)->place);
        char *c1 = concat3((yyvsp[-2].EXPRTYPE)->code, (yyvsp[0].EXPRTYPE)->code, buf_op);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t);
        free((yyvsp[-2].EXPRTYPE)->code); free((yyvsp[-2].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->code); free((yyvsp[0].EXPRTYPE)->place);
        free(t);
    }
#line 2121 "example.tab.c"
    break;

  case 39: /* simple_expression: simple_expression EQ term  */
#line 619 "example.y"
                              {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s == %s", t, (yyvsp[-2].EXPRTYPE)->place, (yyvsp[0].EXPRTYPE)->place);
        char *c1 = concat3((yyvsp[-2].EXPRTYPE)->code, (yyvsp[0].EXPRTYPE)->code, buf_op);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t);
        free((yyvsp[-2].EXPRTYPE)->code); free((yyvsp[-2].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->code); free((yyvsp[0].EXPRTYPE)->place);
        free(t);
    }
#line 2137 "example.tab.c"
    break;

  case 40: /* simple_expression: simple_expression NEQ term  */
#line 630 "example.y"
                               {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s != %s", t, (yyvsp[-2].EXPRTYPE)->place, (yyvsp[0].EXPRTYPE)->place);
        char *c1 = concat3((yyvsp[-2].EXPRTYPE)->code, (yyvsp[0].EXPRTYPE)->code, buf_op);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t);
        free((yyvsp[-2].EXPRTYPE)->code); free((yyvsp[-2].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->code); free((yyvsp[0].EXPRTYPE)->place);
        free(t);
    }
#line 2153 "example.tab.c"
    break;

  case 41: /* simple_expression: simple_expression GT term  */
#line 641 "example.y"
                              {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s > %s", t, (yyvsp[-2].EXPRTYPE)->place, (yyvsp[0].EXPRTYPE)->place);
        char *c1 = concat3((yyvsp[-2].EXPRTYPE)->code, (yyvsp[0].EXPRTYPE)->code, buf_op);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t);
        free((yyvsp[-2].EXPRTYPE)->code); free((yyvsp[-2].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->code); free((yyvsp[0].EXPRTYPE)->place);
        free(t);
    }
#line 2169 "example.tab.c"
    break;

  case 42: /* simple_expression: simple_expression LT term  */
#line 652 "example.y"
                              {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s < %s", t, (yyvsp[-2].EXPRTYPE)->place, (yyvsp[0].EXPRTYPE)->place);
        char *c1 = concat3((yyvsp[-2].EXPRTYPE)->code, (yyvsp[0].EXPRTYPE)->code, buf_op);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t);
        free((yyvsp[-2].EXPRTYPE)->code); free((yyvsp[-2].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->code); free((yyvsp[0].EXPRTYPE)->place);
        free(t);
    }
#line 2185 "example.tab.c"
    break;

  case 43: /* simple_expression: simple_expression GE term  */
#line 663 "example.y"
                              {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s >= %s", t, (yyvsp[-2].EXPRTYPE)->place, (yyvsp[0].EXPRTYPE)->place);
        char *c1 = concat3((yyvsp[-2].EXPRTYPE)->code, (yyvsp[0].EXPRTYPE)->code, buf_op);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t);
        free((yyvsp[-2].EXPRTYPE)->code); free((yyvsp[-2].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->code); free((yyvsp[0].EXPRTYPE)->place);
        free(t);
    }
#line 2201 "example.tab.c"
    break;

  case 44: /* simple_expression: simple_expression LE term  */
#line 674 "example.y"
                              {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s <= %s", t, (yyvsp[-2].EXPRTYPE)->place, (yyvsp[0].EXPRTYPE)->place);
        char *c1 = concat3((yyvsp[-2].EXPRTYPE)->code, (yyvsp[0].EXPRTYPE)->code, buf_op);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t);
        free((yyvsp[-2].EXPRTYPE)->code); free((yyvsp[-2].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->code); free((yyvsp[0].EXPRTYPE)->place);
        free(t);
    }
#line 2217 "example.tab.c"
    break;

  case 45: /* simple_expression: term  */
#line 685 "example.y"
         {
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = (yyvsp[0].EXPRTYPE)->place ? strdup((yyvsp[0].EXPRTYPE)->place) : NULL;
        free((yyvsp[0].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->place);
    }
#line 2228 "example.tab.c"
    break;

  case 46: /* term: term MULT factor  */
#line 697 "example.y"
                     {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s * %s", t, (yyvsp[-2].EXPRTYPE)->place, (yyvsp[0].EXPRTYPE)->place);
        char *c1 = concat3((yyvsp[-2].EXPRTYPE)->code, (yyvsp[0].EXPRTYPE)->code, buf_op);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t);
        free((yyvsp[-2].EXPRTYPE)->code); free((yyvsp[-2].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->code); free((yyvsp[0].EXPRTYPE)->place);
        free(t);
    }
#line 2244 "example.tab.c"
    break;

  case 47: /* term: term DIV factor  */
#line 708 "example.y"
                    {
        char *t = newTemp();
        char buf_op[128];
        sprintf(buf_op, "%s = %s / %s", t, (yyvsp[-2].EXPRTYPE)->place, (yyvsp[0].EXPRTYPE)->place);
        char *c1 = concat3((yyvsp[-2].EXPRTYPE)->code, (yyvsp[0].EXPRTYPE)->code, buf_op);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t);
        free((yyvsp[-2].EXPRTYPE)->code); free((yyvsp[-2].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->code); free((yyvsp[0].EXPRTYPE)->place);
        free(t);
    }
#line 2260 "example.tab.c"
    break;

  case 48: /* term: factor  */
#line 719 "example.y"
           {
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = (yyvsp[0].EXPRTYPE)->place ? strdup((yyvsp[0].EXPRTYPE)->place) : NULL;
        free((yyvsp[0].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->place);
    }
#line 2271 "example.tab.c"
    break;

  case 49: /* factor: LPAREN expression RPAREN  */
#line 736 "example.y"
                             {
        (yyval.EXPRTYPE)->code  = (yyvsp[-1].EXPRTYPE)->code ? strdup((yyvsp[-1].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = (yyvsp[-1].EXPRTYPE)->place ? strdup((yyvsp[-1].EXPRTYPE)->place) : NULL;
        free((yyvsp[-1].EXPRTYPE)->code);
        free((yyvsp[-1].EXPRTYPE)->place);
    }
#line 2282 "example.tab.c"
    break;

  case 50: /* factor: IDENTIFIER  */
#line 742 "example.y"
               {
        (yyval.EXPRTYPE)->code  = strdup("");
        (yyval.EXPRTYPE)->place = strdup((yyvsp[0].str));
    }
#line 2291 "example.tab.c"
    break;

  case 51: /* factor: IDENTIFIER INC  */
#line 746 "example.y"
                   {
        /* x++: 先把 x 放到 t，再 x = x+1 */
        char *t1 = newTemp();
        char buf1[128], buf2[128];
        sprintf(buf1, "%s = %s", t1, (yyvsp[-1].str));
        sprintf(buf2, "%s = %s + 1", (yyvsp[-1].str), (yyvsp[-1].str));
        char *c1 = concatCode(buf1, buf2);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t1);
        free(t1);
    }
#line 2307 "example.tab.c"
    break;

  case 52: /* factor: IDENTIFIER DEC  */
#line 757 "example.y"
                   {
        /* x-- */
        char *t1 = newTemp();
        char buf1[128], buf2[128];
        sprintf(buf1, "%s = %s", t1, (yyvsp[-1].str));
        sprintf(buf2, "%s = %s - 1", (yyvsp[-1].str), (yyvsp[-1].str));
        char *c1 = concatCode(buf1, buf2);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t1);
        free(t1);
    }
#line 2323 "example.tab.c"
    break;

  case 53: /* factor: INC IDENTIFIER  */
#line 768 "example.y"
                   {
        /* ++x: x = x+1, 然後把 x 放到 t */
        char *t1 = newTemp();
        char buf1[128], buf2[128];
        sprintf(buf1, "%s = %s + 1", (yyvsp[0].str), (yyvsp[0].str));
        sprintf(buf2, "%s = %s", t1, (yyvsp[0].str));
        char *c1 = concatCode(buf1, buf2);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t1);
        free(t1);
    }
#line 2339 "example.tab.c"
    break;

  case 54: /* factor: DEC IDENTIFIER  */
#line 779 "example.y"
                   {
        /* --x */
        char *t1 = newTemp();
        char buf1[128], buf2[128];
        sprintf(buf1, "%s = %s - 1", (yyvsp[0].str), (yyvsp[0].str));
        sprintf(buf2, "%s = %s", t1, (yyvsp[0].str));
        char *c1 = concatCode(buf1, buf2);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t1);
        free(t1);
    }
#line 2355 "example.tab.c"
    break;

  case 55: /* factor: IDENTIFIER LBRACKET expression RBRACKET  */
#line 790 "example.y"
                                            {
        /* arr[E] 簡單假設：t = arr [ index ] */
        char *t1 = newTemp();
        char buf[128];
        sprintf(buf, "%s = %s [ %s ]", t1, (yyvsp[-3].str), (yyvsp[-1].EXPRTYPE)->place);
        char *c1 = concatCode((yyvsp[-1].EXPRTYPE)->code, buf);
        (yyval.EXPRTYPE)->code  = c1;
        (yyval.EXPRTYPE)->place = strdup(t1);
        free((yyvsp[-1].EXPRTYPE)->code);
        free((yyvsp[-1].EXPRTYPE)->place);
        free(t1);
    }
#line 2372 "example.tab.c"
    break;

  case 56: /* factor: NUMBER  */
#line 802 "example.y"
           {
        (yyval.EXPRTYPE)->code  = strdup("");
        char buf[32];
        /* 這兒改用 %d 來處理整數 */
        sprintf(buf, "%d", (yyvsp[0].num));
        (yyval.EXPRTYPE)->place = strdup(buf);
    }
#line 2384 "example.tab.c"
    break;

  case 57: /* factor: STRING_LITERAL  */
#line 809 "example.y"
                   {
        (yyval.EXPRTYPE)->code  = strdup("");
        (yyval.EXPRTYPE)->place = strdup((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 2394 "example.tab.c"
    break;

  case 58: /* factor: FLOAT  */
#line 814 "example.y"
          {
        (yyval.EXPRTYPE)->code  = strdup("");
        char buf[32];
        /* FLOAT 用 %g 處理浮點 */
        sprintf(buf, "%g", (yyvsp[0].dbl));
        (yyval.EXPRTYPE)->place = strdup(buf);
    }
#line 2406 "example.tab.c"
    break;

  case 59: /* argument_list_opt: %empty  */
#line 828 "example.y"
                {
        (yyval.EXPRTYPE)->code  = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 2415 "example.tab.c"
    break;

  case 60: /* argument_list_opt: argument_list  */
#line 832 "example.y"
                  {
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = (yyvsp[0].EXPRTYPE)->place ? strdup((yyvsp[0].EXPRTYPE)->place) : NULL;
        free((yyvsp[0].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->place);
    }
#line 2426 "example.tab.c"
    break;

  case 61: /* argument_list: expression  */
#line 845 "example.y"
               {
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = (yyvsp[0].EXPRTYPE)->place ? strdup((yyvsp[0].EXPRTYPE)->place) : NULL;
        free((yyvsp[0].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->place);
    }
#line 2437 "example.tab.c"
    break;

  case 62: /* argument_list: argument_list COMMA expression  */
#line 851 "example.y"
                                   {
        char *tmp = concatCode((yyvsp[-2].EXPRTYPE)->code ? (yyvsp[-2].EXPRTYPE)->code : "", (yyvsp[0].EXPRTYPE)->code ? (yyvsp[0].EXPRTYPE)->code : "");
        free((yyvsp[-2].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->code);
        (yyval.EXPRTYPE)->code  = tmp;
        (yyval.EXPRTYPE)->place = strdup((yyvsp[0].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->place);
    }
#line 2450 "example.tab.c"
    break;

  case 63: /* array_initializer: LBRACE initializer_list RBRACE  */
#line 865 "example.y"
                                   {
        (yyval.EXPRTYPE)->code  = strdup("");
        (yyval.EXPRTYPE)->place = NULL;
    }
#line 2459 "example.tab.c"
    break;

  case 64: /* initializer_list: expression  */
#line 876 "example.y"
               {
        (yyval.EXPRTYPE)->code  = (yyvsp[0].EXPRTYPE)->code ? strdup((yyvsp[0].EXPRTYPE)->code) : strdup("");
        (yyval.EXPRTYPE)->place = (yyvsp[0].EXPRTYPE)->place ? strdup((yyvsp[0].EXPRTYPE)->place) : NULL;
        free((yyvsp[0].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->place);
    }
#line 2470 "example.tab.c"
    break;

  case 65: /* initializer_list: initializer_list COMMA expression  */
#line 882 "example.y"
                                      {
        char *tmp = concatCode((yyvsp[-2].EXPRTYPE)->code ? (yyvsp[-2].EXPRTYPE)->code : "", (yyvsp[0].EXPRTYPE)->code ? (yyvsp[0].EXPRTYPE)->code : "");
        free((yyvsp[-2].EXPRTYPE)->code);
        free((yyvsp[0].EXPRTYPE)->code);
        (yyval.EXPRTYPE)->code  = tmp;
        (yyval.EXPRTYPE)->place = strdup((yyvsp[0].EXPRTYPE)->place);
        free((yyvsp[0].EXPRTYPE)->place);
    }
#line 2483 "example.tab.c"
    break;


#line 2487 "example.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 892 "example.y"


/*======================================================
  錯誤處理
======================================================*/
void yyerror(const char *s) {
    fprintf(stderr, "❌ 語法錯誤：%s 在第 %d 行\n", s, yylineno);
}

int main(int argc, char **argv) {
    yyparse();
    return 0;
}

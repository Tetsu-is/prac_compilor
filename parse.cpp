/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     lex_KW_INT = 258,
     lex_KW_CHAR = 259,
     lex_KW_IF = 260,
     lex_KW_ELSE = 261,
     lex_KW_WHILE = 262,
     lex_KW_RETURN = 263,
     lex_PLUS = 264,
     lex_MINUS = 265,
     lex_STAR = 266,
     lex_SLASH = 267,
     lex_PERCENT = 268,
     lex_AND = 269,
     lex_EQ = 270,
     lex_EQEQ = 271,
     lex_NE = 272,
     lex_LT = 273,
     lex_GT = 274,
     lex_LE = 275,
     lex_GE = 276,
     lex_COMMA = 277,
     lex_SEMICOLON = 278,
     lex_LPAREN = 279,
     lex_RPAREN = 280,
     lex_LBRACE = 281,
     lex_RBRACE = 282,
     lex_LBRACK = 283,
     lex_RBRACK = 284,
     lex_INT = 285,
     lex_CHAR = 286,
     lex_ID = 287
   };
#endif
/* Tokens.  */
#define lex_KW_INT 258
#define lex_KW_CHAR 259
#define lex_KW_IF 260
#define lex_KW_ELSE 261
#define lex_KW_WHILE 262
#define lex_KW_RETURN 263
#define lex_PLUS 264
#define lex_MINUS 265
#define lex_STAR 266
#define lex_SLASH 267
#define lex_PERCENT 268
#define lex_AND 269
#define lex_EQ 270
#define lex_EQEQ 271
#define lex_NE 272
#define lex_LT 273
#define lex_GT 274
#define lex_LE 275
#define lex_GE 276
#define lex_COMMA 277
#define lex_SEMICOLON 278
#define lex_LPAREN 279
#define lex_RPAREN 280
#define lex_LBRACE 281
#define lex_RBRACE 282
#define lex_LBRACK 283
#define lex_RBRACK 284
#define lex_INT 285
#define lex_CHAR 286
#define lex_ID 287




/* Copy the first part of user declarations.  */
#line 1 "parse.yy"

//=====================================================================
//
//     parse.yy: mini-C プログラムの構文解析系生成用記述
//
//            コンパイラ演習  2004 (c) 平岡佑介, 石浦菜岐佐
//
//=====================================================================

// --------------------------------------------------------------------
// [Part-1] ヘッダやグローバル変数, 関数の宣言
// --------------------------------------------------------------------

#include "ast.h"
#include <cstdio>

extern int linenum;
extern std::FILE* yyin;

int yylex(void);
void yyerror(const char*);

Program* ast;
Program* build_program(Declaration_t* dd);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 32 "parse.yy"
{
  char* string;
  int val;
  Expression* expression;
  Exp_variable* exp_variable;
  std::list<Expression*>* explist;
  Statement* statement;
  std::list<Statement*> * stlist;
  Variable* variable;
  Type type;
  Function* function;
  std::list<Variable*>* vars;
  Declaration_t* declaration_data;
}
/* Line 193 of yacc.c.  */
#line 202 "parse.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 215 "parse.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNRULES -- Number of states.  */
#define YYNSTATES  102

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,    10,    13,    23,    24,    26,
      30,    31,    35,    38,    40,    42,    44,    48,    50,    52,
      54,    56,    61,    63,    64,    67,    73,    81,    87,    91,
      97,    99,   101,   103,   107,   109,   114,   115,   117,   121,
     123,   125,   129,   133,   137,   139,   142,   145,   149,   153,
     155,   159,   163,   167,   171,   175
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    -1,    35,    39,    23,    -1,
      35,    36,    -1,    40,    32,    24,    37,    25,    26,    38,
      43,    27,    -1,    -1,    39,    -1,    37,    22,    39,    -1,
      -1,    38,    39,    23,    -1,    40,    32,    -1,     3,    -1,
       4,    -1,    42,    -1,    26,    43,    27,    -1,    45,    -1,
      46,    -1,    47,    -1,    48,    -1,    52,    15,    55,    23,
      -1,    44,    -1,    -1,    44,    41,    -1,     5,    24,    55,
      25,    41,    -1,     5,    24,    55,    25,    41,     6,    41,
      -1,     7,    24,    55,    25,    41,    -1,     8,    55,    23,
      -1,    32,    24,    51,    25,    23,    -1,    30,    -1,    31,
      -1,    52,    -1,    24,    55,    25,    -1,    50,    -1,    32,
      24,    51,    25,    -1,    -1,    55,    -1,    51,    22,    55,
      -1,    32,    -1,    49,    -1,    53,    11,    49,    -1,    53,
      12,    49,    -1,    53,    13,    49,    -1,    53,    -1,     9,
      53,    -1,    10,    53,    -1,    54,     9,    53,    -1,    54,
      10,    53,    -1,    54,    -1,    55,    18,    54,    -1,    55,
      19,    54,    -1,    55,    20,    54,    -1,    55,    21,    54,
      -1,    55,    16,    54,    -1,    55,    17,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   114,   117,   122,   129,   138,   141,   146,
     155,   158,   165,   171,   175,   181,   182,   183,   184,   185,
     186,   189,   195,   203,   206,   213,   217,   223,   229,   235,
     241,   245,   249,   253,   257,   263,   271,   274,   279,   286,
     292,   296,   300,   304,   310,   314,   318,   322,   326,   332,
     336,   340,   344,   348,   352,   356
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "lex_KW_INT", "lex_KW_CHAR", "lex_KW_IF",
  "lex_KW_ELSE", "lex_KW_WHILE", "lex_KW_RETURN", "lex_PLUS", "lex_MINUS",
  "lex_STAR", "lex_SLASH", "lex_PERCENT", "lex_AND", "lex_EQ", "lex_EQEQ",
  "lex_NE", "lex_LT", "lex_GT", "lex_LE", "lex_GE", "lex_COMMA",
  "lex_SEMICOLON", "lex_LPAREN", "lex_RPAREN", "lex_LBRACE", "lex_RBRACE",
  "lex_LBRACK", "lex_RBRACK", "lex_INT", "lex_CHAR", "lex_ID", "$accept",
  "program", "dcllist", "function_dcl", "argument_dcllist",
  "variable_dcllist", "variable_dcl", "type", "statement", "st_assign",
  "st_list", "stlist", "st_if", "st_while", "st_return", "st_function",
  "expression4", "exp_function", "explist", "exp_variable", "expression3",
  "expression2", "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    35,    36,    37,    37,    37,
      38,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      41,    42,    43,    44,    44,    45,    45,    46,    47,    48,
      49,    49,    49,    49,    49,    50,    51,    51,    51,    52,
      53,    53,    53,    53,    54,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     2,     9,     0,     1,     3,
       0,     3,     2,     1,     1,     1,     3,     1,     1,     1,
       1,     4,     1,     0,     2,     5,     7,     5,     3,     5,
       1,     1,     1,     3,     1,     4,     0,     1,     3,     1,
       1,     3,     3,     3,     1,     2,     2,     3,     3,     1,
       3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,    13,    14,     5,     0,     0,     4,
      12,     7,     0,     8,     0,     0,     0,    12,     9,    10,
      23,     0,     0,    22,    11,     6,     0,     0,     0,    23,
      39,    24,    15,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,    30,    31,    39,    40,    34,    32,    44,
      49,     0,     0,    36,     0,     0,     0,    45,    46,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    16,     0,    37,     0,     0,     0,    33,
       0,    41,    42,    43,    47,    48,    54,    55,    50,    51,
      52,    53,     0,     0,    21,    25,    27,    35,    38,    29,
       0,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,    12,    20,     7,    14,    31,    32,
      22,    23,    33,    34,    35,    36,    46,    47,    74,    48,
      49,    50,    75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -69
static const yytype_int8 yypact[] =
{
     -69,     3,    55,   -69,   -69,   -69,   -69,   -15,   -10,   -69,
       2,    55,    39,   -69,    -8,    55,     7,   -69,   -69,   -69,
      55,    40,    48,    -3,   -69,   -69,    60,    79,     4,   -69,
      85,   -69,   -69,   -69,   -69,   -69,   -69,    95,     4,     4,
      36,    36,     4,   -69,   -69,    87,   -69,   -69,   -69,    32,
      98,    53,    73,     4,     4,     0,    21,    32,    32,    31,
       4,    36,    36,    36,    36,    36,     4,     4,     4,     4,
       4,     4,   -69,   -69,    76,    70,    62,    -3,    -3,   -69,
      77,   -69,   -69,   -69,    32,    32,    98,    98,    98,    98,
      98,    98,     4,    89,   -69,   107,   -69,   -69,    70,   -69,
      -3,   -69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -69,   -69,   -69,   -69,    42,   112,   -68,   -69,
      86,   -69,   -69,   -69,   -69,   -69,    43,   -69,    56,   -23,
     -34,    26,   -27
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      37,    51,    26,     3,    27,    28,    57,    58,     9,    95,
      96,    55,    56,    40,    41,    59,    66,    67,    68,    69,
      70,    71,    10,    29,    17,    77,    11,    76,    42,    30,
      84,    85,   101,    19,    43,    44,    45,    66,    67,    68,
      69,    70,    71,    61,    62,    63,    78,    66,    67,    68,
      69,    70,    71,    13,    37,    37,    79,    18,     4,     5,
      42,    15,    21,    24,    16,    98,    43,    44,    45,    66,
      67,    68,    69,    70,    71,    25,    72,    37,    66,    67,
      68,    69,    70,    71,    38,    94,    66,    67,    68,    69,
      70,    71,    86,    87,    88,    89,    90,    91,    92,    92,
      73,    93,    97,    39,    81,    82,    83,    64,    65,    53,
      54,    60,    99,   100,     8,    52,    80
};

static const yytype_uint8 yycheck[] =
{
      23,    28,     5,     0,     7,     8,    40,    41,    23,    77,
      78,    38,    39,     9,    10,    42,    16,    17,    18,    19,
      20,    21,    32,    26,    32,    25,    24,    54,    24,    32,
      64,    65,   100,    26,    30,    31,    32,    16,    17,    18,
      19,    20,    21,    11,    12,    13,    25,    16,    17,    18,
      19,    20,    21,    11,    77,    78,    25,    15,     3,     4,
      24,    22,    20,    23,    25,    92,    30,    31,    32,    16,
      17,    18,    19,    20,    21,    27,    23,   100,    16,    17,
      18,    19,    20,    21,    24,    23,    16,    17,    18,    19,
      20,    21,    66,    67,    68,    69,    70,    71,    22,    22,
      27,    25,    25,    24,    61,    62,    63,     9,    10,    24,
      15,    24,    23,     6,     2,    29,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    35,     0,     3,     4,    36,    39,    40,    23,
      32,    24,    37,    39,    40,    22,    25,    32,    39,    26,
      38,    39,    43,    44,    23,    27,     5,     7,     8,    26,
      32,    41,    42,    45,    46,    47,    48,    52,    24,    24,
       9,    10,    24,    30,    31,    32,    49,    50,    52,    53,
      54,    55,    43,    24,    15,    55,    55,    53,    53,    55,
      24,    11,    12,    13,     9,    10,    16,    17,    18,    19,
      20,    21,    23,    27,    51,    55,    55,    25,    25,    25,
      51,    49,    49,    49,    53,    53,    54,    54,    54,    54,
      54,    54,    22,    25,    23,    41,    41,    25,    55,    23,
       6,    41
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 108 "parse.yy"
    {
  ast = build_program((yyvsp[(1) - (1)].declaration_data));
;}
    break;

  case 3:
#line 114 "parse.yy"
    {
  (yyval.declaration_data) = new Declaration_t;
;}
    break;

  case 4:
#line 118 "parse.yy"
    {
  (yyvsp[(1) - (3)].declaration_data)->vars.push_back((yyvsp[(2) - (3)].variable));
  (yyval.declaration_data) = (yyvsp[(1) - (3)].declaration_data);
;}
    break;

  case 5:
#line 123 "parse.yy"
    {
  (yyvsp[(1) - (2)].declaration_data)->funclist.push_back((yyvsp[(2) - (2)].function));
  (yyval.declaration_data) = (yyvsp[(1) - (2)].declaration_data);
;}
    break;

  case 6:
#line 130 "parse.yy"
    {
  (yyval.function) = new Function((yyvsp[(1) - (9)].type), (yyvsp[(2) - (9)].string), *(yyvsp[(4) - (9)].vars), *(yyvsp[(7) - (9)].vars), (yyvsp[(8) - (9)].statement));
  delete (yyvsp[(4) - (9)].vars);
  delete (yyvsp[(7) - (9)].vars);
;}
    break;

  case 7:
#line 138 "parse.yy"
    {
  (yyval.vars) = new std::list<Variable*>;
;}
    break;

  case 8:
#line 142 "parse.yy"
    {
 (yyval.vars) = new std::list<Variable*>;
 (yyval.vars)->push_back((yyvsp[(1) - (1)].variable));
;}
    break;

  case 9:
#line 147 "parse.yy"
    {
  (yyvsp[(1) - (3)].vars)->push_back((yyvsp[(3) - (3)].variable));
  (yyval.vars) = (yyvsp[(1) - (3)].vars);
;}
    break;

  case 10:
#line 155 "parse.yy"
    {
  (yyval.vars) = new std::list<Variable*>;
;}
    break;

  case 11:
#line 159 "parse.yy"
    {
  (yyvsp[(1) - (3)].vars)->push_back((yyvsp[(2) - (3)].variable));
  (yyval.vars) = (yyvsp[(1) - (3)].vars);
;}
    break;

  case 12:
#line 166 "parse.yy"
    {
  (yyval.variable) = new Variable((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].string));
;}
    break;

  case 13:
#line 172 "parse.yy"
    {
  (yyval.type) = Type_INT;
;}
    break;

  case 14:
#line 176 "parse.yy"
    {
  (yyval.type) = Type_CHAR;
;}
    break;

  case 15:
#line 181 "parse.yy"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);;}
    break;

  case 16:
#line 182 "parse.yy"
    {(yyval.statement) = (yyvsp[(2) - (3)].statement);;}
    break;

  case 17:
#line 183 "parse.yy"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);;}
    break;

  case 18:
#line 184 "parse.yy"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);;}
    break;

  case 19:
#line 185 "parse.yy"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);;}
    break;

  case 20:
#line 186 "parse.yy"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);;}
    break;

  case 21:
#line 190 "parse.yy"
    {
  (yyval.statement) = new St_assign((yyvsp[(1) - (4)].exp_variable), (yyvsp[(3) - (4)].expression));
;}
    break;

  case 22:
#line 196 "parse.yy"
    {
  (yyval.statement) = new St_list(*(yyvsp[(1) - (1)].stlist));
  delete (yyvsp[(1) - (1)].stlist);
;}
    break;

  case 23:
#line 203 "parse.yy"
    {
  (yyval.stlist) = new std::list<Statement*>;
;}
    break;

  case 24:
#line 207 "parse.yy"
    {
  (yyvsp[(1) - (2)].stlist)->push_back((yyvsp[(2) - (2)].statement));
  (yyval.stlist) = (yyvsp[(1) - (2)].stlist);
;}
    break;

  case 25:
#line 214 "parse.yy"
    {
  (yyval.statement) = new St_if((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement), NULL);
;}
    break;

  case 26:
#line 218 "parse.yy"
    {
  (yyval.statement) = new St_if((yyvsp[(3) - (7)].expression), (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement));
;}
    break;

  case 27:
#line 224 "parse.yy"
    {
  (yyval.statement) = new St_while((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement));
;}
    break;

  case 28:
#line 230 "parse.yy"
    {
  (yyval.statement) = new St_return((yyvsp[(2) - (3)].expression));
;}
    break;

  case 29:
#line 236 "parse.yy"
    {
  (yyval.statement) = new St_function((yyvsp[(1) - (5)].string), *(yyvsp[(3) - (5)].explist));
;}
    break;

  case 30:
#line 242 "parse.yy"
    {
  (yyval.expression) = new Exp_constant(Type_INT, (yyvsp[(1) - (1)].val));
;}
    break;

  case 31:
#line 246 "parse.yy"
    {
  (yyval.expression) = new Exp_constant(Type_CHAR, (yyvsp[(1) - (1)].val));
;}
    break;

  case 32:
#line 250 "parse.yy"
    {
  (yyval.expression) = (yyvsp[(1) - (1)].exp_variable);
;}
    break;

  case 33:
#line 254 "parse.yy"
    {
  (yyval.expression) = (yyvsp[(2) - (3)].expression);
;}
    break;

  case 34:
#line 258 "parse.yy"
    {
  (yyval.expression) = (yyvsp[(1) - (1)].expression);
;}
    break;

  case 35:
#line 264 "parse.yy"
    {
  (yyval.expression) = new Exp_function((yyvsp[(1) - (4)].string), *(yyvsp[(3) - (4)].explist));
  delete (yyvsp[(3) - (4)].explist);
;}
    break;

  case 36:
#line 271 "parse.yy"
    {
  (yyval.explist) = new std::list<Expression*>;
;}
    break;

  case 37:
#line 275 "parse.yy"
    {
  (yyval.explist) = new std::list<Expression*>;
  (yyval.explist)->push_back((yyvsp[(1) - (1)].expression));
;}
    break;

  case 38:
#line 280 "parse.yy"
    {
  (yyvsp[(1) - (3)].explist)->push_back((yyvsp[(3) - (3)].expression));
  (yyval.explist) = (yyvsp[(1) - (3)].explist);
;}
    break;

  case 39:
#line 287 "parse.yy"
    {
  (yyval.exp_variable) = new Exp_variable((yyvsp[(1) - (1)].string));
;}
    break;

  case 40:
#line 293 "parse.yy"
    {
  (yyval.expression) = (yyvsp[(1) - (1)].expression);
;}
    break;

  case 41:
#line 297 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_MUL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 42:
#line 301 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_DIV, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 43:
#line 305 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_MOD, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 44:
#line 311 "parse.yy"
    {
  (yyval.expression) = (yyvsp[(1) - (1)].expression);
;}
    break;

  case 45:
#line 315 "parse.yy"
    {
  (yyval.expression) = new Exp_operation1(Operator_PLUS, (yyvsp[(2) - (2)].expression));
;}
    break;

  case 46:
#line 319 "parse.yy"
    {
  (yyval.expression) = new Exp_operation1(Operator_MINUS, (yyvsp[(2) - (2)].expression));
;}
    break;

  case 47:
#line 323 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_PLUS, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 48:
#line 327 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_MINUS, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 49:
#line 333 "parse.yy"
    {
  (yyval.expression) = (yyvsp[(1) - (1)].expression);
;}
    break;

  case 50:
#line 337 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_LT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 51:
#line 341 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_GT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 52:
#line 345 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_LE, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 53:
#line 349 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_GE, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 54:
#line 353 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_EQ, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;

  case 55:
#line 357 "parse.yy"
    {
  (yyval.expression) = new Exp_operation2(Operator_NE, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
;}
    break;


/* Line 1267 of yacc.c.  */
#line 1880 "parse.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 361 "parse.yy"

// --------------------------------------------------------------------
// [Part-7] 関数本体の記述
// --------------------------------------------------------------------

int main(int argc, char *argv[])
{
  if(std::FILE* fp = std::fopen(argv[1], "r"))
  {
    linenum = 1;  // lex の行番号を 1 に初期設定
    yyin = fp;    // lex のファイルポインタをセット
    yyparse();    // 構文解析関数を呼び出す
    ast->run();
  }
  else {
    printf("ファイル '%s' が開けません\n", argv[1]);
  }
}

Program* build_program(Declaration_t* dd)
{
  std::list<Function*> flist;
  Function* mainf;

  // ddのfunclistリスト中の関数のうち、"main"という名前の
  // ものはmainfにセットし、それ以外はリストflistに入れる
  std::list<Function*>::iterator f;
  for (f = dd->funclist.begin(); f != dd->funclist.end(); f++) {
    if ((*f)->name() == "main") { mainf = *f; }
    else { flist.push_back(*f); }
  }

  return new Program(dd->vars, flist, mainf);
}

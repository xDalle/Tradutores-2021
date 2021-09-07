/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "src/syntax.y"

	#define RED "\x1b[31m"
	#define WHITE "\x1b[0m"
	#define GREEN "\x1b[32m"
	#define ERROR -1

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "../lib/structures.h"

	extern int yylex();
	extern int yyparse();
	extern int yylex_destroy();
	extern FILE *yyin;
	extern void yyerror(const char *error_msg);
	extern int num_lines;
	extern int num_chars;
	static int count_errors = 0;

#line 92 "src/syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_MUL = 4,                        /* MUL  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_LOGICAL_OR = 7,                 /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_AND = 8,                /* LOGICAL_AND  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_INPUT = 13,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 14,                    /* OUTPUT  */
  YYSYMBOL_SIMPLE_TYPE = 15,               /* SIMPLE_TYPE  */
  YYSYMBOL_COMPOUND_TYPE = 16,             /* COMPOUND_TYPE  */
  YYSYMBOL_ID = 17,                        /* ID  */
  YYSYMBOL_NIL_CONSTANT = 18,              /* NIL_CONSTANT  */
  YYSYMBOL_LIST_CONSTR = 19,               /* LIST_CONSTR  */
  YYSYMBOL_LIST_OP = 20,                   /* LIST_OP  */
  YYSYMBOL_LIST_DESTR = 21,                /* LIST_DESTR  */
  YYSYMBOL_LIST_FUNC = 22,                 /* LIST_FUNC  */
  YYSYMBOL_RELATIONAL = 23,                /* RELATIONAL  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_OP_OVERLOAD = 25,               /* OP_OVERLOAD  */
  YYSYMBOL_ERROR_STR = 26,                 /* ERROR_STR  */
  YYSYMBOL_ERROR_CHAR = 27,                /* ERROR_CHAR  */
  YYSYMBOL_ERROR_COMM = 28,                /* ERROR_COMM  */
  YYSYMBOL_29_ = 29,                       /* '{'  */
  YYSYMBOL_30_ = 30,                       /* '}'  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_THEN = 36,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_initial = 38,                   /* initial  */
  YYSYMBOL_declaration_list = 39,          /* declaration_list  */
  YYSYMBOL_decl = 40,                      /* decl  */
  YYSYMBOL_var_definition = 41,            /* var_definition  */
  YYSYMBOL_var_declaration = 42,           /* var_declaration  */
  YYSYMBOL_func_definition = 43,           /* func_definition  */
  YYSYMBOL_44_params_opt = 44,             /* params.opt  */
  YYSYMBOL_func_declaration = 45,          /* func_declaration  */
  YYSYMBOL_params = 46,                    /* params  */
  YYSYMBOL_param_list = 47,                /* param_list  */
  YYSYMBOL_param = 48,                     /* param  */
  YYSYMBOL_stmts = 49,                     /* stmts  */
  YYSYMBOL_50_stmt_list_opt = 50,          /* stmt_list.opt  */
  YYSYMBOL_stmt_list = 51,                 /* stmt_list  */
  YYSYMBOL_52_stmt_item = 52,              /* stmt.item  */
  YYSYMBOL_stmt = 53,                      /* stmt  */
  YYSYMBOL_select_stmt = 54,               /* select_stmt  */
  YYSYMBOL_iter_stmt = 55,                 /* iter_stmt  */
  YYSYMBOL_exp_stmt = 56,                  /* exp_stmt  */
  YYSYMBOL_exp = 57,                       /* exp  */
  YYSYMBOL_return_stmt = 58,               /* return_stmt  */
  YYSYMBOL_io_stmt = 59,                   /* io_stmt  */
  YYSYMBOL_in_stmt = 60,                   /* in_stmt  */
  YYSYMBOL_out_stmt = 61,                  /* out_stmt  */
  YYSYMBOL_assign_exp = 62,                /* assign_exp  */
  YYSYMBOL_simple_exp = 63,                /* simple_exp  */
  YYSYMBOL_and_exp = 64,                   /* and_exp  */
  YYSYMBOL_rel_exp = 65,                   /* rel_exp  */
  YYSYMBOL_list_exp = 66,                  /* list_exp  */
  YYSYMBOL_sum_exp = 67,                   /* sum_exp  */
  YYSYMBOL_mul_exp = 68,                   /* mul_exp  */
  YYSYMBOL_unary_exp = 69,                 /* unary_exp  */
  YYSYMBOL_factor = 70,                    /* factor  */
  YYSYMBOL_func_call = 71,                 /* func_call  */
  YYSYMBOL_func_params = 72,               /* func_params  */
  YYSYMBOL_constant = 73                   /* constant  */
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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  267

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
      31,    32,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
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
      25,    26,    27,    28,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   128,   134,   142,   147,   155,   165,   180,
     190,   205,   215,   220,   227,   237,   252,   260,   265,   274,
     282,   290,   295,   302,   308,   316,   321,   329,   334,   339,
     344,   349,   354,   362,   368,   378,   389,   397,   402,   410,
     418,   423,   431,   444,   454,   462,   470,   476,   484,   490,
     498,   504,   512,   518,   524,   532,   538,   546,   552,   560,
     565,   570,   575,   580,   595,   602,   607,   612,   620,   628,
     633,   639,   646,   653,   660
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
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "MUL",
  "INTEGER", "REAL", "LOGICAL_OR", "LOGICAL_AND", "IF", "ELSE", "FOR",
  "RETURN", "INPUT", "OUTPUT", "SIMPLE_TYPE", "COMPOUND_TYPE", "ID",
  "NIL_CONSTANT", "LIST_CONSTR", "LIST_OP", "LIST_DESTR", "LIST_FUNC",
  "RELATIONAL", "STRING", "OP_OVERLOAD", "ERROR_STR", "ERROR_CHAR",
  "ERROR_COMM", "'{'", "'}'", "'('", "')'", "'='", "','", "';'", "THEN",
  "$accept", "initial", "declaration_list", "decl", "var_definition",
  "var_declaration", "func_definition", "params.opt", "func_declaration",
  "params", "param_list", "param", "stmts", "stmt_list.opt", "stmt_list",
  "stmt.item", "stmt", "select_stmt", "iter_stmt", "exp_stmt", "exp",
  "return_stmt", "io_stmt", "in_stmt", "out_stmt", "assign_exp",
  "simple_exp", "and_exp", "rel_exp", "list_exp", "sum_exp", "mul_exp",
  "unary_exp", "factor", "func_call", "func_params", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   123,
     125,    40,    41,    61,    44,    59,   284
};
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,   192,    87,    59,    92,   100,   251,   -14,    56,    -3,
    -161,   273,   126,   165,   275,   254,   186,    62,    74,   225,
     259,   339,    97,   278,   106,   127,   279,  1875,   367,   332,
    2613,   117,   297,   123,   166,  2622,   197,   209,   360,    53,
     333,  2613,  2613,  2613,  2643,  1904,  1933,   131,  1962,  1991,
    2020,  2049,  2078,  2107,   184,  2136,  2165,  2194,  2223,   217,
      23,     2,    -4,    70,    94,   431,   509,   531,   597,   742,
      60,   771,  2643,  2622,   227,   262,   354,   308,   257,   912,
    2622,   779,   801,   823,    22,   369,  2252,  2281,  2613,  2613,
    2613,  2613,  2613,  2613,  2613,    96,   268,  2310,   282,   299,
     302,   318,    37,   361,   335,   853,    27,    73,   130,   870,
     191,   204,   876,  2571,  2613,   338,   345,   348,   905,  2652,
    1382,    31,  2339,  2368,  2397,   181,  2592,  2673,  2426,   313,
    2592,  2455,  1875,  2643,    17,  1180,  1154,  1186,  2643,  2643,
    2643,  2643,   111,   315,   450,  1358,  1188,  1218,  1220,  1226,
    1252,  1148,   366,   173,  2484,  2652,   557,   931,   246,   948,
    2652,  2652,  2652,  2643,   199,   240,   301,  1131,   954,   971,
     988,   994,  1011,  2643,  2513,  2652,   378,   379,  2622,   391,
     400,  1875,  1411,  1440,  1469,  1498,   385,  1527,  1556,  1585,
    1614,   410,  1258,   912,  1260,  1290,  1292,   210,  2643,  2643,
    2643,  2643,  2643,  2643,  2673,  1028,   912,  1034,  1051,  1068,
     223,  2652,  2652,  2652,  2652,  2652,  2652,   115,   310,  2643,
    2622,   407,   427,   412,   415,  1643,  2542,   374,  1298,   604,
     610,  1324,   673,   821,  1330,   420,   382,  1074,   389,   514,
    1091,   622,   720,  1108,   229,   429,  1672,   423,   430,   433,
    1701,  1332,  1114,  2571,  2613,   432,   434,   435,  1730,    35,
    1759,  1788,  1817,  2673,   436,  2571,  1846
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,  -161,   468,  -161,   201,  -161,  -161,  -161,  -161,
    -161,   447,   -24,  -126,  -161,   443,  -108,  -105,  -102,   -97,
     -28,   -87,   -86,   -72,   -62,   -74,   662,   644,   549,   384,
     496,   451,   -29,    83,   188,  -160,   286
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    16,    45,     6,    17,     7,    18,
      19,    20,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   103,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    71,   152,   -49,   -49,   120,   191,    74,   183,   -47,
      89,   184,    81,    82,    83,   147,   185,    12,   128,    90,
     -72,   -72,   131,     1,   -72,   -72,   187,   188,   -14,   173,
      88,   -49,    14,   227,   -46,    89,   -72,   -47,    88,   -72,
     -72,   189,    88,   147,   175,    96,   236,   147,   100,   -72,
     169,   190,   104,   152,   105,   224,   -64,   -64,   -38,    -2,
     -64,   -64,   -46,   -64,   -64,   112,   127,   -64,   -64,   -69,
     263,   -69,   -64,    13,     1,   -64,   -64,   -51,   -51,   -64,
     -48,   -48,   -64,   -64,    79,   186,    80,    10,   -64,   182,
     169,    79,    -4,   -51,    24,   -64,    90,    91,   147,   129,
      -5,   -54,   -54,   173,   192,   -51,   -12,    -4,   -48,   194,
     195,   196,   147,    92,    26,    -5,    93,   -54,   -47,   198,
     -72,   -72,   -46,   198,   -72,   -72,   205,   148,   113,   -54,
     152,   207,   208,   209,   147,    27,   -72,   -50,   -50,   -72,
     -72,    15,    15,   -47,   147,   258,   169,   -46,   183,   152,
     221,   184,   -72,   -50,    72,   148,   185,   266,   -13,   148,
     183,    85,   170,   184,   169,   -50,   187,   188,   185,   147,
     147,   147,   147,   147,   234,   147,   235,   169,   187,   188,
     173,   189,   169,   169,   169,   169,   169,   243,   175,   152,
     147,   190,   245,   189,   147,   249,   -15,    73,   -52,   -52,
      21,     5,   170,   190,     5,   -38,   -47,   211,     8,     9,
     148,   -53,   -53,   -70,   -52,   -70,   148,   173,   -19,    87,
     -19,   148,   148,   148,   148,   186,   -52,   -53,    75,   182,
     173,   -47,   149,   -47,   147,   264,   173,   186,   170,   -53,
      76,   182,   228,   170,   170,   170,   148,   -49,   -49,   -64,
     -64,    -6,   -37,   -64,   -64,   237,   148,   -16,   170,    25,
     149,   253,    97,   212,   149,   -64,    -6,   171,   -64,   -64,
      22,    23,   -49,    -3,   -49,    -9,   170,   206,   -64,    98,
     -64,   148,   148,   148,   148,   148,   148,   148,    -3,   170,
      -9,   -17,   154,   -17,   170,   170,   170,   170,   170,   170,
     -73,   -73,   148,   114,   -73,   -73,   148,   171,   -51,   -51,
      -7,    -8,    -7,    -8,   115,   149,   -73,   -46,   211,   -73,
     -73,   149,   -49,   -49,   -51,   101,   149,   149,   149,   149,
     150,   116,   -73,   -51,   117,   -51,   -74,   -74,   199,   -10,
     -74,   -74,   -46,   171,   -46,   130,   148,   -49,   171,   171,
     171,   149,   -74,   174,   -10,   -74,   -74,   133,   150,   134,
     135,   149,   150,   171,   -18,   172,   -18,   -11,   -74,   -20,
     -45,   151,   137,   122,   138,   139,    77,    78,    99,   140,
     123,   171,   -11,   124,   -20,   141,   149,   149,   149,   149,
     149,   149,   149,   118,   171,   119,   -48,   -48,   -37,   171,
     171,   171,   171,   171,   171,   172,   251,   149,   119,   219,
     220,   149,   212,   150,   252,   133,   119,   134,   135,   150,
     225,   -48,   222,   -48,   150,   150,   150,   150,   144,   151,
     137,   223,   138,   139,   -56,    94,   248,   140,   -56,   -56,
     226,   172,   246,   141,   247,   250,   172,   172,   172,   150,
     -56,   149,   -45,   -56,   -56,   255,   144,   -51,   -51,   150,
     144,   172,   256,   166,   254,   257,   -56,   260,   265,   261,
     262,    11,    29,   -51,   108,     0,   110,   111,     0,   172,
       0,     0,   -51,     0,   150,   150,   150,   150,   150,   150,
     150,    86,   172,     0,     0,   146,     0,   172,   172,   172,
     172,   172,   172,   166,     0,   150,     0,     0,     0,   150,
       0,   144,   -58,   -58,     0,     0,   -58,   -58,     0,     0,
       0,   -50,   -50,   146,     0,   144,     0,   146,   -58,     0,
     168,   -58,   -58,     0,   -59,   -59,     0,   -50,   -59,   -59,
     145,     0,   109,     0,   -58,     0,   -50,   144,   -50,   150,
     -59,     0,     0,   -59,   -59,     0,     0,   144,     0,   166,
     -72,   -72,     0,     0,   -72,   -72,   -59,     0,   145,     0,
     168,     0,   145,     0,     0,   167,   -72,   166,   146,   -72,
     -72,     0,   144,   230,     0,   232,   233,     0,   144,   -72,
     166,   -72,   146,   143,     0,   166,   239,     0,   241,   242,
     -66,   -66,     0,   144,   -66,   -66,     0,   144,     0,     0,
       0,   -48,   -48,     0,   146,   167,   -66,   -50,   -50,   -66,
     -66,   143,     0,   145,   146,   143,   168,   199,   165,   -52,
     -52,     0,   -66,   -50,     0,     0,   -48,   145,   107,     0,
       0,     0,   -50,     0,   168,   -52,     0,   144,     0,   146,
     146,   231,   146,   146,   -52,   146,   -52,   168,     0,   145,
       0,     0,   168,   168,   240,   168,   168,     0,   165,   145,
     146,   167,     0,     0,   146,     0,   143,     0,     0,     0,
     -52,   -52,     0,     0,     0,     0,     0,     0,   142,   167,
     143,     0,     0,     0,   145,   145,   -52,   145,   145,     0,
     145,     0,   167,     0,     0,   -52,    84,   167,   167,     0,
     167,   167,   143,     0,   146,   145,   142,     0,     0,   145,
     142,     0,   143,   164,   165,     0,     0,   -53,   -53,     0,
       0,     0,   106,     0,    95,     0,     0,     0,   153,     0,
       0,   102,   165,   -53,     0,   -67,   -67,   229,     0,   -67,
     -67,     0,   -53,   143,   -53,   165,     0,     0,     0,   145,
     238,   -67,     0,   164,   -67,   -67,     0,     0,   143,     0,
       0,   142,   143,     0,   -63,   -63,   121,   -67,   -63,   -63,
       0,   125,   -60,   -60,     0,   142,   -60,   -60,     0,   153,
     -63,     0,     0,   -63,   -63,     0,     0,     0,   -60,     0,
       0,   -60,   -60,   197,   -61,   -61,   -63,   142,   -61,   -61,
       0,     0,   143,     0,   -60,     0,     0,   217,     0,   218,
     -61,     0,     0,   -61,   -61,   210,   -62,   -62,   -53,   -53,
     -62,   -62,     0,     0,     0,     0,   -61,   164,     0,     0,
       0,     0,   -62,     0,   -53,   -62,   -62,     0,   142,     0,
     164,     0,     0,   -53,     0,   102,   -65,   -65,   -62,     0,
     -65,   -65,     0,   142,     0,     0,   153,   142,   102,     0,
       0,     0,   -65,   -55,    94,   -65,   -65,   -55,   -55,   -57,
     -57,   244,     0,   -57,   -57,   153,     0,     0,   -65,   -55,
       0,     0,   -55,   -55,     0,   -57,     0,     0,   -57,   -57,
       0,     0,     0,     0,     0,   -55,     0,   142,   -68,   -68,
       0,   -57,   -68,   -68,     0,   155,   259,   156,   157,     0,
       0,     0,     0,     0,   -68,   153,     0,   -68,   -68,   158,
     159,     0,   160,   161,   -73,   -73,     0,   162,   -73,   -73,
     -68,     0,     0,   163,   -71,     0,   -71,     0,     0,     0,
     -73,   -74,   -74,   -73,   -73,   -74,   -74,   -56,   216,     0,
       0,   -56,   -56,   -73,     0,   -73,     0,   -74,     0,     0,
     -74,   -74,     0,   -56,   -58,   -58,   -56,   -56,   -58,   -58,
     -74,     0,   -74,     0,     0,     0,   -56,     0,   -56,     0,
     -58,   -59,   -59,   -58,   -58,   -59,   -59,   -66,   -66,     0,
       0,   -66,   -66,   -58,     0,   -58,     0,   -59,     0,     0,
     -59,   -59,     0,   -66,   -67,   -67,   -66,   -66,   -67,   -67,
     -59,     0,   -59,     0,     0,     0,   -66,     0,   -66,     0,
     -67,   -63,   -63,   -67,   -67,   -63,   -63,   -60,   -60,     0,
       0,   -60,   -60,   -67,     0,   -67,     0,   -63,     0,     0,
     -63,   -63,     0,   -60,   -61,   -61,   -60,   -60,   -61,   -61,
     -63,     0,   -63,     0,     0,     0,   -60,     0,   -60,     0,
     -61,   -62,   -62,   -61,   -61,   -62,   -62,   -65,   -65,     0,
       0,   -65,   -65,   -61,     0,   -61,     0,   -62,     0,     0,
     -62,   -62,     0,   -65,   -55,   216,   -65,   -65,   -55,   -55,
     -62,     0,   -62,     0,     0,     0,   -65,     0,   -65,     0,
     -55,   -57,   -57,   -55,   -55,   -57,   -57,   -68,   -68,     0,
       0,   -68,   -68,   -55,     0,   -55,     0,   -57,     0,     0,
     -57,   -57,     0,   -68,   213,     0,   -68,   -68,   -54,   -54,
     -57,     0,   -57,     0,     0,     0,   -68,     0,   -68,     0,
     214,   -64,   -64,   215,   -54,   -64,   -64,   -64,   -64,     0,
       0,   -64,   -64,   -54,     0,   -54,     0,   -64,     0,     0,
     -64,   -64,     0,   -64,     0,     0,   -64,   -64,     0,   193,
     -64,   204,     0,   -73,   -73,   193,   -64,   -73,   -73,   -74,
     -74,   -56,   203,   -74,   -74,   -56,   -56,     0,     0,   -73,
       0,     0,   -73,   -73,     0,   -74,     0,   -56,   -74,   -74,
     -56,   -56,   -73,     0,     0,     0,     0,     0,   -74,     0,
     -56,   -58,   -58,   -59,   -59,   -58,   -58,   -59,   -59,   -66,
     -66,     0,     0,   -66,   -66,     0,     0,   -58,     0,   -59,
     -58,   -58,   -59,   -59,     0,   -66,     0,     0,   -66,   -66,
     -58,     0,   -59,     0,     0,   -67,   -67,     0,   -66,   -67,
     -67,   -63,   -63,   -60,   -60,   -63,   -63,   -60,   -60,     0,
       0,   -67,     0,     0,   -67,   -67,     0,   -63,     0,   -60,
     -63,   -63,   -60,   -60,   -67,     0,     0,     0,     0,     0,
     -63,     0,   -60,   -61,   -61,   -62,   -62,   -61,   -61,   -62,
     -62,   -65,   -65,     0,     0,   -65,   -65,     0,     0,   -61,
       0,   -62,   -61,   -61,   -62,   -62,     0,   -65,     0,     0,
     -65,   -65,   -61,     0,   -62,     0,     0,   -55,   203,     0,
     -65,   -55,   -55,   -57,   -57,   -68,   -68,   -57,   -57,   -68,
     -68,     0,     0,   -55,     0,     0,   -55,   -55,     0,   -57,
       0,   -68,   -57,   -57,   -68,   -68,   -55,     0,     0,     0,
       0,   200,   -57,     0,   -68,   -54,   -54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,     0,     0,
     202,   -54,     0,     0,     0,   -33,     0,   -33,   -33,     0,
     -54,   -33,   126,   -33,   -33,   -33,   -33,   -33,     0,   -33,
     -33,     0,   -33,   -33,     0,     0,     0,   -33,     0,     0,
       0,   -33,   -33,   -33,   -32,     0,   -32,   -32,     0,     0,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,
       0,   -32,   -32,     0,     0,     0,   -32,     0,     0,     0,
     -32,   -32,   -32,   -28,     0,   -28,   -28,     0,     0,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,     0,
     -28,   -28,     0,     0,     0,   -28,     0,     0,     0,   -28,
     -28,   -28,   -29,     0,   -29,   -29,     0,     0,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,     0,   -29,
     -29,     0,     0,     0,   -29,     0,     0,     0,   -29,   -29,
     -29,   -31,     0,   -31,   -31,     0,     0,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,     0,   -31,   -31,     0,   -31,   -31,
       0,     0,     0,   -31,     0,     0,     0,   -31,   -31,   -31,
     -27,     0,   -27,   -27,     0,     0,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,     0,   -27,   -27,     0,   -27,   -27,     0,
       0,     0,   -27,     0,     0,     0,   -27,   -27,   -27,   -30,
       0,   -30,   -30,     0,     0,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,     0,   -30,   -30,     0,   -30,   -30,     0,     0,
       0,   -30,     0,     0,     0,   -30,   -30,   -30,   -40,     0,
     -40,   -40,     0,     0,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,     0,   -40,   -40,     0,   -40,   -40,     0,     0,     0,
     -40,     0,     0,     0,   -40,   -40,   -40,   -41,     0,   -41,
     -41,     0,     0,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
       0,   -41,   -41,     0,   -41,   -41,     0,     0,     0,   -41,
       0,     0,     0,   -41,   -41,   -41,   -36,     0,   -36,   -36,
       0,     0,   -36,   -36,   -36,   -36,   -36,   -36,   -36,     0,
     -36,   -36,     0,   -36,   -36,     0,     0,     0,   -36,     0,
       0,     0,   -36,   -36,   -36,   -39,     0,   -39,   -39,     0,
       0,   -39,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,
     -39,     0,   -39,   -39,     0,     0,     0,   -39,     0,     0,
       0,   -39,   -39,   -39,   -20,     0,   -20,   -20,     0,     0,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,     0,   -20,   -20,
       0,   -20,   -20,     0,     0,     0,   -20,     0,     0,     0,
     -20,   -20,   -20,   -33,     0,   -33,   -33,     0,     0,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,     0,
     -33,   -33,     0,     0,     0,   -33,     0,     0,     0,   -33,
     -33,   -33,   -42,     0,   -42,   -42,     0,     0,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,     0,   -42,
     -42,     0,     0,     0,   -42,     0,     0,     0,   -42,   -42,
     -42,   -43,     0,   -43,   -43,     0,     0,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,
       0,     0,     0,   -43,     0,     0,     0,   -43,   -43,   -43,
     -44,     0,   -44,   -44,     0,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,     0,
       0,     0,   -44,     0,     0,     0,   -44,   -44,   -44,   -35,
       0,   -35,   -35,     0,     0,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,     0,   -35,   -35,     0,   -35,   -35,     0,     0,
       0,   -35,     0,     0,     0,   -35,   -35,   -35,    30,     0,
      31,    32,     0,     0,    33,     0,    34,    35,    36,    37,
      38,     0,    39,    40,     0,    41,    42,     0,     0,     0,
      43,     0,     0,     0,   132,   -22,    44,   -26,     0,   -26,
     -26,     0,     0,   -26,     0,   -26,   -26,   -26,   -26,   -26,
       0,   -26,   -26,     0,   -26,   -26,     0,     0,     0,   -26,
       0,     0,     0,   -26,   -26,   -26,   -32,     0,   -32,   -32,
       0,     0,   -32,     0,   -32,   -32,   -32,   -32,   -32,     0,
     -32,   -32,     0,   -32,   -32,     0,     0,     0,   -32,     0,
       0,     0,   -32,   -32,   -32,    30,     0,    31,    32,     0,
       0,    33,     0,    34,    35,    36,    37,    38,     0,    39,
      40,     0,    41,    42,     0,     0,     0,    43,     0,     0,
       0,   132,   -21,    44,   -24,     0,   -24,   -24,     0,     0,
     -24,     0,   -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,
       0,   -24,   -24,     0,     0,     0,   -24,     0,     0,     0,
     -24,   -24,   -24,   -25,     0,   -25,   -25,     0,     0,   -25,
       0,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,     0,
     -25,   -25,     0,     0,     0,   -25,     0,     0,     0,   -25,
     -25,   -25,   -28,     0,   -28,   -28,     0,     0,   -28,     0,
     -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,     0,   -28,
     -28,     0,     0,     0,   -28,     0,     0,     0,   -28,   -28,
     -28,   -29,     0,   -29,   -29,     0,     0,   -29,     0,   -29,
     -29,   -29,   -29,   -29,     0,   -29,   -29,     0,   -29,   -29,
       0,     0,     0,   -29,     0,     0,     0,   -29,   -29,   -29,
     -31,     0,   -31,   -31,     0,     0,   -31,     0,   -31,   -31,
     -31,   -31,   -31,     0,   -31,   -31,     0,   -31,   -31,     0,
       0,     0,   -31,     0,     0,     0,   -31,   -31,   -31,   -27,
       0,   -27,   -27,     0,     0,   -27,     0,   -27,   -27,   -27,
     -27,   -27,     0,   -27,   -27,     0,   -27,   -27,     0,     0,
       0,   -27,     0,     0,     0,   -27,   -27,   -27,   -30,     0,
     -30,   -30,     0,     0,   -30,     0,   -30,   -30,   -30,   -30,
     -30,     0,   -30,   -30,     0,   -30,   -30,     0,     0,     0,
     -30,     0,     0,     0,   -30,   -30,   -30,   -40,     0,   -40,
     -40,     0,     0,   -40,     0,   -40,   -40,   -40,   -40,   -40,
       0,   -40,   -40,     0,   -40,   -40,     0,     0,     0,   -40,
       0,     0,     0,   -40,   -40,   -40,   -41,     0,   -41,   -41,
       0,     0,   -41,     0,   -41,   -41,   -41,   -41,   -41,     0,
     -41,   -41,     0,   -41,   -41,     0,     0,     0,   -41,     0,
       0,     0,   -41,   -41,   -41,   -23,     0,   -23,   -23,     0,
       0,   -23,     0,   -23,   -23,   -23,   -23,   -23,     0,   -23,
     -23,     0,   -23,   -23,     0,     0,     0,   -23,     0,     0,
       0,   -23,   -23,   -23,   -36,     0,   -36,   -36,     0,     0,
     -36,     0,   -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,
       0,   -36,   -36,     0,     0,     0,   -36,     0,     0,     0,
     -36,   -36,   -36,   -39,     0,   -39,   -39,     0,     0,   -39,
       0,   -39,   -39,   -39,   -39,   -39,     0,   -39,   -39,     0,
     -39,   -39,     0,     0,     0,   -39,     0,     0,     0,   -39,
     -39,   -39,   -42,     0,   -42,   -42,     0,     0,   -42,     0,
     -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,     0,   -42,
     -42,     0,     0,     0,   -42,     0,     0,     0,   -42,   -42,
     -42,   -43,     0,   -43,   -43,     0,     0,   -43,     0,   -43,
     -43,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,
       0,     0,     0,   -43,     0,     0,     0,   -43,   -43,   -43,
     -44,     0,   -44,   -44,     0,     0,   -44,     0,   -44,   -44,
     -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,     0,
       0,     0,   -44,     0,     0,     0,   -44,   -44,   -44,   -34,
       0,   -34,   -34,     0,     0,   -34,     0,   -34,   -34,   -34,
     -34,   -34,     0,   -34,   -34,     0,   -34,   -34,     0,     0,
       0,   -34,     0,     0,     0,   -34,   -34,   -34,   -35,     0,
     -35,   -35,     0,     0,   -35,     0,   -35,   -35,   -35,   -35,
     -35,     0,   -35,   -35,     0,   -35,   -35,     0,     0,     0,
     -35,     0,     0,     0,   -35,   -35,   -35,    -9,     0,    -9,
      -9,     0,     0,    -9,     0,    -9,    -9,    -9,    -9,    -9,
       0,    -9,    -9,     0,    -9,    -9,     0,     0,     0,    -9,
       0,     0,     0,    -9,    -9,    -9,   -10,     0,   -10,   -10,
       0,     0,   -10,     0,   -10,   -10,   -10,   -10,   -10,     0,
     -10,   -10,     0,   -10,   -10,     0,     0,     0,   -10,     0,
       0,     0,   -10,   -10,   -10,   -20,     0,   -20,   -20,     0,
       0,   -20,     0,   -20,   -20,   -20,   -20,   -20,     0,   -20,
     -20,     0,   -20,   -20,     0,     0,     0,   -20,     0,     0,
       0,   -20,   -20,   -20,    30,     0,    31,    32,     0,     0,
     176,     0,   177,   178,   179,   180,     0,     0,    39,    40,
       0,    41,    42,     0,     0,    30,    43,    31,    32,     0,
     181,    33,    44,    34,    35,    36,    37,     0,     0,    39,
      40,     0,    41,    42,     0,     0,    30,    43,    31,    32,
       0,   132,     0,    44,     0,    30,     0,    31,    32,     0,
      70,    40,     0,    41,    42,     0,     0,     0,    43,    39,
      40,     0,    41,    42,    44,     0,   133,    43,   134,   135,
       0,     0,     0,    44,     0,   155,     0,   156,   157,     0,
     136,   137,     0,   138,   139,     0,     0,     0,   140,   158,
     159,     0,   160,   161,   141,     0,   133,   162,   134,   135,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
     151,   137,     0,   138,   139,     0,     0,     0,   140,     0,
       0,     0,     0,     0,   141
};

static const yytype_int16 yycheck[] =
{
      24,    30,    76,     7,     8,   113,   132,    35,   113,     7,
       8,   113,    41,    42,    43,    44,   113,    31,   126,    23,
       3,     4,   130,    15,     7,     8,   113,   113,    31,     7,
       7,    35,    35,   193,     7,     8,    19,    35,     7,    22,
      23,   113,     7,    72,     7,    73,   206,    76,    76,    32,
      79,   113,    80,   127,    32,   181,     3,     4,    35,     0,
       7,     8,    35,     3,     4,    94,    35,     7,     8,    32,
      35,    34,    19,    17,    15,    22,    23,     7,     8,    19,
       7,     8,    22,    23,    31,   113,    33,     0,    35,   113,
     119,    31,     0,    23,    32,    35,    23,     3,   127,   127,
       0,     7,     8,     7,   133,    35,    32,    15,    35,   138,
     139,   140,   141,    19,    17,    15,    22,    23,     7,     8,
       3,     4,     7,     8,     7,     8,   155,    44,    32,    35,
     204,   160,   161,   162,   163,    29,    19,     7,     8,    22,
      23,    15,    15,    32,   173,   253,   175,    32,   253,   223,
     178,   253,    35,    23,    31,    72,   253,   265,    32,    76,
     265,    30,    79,   265,   193,    35,   253,   253,   265,   198,
     199,   200,   201,   202,   203,   204,   204,   206,   265,   265,
       7,   253,   211,   212,   213,   214,   215,   216,     7,   263,
     219,   253,   220,   265,   223,   223,    31,    31,     7,     8,
      35,     0,   119,   265,     3,    32,     7,     8,    16,    17,
     127,     7,     8,    32,    23,    34,   133,     7,    32,    35,
      34,   138,   139,   140,   141,   253,    35,    23,    31,   253,
       7,    32,    44,    34,   263,   263,     7,   265,   155,    35,
      31,   265,    32,   160,   161,   162,   163,     7,     8,     3,
       4,     0,    35,     7,     8,    32,   173,    32,   175,    34,
      72,    32,    35,    23,    76,    19,    15,    79,    22,    23,
      16,    17,    32,     0,    34,     0,   193,    31,    32,    17,
      34,   198,   199,   200,   201,   202,   203,   204,    15,   206,
      15,    32,    35,    34,   211,   212,   213,   214,   215,   216,
       3,     4,   219,    35,     7,     8,   223,   119,     7,     8,
      32,    32,    34,    34,    32,   127,    19,     7,     8,    22,
      23,   133,     7,     8,    23,    17,   138,   139,   140,   141,
      44,    32,    35,    32,    32,    34,     3,     4,    23,     0,
       7,     8,    32,   155,    34,    32,   263,    32,   160,   161,
     162,   163,    19,    35,    15,    22,    23,     3,    72,     5,
       6,   173,    76,   175,    32,    79,    34,     0,    35,     0,
      35,    17,    18,    35,    20,    21,    16,    17,    24,    25,
      35,   193,    15,    35,    15,    31,   198,   199,   200,   201,
     202,   203,   204,    32,   206,    34,     7,     8,    32,   211,
     212,   213,   214,   215,   216,   119,    32,   219,    34,    31,
      31,   223,    23,   127,    32,     3,    34,     5,     6,   133,
      35,    32,    31,    34,   138,   139,   140,   141,    44,    17,
      18,    31,    20,    21,     3,     4,    24,    25,     7,     8,
      30,   155,    35,    31,    17,    30,   160,   161,   162,   163,
      19,   263,    32,    22,    23,    32,    72,     7,     8,   173,
      76,   175,    32,    79,    35,    32,    35,    35,    32,    35,
      35,     3,    25,    23,    90,    -1,    92,    93,    -1,   193,
      -1,    -1,    32,    -1,   198,   199,   200,   201,   202,   203,
     204,    48,   206,    -1,    -1,    44,    -1,   211,   212,   213,
     214,   215,   216,   119,    -1,   219,    -1,    -1,    -1,   223,
      -1,   127,     3,     4,    -1,    -1,     7,     8,    -1,    -1,
      -1,     7,     8,    72,    -1,   141,    -1,    76,    19,    -1,
      79,    22,    23,    -1,     3,     4,    -1,    23,     7,     8,
      44,    -1,    91,    -1,    35,    -1,    32,   163,    34,   263,
      19,    -1,    -1,    22,    23,    -1,    -1,   173,    -1,   175,
       3,     4,    -1,    -1,     7,     8,    35,    -1,    72,    -1,
     119,    -1,    76,    -1,    -1,    79,    19,   193,   127,    22,
      23,    -1,   198,   199,    -1,   201,   202,    -1,   204,    32,
     206,    34,   141,    44,    -1,   211,   212,    -1,   214,   215,
       3,     4,    -1,   219,     7,     8,    -1,   223,    -1,    -1,
      -1,     7,     8,    -1,   163,   119,    19,     7,     8,    22,
      23,    72,    -1,   127,   173,    76,   175,    23,    79,     7,
       8,    -1,    35,    23,    -1,    -1,    32,   141,    89,    -1,
      -1,    -1,    32,    -1,   193,    23,    -1,   263,    -1,   198,
     199,   200,   201,   202,    32,   204,    34,   206,    -1,   163,
      -1,    -1,   211,   212,   213,   214,   215,    -1,   119,   173,
     219,   175,    -1,    -1,   223,    -1,   127,    -1,    -1,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    44,   193,
     141,    -1,    -1,    -1,   198,   199,    23,   201,   202,    -1,
     204,    -1,   206,    -1,    -1,    32,    44,   211,   212,    -1,
     214,   215,   163,    -1,   263,   219,    72,    -1,    -1,   223,
      76,    -1,   173,    79,   175,    -1,    -1,     7,     8,    -1,
      -1,    -1,    88,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,   193,    23,    -1,     3,     4,   198,    -1,     7,
       8,    -1,    32,   204,    34,   206,    -1,    -1,    -1,   263,
     211,    19,    -1,   119,    22,    23,    -1,    -1,   219,    -1,
      -1,   127,   223,    -1,     3,     4,   114,    35,     7,     8,
      -1,   119,     3,     4,    -1,   141,     7,     8,    -1,   127,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    19,    -1,
      -1,    22,    23,   141,     3,     4,    35,   163,     7,     8,
      -1,    -1,   263,    -1,    35,    -1,    -1,   173,    -1,   175,
      19,    -1,    -1,    22,    23,   163,     3,     4,     7,     8,
       7,     8,    -1,    -1,    -1,    -1,    35,   193,    -1,    -1,
      -1,    -1,    19,    -1,    23,    22,    23,    -1,   204,    -1,
     206,    -1,    -1,    32,    -1,   193,     3,     4,    35,    -1,
       7,     8,    -1,   219,    -1,    -1,   204,   223,   206,    -1,
      -1,    -1,    19,     3,     4,    22,    23,     7,     8,     3,
       4,   219,    -1,     7,     8,   223,    -1,    -1,    35,    19,
      -1,    -1,    22,    23,    -1,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    35,    -1,   263,     3,     4,
      -1,    35,     7,     8,    -1,     3,   254,     5,     6,    -1,
      -1,    -1,    -1,    -1,    19,   263,    -1,    22,    23,    17,
      18,    -1,    20,    21,     3,     4,    -1,    25,     7,     8,
      35,    -1,    -1,    31,    32,    -1,    34,    -1,    -1,    -1,
      19,     3,     4,    22,    23,     7,     8,     3,     4,    -1,
      -1,     7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,
      22,    23,    -1,    19,     3,     4,    22,    23,     7,     8,
      32,    -1,    34,    -1,    -1,    -1,    32,    -1,    34,    -1,
      19,     3,     4,    22,    23,     7,     8,     3,     4,    -1,
      -1,     7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,
      22,    23,    -1,    19,     3,     4,    22,    23,     7,     8,
      32,    -1,    34,    -1,    -1,    -1,    32,    -1,    34,    -1,
      19,     3,     4,    22,    23,     7,     8,     3,     4,    -1,
      -1,     7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,
      22,    23,    -1,    19,     3,     4,    22,    23,     7,     8,
      32,    -1,    34,    -1,    -1,    -1,    32,    -1,    34,    -1,
      19,     3,     4,    22,    23,     7,     8,     3,     4,    -1,
      -1,     7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,
      22,    23,    -1,    19,     3,     4,    22,    23,     7,     8,
      32,    -1,    34,    -1,    -1,    -1,    32,    -1,    34,    -1,
      19,     3,     4,    22,    23,     7,     8,     3,     4,    -1,
      -1,     7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,
      22,    23,    -1,    19,     3,    -1,    22,    23,     7,     8,
      32,    -1,    34,    -1,    -1,    -1,    32,    -1,    34,    -1,
      19,     3,     4,    22,    23,     7,     8,     3,     4,    -1,
      -1,     7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,
      22,    23,    -1,    19,    -1,    -1,    22,    23,    -1,    31,
      32,    33,    -1,     3,     4,    31,    32,     7,     8,     3,
       4,     3,     4,     7,     8,     7,     8,    -1,    -1,    19,
      -1,    -1,    22,    23,    -1,    19,    -1,    19,    22,    23,
      22,    23,    32,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      32,     3,     4,     3,     4,     7,     8,     7,     8,     3,
       4,    -1,    -1,     7,     8,    -1,    -1,    19,    -1,    19,
      22,    23,    22,    23,    -1,    19,    -1,    -1,    22,    23,
      32,    -1,    32,    -1,    -1,     3,     4,    -1,    32,     7,
       8,     3,     4,     3,     4,     7,     8,     7,     8,    -1,
      -1,    19,    -1,    -1,    22,    23,    -1,    19,    -1,    19,
      22,    23,    22,    23,    32,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    32,     3,     4,     3,     4,     7,     8,     7,
       8,     3,     4,    -1,    -1,     7,     8,    -1,    -1,    19,
      -1,    19,    22,    23,    22,    23,    -1,    19,    -1,    -1,
      22,    23,    32,    -1,    32,    -1,    -1,     3,     4,    -1,
      32,     7,     8,     3,     4,     3,     4,     7,     8,     7,
       8,    -1,    -1,    19,    -1,    -1,    22,    23,    -1,    19,
      -1,    19,    22,    23,    22,    23,    32,    -1,    -1,    -1,
      -1,     3,    32,    -1,    32,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,     3,    -1,     5,     6,    -1,
      32,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     3,    -1,     5,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     3,    -1,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     3,    -1,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     3,    -1,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       3,    -1,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     3,
      -1,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     3,    -1,
       5,     6,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     3,    -1,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     3,    -1,     5,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     3,    -1,     5,     6,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     3,    -1,     5,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     3,    -1,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     3,    -1,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     3,    -1,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       3,    -1,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     3,
      -1,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     3,    -1,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     3,    -1,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     3,    -1,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     3,    -1,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     3,    -1,     5,     6,    -1,    -1,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     3,    -1,     5,     6,    -1,    -1,     9,
      -1,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     3,    -1,     5,     6,    -1,    -1,     9,    -1,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     3,    -1,     5,     6,    -1,    -1,     9,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       3,    -1,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     3,
      -1,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     3,    -1,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     3,    -1,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     3,    -1,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     3,    -1,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     3,    -1,     5,     6,    -1,    -1,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     3,    -1,     5,     6,    -1,    -1,     9,
      -1,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     3,    -1,     5,     6,    -1,    -1,     9,    -1,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     3,    -1,     5,     6,    -1,    -1,     9,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       3,    -1,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     3,
      -1,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     3,    -1,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     3,    -1,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     3,    -1,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     3,    -1,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     3,    -1,     5,     6,    -1,    -1,
       9,    -1,    11,    12,    13,    14,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,     3,    25,     5,     6,    -1,
      29,     9,    31,    11,    12,    13,    14,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,     3,    25,     5,     6,
      -1,    29,    -1,    31,    -1,     3,    -1,     5,     6,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    17,
      18,    -1,    20,    21,    31,    -1,     3,    25,     5,     6,
      -1,    -1,    -1,    31,    -1,     3,    -1,     5,     6,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    17,
      18,    -1,    20,    21,    31,    -1,     3,    25,     5,     6,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    38,    39,    40,    42,    43,    45,    16,    17,
       0,    40,    31,    17,    35,    15,    41,    44,    46,    47,
      48,    35,    16,    17,    32,    34,    17,    29,    49,    48,
       3,     5,     6,     9,    11,    12,    13,    14,    15,    17,
      18,    20,    21,    25,    31,    42,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    73,
      17,    69,    31,    31,    57,    31,    31,    16,    17,    31,
      33,    69,    69,    69,    63,    30,    52,    35,     7,     8,
      23,     3,    19,    22,     4,    63,    57,    35,    17,    24,
      57,    17,    63,    72,    57,    32,    64,    65,    66,    68,
      66,    66,    69,    32,    35,    32,    32,    32,    32,    34,
      53,    63,    35,    35,    35,    63,    10,    35,    53,    57,
      32,    53,    29,     3,     5,     6,    17,    18,    20,    21,
      25,    31,    64,    65,    66,    67,    68,    69,    70,    71,
      73,    17,    62,    63,    35,     3,     5,     6,    17,    18,
      20,    21,    25,    31,    64,    65,    66,    67,    68,    69,
      70,    71,    73,     7,    35,     7,     9,    11,    12,    13,
      14,    29,    49,    54,    55,    56,    57,    58,    59,    60,
      61,    50,    69,    31,    69,    69,    69,    63,     8,    23,
       3,    19,    22,     4,    33,    69,    31,    69,    69,    69,
      63,     8,    23,     3,    19,    22,     4,    64,    64,    31,
      31,    57,    31,    31,    50,    35,    30,    72,    32,    65,
      66,    68,    66,    66,    69,    57,    72,    32,    65,    66,
      68,    66,    66,    69,    63,    57,    35,    17,    24,    57,
      30,    32,    32,    32,    35,    32,    32,    32,    53,    63,
      35,    35,    35,    35,    57,    32,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    44,    44,    45,    45,    46,    47,    47,    48,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    56,    57,    57,    58,
      59,    59,    60,    61,    61,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    71,    72,
      72,    72,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     3,     3,
       4,     5,     1,     0,     2,     3,     1,     1,     3,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     7,     9,     2,     1,     1,     3,
       1,     1,     5,     5,     5,     3,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     1,
       2,     2,     2,     2,     1,     3,     1,     1,     4,     1,
       3,     0,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* initial: declaration_list  */
#line 119 "src/syntax.y"
                        {
		root = *createAstNode("initial");
		(yyval.ast) = &root;
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2070 "src/syntax.tab.c"
    break;

  case 3: /* declaration_list: declaration_list decl  */
#line 128 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("declaration list");
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2081 "src/syntax.tab.c"
    break;

  case 4: /* declaration_list: decl  */
#line 134 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("declaration list");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2091 "src/syntax.tab.c"
    break;

  case 5: /* decl: var_declaration  */
#line 142 "src/syntax.y"
                       {
		(yyval.ast) = createAstNode("decl");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2101 "src/syntax.tab.c"
    break;

  case 6: /* decl: func_definition  */
#line 147 "src/syntax.y"
                         {
		(yyval.ast) = createAstNode("decl");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2111 "src/syntax.tab.c"
    break;

  case 7: /* var_definition: SIMPLE_TYPE ID  */
#line 155 "src/syntax.y"
                      {
		char concat_type[200];
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, (yyvsp[-1].lexeme).lexeme_string, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, (yyvsp[-1].lexeme).scope);
		(yyval.ast) = createAstNode("var definition");
		strcpy(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2126 "src/syntax.tab.c"
    break;

  case 8: /* var_definition: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 165 "src/syntax.y"
                                      {
		char concat_type[200];
		strcpy(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, concat_type, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, (yyvsp[-2].lexeme).scope);
		(yyval.ast) = createAstNode("var definition");
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2143 "src/syntax.tab.c"
    break;

  case 9: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 180 "src/syntax.y"
                          {
		char concat_type[200];
		insertSymbol(&symbolTable, (yyvsp[-1].lexeme).lexeme_string, (yyvsp[-2].lexeme).lexeme_string, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, (yyvsp[-2].lexeme).scope);
		(yyval.ast) = createAstNode("var declaration");
		strcpy(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2158 "src/syntax.tab.c"
    break;

  case 10: /* var_declaration: SIMPLE_TYPE COMPOUND_TYPE ID ';'  */
#line 190 "src/syntax.y"
                                          {
		char concat_type[200];
		strcpy(concat_type, (yyvsp[-3].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		insertSymbol(&symbolTable, (yyvsp[-1].lexeme).lexeme_string, concat_type, (yyvsp[-3].lexeme).line, (yyvsp[-3].lexeme).column, (yyvsp[-3].lexeme).scope);
		(yyval.ast) = createAstNode("var declaration");
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2175 "src/syntax.tab.c"
    break;

  case 11: /* func_definition: func_declaration '(' params.opt ')' stmts  */
#line 205 "src/syntax.y"
                                                  {
		(yyval.ast) = createAstNode("function definition");
		(yyval.ast)->children[0] = (yyvsp[-4].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2187 "src/syntax.tab.c"
    break;

  case 12: /* params.opt: params  */
#line 215 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("params optional");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2197 "src/syntax.tab.c"
    break;

  case 13: /* params.opt: %empty  */
#line 220 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("params optional empty"); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2206 "src/syntax.tab.c"
    break;

  case 14: /* func_declaration: SIMPLE_TYPE ID  */
#line 227 "src/syntax.y"
                      {
		char concat_type[200];
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, (yyvsp[-1].lexeme).lexeme_string, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, (yyvsp[-1].lexeme).scope);
		(yyval.ast) = createAstNode("function declaration");
		strcpy(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2221 "src/syntax.tab.c"
    break;

  case 15: /* func_declaration: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 237 "src/syntax.y"
                                      {
		char concat_type[200];
		strcpy(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, concat_type, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, (yyvsp[-2].lexeme).scope);
		(yyval.ast) = createAstNode("function declaration");
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2238 "src/syntax.tab.c"
    break;

  case 16: /* params: param_list  */
#line 252 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("params");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2248 "src/syntax.tab.c"
    break;

  case 17: /* param_list: param  */
#line 260 "src/syntax.y"
             {
		(yyval.ast) = createAstNode("param list");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2258 "src/syntax.tab.c"
    break;

  case 18: /* param_list: param_list ',' param  */
#line 265 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("param list");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2269 "src/syntax.tab.c"
    break;

  case 19: /* param: var_definition  */
#line 274 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("param");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2279 "src/syntax.tab.c"
    break;

  case 20: /* stmts: '{' stmt_list.opt '}'  */
#line 282 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("stmts");
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2289 "src/syntax.tab.c"
    break;

  case 21: /* stmt_list.opt: stmt_list  */
#line 290 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list optional");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2299 "src/syntax.tab.c"
    break;

  case 22: /* stmt_list.opt: %empty  */
#line 295 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list empty"); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2308 "src/syntax.tab.c"
    break;

  case 23: /* stmt_list: stmt_list stmt.item  */
#line 302 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("stmt list");
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2319 "src/syntax.tab.c"
    break;

  case 24: /* stmt_list: stmt.item  */
#line 308 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt list");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2329 "src/syntax.tab.c"
    break;

  case 25: /* stmt.item: stmt  */
#line 316 "src/syntax.y"
            {
		(yyval.ast) = createAstNode("stmt item");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2339 "src/syntax.tab.c"
    break;

  case 26: /* stmt.item: var_declaration  */
#line 321 "src/syntax.y"
                         {
		(yyval.ast) = createAstNode("stmt item");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2349 "src/syntax.tab.c"
    break;

  case 27: /* stmt: return_stmt  */
#line 329 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2359 "src/syntax.tab.c"
    break;

  case 28: /* stmt: select_stmt  */
#line 334 "src/syntax.y"
                     {
		(yyval.ast) = createAstNode("stmt");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2369 "src/syntax.tab.c"
    break;

  case 29: /* stmt: iter_stmt  */
#line 339 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2379 "src/syntax.tab.c"
    break;

  case 30: /* stmt: io_stmt  */
#line 344 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2389 "src/syntax.tab.c"
    break;

  case 31: /* stmt: exp_stmt  */
#line 349 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("stmt");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2399 "src/syntax.tab.c"
    break;

  case 32: /* stmt: stmts  */
#line 354 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("stmt");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2409 "src/syntax.tab.c"
    break;

  case 33: /* select_stmt: IF '(' simple_exp ')' stmt  */
#line 362 "src/syntax.y"
                                             {
		(yyval.ast) = createAstNode("select stmt");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2420 "src/syntax.tab.c"
    break;

  case 34: /* select_stmt: IF '(' simple_exp ')' stmt ELSE stmt  */
#line 368 "src/syntax.y"
                                              {
		(yyval.ast) = createAstNode("select stmt");
		(yyval.ast)->children[0] = (yyvsp[-4].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2432 "src/syntax.tab.c"
    break;

  case 35: /* iter_stmt: FOR '(' exp ';' simple_exp ';' exp ')' stmt  */
#line 378 "src/syntax.y"
                                                   {
		(yyval.ast) = createAstNode("iter stmt");
		(yyval.ast)->children[0] = (yyvsp[-6].ast);
		(yyval.ast)->children[1] = (yyvsp[-4].ast);
		(yyval.ast)->children[2] = (yyvsp[-2].ast);
		(yyval.ast)->children[3] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2445 "src/syntax.tab.c"
    break;

  case 36: /* exp_stmt: exp ';'  */
#line 389 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("expression");
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2455 "src/syntax.tab.c"
    break;

  case 37: /* exp: assign_exp  */
#line 397 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("exp stmt");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2465 "src/syntax.tab.c"
    break;

  case 38: /* exp: simple_exp  */
#line 402 "src/syntax.y"
                    {
		(yyval.ast) = createAstNode("exp stmt");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2475 "src/syntax.tab.c"
    break;

  case 39: /* return_stmt: RETURN exp ';'  */
#line 410 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("return stmt");
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2485 "src/syntax.tab.c"
    break;

  case 40: /* io_stmt: in_stmt  */
#line 418 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("in/out stmt");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2495 "src/syntax.tab.c"
    break;

  case 41: /* io_stmt: out_stmt  */
#line 423 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("in/out stmt");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2505 "src/syntax.tab.c"
    break;

  case 42: /* in_stmt: INPUT '(' ID ')' ';'  */
#line 431 "src/syntax.y"
                            {
		char input_type[200];
		(yyval.ast) = createAstNode("input stmt");
		strcpy(input_type, (yyvsp[-4].lexeme).lexeme_string);
		strcat(input_type, " (");
		strcat(input_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(input_type, ")");
		(yyval.ast)->token_name = strdup(input_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2520 "src/syntax.tab.c"
    break;

  case 43: /* out_stmt: OUTPUT '(' STRING ')' ';'  */
#line 444 "src/syntax.y"
                                 {
		char output_type[200];
		(yyval.ast) = createAstNode("output stmt");
		strcpy(output_type, (yyvsp[-4].lexeme).lexeme_string);
		strcat(output_type, " (");
		strcat(output_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(output_type, ")");
		(yyval.ast)->token_name = strdup(output_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2535 "src/syntax.tab.c"
    break;

  case 44: /* out_stmt: OUTPUT '(' exp ')' ';'  */
#line 454 "src/syntax.y"
                                {
		(yyval.ast) = createAstNode("output stmt");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2545 "src/syntax.tab.c"
    break;

  case 45: /* assign_exp: ID '=' exp  */
#line 462 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("assign exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2555 "src/syntax.tab.c"
    break;

  case 46: /* simple_exp: simple_exp LOGICAL_OR and_exp  */
#line 470 "src/syntax.y"
                                     {
		(yyval.ast) = createAstNode("simple exp");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2566 "src/syntax.tab.c"
    break;

  case 47: /* simple_exp: and_exp  */
#line 476 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("simple exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2576 "src/syntax.tab.c"
    break;

  case 48: /* and_exp: and_exp LOGICAL_AND rel_exp  */
#line 484 "src/syntax.y"
                                   {
		(yyval.ast) = createAstNode("and exp");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2587 "src/syntax.tab.c"
    break;

  case 49: /* and_exp: rel_exp  */
#line 490 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("and exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2597 "src/syntax.tab.c"
    break;

  case 50: /* rel_exp: rel_exp RELATIONAL list_exp  */
#line 498 "src/syntax.y"
                                   {
		(yyval.ast) = createAstNode("rel exp");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2608 "src/syntax.tab.c"
    break;

  case 51: /* rel_exp: list_exp  */
#line 504 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("rel exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2618 "src/syntax.tab.c"
    break;

  case 52: /* list_exp: sum_exp LIST_CONSTR list_exp  */
#line 512 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("list exp");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2629 "src/syntax.tab.c"
    break;

  case 53: /* list_exp: sum_exp LIST_FUNC list_exp  */
#line 518 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("list exp");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2640 "src/syntax.tab.c"
    break;

  case 54: /* list_exp: sum_exp  */
#line 524 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("list exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2650 "src/syntax.tab.c"
    break;

  case 55: /* sum_exp: sum_exp ADD mul_exp  */
#line 532 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("sum exp");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2661 "src/syntax.tab.c"
    break;

  case 56: /* sum_exp: mul_exp  */
#line 538 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("sum exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2671 "src/syntax.tab.c"
    break;

  case 57: /* mul_exp: mul_exp MUL unary_exp  */
#line 546 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("mul exp");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2682 "src/syntax.tab.c"
    break;

  case 58: /* mul_exp: unary_exp  */
#line 552 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("mul exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2692 "src/syntax.tab.c"
    break;

  case 59: /* unary_exp: factor  */
#line 560 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("unary exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2702 "src/syntax.tab.c"
    break;

  case 60: /* unary_exp: LIST_OP unary_exp  */
#line 565 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("unary exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2712 "src/syntax.tab.c"
    break;

  case 61: /* unary_exp: LIST_DESTR unary_exp  */
#line 570 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("unary exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2722 "src/syntax.tab.c"
    break;

  case 62: /* unary_exp: OP_OVERLOAD unary_exp  */
#line 575 "src/syntax.y"
                               {
		(yyval.ast) = createAstNode("unary exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2732 "src/syntax.tab.c"
    break;

  case 63: /* unary_exp: ADD unary_exp  */
#line 580 "src/syntax.y"
                       {
		char signal_type[200];
		strcpy(signal_type, "signed unary exp");
		strcat(signal_type, " (");
		strcat(signal_type, RED);
		strcat(signal_type, (yyvsp[-1].lexeme).lexeme_string);
		strcat(signal_type, WHITE);
		strcat(signal_type, ")");
		(yyval.ast) = createAstNode(signal_type);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2749 "src/syntax.tab.c"
    break;

  case 64: /* factor: ID  */
#line 595 "src/syntax.y"
          {
		char id_type[200];
		(yyval.ast) = createAstNode("factor exp");
		strcpy(id_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(id_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2761 "src/syntax.tab.c"
    break;

  case 65: /* factor: '(' simple_exp ')'  */
#line 602 "src/syntax.y"
                            {
		(yyval.ast) = createAstNode("factor exp");
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2771 "src/syntax.tab.c"
    break;

  case 66: /* factor: func_call  */
#line 607 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("factor exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2781 "src/syntax.tab.c"
    break;

  case 67: /* factor: constant  */
#line 612 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("factor exp");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2791 "src/syntax.tab.c"
    break;

  case 68: /* func_call: ID '(' func_params ')'  */
#line 620 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("func call");
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2801 "src/syntax.tab.c"
    break;

  case 69: /* func_params: simple_exp  */
#line 628 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("func params");
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2811 "src/syntax.tab.c"
    break;

  case 70: /* func_params: func_params ',' simple_exp  */
#line 633 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("func params");
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2822 "src/syntax.tab.c"
    break;

  case 71: /* func_params: %empty  */
#line 639 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("func params empty"); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2831 "src/syntax.tab.c"
    break;

  case 72: /* constant: INTEGER  */
#line 646 "src/syntax.y"
               {
		char int_type[200];
		(yyval.ast) = createAstNode("int constant");
		strcpy(int_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(int_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2843 "src/syntax.tab.c"
    break;

  case 73: /* constant: REAL  */
#line 653 "src/syntax.y"
              {
		char real_type[200];
		(yyval.ast) = createAstNode("real constant");
		strcpy(real_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(real_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2855 "src/syntax.tab.c"
    break;

  case 74: /* constant: NIL_CONSTANT  */
#line 660 "src/syntax.y"
                      {
		char nil_type[200];
		(yyval.ast) = createAstNode("nil constant");
		strcpy(nil_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(nil_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2867 "src/syntax.tab.c"
    break;


#line 2871 "src/syntax.tab.c"

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
          goto yyexhaustedlab;
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 669 "src/syntax.y"


void yyerror(const char *error_msg){
	printf("%sLine:%d\tColumn:%d\t%s%s\n", RED, num_lines, num_chars - yylval.lexeme.length, error_msg, WHITE);
	count_errors+= 1;
}


int main(int argc, char *argv[]){
	if(argc == 2){
		FILE *fp = fopen(argv[1], "r");
		if(fp){
			yyin = fp;
			yyparse();
		}else{
			printf("%sError reading file location, please insert a valid path.%s\n", RED, WHITE);
			return ERROR;
		}
	}else{
		printf("%sError calling analyzer. You must only insert the file and path names as arguments.%s\n", RED, WHITE);
		return ERROR;
	}
	fclose(yyin);

	if(count_errors == 0)
		printAST(&root);
	else
		printf("%s~ AST tree will not be printed, due to syntax error.%s\n", RED, WHITE);
	printTable(&symbolTable);

	freeNode(&root);
	freeSymbols(&symbolTable);

	yylex_destroy();
	if(count_errors == 0){
		printf("%sSyntax analysis finished without errors.%s\n", GREEN, WHITE);
	}else{
		printf("%sSyntax analysis finished with errors.%s\n", RED, WHITE);
	}
	return 0;
}

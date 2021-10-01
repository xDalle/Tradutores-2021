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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2904

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  274

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
       0,   119,   119,   128,   134,   142,   147,   152,   160,   171,
     187,   198,   214,   224,   229,   236,   247,   263,   271,   276,
     282,   290,   298,   306,   311,   318,   324,   332,   337,   345,
     350,   355,   360,   365,   370,   375,   383,   389,   399,   410,
     418,   423,   431,   439,   444,   452,   465,   475,   483,   494,
     503,   508,   516,   525,   533,   542,   550,   559,   568,   576,
     585,   593,   602,   610,   615,   623,   631,   639,   654,   661,
     666,   671,   679,   691,   696,   702,   709,   716,   723
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

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,   209,   250,     7,   221,   232,   316,   372,   -19,    55,
     132,  -132,   414,     5,   210,   422,   185,   330,   197,     1,
       8,   243,   244,   496,   115,   265,    90,   125,   286,  1691,
     509,   321,   875,  2822,   303,   341,   129,   142,   790,   155,
     172,   408,    71,   358,  2822,  2822,  2822,  2513,  1722,  1753,
     182,  1784,  1815,  1846,  1877,  1908,  1939,   203,  1970,  2001,
    2032,  2063,   227,    20,    23,    18,    76,    63,   424,   446,
     463,   533,   566,   249,   731,  2513,   790,    29,   263,   269,
    2477,   292,   284,   528,   790,   741,   778,   795,    11,   557,
    2094,  2125,  2822,  2822,  2822,  2822,  2822,  2822,  2822,    15,
     288,  2156,   212,   297,   300,   289,   136,   350,   302,   894,
     114,   110,   116,   904,   118,   200,   911,  2435,  2536,   305,
     308,   315,   928,  2545,  1164,    38,  2187,  2218,  2249,   247,
    2456,  2568,  2280,   322,  2456,  2311,  1691,    56,  2845,  2614,
    2631,  2597,  2637,  2845,  2845,  2845,  2513,     2,    73,   398,
      16,  2654,  2671,  2677,  2694,  2711,  2575,   342,    88,  2342,
     262,  2854,   687,   951,   934,   968,  2854,  2854,  2854,  2513,
     797,   251,   307,   617,   974,   991,  1008,  1014,  1031,  2845,
    2373,  2854,   837,   296,   348,   790,   371,   373,  1691,  1195,
    1226,  1257,  1288,   382,  1319,  1350,  1381,  1412,   355,  2717,
     528,  2734,  2751,  2757,    96,  2845,  2845,  2845,  2845,  2845,
    2845,  2568,  1048,   528,  1054,  1071,  1088,   120,  2854,  2854,
    2854,  2854,  2854,  2854,   102,   829,  2513,   790,   384,   390,
    2504,   404,  1443,  2404,   354,  2774,   572,   673,  2791,   691,
     751,  2797,   403,   357,  1094,   360,  2481,  1111,  2860,  2870,
    1128,   186,   401,  1474,   410,   413,   416,  1505,  2814,  1134,
    2435,  2536,   417,   420,   423,  1536,    62,  1567,  1598,  1629,
    2568,   419,  2435,  1660
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,   453,  -132,   260,  -132,  -132,  -132,  -132,
    -132,   448,   -26,  -131,  -132,   427,  -113,  -116,  -114,   -89,
     -30,   -88,   -66,   -58,   -56,   -69,   609,   -15,   562,   397,
     507,   452,   -31,    82,   190,  -124,   295
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    18,    48,     7,    19,     8,    20,
      21,    22,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,   107,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,   190,    74,   191,   124,   198,    16,    11,    78,   -50,
     205,   157,    13,    85,    86,    87,   152,   132,   179,   207,
      17,   135,   179,   -58,   -58,   -53,   -53,    92,   192,   194,
     -50,    93,   147,    26,   -50,   208,   -51,   -14,   209,   -58,
     -13,    94,     1,   109,   152,    92,   100,   117,   -58,   152,
     104,   195,   175,   -53,   108,   -41,     2,   231,   -50,   196,
     147,   197,   157,   -51,   -51,   147,    95,   116,   170,    92,
     -58,   -58,    14,   131,   -68,   -68,   234,   110,   -68,   -68,
     -53,   -53,    96,   -55,   -55,    97,   -58,   193,   -51,   243,
     -68,   189,   175,   -68,   -68,   179,   206,   270,   -58,   -55,
     152,   133,    83,   179,    84,   -53,   -68,   199,   170,   -49,
     205,   -55,   201,   202,   203,   152,   147,   -52,   -52,    29,
     -41,   -49,    93,   -54,   -54,   -56,   -56,   179,   235,   153,
     212,   147,    28,    94,   -49,   214,   215,   216,   152,   -54,
      17,   -56,   157,   181,   190,   -52,   191,   265,   152,   -49,
     175,   -54,   244,   -56,   147,   228,   190,   153,   191,   273,
      75,   157,   153,   -15,   224,   176,   225,    15,   -73,   175,
     -73,   192,   194,    76,   152,   152,   152,   152,   152,   241,
     152,   242,   175,   192,   194,   170,    79,   175,   175,   175,
     175,   175,   250,   179,   195,   152,   147,   252,   170,   152,
     256,   157,   196,    80,   197,   176,   195,   -57,   -57,    -7,
      -7,   147,    89,   153,   196,   147,   197,   -20,   260,   -20,
     153,    -2,     1,   -57,    -7,   153,   153,   153,   153,   -21,
     193,   -21,    -4,    -4,   189,   -57,     2,   154,    91,   152,
     271,   -16,   193,   176,   119,    23,   189,    -4,   176,   176,
     176,   153,   -68,   -68,   181,   147,   -68,   -68,   -53,   -53,
       6,   153,   -40,   176,     6,   154,     9,    10,   -68,   -51,
     154,   -68,   -68,   177,   219,   -17,   -18,    27,   -18,   -74,
      83,   -74,   176,   -53,   -68,   -53,   102,   153,   153,   153,
     153,   153,   153,   153,   -51,   176,   -51,    -8,   101,    -8,
     176,   176,   176,   176,   176,   176,   -76,   -76,   153,   105,
     -76,   -76,   153,   177,   -55,   -55,    -5,    -5,    -9,   159,
      -9,   154,   -76,   118,   180,   -76,   -76,   226,   154,   120,
     -55,    -5,   121,   154,   154,   154,   154,   -48,   -76,   -55,
     126,   -55,   155,   127,   -77,   -77,    24,    25,   -77,   -77,
     128,   177,   153,   -19,   134,   -19,   177,   177,   177,   154,
     -77,   -78,   -78,   -77,   -77,   -78,   -78,   -52,   -52,   154,
     155,   177,    -6,    -6,   -40,   155,   -77,   -78,   178,   227,
     -78,   -78,   122,   219,   123,   233,   258,    -6,   123,   259,
     177,   123,   -52,   -78,   -52,   154,   154,   154,   154,   154,
     154,   154,   229,   177,   230,   -55,   -55,   254,   177,   177,
     177,   177,   177,   177,    -3,    -3,   154,   232,   178,   253,
     154,   -55,   -10,   -10,    81,    82,   155,   -60,    98,    -3,
     -55,   -60,   -60,   155,   257,   -48,   261,   -10,   155,   155,
     155,   155,   262,   -60,   149,   263,   -60,   -60,   264,   -62,
     -62,   272,   267,   -62,   -62,   268,   178,    12,   269,   -60,
     154,   178,   178,   178,   155,   -62,   -63,   -63,   -62,   -62,
     -63,   -63,   149,     0,   155,    31,   178,   149,    90,     0,
     172,   -62,   -63,     0,     0,   -63,   -63,     0,     0,     0,
       0,   112,     0,   114,   115,   178,   -11,   -11,   -63,   151,
     155,   155,   155,   155,   155,   155,   155,     0,   178,   -12,
     -12,   -11,     0,   178,   178,   178,   178,   178,   178,     0,
     172,   155,     0,     0,   -12,   155,     0,   151,   149,   160,
       0,   161,   151,   162,   163,   174,   -70,   -70,     0,     0,
     -70,   -70,     0,   149,     0,   164,   165,   113,   166,   167,
       0,     0,   -70,   168,   150,   -70,   -70,   -22,   -22,   169,
     -75,     0,   -75,     0,     0,   155,   149,     0,   -70,   -71,
     -71,     0,   -22,   -71,   -71,   174,   149,     0,   172,   -52,
     -52,     0,   150,   151,     0,   -71,     0,   150,   -71,   -71,
     173,     0,     0,     0,     0,   206,     0,   172,   151,     0,
       0,   -71,   149,   237,   -52,   239,   240,     0,   149,   148,
     172,     0,     0,     0,     0,   172,   246,     0,   248,   249,
     220,   151,     0,   149,   -58,   -58,     0,   149,     0,     0,
     173,   151,     0,   174,     0,     0,   221,   148,   150,   222,
     -58,     0,   148,     0,     0,   171,     0,     0,     0,   -58,
       0,   -58,   174,   150,     0,   111,    88,   151,   151,   238,
     151,   151,     0,   151,     0,   174,     0,   149,     0,     0,
     174,   174,   247,   174,   174,     0,   150,     0,   151,     0,
     -54,   -54,   151,     0,    99,   171,   150,     0,   173,   158,
     -76,   -76,   106,   148,   -76,   -76,   -54,     0,   -56,   -56,
       0,     0,     0,     0,     0,   -54,   -76,   173,   148,   -76,
     -76,     0,   150,   150,   -56,   150,   150,     0,   150,   -76,
     173,   -76,   151,   -56,     0,   173,   173,   125,   173,   173,
       0,   148,   129,   150,   -67,   -67,     0,   150,   -67,   -67,
     158,   148,     0,   171,   -64,   -64,     0,     0,   -64,   -64,
     -67,     0,     0,   -67,   -67,   204,     0,     0,   -57,   -57,
     -64,     0,   171,   -64,   -64,     0,   -67,   236,     0,     0,
       0,     0,     0,   148,   -57,   171,   -64,   150,   217,     0,
     245,   -65,   -65,   -57,     0,   -65,   -65,     0,   148,     0,
       0,    77,   148,    33,     0,    34,    35,   -65,   -66,   -66,
     -65,   -65,   -66,   -66,   -50,   218,     0,    42,    43,   106,
      44,    45,     0,   -65,   -66,    46,     0,   -66,   -66,     0,
     158,    47,   106,     0,     0,     0,     0,     0,     0,   -50,
     -66,   -50,   148,     0,     0,   251,   -49,   218,   -35,   158,
     -35,     0,   -35,   -35,   -51,     0,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,     0,   -35,   -35,     0,   -35,   -35,     0,
       0,   -49,   -35,   -49,     0,     0,   -35,   -35,   -35,     0,
     266,     0,   -51,     0,     0,     0,   -35,     0,   -35,   158,
     -35,   -35,   -51,     0,   -35,     0,   -35,   -35,   -35,   -35,
     -35,     0,   -35,   -35,     0,   -35,   -35,   -69,   -69,     0,
     -35,   -69,   -69,     0,   -35,   -35,   -35,   -59,    98,     0,
     -51,   -59,   -59,   -69,   -61,   -61,   -69,   -69,   -61,   -61,
       0,     0,     0,   -59,     0,     0,   -59,   -59,     0,   -69,
     -61,   -72,   -72,   -61,   -61,   -72,   -72,   -68,   -68,   -59,
       0,   -68,   -68,     0,     0,     0,   -61,   -72,     0,     0,
     -72,   -72,     0,   -68,   -77,   -77,   -68,   -68,   -77,   -77,
       0,     0,     0,   -72,     0,   213,   -68,     0,   -68,     0,
     -77,   -78,   -78,   -77,   -77,   -78,   -78,   -60,   223,     0,
       0,   -60,   -60,   -77,     0,   -77,     0,   -78,     0,     0,
     -78,   -78,     0,   -60,   -62,   -62,   -60,   -60,   -62,   -62,
     -78,     0,   -78,     0,     0,     0,   -60,     0,   -60,     0,
     -62,   -63,   -63,   -62,   -62,   -63,   -63,   -70,   -70,     0,
       0,   -70,   -70,   -62,     0,   -62,     0,   -63,     0,     0,
     -63,   -63,     0,   -70,   -71,   -71,   -70,   -70,   -71,   -71,
     -63,     0,   -63,     0,     0,     0,   -70,     0,   -70,     0,
     -71,   -67,   -67,   -71,   -71,   -67,   -67,   -64,   -64,     0,
       0,   -64,   -64,   -71,     0,   -71,     0,   -67,     0,     0,
     -67,   -67,     0,   -64,   -65,   -65,   -64,   -64,   -65,   -65,
     -67,     0,   -67,     0,     0,     0,   -64,     0,   -64,     0,
     -65,   -66,   -66,   -65,   -65,   -66,   -66,   -69,   -69,     0,
       0,   -69,   -69,   -65,     0,   -65,     0,   -66,     0,     0,
     -66,   -66,     0,   -69,   -59,   223,   -69,   -69,   -59,   -59,
     -66,     0,   -66,     0,     0,     0,   -69,     0,   -69,     0,
     -59,   -61,   -61,   -59,   -59,   -61,   -61,   -72,   -72,     0,
       0,   -72,   -72,   -59,     0,   -59,     0,   -61,     0,     0,
     -61,   -61,     0,   -72,     0,     0,   -72,   -72,     0,     0,
     -61,     0,   -61,     0,     0,   -36,   -72,   -36,   -72,   -36,
     -36,     0,     0,   -36,   130,   -36,   -36,   -36,   -36,   -36,
       0,   -36,   -36,     0,   -36,   -36,     0,     0,     0,   -36,
       0,     0,     0,   -36,   -36,   -36,   -34,     0,   -34,     0,
     -34,   -34,     0,     0,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,     0,   -34,   -34,     0,   -34,   -34,     0,     0,     0,
     -34,     0,     0,     0,   -34,   -34,   -34,   -30,     0,   -30,
       0,   -30,   -30,     0,     0,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,     0,   -30,   -30,     0,   -30,   -30,     0,     0,
       0,   -30,     0,     0,     0,   -30,   -30,   -30,   -31,     0,
     -31,     0,   -31,   -31,     0,     0,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,     0,   -31,   -31,     0,   -31,   -31,     0,
       0,     0,   -31,     0,     0,     0,   -31,   -31,   -31,   -33,
       0,   -33,     0,   -33,   -33,     0,     0,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,     0,   -33,   -33,     0,   -33,   -33,
       0,     0,     0,   -33,     0,     0,     0,   -33,   -33,   -33,
     -29,     0,   -29,     0,   -29,   -29,     0,     0,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,     0,   -29,
     -29,     0,     0,     0,   -29,     0,     0,     0,   -29,   -29,
     -29,   -32,     0,   -32,     0,   -32,   -32,     0,     0,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,     0,
     -32,   -32,     0,     0,     0,   -32,     0,     0,     0,   -32,
     -32,   -32,   -43,     0,   -43,     0,   -43,   -43,     0,     0,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,
       0,   -43,   -43,     0,     0,     0,   -43,     0,     0,     0,
     -43,   -43,   -43,   -44,     0,   -44,     0,   -44,   -44,     0,
       0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,
     -44,     0,   -44,   -44,     0,     0,     0,   -44,     0,     0,
       0,   -44,   -44,   -44,   -39,     0,   -39,     0,   -39,   -39,
       0,     0,   -39,   -39,   -39,   -39,   -39,   -39,   -39,     0,
     -39,   -39,     0,   -39,   -39,     0,     0,     0,   -39,     0,
       0,     0,   -39,   -39,   -39,   -42,     0,   -42,     0,   -42,
     -42,     0,     0,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
       0,   -42,   -42,     0,   -42,   -42,     0,     0,     0,   -42,
       0,     0,     0,   -42,   -42,   -42,   -22,     0,   -22,     0,
     -22,   -22,     0,     0,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,     0,   -22,   -22,     0,   -22,   -22,     0,     0,     0,
     -22,     0,     0,     0,   -22,   -22,   -22,   -36,     0,   -36,
       0,   -36,   -36,     0,     0,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,   -36,     0,   -36,   -36,     0,     0,
       0,   -36,     0,     0,     0,   -36,   -36,   -36,   -45,     0,
     -45,     0,   -45,   -45,     0,     0,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,     0,   -45,   -45,     0,   -45,   -45,     0,
       0,     0,   -45,     0,     0,     0,   -45,   -45,   -45,   -46,
       0,   -46,     0,   -46,   -46,     0,     0,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,     0,   -46,   -46,     0,   -46,   -46,
       0,     0,     0,   -46,     0,     0,     0,   -46,   -46,   -46,
     -47,     0,   -47,     0,   -47,   -47,     0,     0,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,     0,   -47,
     -47,     0,     0,     0,   -47,     0,     0,     0,   -47,   -47,
     -47,   -38,     0,   -38,     0,   -38,   -38,     0,     0,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,   -38,     0,
     -38,   -38,     0,     0,     0,   -38,     0,     0,     0,   -38,
     -38,   -38,    32,     0,    33,     0,    34,    35,     0,     0,
      36,     0,    37,    38,    39,    40,    41,     0,    42,    43,
       0,    44,    45,     0,     0,     0,    46,     0,     0,     0,
     136,   -24,    47,   -28,     0,   -28,     0,   -28,   -28,     0,
       0,   -28,     0,   -28,   -28,   -28,   -28,   -28,     0,   -28,
     -28,     0,   -28,   -28,     0,     0,     0,   -28,     0,     0,
       0,   -28,   -28,   -28,   -34,     0,   -34,     0,   -34,   -34,
       0,     0,   -34,     0,   -34,   -34,   -34,   -34,   -34,     0,
     -34,   -34,     0,   -34,   -34,     0,     0,     0,   -34,     0,
       0,     0,   -34,   -34,   -34,    32,     0,    33,     0,    34,
      35,     0,     0,    36,     0,    37,    38,    39,    40,    41,
       0,    42,    43,     0,    44,    45,     0,     0,     0,    46,
       0,     0,     0,   136,   -23,    47,   -26,     0,   -26,     0,
     -26,   -26,     0,     0,   -26,     0,   -26,   -26,   -26,   -26,
     -26,     0,   -26,   -26,     0,   -26,   -26,     0,     0,     0,
     -26,     0,     0,     0,   -26,   -26,   -26,   -27,     0,   -27,
       0,   -27,   -27,     0,     0,   -27,     0,   -27,   -27,   -27,
     -27,   -27,     0,   -27,   -27,     0,   -27,   -27,     0,     0,
       0,   -27,     0,     0,     0,   -27,   -27,   -27,   -30,     0,
     -30,     0,   -30,   -30,     0,     0,   -30,     0,   -30,   -30,
     -30,   -30,   -30,     0,   -30,   -30,     0,   -30,   -30,     0,
       0,     0,   -30,     0,     0,     0,   -30,   -30,   -30,   -31,
       0,   -31,     0,   -31,   -31,     0,     0,   -31,     0,   -31,
     -31,   -31,   -31,   -31,     0,   -31,   -31,     0,   -31,   -31,
       0,     0,     0,   -31,     0,     0,     0,   -31,   -31,   -31,
     -33,     0,   -33,     0,   -33,   -33,     0,     0,   -33,     0,
     -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,     0,   -33,
     -33,     0,     0,     0,   -33,     0,     0,     0,   -33,   -33,
     -33,   -29,     0,   -29,     0,   -29,   -29,     0,     0,   -29,
       0,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,     0,
     -29,   -29,     0,     0,     0,   -29,     0,     0,     0,   -29,
     -29,   -29,   -32,     0,   -32,     0,   -32,   -32,     0,     0,
     -32,     0,   -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,
       0,   -32,   -32,     0,     0,     0,   -32,     0,     0,     0,
     -32,   -32,   -32,   -43,     0,   -43,     0,   -43,   -43,     0,
       0,   -43,     0,   -43,   -43,   -43,   -43,   -43,     0,   -43,
     -43,     0,   -43,   -43,     0,     0,     0,   -43,     0,     0,
       0,   -43,   -43,   -43,   -44,     0,   -44,     0,   -44,   -44,
       0,     0,   -44,     0,   -44,   -44,   -44,   -44,   -44,     0,
     -44,   -44,     0,   -44,   -44,     0,     0,     0,   -44,     0,
       0,     0,   -44,   -44,   -44,   -25,     0,   -25,     0,   -25,
     -25,     0,     0,   -25,     0,   -25,   -25,   -25,   -25,   -25,
       0,   -25,   -25,     0,   -25,   -25,     0,     0,     0,   -25,
       0,     0,     0,   -25,   -25,   -25,   -39,     0,   -39,     0,
     -39,   -39,     0,     0,   -39,     0,   -39,   -39,   -39,   -39,
     -39,     0,   -39,   -39,     0,   -39,   -39,     0,     0,     0,
     -39,     0,     0,     0,   -39,   -39,   -39,   -42,     0,   -42,
       0,   -42,   -42,     0,     0,   -42,     0,   -42,   -42,   -42,
     -42,   -42,     0,   -42,   -42,     0,   -42,   -42,     0,     0,
       0,   -42,     0,     0,     0,   -42,   -42,   -42,   -45,     0,
     -45,     0,   -45,   -45,     0,     0,   -45,     0,   -45,   -45,
     -45,   -45,   -45,     0,   -45,   -45,     0,   -45,   -45,     0,
       0,     0,   -45,     0,     0,     0,   -45,   -45,   -45,   -46,
       0,   -46,     0,   -46,   -46,     0,     0,   -46,     0,   -46,
     -46,   -46,   -46,   -46,     0,   -46,   -46,     0,   -46,   -46,
       0,     0,     0,   -46,     0,     0,     0,   -46,   -46,   -46,
     -47,     0,   -47,     0,   -47,   -47,     0,     0,   -47,     0,
     -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,     0,   -47,
     -47,     0,     0,     0,   -47,     0,     0,     0,   -47,   -47,
     -47,   -37,     0,   -37,     0,   -37,   -37,     0,     0,   -37,
       0,   -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,     0,
     -37,   -37,     0,     0,     0,   -37,     0,     0,     0,   -37,
     -37,   -37,   -38,     0,   -38,     0,   -38,   -38,     0,     0,
     -38,     0,   -38,   -38,   -38,   -38,   -38,     0,   -38,   -38,
       0,   -38,   -38,     0,     0,     0,   -38,     0,     0,     0,
     -38,   -38,   -38,   -10,     0,   -10,     0,   -10,   -10,     0,
       0,   -10,     0,   -10,   -10,   -10,   -10,   -10,     0,   -10,
     -10,     0,   -10,   -10,     0,     0,     0,   -10,     0,     0,
       0,   -10,   -10,   -10,   -11,     0,   -11,     0,   -11,   -11,
       0,     0,   -11,     0,   -11,   -11,   -11,   -11,   -11,     0,
     -11,   -11,     0,   -11,   -11,     0,     0,     0,   -11,     0,
       0,     0,   -11,   -11,   -11,   -22,     0,   -22,     0,   -22,
     -22,     0,     0,   -22,     0,   -22,   -22,   -22,   -22,   -22,
       0,   -22,   -22,     0,   -22,   -22,     0,     0,     0,   -22,
       0,     0,     0,   -22,   -22,   -22,   182,     0,    33,     0,
      34,    35,     0,     0,   183,     0,   184,   185,   186,   187,
       0,     0,    42,    43,     0,    44,    45,    32,     0,    33,
      46,    34,    35,     0,   188,    36,    47,    37,    38,    39,
      40,     0,     0,    42,    43,     0,    44,    45,   137,     0,
     138,    46,   139,   140,     0,   136,     0,    47,   -54,   -54,
       0,     0,     0,     0,   156,   142,     0,   143,   144,     0,
       0,   103,   145,     0,   -54,   137,     0,   138,   146,   139,
     140,     0,     0,   -54,   137,   -54,   138,     0,   139,   140,
       0,   156,   142,     0,   143,   144,     0,     0,   255,   145,
     141,   142,     0,   143,   144,   146,     0,    77,   145,    33,
       0,    34,    35,     0,   146,     0,   160,     0,   161,     0,
     162,   163,     0,    73,    43,     0,    44,    45,     0,     0,
       0,    46,   164,   165,     0,   166,   167,    47,     0,   137,
     168,   138,     0,   139,   140,     0,   169,     0,   -68,   -68,
       0,     0,   -68,   -68,     0,   156,   142,     0,   143,   144,
       0,     0,     0,   145,   -68,     0,     0,   -68,   -68,   146,
     -68,   -68,     0,     0,   -68,   -68,   200,   -68,   211,     0,
       0,     0,     0,     0,     0,     0,   -68,   -76,   -76,   -68,
     -68,   -76,   -76,     0,     0,     0,     0,     0,   200,   -68,
       0,     0,     0,   -76,   -77,   -77,   -76,   -76,   -77,   -77,
     -78,   -78,     0,     0,   -78,   -78,   -76,     0,     0,     0,
     -77,     0,     0,   -77,   -77,     0,   -78,   -60,   210,   -78,
     -78,   -60,   -60,   -77,     0,     0,     0,     0,     0,   -78,
       0,     0,     0,   -60,   -62,   -62,   -60,   -60,   -62,   -62,
     -63,   -63,     0,     0,   -63,   -63,   -60,     0,     0,     0,
     -62,     0,     0,   -62,   -62,     0,   -63,   -70,   -70,   -63,
     -63,   -70,   -70,   -62,     0,     0,     0,     0,     0,   -63,
       0,     0,     0,   -70,   -71,   -71,   -70,   -70,   -71,   -71,
     -67,   -67,     0,     0,   -67,   -67,   -70,     0,     0,     0,
     -71,     0,     0,   -71,   -71,     0,   -67,   -64,   -64,   -67,
     -67,   -64,   -64,   -71,     0,     0,     0,     0,     0,   -67,
       0,     0,     0,   -64,   -65,   -65,   -64,   -64,   -65,   -65,
     -66,   -66,     0,     0,   -66,   -66,   -64,     0,     0,     0,
     -65,     0,     0,   -65,   -65,     0,   -66,   -69,   -69,   -66,
     -66,   -69,   -69,   -65,     0,     0,     0,     0,     0,   -66,
       0,     0,     0,   -69,   -59,   210,   -69,   -69,   -59,   -59,
     -61,   -61,     0,     0,   -61,   -61,   -69,     0,     0,     0,
     -59,     0,     0,   -59,   -59,     0,   -61,   -72,   -72,   -61,
     -61,   -72,   -72,   -59,     0,    33,     0,    34,    35,   -61,
       0,     0,     0,   -72,     0,     0,   -72,   -72,     0,    73,
      43,     0,    44,    45,     0,     0,   -72,    46,   138,     0,
     139,   140,     0,    47,     0,     0,     0,   161,     0,   162,
     163,     0,   141,   142,     0,   143,   144,   -56,   -56,     0,
     145,   164,   165,     0,   166,   167,   146,   -57,   -57,   168,
       0,     0,     0,   -56,     0,   169,     0,     0,     0,     0,
       0,     0,   -56,   -57,   -56,     0,     0,     0,     0,     0,
       0,     0,   -57,     0,   -57
};

static const yytype_int16 yycheck[] =
{
      26,   117,    33,   117,   117,   136,     1,     0,    38,     7,
       8,    80,    31,    44,    45,    46,    47,   130,     7,     3,
      15,   134,     7,     7,     8,     7,     8,     7,   117,   117,
       7,     8,    47,    32,    32,    19,     7,    32,    22,    23,
      32,    23,     1,    32,    75,     7,    76,    32,    32,    80,
      80,   117,    83,    35,    84,    35,    15,   188,    35,   117,
      75,   117,   131,     7,    35,    80,     3,    98,    83,     7,
       7,     8,    17,    35,     3,     4,   200,    92,     7,     8,
       7,     8,    19,     7,     8,    22,    23,   117,    32,   213,
      19,   117,   123,    22,    23,     7,    23,    35,    35,    23,
     131,   131,    31,     7,    33,    32,    35,   138,   123,     7,
       8,    35,   143,   144,   145,   146,   131,     7,     8,    29,
      32,     7,     8,     7,     8,     7,     8,     7,    32,    47,
     161,   146,    17,    23,    32,   166,   167,   168,   169,    23,
      15,    23,   211,     7,   260,    35,   260,   260,   179,    35,
     181,    35,    32,    35,   169,   185,   272,    75,   272,   272,
      31,   230,    80,    31,   179,    83,   181,    35,    32,   200,
      34,   260,   260,    31,   205,   206,   207,   208,   209,   210,
     211,   211,   213,   272,   272,   200,    31,   218,   219,   220,
     221,   222,   223,     7,   260,   226,   211,   227,   213,   230,
     230,   270,   260,    31,   260,   123,   272,     7,     8,     0,
       1,   226,    30,   131,   272,   230,   272,    32,    32,    34,
     138,     0,     1,    23,    15,   143,   144,   145,   146,    32,
     260,    34,     0,     1,   260,    35,    15,    47,    35,   270,
     270,    31,   272,   161,    32,    35,   272,    15,   166,   167,
     168,   169,     3,     4,     7,   270,     7,     8,     7,     8,
       0,   179,    35,   181,     4,    75,    16,    17,    19,     7,
      80,    22,    23,    83,    23,    32,    32,    34,    34,    32,
      31,    34,   200,    32,    35,    34,    17,   205,   206,   207,
     208,   209,   210,   211,    32,   213,    34,    32,    35,    34,
     218,   219,   220,   221,   222,   223,     3,     4,   226,    17,
       7,     8,   230,   123,     7,     8,     0,     1,    32,    35,
      34,   131,    19,    35,    35,    22,    23,    31,   138,    32,
      23,    15,    32,   143,   144,   145,   146,    35,    35,    32,
      35,    34,    47,    35,     3,     4,    16,    17,     7,     8,
      35,   161,   270,    32,    32,    34,   166,   167,   168,   169,
      19,     3,     4,    22,    23,     7,     8,     7,     8,   179,
      75,   181,     0,     1,    32,    80,    35,    19,    83,    31,
      22,    23,    32,    23,    34,    30,    32,    15,    34,    32,
     200,    34,    32,    35,    34,   205,   206,   207,   208,   209,
     210,   211,    31,   213,    31,     7,     8,    17,   218,   219,
     220,   221,   222,   223,     0,     1,   226,    35,   123,    35,
     230,    23,     0,     1,    16,    17,   131,     3,     4,    15,
      32,     7,     8,   138,    30,    32,    35,    15,   143,   144,
     145,   146,    32,    19,    47,    32,    22,    23,    32,     3,
       4,    32,    35,     7,     8,    35,   161,     4,    35,    35,
     270,   166,   167,   168,   169,    19,     3,     4,    22,    23,
       7,     8,    75,    -1,   179,    27,   181,    80,    51,    -1,
      83,    35,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    94,    -1,    96,    97,   200,     0,     1,    35,    47,
     205,   206,   207,   208,   209,   210,   211,    -1,   213,     0,
       1,    15,    -1,   218,   219,   220,   221,   222,   223,    -1,
     123,   226,    -1,    -1,    15,   230,    -1,    75,   131,     1,
      -1,     3,    80,     5,     6,    83,     3,     4,    -1,    -1,
       7,     8,    -1,   146,    -1,    17,    18,    95,    20,    21,
      -1,    -1,    19,    25,    47,    22,    23,     0,     1,    31,
      32,    -1,    34,    -1,    -1,   270,   169,    -1,    35,     3,
       4,    -1,    15,     7,     8,   123,   179,    -1,   181,     7,
       8,    -1,    75,   131,    -1,    19,    -1,    80,    22,    23,
      83,    -1,    -1,    -1,    -1,    23,    -1,   200,   146,    -1,
      -1,    35,   205,   206,    32,   208,   209,    -1,   211,    47,
     213,    -1,    -1,    -1,    -1,   218,   219,    -1,   221,   222,
       3,   169,    -1,   226,     7,     8,    -1,   230,    -1,    -1,
     123,   179,    -1,   181,    -1,    -1,    19,    75,   131,    22,
      23,    -1,    80,    -1,    -1,    83,    -1,    -1,    -1,    32,
      -1,    34,   200,   146,    -1,    93,    47,   205,   206,   207,
     208,   209,    -1,   211,    -1,   213,    -1,   270,    -1,    -1,
     218,   219,   220,   221,   222,    -1,   169,    -1,   226,    -1,
       7,     8,   230,    -1,    75,   123,   179,    -1,   181,    80,
       3,     4,    83,   131,     7,     8,    23,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    32,    19,   200,   146,    22,
      23,    -1,   205,   206,    23,   208,   209,    -1,   211,    32,
     213,    34,   270,    32,    -1,   218,   219,   118,   221,   222,
      -1,   169,   123,   226,     3,     4,    -1,   230,     7,     8,
     131,   179,    -1,   181,     3,     4,    -1,    -1,     7,     8,
      19,    -1,    -1,    22,    23,   146,    -1,    -1,     7,     8,
      19,    -1,   200,    22,    23,    -1,    35,   205,    -1,    -1,
      -1,    -1,    -1,   211,    23,   213,    35,   270,   169,    -1,
     218,     3,     4,    32,    -1,     7,     8,    -1,   226,    -1,
      -1,     1,   230,     3,    -1,     5,     6,    19,     3,     4,
      22,    23,     7,     8,     7,     8,    -1,    17,    18,   200,
      20,    21,    -1,    35,    19,    25,    -1,    22,    23,    -1,
     211,    31,   213,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      35,    34,   270,    -1,    -1,   226,     7,     8,     1,   230,
       3,    -1,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    32,    25,    34,    -1,    -1,    29,    30,    31,    -1,
     261,    -1,    35,    -1,    -1,    -1,     1,    -1,     3,   270,
       5,     6,     7,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,     3,     4,    -1,
      25,     7,     8,    -1,    29,    30,    31,     3,     4,    -1,
      35,     7,     8,    19,     3,     4,    22,    23,     7,     8,
      -1,    -1,    -1,    19,    -1,    -1,    22,    23,    -1,    35,
      19,     3,     4,    22,    23,     7,     8,     3,     4,    35,
      -1,     7,     8,    -1,    -1,    -1,    35,    19,    -1,    -1,
      22,    23,    -1,    19,     3,     4,    22,    23,     7,     8,
      -1,    -1,    -1,    35,    -1,    31,    32,    -1,    34,    -1,
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
      22,    23,    -1,    19,    -1,    -1,    22,    23,    -1,    -1,
      32,    -1,    34,    -1,    -1,     1,    32,     3,    34,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,    -1,
       5,     6,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,
      -1,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,
       3,    -1,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,
      -1,     3,    -1,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       1,    -1,     3,    -1,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     1,    -1,     3,    -1,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     1,    -1,     3,    -1,     5,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     1,    -1,     3,    -1,     5,     6,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     1,    -1,     3,    -1,     5,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     1,    -1,     3,    -1,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,    -1,
       5,     6,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,
      -1,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,
       3,    -1,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,
      -1,     3,    -1,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       1,    -1,     3,    -1,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     1,    -1,     3,    -1,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     1,    -1,     3,    -1,     5,     6,    -1,    -1,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     1,    -1,     3,    -1,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     1,    -1,     3,    -1,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     1,    -1,     3,    -1,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,    -1,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,
      -1,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,
       3,    -1,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,
      -1,     3,    -1,     5,     6,    -1,    -1,     9,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       1,    -1,     3,    -1,     5,     6,    -1,    -1,     9,    -1,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     1,    -1,     3,    -1,     5,     6,    -1,    -1,     9,
      -1,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     1,    -1,     3,    -1,     5,     6,    -1,    -1,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     1,    -1,     3,    -1,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     1,    -1,     3,    -1,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     1,    -1,     3,    -1,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,    -1,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,
      -1,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,
       3,    -1,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,
      -1,     3,    -1,     5,     6,    -1,    -1,     9,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       1,    -1,     3,    -1,     5,     6,    -1,    -1,     9,    -1,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     1,    -1,     3,    -1,     5,     6,    -1,    -1,     9,
      -1,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     1,    -1,     3,    -1,     5,     6,    -1,    -1,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     1,    -1,     3,    -1,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     1,    -1,     3,    -1,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     1,    -1,     3,    -1,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,    -1,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      -1,    -1,    17,    18,    -1,    20,    21,     1,    -1,     3,
      25,     5,     6,    -1,    29,     9,    31,    11,    12,    13,
      14,    -1,    -1,    17,    18,    -1,    20,    21,     1,    -1,
       3,    25,     5,     6,    -1,    29,    -1,    31,     7,     8,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    24,    25,    -1,    23,     1,    -1,     3,    31,     5,
       6,    -1,    -1,    32,     1,    34,     3,    -1,     5,     6,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    24,    25,
      17,    18,    -1,    20,    21,    31,    -1,     1,    25,     3,
      -1,     5,     6,    -1,    31,    -1,     1,    -1,     3,    -1,
       5,     6,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    17,    18,    -1,    20,    21,    31,    -1,     1,
      25,     3,    -1,     5,     6,    -1,    31,    -1,     3,     4,
      -1,    -1,     7,     8,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    19,    -1,    -1,    22,    23,    31,
       3,     4,    -1,    -1,     7,     8,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,     3,     4,    22,
      23,     7,     8,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    19,     3,     4,    22,    23,     7,     8,
       3,     4,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,
      19,    -1,    -1,    22,    23,    -1,    19,     3,     4,    22,
      23,     7,     8,    32,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    19,     3,     4,    22,    23,     7,     8,
       3,     4,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,
      19,    -1,    -1,    22,    23,    -1,    19,     3,     4,    22,
      23,     7,     8,    32,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    19,     3,     4,    22,    23,     7,     8,
       3,     4,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,
      19,    -1,    -1,    22,    23,    -1,    19,     3,     4,    22,
      23,     7,     8,    32,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    19,     3,     4,    22,    23,     7,     8,
       3,     4,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,
      19,    -1,    -1,    22,    23,    -1,    19,     3,     4,    22,
      23,     7,     8,    32,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    19,     3,     4,    22,    23,     7,     8,
       3,     4,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,
      19,    -1,    -1,    22,    23,    -1,    19,     3,     4,    22,
      23,     7,     8,    32,    -1,     3,    -1,     5,     6,    32,
      -1,    -1,    -1,    19,    -1,    -1,    22,    23,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    32,    25,     3,    -1,
       5,     6,    -1,    31,    -1,    -1,    -1,     3,    -1,     5,
       6,    -1,    17,    18,    -1,    20,    21,     7,     8,    -1,
      25,    17,    18,    -1,    20,    21,    31,     7,     8,    25,
      -1,    -1,    -1,    23,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    23,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    15,    38,    39,    40,    42,    43,    45,    16,
      17,     0,    40,    31,    17,    35,     1,    15,    41,    44,
      46,    47,    48,    35,    16,    17,    32,    34,    17,    29,
      49,    48,     1,     3,     5,     6,     9,    11,    12,    13,
      14,    15,    17,    18,    20,    21,    25,    31,    42,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    73,    17,    69,    31,    31,     1,    57,    31,
      31,    16,    17,    31,    33,    69,    69,    69,    63,    30,
      52,    35,     7,     8,    23,     3,    19,    22,     4,    63,
      57,    35,    17,    24,    57,    17,    63,    72,    57,    32,
      64,    65,    66,    68,    66,    66,    69,    32,    35,    32,
      32,    32,    32,    34,    53,    63,    35,    35,    35,    63,
      10,    35,    53,    57,    32,    53,    29,     1,     3,     5,
       6,    17,    18,    20,    21,    25,    31,    64,    65,    66,
      67,    68,    69,    70,    71,    73,    17,    62,    63,    35,
       1,     3,     5,     6,    17,    18,    20,    21,    25,    31,
      64,    65,    66,    67,    68,    69,    70,    71,    73,     7,
      35,     7,     1,     9,    11,    12,    13,    14,    29,    49,
      54,    55,    56,    57,    58,    59,    60,    61,    50,    69,
      31,    69,    69,    69,    63,     8,    23,     3,    19,    22,
       4,    33,    69,    31,    69,    69,    69,    63,     8,    23,
       3,    19,    22,     4,    64,    64,    31,    31,    57,    31,
      31,    50,    35,    30,    72,    32,    65,    66,    68,    66,
      66,    69,    57,    72,    32,    65,    66,    68,    66,    66,
      69,    63,    57,    35,    17,    24,    57,    30,    32,    32,
      32,    35,    32,    32,    32,    53,    63,    35,    35,    35,
      35,    57,    32,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    41,    41,
      42,    42,    43,    44,    44,    45,    45,    46,    47,    47,
      47,    48,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    55,    56,
      57,    57,    58,    59,    59,    60,    61,    61,    62,    63,
      63,    63,    64,    64,    65,    65,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    70,    70,
      70,    70,    71,    72,    72,    72,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     3,
       3,     4,     5,     1,     0,     2,     3,     1,     1,     3,
       1,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     7,     9,     2,
       1,     1,     3,     1,     1,     5,     5,     5,     3,     3,
       1,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     1,     2,     2,     2,     2,     1,     3,
       1,     1,     4,     1,     3,     0,     1,     1,     1
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
		root = *createAstNode("initial", 0);	// non-printable
		(yyval.ast) = &root;
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2113 "src/syntax.tab.c"
    break;

  case 3: /* declaration_list: declaration_list decl  */
#line 128 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("declaration list", 1);	// printable
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2124 "src/syntax.tab.c"
    break;

  case 4: /* declaration_list: decl  */
#line 134 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("declaration list", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2134 "src/syntax.tab.c"
    break;

  case 5: /* decl: var_declaration  */
#line 142 "src/syntax.y"
                       {
		(yyval.ast) = createAstNode("decl", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2144 "src/syntax.tab.c"
    break;

  case 6: /* decl: func_definition  */
#line 147 "src/syntax.y"
                         {
		(yyval.ast) = createAstNode("decl", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2154 "src/syntax.tab.c"
    break;

  case 7: /* decl: error  */
#line 152 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", 0);
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2164 "src/syntax.tab.c"
    break;

  case 8: /* var_definition: SIMPLE_TYPE ID  */
#line 160 "src/syntax.y"
                      {
		char concat_type[200];
		int var_type = 1;
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, (yyvsp[-1].lexeme).lexeme_string, var_type, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, (yyvsp[-1].lexeme).scope);
		(yyval.ast) = createAstNode("var definition", 1);
		strcpy(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2180 "src/syntax.tab.c"
    break;

  case 9: /* var_definition: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 171 "src/syntax.y"
                                      {
		char concat_type[200];
		int var_type = 1;
		strcpy(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, concat_type, var_type, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, (yyvsp[-2].lexeme).scope);
		(yyval.ast) = createAstNode("var definition", 1);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2198 "src/syntax.tab.c"
    break;

  case 10: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 187 "src/syntax.y"
                          {
		char concat_type[200];
		int var_type = 1;
		insertSymbol(&symbolTable, (yyvsp[-1].lexeme).lexeme_string, (yyvsp[-2].lexeme).lexeme_string, var_type, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, (yyvsp[-2].lexeme).scope);
		(yyval.ast) = createAstNode("var declaration", 1);
		strcpy(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2214 "src/syntax.tab.c"
    break;

  case 11: /* var_declaration: SIMPLE_TYPE COMPOUND_TYPE ID ';'  */
#line 198 "src/syntax.y"
                                          {
		char concat_type[200];
		int var_type = 1;
		strcpy(concat_type, (yyvsp[-3].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		insertSymbol(&symbolTable, (yyvsp[-1].lexeme).lexeme_string, concat_type, var_type, (yyvsp[-3].lexeme).line, (yyvsp[-3].lexeme).column, (yyvsp[-3].lexeme).scope);
		(yyval.ast) = createAstNode("var declaration", 1);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2232 "src/syntax.tab.c"
    break;

  case 12: /* func_definition: func_declaration '(' params.opt ')' stmts  */
#line 214 "src/syntax.y"
                                                  {
		(yyval.ast) = createAstNode("function definition", 0);
		(yyval.ast)->children[0] = (yyvsp[-4].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2244 "src/syntax.tab.c"
    break;

  case 13: /* params.opt: params  */
#line 224 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("params optional", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2254 "src/syntax.tab.c"
    break;

  case 14: /* params.opt: %empty  */
#line 229 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("params optional empty", 0); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2263 "src/syntax.tab.c"
    break;

  case 15: /* func_declaration: SIMPLE_TYPE ID  */
#line 236 "src/syntax.y"
                      {
		char concat_type[200];
		int func_type = 0;
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, (yyvsp[-1].lexeme).lexeme_string, func_type, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, (yyvsp[-1].lexeme).scope);
		(yyval.ast) = createAstNode("function declaration", 1);
		strcpy(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2279 "src/syntax.tab.c"
    break;

  case 16: /* func_declaration: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 247 "src/syntax.y"
                                      {
		char concat_type[200];
		int func_type = 0;
		strcpy(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, concat_type, func_type, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, (yyvsp[-2].lexeme).scope);
		(yyval.ast) = createAstNode("function declaration", 1);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(concat_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2297 "src/syntax.tab.c"
    break;

  case 17: /* params: param_list  */
#line 263 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("params", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2307 "src/syntax.tab.c"
    break;

  case 18: /* param_list: param  */
#line 271 "src/syntax.y"
             {
		(yyval.ast) = createAstNode("param list", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2317 "src/syntax.tab.c"
    break;

  case 19: /* param_list: param_list ',' param  */
#line 276 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("param list", 0);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2328 "src/syntax.tab.c"
    break;

  case 20: /* param_list: error  */
#line 282 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", 0);
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2338 "src/syntax.tab.c"
    break;

  case 21: /* param: var_definition  */
#line 290 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("param", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2348 "src/syntax.tab.c"
    break;

  case 22: /* stmts: '{' stmt_list.opt '}'  */
#line 298 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("stmts", 1);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2358 "src/syntax.tab.c"
    break;

  case 23: /* stmt_list.opt: stmt_list  */
#line 306 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list optional", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2368 "src/syntax.tab.c"
    break;

  case 24: /* stmt_list.opt: %empty  */
#line 311 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list empty", 0); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2377 "src/syntax.tab.c"
    break;

  case 25: /* stmt_list: stmt_list stmt.item  */
#line 318 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("stmt list", 0);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2388 "src/syntax.tab.c"
    break;

  case 26: /* stmt_list: stmt.item  */
#line 324 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt list", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2398 "src/syntax.tab.c"
    break;

  case 27: /* stmt.item: stmt  */
#line 332 "src/syntax.y"
            {
		(yyval.ast) = createAstNode("stmt item", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2408 "src/syntax.tab.c"
    break;

  case 28: /* stmt.item: var_declaration  */
#line 337 "src/syntax.y"
                         {
		(yyval.ast) = createAstNode("stmt item", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2418 "src/syntax.tab.c"
    break;

  case 29: /* stmt: return_stmt  */
#line 345 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2428 "src/syntax.tab.c"
    break;

  case 30: /* stmt: select_stmt  */
#line 350 "src/syntax.y"
                     {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2438 "src/syntax.tab.c"
    break;

  case 31: /* stmt: iter_stmt  */
#line 355 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2448 "src/syntax.tab.c"
    break;

  case 32: /* stmt: io_stmt  */
#line 360 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2458 "src/syntax.tab.c"
    break;

  case 33: /* stmt: exp_stmt  */
#line 365 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2468 "src/syntax.tab.c"
    break;

  case 34: /* stmt: stmts  */
#line 370 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2478 "src/syntax.tab.c"
    break;

  case 35: /* stmt: error  */
#line 375 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", 0);
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2488 "src/syntax.tab.c"
    break;

  case 36: /* select_stmt: IF '(' simple_exp ')' stmt  */
#line 383 "src/syntax.y"
                                             {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2499 "src/syntax.tab.c"
    break;

  case 37: /* select_stmt: IF '(' simple_exp ')' stmt ELSE stmt  */
#line 389 "src/syntax.y"
                                              {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-4].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2511 "src/syntax.tab.c"
    break;

  case 38: /* iter_stmt: FOR '(' exp ';' simple_exp ';' exp ')' stmt  */
#line 399 "src/syntax.y"
                                                   {
		(yyval.ast) = createAstNode("iter stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-6].ast);
		(yyval.ast)->children[1] = (yyvsp[-4].ast);
		(yyval.ast)->children[2] = (yyvsp[-2].ast);
		(yyval.ast)->children[3] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2524 "src/syntax.tab.c"
    break;

  case 39: /* exp_stmt: exp ';'  */
#line 410 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("expression", 0);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2534 "src/syntax.tab.c"
    break;

  case 40: /* exp: assign_exp  */
#line 418 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("exp stmt", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2544 "src/syntax.tab.c"
    break;

  case 41: /* exp: simple_exp  */
#line 423 "src/syntax.y"
                    {
		(yyval.ast) = createAstNode("exp stmt", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2554 "src/syntax.tab.c"
    break;

  case 42: /* return_stmt: RETURN exp ';'  */
#line 431 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("return stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2564 "src/syntax.tab.c"
    break;

  case 43: /* io_stmt: in_stmt  */
#line 439 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("in/out stmt", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2574 "src/syntax.tab.c"
    break;

  case 44: /* io_stmt: out_stmt  */
#line 444 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("in/out stmt", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2584 "src/syntax.tab.c"
    break;

  case 45: /* in_stmt: INPUT '(' ID ')' ';'  */
#line 452 "src/syntax.y"
                            {
		char input_type[200];
		(yyval.ast) = createAstNode("input stmt", 1);
		strcpy(input_type, (yyvsp[-4].lexeme).lexeme_string);
		strcat(input_type, " (");
		strcat(input_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(input_type, ")");
		(yyval.ast)->token_name = strdup(input_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2599 "src/syntax.tab.c"
    break;

  case 46: /* out_stmt: OUTPUT '(' STRING ')' ';'  */
#line 465 "src/syntax.y"
                                 {
		char output_type[200];
		(yyval.ast) = createAstNode("output stmt", 1);
		strcpy(output_type, (yyvsp[-4].lexeme).lexeme_string);
		strcat(output_type, " (");
		strcat(output_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(output_type, ")");
		(yyval.ast)->token_name = strdup(output_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2614 "src/syntax.tab.c"
    break;

  case 47: /* out_stmt: OUTPUT '(' exp ')' ';'  */
#line 475 "src/syntax.y"
                                {
		(yyval.ast) = createAstNode("output stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2624 "src/syntax.tab.c"
    break;

  case 48: /* assign_exp: ID '=' exp  */
#line 483 "src/syntax.y"
                  {
		char assign_id[200];
		(yyval.ast) = createAstNode("assign exp", 1);
		strcpy(assign_id, (yyvsp[-2].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(assign_id);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2637 "src/syntax.tab.c"
    break;

  case 49: /* simple_exp: simple_exp LOGICAL_OR and_exp  */
#line 494 "src/syntax.y"
                                     {
		char operation[200];
		(yyval.ast) = createAstNode("simple exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2651 "src/syntax.tab.c"
    break;

  case 50: /* simple_exp: and_exp  */
#line 503 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("simple exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2661 "src/syntax.tab.c"
    break;

  case 51: /* simple_exp: error  */
#line 508 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", 0);
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2671 "src/syntax.tab.c"
    break;

  case 52: /* and_exp: and_exp LOGICAL_AND rel_exp  */
#line 516 "src/syntax.y"
                                   {
		char operation[200];
		(yyval.ast) = createAstNode("and exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2685 "src/syntax.tab.c"
    break;

  case 53: /* and_exp: rel_exp  */
#line 525 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("and exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2695 "src/syntax.tab.c"
    break;

  case 54: /* rel_exp: rel_exp RELATIONAL list_exp  */
#line 533 "src/syntax.y"
                                   {
		char operation[200];
		(yyval.ast) = createAstNode("rel exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2709 "src/syntax.tab.c"
    break;

  case 55: /* rel_exp: list_exp  */
#line 542 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("rel exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2719 "src/syntax.tab.c"
    break;

  case 56: /* list_exp: sum_exp LIST_CONSTR list_exp  */
#line 550 "src/syntax.y"
                                    {
		char operation[200];
		(yyval.ast) = createAstNode("list exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2733 "src/syntax.tab.c"
    break;

  case 57: /* list_exp: sum_exp LIST_FUNC list_exp  */
#line 559 "src/syntax.y"
                                    {
		char operation[200];
		(yyval.ast) = createAstNode("list exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2747 "src/syntax.tab.c"
    break;

  case 58: /* list_exp: sum_exp  */
#line 568 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("list exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2757 "src/syntax.tab.c"
    break;

  case 59: /* sum_exp: sum_exp ADD mul_exp  */
#line 576 "src/syntax.y"
                           {
		char operation[200];
		(yyval.ast) = createAstNode("sum exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2771 "src/syntax.tab.c"
    break;

  case 60: /* sum_exp: mul_exp  */
#line 585 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("sum exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2781 "src/syntax.tab.c"
    break;

  case 61: /* mul_exp: mul_exp MUL unary_exp  */
#line 593 "src/syntax.y"
                             {
		char operation[200];
		(yyval.ast) = createAstNode("mul exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2795 "src/syntax.tab.c"
    break;

  case 62: /* mul_exp: unary_exp  */
#line 602 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("mul exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2805 "src/syntax.tab.c"
    break;

  case 63: /* unary_exp: factor  */
#line 610 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("unary exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2815 "src/syntax.tab.c"
    break;

  case 64: /* unary_exp: LIST_OP unary_exp  */
#line 615 "src/syntax.y"
                           {
		char operation[200];
		(yyval.ast) = createAstNode("unary exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2828 "src/syntax.tab.c"
    break;

  case 65: /* unary_exp: LIST_DESTR unary_exp  */
#line 623 "src/syntax.y"
                              {
		char operation[200];
		(yyval.ast) = createAstNode("unary exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2841 "src/syntax.tab.c"
    break;

  case 66: /* unary_exp: OP_OVERLOAD unary_exp  */
#line 631 "src/syntax.y"
                               {
		char operation[200];
		(yyval.ast) = createAstNode("unary exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2854 "src/syntax.tab.c"
    break;

  case 67: /* unary_exp: ADD unary_exp  */
#line 639 "src/syntax.y"
                       {
		char signal_type[200];
		strcpy(signal_type, "signed unary exp");
		strcat(signal_type, " (");
		strcat(signal_type, RED);
		strcat(signal_type, (yyvsp[-1].lexeme).lexeme_string);
		strcat(signal_type, WHITE);
		strcat(signal_type, ")");
		(yyval.ast) = createAstNode(signal_type, 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2871 "src/syntax.tab.c"
    break;

  case 68: /* factor: ID  */
#line 654 "src/syntax.y"
          {
		char id_type[200];
		(yyval.ast) = createAstNode("factor exp", 1);
		strcpy(id_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(id_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2883 "src/syntax.tab.c"
    break;

  case 69: /* factor: '(' simple_exp ')'  */
#line 661 "src/syntax.y"
                            {
		(yyval.ast) = createAstNode("factor exp", 0);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2893 "src/syntax.tab.c"
    break;

  case 70: /* factor: func_call  */
#line 666 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("factor exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2903 "src/syntax.tab.c"
    break;

  case 71: /* factor: constant  */
#line 671 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("factor exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2913 "src/syntax.tab.c"
    break;

  case 72: /* func_call: ID '(' func_params ')'  */
#line 679 "src/syntax.y"
                              {
		char func_id[200];
		(yyval.ast) = createAstNode("func call", 1);
		strcpy(func_id, (yyvsp[-3].lexeme).lexeme_string);
		strcat(func_id, "()");
		(yyval.ast)->token_name = strdup(func_id);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2927 "src/syntax.tab.c"
    break;

  case 73: /* func_params: simple_exp  */
#line 691 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("func params", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2937 "src/syntax.tab.c"
    break;

  case 74: /* func_params: func_params ',' simple_exp  */
#line 696 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("func params", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2948 "src/syntax.tab.c"
    break;

  case 75: /* func_params: %empty  */
#line 702 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("func params empty", 0); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2957 "src/syntax.tab.c"
    break;

  case 76: /* constant: INTEGER  */
#line 709 "src/syntax.y"
               {
		char int_type[200];
		(yyval.ast) = createAstNode("int constant", 1);
		strcpy(int_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(int_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2969 "src/syntax.tab.c"
    break;

  case 77: /* constant: REAL  */
#line 716 "src/syntax.y"
              {
		char real_type[200];
		(yyval.ast) = createAstNode("real constant", 1);
		strcpy(real_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(real_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2981 "src/syntax.tab.c"
    break;

  case 78: /* constant: NIL_CONSTANT  */
#line 723 "src/syntax.y"
                      {
		char nil_type[200];
		(yyval.ast) = createAstNode("nil constant", 1);
		strcpy(nil_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(nil_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2993 "src/syntax.tab.c"
    break;


#line 2997 "src/syntax.tab.c"

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

#line 732 "src/syntax.y"


void yyerror(const char *error_msg){
	int column = num_chars - yylval.lexeme.length;
	printf("%sLine:%d\tColumn:%d\t%s%s\n", RED, num_lines, column, error_msg, WHITE);
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
		printf("%sSyntax analysis finished with %d errors.%s\n", RED, count_errors, WHITE);
	}
	return 0;
}

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
#define YYLAST   2704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

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
     285,   293,   301,   306,   313,   319,   327,   332,   340,   345,
     350,   355,   360,   365,   373,   379,   389,   400,   408,   413,
     421,   429,   434,   442,   455,   465,   473,   481,   490,   498,
     507,   515,   524,   532,   541,   550,   558,   567,   575,   584,
     592,   597,   605,   613,   621,   636,   643,   648,   653,   661,
     669,   674,   680,   687,   694,   701
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

#define YYPACT_NINF (-162)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,   251,    90,    74,   369,   457,   467,   493,   -14,     6,
      -3,  -162,   518,   126,   165,   660,    98,   186,    55,    62,
     225,   239,   672,    75,   256,    71,   120,   259,  1875,   677,
     278,  2613,   117,   297,   123,   188,  2622,   209,   231,   192,
      53,   333,  2613,  2613,  2613,  2643,  1904,  1933,   112,  1962,
    1991,  2020,  2049,  2078,  2107,   169,  2136,  2165,  2194,  2223,
     193,    23,     2,    -4,    70,    94,   431,   509,   531,   597,
     742,    60,   771,  2643,  2622,   235,   144,   354,   258,   244,
     912,  2622,   779,   801,   823,    22,   684,  2252,  2281,  2613,
    2613,  2613,  2613,  2613,  2613,  2613,    96,   257,  2310,   271,
     282,   293,   296,    37,   279,   299,   853,    27,    73,   130,
     870,   191,   204,   876,  2571,  2613,   304,   318,   319,   905,
    2652,  1382,    31,  2339,  2368,  2397,   181,  2592,  2673,  2426,
     313,  2592,  2455,  1875,  2643,    17,  1180,  1154,  1186,  2643,
    2643,  2643,  2643,   111,   315,   604,  1358,  1188,  1218,  1220,
    1226,  1252,  1148,   335,   173,  2484,  2652,   557,   931,   246,
     948,  2652,  2652,  2652,  2643,   199,   240,   301,  1131,   954,
     971,   988,   994,  1011,  2643,  2513,  2652,   342,   345,  2622,
     346,   352,  1875,  1411,  1440,  1469,  1498,   358,  1527,  1556,
    1585,  1614,   365,  1258,   912,  1260,  1290,  1292,   210,  2643,
    2643,  2643,  2643,  2643,  2643,  2673,  1028,   912,  1034,  1051,
    1068,   223,  2652,  2652,  2652,  2652,  2652,  2652,   115,   310,
    2643,  2622,   363,   391,   412,   376,  1643,  2542,   332,  1298,
     610,   673,  1324,   821,   913,  1330,   377,   348,  1074,   389,
     514,  1091,   622,   720,  1108,   229,   375,  1672,   382,   384,
     388,  1701,  1332,  1114,  2571,  2613,   387,   396,   405,  1730,
      35,  1759,  1788,  1817,  2673,   410,  2571,  1846
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
       0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,   440,  -162,   197,  -162,  -162,  -162,  -162,
    -162,   419,   -25,  -127,  -162,   403,  -109,  -106,  -103,   -98,
     -29,   -88,   -87,   -73,   -63,   -75,   661,   643,   548,   383,
     495,   450,   -30,    82,   187,  -161,   285
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    17,    46,     7,    18,     8,    19,
      20,    21,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,   104,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    72,   153,   -50,   -50,   121,   192,    75,   184,   -48,
      90,   185,    82,    83,    84,   148,   186,    13,   129,    91,
     -73,   -73,   132,    14,   -73,   -73,   188,   189,   -15,   174,
      89,   -50,    15,   228,   -47,    90,   -73,   -48,    89,   -73,
     -73,   190,    89,   148,   176,    97,   237,   148,   101,   -73,
     170,   191,   105,   153,   106,   225,   -65,   -65,   -39,     1,
     -65,   -65,   -47,   -65,   -65,   113,   128,   -65,   -65,   -70,
     264,   -70,   -65,     2,    11,   -65,   -65,   -52,   -52,   -65,
     -49,   -49,   -65,   -65,    80,   187,    81,    25,   -65,   183,
     170,    80,    27,   -52,   -13,   -65,    91,    92,   148,   130,
      28,   -55,   -55,   174,   193,   -52,     9,    10,   -49,   195,
     196,   197,   148,    93,    23,    24,    94,   -55,   -48,   199,
     -73,   -73,   -47,   199,   -73,   -73,   206,   149,   114,   -55,
     153,   208,   209,   210,   148,    16,   -73,   -51,   -51,   -73,
     -73,    16,    86,   -48,   148,   259,   170,   -47,   184,   153,
     222,   185,   -73,   -51,    73,   149,   186,   267,   -14,   149,
     184,    99,   171,   185,   170,   -51,   188,   189,   186,   148,
     148,   148,   148,   148,   235,   148,   236,   170,   188,   189,
     174,   190,   170,   170,   170,   170,   170,   244,   176,   153,
     148,   191,   246,   190,   148,   250,   -16,     6,   -53,   -53,
      22,     6,   171,   191,    88,   -39,   -48,   212,    78,    79,
     149,   -54,   -54,   -71,   -53,   -71,   149,   174,   -20,    74,
     -20,   149,   149,   149,   149,   187,   -53,   -54,   -38,   183,
     174,   -48,   150,   -48,   148,   265,   174,   187,   171,   -54,
      76,   183,   229,   171,   171,   171,   149,   -50,   -50,   -65,
     -65,    -7,    -7,   -65,   -65,   238,   149,   -17,   171,    26,
     150,   254,    77,   213,   150,   -65,    -7,   172,   -65,   -65,
      98,   -18,   -50,   -18,   -50,   102,   171,   207,   -65,   155,
     -65,   149,   149,   149,   149,   149,   149,   149,    -8,   171,
      -8,    -9,   115,    -9,   171,   171,   171,   171,   171,   171,
     -74,   -74,   149,   116,   -74,   -74,   149,   172,   -52,   -52,
     -19,   119,   -19,   120,   117,   150,   -74,   -47,   212,   -74,
     -74,   150,   -50,   -50,   -52,   118,   150,   150,   150,   150,
     151,   175,   -74,   -52,   -46,   -52,   -75,   -75,   200,   123,
     -75,   -75,   -47,   172,   -47,   131,   149,   -50,   172,   172,
     172,   150,   -75,   124,   125,   -75,   -75,   134,   151,   135,
     136,   150,   151,   172,   252,   173,   120,   -38,   -75,    -2,
       1,   152,   138,   220,   139,   140,   221,   223,   100,   141,
     253,   172,   120,   224,     2,   142,   150,   150,   150,   150,
     150,   150,   150,   226,   172,   227,   -49,   -49,   247,   172,
     172,   172,   172,   172,   172,   173,   251,   150,   248,   -46,
     255,   150,   213,   151,   256,   134,   257,   135,   136,   151,
     258,   -49,   261,   -49,   151,   151,   151,   151,   145,   152,
     138,   262,   139,   140,   -57,    95,   249,   141,   -57,   -57,
     263,   173,   266,   142,    12,    30,   173,   173,   173,   151,
     -57,   150,    87,   -57,   -57,     0,   145,    -4,    -4,   151,
     145,   173,     0,   167,     0,     0,   -57,    -5,    -5,     0,
       0,     0,    -4,     0,   109,     0,   111,   112,     0,   173,
       0,     0,    -5,     0,   151,   151,   151,   151,   151,   151,
     151,     0,   173,    -6,    -6,   147,     0,   173,   173,   173,
     173,   173,   173,   167,     0,   151,     0,     0,    -6,   151,
       0,   145,   -59,   -59,     0,     0,   -59,   -59,    -3,    -3,
       0,   -51,   -51,   147,     0,   145,     0,   147,   -59,     0,
     169,   -59,   -59,    -3,   -60,   -60,     0,   -51,   -60,   -60,
     146,     0,   110,     0,   -59,     0,   -51,   145,   -51,   151,
     -60,     0,     0,   -60,   -60,     0,     0,   145,     0,   167,
     -73,   -73,     0,     0,   -73,   -73,   -60,     0,   146,     0,
     169,     0,   146,     0,     0,   168,   -73,   167,   147,   -73,
     -73,     0,   145,   231,     0,   233,   234,     0,   145,   -73,
     167,   -73,   147,   144,     0,   167,   240,     0,   242,   243,
     -67,   -67,     0,   145,   -67,   -67,     0,   145,     0,     0,
       0,   -52,   -52,     0,   147,   168,   -67,   -49,   -49,   -67,
     -67,   144,     0,   146,   147,   144,   169,   -52,   166,   -53,
     -53,     0,   -67,   200,     0,     0,   -52,   146,   108,     0,
       0,     0,   -49,     0,   169,   -53,     0,   145,     0,   147,
     147,   232,   147,   147,   -53,   147,   -53,   169,     0,   146,
     -10,   -10,   169,   169,   241,   169,   169,     0,   166,   146,
     147,   168,   -11,   -11,   147,   -10,   144,   -12,   -12,     0,
     -51,   -51,     0,     0,   -21,   -21,     0,   -11,   143,   168,
     144,     0,   -12,     0,   146,   146,   -51,   146,   146,   -21,
     146,     0,   168,     0,     0,   -51,    85,   168,   168,     0,
     168,   168,   144,     0,   147,   146,   143,     0,     0,   146,
     143,     0,   144,   165,   166,     0,     0,   -54,   -54,     0,
       0,     0,   107,     0,    96,     0,     0,     0,   154,     0,
       0,   103,   166,   -54,     0,   -68,   -68,   230,     0,   -68,
     -68,     0,   -54,   144,   -54,   166,     0,     0,     0,   146,
     239,   -68,     0,   165,   -68,   -68,     0,     0,   144,     0,
       0,   143,   144,     0,   -64,   -64,   122,   -68,   -64,   -64,
       0,   126,   -61,   -61,     0,   143,   -61,   -61,     0,   154,
     -64,     0,     0,   -64,   -64,     0,     0,     0,   -61,     0,
       0,   -61,   -61,   198,   -62,   -62,   -64,   143,   -62,   -62,
       0,     0,   144,     0,   -61,     0,     0,   218,     0,   219,
     -62,     0,     0,   -62,   -62,   211,   -63,   -63,   -53,   -53,
     -63,   -63,     0,     0,     0,     0,   -62,   165,     0,     0,
       0,     0,   -63,     0,   -53,   -63,   -63,     0,   143,     0,
     165,     0,     0,   -53,     0,   103,   -66,   -66,   -63,     0,
     -66,   -66,     0,   143,     0,     0,   154,   143,   103,     0,
       0,     0,   -66,   -56,    95,   -66,   -66,   -56,   -56,   -58,
     -58,   245,     0,   -58,   -58,   154,     0,     0,   -66,   -56,
       0,     0,   -56,   -56,     0,   -58,     0,     0,   -58,   -58,
       0,     0,     0,     0,     0,   -56,     0,   143,   -69,   -69,
       0,   -58,   -69,   -69,     0,   156,   260,   157,   158,     0,
     -54,   -54,     0,     0,   -69,   154,     0,   -69,   -69,   159,
     160,     0,   161,   162,   -74,   -74,   -54,   163,   -74,   -74,
     -69,     0,     0,   164,   -72,   -54,   -72,     0,     0,     0,
     -74,   -75,   -75,   -74,   -74,   -75,   -75,   -57,   217,     0,
       0,   -57,   -57,   -74,     0,   -74,     0,   -75,     0,     0,
     -75,   -75,     0,   -57,   -59,   -59,   -57,   -57,   -59,   -59,
     -75,     0,   -75,     0,     0,     0,   -57,     0,   -57,     0,
     -59,   -60,   -60,   -59,   -59,   -60,   -60,   -67,   -67,     0,
       0,   -67,   -67,   -59,     0,   -59,     0,   -60,     0,     0,
     -60,   -60,     0,   -67,   -68,   -68,   -67,   -67,   -68,   -68,
     -60,     0,   -60,     0,     0,     0,   -67,     0,   -67,     0,
     -68,   -64,   -64,   -68,   -68,   -64,   -64,   -61,   -61,     0,
       0,   -61,   -61,   -68,     0,   -68,     0,   -64,     0,     0,
     -64,   -64,     0,   -61,   -62,   -62,   -61,   -61,   -62,   -62,
     -64,     0,   -64,     0,     0,     0,   -61,     0,   -61,     0,
     -62,   -63,   -63,   -62,   -62,   -63,   -63,   -66,   -66,     0,
       0,   -66,   -66,   -62,     0,   -62,     0,   -63,     0,     0,
     -63,   -63,     0,   -66,   -56,   217,   -66,   -66,   -56,   -56,
     -63,     0,   -63,     0,     0,     0,   -66,     0,   -66,     0,
     -56,   -58,   -58,   -56,   -56,   -58,   -58,   -69,   -69,     0,
       0,   -69,   -69,   -56,     0,   -56,     0,   -58,     0,     0,
     -58,   -58,     0,   -69,   214,     0,   -69,   -69,   -55,   -55,
     -58,     0,   -58,     0,     0,     0,   -69,     0,   -69,     0,
     215,   -65,   -65,   216,   -55,   -65,   -65,   -65,   -65,     0,
       0,   -65,   -65,   -55,     0,   -55,     0,   -65,     0,     0,
     -65,   -65,     0,   -65,     0,     0,   -65,   -65,     0,   194,
     -65,   205,     0,   -74,   -74,   194,   -65,   -74,   -74,   -75,
     -75,   -57,   204,   -75,   -75,   -57,   -57,     0,     0,   -74,
       0,     0,   -74,   -74,     0,   -75,     0,   -57,   -75,   -75,
     -57,   -57,   -74,     0,     0,     0,     0,     0,   -75,     0,
     -57,   -59,   -59,   -60,   -60,   -59,   -59,   -60,   -60,   -67,
     -67,     0,     0,   -67,   -67,     0,     0,   -59,     0,   -60,
     -59,   -59,   -60,   -60,     0,   -67,     0,     0,   -67,   -67,
     -59,     0,   -60,     0,     0,   -68,   -68,     0,   -67,   -68,
     -68,   -64,   -64,   -61,   -61,   -64,   -64,   -61,   -61,     0,
       0,   -68,     0,     0,   -68,   -68,     0,   -64,     0,   -61,
     -64,   -64,   -61,   -61,   -68,     0,     0,     0,     0,     0,
     -64,     0,   -61,   -62,   -62,   -63,   -63,   -62,   -62,   -63,
     -63,   -66,   -66,     0,     0,   -66,   -66,     0,     0,   -62,
       0,   -63,   -62,   -62,   -63,   -63,     0,   -66,     0,     0,
     -66,   -66,   -62,     0,   -63,     0,     0,   -56,   204,     0,
     -66,   -56,   -56,   -58,   -58,   -69,   -69,   -58,   -58,   -69,
     -69,     0,     0,   -56,     0,     0,   -56,   -56,     0,   -58,
       0,   -69,   -58,   -58,   -69,   -69,   -56,     0,     0,     0,
       0,   201,   -58,     0,   -69,   -55,   -55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,     0,
     203,   -55,     0,     0,     0,   -34,     0,   -34,   -34,     0,
     -55,   -34,   127,   -34,   -34,   -34,   -34,   -34,     0,   -34,
     -34,     0,   -34,   -34,     0,     0,     0,   -34,     0,     0,
       0,   -34,   -34,   -34,   -33,     0,   -33,   -33,     0,     0,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,
       0,   -33,   -33,     0,     0,     0,   -33,     0,     0,     0,
     -33,   -33,   -33,   -29,     0,   -29,   -29,     0,     0,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,     0,
     -29,   -29,     0,     0,     0,   -29,     0,     0,     0,   -29,
     -29,   -29,   -30,     0,   -30,   -30,     0,     0,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,     0,   -30,   -30,     0,   -30,
     -30,     0,     0,     0,   -30,     0,     0,     0,   -30,   -30,
     -30,   -32,     0,   -32,   -32,     0,     0,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,
       0,     0,     0,   -32,     0,     0,     0,   -32,   -32,   -32,
     -28,     0,   -28,   -28,     0,     0,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,     0,   -28,   -28,     0,   -28,   -28,     0,
       0,     0,   -28,     0,     0,     0,   -28,   -28,   -28,   -31,
       0,   -31,   -31,     0,     0,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,     0,   -31,   -31,     0,   -31,   -31,     0,     0,
       0,   -31,     0,     0,     0,   -31,   -31,   -31,   -41,     0,
     -41,   -41,     0,     0,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,     0,   -41,   -41,     0,   -41,   -41,     0,     0,     0,
     -41,     0,     0,     0,   -41,   -41,   -41,   -42,     0,   -42,
     -42,     0,     0,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
       0,   -42,   -42,     0,   -42,   -42,     0,     0,     0,   -42,
       0,     0,     0,   -42,   -42,   -42,   -37,     0,   -37,   -37,
       0,     0,   -37,   -37,   -37,   -37,   -37,   -37,   -37,     0,
     -37,   -37,     0,   -37,   -37,     0,     0,     0,   -37,     0,
       0,     0,   -37,   -37,   -37,   -40,     0,   -40,   -40,     0,
       0,   -40,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,
     -40,     0,   -40,   -40,     0,     0,     0,   -40,     0,     0,
       0,   -40,   -40,   -40,   -21,     0,   -21,   -21,     0,     0,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,
       0,   -21,   -21,     0,     0,     0,   -21,     0,     0,     0,
     -21,   -21,   -21,   -34,     0,   -34,   -34,     0,     0,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,   -34,     0,
     -34,   -34,     0,     0,     0,   -34,     0,     0,     0,   -34,
     -34,   -34,   -43,     0,   -43,   -43,     0,     0,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,
     -43,     0,     0,     0,   -43,     0,     0,     0,   -43,   -43,
     -43,   -44,     0,   -44,   -44,     0,     0,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,
       0,     0,     0,   -44,     0,     0,     0,   -44,   -44,   -44,
     -45,     0,   -45,   -45,     0,     0,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,     0,   -45,   -45,     0,   -45,   -45,     0,
       0,     0,   -45,     0,     0,     0,   -45,   -45,   -45,   -36,
       0,   -36,   -36,     0,     0,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,   -36,     0,   -36,   -36,     0,     0,
       0,   -36,     0,     0,     0,   -36,   -36,   -36,    31,     0,
      32,    33,     0,     0,    34,     0,    35,    36,    37,    38,
      39,     0,    40,    41,     0,    42,    43,     0,     0,     0,
      44,     0,     0,     0,   133,   -23,    45,   -27,     0,   -27,
     -27,     0,     0,   -27,     0,   -27,   -27,   -27,   -27,   -27,
       0,   -27,   -27,     0,   -27,   -27,     0,     0,     0,   -27,
       0,     0,     0,   -27,   -27,   -27,   -33,     0,   -33,   -33,
       0,     0,   -33,     0,   -33,   -33,   -33,   -33,   -33,     0,
     -33,   -33,     0,   -33,   -33,     0,     0,     0,   -33,     0,
       0,     0,   -33,   -33,   -33,    31,     0,    32,    33,     0,
       0,    34,     0,    35,    36,    37,    38,    39,     0,    40,
      41,     0,    42,    43,     0,     0,     0,    44,     0,     0,
       0,   133,   -22,    45,   -25,     0,   -25,   -25,     0,     0,
     -25,     0,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,
       0,   -25,   -25,     0,     0,     0,   -25,     0,     0,     0,
     -25,   -25,   -25,   -26,     0,   -26,   -26,     0,     0,   -26,
       0,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,     0,
     -26,   -26,     0,     0,     0,   -26,     0,     0,     0,   -26,
     -26,   -26,   -29,     0,   -29,   -29,     0,     0,   -29,     0,
     -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,     0,   -29,
     -29,     0,     0,     0,   -29,     0,     0,     0,   -29,   -29,
     -29,   -30,     0,   -30,   -30,     0,     0,   -30,     0,   -30,
     -30,   -30,   -30,   -30,     0,   -30,   -30,     0,   -30,   -30,
       0,     0,     0,   -30,     0,     0,     0,   -30,   -30,   -30,
     -32,     0,   -32,   -32,     0,     0,   -32,     0,   -32,   -32,
     -32,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,     0,
       0,     0,   -32,     0,     0,     0,   -32,   -32,   -32,   -28,
       0,   -28,   -28,     0,     0,   -28,     0,   -28,   -28,   -28,
     -28,   -28,     0,   -28,   -28,     0,   -28,   -28,     0,     0,
       0,   -28,     0,     0,     0,   -28,   -28,   -28,   -31,     0,
     -31,   -31,     0,     0,   -31,     0,   -31,   -31,   -31,   -31,
     -31,     0,   -31,   -31,     0,   -31,   -31,     0,     0,     0,
     -31,     0,     0,     0,   -31,   -31,   -31,   -41,     0,   -41,
     -41,     0,     0,   -41,     0,   -41,   -41,   -41,   -41,   -41,
       0,   -41,   -41,     0,   -41,   -41,     0,     0,     0,   -41,
       0,     0,     0,   -41,   -41,   -41,   -42,     0,   -42,   -42,
       0,     0,   -42,     0,   -42,   -42,   -42,   -42,   -42,     0,
     -42,   -42,     0,   -42,   -42,     0,     0,     0,   -42,     0,
       0,     0,   -42,   -42,   -42,   -24,     0,   -24,   -24,     0,
       0,   -24,     0,   -24,   -24,   -24,   -24,   -24,     0,   -24,
     -24,     0,   -24,   -24,     0,     0,     0,   -24,     0,     0,
       0,   -24,   -24,   -24,   -37,     0,   -37,   -37,     0,     0,
     -37,     0,   -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,
       0,   -37,   -37,     0,     0,     0,   -37,     0,     0,     0,
     -37,   -37,   -37,   -40,     0,   -40,   -40,     0,     0,   -40,
       0,   -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,     0,
     -40,   -40,     0,     0,     0,   -40,     0,     0,     0,   -40,
     -40,   -40,   -43,     0,   -43,   -43,     0,     0,   -43,     0,
     -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,
     -43,     0,     0,     0,   -43,     0,     0,     0,   -43,   -43,
     -43,   -44,     0,   -44,   -44,     0,     0,   -44,     0,   -44,
     -44,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,
       0,     0,     0,   -44,     0,     0,     0,   -44,   -44,   -44,
     -45,     0,   -45,   -45,     0,     0,   -45,     0,   -45,   -45,
     -45,   -45,   -45,     0,   -45,   -45,     0,   -45,   -45,     0,
       0,     0,   -45,     0,     0,     0,   -45,   -45,   -45,   -35,
       0,   -35,   -35,     0,     0,   -35,     0,   -35,   -35,   -35,
     -35,   -35,     0,   -35,   -35,     0,   -35,   -35,     0,     0,
       0,   -35,     0,     0,     0,   -35,   -35,   -35,   -36,     0,
     -36,   -36,     0,     0,   -36,     0,   -36,   -36,   -36,   -36,
     -36,     0,   -36,   -36,     0,   -36,   -36,     0,     0,     0,
     -36,     0,     0,     0,   -36,   -36,   -36,   -10,     0,   -10,
     -10,     0,     0,   -10,     0,   -10,   -10,   -10,   -10,   -10,
       0,   -10,   -10,     0,   -10,   -10,     0,     0,     0,   -10,
       0,     0,     0,   -10,   -10,   -10,   -11,     0,   -11,   -11,
       0,     0,   -11,     0,   -11,   -11,   -11,   -11,   -11,     0,
     -11,   -11,     0,   -11,   -11,     0,     0,     0,   -11,     0,
       0,     0,   -11,   -11,   -11,   -21,     0,   -21,   -21,     0,
       0,   -21,     0,   -21,   -21,   -21,   -21,   -21,     0,   -21,
     -21,     0,   -21,   -21,     0,     0,     0,   -21,     0,     0,
       0,   -21,   -21,   -21,    31,     0,    32,    33,     0,     0,
     177,     0,   178,   179,   180,   181,     0,     0,    40,    41,
       0,    42,    43,     0,     0,    31,    44,    32,    33,     0,
     182,    34,    45,    35,    36,    37,    38,     0,     0,    40,
      41,     0,    42,    43,     0,     0,    31,    44,    32,    33,
       0,   133,     0,    45,     0,    31,     0,    32,    33,     0,
      71,    41,     0,    42,    43,     0,     0,     0,    44,    40,
      41,     0,    42,    43,    45,     0,   134,    44,   135,   136,
       0,     0,     0,    45,     0,   156,     0,   157,   158,     0,
     137,   138,     0,   139,   140,     0,     0,     0,   141,   159,
     160,     0,   161,   162,   142,     0,   134,   163,   135,   136,
       0,     0,     0,   164,     0,     0,     0,     0,     0,     0,
     152,   138,     0,   139,   140,     0,     0,     0,   141,     0,
       0,     0,     0,     0,   142
};

static const yytype_int16 yycheck[] =
{
      25,    31,    77,     7,     8,   114,   133,    36,   114,     7,
       8,   114,    42,    43,    44,    45,   114,    31,   127,    23,
       3,     4,   131,    17,     7,     8,   114,   114,    31,     7,
       7,    35,    35,   194,     7,     8,    19,    35,     7,    22,
      23,   114,     7,    73,     7,    74,   207,    77,    77,    32,
      80,   114,    81,   128,    32,   182,     3,     4,    35,     1,
       7,     8,    35,     3,     4,    95,    35,     7,     8,    32,
      35,    34,    19,    15,     0,    22,    23,     7,     8,    19,
       7,     8,    22,    23,    31,   114,    33,    32,    35,   114,
     120,    31,    17,    23,    32,    35,    23,     3,   128,   128,
      29,     7,     8,     7,   134,    35,    16,    17,    35,   139,
     140,   141,   142,    19,    16,    17,    22,    23,     7,     8,
       3,     4,     7,     8,     7,     8,   156,    45,    32,    35,
     205,   161,   162,   163,   164,    15,    19,     7,     8,    22,
      23,    15,    30,    32,   174,   254,   176,    32,   254,   224,
     179,   254,    35,    23,    31,    73,   254,   266,    32,    77,
     266,    17,    80,   266,   194,    35,   254,   254,   266,   199,
     200,   201,   202,   203,   204,   205,   205,   207,   266,   266,
       7,   254,   212,   213,   214,   215,   216,   217,     7,   264,
     220,   254,   221,   266,   224,   224,    31,     0,     7,     8,
      35,     4,   120,   266,    35,    32,     7,     8,    16,    17,
     128,     7,     8,    32,    23,    34,   134,     7,    32,    31,
      34,   139,   140,   141,   142,   254,    35,    23,    35,   254,
       7,    32,    45,    34,   264,   264,     7,   266,   156,    35,
      31,   266,    32,   161,   162,   163,   164,     7,     8,     3,
       4,     0,     1,     7,     8,    32,   174,    32,   176,    34,
      73,    32,    31,    23,    77,    19,    15,    80,    22,    23,
      35,    32,    32,    34,    34,    17,   194,    31,    32,    35,
      34,   199,   200,   201,   202,   203,   204,   205,    32,   207,
      34,    32,    35,    34,   212,   213,   214,   215,   216,   217,
       3,     4,   220,    32,     7,     8,   224,   120,     7,     8,
      32,    32,    34,    34,    32,   128,    19,     7,     8,    22,
      23,   134,     7,     8,    23,    32,   139,   140,   141,   142,
      45,    35,    35,    32,    35,    34,     3,     4,    23,    35,
       7,     8,    32,   156,    34,    32,   264,    32,   161,   162,
     163,   164,    19,    35,    35,    22,    23,     3,    73,     5,
       6,   174,    77,   176,    32,    80,    34,    32,    35,     0,
       1,    17,    18,    31,    20,    21,    31,    31,    24,    25,
      32,   194,    34,    31,    15,    31,   199,   200,   201,   202,
     203,   204,   205,    35,   207,    30,     7,     8,    35,   212,
     213,   214,   215,   216,   217,   120,    30,   220,    17,    32,
      35,   224,    23,   128,    32,     3,    32,     5,     6,   134,
      32,    32,    35,    34,   139,   140,   141,   142,    45,    17,
      18,    35,    20,    21,     3,     4,    24,    25,     7,     8,
      35,   156,    32,    31,     4,    26,   161,   162,   163,   164,
      19,   264,    49,    22,    23,    -1,    73,     0,     1,   174,
      77,   176,    -1,    80,    -1,    -1,    35,     0,     1,    -1,
      -1,    -1,    15,    -1,    91,    -1,    93,    94,    -1,   194,
      -1,    -1,    15,    -1,   199,   200,   201,   202,   203,   204,
     205,    -1,   207,     0,     1,    45,    -1,   212,   213,   214,
     215,   216,   217,   120,    -1,   220,    -1,    -1,    15,   224,
      -1,   128,     3,     4,    -1,    -1,     7,     8,     0,     1,
      -1,     7,     8,    73,    -1,   142,    -1,    77,    19,    -1,
      80,    22,    23,    15,     3,     4,    -1,    23,     7,     8,
      45,    -1,    92,    -1,    35,    -1,    32,   164,    34,   264,
      19,    -1,    -1,    22,    23,    -1,    -1,   174,    -1,   176,
       3,     4,    -1,    -1,     7,     8,    35,    -1,    73,    -1,
     120,    -1,    77,    -1,    -1,    80,    19,   194,   128,    22,
      23,    -1,   199,   200,    -1,   202,   203,    -1,   205,    32,
     207,    34,   142,    45,    -1,   212,   213,    -1,   215,   216,
       3,     4,    -1,   220,     7,     8,    -1,   224,    -1,    -1,
      -1,     7,     8,    -1,   164,   120,    19,     7,     8,    22,
      23,    73,    -1,   128,   174,    77,   176,    23,    80,     7,
       8,    -1,    35,    23,    -1,    -1,    32,   142,    90,    -1,
      -1,    -1,    32,    -1,   194,    23,    -1,   264,    -1,   199,
     200,   201,   202,   203,    32,   205,    34,   207,    -1,   164,
       0,     1,   212,   213,   214,   215,   216,    -1,   120,   174,
     220,   176,     0,     1,   224,    15,   128,     0,     1,    -1,
       7,     8,    -1,    -1,     0,     1,    -1,    15,    45,   194,
     142,    -1,    15,    -1,   199,   200,    23,   202,   203,    15,
     205,    -1,   207,    -1,    -1,    32,    45,   212,   213,    -1,
     215,   216,   164,    -1,   264,   220,    73,    -1,    -1,   224,
      77,    -1,   174,    80,   176,    -1,    -1,     7,     8,    -1,
      -1,    -1,    89,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,   194,    23,    -1,     3,     4,   199,    -1,     7,
       8,    -1,    32,   205,    34,   207,    -1,    -1,    -1,   264,
     212,    19,    -1,   120,    22,    23,    -1,    -1,   220,    -1,
      -1,   128,   224,    -1,     3,     4,   115,    35,     7,     8,
      -1,   120,     3,     4,    -1,   142,     7,     8,    -1,   128,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    19,    -1,
      -1,    22,    23,   142,     3,     4,    35,   164,     7,     8,
      -1,    -1,   264,    -1,    35,    -1,    -1,   174,    -1,   176,
      19,    -1,    -1,    22,    23,   164,     3,     4,     7,     8,
       7,     8,    -1,    -1,    -1,    -1,    35,   194,    -1,    -1,
      -1,    -1,    19,    -1,    23,    22,    23,    -1,   205,    -1,
     207,    -1,    -1,    32,    -1,   194,     3,     4,    35,    -1,
       7,     8,    -1,   220,    -1,    -1,   205,   224,   207,    -1,
      -1,    -1,    19,     3,     4,    22,    23,     7,     8,     3,
       4,   220,    -1,     7,     8,   224,    -1,    -1,    35,    19,
      -1,    -1,    22,    23,    -1,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    35,    -1,   264,     3,     4,
      -1,    35,     7,     8,    -1,     3,   255,     5,     6,    -1,
       7,     8,    -1,    -1,    19,   264,    -1,    22,    23,    17,
      18,    -1,    20,    21,     3,     4,    23,    25,     7,     8,
      35,    -1,    -1,    31,    32,    32,    34,    -1,    -1,    -1,
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
       0,     1,    15,    38,    39,    40,    42,    43,    45,    16,
      17,     0,    40,    31,    17,    35,    15,    41,    44,    46,
      47,    48,    35,    16,    17,    32,    34,    17,    29,    49,
      48,     3,     5,     6,     9,    11,    12,    13,    14,    15,
      17,    18,    20,    21,    25,    31,    42,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      73,    17,    69,    31,    31,    57,    31,    31,    16,    17,
      31,    33,    69,    69,    69,    63,    30,    52,    35,     7,
       8,    23,     3,    19,    22,     4,    63,    57,    35,    17,
      24,    57,    17,    63,    72,    57,    32,    64,    65,    66,
      68,    66,    66,    69,    32,    35,    32,    32,    32,    32,
      34,    53,    63,    35,    35,    35,    63,    10,    35,    53,
      57,    32,    53,    29,     3,     5,     6,    17,    18,    20,
      21,    25,    31,    64,    65,    66,    67,    68,    69,    70,
      71,    73,    17,    62,    63,    35,     3,     5,     6,    17,
      18,    20,    21,    25,    31,    64,    65,    66,    67,    68,
      69,    70,    71,    73,     7,    35,     7,     9,    11,    12,
      13,    14,    29,    49,    54,    55,    56,    57,    58,    59,
      60,    61,    50,    69,    31,    69,    69,    69,    63,     8,
      23,     3,    19,    22,     4,    33,    69,    31,    69,    69,
      69,    63,     8,    23,     3,    19,    22,     4,    64,    64,
      31,    31,    57,    31,    31,    50,    35,    30,    72,    32,
      65,    66,    68,    66,    66,    69,    57,    72,    32,    65,
      66,    68,    66,    66,    69,    63,    57,    35,    17,    24,
      57,    30,    32,    32,    32,    35,    32,    32,    32,    53,
      63,    35,    35,    35,    35,    57,    32,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    41,    41,
      42,    42,    43,    44,    44,    45,    45,    46,    47,    47,
      48,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    56,    57,    57,
      58,    59,    59,    60,    61,    61,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    71,
      72,    72,    72,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     3,
       3,     4,     5,     1,     0,     2,     3,     1,     1,     3,
       1,     3,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     9,     2,     1,     1,
       3,     1,     1,     5,     5,     5,     3,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       1,     2,     2,     2,     2,     1,     3,     1,     1,     4,
       1,     3,     0,     1,     1,     1
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
#line 2070 "src/syntax.tab.c"
    break;

  case 3: /* declaration_list: declaration_list decl  */
#line 128 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("declaration list", 1);	// printable
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2081 "src/syntax.tab.c"
    break;

  case 4: /* declaration_list: decl  */
#line 134 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("declaration list", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2091 "src/syntax.tab.c"
    break;

  case 5: /* decl: var_declaration  */
#line 142 "src/syntax.y"
                       {
		(yyval.ast) = createAstNode("decl", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2101 "src/syntax.tab.c"
    break;

  case 6: /* decl: func_definition  */
#line 147 "src/syntax.y"
                         {
		(yyval.ast) = createAstNode("decl", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2111 "src/syntax.tab.c"
    break;

  case 7: /* decl: error  */
#line 152 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", 0);
		insertAstNode(&astList, (yyval.ast));
		printf("a\n");
	}
#line 2121 "src/syntax.tab.c"
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
#line 2137 "src/syntax.tab.c"
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
#line 2155 "src/syntax.tab.c"
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
#line 2171 "src/syntax.tab.c"
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
#line 2189 "src/syntax.tab.c"
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
#line 2201 "src/syntax.tab.c"
    break;

  case 13: /* params.opt: params  */
#line 224 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("params optional", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2211 "src/syntax.tab.c"
    break;

  case 14: /* params.opt: %empty  */
#line 229 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("params optional empty", 0); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2220 "src/syntax.tab.c"
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
#line 2236 "src/syntax.tab.c"
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
#line 2254 "src/syntax.tab.c"
    break;

  case 17: /* params: param_list  */
#line 263 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("params", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2264 "src/syntax.tab.c"
    break;

  case 18: /* param_list: param  */
#line 271 "src/syntax.y"
             {
		(yyval.ast) = createAstNode("param list", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2274 "src/syntax.tab.c"
    break;

  case 19: /* param_list: param_list ',' param  */
#line 276 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("param list", 0);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2285 "src/syntax.tab.c"
    break;

  case 20: /* param: var_definition  */
#line 285 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("param", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2295 "src/syntax.tab.c"
    break;

  case 21: /* stmts: '{' stmt_list.opt '}'  */
#line 293 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("stmts", 1);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2305 "src/syntax.tab.c"
    break;

  case 22: /* stmt_list.opt: stmt_list  */
#line 301 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list optional", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2315 "src/syntax.tab.c"
    break;

  case 23: /* stmt_list.opt: %empty  */
#line 306 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list empty", 0); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2324 "src/syntax.tab.c"
    break;

  case 24: /* stmt_list: stmt_list stmt.item  */
#line 313 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("stmt list", 0);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2335 "src/syntax.tab.c"
    break;

  case 25: /* stmt_list: stmt.item  */
#line 319 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt list", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2345 "src/syntax.tab.c"
    break;

  case 26: /* stmt.item: stmt  */
#line 327 "src/syntax.y"
            {
		(yyval.ast) = createAstNode("stmt item", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2355 "src/syntax.tab.c"
    break;

  case 27: /* stmt.item: var_declaration  */
#line 332 "src/syntax.y"
                         {
		(yyval.ast) = createAstNode("stmt item", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2365 "src/syntax.tab.c"
    break;

  case 28: /* stmt: return_stmt  */
#line 340 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2375 "src/syntax.tab.c"
    break;

  case 29: /* stmt: select_stmt  */
#line 345 "src/syntax.y"
                     {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2385 "src/syntax.tab.c"
    break;

  case 30: /* stmt: iter_stmt  */
#line 350 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2395 "src/syntax.tab.c"
    break;

  case 31: /* stmt: io_stmt  */
#line 355 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2405 "src/syntax.tab.c"
    break;

  case 32: /* stmt: exp_stmt  */
#line 360 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2415 "src/syntax.tab.c"
    break;

  case 33: /* stmt: stmts  */
#line 365 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2425 "src/syntax.tab.c"
    break;

  case 34: /* select_stmt: IF '(' simple_exp ')' stmt  */
#line 373 "src/syntax.y"
                                             {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2436 "src/syntax.tab.c"
    break;

  case 35: /* select_stmt: IF '(' simple_exp ')' stmt ELSE stmt  */
#line 379 "src/syntax.y"
                                              {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-4].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2448 "src/syntax.tab.c"
    break;

  case 36: /* iter_stmt: FOR '(' exp ';' simple_exp ';' exp ')' stmt  */
#line 389 "src/syntax.y"
                                                   {
		(yyval.ast) = createAstNode("iter stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-6].ast);
		(yyval.ast)->children[1] = (yyvsp[-4].ast);
		(yyval.ast)->children[2] = (yyvsp[-2].ast);
		(yyval.ast)->children[3] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2461 "src/syntax.tab.c"
    break;

  case 37: /* exp_stmt: exp ';'  */
#line 400 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("expression", 0);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2471 "src/syntax.tab.c"
    break;

  case 38: /* exp: assign_exp  */
#line 408 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("exp stmt", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2481 "src/syntax.tab.c"
    break;

  case 39: /* exp: simple_exp  */
#line 413 "src/syntax.y"
                    {
		(yyval.ast) = createAstNode("exp stmt", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2491 "src/syntax.tab.c"
    break;

  case 40: /* return_stmt: RETURN exp ';'  */
#line 421 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("return stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2501 "src/syntax.tab.c"
    break;

  case 41: /* io_stmt: in_stmt  */
#line 429 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("in/out stmt", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2511 "src/syntax.tab.c"
    break;

  case 42: /* io_stmt: out_stmt  */
#line 434 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("in/out stmt", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2521 "src/syntax.tab.c"
    break;

  case 43: /* in_stmt: INPUT '(' ID ')' ';'  */
#line 442 "src/syntax.y"
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
#line 2536 "src/syntax.tab.c"
    break;

  case 44: /* out_stmt: OUTPUT '(' STRING ')' ';'  */
#line 455 "src/syntax.y"
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
#line 2551 "src/syntax.tab.c"
    break;

  case 45: /* out_stmt: OUTPUT '(' exp ')' ';'  */
#line 465 "src/syntax.y"
                                {
		(yyval.ast) = createAstNode("output stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2561 "src/syntax.tab.c"
    break;

  case 46: /* assign_exp: ID '=' exp  */
#line 473 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("assign exp", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2571 "src/syntax.tab.c"
    break;

  case 47: /* simple_exp: simple_exp LOGICAL_OR and_exp  */
#line 481 "src/syntax.y"
                                     {
		char operation[200];
		(yyval.ast) = createAstNode("simple exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2585 "src/syntax.tab.c"
    break;

  case 48: /* simple_exp: and_exp  */
#line 490 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("simple exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2595 "src/syntax.tab.c"
    break;

  case 49: /* and_exp: and_exp LOGICAL_AND rel_exp  */
#line 498 "src/syntax.y"
                                   {
		char operation[200];
		(yyval.ast) = createAstNode("and exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2609 "src/syntax.tab.c"
    break;

  case 50: /* and_exp: rel_exp  */
#line 507 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("and exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2619 "src/syntax.tab.c"
    break;

  case 51: /* rel_exp: rel_exp RELATIONAL list_exp  */
#line 515 "src/syntax.y"
                                   {
		char operation[200];
		(yyval.ast) = createAstNode("rel exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2633 "src/syntax.tab.c"
    break;

  case 52: /* rel_exp: list_exp  */
#line 524 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("rel exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2643 "src/syntax.tab.c"
    break;

  case 53: /* list_exp: sum_exp LIST_CONSTR list_exp  */
#line 532 "src/syntax.y"
                                    {
		char operation[200];
		(yyval.ast) = createAstNode("list exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2657 "src/syntax.tab.c"
    break;

  case 54: /* list_exp: sum_exp LIST_FUNC list_exp  */
#line 541 "src/syntax.y"
                                    {
		char operation[200];
		(yyval.ast) = createAstNode("list exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2671 "src/syntax.tab.c"
    break;

  case 55: /* list_exp: sum_exp  */
#line 550 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("list exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2681 "src/syntax.tab.c"
    break;

  case 56: /* sum_exp: sum_exp ADD mul_exp  */
#line 558 "src/syntax.y"
                           {
		char operation[200];
		(yyval.ast) = createAstNode("sum exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2695 "src/syntax.tab.c"
    break;

  case 57: /* sum_exp: mul_exp  */
#line 567 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("sum exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2705 "src/syntax.tab.c"
    break;

  case 58: /* mul_exp: mul_exp MUL unary_exp  */
#line 575 "src/syntax.y"
                             {
		char operation[200];
		(yyval.ast) = createAstNode("mul exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2719 "src/syntax.tab.c"
    break;

  case 59: /* mul_exp: unary_exp  */
#line 584 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("mul exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2729 "src/syntax.tab.c"
    break;

  case 60: /* unary_exp: factor  */
#line 592 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("unary exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2739 "src/syntax.tab.c"
    break;

  case 61: /* unary_exp: LIST_OP unary_exp  */
#line 597 "src/syntax.y"
                           {
		char operation[200];
		(yyval.ast) = createAstNode("unary exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2752 "src/syntax.tab.c"
    break;

  case 62: /* unary_exp: LIST_DESTR unary_exp  */
#line 605 "src/syntax.y"
                              {
		char operation[200];
		(yyval.ast) = createAstNode("unary exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2765 "src/syntax.tab.c"
    break;

  case 63: /* unary_exp: OP_OVERLOAD unary_exp  */
#line 613 "src/syntax.y"
                               {
		char operation[200];
		(yyval.ast) = createAstNode("unary exp", 1);
		strcpy(operation, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(operation);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2778 "src/syntax.tab.c"
    break;

  case 64: /* unary_exp: ADD unary_exp  */
#line 621 "src/syntax.y"
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
#line 2795 "src/syntax.tab.c"
    break;

  case 65: /* factor: ID  */
#line 636 "src/syntax.y"
          {
		char id_type[200];
		(yyval.ast) = createAstNode("factor exp", 1);
		strcpy(id_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(id_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2807 "src/syntax.tab.c"
    break;

  case 66: /* factor: '(' simple_exp ')'  */
#line 643 "src/syntax.y"
                            {
		(yyval.ast) = createAstNode("factor exp", 0);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2817 "src/syntax.tab.c"
    break;

  case 67: /* factor: func_call  */
#line 648 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("factor exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2827 "src/syntax.tab.c"
    break;

  case 68: /* factor: constant  */
#line 653 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("factor exp", 0);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2837 "src/syntax.tab.c"
    break;

  case 69: /* func_call: ID '(' func_params ')'  */
#line 661 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("func call", 1);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2847 "src/syntax.tab.c"
    break;

  case 70: /* func_params: simple_exp  */
#line 669 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("func params", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2857 "src/syntax.tab.c"
    break;

  case 71: /* func_params: func_params ',' simple_exp  */
#line 674 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("func params", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2868 "src/syntax.tab.c"
    break;

  case 72: /* func_params: %empty  */
#line 680 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("func params empty", 0); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2877 "src/syntax.tab.c"
    break;

  case 73: /* constant: INTEGER  */
#line 687 "src/syntax.y"
               {
		char int_type[200];
		(yyval.ast) = createAstNode("int constant", 1);
		strcpy(int_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(int_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2889 "src/syntax.tab.c"
    break;

  case 74: /* constant: REAL  */
#line 694 "src/syntax.y"
              {
		char real_type[200];
		(yyval.ast) = createAstNode("real constant", 1);
		strcpy(real_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(real_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2901 "src/syntax.tab.c"
    break;

  case 75: /* constant: NIL_CONSTANT  */
#line 701 "src/syntax.y"
                      {
		char nil_type[200];
		(yyval.ast) = createAstNode("nil constant", 1);
		strcpy(nil_type, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup(nil_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2913 "src/syntax.tab.c"
    break;


#line 2917 "src/syntax.tab.c"

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

#line 710 "src/syntax.y"


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

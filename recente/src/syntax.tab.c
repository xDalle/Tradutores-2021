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
#line 5 "src/syntax.y"

	#define RED "\x1b[31m"
	#define WHITE "\x1b[0m"
	#define GREEN "\x1b[32m"
	#define PURPLE "\x1b[35m"
	#define ERROR -1
	#define DEBUG_AST 0
	
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
	extern int last_scope;
	extern int func_context;
	static int syntax_errors = 0;
	static int semantic_errors = 0;
	int check_func_type = 0;
	extern Ast root;
	extern AstList astList;
	extern Table symbolTable;
	extern Context contextList;

#line 102 "src/syntax.tab.c"

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
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_46_params_opt = 46,             /* params.opt  */
  YYSYMBOL_func_declaration = 47,          /* func_declaration  */
  YYSYMBOL_param_list = 48,                /* param_list  */
  YYSYMBOL_param = 49,                     /* param  */
  YYSYMBOL_stmts = 50,                     /* stmts  */
  YYSYMBOL_51_stmt_list_opt = 51,          /* stmt_list.opt  */
  YYSYMBOL_stmt_list = 52,                 /* stmt_list  */
  YYSYMBOL_53_stmt_item = 53,              /* stmt.item  */
  YYSYMBOL_stmt = 54,                      /* stmt  */
  YYSYMBOL_select_stmt = 55,               /* select_stmt  */
  YYSYMBOL_iter_stmt = 56,                 /* iter_stmt  */
  YYSYMBOL_exp_stmt = 57,                  /* exp_stmt  */
  YYSYMBOL_exp = 58,                       /* exp  */
  YYSYMBOL_return_stmt = 59,               /* return_stmt  */
  YYSYMBOL_io_stmt = 60,                   /* io_stmt  */
  YYSYMBOL_in_stmt = 61,                   /* in_stmt  */
  YYSYMBOL_out_stmt = 62,                  /* out_stmt  */
  YYSYMBOL_assign_exp = 63,                /* assign_exp  */
  YYSYMBOL_simple_exp = 64,                /* simple_exp  */
  YYSYMBOL_and_exp = 65,                   /* and_exp  */
  YYSYMBOL_rel_exp = 66,                   /* rel_exp  */
  YYSYMBOL_list_exp = 67,                  /* list_exp  */
  YYSYMBOL_sum_exp = 68,                   /* sum_exp  */
  YYSYMBOL_mul_exp = 69,                   /* mul_exp  */
  YYSYMBOL_unary_exp = 70,                 /* unary_exp  */
  YYSYMBOL_factor = 71,                    /* factor  */
  YYSYMBOL_func_call = 72,                 /* func_call  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_func_params = 74,               /* func_params  */
  YYSYMBOL_constant = 75                   /* constant  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3049

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  282

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
       0,   126,   126,   137,   143,   151,   156,   161,   165,   173,
     188,   207,   221,   240,   243,   240,   256,   261,   268,   286,
     309,   314,   320,   328,   337,   345,   350,   357,   363,   371,
     376,   384,   389,   394,   399,   404,   409,   413,   421,   427,
     437,   448,   456,   461,   469,   478,   483,   491,   507,   517,
     529,   544,   551,   556,   564,   571,   579,   586,   594,   601,
     608,   616,   623,   631,   638,   646,   651,   657,   663,   669,
     684,   694,   699,   704,   712,   712,   728,   744,   749,   758,
     766,   774
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
  "var_declaration", "func_definition", "$@1", "$@2", "params.opt",
  "func_declaration", "param_list", "param", "stmts", "stmt_list.opt",
  "stmt_list", "stmt.item", "stmt", "select_stmt", "iter_stmt", "exp_stmt",
  "exp", "return_stmt", "io_stmt", "in_stmt", "out_stmt", "assign_exp",
  "simple_exp", "and_exp", "rel_exp", "list_exp", "sum_exp", "mul_exp",
  "unary_exp", "factor", "func_call", "$@3", "func_params", "constant", YY_NULLPTR
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

#define YYPACT_NINF (-180)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,    20,     2,    23,    34,    27,    30,    32,    36,    39,
      73,    96,  -180,    72,    49,   188,    76,    78,    82,   198,
      44,   206,     8,   220,   283,    88,   317,    80,   113,   321,
     133,   332,   816,    94,    45,  2988,   267,   718,   137,   181,
    2633,   189,   204,   130,   337,   743,  2988,  2988,  2988,  2642,
    1412,  1443,  1474,   211,  1505,  1536,  1567,  1598,  1629,  1660,
     213,  1691,  1722,  1753,  1784,   218,    50,   202,    61,   114,
     414,   769,   777,  2144,  2154,  2161,   486,  2178,  2642,  2633,
     223,   245,  2597,   280,   281,  2278,  2633,  2184,  2201,  2207,
       9,   216,  1815,  1846,  2988,  2988,  2988,  2988,  2988,  2988,
    2988,   116,   286,  1877,   316,   331,   383,   393,  2224,  2665,
     396,  2230,   292,   199,   249,  2247,   284,   287,  2253,   577,
    2674,   403,   404,   405,    92,   372,   852,    67,  1908,  1939,
    1970,  2270,  2665,   661,  2697,   111,  2001,   409,   661,  2032,
     816,   322,  2997,  2743,  2760,  2726,  2766,  2997,  2997,  2997,
    2642,   176,   253,   339,  2966,  2783,  2800,  2806,  2823,  2840,
    2704,   411,   350,  2063,  2997,  2094,   127,  3018,   301,  2342,
    2336,  2374,  3018,  3018,  3018,  2642,   318,   335,   373,  2574,
    2380,  2397,  2414,  2420,  2437,   413,   415,  2633,   416,   417,
     816,   885,   916,   947,   978,  1009,   424,  1040,  1071,  1102,
    1133,  3018,   288,  2846,  2301,  2863,  2880,  2886,   376,  2997,
    2997,  2997,  2997,  2997,  2997,  2697,   596,  2454,  2310,  2460,
    2477,  2494,   388,  3018,  3018,  3018,  3018,  3018,  3018,  2642,
    2633,   425,   433,  2606,   421,  1164,   422,  2125,  2903,  2665,
    2920,   450,   511,  2926,   569,   602,  2943,   420,  2500,  2665,
    2517,   464,   499,  2534,   518,   521,  2540,   391,   434,  1195,
     442,   451,   460,  1226,   377,   378,   577,  2674,   462,   467,
     469,  2960,  2557,  1257,    71,  1288,  1319,  1350,  2697,   463,
     577,  1381
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,  -180,   494,  -180,   120,  -180,  -180,  -180,  -180,
    -180,  -180,   482,   -30,  -134,  -180,   458,  -116,  -115,  -114,
    -111,   -33,  -110,  -109,  -108,   -93,   -80,   611,    10,   574,
     336,   490,   406,   -34,    54,   164,  -179,   -25,   252
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    21,    51,     8,    17,    27,    22,
       9,    23,    24,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   109,   125,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    77,   161,   126,   193,   194,   202,    80,   195,   197,
     198,   199,    87,    88,    89,   156,   164,   136,    10,    11,
      -8,    -8,   139,    -7,    -7,   239,   200,    -2,     1,     1,
      -4,    -4,    -5,    -5,    12,    -8,    -6,    -6,    -7,   249,
     -14,   111,     2,     2,   156,    -4,   102,    -5,   156,   106,
     -13,    -6,   -53,   110,   161,    -8,   234,    94,    -7,   151,
      25,    26,     3,     3,   -13,    -4,   118,    -5,   -55,   -55,
      14,    -6,    -3,    -3,    94,   181,   -11,   -11,    94,    19,
     -53,   -13,   -12,   -12,    96,   -43,   196,    -3,   151,   192,
      15,   -11,   151,    20,   -15,   -15,   -55,   -12,   181,   201,
     156,   137,   134,   157,   112,    29,   278,    -3,   203,   -15,
     -17,   -11,    30,   205,   206,   207,   156,   -12,   201,   176,
       7,   -57,   -57,   164,   -77,     7,   -77,   -18,    20,   -15,
     156,    16,   157,   217,   -53,   161,   157,   -57,   219,   220,
     221,   156,   176,   -78,   151,   -78,    83,    84,   119,   -57,
     273,   193,   194,   161,   231,   195,   197,   198,   199,   -53,
     151,   -53,    32,   182,   281,   193,   194,   181,    78,   195,
     197,   198,   199,   200,   216,   156,   156,   156,   156,   156,
     246,   156,   247,   -52,   209,   151,   182,   200,   157,   181,
     181,   181,   181,   181,   256,   156,   157,   258,   161,   156,
     262,   157,   157,   157,   157,   181,   -54,   -54,   -52,   -52,
      95,   236,    79,   158,   264,   181,   -24,   -24,   157,   -19,
      81,   182,    96,    18,   265,   151,   182,   182,   182,   157,
     -22,   -24,   -22,   196,   -54,    82,   192,   -52,   -23,   151,
     -23,    91,   158,   151,   156,   279,   158,   196,    93,   176,
     192,   -24,   -16,   -42,    28,   182,   -56,   -56,   103,   176,
     -55,   -55,   104,   157,   157,   157,   157,   157,   157,   157,
     -79,   -79,   -56,   183,   -79,   -79,   210,   182,   182,   182,
     182,   182,   182,   157,   -56,   -55,   -79,   157,   151,   -79,
     -79,   -58,   -58,   182,   -59,   -59,   183,   107,   158,   -51,
      95,   159,   -79,   182,   -79,   -79,   158,   -58,   -79,   -79,
     -59,   158,   158,   158,   158,   -20,   163,   -20,   237,   -58,
     -79,   120,   -59,   -79,   -79,   -52,   223,   -51,   158,   -53,
     159,   183,   157,   -79,   159,   -79,   183,   183,   183,   158,
     -70,   -70,   -55,   -55,   -70,   -70,   -57,   -57,   121,    -9,
     -52,    -9,   -52,   -10,   -53,   -10,   -70,   164,   224,   -70,
     -70,   184,   -57,   122,   -21,   183,   -21,   -55,    85,   -55,
      86,   -57,   -70,   158,   158,   158,   158,   158,   158,   158,
     -57,   -57,   -43,   164,   184,   153,   159,   183,   183,   183,
     183,   183,   183,   158,   159,   164,   -57,   158,   164,   159,
     159,   159,   159,   183,   131,   -57,   132,   -57,   240,   271,
     272,   132,   132,   183,   153,   123,   159,    97,   153,   184,
     250,   -60,   -60,   266,   184,   184,   184,   159,   165,   -51,
     223,   -50,   114,    98,   116,   117,    99,   -60,   128,   129,
     130,   138,   158,   -42,   229,   178,   230,   232,   233,   -60,
     260,   263,   -50,   184,   -51,   155,   -51,   -54,   -54,   235,
     259,   159,   159,   159,   159,   159,   159,   159,   178,   267,
     153,   -54,   -54,   210,   268,   184,   184,   184,   184,   184,
     184,   159,   -54,   269,   155,   159,   153,   224,   155,   -70,
     -70,   184,   270,   -70,   -70,   280,   -54,   275,   -54,    13,
     153,   184,   276,   115,   277,   -70,   -56,   -56,   -70,   -70,
      31,   153,    92,     0,     0,   180,     0,    85,   -56,   -56,
       0,   -70,   -56,     0,     0,   -58,   -58,     0,   -59,   -59,
     159,   -56,     0,   -56,   -56,     0,     0,   178,   180,   154,
     155,   -58,     0,   -56,   -59,   153,   242,     0,   244,   245,
     -58,   153,   -58,   -59,     0,   -59,   155,     0,     0,   178,
     252,     0,   254,   255,     0,   153,     0,     0,   154,   153,
     155,     0,   154,     0,     0,   178,   -58,   -58,    34,     0,
      35,   155,    36,    37,     0,   178,   185,     0,   186,   187,
     188,   189,   -58,     0,    44,    45,     0,    46,    47,   179,
       0,   -58,    48,   -51,   209,     0,   190,   180,    49,   -59,
     -59,     0,   191,     0,   153,   155,   155,   243,   155,   155,
       0,   155,   179,   152,   154,   -59,     0,     0,   -51,   180,
     180,   253,   180,   180,   -59,   155,     0,     0,     0,   155,
     154,     0,     0,     0,     0,   180,     0,     0,     0,     0,
       0,     0,   152,     0,   154,   180,   152,     0,     0,     0,
      90,     0,    34,     0,    35,   154,    36,    37,     0,   113,
      38,     0,    39,    40,    41,    42,     0,     0,    44,    45,
       0,    46,    47,   177,   155,     0,    48,     0,     0,   101,
     140,   179,    49,   162,     0,     0,    50,     0,     0,   154,
     154,     0,   154,   154,     0,   154,   177,     0,   152,     0,
       0,     0,     0,   179,   179,     0,   179,   179,     0,   154,
     124,   -80,   -80,   154,   152,   -80,   -80,     0,     0,   179,
       0,   127,     0,     0,     0,     0,     0,   -80,   152,   179,
     -80,   -80,     0,   135,     0,   162,   -81,   -81,     0,   152,
     -81,   -81,     0,   -80,     0,     0,     0,     0,     0,     0,
       0,   208,   -81,     0,     0,   -81,   -81,     0,   154,     0,
       0,     0,   -62,   100,     0,   177,   -62,   -62,   -81,     0,
     -64,   -64,     0,   241,   -64,   -64,   222,     0,   -62,   152,
       0,   -62,   -62,     0,     0,     0,   -64,   251,     0,   -64,
     -64,     0,     0,   152,   -62,     0,     0,   152,     0,     0,
       0,     0,   -64,   177,     0,     0,     0,    34,     0,    35,
       0,    36,    37,   177,     0,    38,   162,    39,    40,    41,
      42,    43,     0,    44,    45,     0,    46,    47,     0,     0,
     257,    48,     0,     0,   162,   140,   -26,    49,     0,     0,
     124,    50,   152,   -38,     0,   -38,     0,   -38,   -38,     0,
     124,   -38,   133,   -38,   -38,   -38,   -38,   -38,     0,   -38,
     -38,     0,   -38,   -38,     0,     0,     0,   -38,   274,     0,
       0,   -38,   -38,   -38,     0,     0,   -36,   -38,   -36,   162,
     -36,   -36,     0,     0,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,     0,   -36,   -36,     0,   -36,   -36,     0,     0,     0,
     -36,     0,     0,     0,   -36,   -36,   -36,   -37,     0,   -37,
     -36,   -37,   -37,     0,     0,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,     0,   -37,   -37,     0,     0,
       0,   -37,     0,     0,     0,   -37,   -37,   -37,   -32,     0,
     -32,   -37,   -32,   -32,     0,     0,   -32,   -32,   -32,   -32,
     -32,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,     0,
       0,     0,   -32,     0,     0,     0,   -32,   -32,   -32,   -33,
       0,   -33,   -32,   -33,   -33,     0,     0,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,     0,   -33,   -33,     0,   -33,   -33,
       0,     0,     0,   -33,     0,     0,     0,   -33,   -33,   -33,
     -35,     0,   -35,   -33,   -35,   -35,     0,     0,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,     0,   -35,
     -35,     0,     0,     0,   -35,     0,     0,     0,   -35,   -35,
     -35,   -31,     0,   -31,   -35,   -31,   -31,     0,     0,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,     0,
     -31,   -31,     0,     0,     0,   -31,     0,     0,     0,   -31,
     -31,   -31,   -34,     0,   -34,   -31,   -34,   -34,     0,     0,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,   -34,
       0,   -34,   -34,     0,     0,     0,   -34,     0,     0,     0,
     -34,   -34,   -34,   -45,     0,   -45,   -34,   -45,   -45,     0,
       0,   -45,   -45,   -45,   -45,   -45,   -45,   -45,     0,   -45,
     -45,     0,   -45,   -45,     0,     0,     0,   -45,     0,     0,
       0,   -45,   -45,   -45,   -46,     0,   -46,   -45,   -46,   -46,
       0,     0,   -46,   -46,   -46,   -46,   -46,   -46,   -46,     0,
     -46,   -46,     0,   -46,   -46,     0,     0,     0,   -46,     0,
       0,     0,   -46,   -46,   -46,   -41,     0,   -41,   -46,   -41,
     -41,     0,     0,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
       0,   -41,   -41,     0,   -41,   -41,     0,     0,     0,   -41,
       0,     0,     0,   -41,   -41,   -41,   -44,     0,   -44,   -41,
     -44,   -44,     0,     0,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,     0,   -44,   -44,     0,   -44,   -44,     0,     0,     0,
     -44,     0,     0,     0,   -44,   -44,   -44,   -24,     0,   -24,
     -44,   -24,   -24,     0,     0,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,     0,   -24,   -24,     0,   -24,   -24,     0,     0,
       0,   -24,     0,     0,     0,   -24,   -24,   -24,   -38,     0,
     -38,   -24,   -38,   -38,     0,     0,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,     0,
       0,     0,   -38,     0,     0,     0,   -38,   -38,   -38,   -47,
       0,   -47,   -38,   -47,   -47,     0,     0,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,
       0,     0,     0,   -47,     0,     0,     0,   -47,   -47,   -47,
     -48,     0,   -48,   -47,   -48,   -48,     0,     0,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,     0,   -48,
     -48,     0,     0,     0,   -48,     0,     0,     0,   -48,   -48,
     -48,   -49,     0,   -49,   -48,   -49,   -49,     0,     0,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,     0,
     -49,   -49,     0,     0,     0,   -49,     0,     0,     0,   -49,
     -49,   -49,   -40,     0,   -40,   -49,   -40,   -40,     0,     0,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,
       0,   -40,   -40,     0,     0,     0,   -40,     0,     0,     0,
     -40,   -40,   -40,   -36,     0,   -36,   -40,   -36,   -36,     0,
       0,   -36,     0,   -36,   -36,   -36,   -36,   -36,     0,   -36,
     -36,     0,   -36,   -36,     0,     0,     0,   -36,     0,     0,
       0,   -36,   -36,   -36,   -30,     0,   -30,   -36,   -30,   -30,
       0,     0,   -30,     0,   -30,   -30,   -30,   -30,   -30,     0,
     -30,   -30,     0,   -30,   -30,     0,     0,     0,   -30,     0,
       0,     0,   -30,   -30,   -30,   -37,     0,   -37,   -30,   -37,
     -37,     0,     0,   -37,     0,   -37,   -37,   -37,   -37,   -37,
       0,   -37,   -37,     0,   -37,   -37,     0,     0,     0,   -37,
       0,     0,     0,   -37,   -37,   -37,    34,     0,    35,   -37,
      36,    37,     0,     0,    38,     0,    39,    40,    41,    42,
      43,     0,    44,    45,     0,    46,    47,     0,     0,     0,
      48,     0,     0,     0,   140,   -25,    49,   -28,     0,   -28,
      50,   -28,   -28,     0,     0,   -28,     0,   -28,   -28,   -28,
     -28,   -28,     0,   -28,   -28,     0,   -28,   -28,     0,     0,
       0,   -28,     0,     0,     0,   -28,   -28,   -28,   -29,     0,
     -29,   -28,   -29,   -29,     0,     0,   -29,     0,   -29,   -29,
     -29,   -29,   -29,     0,   -29,   -29,     0,   -29,   -29,     0,
       0,     0,   -29,     0,     0,     0,   -29,   -29,   -29,   -32,
       0,   -32,   -29,   -32,   -32,     0,     0,   -32,     0,   -32,
     -32,   -32,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,
       0,     0,     0,   -32,     0,     0,     0,   -32,   -32,   -32,
     -33,     0,   -33,   -32,   -33,   -33,     0,     0,   -33,     0,
     -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,     0,   -33,
     -33,     0,     0,     0,   -33,     0,     0,     0,   -33,   -33,
     -33,   -35,     0,   -35,   -33,   -35,   -35,     0,     0,   -35,
       0,   -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,     0,
     -35,   -35,     0,     0,     0,   -35,     0,     0,     0,   -35,
     -35,   -35,   -31,     0,   -31,   -35,   -31,   -31,     0,     0,
     -31,     0,   -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,
       0,   -31,   -31,     0,     0,     0,   -31,     0,     0,     0,
     -31,   -31,   -31,   -34,     0,   -34,   -31,   -34,   -34,     0,
       0,   -34,     0,   -34,   -34,   -34,   -34,   -34,     0,   -34,
     -34,     0,   -34,   -34,     0,     0,     0,   -34,     0,     0,
       0,   -34,   -34,   -34,   -45,     0,   -45,   -34,   -45,   -45,
       0,     0,   -45,     0,   -45,   -45,   -45,   -45,   -45,     0,
     -45,   -45,     0,   -45,   -45,     0,     0,     0,   -45,     0,
       0,     0,   -45,   -45,   -45,   -46,     0,   -46,   -45,   -46,
     -46,     0,     0,   -46,     0,   -46,   -46,   -46,   -46,   -46,
       0,   -46,   -46,     0,   -46,   -46,     0,     0,     0,   -46,
       0,     0,     0,   -46,   -46,   -46,   -27,     0,   -27,   -46,
     -27,   -27,     0,     0,   -27,     0,   -27,   -27,   -27,   -27,
     -27,     0,   -27,   -27,     0,   -27,   -27,     0,     0,     0,
     -27,     0,     0,     0,   -27,   -27,   -27,   -41,     0,   -41,
     -27,   -41,   -41,     0,     0,   -41,     0,   -41,   -41,   -41,
     -41,   -41,     0,   -41,   -41,     0,   -41,   -41,     0,     0,
       0,   -41,     0,     0,     0,   -41,   -41,   -41,   -44,     0,
     -44,   -41,   -44,   -44,     0,     0,   -44,     0,   -44,   -44,
     -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,     0,
       0,     0,   -44,     0,     0,     0,   -44,   -44,   -44,   -47,
       0,   -47,   -44,   -47,   -47,     0,     0,   -47,     0,   -47,
     -47,   -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,
       0,     0,     0,   -47,     0,     0,     0,   -47,   -47,   -47,
     -48,     0,   -48,   -47,   -48,   -48,     0,     0,   -48,     0,
     -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,     0,   -48,
     -48,     0,     0,     0,   -48,     0,     0,     0,   -48,   -48,
     -48,   -49,     0,   -49,   -48,   -49,   -49,     0,     0,   -49,
       0,   -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,     0,
     -49,   -49,     0,     0,     0,   -49,     0,     0,     0,   -49,
     -49,   -49,   -39,     0,   -39,   -49,   -39,   -39,     0,     0,
     -39,     0,   -39,   -39,   -39,   -39,   -39,     0,   -39,   -39,
       0,   -39,   -39,     0,     0,     0,   -39,     0,     0,     0,
     -39,   -39,   -39,   -40,     0,   -40,   -39,   -40,   -40,     0,
       0,   -40,     0,   -40,   -40,   -40,   -40,   -40,     0,   -40,
     -40,     0,   -40,   -40,     0,     0,     0,   -40,     0,     0,
       0,   -40,   -40,   -40,   -11,     0,   -11,   -40,   -11,   -11,
       0,     0,   -11,     0,   -11,   -11,   -11,   -11,   -11,     0,
     -11,   -11,     0,   -11,   -11,     0,     0,     0,   -11,     0,
       0,     0,   -11,   -11,   -11,   -12,     0,   -12,   -11,   -12,
     -12,     0,     0,   -12,     0,   -12,   -12,   -12,   -12,   -12,
       0,   -12,   -12,     0,   -12,   -12,     0,     0,     0,   -12,
       0,     0,     0,   -12,   -12,   -12,   -24,     0,   -24,   -12,
     -24,   -24,     0,     0,   -24,     0,   -24,   -24,   -24,   -24,
     -24,     0,   -24,   -24,     0,   -24,   -24,   -65,   -65,     0,
     -24,   -65,   -65,     0,   -24,   -24,   -24,   -72,   -72,     0,
     -24,   -72,   -72,   -65,   -73,   -73,   -65,   -65,   -73,   -73,
       0,     0,     0,   -72,     0,     0,   -72,   -72,     0,   -65,
     -73,   -69,   -69,   -73,   -73,   -69,   -69,   -66,   -66,   -72,
       0,   -66,   -66,     0,     0,     0,   -73,   -69,     0,     0,
     -69,   -69,     0,   -66,   -67,   -67,   -66,   -66,   -67,   -67,
     -68,   -68,     0,   -69,   -68,   -68,     0,     0,     0,   -66,
     -67,     0,     0,   -67,   -67,     0,   -68,   -76,   -76,   -68,
     -68,   -76,   -76,   -71,   -71,     0,   -67,   -71,   -71,     0,
       0,     0,   -68,   -76,     0,     0,   -76,   -76,     0,   -71,
     -61,   100,   -71,   -71,   -61,   -61,   -63,   -63,     0,   -76,
     -63,   -63,     0,     0,     0,   -71,   -61,     0,     0,   -61,
     -61,     0,   -63,   -75,   -75,   -63,   -63,   -75,   -75,   -74,
       0,   -74,   -61,   -74,   -74,     0,     0,     0,   -63,   -75,
       0,     0,   -75,   -75,     0,   -74,   -74,     0,   -74,   -74,
       0,     0,   -74,   -74,   -74,   -75,   -74,   -74,     0,   -74,
     108,   -74,     0,   -74,     0,   -74,   -74,     0,   -74,   -74,
       0,   -74,   -74,     0,     0,     0,   -74,   -74,   -74,     0,
     -74,   -74,   -74,   238,     0,   -74,     0,     0,     0,   -70,
     -70,   -74,   248,   -70,   -70,   -80,   -80,     0,     0,   -80,
     -80,     0,     0,     0,     0,   -70,     0,     0,   -70,   -70,
       0,   -80,     0,     0,   -80,   -80,     0,   218,   -70,     0,
     -70,     0,     0,     0,   -80,     0,   -80,   -81,   -81,     0,
       0,   -81,   -81,   -62,   228,     0,     0,   -62,   -62,     0,
       0,     0,     0,   -81,     0,     0,   -81,   -81,     0,   -62,
     -64,   -64,   -62,   -62,   -64,   -64,   -81,     0,   -81,     0,
       0,     0,   -62,     0,   -62,     0,   -64,   -65,   -65,   -64,
     -64,   -65,   -65,   -72,   -72,     0,     0,   -72,   -72,   -64,
       0,   -64,     0,   -65,     0,     0,   -65,   -65,     0,   -72,
     -73,   -73,   -72,   -72,   -73,   -73,   -65,     0,   -65,     0,
       0,     0,   -72,     0,   -72,     0,   -73,   -69,   -69,   -73,
     -73,   -69,   -69,   -66,   -66,     0,     0,   -66,   -66,   -73,
       0,   -73,     0,   -69,     0,     0,   -69,   -69,     0,   -66,
     -67,   -67,   -66,   -66,   -67,   -67,   -69,     0,   -69,     0,
       0,     0,   -66,     0,   -66,     0,   -67,   -68,   -68,   -67,
     -67,   -68,   -68,   -76,   -76,     0,     0,   -76,   -76,   -67,
       0,   -67,     0,   -68,     0,     0,   -68,   -68,     0,   -76,
     -71,   -71,   -76,   -76,   -71,   -71,   -68,     0,   -68,     0,
       0,     0,   -76,     0,   -76,     0,   -71,   -61,   228,   -71,
     -71,   -61,   -61,   -63,   -63,     0,     0,   -63,   -63,   -71,
       0,   -71,     0,   -61,     0,     0,   -61,   -61,     0,   -63,
     -75,   -75,   -63,   -63,   -75,   -75,   -61,     0,   -61,     0,
       0,     0,   -63,     0,   -63,     0,   -75,   225,     0,   -75,
     -75,   -60,   -60,     0,     0,     0,     0,     0,     0,   -75,
       0,   -75,     0,   226,     0,     0,   227,   -60,   141,     0,
     142,     0,   143,   144,     0,     0,   -60,   141,   -60,   142,
       0,   143,   144,     0,   160,   146,     0,   147,   148,     0,
       0,   105,   149,   160,   146,     0,   147,   148,   150,     0,
     261,   149,     0,     0,    34,     0,    35,   150,    36,    37,
       0,     0,     0,   141,     0,   142,     0,   143,   144,     0,
      44,    45,     0,    46,    47,     0,     0,     0,    48,   145,
     146,     0,   147,   148,    49,     0,   166,   149,   167,     0,
     168,   169,     0,   150,     0,    34,     0,    35,     0,    36,
      37,     0,   170,   171,     0,   172,   173,     0,     0,     0,
     174,    76,    45,     0,    46,    47,   175,     0,   141,    48,
     142,     0,   143,   144,     0,    49,     0,   -70,   -70,     0,
       0,   -70,   -70,     0,   160,   146,     0,   147,   148,     0,
       0,     0,   149,   -70,     0,     0,   -70,   -70,   150,   -70,
     -70,     0,     0,   -70,   -70,   204,   -70,   215,     0,     0,
       0,     0,     0,     0,     0,   -70,   -79,   -79,   -70,   -70,
     -79,   -79,     0,     0,     0,     0,     0,   204,   -70,     0,
       0,     0,   -79,   -80,   -80,   -79,   -79,   -80,   -80,   -81,
     -81,     0,     0,   -81,   -81,   -79,     0,     0,     0,   -80,
       0,     0,   -80,   -80,     0,   -81,   -62,   214,   -81,   -81,
     -62,   -62,   -80,     0,     0,     0,     0,     0,   -81,     0,
       0,     0,   -62,   -64,   -64,   -62,   -62,   -64,   -64,   -65,
     -65,     0,     0,   -65,   -65,   -62,     0,     0,     0,   -64,
       0,     0,   -64,   -64,     0,   -65,   -72,   -72,   -65,   -65,
     -72,   -72,   -64,     0,     0,     0,     0,     0,   -65,     0,
       0,     0,   -72,   -73,   -73,   -72,   -72,   -73,   -73,   -69,
     -69,     0,     0,   -69,   -69,   -72,     0,     0,     0,   -73,
       0,     0,   -73,   -73,     0,   -69,   -66,   -66,   -69,   -69,
     -66,   -66,   -73,     0,     0,     0,     0,     0,   -69,     0,
       0,     0,   -66,   -67,   -67,   -66,   -66,   -67,   -67,   -68,
     -68,     0,     0,   -68,   -68,   -66,     0,     0,     0,   -67,
       0,     0,   -67,   -67,     0,   -68,   -76,   -76,   -68,   -68,
     -76,   -76,   -67,     0,     0,     0,     0,     0,   -68,     0,
       0,     0,   -76,   -71,   -71,   -76,   -76,   -71,   -71,   -61,
     214,     0,     0,   -61,   -61,   -76,     0,     0,     0,   -71,
       0,     0,   -71,   -71,     0,   -61,   -63,   -63,   -61,   -61,
     -63,   -63,   -71,     0,     0,     0,     0,     0,   -61,     0,
       0,     0,   -63,   -75,   -75,   -63,   -63,   -75,   -75,   211,
       0,     0,     0,   -60,   -60,   -63,     0,     0,     0,   -75,
       0,     0,   -75,   -75,     0,   212,     0,     0,   213,   -60,
       0,    35,   -75,    36,    37,     0,     0,     0,   -60,     0,
     142,     0,   143,   144,     0,    76,    45,     0,    46,    47,
       0,     0,     0,    48,   145,   146,     0,   147,   148,    49,
       0,   167,   149,   168,   169,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,   170,   171,     0,   172,   173,
       0,     0,     0,   174,     0,     0,     0,     0,     0,   175
};

static const yytype_int16 yycheck[] =
{
      30,    35,    82,   119,   119,   119,   140,    40,   119,   119,
     119,   119,    46,    47,    48,    49,     7,   133,    16,    17,
       0,     1,   138,     0,     1,   204,   119,     0,     1,     1,
       0,     1,     0,     1,     0,    15,     0,     1,    15,   218,
      32,    32,    15,    15,    78,    15,    79,    15,    82,    82,
       1,    15,     7,    86,   134,    35,   190,     7,    35,    49,
      16,    17,    35,    35,    15,    35,   100,    35,     7,     8,
      31,    35,     0,     1,     7,   109,     0,     1,     7,     1,
      35,    32,     0,     1,    23,    35,   119,    15,    78,   119,
      17,    15,    82,    15,     0,     1,    35,    15,   132,     7,
     134,   134,    35,    49,    94,    17,    35,    35,   142,    15,
      32,    35,    32,   147,   148,   149,   150,    35,     7,   109,
       0,     7,     8,     7,    32,     5,    34,    31,    15,    35,
     164,    35,    78,   167,     7,   215,    82,    23,   172,   173,
     174,   175,   132,    32,   134,    34,    16,    17,    32,    35,
     266,   266,   266,   233,   187,   266,   266,   266,   266,    32,
     150,    34,    29,   109,   280,   280,   280,   201,    31,   280,
     280,   280,   280,   266,   164,   209,   210,   211,   212,   213,
     214,   215,   215,     7,     8,   175,   132,   280,   134,   223,
     224,   225,   226,   227,   228,   229,   142,   230,   278,   233,
     233,   147,   148,   149,   150,   239,     7,     8,    32,     7,
       8,   201,    31,    49,   239,   249,     0,     1,   164,    31,
      31,   167,    23,    35,   249,   215,   172,   173,   174,   175,
      32,    15,    34,   266,    35,    31,   266,    35,    32,   229,
      34,    30,    78,   233,   278,   278,    82,   280,    35,   239,
     280,    35,    32,    35,    34,   201,     7,     8,    35,   249,
       7,     8,    17,   209,   210,   211,   212,   213,   214,   215,
       3,     4,    23,   109,     7,     8,    23,   223,   224,   225,
     226,   227,   228,   229,    35,    32,    19,   233,   278,    22,
      23,     7,     8,   239,     7,     8,   132,    17,   134,     7,
       8,    49,    35,   249,     3,     4,   142,    23,     7,     8,
      23,   147,   148,   149,   150,    32,    35,    34,    30,    35,
      19,    35,    35,    22,    23,     7,     8,    35,   164,     7,
      78,   167,   278,    32,    82,    34,   172,   173,   174,   175,
       3,     4,     7,     8,     7,     8,     7,     8,    32,    32,
      32,    34,    34,    32,    32,    34,    19,     7,    23,    22,
      23,   109,    23,    32,    32,   201,    34,    32,    31,    34,
      33,    32,    35,   209,   210,   211,   212,   213,   214,   215,
       7,     8,    32,     7,   132,    49,   134,   223,   224,   225,
     226,   227,   228,   229,   142,     7,    23,   233,     7,   147,
     148,   149,   150,   239,    32,    32,    34,    34,    32,    32,
      32,    34,    34,   249,    78,    32,   164,     3,    82,   167,
      32,     7,     8,    32,   172,   173,   174,   175,    35,     7,
       8,    35,    96,    19,    98,    99,    22,    23,    35,    35,
      35,    32,   278,    32,    31,   109,    31,    31,    31,    35,
      17,    30,    32,   201,    32,    49,    34,     7,     8,    35,
      35,   209,   210,   211,   212,   213,   214,   215,   132,    35,
     134,     7,     8,    23,    32,   223,   224,   225,   226,   227,
     228,   229,    32,    32,    78,   233,   150,    23,    82,     3,
       4,   239,    32,     7,     8,    32,    32,    35,    34,     5,
     164,   249,    35,    97,    35,    19,     7,     8,    22,    23,
      28,   175,    54,    -1,    -1,   109,    -1,    31,     7,     8,
      -1,    35,    23,    -1,    -1,     7,     8,    -1,     7,     8,
     278,    32,    -1,    34,    23,    -1,    -1,   201,   132,    49,
     134,    23,    -1,    32,    23,   209,   210,    -1,   212,   213,
      32,   215,    34,    32,    -1,    34,   150,    -1,    -1,   223,
     224,    -1,   226,   227,    -1,   229,    -1,    -1,    78,   233,
     164,    -1,    82,    -1,    -1,   239,     7,     8,     1,    -1,
       3,   175,     5,     6,    -1,   249,     9,    -1,    11,    12,
      13,    14,    23,    -1,    17,    18,    -1,    20,    21,   109,
      -1,    32,    25,     7,     8,    -1,    29,   201,    31,     7,
       8,    -1,    35,    -1,   278,   209,   210,   211,   212,   213,
      -1,   215,   132,    49,   134,    23,    -1,    -1,    32,   223,
     224,   225,   226,   227,    32,   229,    -1,    -1,    -1,   233,
     150,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,   164,   249,    82,    -1,    -1,    -1,
      49,    -1,     1,    -1,     3,   175,     5,     6,    -1,    95,
       9,    -1,    11,    12,    13,    14,    -1,    -1,    17,    18,
      -1,    20,    21,   109,   278,    -1,    25,    -1,    -1,    78,
      29,   201,    31,    82,    -1,    -1,    35,    -1,    -1,   209,
     210,    -1,   212,   213,    -1,   215,   132,    -1,   134,    -1,
      -1,    -1,    -1,   223,   224,    -1,   226,   227,    -1,   229,
     109,     3,     4,   233,   150,     7,     8,    -1,    -1,   239,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    19,   164,   249,
      22,    23,    -1,   132,    -1,   134,     3,     4,    -1,   175,
       7,     8,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,    19,    -1,    -1,    22,    23,    -1,   278,    -1,
      -1,    -1,     3,     4,    -1,   201,     7,     8,    35,    -1,
       3,     4,    -1,   209,     7,     8,   175,    -1,    19,   215,
      -1,    22,    23,    -1,    -1,    -1,    19,   223,    -1,    22,
      23,    -1,    -1,   229,    35,    -1,    -1,   233,    -1,    -1,
      -1,    -1,    35,   239,    -1,    -1,    -1,     1,    -1,     3,
      -1,     5,     6,   249,    -1,     9,   215,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
     229,    25,    -1,    -1,   233,    29,    30,    31,    -1,    -1,
     239,    35,   278,     1,    -1,     3,    -1,     5,     6,    -1,
     249,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,   267,    -1,
      -1,    29,    30,    31,    -1,    -1,     1,    35,     3,   278,
       5,     6,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,
      35,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,
       3,    35,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,
      -1,     3,    35,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       1,    -1,     3,    35,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     1,    -1,     3,    35,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     1,    -1,     3,    35,     5,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     1,    -1,     3,    35,     5,     6,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     1,    -1,     3,    35,     5,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     1,    -1,     3,    35,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,    35,
       5,     6,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,
      35,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,
       3,    35,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,
      -1,     3,    35,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       1,    -1,     3,    35,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     1,    -1,     3,    35,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     1,    -1,     3,    35,     5,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     1,    -1,     3,    35,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     1,    -1,     3,    35,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     1,    -1,     3,    35,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,    35,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,
      35,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,
       3,    35,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,
      -1,     3,    35,     5,     6,    -1,    -1,     9,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       1,    -1,     3,    35,     5,     6,    -1,    -1,     9,    -1,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     1,    -1,     3,    35,     5,     6,    -1,    -1,     9,
      -1,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     1,    -1,     3,    35,     5,     6,    -1,    -1,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     1,    -1,     3,    35,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     1,    -1,     3,    35,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     1,    -1,     3,    35,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,    35,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,
      35,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,    -1,
       3,    35,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,     1,
      -1,     3,    35,     5,     6,    -1,    -1,     9,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
       1,    -1,     3,    35,     5,     6,    -1,    -1,     9,    -1,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,     1,    -1,     3,    35,     5,     6,    -1,    -1,     9,
      -1,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,     1,    -1,     3,    35,     5,     6,    -1,    -1,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,     1,    -1,     3,    35,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     1,    -1,     3,    35,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     1,    -1,     3,    35,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,     1,    -1,     3,    35,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,     3,     4,    -1,
      25,     7,     8,    -1,    29,    30,    31,     3,     4,    -1,
      35,     7,     8,    19,     3,     4,    22,    23,     7,     8,
      -1,    -1,    -1,    19,    -1,    -1,    22,    23,    -1,    35,
      19,     3,     4,    22,    23,     7,     8,     3,     4,    35,
      -1,     7,     8,    -1,    -1,    -1,    35,    19,    -1,    -1,
      22,    23,    -1,    19,     3,     4,    22,    23,     7,     8,
       3,     4,    -1,    35,     7,     8,    -1,    -1,    -1,    35,
      19,    -1,    -1,    22,    23,    -1,    19,     3,     4,    22,
      23,     7,     8,     3,     4,    -1,    35,     7,     8,    -1,
      -1,    -1,    35,    19,    -1,    -1,    22,    23,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    35,
       7,     8,    -1,    -1,    -1,    35,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,     1,
      -1,     3,    35,     5,     6,    -1,    -1,    -1,    35,    19,
      -1,    -1,    22,    23,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,     1,    25,     3,    35,     5,     6,    -1,    31,
      32,     1,    -1,     3,    -1,     5,     6,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    17,    18,    -1,
      20,    21,    31,    32,    -1,    25,    -1,    -1,    -1,     3,
       4,    31,    32,     7,     8,     3,     4,    -1,    -1,     7,
       8,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    23,
      -1,    19,    -1,    -1,    22,    23,    -1,    31,    32,    -1,
      34,    -1,    -1,    -1,    32,    -1,    34,     3,     4,    -1,
      -1,     7,     8,     3,     4,    -1,    -1,     7,     8,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    22,    23,    -1,    19,
       3,     4,    22,    23,     7,     8,    32,    -1,    34,    -1,
      -1,    -1,    32,    -1,    34,    -1,    19,     3,     4,    22,
      23,     7,     8,     3,     4,    -1,    -1,     7,     8,    32,
      -1,    34,    -1,    19,    -1,    -1,    22,    23,    -1,    19,
       3,     4,    22,    23,     7,     8,    32,    -1,    34,    -1,
      -1,    -1,    32,    -1,    34,    -1,    19,     3,     4,    22,
      23,     7,     8,     3,     4,    -1,    -1,     7,     8,    32,
      -1,    34,    -1,    19,    -1,    -1,    22,    23,    -1,    19,
       3,     4,    22,    23,     7,     8,    32,    -1,    34,    -1,
      -1,    -1,    32,    -1,    34,    -1,    19,     3,     4,    22,
      23,     7,     8,     3,     4,    -1,    -1,     7,     8,    32,
      -1,    34,    -1,    19,    -1,    -1,    22,    23,    -1,    19,
       3,     4,    22,    23,     7,     8,    32,    -1,    34,    -1,
      -1,    -1,    32,    -1,    34,    -1,    19,     3,     4,    22,
      23,     7,     8,     3,     4,    -1,    -1,     7,     8,    32,
      -1,    34,    -1,    19,    -1,    -1,    22,    23,    -1,    19,
       3,     4,    22,    23,     7,     8,    32,    -1,    34,    -1,
      -1,    -1,    32,    -1,    34,    -1,    19,     3,    -1,    22,
      23,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,    19,    -1,    -1,    22,    23,     1,    -1,
       3,    -1,     5,     6,    -1,    -1,    32,     1,    34,     3,
      -1,     5,     6,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    24,    25,    17,    18,    -1,    20,    21,    31,    -1,
      24,    25,    -1,    -1,     1,    -1,     3,    31,     5,     6,
      -1,    -1,    -1,     1,    -1,     3,    -1,     5,     6,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    17,
      18,    -1,    20,    21,    31,    -1,     1,    25,     3,    -1,
       5,     6,    -1,    31,    -1,     1,    -1,     3,    -1,     5,
       6,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    17,    18,    -1,    20,    21,    31,    -1,     1,    25,
       3,    -1,     5,     6,    -1,    31,    -1,     3,     4,    -1,
      -1,     7,     8,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    19,    -1,    -1,    22,    23,    31,     3,
       4,    -1,    -1,     7,     8,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,     3,     4,    22,    23,
       7,     8,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    19,     3,     4,    22,    23,     7,     8,     3,
       4,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    -1,    19,     3,     4,    22,    23,
       7,     8,    32,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    19,     3,     4,    22,    23,     7,     8,     3,
       4,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    -1,    19,     3,     4,    22,    23,
       7,     8,    32,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    19,     3,     4,    22,    23,     7,     8,     3,
       4,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    -1,    19,     3,     4,    22,    23,
       7,     8,    32,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    19,     3,     4,    22,    23,     7,     8,     3,
       4,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    -1,    19,     3,     4,    22,    23,
       7,     8,    32,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    19,     3,     4,    22,    23,     7,     8,     3,
       4,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    -1,    19,     3,     4,    22,    23,
       7,     8,    32,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    19,     3,     4,    22,    23,     7,     8,     3,
      -1,    -1,    -1,     7,     8,    32,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    -1,    19,    -1,    -1,    22,    23,
      -1,     3,    32,     5,     6,    -1,    -1,    -1,    32,    -1,
       3,    -1,     5,     6,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    17,    18,    -1,    20,    21,    31,
      -1,     3,    25,     5,     6,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    15,    35,    38,    39,    40,    42,    43,    47,
      16,    17,     0,    40,    31,    17,    35,    44,    35,     1,
      15,    41,    46,    48,    49,    16,    17,    45,    34,    17,
      32,    49,    29,    50,     1,     3,     5,     6,     9,    11,
      12,    13,    14,    15,    17,    18,    20,    21,    25,    31,
      35,    42,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    75,    17,    70,    31,    31,
      58,    31,    31,    16,    17,    31,    33,    70,    70,    70,
      64,    30,    53,    35,     7,     8,    23,     3,    19,    22,
       4,    64,    58,    35,    17,    24,    58,    17,    32,    73,
      58,    32,    65,    66,    67,    69,    67,    67,    70,    32,
      35,    32,    32,    32,    64,    74,    54,    64,    35,    35,
      35,    32,    34,    10,    35,    64,    54,    58,    32,    54,
      29,     1,     3,     5,     6,    17,    18,    20,    21,    25,
      31,    65,    66,    67,    68,    69,    70,    71,    72,    75,
      17,    63,    64,    35,     7,    35,     1,     3,     5,     6,
      17,    18,    20,    21,    25,    31,    65,    66,    67,    68,
      69,    70,    71,    72,    75,     9,    11,    12,    13,    14,
      29,    35,    50,    55,    56,    57,    58,    59,    60,    61,
      62,     7,    51,    70,    31,    70,    70,    70,    64,     8,
      23,     3,    19,    22,     4,    33,    65,    70,    31,    70,
      70,    70,    64,     8,    23,     3,    19,    22,     4,    31,
      31,    58,    31,    31,    51,    35,    65,    30,    32,    73,
      32,    66,    67,    69,    67,    67,    70,    58,    32,    73,
      32,    66,    67,    69,    67,    67,    70,    64,    58,    35,
      17,    24,    58,    30,    74,    74,    32,    35,    32,    32,
      32,    32,    32,    54,    64,    35,    35,    35,    35,    58,
      32,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    41,
      41,    42,    42,    44,    45,    43,    46,    46,    47,    47,
      48,    48,    48,    49,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    55,    55,
      56,    57,    58,    58,    59,    60,    60,    61,    62,    62,
      63,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      71,    71,    71,    71,    73,    72,    72,    74,    74,    75,
      75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       3,     3,     4,     0,     0,     7,     1,     0,     2,     3,
       1,     3,     1,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     7,
       9,     2,     1,     1,     3,     1,     1,     5,     5,     5,
       3,     3,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     1,     2,     2,     2,     2,
       1,     3,     1,     1,     0,     5,     3,     1,     3,     1,
       1,     1
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
#line 126 "src/syntax.y"
                        {
		//root = *createAstNode("initial", DEBUG_AST);	// non-printable
		root.node_name = strdup("initial");
		root.printable = DEBUG_AST;
		(yyval.ast) = &root;
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2161 "src/syntax.tab.c"
    break;

  case 3: /* declaration_list: declaration_list decl  */
#line 137 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("declaration list", 1);	// printable
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2172 "src/syntax.tab.c"
    break;

  case 4: /* declaration_list: decl  */
#line 143 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("declaration list", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2182 "src/syntax.tab.c"
    break;

  case 5: /* decl: var_declaration  */
#line 151 "src/syntax.y"
                       {
		(yyval.ast) = createAstNode("decl", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2192 "src/syntax.tab.c"
    break;

  case 6: /* decl: func_definition  */
#line 156 "src/syntax.y"
                         {
		(yyval.ast) = createAstNode("decl", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2202 "src/syntax.tab.c"
    break;

  case 7: /* decl: ';'  */
#line 161 "src/syntax.y"
             {
		(yyval.ast) = createAstNode("decl", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2211 "src/syntax.tab.c"
    break;

  case 8: /* decl: error  */
#line 165 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2221 "src/syntax.tab.c"
    break;

  case 9: /* var_definition: SIMPLE_TYPE ID  */
#line 173 "src/syntax.y"
                      {
		//char concat_type[200];
		int var_type = 2;	// parameter
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, (yyvsp[-1].lexeme).lexeme_string, var_type, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, (yyvsp[0].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode("var definition", 1);
		//strcpy(concat_type, $1.lexeme_string);
		//strcat(concat_type, " ");
		//strcat(concat_type, $2.lexeme_string);
		//$$->token_name = strdup(concat_type);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2241 "src/syntax.tab.c"
    break;

  case 10: /* var_definition: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 188 "src/syntax.y"
                                      {
		char concat_type[15];
		int var_type = 2;	// parameter
		strcpy(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, concat_type, var_type, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, (yyvsp[0].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode("var definition", 1);
		//strcat(concat_type, " ");
		//strcat(concat_type, $3.lexeme_string);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup(concat_type);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2262 "src/syntax.tab.c"
    break;

  case 11: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 207 "src/syntax.y"
                          {
		//char concat_type[200];
		int var_type = 1;
		insertSymbol(&symbolTable, (yyvsp[-1].lexeme).lexeme_string, (yyvsp[-2].lexeme).lexeme_string, var_type, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, (yyvsp[-1].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode("var declaration", 1);
		//strcpy(concat_type, $1.lexeme_string);
		//strcat(concat_type, " ");
		//strcat(concat_type, $2.lexeme_string);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup((yyvsp[-2].lexeme).lexeme_string);
		(yyval.ast)->token_line = (yyvsp[-1].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-1].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2281 "src/syntax.tab.c"
    break;

  case 12: /* var_declaration: SIMPLE_TYPE COMPOUND_TYPE ID ';'  */
#line 221 "src/syntax.y"
                                          {
		char concat_type[15];
		int var_type = 1;
		strcpy(concat_type, (yyvsp[-3].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		insertSymbol(&symbolTable, (yyvsp[-1].lexeme).lexeme_string, concat_type, var_type, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, (yyvsp[-1].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode("var declaration", 1);
		//strcat(concat_type, " ");
		//strcat(concat_type, $3.lexeme_string);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup(concat_type);
		(yyval.ast)->token_line = (yyvsp[-1].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-1].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2302 "src/syntax.tab.c"
    break;

  case 13: /* $@1: %empty  */
#line 240 "src/syntax.y"
                             {
		func_context = 1;
		insertScope(++last_scope, &contextList);
	}
#line 2311 "src/syntax.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 243 "src/syntax.y"
                     {
		;
	}
#line 2319 "src/syntax.tab.c"
    break;

  case 15: /* func_definition: func_declaration '(' $@1 params.opt $@2 ')' stmts  */
#line 245 "src/syntax.y"
                    {
		(yyval.ast) = createAstNode("function definition", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-6].ast);
		(yyval.ast)->children[1] = (yyvsp[-3].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
		removeScope(&contextList);
	}
#line 2332 "src/syntax.tab.c"
    break;

  case 16: /* params.opt: param_list  */
#line 256 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("params optional", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2342 "src/syntax.tab.c"
    break;

  case 17: /* params.opt: %empty  */
#line 261 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("params optional empty", DEBUG_AST); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2351 "src/syntax.tab.c"
    break;

  case 18: /* func_declaration: SIMPLE_TYPE ID  */
#line 268 "src/syntax.y"
                      {
		//char concat_type[200];
		int func_type = 0;
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, (yyvsp[-1].lexeme).lexeme_string, func_type, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, (yyvsp[0].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode("function declaration", 1);
		//strcpy(concat_type, $1.lexeme_string);
		//strcat(concat_type, " ");
		//strcat(concat_type, $2.lexeme_string);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup((yyvsp[-1].lexeme).lexeme_string);
		if(strcmp((yyvsp[-1].lexeme).lexeme_string, "int") == 0)
			check_func_type = 1;
		else
			check_func_type = 2;
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2374 "src/syntax.tab.c"
    break;

  case 19: /* func_declaration: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 286 "src/syntax.y"
                                      {
		char concat_type[15];
		int func_type = 0;
		strcpy(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, concat_type, func_type, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, (yyvsp[0].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode("function declaration", 1);
		//strcat(concat_type, " ");
		//strcat(concat_type, $3.lexeme_string);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup(concat_type);
		if(strcmp((yyvsp[-2].lexeme).lexeme_string, "int") == 0)
			check_func_type = 3;
		else
			check_func_type = 4;
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2399 "src/syntax.tab.c"
    break;

  case 20: /* param_list: param  */
#line 309 "src/syntax.y"
             {
		(yyval.ast) = createAstNode("param list", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2409 "src/syntax.tab.c"
    break;

  case 21: /* param_list: param_list ',' param  */
#line 314 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("param list", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2420 "src/syntax.tab.c"
    break;

  case 22: /* param_list: error  */
#line 320 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2430 "src/syntax.tab.c"
    break;

  case 23: /* param: var_definition  */
#line 328 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("param", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
		setupParameters(&symbolTable);
	}
#line 2441 "src/syntax.tab.c"
    break;

  case 24: /* stmts: '{' stmt_list.opt '}'  */
#line 337 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("stmts", 1);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2451 "src/syntax.tab.c"
    break;

  case 25: /* stmt_list.opt: stmt_list  */
#line 345 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list optional", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2461 "src/syntax.tab.c"
    break;

  case 26: /* stmt_list.opt: %empty  */
#line 350 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list empty", DEBUG_AST); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2470 "src/syntax.tab.c"
    break;

  case 27: /* stmt_list: stmt_list stmt.item  */
#line 357 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("stmt list", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2481 "src/syntax.tab.c"
    break;

  case 28: /* stmt_list: stmt.item  */
#line 363 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt list", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2491 "src/syntax.tab.c"
    break;

  case 29: /* stmt.item: stmt  */
#line 371 "src/syntax.y"
            {
		(yyval.ast) = createAstNode("stmt item", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2501 "src/syntax.tab.c"
    break;

  case 30: /* stmt.item: var_declaration  */
#line 376 "src/syntax.y"
                         {
		(yyval.ast) = createAstNode("stmt item", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2511 "src/syntax.tab.c"
    break;

  case 31: /* stmt: return_stmt  */
#line 384 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2521 "src/syntax.tab.c"
    break;

  case 32: /* stmt: select_stmt  */
#line 389 "src/syntax.y"
                     {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2531 "src/syntax.tab.c"
    break;

  case 33: /* stmt: iter_stmt  */
#line 394 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2541 "src/syntax.tab.c"
    break;

  case 34: /* stmt: io_stmt  */
#line 399 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2551 "src/syntax.tab.c"
    break;

  case 35: /* stmt: exp_stmt  */
#line 404 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2561 "src/syntax.tab.c"
    break;

  case 36: /* stmt: ';'  */
#line 409 "src/syntax.y"
             {
		(yyval.ast) = createAstNode("stmt", 1);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2570 "src/syntax.tab.c"
    break;

  case 37: /* stmt: stmts  */
#line 413 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2580 "src/syntax.tab.c"
    break;

  case 38: /* select_stmt: IF '(' simple_exp ')' stmt  */
#line 421 "src/syntax.y"
                                             {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2591 "src/syntax.tab.c"
    break;

  case 39: /* select_stmt: IF '(' simple_exp ')' stmt ELSE stmt  */
#line 427 "src/syntax.y"
                                              {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-4].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2603 "src/syntax.tab.c"
    break;

  case 40: /* iter_stmt: FOR '(' exp ';' simple_exp ';' exp ')' stmt  */
#line 437 "src/syntax.y"
                                                   {
		(yyval.ast) = createAstNode("iter stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-6].ast);
		(yyval.ast)->children[1] = (yyvsp[-4].ast);
		(yyval.ast)->children[2] = (yyvsp[-2].ast);
		(yyval.ast)->children[3] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2616 "src/syntax.tab.c"
    break;

  case 41: /* exp_stmt: exp ';'  */
#line 448 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("expression", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2626 "src/syntax.tab.c"
    break;

  case 42: /* exp: assign_exp  */
#line 456 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("exp stmt", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2636 "src/syntax.tab.c"
    break;

  case 43: /* exp: simple_exp  */
#line 461 "src/syntax.y"
                    {
		(yyval.ast) = createAstNode("exp stmt", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2646 "src/syntax.tab.c"
    break;

  case 44: /* return_stmt: RETURN exp ';'  */
#line 469 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("return stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
		//checkType($$, $1.line, $1.column, &semantic_errors);
	}
#line 2657 "src/syntax.tab.c"
    break;

  case 45: /* io_stmt: in_stmt  */
#line 478 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("in/out stmt", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2667 "src/syntax.tab.c"
    break;

  case 46: /* io_stmt: out_stmt  */
#line 483 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("in/out stmt", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2677 "src/syntax.tab.c"
    break;

  case 47: /* in_stmt: INPUT '(' ID ')' ';'  */
#line 491 "src/syntax.y"
                            {
		char input_type[200];
		char id_type[15];
		strcpy(id_type, getContext(&symbolTable, &contextList, (yyvsp[-2].lexeme).lexeme_string, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("input stmt", 1);
		strcpy(input_type, (yyvsp[-4].lexeme).lexeme_string);
		strcat(input_type, "(");
		strcat(input_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(input_type, ")");
		(yyval.ast)->token_name = strdup(input_type);
		//$$->token_type = strdup(id_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2695 "src/syntax.tab.c"
    break;

  case 48: /* out_stmt: OUTPUT '(' STRING ')' ';'  */
#line 507 "src/syntax.y"
                                 {
		char output_type[200];
		(yyval.ast) = createAstNode("output stmt", 1);
		strcpy(output_type, (yyvsp[-4].lexeme).lexeme_string);
		strcat(output_type, "(");
		strcat(output_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(output_type, ")");
		(yyval.ast)->token_name = strdup(output_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2710 "src/syntax.tab.c"
    break;

  case 49: /* out_stmt: OUTPUT '(' exp ')' ';'  */
#line 517 "src/syntax.y"
                                {
		char output_type[200];
		(yyval.ast) = createAstNode("output stmt", 1);
		strcpy(output_type, (yyvsp[-4].lexeme).lexeme_string);
		strcat(output_type, "()");
		(yyval.ast)->token_name = strdup(output_type);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2724 "src/syntax.tab.c"
    break;

  case 50: /* assign_exp: ID '=' exp  */
#line 529 "src/syntax.y"
                  {
		char id_type[15];
		strcpy(id_type, getContext(&symbolTable, &contextList, (yyvsp[-2].lexeme).lexeme_string, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("assign exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-2].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup(id_type);
		(yyval.ast)->token_line = (yyvsp[-2].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-2].lexeme).column;
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
		//checkType($$, $1.line, $1.column, &semantic_errors);
	}
#line 2741 "src/syntax.tab.c"
    break;

  case 51: /* simple_exp: simple_exp LOGICAL_OR and_exp  */
#line 544 "src/syntax.y"
                                     {
		(yyval.ast) = createAstNode("simple exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2753 "src/syntax.tab.c"
    break;

  case 52: /* simple_exp: and_exp  */
#line 551 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("simple exp", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2763 "src/syntax.tab.c"
    break;

  case 53: /* simple_exp: error  */
#line 556 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2773 "src/syntax.tab.c"
    break;

  case 54: /* and_exp: and_exp LOGICAL_AND rel_exp  */
#line 564 "src/syntax.y"
                                   {
		(yyval.ast) = createAstNode("and exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2785 "src/syntax.tab.c"
    break;

  case 55: /* and_exp: rel_exp  */
#line 571 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("and exp", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2795 "src/syntax.tab.c"
    break;

  case 56: /* rel_exp: rel_exp RELATIONAL list_exp  */
#line 579 "src/syntax.y"
                                   {
		(yyval.ast) = createAstNode("rel exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2807 "src/syntax.tab.c"
    break;

  case 57: /* rel_exp: list_exp  */
#line 586 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("rel exp", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2817 "src/syntax.tab.c"
    break;

  case 58: /* list_exp: sum_exp LIST_CONSTR list_exp  */
#line 594 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("list exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2829 "src/syntax.tab.c"
    break;

  case 59: /* list_exp: sum_exp LIST_FUNC list_exp  */
#line 601 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("list exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2841 "src/syntax.tab.c"
    break;

  case 60: /* list_exp: sum_exp  */
#line 608 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("list exp", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2851 "src/syntax.tab.c"
    break;

  case 61: /* sum_exp: sum_exp ADD mul_exp  */
#line 616 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("sum exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2863 "src/syntax.tab.c"
    break;

  case 62: /* sum_exp: mul_exp  */
#line 623 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("sum exp", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2873 "src/syntax.tab.c"
    break;

  case 63: /* mul_exp: mul_exp MUL unary_exp  */
#line 631 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("mul exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2885 "src/syntax.tab.c"
    break;

  case 64: /* mul_exp: unary_exp  */
#line 638 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("mul exp", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2895 "src/syntax.tab.c"
    break;

  case 65: /* unary_exp: factor  */
#line 646 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("unary exp", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2905 "src/syntax.tab.c"
    break;

  case 66: /* unary_exp: LIST_OP unary_exp  */
#line 651 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2916 "src/syntax.tab.c"
    break;

  case 67: /* unary_exp: LIST_DESTR unary_exp  */
#line 657 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2927 "src/syntax.tab.c"
    break;

  case 68: /* unary_exp: OP_OVERLOAD unary_exp  */
#line 663 "src/syntax.y"
                               {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2938 "src/syntax.tab.c"
    break;

  case 69: /* unary_exp: ADD unary_exp  */
#line 669 "src/syntax.y"
                       {
		char signal_type[100];
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
#line 2955 "src/syntax.tab.c"
    break;

  case 70: /* factor: ID  */
#line 684 "src/syntax.y"
          {
		char id_type[15];
		strcpy(id_type, getContext(&symbolTable, &contextList, (yyvsp[0].lexeme).lexeme_string, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("factor exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup(id_type);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2970 "src/syntax.tab.c"
    break;

  case 71: /* factor: '(' simple_exp ')'  */
#line 694 "src/syntax.y"
                            {
		(yyval.ast) = createAstNode("factor exp", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2980 "src/syntax.tab.c"
    break;

  case 72: /* factor: func_call  */
#line 699 "src/syntax.y"
                   {
		(yyval.ast) = createAstNode("factor exp", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2990 "src/syntax.tab.c"
    break;

  case 73: /* factor: constant  */
#line 704 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("factor exp", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 3000 "src/syntax.tab.c"
    break;

  case 74: /* $@3: %empty  */
#line 712 "src/syntax.y"
               {
		;
	}
#line 3008 "src/syntax.tab.c"
    break;

  case 75: /* func_call: ID '(' $@3 func_params ')'  */
#line 714 "src/syntax.y"
                         {
		char func_id[200];
		char func_type[15];
		strcpy(func_type, getContext(&symbolTable, &contextList, (yyvsp[-4].lexeme).lexeme_string, (yyvsp[-4].lexeme).line, (yyvsp[-4].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("func call", 1);
		strcpy(func_id, (yyvsp[-4].lexeme).lexeme_string);
		strcat(func_id, "()");
		(yyval.ast)->token_name = strdup(func_id);
		(yyval.ast)->token_type = strdup(func_type);
		(yyval.ast)->token_line = (yyvsp[-4].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-4].lexeme).column;
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 3027 "src/syntax.tab.c"
    break;

  case 76: /* func_call: ID '(' ')'  */
#line 728 "src/syntax.y"
                    {
		char func_id[200];
		char func_type[15];
		strcpy(func_type, getContext(&symbolTable, &contextList, (yyvsp[-2].lexeme).lexeme_string, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("func call", 1);
		strcpy(func_id, (yyvsp[-2].lexeme).lexeme_string);
		strcat(func_id, "()");
		(yyval.ast)->token_name = strdup(func_id);
		(yyval.ast)->token_type = strdup(func_type);
		(yyval.ast)->token_line = (yyvsp[-2].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-2].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3045 "src/syntax.tab.c"
    break;

  case 77: /* func_params: simple_exp  */
#line 744 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("func params", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 3055 "src/syntax.tab.c"
    break;

  case 78: /* func_params: func_params ',' simple_exp  */
#line 749 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("func params", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 3066 "src/syntax.tab.c"
    break;

  case 79: /* constant: INTEGER  */
#line 758 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("int constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup("\0");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3079 "src/syntax.tab.c"
    break;

  case 80: /* constant: REAL  */
#line 766 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("real constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup("\0");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3092 "src/syntax.tab.c"
    break;

  case 81: /* constant: NIL_CONSTANT  */
#line 774 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("nil constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup("\0");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3105 "src/syntax.tab.c"
    break;


#line 3109 "src/syntax.tab.c"

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

#line 784 "src/syntax.y"


void yyerror(const char *error_msg){
	int column = num_chars - yylval.lexeme.length;
	printf("%sLine:%d\tColumn:%d\t%s%s\n", RED, num_lines, column, error_msg, WHITE);
	syntax_errors+= 1;
}


int main(int argc, char *argv[]){
	setupContext(&contextList);
	
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

	if(!hasMainFunction(&symbolTable)){
		printf("%sLine:?\tColumn:?\tSemantic error! Undefined reference to %s`main()`%s function.%s\n", RED, PURPLE, RED, WHITE);
		semantic_errors+= 1;
	}

	if(syntax_errors == 0 && semantic_errors == 0)
		printAST(&root);
	else
		printf("%s~> AST tree will not be printed, due to syntax or semantic error(s).%s\n", RED, WHITE);

	printTable(&symbolTable);

	if(syntax_errors == 0)
		printf("\n%sSyntax analysis finished without error(s).%s\n", GREEN, WHITE);
	else
		printf("%sSyntax analysis finished with %d error(s).%s\n", RED, syntax_errors, WHITE);

	if(semantic_errors == 0)
		printf("%sSemantic analysis finished without error(s).%s\n", GREEN, WHITE);
	else
		printf("%sSemantic analysis finished with %d error(s).%s\n", RED, semantic_errors, WHITE);

	printParams(&symbolTable);

	freeNode(&root);
	freeSymbols(&symbolTable);
	freeContextList(&contextList);
	yylex_destroy();
	return 0;
}

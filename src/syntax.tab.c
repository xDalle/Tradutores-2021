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
	#define BLUE "\x1b[36m"
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
	int func_params_counter = 0;
	extern Ast root;
	extern AstList astList;
	extern Table symbolTable;
	extern Context contextList;

#line 104 "src/syntax.tab.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2928

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  279

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
       0,   128,   128,   139,   145,   154,   160,   166,   174,   189,
     211,   226,   248,   251,   248,   264,   269,   276,   295,   321,
     327,   333,   341,   351,   360,   365,   372,   378,   387,   393,
     402,   408,   414,   420,   426,   432,   441,   447,   457,   468,
     477,   483,   492,   501,   507,   516,   532,   542,   554,   569,
     576,   582,   590,   597,   606,   613,   622,   629,   636,   645,
     652,   661,   668,   677,   683,   689,   695,   701,   716,   726,
     732,   738,   747,   747,   764,   781,   788,   798,   806,   814
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

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    17,   230,    20,    24,   181,   482,   556,    35,    58,
      46,  -180,   592,    39,   180,   665,    69,   667,    -6,   336,
      -5,    48,   126,   288,   119,   303,   114,   202,   377,   191,
     445,  1717,   669,    37,  2865,    34,    86,   199,   218,   422,
     228,   256,   421,    27,   232,  2865,  2865,  2865,  2539,  1748,
    1779,   251,  1810,  1841,  1872,  1903,  1934,  1965,   257,  1996,
    2027,  2058,  2089,   270,    52,   116,    96,   110,   250,   295,
     339,   341,   485,   511,    60,   547,  2539,   422,   290,   299,
    2503,   322,   363,   858,   422,   652,   688,   751,    66,   678,
    2120,  2151,  2865,  2865,  2865,  2865,  2865,  2865,  2865,   135,
     366,  2182,   325,   370,   380,   387,   758,  2562,   399,   791,
     275,   120,   198,   801,   215,   221,   825,  2461,  2571,   406,
     410,   426,    44,   467,  1190,    85,  2213,  2244,  2275,   835,
    2562,  2482,  2594,   178,  2306,   418,  2482,  2337,  1717,   140,
    2888,  2640,  2657,  2623,  2663,  2888,  2888,  2888,  2539,   200,
     333,   458,   103,  2680,  2697,  2703,  2720,  2737,  2601,   432,
     347,  2368,  2888,  2399,   287,  2897,   922,   954,   916,   960,
    2897,  2897,  2897,  2539,   398,   263,   281,  1160,   977,   994,
    1000,  1017,  1034,   436,   449,   422,   465,   471,  1717,  1221,
    1252,  1283,  1314,   441,  1345,  1376,  1407,  1438,  2897,   475,
    2743,   881,  2760,  2777,  2783,   385,  2888,  2888,  2888,  2888,
    2888,  2888,  2594,   382,  1040,   890,  1057,  1074,  1080,   397,
    2897,  2897,  2897,  2897,  2897,  2897,  2539,   422,   474,   489,
    2530,   483,  1469,   565,  2430,  2800,  2562,  2817,   517,   536,
    2823,   588,   641,  2840,   494,  1097,  2562,  1114,   304,   343,
    1120,   392,   504,  1137,   401,   486,  1500,   500,   507,   516,
    1531,   497,   503,  2461,  2571,   525,   539,   548,  2857,  1154,
    1562,   109,  1593,  1624,  1655,  2594,   520,  2461,  1686
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
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,  -180,   538,  -180,   214,  -180,  -180,  -180,  -180,
    -180,  -180,   557,   -29,  -133,  -180,   535,  -115,  -114,  -113,
    -111,   -32,  -109,  -107,  -106,   -94,   -71,   368,   605,   570,
     355,   510,   415,   -33,    54,   161,  -179,  -150,   248
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    20,    49,     7,    16,    26,    21,
       8,    22,    23,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,   107,   123,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    75,   124,   190,   191,   199,   192,    78,   194,   159,
     195,   196,    85,    86,    87,   154,   134,    -7,    -7,     1,
      11,   137,   236,   197,    -2,     1,   -21,   -22,   -21,   -22,
     -68,   -68,    -7,     2,   -68,   -68,   246,   -77,   -77,     2,
     -12,   -77,   -77,   154,   -51,   100,   -68,   154,   104,   -68,
     -68,   198,   108,   -77,   -12,   231,   -77,   -77,    83,    92,
      84,   159,   -68,   -68,   -68,   116,    13,   -68,   -68,   -77,
      18,   -12,   -51,   162,   179,    14,   -75,   -17,   -75,   -68,
     -13,    15,   -68,   -68,    19,   193,   261,   -41,   189,   -78,
     -78,    83,    92,   -78,   -78,   -68,   262,   179,   109,   154,
     135,   -16,   155,   -53,   -53,   -78,   208,   200,   -78,   -78,
     -58,   -58,   202,   203,   204,   154,    92,   -55,   -55,    94,
     132,   -78,   209,   -50,    93,   210,   -58,   -52,   -52,   154,
     155,   -53,   214,   -55,   155,   -58,    28,   216,   217,   218,
     154,   159,   162,    94,   275,   -55,    29,   -51,   270,   190,
     191,   -50,   192,   228,   194,   -52,   195,   196,   -15,   159,
      27,   180,   278,   190,   191,   179,   192,   117,   194,   197,
     195,   196,   -51,   154,   154,   154,   154,   154,   243,   154,
     244,    -4,    -4,   197,   180,   198,   155,   179,   179,   179,
     179,   179,   253,   154,   155,   255,    -4,   154,   259,   155,
     155,   155,   155,   179,   159,   -54,   -54,   -50,   206,   156,
     -76,   -18,   -76,   179,     6,    17,   155,    19,     6,   180,
      31,   -54,   -56,   -56,   180,   180,   180,   155,   -57,   -57,
      76,   193,   -50,   -54,   189,   -79,   -79,   156,   -56,   -79,
     -79,   156,   154,   276,   -57,   193,     9,    10,   189,    77,
     -56,   -79,   180,    95,   -79,   -79,   -57,   -58,   -58,    79,
     155,   155,   155,   155,   155,   155,   155,   -79,   181,    96,
     -53,   -53,    97,   -58,   180,   180,   180,   180,   180,   180,
     155,    89,   -49,    93,   155,   -58,   221,    80,   -55,   -55,
     180,   181,    91,   156,   -51,   -53,   157,   -53,   -60,    98,
     180,   156,   -60,   -60,   -55,   -40,   156,   156,   156,   156,
     -49,   -52,   -52,   -55,   -60,   -55,   102,   -60,   -60,   -51,
     -19,   -51,   -19,   156,   157,   101,   181,   221,   157,   155,
     -60,   181,   181,   181,   156,    -8,   -52,    -8,   -52,   105,
     -53,   -53,   -62,   -62,   -63,   -63,   -62,   -62,   -63,   -63,
     -54,   -54,    24,    25,   162,   182,   207,   119,   -62,   181,
     -63,   -62,   -62,   -63,   -63,   -53,   -54,   156,   156,   156,
     156,   156,   156,   156,   -62,   -54,   -63,   -54,   182,   -41,
     157,   181,   181,   181,   181,   181,   181,   156,   157,   -49,
     206,   156,   162,   157,   157,   157,   157,   181,   161,   -56,
     -56,   118,   120,   151,   162,   -50,   220,   181,   162,    -9,
     157,    -9,   121,   182,   -49,   -56,    88,   237,   182,   182,
     182,   157,   163,    33,   -56,    34,   -56,    35,    36,   247,
     -50,   151,   -50,   263,   -48,   151,   156,    81,    82,    43,
      44,   126,    45,    46,    99,   127,   182,    47,   160,   112,
     136,   114,   115,    48,   157,   157,   157,   157,   157,   157,
     157,   128,   176,   153,   -40,   -55,   -55,   226,   182,   182,
     182,   182,   182,   182,   157,   122,   232,   -20,   157,   -20,
     227,   -55,    -5,    -5,   182,   176,   125,   151,   -70,   -70,
     -55,   153,   -70,   -70,   182,   153,   229,    -5,   133,   129,
     160,   130,   230,   151,   -70,   234,   257,   -70,   -70,   256,
     113,   -57,   -57,   260,   -71,   -71,   205,   151,   -71,   -71,
     -70,   264,   178,   157,   -52,   -52,   -48,   -57,   151,   268,
     -71,   130,   265,   -71,   -71,   269,   -57,   130,   -57,   266,
     207,   219,    12,   -54,   -54,   178,   -71,   153,   267,   -52,
     -67,   -67,   277,   176,   -67,   -67,    -6,    -6,   152,   -54,
     272,   151,   239,   153,   241,   242,   -67,   151,   -54,   -67,
     -67,    -6,   -49,   220,   273,   176,   249,   153,   251,   252,
     160,   151,   -67,   274,    30,   151,   152,    90,   153,     0,
     152,   176,    -3,    -3,   254,   -56,   -56,   -49,   160,   -49,
       0,   176,     0,     0,   122,     0,     0,    -3,     0,     0,
       0,   -56,     0,   178,   122,     0,     0,   177,   150,     0,
     -56,   153,   153,   240,   153,   153,     0,   153,     0,     0,
     151,     0,   271,     0,     0,   178,   178,   250,   178,   178,
     177,   153,   152,   160,     0,   153,   150,     0,   -57,   -57,
     150,   178,     0,   149,     0,   -64,   -64,     0,   152,   -64,
     -64,   178,     0,   111,   -57,   -10,   -10,   -11,   -11,   -14,
     -14,   -64,   152,   -57,   -64,   -64,     0,   175,   -23,   -23,
     -10,   149,   -11,   152,   -14,   149,     0,   -64,     0,     0,
     153,   -65,   -65,   -23,     0,   -65,   -65,   110,     0,     0,
     175,     0,   150,     0,     0,     0,     0,   -65,   177,     0,
     -65,   -65,   174,     0,     0,     0,   152,   152,   150,   152,
     152,     0,   152,   -65,     0,     0,     0,     0,     0,     0,
     177,   177,   150,   177,   177,   174,   152,   149,     0,     0,
     152,     0,     0,   150,     0,     0,   177,     0,     0,     0,
       0,     0,     0,   149,   -66,   -66,   177,     0,   -66,   -66,
       0,   -74,   -74,     0,     0,   -74,   -74,   213,   175,     0,
     -66,     0,     0,   -66,   -66,     0,   238,   -74,   149,     0,
     -74,   -74,   150,     0,     0,   152,   -66,     0,     0,     0,
     248,     0,     0,   -74,   -69,   -69,   150,     0,   -69,   -69,
     150,     0,     0,   233,   -59,    98,   175,     0,   -59,   -59,
     -69,     0,     0,   -69,   -69,     0,   175,   149,     0,     0,
     -59,     0,     0,   -59,   -59,     0,   -69,     0,   -61,   -61,
       0,   149,   -61,   -61,     0,   149,   -59,     0,   -73,   -73,
       0,   174,   -73,   -73,   -61,   150,     0,   -61,   -61,     0,
       0,   174,     0,     0,   -73,     0,     0,   -73,   -73,   -72,
     -61,   -72,     0,   -72,   -72,     0,     0,     0,     0,     0,
     -73,     0,     0,     0,     0,   -72,   -72,     0,   -72,   -72,
     149,     0,   -72,   -72,   -72,     0,   -72,   -72,     0,   -72,
     106,   -72,     0,   -72,     0,   -72,   -72,     0,   -72,   -72,
       0,   -72,   -72,     0,     0,     0,   -72,   -72,   -72,     0,
     -72,   -72,   -72,   235,     0,   -72,     0,     0,     0,   -68,
     -68,   -72,   245,   -68,   -68,   -77,   -77,     0,     0,   -77,
     -77,     0,     0,     0,     0,   -68,     0,     0,   -68,   -68,
       0,   -77,     0,     0,   -77,   -77,     0,   215,   -68,     0,
     -68,     0,     0,     0,   -77,     0,   -77,   -78,   -78,     0,
       0,   -78,   -78,   -79,   -79,     0,     0,   -79,   -79,     0,
       0,     0,     0,   -78,     0,     0,   -78,   -78,     0,   -79,
     -60,   225,   -79,   -79,   -60,   -60,   -78,     0,   -78,     0,
       0,     0,   -79,     0,   -79,     0,   -60,   -62,   -62,   -60,
     -60,   -62,   -62,   -63,   -63,     0,     0,   -63,   -63,   -60,
       0,   -60,     0,   -62,     0,     0,   -62,   -62,     0,   -63,
     -70,   -70,   -63,   -63,   -70,   -70,   -62,     0,   -62,     0,
       0,     0,   -63,     0,   -63,     0,   -70,   -71,   -71,   -70,
     -70,   -71,   -71,   -67,   -67,     0,     0,   -67,   -67,   -70,
       0,   -70,     0,   -71,     0,     0,   -71,   -71,     0,   -67,
     -64,   -64,   -67,   -67,   -64,   -64,   -71,     0,   -71,     0,
       0,     0,   -67,     0,   -67,     0,   -64,   -65,   -65,   -64,
     -64,   -65,   -65,   -66,   -66,     0,     0,   -66,   -66,   -64,
       0,   -64,     0,   -65,     0,     0,   -65,   -65,     0,   -66,
     -74,   -74,   -66,   -66,   -74,   -74,   -65,     0,   -65,     0,
       0,     0,   -66,     0,   -66,     0,   -74,   -69,   -69,   -74,
     -74,   -69,   -69,   -59,   225,     0,     0,   -59,   -59,   -74,
       0,   -74,     0,   -69,     0,     0,   -69,   -69,     0,   -59,
     -61,   -61,   -59,   -59,   -61,   -61,   -69,     0,   -69,     0,
       0,     0,   -59,     0,   -59,     0,   -61,   -73,   -73,   -61,
     -61,   -73,   -73,   222,     0,     0,     0,   -58,   -58,   -61,
       0,   -61,     0,   -73,     0,     0,   -73,   -73,     0,   223,
       0,     0,   224,   -58,     0,     0,   -73,     0,   -73,     0,
       0,   -36,   -58,   -36,   -58,   -36,   -36,     0,     0,   -36,
     131,   -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,     0,
     -36,   -36,     0,     0,     0,   -36,     0,     0,     0,   -36,
     -36,   -36,   -35,     0,   -35,     0,   -35,   -35,     0,     0,
     -35,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,
       0,   -35,   -35,     0,     0,     0,   -35,     0,     0,     0,
     -35,   -35,   -35,   -31,     0,   -31,     0,   -31,   -31,     0,
       0,   -31,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,
     -31,     0,   -31,   -31,     0,     0,     0,   -31,     0,     0,
       0,   -31,   -31,   -31,   -32,     0,   -32,     0,   -32,   -32,
       0,     0,   -32,   -32,   -32,   -32,   -32,   -32,   -32,     0,
     -32,   -32,     0,   -32,   -32,     0,     0,     0,   -32,     0,
       0,     0,   -32,   -32,   -32,   -34,     0,   -34,     0,   -34,
     -34,     0,     0,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
       0,   -34,   -34,     0,   -34,   -34,     0,     0,     0,   -34,
       0,     0,     0,   -34,   -34,   -34,   -30,     0,   -30,     0,
     -30,   -30,     0,     0,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,     0,   -30,   -30,     0,   -30,   -30,     0,     0,     0,
     -30,     0,     0,     0,   -30,   -30,   -30,   -33,     0,   -33,
       0,   -33,   -33,     0,     0,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,     0,   -33,   -33,     0,   -33,   -33,     0,     0,
       0,   -33,     0,     0,     0,   -33,   -33,   -33,   -43,     0,
     -43,     0,   -43,   -43,     0,     0,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,     0,
       0,     0,   -43,     0,     0,     0,   -43,   -43,   -43,   -44,
       0,   -44,     0,   -44,   -44,     0,     0,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,
       0,     0,     0,   -44,     0,     0,     0,   -44,   -44,   -44,
     -39,     0,   -39,     0,   -39,   -39,     0,     0,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,     0,   -39,   -39,     0,   -39,
     -39,     0,     0,     0,   -39,     0,     0,     0,   -39,   -39,
     -39,   -42,     0,   -42,     0,   -42,   -42,     0,     0,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,     0,
     -42,   -42,     0,     0,     0,   -42,     0,     0,     0,   -42,
     -42,   -42,   -23,     0,   -23,     0,   -23,   -23,     0,     0,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,
       0,   -23,   -23,     0,     0,     0,   -23,     0,     0,     0,
     -23,   -23,   -23,   -36,     0,   -36,     0,   -36,   -36,     0,
       0,   -36,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,
     -36,     0,   -36,   -36,     0,     0,     0,   -36,     0,     0,
       0,   -36,   -36,   -36,   -45,     0,   -45,     0,   -45,   -45,
       0,     0,   -45,   -45,   -45,   -45,   -45,   -45,   -45,     0,
     -45,   -45,     0,   -45,   -45,     0,     0,     0,   -45,     0,
       0,     0,   -45,   -45,   -45,   -46,     0,   -46,     0,   -46,
     -46,     0,     0,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
       0,   -46,   -46,     0,   -46,   -46,     0,     0,     0,   -46,
       0,     0,     0,   -46,   -46,   -46,   -47,     0,   -47,     0,
     -47,   -47,     0,     0,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,     0,   -47,   -47,     0,   -47,   -47,     0,     0,     0,
     -47,     0,     0,     0,   -47,   -47,   -47,   -38,     0,   -38,
       0,   -38,   -38,     0,     0,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,     0,   -38,   -38,     0,   -38,   -38,     0,     0,
       0,   -38,     0,     0,     0,   -38,   -38,   -38,    33,     0,
      34,     0,    35,    36,     0,     0,    37,     0,    38,    39,
      40,    41,    42,     0,    43,    44,     0,    45,    46,     0,
       0,     0,    47,     0,     0,     0,   138,   -25,    48,   -29,
       0,   -29,     0,   -29,   -29,     0,     0,   -29,     0,   -29,
     -29,   -29,   -29,   -29,     0,   -29,   -29,     0,   -29,   -29,
       0,     0,     0,   -29,     0,     0,     0,   -29,   -29,   -29,
     -35,     0,   -35,     0,   -35,   -35,     0,     0,   -35,     0,
     -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,     0,   -35,
     -35,     0,     0,     0,   -35,     0,     0,     0,   -35,   -35,
     -35,    33,     0,    34,     0,    35,    36,     0,     0,    37,
       0,    38,    39,    40,    41,    42,     0,    43,    44,     0,
      45,    46,     0,     0,     0,    47,     0,     0,     0,   138,
     -24,    48,   -27,     0,   -27,     0,   -27,   -27,     0,     0,
     -27,     0,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,
       0,   -27,   -27,     0,     0,     0,   -27,     0,     0,     0,
     -27,   -27,   -27,   -28,     0,   -28,     0,   -28,   -28,     0,
       0,   -28,     0,   -28,   -28,   -28,   -28,   -28,     0,   -28,
     -28,     0,   -28,   -28,     0,     0,     0,   -28,     0,     0,
       0,   -28,   -28,   -28,   -31,     0,   -31,     0,   -31,   -31,
       0,     0,   -31,     0,   -31,   -31,   -31,   -31,   -31,     0,
     -31,   -31,     0,   -31,   -31,     0,     0,     0,   -31,     0,
       0,     0,   -31,   -31,   -31,   -32,     0,   -32,     0,   -32,
     -32,     0,     0,   -32,     0,   -32,   -32,   -32,   -32,   -32,
       0,   -32,   -32,     0,   -32,   -32,     0,     0,     0,   -32,
       0,     0,     0,   -32,   -32,   -32,   -34,     0,   -34,     0,
     -34,   -34,     0,     0,   -34,     0,   -34,   -34,   -34,   -34,
     -34,     0,   -34,   -34,     0,   -34,   -34,     0,     0,     0,
     -34,     0,     0,     0,   -34,   -34,   -34,   -30,     0,   -30,
       0,   -30,   -30,     0,     0,   -30,     0,   -30,   -30,   -30,
     -30,   -30,     0,   -30,   -30,     0,   -30,   -30,     0,     0,
       0,   -30,     0,     0,     0,   -30,   -30,   -30,   -33,     0,
     -33,     0,   -33,   -33,     0,     0,   -33,     0,   -33,   -33,
     -33,   -33,   -33,     0,   -33,   -33,     0,   -33,   -33,     0,
       0,     0,   -33,     0,     0,     0,   -33,   -33,   -33,   -43,
       0,   -43,     0,   -43,   -43,     0,     0,   -43,     0,   -43,
     -43,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,
       0,     0,     0,   -43,     0,     0,     0,   -43,   -43,   -43,
     -44,     0,   -44,     0,   -44,   -44,     0,     0,   -44,     0,
     -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,
     -44,     0,     0,     0,   -44,     0,     0,     0,   -44,   -44,
     -44,   -26,     0,   -26,     0,   -26,   -26,     0,     0,   -26,
       0,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,     0,
     -26,   -26,     0,     0,     0,   -26,     0,     0,     0,   -26,
     -26,   -26,   -39,     0,   -39,     0,   -39,   -39,     0,     0,
     -39,     0,   -39,   -39,   -39,   -39,   -39,     0,   -39,   -39,
       0,   -39,   -39,     0,     0,     0,   -39,     0,     0,     0,
     -39,   -39,   -39,   -42,     0,   -42,     0,   -42,   -42,     0,
       0,   -42,     0,   -42,   -42,   -42,   -42,   -42,     0,   -42,
     -42,     0,   -42,   -42,     0,     0,     0,   -42,     0,     0,
       0,   -42,   -42,   -42,   -45,     0,   -45,     0,   -45,   -45,
       0,     0,   -45,     0,   -45,   -45,   -45,   -45,   -45,     0,
     -45,   -45,     0,   -45,   -45,     0,     0,     0,   -45,     0,
       0,     0,   -45,   -45,   -45,   -46,     0,   -46,     0,   -46,
     -46,     0,     0,   -46,     0,   -46,   -46,   -46,   -46,   -46,
       0,   -46,   -46,     0,   -46,   -46,     0,     0,     0,   -46,
       0,     0,     0,   -46,   -46,   -46,   -47,     0,   -47,     0,
     -47,   -47,     0,     0,   -47,     0,   -47,   -47,   -47,   -47,
     -47,     0,   -47,   -47,     0,   -47,   -47,     0,     0,     0,
     -47,     0,     0,     0,   -47,   -47,   -47,   -37,     0,   -37,
       0,   -37,   -37,     0,     0,   -37,     0,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,     0,   -37,   -37,     0,     0,
       0,   -37,     0,     0,     0,   -37,   -37,   -37,   -38,     0,
     -38,     0,   -38,   -38,     0,     0,   -38,     0,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,     0,
       0,     0,   -38,     0,     0,     0,   -38,   -38,   -38,   -10,
       0,   -10,     0,   -10,   -10,     0,     0,   -10,     0,   -10,
     -10,   -10,   -10,   -10,     0,   -10,   -10,     0,   -10,   -10,
       0,     0,     0,   -10,     0,     0,     0,   -10,   -10,   -10,
     -11,     0,   -11,     0,   -11,   -11,     0,     0,   -11,     0,
     -11,   -11,   -11,   -11,   -11,     0,   -11,   -11,     0,   -11,
     -11,     0,     0,     0,   -11,     0,     0,     0,   -11,   -11,
     -11,   -23,     0,   -23,     0,   -23,   -23,     0,     0,   -23,
       0,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,     0,
     -23,   -23,     0,     0,     0,   -23,     0,     0,     0,   -23,
     -23,   -23,    33,     0,    34,     0,    35,    36,     0,     0,
     183,     0,   184,   185,   186,   187,     0,     0,    43,    44,
       0,    45,    46,    33,     0,    34,    47,    35,    36,     0,
     188,    37,    48,    38,    39,    40,    41,     0,     0,    43,
      44,     0,    45,    46,   139,     0,   140,    47,   141,   142,
       0,   138,     0,    48,     0,     0,     0,     0,     0,     0,
     158,   144,     0,   145,   146,     0,     0,   103,   147,     0,
       0,   139,     0,   140,   148,   141,   142,     0,     0,     0,
     139,     0,   140,     0,   141,   142,     0,   158,   144,     0,
     145,   146,     0,     0,   258,   147,   143,   144,     0,   145,
     146,   148,     0,   164,   147,   165,     0,   166,   167,     0,
     148,     0,    33,     0,    34,     0,    35,    36,     0,   168,
     169,     0,   170,   171,     0,     0,     0,   172,    74,    44,
       0,    45,    46,   173,     0,   139,    47,   140,     0,   141,
     142,     0,    48,     0,   -68,   -68,     0,     0,   -68,   -68,
       0,   158,   144,     0,   145,   146,     0,     0,     0,   147,
     -68,     0,     0,   -68,   -68,   148,   -68,   -68,     0,     0,
     -68,   -68,   201,   -68,   212,     0,     0,     0,     0,     0,
       0,     0,   -68,   -77,   -77,   -68,   -68,   -77,   -77,     0,
       0,     0,     0,     0,   201,   -68,     0,     0,     0,   -77,
     -78,   -78,   -77,   -77,   -78,   -78,   -79,   -79,     0,     0,
     -79,   -79,   -77,     0,     0,     0,   -78,     0,     0,   -78,
     -78,     0,   -79,   -60,   211,   -79,   -79,   -60,   -60,   -78,
       0,     0,     0,     0,     0,   -79,     0,     0,     0,   -60,
     -62,   -62,   -60,   -60,   -62,   -62,   -63,   -63,     0,     0,
     -63,   -63,   -60,     0,     0,     0,   -62,     0,     0,   -62,
     -62,     0,   -63,   -70,   -70,   -63,   -63,   -70,   -70,   -62,
       0,     0,     0,     0,     0,   -63,     0,     0,     0,   -70,
     -71,   -71,   -70,   -70,   -71,   -71,   -67,   -67,     0,     0,
     -67,   -67,   -70,     0,     0,     0,   -71,     0,     0,   -71,
     -71,     0,   -67,   -64,   -64,   -67,   -67,   -64,   -64,   -71,
       0,     0,     0,     0,     0,   -67,     0,     0,     0,   -64,
     -65,   -65,   -64,   -64,   -65,   -65,   -66,   -66,     0,     0,
     -66,   -66,   -64,     0,     0,     0,   -65,     0,     0,   -65,
     -65,     0,   -66,   -74,   -74,   -66,   -66,   -74,   -74,   -65,
       0,     0,     0,     0,     0,   -66,     0,     0,     0,   -74,
     -69,   -69,   -74,   -74,   -69,   -69,   -59,   211,     0,     0,
     -59,   -59,   -74,     0,     0,     0,   -69,     0,     0,   -69,
     -69,     0,   -59,   -61,   -61,   -59,   -59,   -61,   -61,   -69,
       0,     0,     0,     0,     0,   -59,     0,     0,     0,   -61,
     -73,   -73,   -61,   -61,   -73,   -73,     0,     0,    34,     0,
      35,    36,   -61,     0,     0,     0,   -73,     0,     0,   -73,
     -73,     0,    74,    44,     0,    45,    46,     0,     0,   -73,
      47,   140,     0,   141,   142,     0,    48,     0,     0,     0,
     165,     0,   166,   167,     0,   143,   144,     0,   145,   146,
       0,     0,     0,   147,   168,   169,     0,   170,   171,   148,
       0,     0,   172,     0,     0,     0,     0,     0,   173
};

static const yytype_int16 yycheck[] =
{
      29,    34,   117,   117,   117,   138,   117,    39,   117,    80,
     117,   117,    45,    46,    47,    48,   131,     0,     1,     1,
       0,   136,   201,   117,     0,     1,    32,    32,    34,    34,
       3,     4,    15,    15,     7,     8,   215,     3,     4,    15,
       1,     7,     8,    76,     7,    77,    19,    80,    80,    22,
      23,     7,    84,    19,    15,   188,    22,    23,    31,     7,
      33,   132,    35,     3,     4,    98,    31,     7,     8,    35,
       1,    32,    35,     7,   107,    17,    32,    31,    34,    19,
      32,    35,    22,    23,    15,   117,   236,    35,   117,     3,
       4,    31,     7,     7,     8,    35,   246,   130,    32,   132,
     132,    32,    48,     7,     8,    19,     3,   140,    22,    23,
       7,     8,   145,   146,   147,   148,     7,     7,     8,    23,
      35,    35,    19,     7,     8,    22,    23,     7,     8,   162,
      76,    35,   165,    23,    80,    32,    17,   170,   171,   172,
     173,   212,     7,    23,    35,    35,    32,     7,   263,   263,
     263,    35,   263,   185,   263,    35,   263,   263,    32,   230,
      34,   107,   277,   277,   277,   198,   277,    32,   277,   263,
     277,   277,    32,   206,   207,   208,   209,   210,   211,   212,
     212,     0,     1,   277,   130,     7,   132,   220,   221,   222,
     223,   224,   225,   226,   140,   227,    15,   230,   230,   145,
     146,   147,   148,   236,   275,     7,     8,     7,     8,    48,
      32,    31,    34,   246,     0,    35,   162,    15,     4,   165,
      29,    23,     7,     8,   170,   171,   172,   173,     7,     8,
      31,   263,    32,    35,   263,     3,     4,    76,    23,     7,
       8,    80,   275,   275,    23,   277,    16,    17,   277,    31,
      35,    19,   198,     3,    22,    23,    35,     7,     8,    31,
     206,   207,   208,   209,   210,   211,   212,    35,   107,    19,
       7,     8,    22,    23,   220,   221,   222,   223,   224,   225,
     226,    30,     7,     8,   230,    35,    23,    31,     7,     8,
     236,   130,    35,   132,     7,    32,    48,    34,     3,     4,
     246,   140,     7,     8,    23,    35,   145,   146,   147,   148,
      35,     7,     8,    32,    19,    34,    17,    22,    23,    32,
      32,    34,    34,   162,    76,    35,   165,    23,    80,   275,
      35,   170,   171,   172,   173,    32,    32,    34,    34,    17,
       7,     8,     3,     4,     3,     4,     7,     8,     7,     8,
       7,     8,    16,    17,     7,   107,    23,    32,    19,   198,
      19,    22,    23,    22,    23,    32,    23,   206,   207,   208,
     209,   210,   211,   212,    35,    32,    35,    34,   130,    32,
     132,   220,   221,   222,   223,   224,   225,   226,   140,     7,
       8,   230,     7,   145,   146,   147,   148,   236,    35,     7,
       8,    35,    32,    48,     7,     7,     8,   246,     7,    32,
     162,    34,    32,   165,    32,    23,    48,    32,   170,   171,
     172,   173,    35,     1,    32,     3,    34,     5,     6,    32,
      32,    76,    34,    32,    35,    80,   275,    16,    17,    17,
      18,    35,    20,    21,    76,    35,   198,    25,    80,    94,
      32,    96,    97,    31,   206,   207,   208,   209,   210,   211,
     212,    35,   107,    48,    32,     7,     8,    31,   220,   221,
     222,   223,   224,   225,   226,   107,    35,    32,   230,    34,
      31,    23,     0,     1,   236,   130,   118,   132,     3,     4,
      32,    76,     7,     8,   246,    80,    31,    15,   130,    32,
     132,    34,    31,   148,    19,    30,    17,    22,    23,    35,
      95,     7,     8,    30,     3,     4,   148,   162,     7,     8,
      35,    35,   107,   275,     7,     8,    32,    23,   173,    32,
      19,    34,    32,    22,    23,    32,    32,    34,    34,    32,
      23,   173,     4,     7,     8,   130,    35,   132,    32,    32,
       3,     4,    32,   198,     7,     8,     0,     1,    48,    23,
      35,   206,   207,   148,   209,   210,    19,   212,    32,    22,
      23,    15,     7,     8,    35,   220,   221,   162,   223,   224,
     212,   226,    35,    35,    27,   230,    76,    52,   173,    -1,
      80,   236,     0,     1,   226,     7,     8,    32,   230,    34,
      -1,   246,    -1,    -1,   236,    -1,    -1,    15,    -1,    -1,
      -1,    23,    -1,   198,   246,    -1,    -1,   107,    48,    -1,
      32,   206,   207,   208,   209,   210,    -1,   212,    -1,    -1,
     275,    -1,   264,    -1,    -1,   220,   221,   222,   223,   224,
     130,   226,   132,   275,    -1,   230,    76,    -1,     7,     8,
      80,   236,    -1,    48,    -1,     3,     4,    -1,   148,     7,
       8,   246,    -1,    93,    23,     0,     1,     0,     1,     0,
       1,    19,   162,    32,    22,    23,    -1,   107,     0,     1,
      15,    76,    15,   173,    15,    80,    -1,    35,    -1,    -1,
     275,     3,     4,    15,    -1,     7,     8,    92,    -1,    -1,
     130,    -1,   132,    -1,    -1,    -1,    -1,    19,   198,    -1,
      22,    23,   107,    -1,    -1,    -1,   206,   207,   148,   209,
     210,    -1,   212,    35,    -1,    -1,    -1,    -1,    -1,    -1,
     220,   221,   162,   223,   224,   130,   226,   132,    -1,    -1,
     230,    -1,    -1,   173,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,   148,     3,     4,   246,    -1,     7,     8,
      -1,     3,     4,    -1,    -1,     7,     8,   162,   198,    -1,
      19,    -1,    -1,    22,    23,    -1,   206,    19,   173,    -1,
      22,    23,   212,    -1,    -1,   275,    35,    -1,    -1,    -1,
     220,    -1,    -1,    35,     3,     4,   226,    -1,     7,     8,
     230,    -1,    -1,   198,     3,     4,   236,    -1,     7,     8,
      19,    -1,    -1,    22,    23,    -1,   246,   212,    -1,    -1,
      19,    -1,    -1,    22,    23,    -1,    35,    -1,     3,     4,
      -1,   226,     7,     8,    -1,   230,    35,    -1,     3,     4,
      -1,   236,     7,     8,    19,   275,    -1,    22,    23,    -1,
      -1,   246,    -1,    -1,    19,    -1,    -1,    22,    23,     1,
      35,     3,    -1,     5,     6,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
     275,    -1,     1,    25,     3,    -1,     5,     6,    -1,    31,
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
      -1,    -1,    32,    -1,    34,    -1,    19,     3,     4,    22,
      23,     7,     8,     3,    -1,    -1,    -1,     7,     8,    32,
      -1,    34,    -1,    19,    -1,    -1,    22,    23,    -1,    19,
      -1,    -1,    22,    23,    -1,    -1,    32,    -1,    34,    -1,
      -1,     1,    32,     3,    34,     5,     6,    -1,    -1,     9,
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
       9,    -1,    11,    12,    13,    14,    -1,    -1,    17,    18,
      -1,    20,    21,     1,    -1,     3,    25,     5,     6,    -1,
      29,     9,    31,    11,    12,    13,    14,    -1,    -1,    17,
      18,    -1,    20,    21,     1,    -1,     3,    25,     5,     6,
      -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    24,    25,    -1,
      -1,     1,    -1,     3,    31,     5,     6,    -1,    -1,    -1,
       1,    -1,     3,    -1,     5,     6,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    24,    25,    17,    18,    -1,    20,
      21,    31,    -1,     1,    25,     3,    -1,     5,     6,    -1,
      31,    -1,     1,    -1,     3,    -1,     5,     6,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    17,    18,
      -1,    20,    21,    31,    -1,     1,    25,     3,    -1,     5,
       6,    -1,    31,    -1,     3,     4,    -1,    -1,     7,     8,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      19,    -1,    -1,    22,    23,    31,     3,     4,    -1,    -1,
       7,     8,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,     3,     4,    22,    23,     7,     8,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    -1,
       7,     8,    32,    -1,    -1,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,    32,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    -1,
       7,     8,    32,    -1,    -1,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,    32,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    -1,
       7,     8,    32,    -1,    -1,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,    32,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    -1,
       7,     8,    32,    -1,    -1,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,    32,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    -1,
       7,     8,    32,    -1,    -1,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,    32,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    19,
       3,     4,    22,    23,     7,     8,    -1,    -1,     3,    -1,
       5,     6,    32,    -1,    -1,    -1,    19,    -1,    -1,    22,
      23,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    32,
      25,     3,    -1,     5,     6,    -1,    31,    -1,    -1,    -1,
       3,    -1,     5,     6,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    17,    18,    -1,    20,    21,    31,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    15,    38,    39,    40,    42,    43,    47,    16,
      17,     0,    40,    31,    17,    35,    44,    35,     1,    15,
      41,    46,    48,    49,    16,    17,    45,    34,    17,    32,
      49,    29,    50,     1,     3,     5,     6,     9,    11,    12,
      13,    14,    15,    17,    18,    20,    21,    25,    31,    42,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    75,    17,    70,    31,    31,    58,    31,
      31,    16,    17,    31,    33,    70,    70,    70,    64,    30,
      53,    35,     7,     8,    23,     3,    19,    22,     4,    64,
      58,    35,    17,    24,    58,    17,    32,    73,    58,    32,
      65,    66,    67,    69,    67,    67,    70,    32,    35,    32,
      32,    32,    64,    74,    54,    64,    35,    35,    35,    32,
      34,    10,    35,    64,    54,    58,    32,    54,    29,     1,
       3,     5,     6,    17,    18,    20,    21,    25,    31,    65,
      66,    67,    68,    69,    70,    71,    72,    75,    17,    63,
      64,    35,     7,    35,     1,     3,     5,     6,    17,    18,
      20,    21,    25,    31,    65,    66,    67,    68,    69,    70,
      71,    72,    75,     9,    11,    12,    13,    14,    29,    50,
      55,    56,    57,    58,    59,    60,    61,    62,     7,    51,
      70,    31,    70,    70,    70,    64,     8,    23,     3,    19,
      22,     4,    33,    65,    70,    31,    70,    70,    70,    64,
       8,    23,     3,    19,    22,     4,    31,    31,    58,    31,
      31,    51,    35,    65,    30,    32,    73,    32,    66,    67,
      69,    67,    67,    70,    58,    32,    73,    32,    66,    67,
      69,    67,    67,    70,    64,    58,    35,    17,    24,    58,
      30,    74,    74,    32,    35,    32,    32,    32,    32,    32,
      54,    64,    35,    35,    35,    35,    58,    32,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    41,    41,
      42,    42,    44,    45,    43,    46,    46,    47,    47,    48,
      48,    48,    49,    50,    51,    51,    52,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    55,    55,    56,    57,
      58,    58,    59,    60,    60,    61,    62,    62,    63,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      71,    71,    73,    72,    72,    74,    74,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     3,
       3,     4,     0,     0,     7,     1,     0,     2,     3,     1,
       3,     1,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     7,     9,     2,
       1,     1,     3,     1,     1,     5,     5,     5,     3,     3,
       1,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     1,     2,     2,     2,     2,     1,     3,
       1,     1,     0,     5,     3,     1,     3,     1,     1,     1
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
#line 128 "src/syntax.y"
                        {
		//root = *createAstNode("initial", DEBUG_AST);	// non-printable
		root.node_name = strdup("initial");
		root.printable = 0;
		(yyval.ast) = &root;
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2133 "src/syntax.tab.c"
    break;

  case 3: /* declaration_list: declaration_list decl  */
#line 139 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("declaration list", 1);	// printable
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2144 "src/syntax.tab.c"
    break;

  case 4: /* declaration_list: decl  */
#line 145 "src/syntax.y"
              {
		//$$ = createAstNode("declaration list", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2155 "src/syntax.tab.c"
    break;

  case 5: /* decl: var_declaration  */
#line 154 "src/syntax.y"
                       {
		//$$ = createAstNode("decl", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2166 "src/syntax.tab.c"
    break;

  case 6: /* decl: func_definition  */
#line 160 "src/syntax.y"
                         {
		//$$ = createAstNode("decl", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2177 "src/syntax.tab.c"
    break;

  case 7: /* decl: error  */
#line 166 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2187 "src/syntax.tab.c"
    break;

  case 8: /* var_definition: SIMPLE_TYPE ID  */
#line 174 "src/syntax.y"
                      {
		int var_type = 2;	// parameter
		char type_and_id[150];
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, (yyvsp[-1].lexeme).lexeme_string);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " parameter definition");
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, (yyvsp[-1].lexeme).lexeme_string, var_type, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, (yyvsp[0].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode(type_and_id, 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2207 "src/syntax.tab.c"
    break;

  case 9: /* var_definition: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 189 "src/syntax.y"
                                      {
		char concat_type[15];
		char type_and_id[150];
		int var_type = 2;	// parameter
		strcpy(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, concat_type);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " parameter definition");
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, concat_type, var_type, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, (yyvsp[0].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode(type_and_id, 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup(concat_type);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2231 "src/syntax.tab.c"
    break;

  case 10: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 211 "src/syntax.y"
                          {
		int var_type = 1;
		char type_and_id[150];
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, (yyvsp[-2].lexeme).lexeme_string);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " variable declaration");
		insertSymbol(&symbolTable, (yyvsp[-1].lexeme).lexeme_string, (yyvsp[-2].lexeme).lexeme_string, var_type, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, (yyvsp[-1].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode(type_and_id, 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup((yyvsp[-2].lexeme).lexeme_string);
		(yyval.ast)->token_line = (yyvsp[-1].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-1].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2251 "src/syntax.tab.c"
    break;

  case 11: /* var_declaration: SIMPLE_TYPE COMPOUND_TYPE ID ';'  */
#line 226 "src/syntax.y"
                                          {
		char concat_type[15];
		char type_and_id[150];
		int var_type = 1;
		strcpy(concat_type, (yyvsp[-3].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, concat_type);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " variable declaration");
		insertSymbol(&symbolTable, (yyvsp[-1].lexeme).lexeme_string, concat_type, var_type, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, (yyvsp[-1].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode(type_and_id, 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup(concat_type);
		(yyval.ast)->token_line = (yyvsp[-1].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-1].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2275 "src/syntax.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 248 "src/syntax.y"
                             {
		func_context = 1;
		insertScope(++last_scope, &contextList);
	}
#line 2284 "src/syntax.tab.c"
    break;

  case 13: /* $@2: %empty  */
#line 251 "src/syntax.y"
                     {
		;
	}
#line 2292 "src/syntax.tab.c"
    break;

  case 14: /* func_definition: func_declaration '(' $@1 params.opt $@2 ')' stmts  */
#line 253 "src/syntax.y"
                    {
		(yyval.ast) = createAstNode("function definition", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-6].ast);
		(yyval.ast)->children[1] = (yyvsp[-3].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
		removeScope(&contextList);
	}
#line 2305 "src/syntax.tab.c"
    break;

  case 15: /* params.opt: param_list  */
#line 264 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("params optional", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2315 "src/syntax.tab.c"
    break;

  case 16: /* params.opt: %empty  */
#line 269 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("params optional empty", DEBUG_AST); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2324 "src/syntax.tab.c"
    break;

  case 17: /* func_declaration: SIMPLE_TYPE ID  */
#line 276 "src/syntax.y"
                      {
		int func_type = 0;
		char type_and_id[150];
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, (yyvsp[-1].lexeme).lexeme_string);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " function declaration");
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, (yyvsp[-1].lexeme).lexeme_string, func_type, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, (yyvsp[0].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode(type_and_id, 1);
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
#line 2348 "src/syntax.tab.c"
    break;

  case 18: /* func_declaration: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 295 "src/syntax.y"
                                      {
		char concat_type[15];
		char type_and_id[150];
		int func_type = 0;
		strcpy(concat_type, (yyvsp[-2].lexeme).lexeme_string);
		strcat(concat_type, " ");
		strcat(concat_type, (yyvsp[-1].lexeme).lexeme_string);
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, concat_type);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " function declaration");
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, concat_type, func_type, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, (yyvsp[0].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode(type_and_id, 1);
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
#line 2376 "src/syntax.tab.c"
    break;

  case 19: /* param_list: param  */
#line 321 "src/syntax.y"
             {
		//$$ = createAstNode("param list", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2387 "src/syntax.tab.c"
    break;

  case 20: /* param_list: param_list ',' param  */
#line 327 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("param list", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2398 "src/syntax.tab.c"
    break;

  case 21: /* param_list: error  */
#line 333 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2408 "src/syntax.tab.c"
    break;

  case 22: /* param: var_definition  */
#line 341 "src/syntax.y"
                      {
		//$$ = createAstNode("param", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
		setupParameters(&symbolTable);
	}
#line 2420 "src/syntax.tab.c"
    break;

  case 23: /* stmts: '{' stmt_list.opt '}'  */
#line 351 "src/syntax.y"
                             {
		//$$ = createAstNode("stmts", 1);
		//$$->children[0] = $2;
		(yyval.ast) = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2431 "src/syntax.tab.c"
    break;

  case 24: /* stmt_list.opt: stmt_list  */
#line 360 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list optional", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2441 "src/syntax.tab.c"
    break;

  case 25: /* stmt_list.opt: %empty  */
#line 365 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list empty", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2450 "src/syntax.tab.c"
    break;

  case 26: /* stmt_list: stmt_list stmt.item  */
#line 372 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("stmt list", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2461 "src/syntax.tab.c"
    break;

  case 27: /* stmt_list: stmt.item  */
#line 378 "src/syntax.y"
                   {
		//$$ = createAstNode("stmt list", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2472 "src/syntax.tab.c"
    break;

  case 28: /* stmt.item: stmt  */
#line 387 "src/syntax.y"
            {
		//$$ = createAstNode("stmt item", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2483 "src/syntax.tab.c"
    break;

  case 29: /* stmt.item: var_declaration  */
#line 393 "src/syntax.y"
                         {
		//$$ = createAstNode("stmt item", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2494 "src/syntax.tab.c"
    break;

  case 30: /* stmt: return_stmt  */
#line 402 "src/syntax.y"
                   {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2505 "src/syntax.tab.c"
    break;

  case 31: /* stmt: select_stmt  */
#line 408 "src/syntax.y"
                     {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2516 "src/syntax.tab.c"
    break;

  case 32: /* stmt: iter_stmt  */
#line 414 "src/syntax.y"
                   {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2527 "src/syntax.tab.c"
    break;

  case 33: /* stmt: io_stmt  */
#line 420 "src/syntax.y"
                 {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2538 "src/syntax.tab.c"
    break;

  case 34: /* stmt: exp_stmt  */
#line 426 "src/syntax.y"
                  {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2549 "src/syntax.tab.c"
    break;

  case 35: /* stmt: stmts  */
#line 432 "src/syntax.y"
               {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2560 "src/syntax.tab.c"
    break;

  case 36: /* select_stmt: IF '(' simple_exp ')' stmt  */
#line 441 "src/syntax.y"
                                             {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2571 "src/syntax.tab.c"
    break;

  case 37: /* select_stmt: IF '(' simple_exp ')' stmt ELSE stmt  */
#line 447 "src/syntax.y"
                                              {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-4].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2583 "src/syntax.tab.c"
    break;

  case 38: /* iter_stmt: FOR '(' exp ';' simple_exp ';' exp ')' stmt  */
#line 457 "src/syntax.y"
                                                   {
		(yyval.ast) = createAstNode("iter stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-6].ast);
		(yyval.ast)->children[1] = (yyvsp[-4].ast);
		(yyval.ast)->children[2] = (yyvsp[-2].ast);
		(yyval.ast)->children[3] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2596 "src/syntax.tab.c"
    break;

  case 39: /* exp_stmt: exp ';'  */
#line 468 "src/syntax.y"
               {
		//$$ = createAstNode("expression", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2607 "src/syntax.tab.c"
    break;

  case 40: /* exp: assign_exp  */
#line 477 "src/syntax.y"
                  {
		//$$ = createAstNode("exp stmt", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2618 "src/syntax.tab.c"
    break;

  case 41: /* exp: simple_exp  */
#line 483 "src/syntax.y"
                    {
		//$$ = createAstNode("exp stmt", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2629 "src/syntax.tab.c"
    break;

  case 42: /* return_stmt: RETURN exp ';'  */
#line 492 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("return stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
		//checkType($$, $1.line, $1.column, &semantic_errors);
	}
#line 2640 "src/syntax.tab.c"
    break;

  case 43: /* io_stmt: in_stmt  */
#line 501 "src/syntax.y"
               {
		//$$ = createAstNode("in/out stmt", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2651 "src/syntax.tab.c"
    break;

  case 44: /* io_stmt: out_stmt  */
#line 507 "src/syntax.y"
                  {
		//$$ = createAstNode("in/out stmt", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2662 "src/syntax.tab.c"
    break;

  case 45: /* in_stmt: INPUT '(' ID ')' ';'  */
#line 516 "src/syntax.y"
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
#line 2680 "src/syntax.tab.c"
    break;

  case 46: /* out_stmt: OUTPUT '(' STRING ')' ';'  */
#line 532 "src/syntax.y"
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
#line 2695 "src/syntax.tab.c"
    break;

  case 47: /* out_stmt: OUTPUT '(' exp ')' ';'  */
#line 542 "src/syntax.y"
                                {
		char output_type[200];
		(yyval.ast) = createAstNode("output stmt", 1);
		strcpy(output_type, (yyvsp[-4].lexeme).lexeme_string);
		strcat(output_type, "()");
		(yyval.ast)->token_name = strdup(output_type);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2709 "src/syntax.tab.c"
    break;

  case 48: /* assign_exp: ID '=' exp  */
#line 554 "src/syntax.y"
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
#line 2726 "src/syntax.tab.c"
    break;

  case 49: /* simple_exp: simple_exp LOGICAL_OR and_exp  */
#line 569 "src/syntax.y"
                                     {
		(yyval.ast) = createAstNode("simple exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2738 "src/syntax.tab.c"
    break;

  case 50: /* simple_exp: and_exp  */
#line 576 "src/syntax.y"
                 {
		//$$ = createAstNode("simple exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2749 "src/syntax.tab.c"
    break;

  case 51: /* simple_exp: error  */
#line 582 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2759 "src/syntax.tab.c"
    break;

  case 52: /* and_exp: and_exp LOGICAL_AND rel_exp  */
#line 590 "src/syntax.y"
                                   {
		(yyval.ast) = createAstNode("and exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2771 "src/syntax.tab.c"
    break;

  case 53: /* and_exp: rel_exp  */
#line 597 "src/syntax.y"
                 {
		//$$ = createAstNode("and exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2782 "src/syntax.tab.c"
    break;

  case 54: /* rel_exp: rel_exp RELATIONAL list_exp  */
#line 606 "src/syntax.y"
                                   {
		(yyval.ast) = createAstNode("rel exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2794 "src/syntax.tab.c"
    break;

  case 55: /* rel_exp: list_exp  */
#line 613 "src/syntax.y"
                  {
		//$$ = createAstNode("rel exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2805 "src/syntax.tab.c"
    break;

  case 56: /* list_exp: sum_exp LIST_CONSTR list_exp  */
#line 622 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("list exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2817 "src/syntax.tab.c"
    break;

  case 57: /* list_exp: sum_exp LIST_FUNC list_exp  */
#line 629 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("list exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2829 "src/syntax.tab.c"
    break;

  case 58: /* list_exp: sum_exp  */
#line 636 "src/syntax.y"
                 {
		//$$ = createAstNode("list exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2840 "src/syntax.tab.c"
    break;

  case 59: /* sum_exp: sum_exp ADD mul_exp  */
#line 645 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("sum exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2852 "src/syntax.tab.c"
    break;

  case 60: /* sum_exp: mul_exp  */
#line 652 "src/syntax.y"
                 {
		//$$ = createAstNode("sum exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2863 "src/syntax.tab.c"
    break;

  case 61: /* mul_exp: mul_exp MUL unary_exp  */
#line 661 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("mul exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2875 "src/syntax.tab.c"
    break;

  case 62: /* mul_exp: unary_exp  */
#line 668 "src/syntax.y"
                   {
		//$$ = createAstNode("mul exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2886 "src/syntax.tab.c"
    break;

  case 63: /* unary_exp: factor  */
#line 677 "src/syntax.y"
              {
		//$$ = createAstNode("unary exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2897 "src/syntax.tab.c"
    break;

  case 64: /* unary_exp: LIST_OP unary_exp  */
#line 683 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2908 "src/syntax.tab.c"
    break;

  case 65: /* unary_exp: LIST_DESTR unary_exp  */
#line 689 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2919 "src/syntax.tab.c"
    break;

  case 66: /* unary_exp: OP_OVERLOAD unary_exp  */
#line 695 "src/syntax.y"
                               {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2930 "src/syntax.tab.c"
    break;

  case 67: /* unary_exp: ADD unary_exp  */
#line 701 "src/syntax.y"
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
#line 2947 "src/syntax.tab.c"
    break;

  case 68: /* factor: ID  */
#line 716 "src/syntax.y"
          {
		char id_type[15];
		strcpy(id_type, getContext(&symbolTable, &contextList, (yyvsp[0].lexeme).lexeme_string, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("id", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup(id_type);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2962 "src/syntax.tab.c"
    break;

  case 69: /* factor: '(' simple_exp ')'  */
#line 726 "src/syntax.y"
                            {
		//$$ = createAstNode("factor exp", DEBUG_AST);
		//$$->children[0] = $2;
		(yyval.ast) = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2973 "src/syntax.tab.c"
    break;

  case 70: /* factor: func_call  */
#line 732 "src/syntax.y"
                   {
		//$$ = createAstNode("factor exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2984 "src/syntax.tab.c"
    break;

  case 71: /* factor: constant  */
#line 738 "src/syntax.y"
                  {
		//$$ = createAstNode("factor exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2995 "src/syntax.tab.c"
    break;

  case 72: /* $@3: %empty  */
#line 747 "src/syntax.y"
               {
		func_params_counter = 0;
	}
#line 3003 "src/syntax.tab.c"
    break;

  case 73: /* func_call: ID '(' $@3 func_params ')'  */
#line 749 "src/syntax.y"
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
		checkFunctionCall(&symbolTable, &contextList, (yyvsp[-4].lexeme).lexeme_string, (yyvsp[-4].lexeme).line, (yyvsp[-4].lexeme).column, func_params_counter, &semantic_errors);
	}
#line 3023 "src/syntax.tab.c"
    break;

  case 74: /* func_call: ID '(' ')'  */
#line 764 "src/syntax.y"
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
		checkFunctionCall(&symbolTable, &contextList, (yyvsp[-2].lexeme).lexeme_string, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, 0, &semantic_errors);
	}
#line 3042 "src/syntax.tab.c"
    break;

  case 75: /* func_params: simple_exp  */
#line 781 "src/syntax.y"
                  {
		func_params_counter+= 1;
		//$$ = createAstNode("func params", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 3054 "src/syntax.tab.c"
    break;

  case 76: /* func_params: func_params ',' simple_exp  */
#line 788 "src/syntax.y"
                                    {
		func_params_counter+= 1;
		(yyval.ast) = createAstNode("func params", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 3066 "src/syntax.tab.c"
    break;

  case 77: /* constant: INTEGER  */
#line 798 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("int constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup("int");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3079 "src/syntax.tab.c"
    break;

  case 78: /* constant: REAL  */
#line 806 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("real constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup("float");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3092 "src/syntax.tab.c"
    break;

  case 79: /* constant: NIL_CONSTANT  */
#line 814 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("nil constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup("nil");
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

#line 824 "src/syntax.y"


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
		printf("\n%s~> AST tree will not be printed, due to syntax or semantic error(s).%s\n", RED, WHITE);

	printTable(&symbolTable);

	if(syntax_errors == 0)
		printf("\n%sSyntax analysis finished without error(s).%s\n", GREEN, WHITE);
	else
		printf("\n%sSyntax analysis finished with %d error(s).%s\n", RED, syntax_errors, WHITE);

	if(semantic_errors == 0)
		printf("%sSemantic analysis finished without error(s).%s\n", GREEN, WHITE);
	else
		printf("%sSemantic analysis finished with %d error(s).%s\n", RED, semantic_errors, WHITE);

	//printParams(&symbolTable);

	freeNode(&root);
	freeSymbols(&symbolTable);
	freeContextList(&contextList);
	yylex_destroy();
	return 0;
}

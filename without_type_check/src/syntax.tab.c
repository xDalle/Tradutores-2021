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
	extern int func_context;			// manipulate scope interaction between lexical and syntatic
	static int syntax_errors = 0;	
	static int semantic_errors = 0;
	int func_params_counter = 0;		// incremented by the number of params in function call
	int check_func_type = 0;
	char function_name[100];
	extern Ast root;
	extern AstList astList;
	extern Table symbolTable;
	extern Context contextList;

#line 105 "src/syntax.tab.c"

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
  YYSYMBOL_45_params_opt = 45,             /* params.opt  */
  YYSYMBOL_func_declaration = 46,          /* func_declaration  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3042

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  278

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
       0,   129,   129,   140,   146,   155,   161,   167,   177,   186,
     201,   223,   238,   260,   260,   274,   279,   286,   306,   333,
     339,   345,   354,   364,   373,   378,   385,   391,   400,   406,
     415,   421,   427,   433,   439,   445,   455,   464,   470,   480,
     491,   500,   506,   515,   524,   530,   539,   555,   565,   577,
     592,   599,   605,   614,   621,   630,   637,   646,   653,   660,
     669,   676,   685,   692,   701,   707,   713,   719,   725,   742,
     753,   759,   765,   774,   790,   807,   814,   824,   844,   853
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
  "var_declaration", "func_definition", "$@1", "params.opt",
  "func_declaration", "param_list", "param", "stmts", "stmt_list.opt",
  "stmt_list", "stmt.item", "stmt", "select_stmt", "iter_stmt", "exp_stmt",
  "exp", "return_stmt", "io_stmt", "in_stmt", "out_stmt", "assign_exp",
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

#define YYPACT_NINF (-186)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,     6,   125,    23,    10,    25,    31,    33,    36,    28,
      39,   181,  -186,    61,    79,   233,    63,    80,    69,    71,
     147,   247,    47,   290,   361,    48,   377,    56,    82,   387,
    1425,    72,   396,     4,   366,   121,   255,    55,    95,  2653,
     122,   140,   188,   203,   345,   366,   366,   366,  2662,  1456,
    1487,  1518,    93,  1549,  1580,  1611,  1642,  1673,  1704,   162,
    1735,  1766,  1797,  1828,   186,   110,    75,    83,   112,  2305,
     475,   519,   643,   651,   660,   311,   740,  2662,  2653,   193,
     234,  2617,   254,   231,   572,  2653,  2219,  2229,  2236,   127,
      74,  1859,  1890,   366,   366,   366,   366,   366,   366,   366,
     294,   235,  1921,   248,   271,   279,   288,  2253,   216,   410,
     292,  2259,    92,   249,   275,  2276,   321,   343,  2282,   795,
    2685,   296,   300,   308,  2299,  2694,   860,   123,  1952,  1983,
    2014,   268,  2200,  2717,  2045,   327,  2200,  2076,  1425,   350,
    2988,   835,  2763,  2746,  2780,  2988,  2988,  2988,  2662,   114,
      12,   195,  2980,  2786,  2803,  2820,  2826,  2843,  2724,   344,
     358,  2107,   347,  3011,  2377,  2394,  2356,  2400,  3011,  3011,
    3011,  2662,   207,   212,   313,  2307,  2417,  2434,  2440,  2457,
    2474,  2988,  2138,  3011,   357,   405,  2653,   406,   417,  1425,
     898,   929,   960,   991,  1022,   354,  1053,  1084,  1115,  1146,
     362,  2860,  2330,  2866,  2883,  2900,   378,  2988,  2988,  2988,
    2988,  2988,  2988,  2717,  2480,  2351,  2497,  2514,  2520,   391,
    3011,  3011,  3011,  3011,  3011,  3011,   281,   253,  2662,  2653,
     373,   437,  2626,   392,  1177,  2169,  2906,   415,  2923,   427,
     445,  2940,   525,   625,  2946,   395,  2537,   423,  2554,   814,
    2632,  2560,  2966,  3003,  2577,   399,   425,  1208,   426,   433,
     435,  1239,  2963,  2594,   795,  2685,   434,   436,   440,  1270,
     160,  1301,  1332,  1363,  2717,   438,   795,  1394
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
       0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -186,  -186,  -186,   467,  -186,   208,  -186,  -186,  -186,  -186,
    -186,   457,   -27,  -134,  -186,   439,  -114,  -116,  -110,  -107,
     -31,   -92,   -91,   -90,   -77,   -80,   632,   612,   559,   348,
     504,   403,   -32,    84,   192,  -185,   293
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    21,    50,     8,    17,    22,     9,
      23,    24,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,   109,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   159,    76,   192,   200,   126,    -8,    -8,    79,   193,
      12,   -52,   194,    86,    87,    88,   154,   237,   134,   -54,
     -54,    -8,   137,    -7,    -7,    -2,     1,   196,   197,   198,
     247,    -4,    -4,    -5,    -5,   208,    -6,    -6,    -7,   -52,
       2,    -8,   199,     1,   -54,   154,    -4,   101,    -5,   154,
     105,    -6,   177,   159,   110,   233,    15,     2,    -7,    14,
       3,    -3,    -3,   -11,   -11,    29,    -4,   118,    -5,   -12,
     -12,    -6,   -14,   -14,   -23,   -23,    -3,     3,   -11,    27,
     -13,    19,   -51,    94,   -12,    30,    77,   -14,   195,   -23,
     -54,   -54,   191,   177,   -13,    20,    -3,    20,   -11,   -50,
      94,   154,   135,   -21,   -12,   -21,    95,   -14,   201,   -23,
     -51,   -13,   -16,   203,   204,   205,   154,    93,   -54,   -56,
     -56,   -51,   207,    90,   -77,   -77,    78,   -50,   -77,   -77,
      93,   214,   155,   159,   181,   -56,   216,   217,   218,   154,
     -77,    10,    11,   -77,   -77,   -42,   -51,   -56,   192,   154,
     269,   177,   159,    80,   193,   230,   -77,   194,   133,   111,
     192,   155,   277,    25,    26,   155,   193,    93,   178,   194,
     177,    81,   196,   197,   198,   154,   154,   154,   154,   154,
     244,   154,   245,   177,   196,   197,   198,   199,   177,   177,
     177,   177,   177,   254,   159,   274,   154,    92,   256,   199,
     154,   260,   -56,   -56,    82,    83,   -69,   -69,     7,   178,
     -69,   -69,   -17,     7,   -51,   220,    16,   155,   -56,   -54,
     -54,   -41,   -69,   183,   155,   -69,   -69,   -56,   102,   155,
     155,   155,   155,   195,    84,   221,    85,   191,   -69,   -51,
     156,   -51,   154,   275,   -54,   195,   -54,   178,   -75,   191,
     -75,   103,   178,   178,   178,   155,   -53,   -53,   -78,   -78,
     -50,   220,   -78,   -78,   -18,   155,   161,   178,    18,   156,
     120,   106,    95,   156,   -78,   183,   179,   -78,   -78,   -22,
     121,   -22,   -55,   -55,   -53,   -50,   178,   -50,   -50,   207,
     -78,   155,   155,   155,   155,   155,   155,   155,   -55,   178,
     -76,   181,   -76,   122,   178,   178,   178,   178,   178,   178,
     -55,   123,   155,   -50,   -69,   -69,   155,   179,   -69,   -69,
     -56,   -56,   -15,   182,    28,   156,   119,   -49,   -57,   -57,
     -69,   128,   156,   -69,   -69,   129,   -56,   156,   156,   156,
     156,   157,    84,   130,   -57,   -56,   -69,   -56,   -79,   -79,
     -58,   -58,   -79,   -79,   -52,   179,   -57,   -52,   155,   136,
     179,   179,   179,   156,   -79,   181,   -58,   -79,   -79,    34,
     157,    35,    36,   156,   157,   179,   -41,   180,   -58,   -52,
     -79,   -52,   -52,    75,    44,   181,    45,    46,   228,   234,
     -42,    47,   235,   -19,   179,   -19,   151,    48,   181,   156,
     156,   156,   156,   156,   156,   156,   181,   179,   257,    -9,
     238,    -9,   179,   179,   179,   179,   179,   179,   180,   -10,
     156,   -10,   261,   248,   156,   151,   157,   -49,   -20,   151,
     -20,   264,   174,   157,   -53,   -53,   229,   231,   157,   157,
     157,   157,   124,   114,   125,   116,   117,   262,   232,   125,
     208,   153,   -55,   -55,   258,   263,   180,   125,   266,   -53,
     265,   180,   180,   180,   157,   267,   156,   268,   -55,   271,
     276,   272,    13,   174,   157,   273,   180,   -55,   -61,    99,
     153,   151,   -61,   -61,   153,    32,     0,   176,     0,     0,
       0,     0,    91,     0,   -61,   180,   151,   -61,   -61,   115,
     157,   157,   157,   157,   157,   157,   157,     0,   180,     0,
     -61,     0,     0,   180,   180,   180,   180,   180,   180,   151,
       0,   157,   -63,   -63,     0,   157,   -63,   -63,   176,   151,
       0,   174,   -57,   -57,     0,     0,   153,     0,   -63,     0,
       0,   -63,   -63,     0,     0,     0,     0,     0,   -57,     0,
     174,   153,   152,     0,   -63,   151,   240,   -57,   242,   243,
       0,   151,     0,   174,     0,     0,     0,   157,   174,   250,
       0,   252,   253,   162,   153,   163,   151,   164,   165,     0,
     151,   152,     0,     0,   153,   152,   176,     0,   175,   166,
     167,     0,   168,   169,     0,     0,     0,   170,     0,     0,
       0,     0,     0,   171,   107,   176,     0,   150,     0,     0,
     153,   153,   241,   153,   153,     0,   153,     0,   176,     0,
       0,     0,   151,   176,   176,   251,   176,   176,     0,   175,
       0,   153,   -58,   -58,     0,   153,   150,   152,     0,     0,
     150,     0,     0,   173,     0,     0,   -64,   -64,   -58,     0,
     -64,   -64,   152,   113,   -71,   -71,     0,   -58,   -71,   -71,
     149,     0,   -64,   -72,   -72,   -64,   -64,   -72,   -72,     0,
     -71,     0,     0,   -71,   -71,   152,     0,   153,   -64,   -72,
      89,     0,   -72,   -72,   173,   152,   -71,   175,     0,   149,
       0,     0,   150,   149,     0,   -72,   172,     0,     0,     0,
       0,     0,     0,     0,     0,   112,   175,   150,     0,   100,
       0,   152,   152,   160,   152,   152,   108,   152,     0,   175,
       0,     0,     0,     0,   175,   175,     0,   175,   175,     0,
     150,     0,   152,     0,     0,     0,   152,   172,     0,     0,
     150,     0,   173,   -68,   -68,   149,     0,   -68,   -68,     0,
       0,     0,   127,     0,     0,     0,     0,   131,     0,   -68,
     149,   173,   -68,   -68,     0,   160,   239,     0,     0,     0,
       0,     0,   150,     0,   173,   -68,     0,     0,   152,   249,
     206,     0,     0,   149,     0,     0,     0,   150,     0,     0,
       0,   150,     0,   226,     0,   227,    33,     0,    34,     0,
      35,    36,     0,   219,   184,     0,   185,   186,   187,   188,
       0,     0,    43,    44,   172,    45,    46,     0,     0,     0,
      47,   -53,   -53,     0,   189,   149,    48,   172,     0,     0,
     190,     0,     0,   150,   108,     0,     0,   221,   -77,   -77,
     149,     0,   -77,   -77,   149,   160,   -53,   108,   -53,     0,
       0,     0,     0,     0,   -77,     0,     0,   -77,   -77,     0,
     255,   -37,     0,   -37,   160,   -37,   -37,   -77,     0,   -37,
     132,   -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,     0,
     -37,   -37,     0,     0,     0,   -37,   149,     0,     0,   -37,
     -37,   -37,     0,     0,     0,   -37,     0,   270,     0,   -35,
       0,   -35,     0,   -35,   -35,     0,   160,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,     0,   -35,   -35,     0,   -35,   -35,
       0,     0,     0,   -35,     0,     0,     0,   -35,   -35,   -35,
     -36,     0,   -36,   -35,   -36,   -36,     0,     0,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,     0,   -36,
     -36,     0,     0,     0,   -36,     0,     0,     0,   -36,   -36,
     -36,   -31,     0,   -31,   -36,   -31,   -31,     0,     0,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,     0,
     -31,   -31,     0,     0,     0,   -31,     0,     0,     0,   -31,
     -31,   -31,   -32,     0,   -32,   -31,   -32,   -32,     0,     0,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,
       0,   -32,   -32,     0,     0,     0,   -32,     0,     0,     0,
     -32,   -32,   -32,   -34,     0,   -34,   -32,   -34,   -34,     0,
       0,   -34,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,
     -34,     0,   -34,   -34,     0,     0,     0,   -34,     0,     0,
       0,   -34,   -34,   -34,   -30,     0,   -30,   -34,   -30,   -30,
       0,     0,   -30,   -30,   -30,   -30,   -30,   -30,   -30,     0,
     -30,   -30,     0,   -30,   -30,     0,     0,     0,   -30,     0,
       0,     0,   -30,   -30,   -30,   -33,     0,   -33,   -30,   -33,
     -33,     0,     0,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
       0,   -33,   -33,     0,   -33,   -33,     0,     0,     0,   -33,
       0,     0,     0,   -33,   -33,   -33,   -44,     0,   -44,   -33,
     -44,   -44,     0,     0,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,     0,   -44,   -44,     0,   -44,   -44,     0,     0,     0,
     -44,     0,     0,     0,   -44,   -44,   -44,   -45,     0,   -45,
     -44,   -45,   -45,     0,     0,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,     0,   -45,   -45,     0,   -45,   -45,     0,     0,
       0,   -45,     0,     0,     0,   -45,   -45,   -45,   -40,     0,
     -40,   -45,   -40,   -40,     0,     0,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,     0,   -40,   -40,     0,   -40,   -40,     0,
       0,     0,   -40,     0,     0,     0,   -40,   -40,   -40,   -43,
       0,   -43,   -40,   -43,   -43,     0,     0,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,
       0,     0,     0,   -43,     0,     0,     0,   -43,   -43,   -43,
     -23,     0,   -23,   -43,   -23,   -23,     0,     0,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,     0,   -23,
     -23,     0,     0,     0,   -23,     0,     0,     0,   -23,   -23,
     -23,   -37,     0,   -37,   -23,   -37,   -37,     0,     0,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,     0,
     -37,   -37,     0,     0,     0,   -37,     0,     0,     0,   -37,
     -37,   -37,   -46,     0,   -46,   -37,   -46,   -46,     0,     0,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,     0,   -46,   -46,
       0,   -46,   -46,     0,     0,     0,   -46,     0,     0,     0,
     -46,   -46,   -46,   -47,     0,   -47,   -46,   -47,   -47,     0,
       0,   -47,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,
     -47,     0,   -47,   -47,     0,     0,     0,   -47,     0,     0,
       0,   -47,   -47,   -47,   -48,     0,   -48,   -47,   -48,   -48,
       0,     0,   -48,   -48,   -48,   -48,   -48,   -48,   -48,     0,
     -48,   -48,     0,   -48,   -48,     0,     0,     0,   -48,     0,
       0,     0,   -48,   -48,   -48,   -39,     0,   -39,   -48,   -39,
     -39,     0,     0,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
       0,   -39,   -39,     0,   -39,   -39,     0,     0,     0,   -39,
       0,     0,     0,   -39,   -39,   -39,    33,     0,    34,   -39,
      35,    36,     0,     0,    37,     0,    38,    39,    40,    41,
      42,     0,    43,    44,     0,    45,    46,     0,     0,     0,
      47,     0,     0,     0,   138,   -25,    48,   -35,     0,   -35,
      49,   -35,   -35,     0,     0,   -35,     0,   -35,   -35,   -35,
     -35,   -35,     0,   -35,   -35,     0,   -35,   -35,     0,     0,
       0,   -35,     0,     0,     0,   -35,   -35,   -35,   -29,     0,
     -29,   -35,   -29,   -29,     0,     0,   -29,     0,   -29,   -29,
     -29,   -29,   -29,     0,   -29,   -29,     0,   -29,   -29,     0,
       0,     0,   -29,     0,     0,     0,   -29,   -29,   -29,   -36,
       0,   -36,   -29,   -36,   -36,     0,     0,   -36,     0,   -36,
     -36,   -36,   -36,   -36,     0,   -36,   -36,     0,   -36,   -36,
       0,     0,     0,   -36,     0,     0,     0,   -36,   -36,   -36,
      33,     0,    34,   -36,    35,    36,     0,     0,    37,     0,
      38,    39,    40,    41,    42,     0,    43,    44,     0,    45,
      46,     0,     0,     0,    47,     0,     0,     0,   138,   -24,
      48,   -27,     0,   -27,    49,   -27,   -27,     0,     0,   -27,
       0,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,     0,
     -27,   -27,     0,     0,     0,   -27,     0,     0,     0,   -27,
     -27,   -27,   -28,     0,   -28,   -27,   -28,   -28,     0,     0,
     -28,     0,   -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,
       0,   -28,   -28,     0,     0,     0,   -28,     0,     0,     0,
     -28,   -28,   -28,   -31,     0,   -31,   -28,   -31,   -31,     0,
       0,   -31,     0,   -31,   -31,   -31,   -31,   -31,     0,   -31,
     -31,     0,   -31,   -31,     0,     0,     0,   -31,     0,     0,
       0,   -31,   -31,   -31,   -32,     0,   -32,   -31,   -32,   -32,
       0,     0,   -32,     0,   -32,   -32,   -32,   -32,   -32,     0,
     -32,   -32,     0,   -32,   -32,     0,     0,     0,   -32,     0,
       0,     0,   -32,   -32,   -32,   -34,     0,   -34,   -32,   -34,
     -34,     0,     0,   -34,     0,   -34,   -34,   -34,   -34,   -34,
       0,   -34,   -34,     0,   -34,   -34,     0,     0,     0,   -34,
       0,     0,     0,   -34,   -34,   -34,   -30,     0,   -30,   -34,
     -30,   -30,     0,     0,   -30,     0,   -30,   -30,   -30,   -30,
     -30,     0,   -30,   -30,     0,   -30,   -30,     0,     0,     0,
     -30,     0,     0,     0,   -30,   -30,   -30,   -33,     0,   -33,
     -30,   -33,   -33,     0,     0,   -33,     0,   -33,   -33,   -33,
     -33,   -33,     0,   -33,   -33,     0,   -33,   -33,     0,     0,
       0,   -33,     0,     0,     0,   -33,   -33,   -33,   -44,     0,
     -44,   -33,   -44,   -44,     0,     0,   -44,     0,   -44,   -44,
     -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,     0,
       0,     0,   -44,     0,     0,     0,   -44,   -44,   -44,   -45,
       0,   -45,   -44,   -45,   -45,     0,     0,   -45,     0,   -45,
     -45,   -45,   -45,   -45,     0,   -45,   -45,     0,   -45,   -45,
       0,     0,     0,   -45,     0,     0,     0,   -45,   -45,   -45,
     -26,     0,   -26,   -45,   -26,   -26,     0,     0,   -26,     0,
     -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,     0,   -26,
     -26,     0,     0,     0,   -26,     0,     0,     0,   -26,   -26,
     -26,   -40,     0,   -40,   -26,   -40,   -40,     0,     0,   -40,
       0,   -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,     0,
     -40,   -40,     0,     0,     0,   -40,     0,     0,     0,   -40,
     -40,   -40,   -43,     0,   -43,   -40,   -43,   -43,     0,     0,
     -43,     0,   -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,
       0,   -43,   -43,     0,     0,     0,   -43,     0,     0,     0,
     -43,   -43,   -43,   -46,     0,   -46,   -43,   -46,   -46,     0,
       0,   -46,     0,   -46,   -46,   -46,   -46,   -46,     0,   -46,
     -46,     0,   -46,   -46,     0,     0,     0,   -46,     0,     0,
       0,   -46,   -46,   -46,   -47,     0,   -47,   -46,   -47,   -47,
       0,     0,   -47,     0,   -47,   -47,   -47,   -47,   -47,     0,
     -47,   -47,     0,   -47,   -47,     0,     0,     0,   -47,     0,
       0,     0,   -47,   -47,   -47,   -48,     0,   -48,   -47,   -48,
     -48,     0,     0,   -48,     0,   -48,   -48,   -48,   -48,   -48,
       0,   -48,   -48,     0,   -48,   -48,     0,     0,     0,   -48,
       0,     0,     0,   -48,   -48,   -48,   -38,     0,   -38,   -48,
     -38,   -38,     0,     0,   -38,     0,   -38,   -38,   -38,   -38,
     -38,     0,   -38,   -38,     0,   -38,   -38,     0,     0,     0,
     -38,     0,     0,     0,   -38,   -38,   -38,   -39,     0,   -39,
     -38,   -39,   -39,     0,     0,   -39,     0,   -39,   -39,   -39,
     -39,   -39,     0,   -39,   -39,     0,   -39,   -39,     0,     0,
       0,   -39,     0,     0,     0,   -39,   -39,   -39,   -11,     0,
     -11,   -39,   -11,   -11,     0,     0,   -11,     0,   -11,   -11,
     -11,   -11,   -11,     0,   -11,   -11,     0,   -11,   -11,     0,
       0,     0,   -11,     0,     0,     0,   -11,   -11,   -11,   -12,
       0,   -12,   -11,   -12,   -12,     0,     0,   -12,     0,   -12,
     -12,   -12,   -12,   -12,     0,   -12,   -12,     0,   -12,   -12,
       0,     0,     0,   -12,     0,     0,     0,   -12,   -12,   -12,
     -23,     0,   -23,   -12,   -23,   -23,     0,     0,   -23,     0,
     -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,     0,   -23,
     -23,     0,     0,     0,   -23,     0,     0,     0,   -23,   -23,
     -23,    33,     0,    34,   -23,    35,    36,     0,     0,    37,
       0,    38,    39,    40,    41,     0,     0,    43,    44,     0,
      45,    46,   -65,   -65,     0,    47,   -65,   -65,     0,   138,
       0,    48,   -66,   -66,     0,    49,   -66,   -66,   -65,   -67,
     -67,   -65,   -65,   -67,   -67,     0,     0,     0,   -66,     0,
       0,   -66,   -66,     0,   -65,   -67,   -74,   -74,   -67,   -67,
     -74,   -74,   -70,   -70,   -66,     0,   -70,   -70,     0,     0,
       0,   -67,   -74,     0,     0,   -74,   -74,     0,   -70,   -60,
      99,   -70,   -70,   -60,   -60,   -62,   -62,     0,   -74,   -62,
     -62,     0,     0,     0,   -70,   -60,     0,     0,   -60,   -60,
       0,   -62,   -73,   -73,   -62,   -62,   -73,   -73,    96,     0,
     222,   -60,   -59,   -59,   -59,   -59,     0,   -62,   -73,     0,
       0,   -73,   -73,     0,    97,     0,   223,    98,   -59,   224,
     -59,   162,     0,   163,   -73,   164,   165,     0,     0,   -59,
     -59,   -59,     0,     0,     0,     0,     0,   166,   167,     0,
     168,   169,   162,     0,   163,   170,   164,   165,     0,   -69,
     -69,   171,   236,   -69,   -69,     0,     0,     0,   166,   167,
       0,   168,   169,     0,     0,   -69,   170,     0,   -69,   -69,
     -77,   -77,   171,   246,   -77,   -77,     0,   215,   -69,     0,
     -69,     0,     0,     0,     0,     0,   -77,   -78,   -78,   -77,
     -77,   -78,   -78,   -79,   -79,     0,     0,   -79,   -79,   -77,
       0,   -77,     0,   -78,     0,     0,   -78,   -78,     0,   -79,
     -61,   225,   -79,   -79,   -61,   -61,   -78,     0,   -78,     0,
       0,     0,   -79,     0,   -79,     0,   -61,   -63,   -63,   -61,
     -61,   -63,   -63,   -64,   -64,     0,     0,   -64,   -64,   -61,
       0,   -61,     0,   -63,     0,     0,   -63,   -63,     0,   -64,
     -71,   -71,   -64,   -64,   -71,   -71,   -63,     0,   -63,     0,
       0,     0,   -64,     0,   -64,     0,   -71,   -72,   -72,   -71,
     -71,   -72,   -72,   -68,   -68,     0,     0,   -68,   -68,   -71,
       0,   -71,     0,   -72,     0,     0,   -72,   -72,     0,   -68,
     -65,   -65,   -68,   -68,   -65,   -65,   -72,     0,   -72,     0,
       0,     0,   -68,     0,   -68,     0,   -65,   -66,   -66,   -65,
     -65,   -66,   -66,   -67,   -67,     0,     0,   -67,   -67,   -65,
       0,   -65,     0,   -66,     0,     0,   -66,   -66,     0,   -67,
     -74,   -74,   -67,   -67,   -74,   -74,   -66,     0,   -66,     0,
       0,     0,   -67,     0,   -67,     0,   -74,   -70,   -70,   -74,
     -74,   -70,   -70,   -60,   225,     0,     0,   -60,   -60,   -74,
       0,   -74,     0,   -70,     0,     0,   -70,   -70,     0,   -60,
     -62,   -62,   -60,   -60,   -62,   -62,   -70,     0,   -70,     0,
       0,     0,   -60,     0,   -60,     0,   -62,   -73,   -73,   -62,
     -62,   -73,   -73,     0,     0,     0,     0,     0,     0,   -62,
       0,   -62,     0,   -73,     0,     0,   -73,   -73,   139,     0,
     140,     0,   141,   142,     0,     0,   -73,   139,   -73,   140,
       0,   141,   142,     0,   158,   144,     0,   145,   146,   -55,
     -55,   104,   147,   158,   144,     0,   145,   146,   148,     0,
     259,   147,     0,     0,    33,   -55,    34,   148,    35,    36,
       0,     0,     0,   139,   -55,   140,   -55,   141,   142,     0,
      43,    44,     0,    45,    46,     0,     0,     0,    47,   143,
     144,     0,   145,   146,    48,     0,    33,   147,    34,     0,
      35,    36,     0,   148,     0,   162,     0,   163,     0,   164,
     165,     0,    75,    44,     0,    45,    46,     0,     0,     0,
      47,   166,   167,     0,   168,   169,    48,     0,   139,   170,
     140,     0,   141,   142,     0,   171,     0,   -69,   -69,     0,
       0,   -69,   -69,     0,   158,   144,     0,   145,   146,     0,
       0,     0,   147,   -69,     0,     0,   -69,   -69,   148,   -69,
     -69,     0,     0,   -69,   -69,   202,   -69,   213,     0,     0,
       0,     0,     0,     0,     0,   -69,   -78,   -78,   -69,   -69,
     -78,   -78,     0,     0,     0,     0,     0,   202,   -69,     0,
       0,     0,   -78,   -79,   -79,   -78,   -78,   -79,   -79,   -61,
     212,     0,     0,   -61,   -61,   -78,     0,     0,     0,   -79,
       0,     0,   -79,   -79,     0,   -61,   -63,   -63,   -61,   -61,
     -63,   -63,   -79,     0,     0,     0,     0,     0,   -61,     0,
       0,     0,   -63,   -64,   -64,   -63,   -63,   -64,   -64,   -71,
     -71,     0,     0,   -71,   -71,   -63,     0,     0,     0,   -64,
       0,     0,   -64,   -64,     0,   -71,   -72,   -72,   -71,   -71,
     -72,   -72,   -64,     0,     0,     0,     0,     0,   -71,     0,
       0,     0,   -72,   -68,   -68,   -72,   -72,   -68,   -68,   -65,
     -65,     0,     0,   -65,   -65,   -72,     0,     0,     0,   -68,
       0,     0,   -68,   -68,     0,   -65,   -66,   -66,   -65,   -65,
     -66,   -66,   -68,     0,     0,     0,     0,     0,   -65,     0,
       0,     0,   -66,   -67,   -67,   -66,   -66,   -67,   -67,   -74,
     -74,     0,     0,   -74,   -74,   -66,     0,     0,     0,   -67,
       0,     0,   -67,   -67,     0,   -74,   -70,   -70,   -74,   -74,
     -70,   -70,   -67,     0,     0,     0,     0,     0,   -74,     0,
       0,     0,   -70,   -60,   212,   -70,   -70,   -60,   -60,   -62,
     -62,     0,     0,   -62,   -62,   -70,     0,     0,     0,   -60,
       0,     0,   -60,   -60,     0,   -62,   -73,   -73,   -62,   -62,
     -73,   -73,   -60,   -57,   -57,     0,     0,     0,   -62,     0,
       0,     0,   -73,   209,     0,   -73,   -73,   -59,   -59,   -57,
       0,   140,     0,   141,   142,   -73,     0,     0,   -57,   210,
     -57,     0,   211,   -59,     0,   143,   144,     0,   145,   146,
     -58,   -58,   -59,   147,   163,     0,   164,   165,     0,   148,
       0,     0,     0,     0,     0,     0,   -58,     0,   166,   167,
       0,   168,   169,     0,     0,   -58,   170,   -58,     0,     0,
       0,     0,   171
};

static const yytype_int16 yycheck[] =
{
      27,    81,    34,   119,   138,   119,     0,     1,    39,   119,
       0,     7,   119,    45,    46,    47,    48,   202,   132,     7,
       8,    15,   136,     0,     1,     0,     1,   119,   119,   119,
     215,     0,     1,     0,     1,    23,     0,     1,    15,    35,
      15,    35,   119,     1,    32,    77,    15,    78,    15,    81,
      81,    15,    84,   133,    85,   189,    17,    15,    35,    31,
      35,     0,     1,     0,     1,    17,    35,    99,    35,     0,
       1,    35,     0,     1,     0,     1,    15,    35,    15,    32,
       1,     1,     7,     8,    15,    29,    31,    15,   119,    15,
       7,     8,   119,   125,    15,    15,    35,    15,    35,     7,
       8,   133,   133,    32,    35,    34,    23,    35,   140,    35,
      35,    32,    32,   145,   146,   147,   148,     7,    35,     7,
       8,     7,     8,    30,     3,     4,    31,    35,     7,     8,
       7,   163,    48,   213,     7,    23,   168,   169,   170,   171,
      19,    16,    17,    22,    23,    35,    32,    35,   264,   181,
     264,   183,   232,    31,   264,   186,    35,   264,    35,    32,
     276,    77,   276,    16,    17,    81,   276,     7,    84,   276,
     202,    31,   264,   264,   264,   207,   208,   209,   210,   211,
     212,   213,   213,   215,   276,   276,   276,   264,   220,   221,
     222,   223,   224,   225,   274,    35,   228,    35,   229,   276,
     232,   232,     7,     8,    16,    17,     3,     4,     0,   125,
       7,     8,    31,     5,     7,     8,    35,   133,    23,     7,
       8,    35,    19,     7,   140,    22,    23,    32,    35,   145,
     146,   147,   148,   264,    31,    23,    33,   264,    35,    32,
      48,    34,   274,   274,    32,   276,    34,   163,    32,   276,
      34,    17,   168,   169,   170,   171,     7,     8,     3,     4,
       7,     8,     7,     8,    31,   181,    35,   183,    35,    77,
      35,    17,    23,    81,    19,     7,    84,    22,    23,    32,
      32,    34,     7,     8,    35,    32,   202,    34,     7,     8,
      35,   207,   208,   209,   210,   211,   212,   213,    23,   215,
      32,     7,    34,    32,   220,   221,   222,   223,   224,   225,
      35,    32,   228,    32,     3,     4,   232,   125,     7,     8,
       7,     8,    32,    35,    34,   133,    32,    35,     7,     8,
      19,    35,   140,    22,    23,    35,    23,   145,   146,   147,
     148,    48,    31,    35,    23,    32,    35,    34,     3,     4,
       7,     8,     7,     8,     7,   163,    35,     7,   274,    32,
     168,   169,   170,   171,    19,     7,    23,    22,    23,     3,
      77,     5,     6,   181,    81,   183,    32,    84,    35,    32,
      35,    34,    32,    17,    18,     7,    20,    21,    31,    35,
      32,    25,    30,    32,   202,    34,    48,    31,     7,   207,
     208,   209,   210,   211,   212,   213,     7,   215,    35,    32,
      32,    34,   220,   221,   222,   223,   224,   225,   125,    32,
     228,    34,    30,    32,   232,    77,   133,    32,    32,    81,
      34,    32,    84,   140,     7,     8,    31,    31,   145,   146,
     147,   148,    32,    95,    34,    97,    98,    32,    31,    34,
      23,    48,     7,     8,    17,    32,   163,    34,    32,    32,
      35,   168,   169,   170,   171,    32,   274,    32,    23,    35,
      32,    35,     5,   125,   181,    35,   183,    32,     3,     4,
      77,   133,     7,     8,    81,    28,    -1,    84,    -1,    -1,
      -1,    -1,    53,    -1,    19,   202,   148,    22,    23,    96,
     207,   208,   209,   210,   211,   212,   213,    -1,   215,    -1,
      35,    -1,    -1,   220,   221,   222,   223,   224,   225,   171,
      -1,   228,     3,     4,    -1,   232,     7,     8,   125,   181,
      -1,   183,     7,     8,    -1,    -1,   133,    -1,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    23,    -1,
     202,   148,    48,    -1,    35,   207,   208,    32,   210,   211,
      -1,   213,    -1,   215,    -1,    -1,    -1,   274,   220,   221,
      -1,   223,   224,     1,   171,     3,   228,     5,     6,    -1,
     232,    77,    -1,    -1,   181,    81,   183,    -1,    84,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    31,    32,   202,    -1,    48,    -1,    -1,
     207,   208,   209,   210,   211,    -1,   213,    -1,   215,    -1,
      -1,    -1,   274,   220,   221,   222,   223,   224,    -1,   125,
      -1,   228,     7,     8,    -1,   232,    77,   133,    -1,    -1,
      81,    -1,    -1,    84,    -1,    -1,     3,     4,    23,    -1,
       7,     8,   148,    94,     3,     4,    -1,    32,     7,     8,
      48,    -1,    19,     3,     4,    22,    23,     7,     8,    -1,
      19,    -1,    -1,    22,    23,   171,    -1,   274,    35,    19,
      48,    -1,    22,    23,   125,   181,    35,   183,    -1,    77,
      -1,    -1,   133,    81,    -1,    35,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,   202,   148,    -1,    77,
      -1,   207,   208,    81,   210,   211,    84,   213,    -1,   215,
      -1,    -1,    -1,    -1,   220,   221,    -1,   223,   224,    -1,
     171,    -1,   228,    -1,    -1,    -1,   232,   125,    -1,    -1,
     181,    -1,   183,     3,     4,   133,    -1,     7,     8,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,   125,    -1,    19,
     148,   202,    22,    23,    -1,   133,   207,    -1,    -1,    -1,
      -1,    -1,   213,    -1,   215,    35,    -1,    -1,   274,   220,
     148,    -1,    -1,   171,    -1,    -1,    -1,   228,    -1,    -1,
      -1,   232,    -1,   181,    -1,   183,     1,    -1,     3,    -1,
       5,     6,    -1,   171,     9,    -1,    11,    12,    13,    14,
      -1,    -1,    17,    18,   202,    20,    21,    -1,    -1,    -1,
      25,     7,     8,    -1,    29,   213,    31,   215,    -1,    -1,
      35,    -1,    -1,   274,   202,    -1,    -1,    23,     3,     4,
     228,    -1,     7,     8,   232,   213,    32,   215,    34,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    23,    -1,
     228,     1,    -1,     3,   232,     5,     6,    32,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,   274,    -1,    -1,    29,
      30,    31,    -1,    -1,    -1,    35,    -1,   265,    -1,     1,
      -1,     3,    -1,     5,     6,    -1,   274,     9,    10,    11,
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
      -1,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,     1,    -1,     3,    35,     5,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    31,     1,    -1,     3,    35,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
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
      -1,    11,    12,    13,    14,    -1,    -1,    17,    18,    -1,
      20,    21,     3,     4,    -1,    25,     7,     8,    -1,    29,
      -1,    31,     3,     4,    -1,    35,     7,     8,    19,     3,
       4,    22,    23,     7,     8,    -1,    -1,    -1,    19,    -1,
      -1,    22,    23,    -1,    35,    19,     3,     4,    22,    23,
       7,     8,     3,     4,    35,    -1,     7,     8,    -1,    -1,
      -1,    35,    19,    -1,    -1,    22,    23,    -1,    19,     3,
       4,    22,    23,     7,     8,     3,     4,    -1,    35,     7,
       8,    -1,    -1,    -1,    35,    19,    -1,    -1,    22,    23,
      -1,    19,     3,     4,    22,    23,     7,     8,     3,    -1,
       3,    35,     7,     8,     7,     8,    -1,    35,    19,    -1,
      -1,    22,    23,    -1,    19,    -1,    19,    22,    23,    22,
      23,     1,    -1,     3,    35,     5,     6,    -1,    -1,    32,
      35,    34,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,     1,    -1,     3,    25,     5,     6,    -1,     3,
       4,    31,    32,     7,     8,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    19,    25,    -1,    22,    23,
       3,     4,    31,    32,     7,     8,    -1,    31,    32,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    19,     3,     4,    22,
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
      23,     7,     8,     3,     4,    -1,    -1,     7,     8,    32,
      -1,    34,    -1,    19,    -1,    -1,    22,    23,    -1,    19,
       3,     4,    22,    23,     7,     8,    32,    -1,    34,    -1,
      -1,    -1,    32,    -1,    34,    -1,    19,     3,     4,    22,
      23,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,    19,    -1,    -1,    22,    23,     1,    -1,
       3,    -1,     5,     6,    -1,    -1,    32,     1,    34,     3,
      -1,     5,     6,    -1,    17,    18,    -1,    20,    21,     7,
       8,    24,    25,    17,    18,    -1,    20,    21,    31,    -1,
      24,    25,    -1,    -1,     1,    23,     3,    31,     5,     6,
      -1,    -1,    -1,     1,    32,     3,    34,     5,     6,    -1,
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
       7,     8,    32,     7,     8,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    19,     3,    -1,    22,    23,     7,     8,    23,
      -1,     3,    -1,     5,     6,    32,    -1,    -1,    32,    19,
      34,    -1,    22,    23,    -1,    17,    18,    -1,    20,    21,
       7,     8,    32,    25,     3,    -1,     5,     6,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    32,    25,    34,    -1,    -1,
      -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    15,    35,    38,    39,    40,    42,    43,    46,
      16,    17,     0,    40,    31,    17,    35,    44,    35,     1,
      15,    41,    45,    47,    48,    16,    17,    32,    34,    17,
      29,    49,    48,     1,     3,     5,     6,     9,    11,    12,
      13,    14,    15,    17,    18,    20,    21,    25,    31,    35,
      42,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    73,    17,    69,    31,    31,    57,
      31,    31,    16,    17,    31,    33,    69,    69,    69,    63,
      30,    52,    35,     7,     8,    23,     3,    19,    22,     4,
      63,    57,    35,    17,    24,    57,    17,    32,    63,    72,
      57,    32,    64,    65,    66,    68,    66,    66,    69,    32,
      35,    32,    32,    32,    32,    34,    53,    63,    35,    35,
      35,    63,    10,    35,    53,    57,    32,    53,    29,     1,
       3,     5,     6,    17,    18,    20,    21,    25,    31,    64,
      65,    66,    67,    68,    69,    70,    71,    73,    17,    62,
      63,    35,     1,     3,     5,     6,    17,    18,    20,    21,
      25,    31,    64,    65,    66,    67,    68,    69,    70,    71,
      73,     7,    35,     7,     9,    11,    12,    13,    14,    29,
      35,    49,    54,    55,    56,    57,    58,    59,    60,    61,
      50,    69,    31,    69,    69,    69,    63,     8,    23,     3,
      19,    22,     4,    33,    69,    31,    69,    69,    69,    63,
       8,    23,     3,    19,    22,     4,    64,    64,    31,    31,
      57,    31,    31,    50,    35,    30,    32,    72,    32,    65,
      66,    68,    66,    66,    69,    57,    32,    72,    32,    65,
      66,    68,    66,    66,    69,    63,    57,    35,    17,    24,
      57,    30,    32,    32,    32,    35,    32,    32,    32,    53,
      63,    35,    35,    35,    35,    57,    32,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    41,
      41,    42,    42,    44,    43,    45,    45,    46,    46,    47,
      47,    47,    48,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      56,    57,    57,    58,    59,    59,    60,    61,    61,    62,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    70,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       3,     3,     4,     0,     6,     1,     0,     2,     3,     1,
       3,     1,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     7,     9,
       2,     1,     1,     3,     1,     1,     5,     5,     5,     3,
       3,     1,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     1,     2,     2,     2,     2,     1,
       3,     1,     1,     4,     3,     1,     3,     1,     1,     1
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
#line 129 "src/syntax.y"
                        {
		//root = *createAstNode("initial", DEBUG_AST);	// non-printable
		root.node_name = strdup("initial");
		root.printable = DEBUG_AST;
		(yyval.ast) = &root;
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2156 "src/syntax.tab.c"
    break;

  case 3: /* declaration_list: declaration_list decl  */
#line 140 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("declaration list", 1);	// printable
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2167 "src/syntax.tab.c"
    break;

  case 4: /* declaration_list: decl  */
#line 146 "src/syntax.y"
              {
		//$$ = createAstNode("declaration list", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2178 "src/syntax.tab.c"
    break;

  case 5: /* decl: var_declaration  */
#line 155 "src/syntax.y"
                       {
		//$$ = createAstNode("decl", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2189 "src/syntax.tab.c"
    break;

  case 6: /* decl: func_definition  */
#line 161 "src/syntax.y"
                         {
		//$$ = createAstNode("decl", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2200 "src/syntax.tab.c"
    break;

  case 7: /* decl: ';'  */
#line 167 "src/syntax.y"
             {
		char nop[50];
		strcpy(nop, "no operation [");
		strcat(nop, RED);
		strcat(nop, ";");
		strcat(nop, WHITE);
		strcat(nop, "]");
		(yyval.ast) = createAstNode(nop, 1);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2215 "src/syntax.tab.c"
    break;

  case 8: /* decl: error  */
#line 177 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
		//freeNode(&root);
		yyerrok;
	}
#line 2226 "src/syntax.tab.c"
    break;

  case 9: /* var_definition: SIMPLE_TYPE ID  */
#line 186 "src/syntax.y"
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
#line 2246 "src/syntax.tab.c"
    break;

  case 10: /* var_definition: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 201 "src/syntax.y"
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
#line 2270 "src/syntax.tab.c"
    break;

  case 11: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 223 "src/syntax.y"
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
#line 2290 "src/syntax.tab.c"
    break;

  case 12: /* var_declaration: SIMPLE_TYPE COMPOUND_TYPE ID ';'  */
#line 238 "src/syntax.y"
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
#line 2314 "src/syntax.tab.c"
    break;

  case 13: /* $@1: %empty  */
#line 260 "src/syntax.y"
                             {
		func_context = 1;
		insertScope(++last_scope, &contextList);
	}
#line 2323 "src/syntax.tab.c"
    break;

  case 14: /* func_definition: func_declaration '(' $@1 params.opt ')' stmts  */
#line 263 "src/syntax.y"
                               {
		(yyval.ast) = createAstNode("function definition", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-5].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
		removeScope(&contextList);
	}
#line 2336 "src/syntax.tab.c"
    break;

  case 15: /* params.opt: param_list  */
#line 274 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("params optional", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2346 "src/syntax.tab.c"
    break;

  case 16: /* params.opt: %empty  */
#line 279 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("params optional empty", DEBUG_AST); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2355 "src/syntax.tab.c"
    break;

  case 17: /* func_declaration: SIMPLE_TYPE ID  */
#line 286 "src/syntax.y"
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
		strcpy(function_name, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2380 "src/syntax.tab.c"
    break;

  case 18: /* func_declaration: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 306 "src/syntax.y"
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
		strcpy(function_name, (yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2409 "src/syntax.tab.c"
    break;

  case 19: /* param_list: param  */
#line 333 "src/syntax.y"
             {
		//$$ = createAstNode("param list", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2420 "src/syntax.tab.c"
    break;

  case 20: /* param_list: param_list ',' param  */
#line 339 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("param list", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2431 "src/syntax.tab.c"
    break;

  case 21: /* param_list: error  */
#line 345 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
		//freeNode(&root);
		yyerrok;
	}
#line 2442 "src/syntax.tab.c"
    break;

  case 22: /* param: var_definition  */
#line 354 "src/syntax.y"
                      {
		//$$ = createAstNode("param", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
		setupParameters(&symbolTable);
	}
#line 2454 "src/syntax.tab.c"
    break;

  case 23: /* stmts: '{' stmt_list.opt '}'  */
#line 364 "src/syntax.y"
                             {
		//$$ = createAstNode("stmts", 1);
		//$$->children[0] = $2;
		(yyval.ast) = (yyvsp[-1].ast);
		//insertAstNode(&astList, $$);
	}
#line 2465 "src/syntax.tab.c"
    break;

  case 24: /* stmt_list.opt: stmt_list  */
#line 373 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list optional", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2475 "src/syntax.tab.c"
    break;

  case 25: /* stmt_list.opt: %empty  */
#line 378 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list empty", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2484 "src/syntax.tab.c"
    break;

  case 26: /* stmt_list: stmt_list stmt.item  */
#line 385 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("stmt list", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2495 "src/syntax.tab.c"
    break;

  case 27: /* stmt_list: stmt.item  */
#line 391 "src/syntax.y"
                   {
		//$$ = createAstNode("stmt list", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2506 "src/syntax.tab.c"
    break;

  case 28: /* stmt.item: stmt  */
#line 400 "src/syntax.y"
            {
		//$$ = createAstNode("stmt item", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2517 "src/syntax.tab.c"
    break;

  case 29: /* stmt.item: var_declaration  */
#line 406 "src/syntax.y"
                         {
		//$$ = createAstNode("stmt item", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2528 "src/syntax.tab.c"
    break;

  case 30: /* stmt: return_stmt  */
#line 415 "src/syntax.y"
                   {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2539 "src/syntax.tab.c"
    break;

  case 31: /* stmt: select_stmt  */
#line 421 "src/syntax.y"
                     {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2550 "src/syntax.tab.c"
    break;

  case 32: /* stmt: iter_stmt  */
#line 427 "src/syntax.y"
                   {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2561 "src/syntax.tab.c"
    break;

  case 33: /* stmt: io_stmt  */
#line 433 "src/syntax.y"
                 {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2572 "src/syntax.tab.c"
    break;

  case 34: /* stmt: exp_stmt  */
#line 439 "src/syntax.y"
                  {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2583 "src/syntax.tab.c"
    break;

  case 35: /* stmt: ';'  */
#line 445 "src/syntax.y"
             {
		char nop[50];
		strcpy(nop, "no operation [");
		strcat(nop, RED);
		strcat(nop, ";");
		strcat(nop, WHITE);
		strcat(nop, "]");
		(yyval.ast) = createAstNode(nop, 1);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2598 "src/syntax.tab.c"
    break;

  case 36: /* stmt: stmts  */
#line 455 "src/syntax.y"
               {
		//$$ = createAstNode("stmt", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2609 "src/syntax.tab.c"
    break;

  case 37: /* select_stmt: IF '(' simple_exp ')' stmt  */
#line 464 "src/syntax.y"
                                             {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2620 "src/syntax.tab.c"
    break;

  case 38: /* select_stmt: IF '(' simple_exp ')' stmt ELSE stmt  */
#line 470 "src/syntax.y"
                                              {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-4].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2632 "src/syntax.tab.c"
    break;

  case 39: /* iter_stmt: FOR '(' exp ';' simple_exp ';' exp ')' stmt  */
#line 480 "src/syntax.y"
                                                   {
		(yyval.ast) = createAstNode("iter stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-6].ast);
		(yyval.ast)->children[1] = (yyvsp[-4].ast);
		(yyval.ast)->children[2] = (yyvsp[-2].ast);
		(yyval.ast)->children[3] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2645 "src/syntax.tab.c"
    break;

  case 40: /* exp_stmt: exp ';'  */
#line 491 "src/syntax.y"
               {
		//$$ = createAstNode("expression", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[-1].ast);
		//insertAstNode(&astList, $$);
	}
#line 2656 "src/syntax.tab.c"
    break;

  case 41: /* exp: assign_exp  */
#line 500 "src/syntax.y"
                  {
		//$$ = createAstNode("exp stmt", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2667 "src/syntax.tab.c"
    break;

  case 42: /* exp: simple_exp  */
#line 506 "src/syntax.y"
                    {
		//$$ = createAstNode("exp stmt", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2678 "src/syntax.tab.c"
    break;

  case 43: /* return_stmt: RETURN exp ';'  */
#line 515 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("return stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
		//checkType($$, check_func_type, function_name, $1.line, $1.column, &semantic_errors);
	}
#line 2689 "src/syntax.tab.c"
    break;

  case 44: /* io_stmt: in_stmt  */
#line 524 "src/syntax.y"
               {
		//$$ = createAstNode("in/out stmt", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2700 "src/syntax.tab.c"
    break;

  case 45: /* io_stmt: out_stmt  */
#line 530 "src/syntax.y"
                  {
		//$$ = createAstNode("in/out stmt", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2711 "src/syntax.tab.c"
    break;

  case 46: /* in_stmt: INPUT '(' ID ')' ';'  */
#line 539 "src/syntax.y"
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
#line 2729 "src/syntax.tab.c"
    break;

  case 47: /* out_stmt: OUTPUT '(' STRING ')' ';'  */
#line 555 "src/syntax.y"
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
#line 2744 "src/syntax.tab.c"
    break;

  case 48: /* out_stmt: OUTPUT '(' exp ')' ';'  */
#line 565 "src/syntax.y"
                                {
		char output_type[200];
		(yyval.ast) = createAstNode("output stmt", 1);
		strcpy(output_type, (yyvsp[-4].lexeme).lexeme_string);
		strcat(output_type, "()");
		(yyval.ast)->token_name = strdup(output_type);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2758 "src/syntax.tab.c"
    break;

  case 49: /* assign_exp: ID '=' exp  */
#line 577 "src/syntax.y"
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
#line 2775 "src/syntax.tab.c"
    break;

  case 50: /* simple_exp: simple_exp LOGICAL_OR and_exp  */
#line 592 "src/syntax.y"
                                     {
		(yyval.ast) = createAstNode("simple exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2787 "src/syntax.tab.c"
    break;

  case 51: /* simple_exp: and_exp  */
#line 599 "src/syntax.y"
                 {
		//$$ = createAstNode("simple exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2798 "src/syntax.tab.c"
    break;

  case 52: /* simple_exp: error  */
#line 605 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		insertAstNode(&astList, (yyval.ast));
		//freeNode(&root);
		yyerrok;
	}
#line 2809 "src/syntax.tab.c"
    break;

  case 53: /* and_exp: and_exp LOGICAL_AND rel_exp  */
#line 614 "src/syntax.y"
                                   {
		(yyval.ast) = createAstNode("and exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2821 "src/syntax.tab.c"
    break;

  case 54: /* and_exp: rel_exp  */
#line 621 "src/syntax.y"
                 {
		//$$ = createAstNode("and exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2832 "src/syntax.tab.c"
    break;

  case 55: /* rel_exp: rel_exp RELATIONAL list_exp  */
#line 630 "src/syntax.y"
                                   {
		(yyval.ast) = createAstNode("rel exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2844 "src/syntax.tab.c"
    break;

  case 56: /* rel_exp: list_exp  */
#line 637 "src/syntax.y"
                  {
		//$$ = createAstNode("rel exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2855 "src/syntax.tab.c"
    break;

  case 57: /* list_exp: sum_exp LIST_CONSTR list_exp  */
#line 646 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("list exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2867 "src/syntax.tab.c"
    break;

  case 58: /* list_exp: sum_exp LIST_FUNC list_exp  */
#line 653 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("list exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2879 "src/syntax.tab.c"
    break;

  case 59: /* list_exp: sum_exp  */
#line 660 "src/syntax.y"
                 {
		//$$ = createAstNode("list exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2890 "src/syntax.tab.c"
    break;

  case 60: /* sum_exp: sum_exp ADD mul_exp  */
#line 669 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("sum exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2902 "src/syntax.tab.c"
    break;

  case 61: /* sum_exp: mul_exp  */
#line 676 "src/syntax.y"
                 {
		//$$ = createAstNode("sum exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2913 "src/syntax.tab.c"
    break;

  case 62: /* mul_exp: mul_exp MUL unary_exp  */
#line 685 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("mul exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2925 "src/syntax.tab.c"
    break;

  case 63: /* mul_exp: unary_exp  */
#line 692 "src/syntax.y"
                   {
		//$$ = createAstNode("mul exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2936 "src/syntax.tab.c"
    break;

  case 64: /* unary_exp: factor  */
#line 701 "src/syntax.y"
              {
		//$$ = createAstNode("unary exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 2947 "src/syntax.tab.c"
    break;

  case 65: /* unary_exp: LIST_OP unary_exp  */
#line 707 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2958 "src/syntax.tab.c"
    break;

  case 66: /* unary_exp: LIST_DESTR unary_exp  */
#line 713 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2969 "src/syntax.tab.c"
    break;

  case 67: /* unary_exp: OP_OVERLOAD unary_exp  */
#line 719 "src/syntax.y"
                               {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2980 "src/syntax.tab.c"
    break;

  case 68: /* unary_exp: ADD unary_exp  */
#line 725 "src/syntax.y"
                       {
		char signal_type[100];
		//char signal = $1.lexeme_string[0];
		strcpy(signal_type, "signed unary exp");
		strcat(signal_type, " [");
		strcat(signal_type, RED);
		strcat(signal_type, (yyvsp[-1].lexeme).lexeme_string);
		strcat(signal_type, WHITE);
		strcat(signal_type, "]");
		(yyval.ast) = createAstNode(signal_type, 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
		//insertSignalList(signal, &signalList);
	}
#line 2999 "src/syntax.tab.c"
    break;

  case 69: /* factor: ID  */
#line 742 "src/syntax.y"
          {
		char id_type[15];
		strcpy(id_type, getContext(&symbolTable, &contextList, (yyvsp[0].lexeme).lexeme_string, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("id", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup(id_type);
		(yyval.ast)->node_type = strdup(id_type);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3015 "src/syntax.tab.c"
    break;

  case 70: /* factor: '(' simple_exp ')'  */
#line 753 "src/syntax.y"
                            {
		//$$ = createAstNode("factor exp", DEBUG_AST);
		//$$->children[0] = $2;
		(yyval.ast) = (yyvsp[-1].ast);
		//insertAstNode(&astList, $$);
	}
#line 3026 "src/syntax.tab.c"
    break;

  case 71: /* factor: func_call  */
#line 759 "src/syntax.y"
                   {
		//$$ = createAstNode("factor exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 3037 "src/syntax.tab.c"
    break;

  case 72: /* factor: constant  */
#line 765 "src/syntax.y"
                  {
		//$$ = createAstNode("factor exp", DEBUG_AST);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 3048 "src/syntax.tab.c"
    break;

  case 73: /* func_call: ID '(' func_params ')'  */
#line 774 "src/syntax.y"
                              {
		char func_id[200];
		char func_type[15];
		strcpy(func_type, getContext(&symbolTable, &contextList, (yyvsp[-3].lexeme).lexeme_string, (yyvsp[-3].lexeme).line, (yyvsp[-3].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("func call", 1);
		strcpy(func_id, (yyvsp[-3].lexeme).lexeme_string);
		strcat(func_id, "()");
		(yyval.ast)->token_name = strdup(func_id);
		(yyval.ast)->token_type = strdup(func_type);
		(yyval.ast)->token_line = (yyvsp[-3].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-3].lexeme).column;
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
		checkFunctionCall(&symbolTable, &contextList, (yyvsp[-3].lexeme).lexeme_string, (yyvsp[-3].lexeme).line, (yyvsp[-3].lexeme).column, func_params_counter, &semantic_errors);
		func_params_counter = 0;
	}
#line 3069 "src/syntax.tab.c"
    break;

  case 74: /* func_call: ID '(' ')'  */
#line 790 "src/syntax.y"
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
#line 3088 "src/syntax.tab.c"
    break;

  case 75: /* func_params: simple_exp  */
#line 807 "src/syntax.y"
                  {
		func_params_counter+= 1;
		//$$ = createAstNode("func params", 1);
		//$$->children[0] = $1;
		(yyval.ast) = (yyvsp[0].ast);
		//insertAstNode(&astList, $$);
	}
#line 3100 "src/syntax.tab.c"
    break;

  case 76: /* func_params: func_params ',' simple_exp  */
#line 814 "src/syntax.y"
                                    {
		func_params_counter+= 1;
		(yyval.ast) = createAstNode("func params", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 3112 "src/syntax.tab.c"
    break;

  case 77: /* constant: INTEGER  */
#line 824 "src/syntax.y"
               {
		/*char signed_integer[100];
		char signal;
		strcpy(signed_integer, "\0");
		while(signalListNotEmpty(&signalList)){
			signal = removeSignalList(&signalList);
			printf("SIGNAL -> %c", signal);
			strncat(signed_integer, &signal, 1);
		}

		strcat(signed_integer, $1.lexeme_string);
		*/
		(yyval.ast) = createAstNode("int constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup("int");
		(yyval.ast)->node_type = strdup("int");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3137 "src/syntax.tab.c"
    break;

  case 78: /* constant: REAL  */
#line 844 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("real constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup("float");
		(yyval.ast)->node_type = strdup("float");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3151 "src/syntax.tab.c"
    break;

  case 79: /* constant: NIL_CONSTANT  */
#line 853 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("nil constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_type = strdup("nil");
		(yyval.ast)->node_type = strdup("int list");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3165 "src/syntax.tab.c"
    break;


#line 3169 "src/syntax.tab.c"

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

#line 864 "src/syntax.y"


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

	if(syntax_errors == 0){
		updateSignal(&root);	// update signal (int/real constants)... i think it will be useful at TAC
		printAST(&root);
	}else{
		printf("\n%s~> AST tree will not be printed, due to syntax error(s).%s\n", RED, WHITE);
	}

	printTable(&symbolTable);

	if(syntax_errors == 0)
		printf("\n%sSyntax analysis finished without error(s).%s\n", GREEN, WHITE);
	else
		printf("\n%sSyntax analysis finished with %d error(s).%s\n", RED, syntax_errors, WHITE);

	if(semantic_errors == 0)
		printf("%sSemantic analysis finished without error(s).%s\n", GREEN, WHITE);
	else
		printf("%sSemantic analysis finished with %d error(s).%s\n", RED, semantic_errors, WHITE);

	freeNode(&root);
	freeSymbols(&symbolTable);
	freeContextList(&contextList);
	yylex_destroy();
	return 0;
}

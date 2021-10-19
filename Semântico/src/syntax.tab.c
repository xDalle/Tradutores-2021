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

	#define WHITE "\x1b[0m"
	#define RED "\x1b[31m"
	#define GREEN "\x1b[32m"
	#define YELLOW "\x1b[33m"
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
	extern int lexical_errors;
	int error_comm = 0;
	int error_signal = 0;

	static int syntax_errors = 0;	
	static int semantic_errors = 0;

	int func_params_counter = 0;		// incremented by the number of params in function call
	int has_return = 0;
	int return_line;
	int return_column;

	char return_type[15];
	char function_type[15];

	extern Ast root;
	extern AstList astList;
	extern Table symbolTable;
	extern Context contextList;
	extern ParameterTypeList parameterTypeList;

#line 118 "src/syntax.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3079

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  281

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
       0,   142,   142,   153,   159,   165,   168,   171,   176,   182,
     191,   207,   230,   246,   269,   269,   344,   349,   356,   373,
     397,   400,   406,   415,   422,   428,   433,   440,   446,   452,
     455,   461,   464,   467,   470,   473,   476,   481,   487,   493,
     499,   509,   520,   526,   529,   535,   557,   560,   566,   581,
     591,   603,   670,   707,   710,   719,   756,   762,   817,   823,
     845,   867,   873,   910,   916,   953,   959,   962,   976,   990,
     997,  1015,  1026,  1029,  1032,  1038,  1055,  1073,  1080,  1091,
    1100,  1109
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

#define YYPACT_NINF (-137)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,    24,    67,    26,    30,     6,    32,    34,    42,    71,
      -9,    20,     9,  -137,    73,     4,    47,    90,    97,    95,
     -11,   198,   179,    87,   188,   238,    49,   249,    93,   142,
     310,  1443,   206,   330,     3,  3010,   363,   594,   103,   120,
    2719,   140,   168,   221,   523,   628,  3010,  3010,  3010,  1474,
    2742,  1505,  1536,  1567,   199,  1598,  1629,  1660,  1691,  1722,
    1753,   184,  1784,  1815,  1846,  1877,   214,    57,    72,   113,
     119,   514,   635,   699,   823,  2268,  2278,   255,  2285,  2742,
    2719,   215,   243,   316,   252,   247,  2402,  2719,  2302,  2308,
    2325,    68,   208,  1908,  1939,  3010,  3010,  3010,  3010,  3010,
    3010,  3010,   128,   254,  1970,   260,   270,   283,   281,  2331,
     233,   345,   294,  2348,   138,   181,   189,  2354,   268,   277,
    2371,   759,  2751,   297,   300,   303,  2377,  2774,   804,    69,
    2001,  2032,  2063,   239,  2249,  2783,  2094,   292,  2249,  2125,
    1443,   136,  3039,   506,  2835,  2809,  2841,  3039,  3039,  3039,
    2742,   272,   557,   617,  3015,  2843,  2873,  2875,  2881,  2907,
    2803,   313,   194,  2156,   380,  3048,  2470,  2487,  2449,  2493,
    3048,  3048,  3048,  2742,   445,   323,   346,  2379,  2510,  2527,
    2533,  2550,  2567,  3039,  2187,  3048,   256,   327,  2719,   334,
     342,   874,  1443,   916,   947,   978,  1009,  1040,   341,  1071,
    1102,  1133,  1164,   351,  2913,  2423,  2915,  2945,  2947,   210,
    3039,  3039,  3039,  3039,  3039,  3039,  2783,  2573,  2444,  2590,
    2607,  2613,   220,  3048,  3048,  3048,  3048,  3048,  3048,   434,
     553,  2742,  2719,   360,   390,  2710,   398,  1195,  2218,  2953,
     385,  2979,   687,   697,  2985,   830,   836,  2987,   365,  2630,
     393,  2647,   403,   425,  2653,   657,   709,  2670,   367,   394,
    1226,   399,   402,   404,  1257,  3017,  2687,   759,  2751,   395,
     405,   414,  1288,    78,  1319,  1350,  1381,  2783,   418,   759,
    1412
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
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
       0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,   454,  -137,    81,  -137,  -137,  -137,  -137,
    -137,   432,   -28,  -136,  -137,   408,  -118,  -120,  -114,  -112,
     -32,  -109,  -103,   -93,   -92,   -72,   647,   289,   573,   368,
     526,   461,   -33,    83,   178,   -77,   273
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    22,    52,     9,    18,    23,    10,
      24,    25,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   111,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   195,    78,   128,   203,   -14,    13,   196,    81,   197,
     -54,   161,   199,    88,    89,    90,   136,   156,   200,   -14,
     139,   -22,    15,   -22,    -9,    -9,    -8,    -8,   201,   202,
      -7,    -7,    -2,     1,    -4,    -4,   -14,    16,   -54,    -9,
     -18,    -8,    -5,    -5,    17,    -7,   156,     2,   103,    -4,
     156,   107,    -9,   179,    -8,   112,   236,    -5,    -7,    -9,
       3,    -8,    -4,   161,    95,    -7,    30,     4,   120,    -4,
      -5,    -6,    -6,    -3,    -3,   183,    95,    -5,   -19,   -53,
      96,     8,    19,    11,    12,    95,    -6,     8,    -3,   198,
     -12,   -12,   -44,   194,   179,   -13,   -13,     1,    20,    -6,
     113,    -3,   156,   137,   135,   -12,    -6,   -53,    -3,   204,
     -13,     2,    21,   277,   206,   207,   208,   156,   -12,    28,
     -56,   -56,    31,   -13,     3,   -12,   -58,   -58,   240,   -17,
     -13,     4,   217,   157,    79,   183,    97,   219,   220,   221,
     156,   250,   -58,   -54,   161,   -52,    96,   195,   -56,   272,
     156,    80,   179,   196,   -58,   197,   233,    21,   199,   195,
     121,   280,   157,   161,   200,   196,   157,   197,   -54,   180,
     199,    82,   179,   -52,   201,   202,   200,   156,   156,   156,
     156,   156,   247,   156,   248,   179,   201,   202,   -55,   -55,
     179,   179,   179,   179,   179,   257,   -57,   -57,   156,    83,
     259,   183,   156,   263,    97,   161,   -15,   -15,   -24,   -24,
     180,   -23,   -57,   -23,    26,    27,   -55,   183,   157,    94,
     -16,   -15,    29,   -24,   -57,   157,   -44,   183,   158,    92,
     157,   157,   157,   157,   -15,   198,   -24,    84,    85,   194,
     185,   -15,   241,   -24,   156,   278,   185,   198,   180,   -43,
     104,   194,   251,   180,   180,   180,   157,   158,   -71,   -71,
     105,   158,   -71,   -71,   181,   -77,   157,   -77,   180,   108,
     -20,   -78,   -20,   -78,   -71,   -59,   -59,   -71,   -71,   -53,
     210,   -10,   163,   -10,   -60,   -60,    86,   231,   180,   122,
     -71,   -59,   123,   157,   157,   157,   157,   157,   157,   157,
     -60,   180,   124,   -59,   -53,   181,   180,   180,   180,   180,
     180,   180,   -60,   158,   157,   125,   184,   141,   157,   142,
     158,   143,   144,   159,   138,   158,   158,   158,   158,   -51,
     -56,   -56,   130,   160,   146,   131,   147,   148,   132,   151,
     106,   149,   -11,   181,   -11,   -43,   224,   150,   181,   181,
     181,   158,   159,   -58,   -58,   -56,   159,   -56,   232,   182,
     157,   158,   -21,   181,   -21,   234,   -79,   -79,   151,   -58,
     -79,   -79,   151,   235,   183,   174,   237,   126,   -58,   127,
     -58,   238,   -79,   181,   114,   -79,   -79,   -54,   158,   158,
     158,   158,   158,   158,   158,   260,   181,   -51,   -79,   267,
     182,   181,   181,   181,   181,   181,   181,   261,   159,   158,
     -55,   -55,   -54,   158,   -54,   159,   174,   265,   153,   127,
     159,   159,   159,   159,   151,   266,   224,   127,   264,   268,
     274,   269,   -57,   -57,   270,   -55,   271,   -55,   182,   151,
     275,   -52,   210,   182,   182,   182,   159,   153,   -57,   276,
     279,   153,   -53,   223,   176,   158,   159,   -57,   182,   -57,
      14,    33,   151,    93,     0,   116,   -52,   118,   119,     0,
       0,     0,   229,     0,   230,     0,     0,   -53,   182,   -53,
       0,     0,     0,   159,   159,   159,   159,   159,   159,   159,
       0,   182,     0,     0,   174,   176,   182,   182,   182,   182,
     182,   182,     0,   153,   159,   151,     0,   174,   159,   -79,
     -79,   155,     0,   -79,   -79,     0,     0,    98,   153,     0,
     151,   -61,   -61,     0,   151,   -79,   -71,   -71,   -79,   -79,
     -71,   -71,     0,    99,     0,     0,   100,   -61,   -79,     0,
     155,   153,   -71,     0,   155,   -71,   -71,   178,     0,   -61,
     159,   153,     0,   176,    86,     0,    87,     0,   -71,   117,
     -52,   223,     0,     0,   -56,   -56,   151,     0,     0,     0,
       0,     0,     0,   176,     0,     0,   154,     0,   153,   243,
     211,   245,   246,     0,   153,   -52,   176,   -52,   178,   -56,
       0,   176,   253,     0,   255,   256,   155,   -80,   -80,   153,
       0,   -80,   -80,   153,     0,   154,     0,     0,     0,   154,
       0,   155,   177,   -80,     0,     0,   -80,   -80,     0,     0,
       0,     0,     0,   152,   -58,   -58,     0,     0,     0,   -80,
       0,   -81,   -81,     0,   155,   -81,   -81,     0,   -63,   101,
     -58,     0,   -63,   -63,   155,   153,   178,   -81,     0,   -58,
     -81,   -81,   152,   177,   -63,     0,   152,   -63,   -63,   175,
       0,   154,     0,   -81,   -59,   -59,   178,     0,     0,   115,
     -63,   155,   155,   244,   155,   155,   154,   155,     0,   178,
     -59,     0,     0,     0,   178,   178,   254,   178,   178,   -59,
       0,   -59,   155,     0,   -55,   -55,   155,    91,     0,   154,
     175,     0,   -65,   -65,   -57,   -57,   -65,   -65,   152,   154,
     211,   177,     0,     0,     0,     0,   -60,   -60,   -65,   -55,
     -57,   -65,   -65,   152,     0,     0,   102,     0,     0,   -57,
     162,   177,   -60,   110,   -65,     0,   154,   154,   155,   154,
     154,   -60,   154,   -60,   177,     0,   152,     0,     0,   177,
     177,     0,   177,   177,     0,     0,   152,   154,   175,     0,
      34,   154,    35,     0,    36,    37,     0,     0,   186,   129,
     187,   188,   189,   190,   133,     0,    44,    45,   175,    46,
      47,     0,   162,   242,    48,     0,     0,   191,   192,   152,
      50,   175,     0,     0,   193,     0,   252,   209,     0,     0,
       0,     0,     0,   154,   152,   -39,     0,   -39,   152,   -39,
     -39,     0,     0,   -39,   134,   -39,   -39,   -39,   -39,   -39,
     222,   -39,   -39,     0,   -39,   -39,   -66,   -66,     0,   -39,
     -66,   -66,   -39,   -39,   -39,   -39,     0,   -59,   -59,   -39,
       0,     0,   -66,   -60,   -60,   -66,   -66,     0,     0,     0,
     152,     0,   110,   -59,     0,     0,     0,     0,   -66,   -60,
       0,     0,   -59,   162,     0,   110,     0,     0,   -60,     0,
       0,     0,     0,     0,     0,   -37,     0,   -37,   258,   -37,
     -37,     0,   162,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
       0,   -37,   -37,     0,   -37,   -37,     0,     0,     0,   -37,
       0,     0,   -37,   -37,   -37,   -37,     0,     0,     0,   -37,
       0,     0,     0,     0,     0,   273,     0,   -36,     0,   -36,
       0,   -36,   -36,     0,   162,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,   -36,     0,   -36,   -36,     0,     0,
       0,   -36,     0,     0,   -36,   -36,   -36,   -36,   -38,     0,
     -38,   -36,   -38,   -38,     0,     0,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,     0,
       0,     0,   -38,     0,     0,   -38,   -38,   -38,   -38,   -32,
       0,   -32,   -38,   -32,   -32,     0,     0,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,
       0,     0,     0,   -32,     0,     0,   -32,   -32,   -32,   -32,
     -33,     0,   -33,   -32,   -33,   -33,     0,     0,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,     0,   -33,
     -33,     0,     0,     0,   -33,     0,     0,   -33,   -33,   -33,
     -33,   -35,     0,   -35,   -33,   -35,   -35,     0,     0,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,     0,
     -35,   -35,     0,     0,     0,   -35,     0,     0,   -35,   -35,
     -35,   -35,   -31,     0,   -31,   -35,   -31,   -31,     0,     0,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,
       0,   -31,   -31,     0,     0,     0,   -31,     0,     0,   -31,
     -31,   -31,   -31,   -34,     0,   -34,   -31,   -34,   -34,     0,
       0,   -34,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,
     -34,     0,   -34,   -34,     0,     0,     0,   -34,     0,     0,
     -34,   -34,   -34,   -34,   -46,     0,   -46,   -34,   -46,   -46,
       0,     0,   -46,   -46,   -46,   -46,   -46,   -46,   -46,     0,
     -46,   -46,     0,   -46,   -46,     0,     0,     0,   -46,     0,
       0,   -46,   -46,   -46,   -46,   -47,     0,   -47,   -46,   -47,
     -47,     0,     0,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
       0,   -47,   -47,     0,   -47,   -47,     0,     0,     0,   -47,
       0,     0,   -47,   -47,   -47,   -47,   -42,     0,   -42,   -47,
     -42,   -42,     0,     0,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,     0,   -42,   -42,     0,   -42,   -42,     0,     0,     0,
     -42,     0,     0,   -42,   -42,   -42,   -42,   -45,     0,   -45,
     -42,   -45,   -45,     0,     0,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,     0,   -45,   -45,     0,   -45,   -45,     0,     0,
       0,   -45,     0,     0,   -45,   -45,   -45,   -45,   -24,     0,
     -24,   -45,   -24,   -24,     0,     0,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,     0,   -24,   -24,     0,   -24,   -24,     0,
       0,     0,   -24,     0,     0,   -24,   -24,   -24,   -24,   -39,
       0,   -39,   -24,   -39,   -39,     0,     0,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,     0,   -39,   -39,     0,   -39,   -39,
       0,     0,     0,   -39,     0,     0,   -39,   -39,   -39,   -39,
     -48,     0,   -48,   -39,   -48,   -48,     0,     0,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,     0,   -48,
     -48,     0,     0,     0,   -48,     0,     0,   -48,   -48,   -48,
     -48,   -49,     0,   -49,   -48,   -49,   -49,     0,     0,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,     0,
     -49,   -49,     0,     0,     0,   -49,     0,     0,   -49,   -49,
     -49,   -49,   -50,     0,   -50,   -49,   -50,   -50,     0,     0,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,     0,   -50,   -50,
       0,   -50,   -50,     0,     0,     0,   -50,     0,     0,   -50,
     -50,   -50,   -50,   -41,     0,   -41,   -50,   -41,   -41,     0,
       0,   -41,   -41,   -41,   -41,   -41,   -41,   -41,     0,   -41,
     -41,     0,   -41,   -41,     0,     0,     0,   -41,     0,     0,
     -41,   -41,   -41,   -41,    34,     0,    35,   -41,    36,    37,
       0,     0,    38,     0,    39,    40,    41,    42,    43,     0,
      44,    45,     0,    46,    47,     0,     0,     0,    48,     0,
       0,    49,   140,   -26,    50,   -37,     0,   -37,    51,   -37,
     -37,     0,     0,   -37,     0,   -37,   -37,   -37,   -37,   -37,
       0,   -37,   -37,     0,   -37,   -37,     0,     0,     0,   -37,
       0,     0,   -37,   -37,   -37,   -37,   -36,     0,   -36,   -37,
     -36,   -36,     0,     0,   -36,     0,   -36,   -36,   -36,   -36,
     -36,     0,   -36,   -36,     0,   -36,   -36,     0,     0,     0,
     -36,     0,     0,   -36,   -36,   -36,   -36,   -30,     0,   -30,
     -36,   -30,   -30,     0,     0,   -30,     0,   -30,   -30,   -30,
     -30,   -30,     0,   -30,   -30,     0,   -30,   -30,     0,     0,
       0,   -30,     0,     0,   -30,   -30,   -30,   -30,   -38,     0,
     -38,   -30,   -38,   -38,     0,     0,   -38,     0,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,     0,
       0,     0,   -38,     0,     0,   -38,   -38,   -38,   -38,    34,
       0,    35,   -38,    36,    37,     0,     0,    38,     0,    39,
      40,    41,    42,    43,     0,    44,    45,     0,    46,    47,
       0,     0,     0,    48,     0,     0,    49,   140,   -25,    50,
     -28,     0,   -28,    51,   -28,   -28,     0,     0,   -28,     0,
     -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,     0,   -28,
     -28,     0,     0,     0,   -28,     0,     0,   -28,   -28,   -28,
     -28,   -29,     0,   -29,   -28,   -29,   -29,     0,     0,   -29,
       0,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,     0,
     -29,   -29,     0,     0,     0,   -29,     0,     0,   -29,   -29,
     -29,   -29,   -32,     0,   -32,   -29,   -32,   -32,     0,     0,
     -32,     0,   -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,
       0,   -32,   -32,     0,     0,     0,   -32,     0,     0,   -32,
     -32,   -32,   -32,   -33,     0,   -33,   -32,   -33,   -33,     0,
       0,   -33,     0,   -33,   -33,   -33,   -33,   -33,     0,   -33,
     -33,     0,   -33,   -33,     0,     0,     0,   -33,     0,     0,
     -33,   -33,   -33,   -33,   -35,     0,   -35,   -33,   -35,   -35,
       0,     0,   -35,     0,   -35,   -35,   -35,   -35,   -35,     0,
     -35,   -35,     0,   -35,   -35,     0,     0,     0,   -35,     0,
       0,   -35,   -35,   -35,   -35,   -31,     0,   -31,   -35,   -31,
     -31,     0,     0,   -31,     0,   -31,   -31,   -31,   -31,   -31,
       0,   -31,   -31,     0,   -31,   -31,     0,     0,     0,   -31,
       0,     0,   -31,   -31,   -31,   -31,   -34,     0,   -34,   -31,
     -34,   -34,     0,     0,   -34,     0,   -34,   -34,   -34,   -34,
     -34,     0,   -34,   -34,     0,   -34,   -34,     0,     0,     0,
     -34,     0,     0,   -34,   -34,   -34,   -34,   -46,     0,   -46,
     -34,   -46,   -46,     0,     0,   -46,     0,   -46,   -46,   -46,
     -46,   -46,     0,   -46,   -46,     0,   -46,   -46,     0,     0,
       0,   -46,     0,     0,   -46,   -46,   -46,   -46,   -47,     0,
     -47,   -46,   -47,   -47,     0,     0,   -47,     0,   -47,   -47,
     -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,     0,
       0,     0,   -47,     0,     0,   -47,   -47,   -47,   -47,   -27,
       0,   -27,   -47,   -27,   -27,     0,     0,   -27,     0,   -27,
     -27,   -27,   -27,   -27,     0,   -27,   -27,     0,   -27,   -27,
       0,     0,     0,   -27,     0,     0,   -27,   -27,   -27,   -27,
     -42,     0,   -42,   -27,   -42,   -42,     0,     0,   -42,     0,
     -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,     0,   -42,
     -42,     0,     0,     0,   -42,     0,     0,   -42,   -42,   -42,
     -42,   -45,     0,   -45,   -42,   -45,   -45,     0,     0,   -45,
       0,   -45,   -45,   -45,   -45,   -45,     0,   -45,   -45,     0,
     -45,   -45,     0,     0,     0,   -45,     0,     0,   -45,   -45,
     -45,   -45,   -48,     0,   -48,   -45,   -48,   -48,     0,     0,
     -48,     0,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,
       0,   -48,   -48,     0,     0,     0,   -48,     0,     0,   -48,
     -48,   -48,   -48,   -49,     0,   -49,   -48,   -49,   -49,     0,
       0,   -49,     0,   -49,   -49,   -49,   -49,   -49,     0,   -49,
     -49,     0,   -49,   -49,     0,     0,     0,   -49,     0,     0,
     -49,   -49,   -49,   -49,   -50,     0,   -50,   -49,   -50,   -50,
       0,     0,   -50,     0,   -50,   -50,   -50,   -50,   -50,     0,
     -50,   -50,     0,   -50,   -50,     0,     0,     0,   -50,     0,
       0,   -50,   -50,   -50,   -50,   -40,     0,   -40,   -50,   -40,
     -40,     0,     0,   -40,     0,   -40,   -40,   -40,   -40,   -40,
       0,   -40,   -40,     0,   -40,   -40,     0,     0,     0,   -40,
       0,     0,   -40,   -40,   -40,   -40,   -41,     0,   -41,   -40,
     -41,   -41,     0,     0,   -41,     0,   -41,   -41,   -41,   -41,
     -41,     0,   -41,   -41,     0,   -41,   -41,     0,     0,     0,
     -41,     0,     0,   -41,   -41,   -41,   -41,   -12,     0,   -12,
     -41,   -12,   -12,     0,     0,   -12,     0,   -12,   -12,   -12,
     -12,   -12,     0,   -12,   -12,     0,   -12,   -12,     0,     0,
       0,   -12,     0,     0,   -12,   -12,   -12,   -12,   -13,     0,
     -13,   -12,   -13,   -13,     0,     0,   -13,     0,   -13,   -13,
     -13,   -13,   -13,     0,   -13,   -13,     0,   -13,   -13,     0,
       0,     0,   -13,     0,     0,   -13,   -13,   -13,   -13,   -24,
       0,   -24,   -13,   -24,   -24,     0,     0,   -24,     0,   -24,
     -24,   -24,   -24,   -24,     0,   -24,   -24,     0,   -24,   -24,
       0,     0,     0,   -24,     0,     0,   -24,   -24,   -24,   -24,
      34,     0,    35,   -24,    36,    37,     0,     0,    38,     0,
      39,    40,    41,    42,     0,     0,    44,    45,     0,    46,
      47,   -73,   -73,     0,    48,   -73,   -73,    49,   140,     0,
      50,   -74,   -74,     0,    51,   -74,   -74,   -73,   -70,   -70,
     -73,   -73,   -70,   -70,     0,     0,     0,   -74,     0,     0,
     -74,   -74,     0,   -73,   -70,   -67,   -67,   -70,   -70,   -67,
     -67,   -68,   -68,   -74,     0,   -68,   -68,     0,     0,     0,
     -70,   -67,     0,     0,   -67,   -67,     0,   -68,   -69,   -69,
     -68,   -68,   -69,   -69,   -76,   -76,     0,   -67,   -76,   -76,
       0,     0,     0,   -68,   -69,     0,     0,   -69,   -69,     0,
     -76,   -72,   -72,   -76,   -76,   -72,   -72,   -62,   101,     0,
     -69,   -62,   -62,     0,     0,     0,   -76,   -72,     0,     0,
     -72,   -72,     0,   -62,   -64,   -64,   -62,   -62,   -64,   -64,
     -75,   -75,   225,   -72,   -75,   -75,   -61,   -61,     0,   -62,
     -64,     0,     0,   -64,   -64,     0,   -75,     0,   226,   -75,
     -75,   227,   -61,   164,     0,   165,   -64,   166,   167,     0,
       0,   -61,   -75,   -61,     0,     0,     0,     0,     0,   168,
     169,     0,   170,   171,   164,     0,   165,   172,   166,   167,
       0,     0,     0,   173,   109,     0,     0,     0,     0,     0,
     168,   169,     0,   170,   171,   164,     0,   165,   172,   166,
     167,     0,   -71,   -71,   173,   239,   -71,   -71,     0,     0,
       0,   168,   169,     0,   170,   171,     0,     0,   -71,   172,
       0,   -71,   -71,   -79,   -79,   173,   249,   -79,   -79,     0,
     218,   -71,     0,   -71,     0,     0,     0,     0,     0,   -79,
     -80,   -80,   -79,   -79,   -80,   -80,   -81,   -81,     0,     0,
     -81,   -81,   -79,     0,   -79,     0,   -80,     0,     0,   -80,
     -80,     0,   -81,   -63,   228,   -81,   -81,   -63,   -63,   -80,
       0,   -80,     0,     0,     0,   -81,     0,   -81,     0,   -63,
     -65,   -65,   -63,   -63,   -65,   -65,   -66,   -66,     0,     0,
     -66,   -66,   -63,     0,   -63,     0,   -65,     0,     0,   -65,
     -65,     0,   -66,   -73,   -73,   -66,   -66,   -73,   -73,   -65,
       0,   -65,     0,     0,     0,   -66,     0,   -66,     0,   -73,
     -74,   -74,   -73,   -73,   -74,   -74,   -70,   -70,     0,     0,
     -70,   -70,   -73,     0,   -73,     0,   -74,     0,     0,   -74,
     -74,     0,   -70,   -67,   -67,   -70,   -70,   -67,   -67,   -74,
       0,   -74,     0,     0,     0,   -70,     0,   -70,     0,   -67,
     -68,   -68,   -67,   -67,   -68,   -68,   -69,   -69,     0,     0,
     -69,   -69,   -67,     0,   -67,     0,   -68,     0,     0,   -68,
     -68,     0,   -69,   -76,   -76,   -69,   -69,   -76,   -76,   -68,
       0,   -68,     0,     0,     0,   -69,     0,   -69,     0,   -76,
     -72,   -72,   -76,   -76,   -72,   -72,   -62,   228,     0,     0,
     -62,   -62,   -76,     0,   -76,     0,   -72,     0,     0,   -72,
     -72,     0,   -62,   -64,   -64,   -62,   -62,   -64,   -64,   -72,
       0,   -72,     0,     0,     0,   -62,     0,   -62,     0,   -64,
     -75,   -75,   -64,   -64,   -75,   -75,     0,     0,     0,     0,
       0,     0,   -64,     0,   -64,     0,   -75,     0,     0,   -75,
     -75,   141,     0,   142,     0,   143,   144,     0,     0,   -75,
      34,   -75,    35,     0,    36,    37,     0,   160,   146,     0,
     147,   148,     0,     0,   262,   149,    44,    45,     0,    46,
      47,   150,     0,   141,    48,   142,     0,   143,   144,     0,
      50,     0,    34,     0,    35,     0,    36,    37,     0,   145,
     146,     0,   147,   148,     0,     0,     0,   149,    77,    45,
       0,    46,    47,   150,     0,   164,    48,   165,     0,   166,
     167,     0,    50,     0,   141,     0,   142,     0,   143,   144,
       0,   168,   169,     0,   170,   171,     0,     0,     0,   172,
     160,   146,     0,   147,   148,   173,   -71,   -71,   149,     0,
     -71,   -71,   -71,   -71,   150,     0,   -71,   -71,     0,     0,
       0,     0,   -71,     0,     0,   -71,   -71,     0,   -71,     0,
       0,   -71,   -71,     0,   205,   -71,   216,     0,   -80,   -80,
     205,   -71,   -80,   -80,   -81,   -81,   -63,   215,   -81,   -81,
     -63,   -63,     0,     0,   -80,     0,     0,   -80,   -80,     0,
     -81,     0,   -63,   -81,   -81,   -63,   -63,   -80,     0,     0,
       0,     0,     0,   -81,     0,   -63,   -65,   -65,   -66,   -66,
     -65,   -65,   -66,   -66,   -73,   -73,     0,     0,   -73,   -73,
       0,     0,   -65,     0,   -66,   -65,   -65,   -66,   -66,     0,
     -73,     0,     0,   -73,   -73,   -65,     0,   -66,     0,     0,
     -74,   -74,     0,   -73,   -74,   -74,   -70,   -70,   -67,   -67,
     -70,   -70,   -67,   -67,     0,     0,   -74,     0,     0,   -74,
     -74,     0,   -70,     0,   -67,   -70,   -70,   -67,   -67,   -74,
       0,     0,     0,     0,     0,   -70,     0,   -67,   -68,   -68,
     -69,   -69,   -68,   -68,   -69,   -69,   -76,   -76,     0,     0,
     -76,   -76,     0,     0,   -68,     0,   -69,   -68,   -68,   -69,
     -69,     0,   -76,     0,     0,   -76,   -76,   -68,     0,   -69,
       0,     0,   -72,   -72,     0,   -76,   -72,   -72,   -62,   215,
     -64,   -64,   -62,   -62,   -64,   -64,     0,     0,   -72,     0,
       0,   -72,   -72,     0,   -62,     0,   -64,   -62,   -62,   -64,
     -64,   -72,     0,    35,     0,    36,    37,   -62,   212,   -64,
     -75,   -75,   -61,   -61,   -75,   -75,     0,    77,    45,     0,
      46,    47,     0,     0,   213,    48,   -75,   214,   -61,   -75,
     -75,    50,   142,     0,   143,   144,     0,   -61,     0,   -75,
       0,   165,     0,   166,   167,     0,   145,   146,     0,   147,
     148,     0,     0,     0,   149,   168,   169,     0,   170,   171,
     150,     0,     0,   172,     0,     0,     0,     0,     0,   173
};

static const yytype_int16 yycheck[] =
{
      28,   121,    35,   121,   140,     1,     0,   121,    40,   121,
       7,    83,   121,    46,    47,    48,   134,    50,   121,    15,
     138,    32,    31,    34,     0,     1,     0,     1,   121,   121,
       0,     1,     0,     1,     0,     1,    32,    17,    35,    15,
      31,    15,     0,     1,    35,    15,    79,    15,    80,    15,
      83,    83,    28,    86,    28,    87,   192,    15,    28,    35,
      28,    35,    28,   135,     7,    35,    17,    35,   101,    35,
      28,     0,     1,     0,     1,     7,     7,    35,    31,     7,
       8,     0,    35,    16,    17,     7,    15,     6,    15,   121,
       0,     1,    35,   121,   127,     0,     1,     1,     1,    28,
      32,    28,   135,   135,    35,    15,    35,    35,    35,   142,
      15,    15,    15,    35,   147,   148,   149,   150,    28,    32,
       7,     8,    29,    28,    28,    35,     7,     8,   205,    32,
      35,    35,   165,    50,    31,     7,    23,   170,   171,   172,
     173,   218,    23,     7,   216,     7,     8,   267,    35,   267,
     183,    31,   185,   267,    35,   267,   188,    15,   267,   279,
      32,   279,    79,   235,   267,   279,    83,   279,    32,    86,
     279,    31,   205,    35,   267,   267,   279,   210,   211,   212,
     213,   214,   215,   216,   216,   218,   279,   279,     7,     8,
     223,   224,   225,   226,   227,   228,     7,     8,   231,    31,
     232,     7,   235,   235,    23,   277,     0,     1,     0,     1,
     127,    32,    23,    34,    16,    17,    35,     7,   135,    35,
      32,    15,    34,    15,    35,   142,    32,     7,    50,    30,
     147,   148,   149,   150,    28,   267,    28,    16,    17,   267,
       7,    35,    32,    35,   277,   277,     7,   279,   165,    35,
      35,   279,    32,   170,   171,   172,   173,    79,     3,     4,
      17,    83,     7,     8,    86,    32,   183,    34,   185,    17,
      32,    32,    34,    34,    19,     7,     8,    22,    23,     7,
       8,    32,    35,    34,     7,     8,    31,    31,   205,    35,
      35,    23,    32,   210,   211,   212,   213,   214,   215,   216,
      23,   218,    32,    35,    32,   127,   223,   224,   225,   226,
     227,   228,    35,   135,   231,    32,    35,     1,   235,     3,
     142,     5,     6,    50,    32,   147,   148,   149,   150,    35,
       7,     8,    35,    17,    18,    35,    20,    21,    35,    50,
      24,    25,    32,   165,    34,    32,    23,    31,   170,   171,
     172,   173,    79,     7,     8,    32,    83,    34,    31,    86,
     277,   183,    32,   185,    34,    31,     3,     4,    79,    23,
       7,     8,    83,    31,     7,    86,    35,    32,    32,    34,
      34,    30,    19,   205,    95,    22,    23,     7,   210,   211,
     212,   213,   214,   215,   216,    35,   218,    32,    35,    32,
     127,   223,   224,   225,   226,   227,   228,    17,   135,   231,
       7,     8,    32,   235,    34,   142,   127,    32,    50,    34,
     147,   148,   149,   150,   135,    32,    23,    34,    30,    35,
      35,    32,     7,     8,    32,    32,    32,    34,   165,   150,
      35,     7,     8,   170,   171,   172,   173,    79,    23,    35,
      32,    83,     7,     8,    86,   277,   183,    32,   185,    34,
       6,    29,   173,    55,    -1,    97,    32,    99,   100,    -1,
      -1,    -1,   183,    -1,   185,    -1,    -1,    32,   205,    34,
      -1,    -1,    -1,   210,   211,   212,   213,   214,   215,   216,
      -1,   218,    -1,    -1,   205,   127,   223,   224,   225,   226,
     227,   228,    -1,   135,   231,   216,    -1,   218,   235,     3,
       4,    50,    -1,     7,     8,    -1,    -1,     3,   150,    -1,
     231,     7,     8,    -1,   235,    19,     3,     4,    22,    23,
       7,     8,    -1,    19,    -1,    -1,    22,    23,    32,    -1,
      79,   173,    19,    -1,    83,    22,    23,    86,    -1,    35,
     277,   183,    -1,   185,    31,    -1,    33,    -1,    35,    98,
       7,     8,    -1,    -1,     7,     8,   277,    -1,    -1,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    50,    -1,   210,   211,
      23,   213,   214,    -1,   216,    32,   218,    34,   127,    32,
      -1,   223,   224,    -1,   226,   227,   135,     3,     4,   231,
      -1,     7,     8,   235,    -1,    79,    -1,    -1,    -1,    83,
      -1,   150,    86,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    50,     7,     8,    -1,    -1,    -1,    35,
      -1,     3,     4,    -1,   173,     7,     8,    -1,     3,     4,
      23,    -1,     7,     8,   183,   277,   185,    19,    -1,    32,
      22,    23,    79,   127,    19,    -1,    83,    22,    23,    86,
      -1,   135,    -1,    35,     7,     8,   205,    -1,    -1,    96,
      35,   210,   211,   212,   213,   214,   150,   216,    -1,   218,
      23,    -1,    -1,    -1,   223,   224,   225,   226,   227,    32,
      -1,    34,   231,    -1,     7,     8,   235,    50,    -1,   173,
     127,    -1,     3,     4,     7,     8,     7,     8,   135,   183,
      23,   185,    -1,    -1,    -1,    -1,     7,     8,    19,    32,
      23,    22,    23,   150,    -1,    -1,    79,    -1,    -1,    32,
      83,   205,    23,    86,    35,    -1,   210,   211,   277,   213,
     214,    32,   216,    34,   218,    -1,   173,    -1,    -1,   223,
     224,    -1,   226,   227,    -1,    -1,   183,   231,   185,    -1,
       1,   235,     3,    -1,     5,     6,    -1,    -1,     9,   122,
      11,    12,    13,    14,   127,    -1,    17,    18,   205,    20,
      21,    -1,   135,   210,    25,    -1,    -1,    28,    29,   216,
      31,   218,    -1,    -1,    35,    -1,   223,   150,    -1,    -1,
      -1,    -1,    -1,   277,   231,     1,    -1,     3,   235,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
     173,    17,    18,    -1,    20,    21,     3,     4,    -1,    25,
       7,     8,    28,    29,    30,    31,    -1,     7,     8,    35,
      -1,    -1,    19,     7,     8,    22,    23,    -1,    -1,    -1,
     277,    -1,   205,    23,    -1,    -1,    -1,    -1,    35,    23,
      -1,    -1,    32,   216,    -1,   218,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,   231,     5,
       6,    -1,   235,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,   268,    -1,     1,    -1,     3,
      -1,     5,     6,    -1,   277,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    28,    29,    30,    31,     1,    -1,
       3,    35,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    28,    29,    30,    31,     1,
      -1,     3,    35,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    28,    29,    30,    31,
       1,    -1,     3,    35,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    28,    29,    30,
      31,     1,    -1,     3,    35,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,    29,
      30,    31,     1,    -1,     3,    35,     5,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,
      29,    30,    31,     1,    -1,     3,    35,     5,     6,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      28,    29,    30,    31,     1,    -1,     3,    35,     5,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    28,    29,    30,    31,     1,    -1,     3,    35,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    28,    29,    30,    31,     1,    -1,     3,    35,
       5,     6,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    28,    29,    30,    31,     1,    -1,     3,
      35,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    28,    29,    30,    31,     1,    -1,
       3,    35,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    28,    29,    30,    31,     1,
      -1,     3,    35,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    28,    29,    30,    31,
       1,    -1,     3,    35,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    28,    29,    30,
      31,     1,    -1,     3,    35,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,    29,
      30,    31,     1,    -1,     3,    35,     5,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,
      29,    30,    31,     1,    -1,     3,    35,     5,     6,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      28,    29,    30,    31,     1,    -1,     3,    35,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    28,    29,    30,    31,     1,    -1,     3,    35,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    28,    29,    30,    31,     1,    -1,     3,    35,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    28,    29,    30,    31,     1,    -1,     3,
      35,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    28,    29,    30,    31,     1,    -1,
       3,    35,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    28,    29,    30,    31,     1,
      -1,     3,    35,     5,     6,    -1,    -1,     9,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    28,    29,    30,    31,
       1,    -1,     3,    35,     5,     6,    -1,    -1,     9,    -1,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    28,    29,    30,
      31,     1,    -1,     3,    35,     5,     6,    -1,    -1,     9,
      -1,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,    29,
      30,    31,     1,    -1,     3,    35,     5,     6,    -1,    -1,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,
      29,    30,    31,     1,    -1,     3,    35,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      28,    29,    30,    31,     1,    -1,     3,    35,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    28,    29,    30,    31,     1,    -1,     3,    35,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    28,    29,    30,    31,     1,    -1,     3,    35,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    28,    29,    30,    31,     1,    -1,     3,
      35,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    28,    29,    30,    31,     1,    -1,
       3,    35,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    28,    29,    30,    31,     1,
      -1,     3,    35,     5,     6,    -1,    -1,     9,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    28,    29,    30,    31,
       1,    -1,     3,    35,     5,     6,    -1,    -1,     9,    -1,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,    28,    29,    30,
      31,     1,    -1,     3,    35,     5,     6,    -1,    -1,     9,
      -1,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,    29,
      30,    31,     1,    -1,     3,    35,     5,     6,    -1,    -1,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,
      29,    30,    31,     1,    -1,     3,    35,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,
      28,    29,    30,    31,     1,    -1,     3,    35,     5,     6,
      -1,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    28,    29,    30,    31,     1,    -1,     3,    35,     5,
       6,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    28,    29,    30,    31,     1,    -1,     3,    35,
       5,     6,    -1,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    28,    29,    30,    31,     1,    -1,     3,
      35,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    28,    29,    30,    31,     1,    -1,
       3,    35,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    28,    29,    30,    31,     1,
      -1,     3,    35,     5,     6,    -1,    -1,     9,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,    28,    29,    30,    31,
       1,    -1,     3,    35,     5,     6,    -1,    -1,     9,    -1,
      11,    12,    13,    14,    -1,    -1,    17,    18,    -1,    20,
      21,     3,     4,    -1,    25,     7,     8,    28,    29,    -1,
      31,     3,     4,    -1,    35,     7,     8,    19,     3,     4,
      22,    23,     7,     8,    -1,    -1,    -1,    19,    -1,    -1,
      22,    23,    -1,    35,    19,     3,     4,    22,    23,     7,
       8,     3,     4,    35,    -1,     7,     8,    -1,    -1,    -1,
      35,    19,    -1,    -1,    22,    23,    -1,    19,     3,     4,
      22,    23,     7,     8,     3,     4,    -1,    35,     7,     8,
      -1,    -1,    -1,    35,    19,    -1,    -1,    22,    23,    -1,
      19,     3,     4,    22,    23,     7,     8,     3,     4,    -1,
      35,     7,     8,    -1,    -1,    -1,    35,    19,    -1,    -1,
      22,    23,    -1,    19,     3,     4,    22,    23,     7,     8,
       3,     4,     3,    35,     7,     8,     7,     8,    -1,    35,
      19,    -1,    -1,    22,    23,    -1,    19,    -1,    19,    22,
      23,    22,    23,     1,    -1,     3,    35,     5,     6,    -1,
      -1,    32,    35,    34,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,     1,    -1,     3,    25,     5,     6,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,     1,    -1,     3,    25,     5,
       6,    -1,     3,     4,    31,    32,     7,     8,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    19,    25,
      -1,    22,    23,     3,     4,    31,    32,     7,     8,    -1,
      31,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    -1,
       7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,    32,
      -1,    34,    -1,    -1,    -1,    32,    -1,    34,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    -1,
       7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,    32,
      -1,    34,    -1,    -1,    -1,    32,    -1,    34,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    -1,
       7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,    32,
      -1,    34,    -1,    -1,    -1,    32,    -1,    34,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    -1,
       7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,    32,
      -1,    34,    -1,    -1,    -1,    32,    -1,    34,    -1,    19,
       3,     4,    22,    23,     7,     8,     3,     4,    -1,    -1,
       7,     8,    32,    -1,    34,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,     3,     4,    22,    23,     7,     8,    32,
      -1,    34,    -1,    -1,    -1,    32,    -1,    34,    -1,    19,
       3,     4,    22,    23,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    19,    -1,    -1,    22,
      23,     1,    -1,     3,    -1,     5,     6,    -1,    -1,    32,
       1,    34,     3,    -1,     5,     6,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    24,    25,    17,    18,    -1,    20,
      21,    31,    -1,     1,    25,     3,    -1,     5,     6,    -1,
      31,    -1,     1,    -1,     3,    -1,     5,     6,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    17,    18,
      -1,    20,    21,    31,    -1,     1,    25,     3,    -1,     5,
       6,    -1,    31,    -1,     1,    -1,     3,    -1,     5,     6,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      17,    18,    -1,    20,    21,    31,     3,     4,    25,    -1,
       7,     8,     3,     4,    31,    -1,     7,     8,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    22,    23,    -1,    19,    -1,
      -1,    22,    23,    -1,    31,    32,    33,    -1,     3,     4,
      31,    32,     7,     8,     3,     4,     3,     4,     7,     8,
       7,     8,    -1,    -1,    19,    -1,    -1,    22,    23,    -1,
      19,    -1,    19,    22,    23,    22,    23,    32,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    32,     3,     4,     3,     4,
       7,     8,     7,     8,     3,     4,    -1,    -1,     7,     8,
      -1,    -1,    19,    -1,    19,    22,    23,    22,    23,    -1,
      19,    -1,    -1,    22,    23,    32,    -1,    32,    -1,    -1,
       3,     4,    -1,    32,     7,     8,     3,     4,     3,     4,
       7,     8,     7,     8,    -1,    -1,    19,    -1,    -1,    22,
      23,    -1,    19,    -1,    19,    22,    23,    22,    23,    32,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    32,     3,     4,
       3,     4,     7,     8,     7,     8,     3,     4,    -1,    -1,
       7,     8,    -1,    -1,    19,    -1,    19,    22,    23,    22,
      23,    -1,    19,    -1,    -1,    22,    23,    32,    -1,    32,
      -1,    -1,     3,     4,    -1,    32,     7,     8,     3,     4,
       3,     4,     7,     8,     7,     8,    -1,    -1,    19,    -1,
      -1,    22,    23,    -1,    19,    -1,    19,    22,    23,    22,
      23,    32,    -1,     3,    -1,     5,     6,    32,     3,    32,
       3,     4,     7,     8,     7,     8,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    19,    25,    19,    22,    23,    22,
      23,    31,     3,    -1,     5,     6,    -1,    32,    -1,    32,
      -1,     3,    -1,     5,     6,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    17,    18,    -1,    20,    21,
      31,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    15,    28,    35,    38,    39,    40,    42,    43,
      46,    16,    17,     0,    40,    31,    17,    35,    44,    35,
       1,    15,    41,    45,    47,    48,    16,    17,    32,    34,
      17,    29,    49,    48,     1,     3,     5,     6,     9,    11,
      12,    13,    14,    15,    17,    18,    20,    21,    25,    28,
      31,    35,    42,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    73,    17,    69,    31,
      31,    57,    31,    31,    16,    17,    31,    33,    69,    69,
      69,    63,    30,    52,    35,     7,     8,    23,     3,    19,
      22,     4,    63,    57,    35,    17,    24,    57,    17,    32,
      63,    72,    57,    32,    64,    65,    66,    68,    66,    66,
      69,    32,    35,    32,    32,    32,    32,    34,    53,    63,
      35,    35,    35,    63,    10,    35,    53,    57,    32,    53,
      29,     1,     3,     5,     6,    17,    18,    20,    21,    25,
      31,    64,    65,    66,    67,    68,    69,    70,    71,    73,
      17,    62,    63,    35,     1,     3,     5,     6,    17,    18,
      20,    21,    25,    31,    64,    65,    66,    67,    68,    69,
      70,    71,    73,     7,    35,     7,     9,    11,    12,    13,
      14,    28,    29,    35,    49,    54,    55,    56,    57,    58,
      59,    60,    61,    50,    69,    31,    69,    69,    69,    63,
       8,    23,     3,    19,    22,     4,    33,    69,    31,    69,
      69,    69,    63,     8,    23,     3,    19,    22,     4,    64,
      64,    31,    31,    57,    31,    31,    50,    35,    30,    32,
      72,    32,    65,    66,    68,    66,    66,    69,    57,    32,
      72,    32,    65,    66,    68,    66,    66,    69,    63,    57,
      35,    17,    24,    57,    30,    32,    32,    32,    35,    32,
      32,    32,    53,    63,    35,    35,    35,    35,    57,    32,
      53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      41,    41,    42,    42,    44,    43,    45,    45,    46,    46,
      47,    47,    47,    48,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    55,    56,    57,    57,    58,    59,    59,    60,    61,
      61,    62,    63,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     4,     0,     6,     1,     0,     2,     3,
       1,     3,     1,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       7,     9,     2,     1,     1,     3,     1,     1,     5,     5,
       5,     3,     3,     1,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     1,     2,     2,     2,
       2,     1,     3,     1,     1,     4,     3,     1,     3,     1,
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
#line 142 "src/syntax.y"
                        {
		//root = *createAstNode("initial", DEBUG_AST);	// non-printable
		root.node_name = strdup("initial");
		root.printable = DEBUG_AST;
		(yyval.ast) = &root;
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2181 "src/syntax.tab.c"
    break;

  case 3: /* declaration_list: declaration_list decl  */
#line 153 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("declaration list", 1);	// printable
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2192 "src/syntax.tab.c"
    break;

  case 4: /* declaration_list: decl  */
#line 159 "src/syntax.y"
              {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2200 "src/syntax.tab.c"
    break;

  case 5: /* decl: var_declaration  */
#line 165 "src/syntax.y"
                       {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2208 "src/syntax.tab.c"
    break;

  case 6: /* decl: func_definition  */
#line 168 "src/syntax.y"
                         {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2216 "src/syntax.tab.c"
    break;

  case 7: /* decl: ';'  */
#line 171 "src/syntax.y"
             {
		(yyval.ast) = createAstNode("no operation", DEBUG_AST);
		(yyval.ast)->token_name = strdup(";");
		insertAstNode(&astList, (yyval.ast));
	}
#line 2226 "src/syntax.tab.c"
    break;

  case 8: /* decl: ERROR_COMM  */
#line 176 "src/syntax.y"
                    {
		error_comm = 1;
		fclose(yyin);
		yylex_destroy();
		return ERROR;
	}
#line 2237 "src/syntax.tab.c"
    break;

  case 9: /* decl: error  */
#line 182 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		(yyval.ast)->node_type = strdup("invalid");
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2248 "src/syntax.tab.c"
    break;

  case 10: /* var_definition: SIMPLE_TYPE ID  */
#line 191 "src/syntax.y"
                      {
		int var_type = 2;	// parameter
		char type_and_id[150];
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, (yyvsp[-1].lexeme).lexeme_string);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " parameter definition");
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, (yyvsp[-1].lexeme).lexeme_string, var_type, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, (yyvsp[0].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode(type_and_id, 1);
		(yyval.ast)->node_type = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2269 "src/syntax.tab.c"
    break;

  case 11: /* var_definition: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 207 "src/syntax.y"
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
		(yyval.ast)->node_type = strdup(concat_type);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup(concat_type);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2294 "src/syntax.tab.c"
    break;

  case 12: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 230 "src/syntax.y"
                          {
		int var_type = 1;
		char type_and_id[150];
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, (yyvsp[-2].lexeme).lexeme_string);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " variable declaration");
		insertSymbol(&symbolTable, (yyvsp[-1].lexeme).lexeme_string, (yyvsp[-2].lexeme).lexeme_string, var_type, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, (yyvsp[-1].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode(type_and_id, 1);
		(yyval.ast)->node_type = strdup((yyvsp[-2].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup((yyvsp[-2].lexeme).lexeme_string);
		(yyval.ast)->token_line = (yyvsp[-1].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-1].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2315 "src/syntax.tab.c"
    break;

  case 13: /* var_declaration: SIMPLE_TYPE COMPOUND_TYPE ID ';'  */
#line 246 "src/syntax.y"
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
		(yyval.ast)->node_type = strdup(concat_type);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup(concat_type);
		(yyval.ast)->token_line = (yyvsp[-1].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-1].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2340 "src/syntax.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 269 "src/syntax.y"
                             {
		func_context = 1;
		has_return = 0;
		insertScope(++last_scope, &contextList);
	}
#line 2350 "src/syntax.tab.c"
    break;

  case 15: /* func_definition: func_declaration '(' $@1 params.opt ')' stmts  */
#line 273 "src/syntax.y"
                               {
		(yyval.ast) = createAstNode("function definition", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-5].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);

		char return_value[5];

		if(has_return){
			if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0){
				if(strcmp(return_type, "int") == 0 || strcmp(return_type, "float") == 0){
					(yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Return type error in function %s%s%s.%s\n", 
					RED, return_line, return_column, GREEN, (yyval.ast)->children[0]->token_name, RED, WHITE);
					printf("\t\t\t%s<Function type is %s%s%s and return type is %s%s%s>%s\n", 
					RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, return_type, RED, WHITE);
					(yyval.ast)->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
				if(strcmp(return_type, "float") == 0 || strcmp(return_type, "int") == 0){
					(yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Return type error in function %s%s%s.%s\n", 
					RED, return_line, return_column, GREEN, (yyval.ast)->children[0]->token_name, RED, WHITE);
					printf("\t\t\t%s<Function type is %s%s%s and return type is %s%s%s>%s\n", 
					RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, return_type, RED, WHITE);
					(yyval.ast)->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp((yyval.ast)->children[0]->node_type, "int list") == 0){
				if(strcmp(return_type, "int list") == 0 || strcmp(return_type, "nil") == 0){
					(yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Return type error in function %s%s%s.%s\n", 
					RED, return_line, return_column, GREEN, (yyval.ast)->children[0]->token_name, RED, WHITE);
					printf("\t\t\t%s<Function type is %s%s%s and return type is %s%s%s>%s\n", 
					RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, return_type, RED, WHITE);
					(yyval.ast)->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp((yyval.ast)->children[0]->node_type, "float list") == 0){
				if(strcmp(return_type, "float list") == 0 || strcmp(return_type, "nil") == 0){
					(yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Return type error in function %s%s%s.%s\n", 
					RED, return_line, return_column, GREEN, (yyval.ast)->children[0]->token_name, RED, WHITE);
					printf("\t\t\t%s<Function type is %s%s%s and return type is %s%s%s>%s\n", 
					RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, return_type, RED, WHITE);
					(yyval.ast)->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}
		}else{
			(yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
			if(strcmp((yyval.ast)->node_type, "int") == 0)
				strcpy(return_value, "0");
			else if(strcmp((yyval.ast)->node_type, "float") == 0)
				strcpy(return_value, "0.0");
			else
				strcpy(return_value, "NIL");
			printf("%sLine:%d\tColumn:%d\tSemantic warning! Function %s%s%s without a return. Default value of return is set to %s%s%s.%s\n", 
			YELLOW, (yyval.ast)->children[0]->token_line, (yyval.ast)->children[0]->token_column, GREEN, (yyval.ast)->children[0]->token_name, YELLOW, BLUE, return_value, YELLOW, WHITE);
		}
		insertAstNode(&astList, (yyval.ast));
		removeScope(&contextList);
	}
#line 2423 "src/syntax.tab.c"
    break;

  case 16: /* params.opt: param_list  */
#line 344 "src/syntax.y"
                  {
		(yyval.ast) = createAstNode("params optional", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2433 "src/syntax.tab.c"
    break;

  case 17: /* params.opt: %empty  */
#line 349 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("params optional empty", DEBUG_AST); 
		insertAstNode(&astList, (yyval.ast));
	}
#line 2442 "src/syntax.tab.c"
    break;

  case 18: /* func_declaration: SIMPLE_TYPE ID  */
#line 356 "src/syntax.y"
                      {
		int func_type = 0;
		char type_and_id[150];
		strcpy(type_and_id, BLUE);
		strcat(type_and_id, (yyvsp[-1].lexeme).lexeme_string);
		strcat(type_and_id, WHITE);
		strcat(type_and_id, " function declaration");
		insertSymbol(&symbolTable, (yyvsp[0].lexeme).lexeme_string, (yyvsp[-1].lexeme).lexeme_string, func_type, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, (yyvsp[0].lexeme).scope, &semantic_errors);
		(yyval.ast) = createAstNode(type_and_id, 1);
		(yyval.ast)->node_type = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup((yyvsp[-1].lexeme).lexeme_string);
		strcpy(function_type, (yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2464 "src/syntax.tab.c"
    break;

  case 19: /* func_declaration: SIMPLE_TYPE COMPOUND_TYPE ID  */
#line 373 "src/syntax.y"
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
		(yyval.ast)->node_type = strdup(concat_type);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup(concat_type);
		strcpy(function_type, concat_type);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 2490 "src/syntax.tab.c"
    break;

  case 20: /* param_list: param  */
#line 397 "src/syntax.y"
             {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2498 "src/syntax.tab.c"
    break;

  case 21: /* param_list: param_list ',' param  */
#line 400 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("param list", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2509 "src/syntax.tab.c"
    break;

  case 22: /* param_list: error  */
#line 406 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		(yyval.ast)->node_type = strdup("invalid");
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2520 "src/syntax.tab.c"
    break;

  case 23: /* param: var_definition  */
#line 415 "src/syntax.y"
                      {
		(yyval.ast) = (yyvsp[0].ast);
		setupParameters(&symbolTable);
	}
#line 2529 "src/syntax.tab.c"
    break;

  case 24: /* stmts: '{' stmt_list.opt '}'  */
#line 422 "src/syntax.y"
                             {
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 2537 "src/syntax.tab.c"
    break;

  case 25: /* stmt_list.opt: stmt_list  */
#line 428 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list optional", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2547 "src/syntax.tab.c"
    break;

  case 26: /* stmt_list.opt: %empty  */
#line 433 "src/syntax.y"
                 {
		(yyval.ast) = createAstNode("stmt list empty", 1);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2556 "src/syntax.tab.c"
    break;

  case 27: /* stmt_list: stmt_list stmt.item  */
#line 440 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("stmt list", DEBUG_AST);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2567 "src/syntax.tab.c"
    break;

  case 28: /* stmt_list: stmt.item  */
#line 446 "src/syntax.y"
                   {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2575 "src/syntax.tab.c"
    break;

  case 29: /* stmt.item: stmt  */
#line 452 "src/syntax.y"
            {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2583 "src/syntax.tab.c"
    break;

  case 30: /* stmt.item: var_declaration  */
#line 455 "src/syntax.y"
                         {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2591 "src/syntax.tab.c"
    break;

  case 31: /* stmt: return_stmt  */
#line 461 "src/syntax.y"
                   {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2599 "src/syntax.tab.c"
    break;

  case 32: /* stmt: select_stmt  */
#line 464 "src/syntax.y"
                     {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2607 "src/syntax.tab.c"
    break;

  case 33: /* stmt: iter_stmt  */
#line 467 "src/syntax.y"
                   {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2615 "src/syntax.tab.c"
    break;

  case 34: /* stmt: io_stmt  */
#line 470 "src/syntax.y"
                 {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2623 "src/syntax.tab.c"
    break;

  case 35: /* stmt: exp_stmt  */
#line 473 "src/syntax.y"
                  {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2631 "src/syntax.tab.c"
    break;

  case 36: /* stmt: ';'  */
#line 476 "src/syntax.y"
             {
		(yyval.ast) = createAstNode("no operation", DEBUG_AST);
		(yyval.ast)->token_name = strdup(";");
		insertAstNode(&astList, (yyval.ast));
	}
#line 2641 "src/syntax.tab.c"
    break;

  case 37: /* stmt: ERROR_COMM  */
#line 481 "src/syntax.y"
                    {
		error_comm = 1;
		fclose(yyin);
		yylex_destroy();
		return ERROR;
	}
#line 2652 "src/syntax.tab.c"
    break;

  case 38: /* stmt: stmts  */
#line 487 "src/syntax.y"
               {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2660 "src/syntax.tab.c"
    break;

  case 39: /* select_stmt: IF '(' simple_exp ')' stmt  */
#line 493 "src/syntax.y"
                                             {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2671 "src/syntax.tab.c"
    break;

  case 40: /* select_stmt: IF '(' simple_exp ')' stmt ELSE stmt  */
#line 499 "src/syntax.y"
                                              {
		(yyval.ast) = createAstNode("select stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-4].ast);
		(yyval.ast)->children[1] = (yyvsp[-2].ast);
		(yyval.ast)->children[2] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2683 "src/syntax.tab.c"
    break;

  case 41: /* iter_stmt: FOR '(' exp ';' simple_exp ';' exp ')' stmt  */
#line 509 "src/syntax.y"
                                                   {
		(yyval.ast) = createAstNode("iter stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-6].ast);
		(yyval.ast)->children[1] = (yyvsp[-4].ast);
		(yyval.ast)->children[2] = (yyvsp[-2].ast);
		(yyval.ast)->children[3] = (yyvsp[0].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2696 "src/syntax.tab.c"
    break;

  case 42: /* exp_stmt: exp ';'  */
#line 520 "src/syntax.y"
               {
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 2704 "src/syntax.tab.c"
    break;

  case 43: /* exp: assign_exp  */
#line 526 "src/syntax.y"
                  {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2712 "src/syntax.tab.c"
    break;

  case 44: /* exp: simple_exp  */
#line 529 "src/syntax.y"
                    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2720 "src/syntax.tab.c"
    break;

  case 45: /* return_stmt: RETURN exp ';'  */
#line 535 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("return stmt", 1);
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		return_line = (yyvsp[-2].lexeme).line;
		return_column = (yyvsp[-2].lexeme).column;
		(yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
		strcpy(return_type, (yyval.ast)->children[0]->node_type);
		if(strcmp(return_type, "int") == 0){
			if(strcmp(function_type, "float") == 0){
				(yyval.ast)->node_cast = strdup(function_type);
			}
		}else if(strcmp(return_type, "float") == 0){
			if(strcmp(function_type, "int") == 0){
				(yyval.ast)->node_cast = strdup(function_type);
			}
		}
		insertAstNode(&astList, (yyval.ast));
		has_return = 1;
	}
#line 2744 "src/syntax.tab.c"
    break;

  case 46: /* io_stmt: in_stmt  */
#line 557 "src/syntax.y"
               {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2752 "src/syntax.tab.c"
    break;

  case 47: /* io_stmt: out_stmt  */
#line 560 "src/syntax.y"
                  {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2760 "src/syntax.tab.c"
    break;

  case 48: /* in_stmt: INPUT '(' ID ')' ';'  */
#line 566 "src/syntax.y"
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
		insertAstNode(&astList, (yyval.ast));
	}
#line 2777 "src/syntax.tab.c"
    break;

  case 49: /* out_stmt: OUTPUT '(' STRING ')' ';'  */
#line 581 "src/syntax.y"
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
#line 2792 "src/syntax.tab.c"
    break;

  case 50: /* out_stmt: OUTPUT '(' exp ')' ';'  */
#line 591 "src/syntax.y"
                                {
		char output_type[200];
		(yyval.ast) = createAstNode("output stmt", 1);
		strcpy(output_type, (yyvsp[-4].lexeme).lexeme_string);
		strcat(output_type, "()");
		(yyval.ast)->token_name = strdup(output_type);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		insertAstNode(&astList, (yyval.ast));
	}
#line 2806 "src/syntax.tab.c"
    break;

  case 51: /* assign_exp: ID '=' exp  */
#line 603 "src/syntax.y"
                  {
		char id_type[15];
		strcpy(id_type, getContext(&symbolTable, &contextList, (yyvsp[-2].lexeme).lexeme_string, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("assign exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-2].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup(id_type);
		(yyval.ast)->token_line = (yyvsp[-2].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-2].lexeme).column;
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		if(checklvalueAssignment(&symbolTable, &contextList, (yyvsp[-2].lexeme).lexeme_string, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, &semantic_errors)){
			if(strcmp(id_type, "int") == 0){
				if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0){
					(yyval.ast)->node_type = strdup(id_type);
				}else if(strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
					(yyval.ast)->node_type = strdup(id_type);
					(yyval.ast)->children[0]->node_cast = strdup(id_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in assignment operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
					RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, id_type, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, WHITE);
					(yyval.ast)->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp(id_type, "float") == 0){
				if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0){
					(yyval.ast)->node_type = strdup(id_type);
					(yyval.ast)->children[0]->node_cast = strdup(id_type);
				}else if(strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
					(yyval.ast)->node_type = strdup(id_type);
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in assignment operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
					RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, id_type, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, WHITE);
					(yyval.ast)->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp(id_type, "int list") == 0){
				if(strcmp((yyval.ast)->children[0]->node_type, "int list") == 0 || strcmp((yyval.ast)->children[0]->node_type, "float list") == 0 || strcmp((yyval.ast)->children[0]->node_type, "nil") == 0){
					(yyval.ast)->node_type = strdup(id_type);
					if(strcmp((yyval.ast)->children[0]->node_type, "float list") == 0){
						(yyval.ast)->children[0]->node_cast = strdup("int");		// Cast elements to int, in order to assign an int list
					}
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in assignment operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
					RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, id_type, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, WHITE);
					(yyval.ast)->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}else if(strcmp(id_type, "float list") == 0){
				if(strcmp((yyval.ast)->children[0]->node_type, "float list") == 0 || strcmp((yyval.ast)->children[0]->node_type, "int list") == 0 || strcmp((yyval.ast)->children[0]->node_type, "nil") == 0){
					(yyval.ast)->node_type = strdup(id_type);
					if(strcmp((yyval.ast)->children[0]->node_type, "int list") == 0){
						(yyval.ast)->children[0]->node_cast = strdup("float");	// Cast elements to float, in order to assign a float list
					}
				}else{
					printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in assignment operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
					RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, id_type, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, WHITE);
					(yyval.ast)->node_type = strdup("undefined");
					semantic_errors+= 1;
				}
			}
		}else{
			(yyval.ast)->node_type = strdup("invalid");
		}
		insertAstNode(&astList, (yyval.ast));
	}
#line 2875 "src/syntax.tab.c"
    break;

  case 52: /* simple_exp: simple_exp LOGICAL_OR and_exp  */
#line 670 "src/syntax.y"
                                     {
		(yyval.ast) = createAstNode("simple exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0){
            if(strcmp((yyval.ast)->children[1]->node_type, "int") == 0){
                (yyval.ast)->node_type = strdup("int");
            }else if(strcmp((yyval.ast)->children[1]->node_type, "float") == 0){
                (yyval.ast)->node_type = strdup("int");
				(yyval.ast)->children[0]->node_cast = strdup((yyval.ast)->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in logical operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
            if(strcmp((yyval.ast)->children[1]->node_type, "int") == 0){
                (yyval.ast)->node_type = strdup("int");
				(yyval.ast)->children[1]->node_cast = strdup((yyval.ast)->children[0]->node_type);
            }else if(strcmp((yyval.ast)->children[1]->node_type, "float") == 0){
                (yyval.ast)->node_type = strdup("int");
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in logical operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else{
            printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in logical operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
			(yyval.ast)->node_type = strdup("undefined");
			semantic_errors+= 1;
        }
		insertAstNode(&astList, (yyval.ast));
	}
#line 2917 "src/syntax.tab.c"
    break;

  case 53: /* simple_exp: and_exp  */
#line 707 "src/syntax.y"
                 {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2925 "src/syntax.tab.c"
    break;

  case 54: /* simple_exp: error  */
#line 710 "src/syntax.y"
                {
		(yyval.ast) = createAstNode("error", DEBUG_AST);
		(yyval.ast)->node_type = strdup("invalid");
		insertAstNode(&astList, (yyval.ast));
		yyerrok;
	}
#line 2936 "src/syntax.tab.c"
    break;

  case 55: /* and_exp: and_exp LOGICAL_AND rel_exp  */
#line 719 "src/syntax.y"
                                   {
		(yyval.ast) = createAstNode("and exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0){
            if(strcmp((yyval.ast)->children[1]->node_type, "int") == 0){
                (yyval.ast)->node_type = strdup("int");
            }else if(strcmp((yyval.ast)->children[1]->node_type, "float") == 0){
                (yyval.ast)->node_type = strdup("int");
				(yyval.ast)->children[0]->node_cast = strdup((yyval.ast)->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in logical operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
            if(strcmp((yyval.ast)->children[1]->node_type, "int") == 0){
                (yyval.ast)->node_type = strdup("int");
				(yyval.ast)->children[1]->node_cast = strdup((yyval.ast)->children[0]->node_type);
            }else if(strcmp((yyval.ast)->children[1]->node_type, "float") == 0){
                (yyval.ast)->node_type = strdup("int");
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else{
            printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
			(yyval.ast)->node_type = strdup("undefined");
			semantic_errors+= 1;
        }
		insertAstNode(&astList, (yyval.ast));
	}
#line 2978 "src/syntax.tab.c"
    break;

  case 56: /* and_exp: rel_exp  */
#line 756 "src/syntax.y"
                 {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2986 "src/syntax.tab.c"
    break;

  case 57: /* rel_exp: rel_exp RELATIONAL list_exp  */
#line 762 "src/syntax.y"
                                   {
		(yyval.ast) = createAstNode("rel exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0){
            if(strcmp((yyval.ast)->children[1]->node_type, "int") == 0){
                (yyval.ast)->node_type = strdup("int");
            }else if(strcmp((yyval.ast)->children[1]->node_type, "float") == 0){
                (yyval.ast)->node_type = strdup("int");
				(yyval.ast)->children[0]->node_cast = strdup((yyval.ast)->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
            if(strcmp((yyval.ast)->children[1]->node_type, "int") == 0){
                (yyval.ast)->node_type = strdup("int");
				(yyval.ast)->children[1]->node_cast = strdup((yyval.ast)->children[0]->node_type);
            }else if(strcmp((yyval.ast)->children[1]->node_type, "float") == 0){
                (yyval.ast)->node_type = strdup("int");
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp((yyval.ast)->children[0]->node_type, "int list") == 0){
			if(strcmp((yyval.ast)->children[1]->node_type, "int list") == 0 || strcmp((yyval.ast)->children[1]->node_type, "nil") == 0){
				(yyval.ast)->node_type = strdup("int");
			}else{
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
		}else if(strcmp((yyval.ast)->children[0]->node_type, "float list") == 0){
			if(strcmp((yyval.ast)->children[1]->node_type, "float list") == 0 || strcmp((yyval.ast)->children[1]->node_type, "nil") == 0){
				(yyval.ast)->node_type = strdup("int");
			}else{
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in relational operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
			(yyval.ast)->node_type = strdup("undefined");
			semantic_errors+= 1;
        }
		insertAstNode(&astList, (yyval.ast));
	}
#line 3046 "src/syntax.tab.c"
    break;

  case 58: /* rel_exp: list_exp  */
#line 817 "src/syntax.y"
                  {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3054 "src/syntax.tab.c"
    break;

  case 59: /* list_exp: sum_exp LIST_CONSTR list_exp  */
#line 823 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("list exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0 || strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
			if(strcmp((yyval.ast)->children[1]->node_type, "int list") == 0 || strcmp((yyval.ast)->children[1]->node_type, "float list") == 0){
				(yyval.ast)->node_type = strdup((yyval.ast)->children[1]->node_type);
			}else{
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in list operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in list operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
			(yyval.ast)->node_type = strdup("undefined");
			semantic_errors+= 1;
		}
		insertAstNode(&astList, (yyval.ast));
	}
#line 3081 "src/syntax.tab.c"
    break;

  case 60: /* list_exp: sum_exp LIST_FUNC list_exp  */
#line 845 "src/syntax.y"
                                    {
		(yyval.ast) = createAstNode("list exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0 || strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
			if(strcmp((yyval.ast)->children[1]->node_type, "int list") == 0 || strcmp((yyval.ast)->children[1]->node_type, "float list") == 0){
				(yyval.ast)->node_type = strdup((yyval.ast)->children[1]->node_type);
			}else{
				printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in list operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
			}
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in list operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
			(yyval.ast)->node_type = strdup("undefined");
			semantic_errors+= 1;
		}
		insertAstNode(&astList, (yyval.ast));
	}
#line 3108 "src/syntax.tab.c"
    break;

  case 61: /* list_exp: sum_exp  */
#line 867 "src/syntax.y"
                 {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3116 "src/syntax.tab.c"
    break;

  case 62: /* sum_exp: sum_exp ADD mul_exp  */
#line 873 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("sum exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0){
            if(strcmp((yyval.ast)->children[1]->node_type, "int") == 0){
                (yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
            }else if(strcmp((yyval.ast)->children[1]->node_type, "float") == 0){
                (yyval.ast)->node_type = strdup((yyval.ast)->children[1]->node_type);
				(yyval.ast)->children[0]->node_cast = strdup((yyval.ast)->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in additive operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
            if(strcmp((yyval.ast)->children[1]->node_type, "int") == 0){
                (yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
				(yyval.ast)->children[1]->node_cast = strdup((yyval.ast)->children[0]->node_type);
            }else if(strcmp((yyval.ast)->children[1]->node_type, "float") == 0){
                (yyval.ast)->node_type = strdup((yyval.ast)->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in additive operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else{
            printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in additive operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
			(yyval.ast)->node_type = strdup("undefined");
			semantic_errors+= 1;
        }
		insertAstNode(&astList, (yyval.ast));
	}
#line 3158 "src/syntax.tab.c"
    break;

  case 63: /* sum_exp: mul_exp  */
#line 910 "src/syntax.y"
                 {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3166 "src/syntax.tab.c"
    break;

  case 64: /* mul_exp: mul_exp MUL unary_exp  */
#line 916 "src/syntax.y"
                             {
		(yyval.ast) = createAstNode("mul exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0){
            if(strcmp((yyval.ast)->children[1]->node_type, "int") == 0){
                (yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
            }else if(strcmp((yyval.ast)->children[1]->node_type, "float") == 0){
                (yyval.ast)->node_type = strdup((yyval.ast)->children[1]->node_type);
				(yyval.ast)->children[0]->node_cast = strdup((yyval.ast)->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in multiplicative operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else if(strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
            if(strcmp((yyval.ast)->children[1]->node_type, "int") == 0){
                (yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
				(yyval.ast)->children[1]->node_cast = strdup((yyval.ast)->children[0]->node_type);
            }else if(strcmp((yyval.ast)->children[1]->node_type, "float") == 0){
                (yyval.ast)->node_type = strdup((yyval.ast)->children[1]->node_type);
            }else{
                printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in multiplicative operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
				RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
				(yyval.ast)->node_type = strdup("undefined");
				semantic_errors+= 1;
            }
        }else{
            printf("%sLine:%d\tColumn:%d\tSemantic error! Binary type error in multiplicative operation %s%s%s between %s%s%s and %s%s%s expressions.%s\n", 
			RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, BLUE, (yyval.ast)->children[1]->node_type, RED, WHITE);
			(yyval.ast)->node_type = strdup("undefined");
			semantic_errors+= 1;
        }
		insertAstNode(&astList, (yyval.ast));
	}
#line 3208 "src/syntax.tab.c"
    break;

  case 65: /* mul_exp: unary_exp  */
#line 953 "src/syntax.y"
                   {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3216 "src/syntax.tab.c"
    break;

  case 66: /* unary_exp: factor  */
#line 959 "src/syntax.y"
              {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3224 "src/syntax.tab.c"
    break;

  case 67: /* unary_exp: LIST_OP unary_exp  */
#line 962 "src/syntax.y"
                           {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		if(strcmp((yyval.ast)->children[0]->node_type, "int list") == 0 || strcmp((yyval.ast)->children[0]->node_type, "float list") == 0){
			(yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Unary type error in operation %s%s%s to %s%s%s expression.%s\n", 
			RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, WHITE);
			(yyval.ast)->node_type = strdup("undefined");
			semantic_errors+= 1;
		}
		insertAstNode(&astList, (yyval.ast));
	}
#line 3243 "src/syntax.tab.c"
    break;

  case 68: /* unary_exp: LIST_DESTR unary_exp  */
#line 976 "src/syntax.y"
                              {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		if(strcmp((yyval.ast)->children[0]->node_type, "int list") == 0 || strcmp((yyval.ast)->children[0]->node_type, "float list") == 0){
			(yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Unary type error in operation %s%s%s to %s%s%s expression.%s\n", 
			RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, WHITE);
			(yyval.ast)->node_type = strdup("undefined");
			semantic_errors+= 1;
		}
		insertAstNode(&astList, (yyval.ast));
	}
#line 3262 "src/syntax.tab.c"
    break;

  case 69: /* unary_exp: OP_OVERLOAD unary_exp  */
#line 990 "src/syntax.y"
                               {
		(yyval.ast) = createAstNode("unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		(yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
		insertAstNode(&astList, (yyval.ast));
	}
#line 3274 "src/syntax.tab.c"
    break;

  case 70: /* unary_exp: ADD unary_exp  */
#line 997 "src/syntax.y"
                       {
		(yyval.ast) = createAstNode("signed unary exp", 1);
		(yyval.ast)->token_name = strdup((yyvsp[-1].lexeme).lexeme_string);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		if(strcmp((yyval.ast)->children[0]->node_type, "int") == 0 || strcmp((yyval.ast)->children[0]->node_type, "float") == 0){
			(yyval.ast)->node_type = strdup((yyval.ast)->children[0]->node_type);
		}else{
			printf("%sLine:%d\tColumn:%d\tSemantic error! Unary type error in assigning %s%s%s to %s%s%s expression.%s\n", 
			RED, (yyvsp[-1].lexeme).line, (yyvsp[-1].lexeme).column, YELLOW, (yyvsp[-1].lexeme).lexeme_string, RED, BLUE, (yyval.ast)->children[0]->node_type, RED, WHITE);
			(yyval.ast)->node_type = strdup("undefined");
			semantic_errors+= 1;
			error_signal = 1;
		}
		insertAstNode(&astList, (yyval.ast));
	}
#line 3294 "src/syntax.tab.c"
    break;

  case 71: /* factor: ID  */
#line 1015 "src/syntax.y"
          {
		char id_type[15];
		strcpy(id_type, getContext(&symbolTable, &contextList, (yyvsp[0].lexeme).lexeme_string, (yyvsp[0].lexeme).line, (yyvsp[0].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("id", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup(id_type);
		(yyval.ast)->node_type = strdup(id_type);
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3310 "src/syntax.tab.c"
    break;

  case 72: /* factor: '(' simple_exp ')'  */
#line 1026 "src/syntax.y"
                            {
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 3318 "src/syntax.tab.c"
    break;

  case 73: /* factor: func_call  */
#line 1029 "src/syntax.y"
                   {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3326 "src/syntax.tab.c"
    break;

  case 74: /* factor: constant  */
#line 1032 "src/syntax.y"
                  {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3334 "src/syntax.tab.c"
    break;

  case 75: /* func_call: ID '(' func_params ')'  */
#line 1038 "src/syntax.y"
                              {
		char func_id[200];
		char func_type[15];
		strcpy(func_type, getContext(&symbolTable, &contextList, (yyvsp[-3].lexeme).lexeme_string, (yyvsp[-3].lexeme).line, (yyvsp[-3].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("func call", 1);
		strcpy(func_id, (yyvsp[-3].lexeme).lexeme_string);
		strcat(func_id, "()");
		(yyval.ast)->token_name = strdup(func_id);
		(yyval.ast)->token_print = strdup(func_type);
		(yyval.ast)->node_type = strdup(func_type);
		(yyval.ast)->token_line = (yyvsp[-3].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-3].lexeme).column;
		(yyval.ast)->children[0] = (yyvsp[-1].ast);
		insertAstNode(&astList, (yyval.ast));
		checkFunctionCall(&symbolTable, &contextList, &parameterTypeList, (yyvsp[-3].lexeme).lexeme_string, (yyvsp[-3].lexeme).line, (yyvsp[-3].lexeme).column, func_params_counter, &semantic_errors);
		func_params_counter = 0;
	}
#line 3356 "src/syntax.tab.c"
    break;

  case 76: /* func_call: ID '(' ')'  */
#line 1055 "src/syntax.y"
                    {
		char func_id[200];
		char func_type[15];
		strcpy(func_type, getContext(&symbolTable, &contextList, (yyvsp[-2].lexeme).lexeme_string, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, &semantic_errors));
		(yyval.ast) = createAstNode("func call", 1);
		strcpy(func_id, (yyvsp[-2].lexeme).lexeme_string);
		strcat(func_id, "()");
		(yyval.ast)->token_name = strdup(func_id);
		(yyval.ast)->token_print = strdup(func_type);
		(yyval.ast)->node_type = strdup(func_type);
		(yyval.ast)->token_line = (yyvsp[-2].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[-2].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
		checkFunctionCall(&symbolTable, &contextList, &parameterTypeList, (yyvsp[-2].lexeme).lexeme_string, (yyvsp[-2].lexeme).line, (yyvsp[-2].lexeme).column, 0, &semantic_errors);
	}
#line 3376 "src/syntax.tab.c"
    break;

  case 77: /* func_params: simple_exp  */
#line 1073 "src/syntax.y"
                  {
		func_params_counter+= 1;
		(yyval.ast) = createAstNode("func params", 1);
		(yyval.ast)->children[0] = (yyvsp[0].ast);
		insertParameterType((yyval.ast)->children[0]->node_type, &parameterTypeList);
		insertAstNode(&astList, (yyval.ast));
	}
#line 3388 "src/syntax.tab.c"
    break;

  case 78: /* func_params: func_params ',' simple_exp  */
#line 1080 "src/syntax.y"
                                    {
		func_params_counter+= 1;
		(yyval.ast) = createAstNode("func params", 1);
		(yyval.ast)->children[0] = (yyvsp[-2].ast);
		(yyval.ast)->children[1] = (yyvsp[0].ast);
		insertParameterType((yyval.ast)->children[1]->node_type, &parameterTypeList);
		insertAstNode(&astList, (yyval.ast));
	}
#line 3401 "src/syntax.tab.c"
    break;

  case 79: /* constant: INTEGER  */
#line 1091 "src/syntax.y"
               {
		(yyval.ast) = createAstNode("int constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup("int");
		(yyval.ast)->node_type = strdup("int");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3415 "src/syntax.tab.c"
    break;

  case 80: /* constant: REAL  */
#line 1100 "src/syntax.y"
              {
		(yyval.ast) = createAstNode("real constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup("float");
		(yyval.ast)->node_type = strdup("float");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3429 "src/syntax.tab.c"
    break;

  case 81: /* constant: NIL_CONSTANT  */
#line 1109 "src/syntax.y"
                      {
		(yyval.ast) = createAstNode("nil constant", 1);
		(yyval.ast)->token_name = strdup((yyvsp[0].lexeme).lexeme_string);
		(yyval.ast)->token_print = strdup("nil");
		(yyval.ast)->node_type = strdup("nil");
		(yyval.ast)->token_line = (yyvsp[0].lexeme).line;
		(yyval.ast)->token_column = (yyvsp[0].lexeme).column;
		insertAstNode(&astList, (yyval.ast));
	}
#line 3443 "src/syntax.tab.c"
    break;


#line 3447 "src/syntax.tab.c"

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

#line 1120 "src/syntax.y"


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
	if(!error_comm)
		fclose(yyin);

	if(!hasMainFunction(&symbolTable)){
		printf("%sLine:?\tColumn:?\tSemantic error! Undefined reference to %s`main()`%s function.%s\n", RED, PURPLE, RED, WHITE);
		semantic_errors+= 1;
	}

	if(syntax_errors == 0){
		if(error_signal == 0){
			updateSignal(&root);	// update signal (int/real constants)... i think it will be useful at TAC
		}
		printAST(&root);
	}else{
		printf("\n%s~> AST tree will not be printed, due to syntax error(s).%s\n", RED, WHITE);
	}

	printTable(&symbolTable);

	if(lexical_errors == 0)
		printf("\n%sLexical analysis finished without error(s).%s", GREEN, WHITE);
	else
		printf("\n%sLexical analysis finished with %d error(s).%s", RED, lexical_errors, WHITE);
		
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
	freeParameterTypeList(&parameterTypeList);	// avoid mem leak caused by func params semantic errors.

	if(!error_comm)
		yylex_destroy();
		
	return 0;
}

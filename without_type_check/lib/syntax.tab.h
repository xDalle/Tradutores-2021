/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LIB_SYNTAX_TAB_H_INCLUDED
# define YY_YY_LIB_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ADD = 258,                     /* ADD  */
    MUL = 259,                     /* MUL  */
    INTEGER = 260,                 /* INTEGER  */
    REAL = 261,                    /* REAL  */
    LOGICAL_OR = 262,              /* LOGICAL_OR  */
    LOGICAL_AND = 263,             /* LOGICAL_AND  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    FOR = 266,                     /* FOR  */
    RETURN = 267,                  /* RETURN  */
    INPUT = 268,                   /* INPUT  */
    OUTPUT = 269,                  /* OUTPUT  */
    SIMPLE_TYPE = 270,             /* SIMPLE_TYPE  */
    COMPOUND_TYPE = 271,           /* COMPOUND_TYPE  */
    ID = 272,                      /* ID  */
    NIL_CONSTANT = 273,            /* NIL_CONSTANT  */
    LIST_CONSTR = 274,             /* LIST_CONSTR  */
    LIST_OP = 275,                 /* LIST_OP  */
    LIST_DESTR = 276,              /* LIST_DESTR  */
    LIST_FUNC = 277,               /* LIST_FUNC  */
    RELATIONAL = 278,              /* RELATIONAL  */
    STRING = 279,                  /* STRING  */
    OP_OVERLOAD = 280,             /* OP_OVERLOAD  */
    ERROR_STR = 281,               /* ERROR_STR  */
    ERROR_CHAR = 282,              /* ERROR_CHAR  */
    ERROR_COMM = 283,              /* ERROR_COMM  */
    THEN = 284                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "src/syntax.y"

	struct Ast *ast;
	struct Lexeme {
		char lexeme_string[200];
		int line;
		int column;
		int scope;
		int length;
	}lexeme;

#line 104 "lib/syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LIB_SYNTAX_TAB_H_INCLUDED  */

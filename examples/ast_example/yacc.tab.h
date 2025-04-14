/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
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
    IDENFR = 258,                  /* IDENFR  */
    STRCON = 259,                  /* STRCON  */
    INTCON = 260,                  /* INTCON  */
    MAINTK = 261,                  /* MAINTK  */
    CONSTTK = 262,                 /* CONSTTK  */
    INTTK = 263,                   /* INTTK  */
    BREAKTK = 264,                 /* BREAKTK  */
    CONTINUETK = 265,              /* CONTINUETK  */
    IFTK = 266,                    /* IFTK  */
    ELSETK = 267,                  /* ELSETK  */
    WHILETK = 268,                 /* WHILETK  */
    GETINTTK = 269,                /* GETINTTK  */
    PRINTFTK = 270,                /* PRINTFTK  */
    RETURNTK = 271,                /* RETURNTK  */
    VOIDTK = 272,                  /* VOIDTK  */
    PLUS = 273,                    /* PLUS  */
    MINU = 274,                    /* MINU  */
    MULT = 275,                    /* MULT  */
    DIV = 276,                     /* DIV  */
    MOD = 277,                     /* MOD  */
    AND = 278,                     /* AND  */
    OR = 279,                      /* OR  */
    NOT = 280,                     /* NOT  */
    LSS = 281,                     /* LSS  */
    LEQ = 282,                     /* LEQ  */
    GRE = 283,                     /* GRE  */
    GEQ = 284,                     /* GEQ  */
    EQL = 285,                     /* EQL  */
    NEQ = 286,                     /* NEQ  */
    ASSIGN = 287,                  /* ASSIGN  */
    SEMICN = 288,                  /* SEMICN  */
    COMMA = 289,                   /* COMMA  */
    LPARENT = 290,                 /* LPARENT  */
    RPARENT = 291,                 /* RPARENT  */
    LBRACK = 292,                  /* LBRACK  */
    RBRACK = 293,                  /* RBRACK  */
    LBRACE = 294,                  /* LBRACE  */
    RBRACE = 295                   /* RBRACE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 83 "yacc.y"

    char* str_val;
    int int_val;
    BaseAST* ast_ptr;
    CompUnitAST* comp_unit_ptr;
    DeclAST* decl_ptr;
    ConstDeclAST* const_decl_ptr;
    VarDeclAST* var_decl_ptr;
    MainFuncDefAST* main_func_def_ptr;
    BlockAST* block_ptr;
    StmtAST* stmt_ptr;
    AssignmentAST* assignment_ptr;

#line 118 "yacc.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */

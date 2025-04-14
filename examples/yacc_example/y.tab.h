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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    MAINTK = 258,                  /* MAINTK  */
    CONSTTK = 259,                 /* CONSTTK  */
    INTTK = 260,                   /* INTTK  */
    BREAKTK = 261,                 /* BREAKTK  */
    CONTINUETK = 262,              /* CONTINUETK  */
    IFTK = 263,                    /* IFTK  */
    ELSETK = 264,                  /* ELSETK  */
    WHILETK = 265,                 /* WHILETK  */
    GETINTTK = 266,                /* GETINTTK  */
    PRINTFTK = 267,                /* PRINTFTK  */
    RETURNTK = 268,                /* RETURNTK  */
    VOIDTK = 269,                  /* VOIDTK  */
    IDENFR = 270,                  /* IDENFR  */
    INTCON = 271,                  /* INTCON  */
    STRCON = 272,                  /* STRCON  */
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
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define MAINTK 258
#define CONSTTK 259
#define INTTK 260
#define BREAKTK 261
#define CONTINUETK 262
#define IFTK 263
#define ELSETK 264
#define WHILETK 265
#define GETINTTK 266
#define PRINTFTK 267
#define RETURNTK 268
#define VOIDTK 269
#define IDENFR 270
#define INTCON 271
#define STRCON 272
#define PLUS 273
#define MINU 274
#define MULT 275
#define DIV 276
#define MOD 277
#define AND 278
#define OR 279
#define NOT 280
#define LSS 281
#define LEQ 282
#define GRE 283
#define GEQ 284
#define EQL 285
#define NEQ 286
#define ASSIGN 287
#define SEMICN 288
#define COMMA 289
#define LPARENT 290
#define RPARENT 291
#define LBRACK 292
#define RBRACK 293
#define LBRACE 294
#define RBRACE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

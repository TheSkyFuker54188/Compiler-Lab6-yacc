/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern char* yytext;
void yyerror(const char* s);
int yylex(void);

// 控制输出的变量
int print_var_decl = 0;     // 控制VarDecl打印
int top_level = 1;          // 是否在顶层

#line 86 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAINTK = 3,                     /* MAINTK  */
  YYSYMBOL_CONSTTK = 4,                    /* CONSTTK  */
  YYSYMBOL_INTTK = 5,                      /* INTTK  */
  YYSYMBOL_BREAKTK = 6,                    /* BREAKTK  */
  YYSYMBOL_CONTINUETK = 7,                 /* CONTINUETK  */
  YYSYMBOL_IFTK = 8,                       /* IFTK  */
  YYSYMBOL_ELSETK = 9,                     /* ELSETK  */
  YYSYMBOL_WHILETK = 10,                   /* WHILETK  */
  YYSYMBOL_GETINTTK = 11,                  /* GETINTTK  */
  YYSYMBOL_PRINTFTK = 12,                  /* PRINTFTK  */
  YYSYMBOL_RETURNTK = 13,                  /* RETURNTK  */
  YYSYMBOL_VOIDTK = 14,                    /* VOIDTK  */
  YYSYMBOL_IDENFR = 15,                    /* IDENFR  */
  YYSYMBOL_INTCON = 16,                    /* INTCON  */
  YYSYMBOL_STRCON = 17,                    /* STRCON  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINU = 19,                      /* MINU  */
  YYSYMBOL_MULT = 20,                      /* MULT  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_MOD = 22,                       /* MOD  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_LSS = 26,                       /* LSS  */
  YYSYMBOL_LEQ = 27,                       /* LEQ  */
  YYSYMBOL_GRE = 28,                       /* GRE  */
  YYSYMBOL_GEQ = 29,                       /* GEQ  */
  YYSYMBOL_EQL = 30,                       /* EQL  */
  YYSYMBOL_NEQ = 31,                       /* NEQ  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_SEMICN = 33,                    /* SEMICN  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_LPARENT = 35,                   /* LPARENT  */
  YYSYMBOL_RPARENT = 36,                   /* RPARENT  */
  YYSYMBOL_LBRACK = 37,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 38,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 39,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 40,                    /* RBRACE  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_CompUnit = 42,                  /* CompUnit  */
  YYSYMBOL_Decl = 43,                      /* Decl  */
  YYSYMBOL_ConstDecl = 44,                 /* ConstDecl  */
  YYSYMBOL_VarDecl = 45,                   /* VarDecl  */
  YYSYMBOL_FuncDef = 46,                   /* FuncDef  */
  YYSYMBOL_MainFuncDef = 47,               /* MainFuncDef  */
  YYSYMBOL_FuncFParams = 48,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 49,                /* FuncFParam  */
  YYSYMBOL_FuncFParamArrayList = 50,       /* FuncFParamArrayList  */
  YYSYMBOL_Block = 51,                     /* Block  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_BlockItems = 54,                /* BlockItems  */
  YYSYMBOL_BlockItem = 55,                 /* BlockItem  */
  YYSYMBOL_Stmt = 56,                      /* Stmt  */
  YYSYMBOL_PrintfParams = 57,              /* PrintfParams  */
  YYSYMBOL_LVal = 58,                      /* LVal  */
  YYSYMBOL_LValArrayList = 59,             /* LValArrayList  */
  YYSYMBOL_Exp = 60,                       /* Exp  */
  YYSYMBOL_Cond = 61,                      /* Cond  */
  YYSYMBOL_ConstExp = 62,                  /* ConstExp  */
  YYSYMBOL_LOrExp = 63,                    /* LOrExp  */
  YYSYMBOL_LAndExp = 64,                   /* LAndExp  */
  YYSYMBOL_EqExp = 65,                     /* EqExp  */
  YYSYMBOL_RelExp = 66,                    /* RelExp  */
  YYSYMBOL_AddExp = 67,                    /* AddExp  */
  YYSYMBOL_MulExp = 68,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 69,                  /* UnaryExp  */
  YYSYMBOL_FuncRParams = 70,               /* FuncRParams  */
  YYSYMBOL_PrimaryExp = 71,                /* PrimaryExp  */
  YYSYMBOL_Number = 72,                    /* Number  */
  YYSYMBOL_InitVal = 73,                   /* InitVal  */
  YYSYMBOL_LBraceInitVal = 74,             /* LBraceInitVal  */
  YYSYMBOL_InitValList = 75                /* InitValList  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    27,    27,    30,    33,    36,    39,    42,    48,    52,
      60,    63,    66,    69,    75,    82,    89,    96,   103,   106,
     109,   112,   118,   121,   124,   127,   133,   139,   140,   144,
     145,   146,   150,   151,   155,   155,   159,   159,   166,   167,
     171,   172,   176,   179,   182,   185,   188,   191,   194,   197,
     200,   203,   206,   209,   212,   215,   221,   222,   226,   227,
     231,   232,   236,   240,   244,   248,   249,   253,   254,   258,
     259,   260,   264,   265,   266,   267,   268,   272,   273,   274,
     278,   279,   280,   281,   285,   286,   287,   288,   289,   290,
     294,   295,   299,   300,   301,   305,   309,   313,   314,   318,
     319
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAINTK", "CONSTTK",
  "INTTK", "BREAKTK", "CONTINUETK", "IFTK", "ELSETK", "WHILETK",
  "GETINTTK", "PRINTFTK", "RETURNTK", "VOIDTK", "IDENFR", "INTCON",
  "STRCON", "PLUS", "MINU", "MULT", "DIV", "MOD", "AND", "OR", "NOT",
  "LSS", "LEQ", "GRE", "GEQ", "EQL", "NEQ", "ASSIGN", "SEMICN", "COMMA",
  "LPARENT", "RPARENT", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "$accept",
  "CompUnit", "Decl", "ConstDecl", "VarDecl", "FuncDef", "MainFuncDef",
  "FuncFParams", "FuncFParam", "FuncFParamArrayList", "Block", "$@1",
  "$@2", "BlockItems", "BlockItem", "Stmt", "PrintfParams", "LVal",
  "LValArrayList", "Exp", "Cond", "ConstExp", "LOrExp", "LAndExp", "EqExp",
  "RelExp", "AddExp", "MulExp", "UnaryExp", "FuncRParams", "PrimaryExp",
  "Number", "InitVal", "LBraceInitVal", "InitValList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-168)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-35)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,     5,    10,     1,    82,  -168,     8,    16,  -168,  -168,
      14,    21,    11,    36,  -168,  -168,  -168,  -168,  -168,    65,
    -168,    92,    25,    58,   133,    -1,   133,     2,    26,    52,
     133,   133,    62,    53,  -168,   133,   133,   133,   133,  -168,
    -168,    79,   186,  -168,  -168,  -168,  -168,    95,    62,     0,
    -168,    78,    79,    62,    94,   133,   133,   133,   133,  -168,
      81,    85,  -168,   194,   133,    99,  -168,  -168,  -168,   103,
     133,   133,   133,   133,   133,   105,  -168,   117,    62,   118,
    -168,    62,  -168,   116,  -168,   121,   142,   139,    60,  -168,
    -168,    98,   144,   133,  -168,   186,   186,  -168,  -168,  -168,
     151,  -168,  -168,   154,  -168,   164,   190,   154,  -168,   208,
     192,   193,   196,   198,   200,   199,  -168,  -168,  -168,   165,
    -168,  -168,   195,   203,   133,  -168,  -168,   201,   191,   176,
    -168,   154,   154,  -168,    86,  -168,  -168,   133,   133,   220,
    -168,   205,  -168,  -168,   122,  -168,  -168,  -168,   133,   204,
    -168,  -168,   -23,  -168,  -168,   206,   216,   221,   115,   159,
      79,   207,   119,  -168,   210,   213,   209,   133,   133,  -168,
      96,   133,   133,   133,   133,   133,   133,   133,   133,    96,
     133,   215,   163,   214,  -168,  -168,   211,  -168,   242,   221,
     115,   159,   159,    79,    79,    79,    79,  -168,  -168,  -168,
     133,   219,   222,  -168,    96,  -168,  -168,  -168,  -168
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     0,     3,     4,
       0,     0,    14,     0,     1,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,    58,    95,     0,     0,     0,     0,    93,
      96,    62,    77,    80,    84,    94,    16,     0,     0,     0,
      27,     0,    64,     0,     0,     0,     0,     0,     0,    10,
       0,    36,    26,     0,     0,    59,    85,    86,    87,     0,
       0,     0,     0,     0,     0,    29,    22,     0,     0,    15,
      23,     0,    12,     0,    20,     0,     0,     0,     0,    88,
      90,     0,     0,     0,    92,    78,    79,    81,    82,    83,
       0,    28,    24,     0,    25,     0,    19,     0,    35,     0,
       0,     0,     0,     0,     0,     0,    43,    40,    45,     0,
      38,    41,    93,     0,     0,    89,    60,     0,    30,     0,
      17,     0,     0,    11,    14,    49,    50,     0,     0,     0,
      51,     0,    37,    39,     0,    44,    91,    61,     0,    31,
      97,    99,     0,    13,    21,     0,    63,    65,    67,    69,
      72,     0,     0,    52,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    32,     0,   100,    46,    66,
      68,    70,    71,    73,    74,    75,    76,    48,    56,    54,
       0,     0,     0,    33,     0,    57,    53,    55,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,    77,  -168,  -168,   249,   250,   229,   180,  -168,
     -27,  -168,  -168,  -168,   140,  -167,  -168,   -87,  -168,   -24,
     120,    -3,  -168,    89,    90,    29,   -11,   150,   -13,  -168,
    -168,  -168,   -55,  -101,  -168
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,   117,     6,     7,     8,     9,    49,    50,   149,
     118,    87,    88,   119,   120,   121,   182,    39,    65,   123,
     155,    51,   156,   157,   158,   159,    41,    42,    43,    91,
      44,    45,    46,   130,   152
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,   122,    84,   188,    47,    62,   133,    47,     1,     2,
      10,   168,   197,    11,    69,    52,    13,   169,     3,    52,
      52,    76,    66,    67,    68,    12,    80,    59,    60,    22,
     153,   154,   122,    40,    77,    48,    78,   208,    53,    90,
      92,    18,    19,    24,    52,    52,    25,    52,    26,    20,
      21,   102,    82,    83,   104,    85,    23,    30,    55,    97,
      98,    99,    31,    56,     1,   109,   110,   111,   112,   127,
     113,    27,   114,   115,   151,    33,    34,     5,    35,    36,
      28,    15,    14,   122,    57,    37,     1,     2,    63,    58,
      64,   141,   122,   116,    32,    38,     3,    70,    71,    61,
     146,    61,   110,   111,   112,    40,   113,    29,   114,   115,
      75,    33,    34,   187,    35,    36,    79,   122,    24,    86,
     165,    37,    47,    26,   166,   -34,   160,   160,    77,   116,
      81,    38,   124,   164,   125,    61,    93,    33,    34,    94,
      35,    36,   100,   186,    40,   173,   174,    37,    33,    34,
     103,    35,    36,   180,   105,   181,   198,    38,    37,   106,
     160,   160,   160,   160,   193,   194,   195,   196,    38,     1,
     109,   110,   111,   112,   107,   113,   205,   114,   115,   108,
      33,    34,   126,    35,    36,   175,   176,   177,   178,   128,
      37,    33,    34,   129,    35,    36,   131,   200,   116,   201,
      38,    37,   191,   192,    61,   142,    72,    73,    74,    33,
      34,    38,    35,    36,    33,    34,   150,    35,    36,    37,
      95,    96,   132,   134,    37,   135,   136,   144,   148,    38,
      89,   137,   140,   138,    38,   139,   145,   162,   163,   147,
     171,   167,   170,   179,   172,   183,   184,   185,   199,   203,
     202,   204,   206,    16,    17,   207,    54,   101,   161,   143,
     189,     0,   190
};

static const yytype_int16 yycheck[] =
{
      24,    88,    57,   170,     5,    32,   107,     5,     4,     5,
       5,    34,   179,     3,    38,    26,    15,    40,    14,    30,
      31,    48,    35,    36,    37,    15,    53,    30,    31,    15,
     131,   132,   119,    57,    34,    36,    36,   204,    36,    63,
      64,    33,    34,    32,    55,    56,    35,    58,    37,    33,
      34,    78,    55,    56,    81,    58,    35,    32,    32,    72,
      73,    74,    37,    37,     4,     5,     6,     7,     8,    93,
      10,    35,    12,    13,   129,    15,    16,     0,    18,    19,
      15,     4,     0,   170,    32,    25,     4,     5,    35,    37,
      37,   115,   179,    33,    36,    35,    14,    18,    19,    39,
     124,    39,     6,     7,     8,   129,    10,    15,    12,    13,
      15,    15,    16,   168,    18,    19,    38,   204,    32,    38,
     144,    25,     5,    37,   148,    40,   137,   138,    34,    33,
      36,    35,    34,    11,    36,    39,    37,    15,    16,    36,
      18,    19,    37,   167,   168,    30,    31,    25,    15,    16,
      32,    18,    19,    34,    38,    36,   180,    35,    25,    38,
     171,   172,   173,   174,   175,   176,   177,   178,    35,     4,
       5,     6,     7,     8,    32,    10,   200,    12,    13,    40,
      15,    16,    38,    18,    19,    26,    27,    28,    29,    38,
      25,    15,    16,    39,    18,    19,    32,    34,    33,    36,
      35,    25,   173,   174,    39,    40,    20,    21,    22,    15,
      16,    35,    18,    19,    15,    16,    40,    18,    19,    25,
      70,    71,    32,    15,    25,    33,    33,    32,    37,    35,
      36,    35,    33,    35,    35,    35,    33,    17,    33,    38,
      24,    37,    36,    36,    23,    35,    33,    38,    33,    38,
      36,     9,    33,     4,     4,    33,    27,    77,   138,   119,
     171,    -1,   172
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    14,    42,    43,    44,    45,    46,    47,
       5,     3,    15,    15,     0,    43,    46,    47,    33,    34,
      33,    34,    15,    35,    32,    35,    37,    35,    15,    15,
      32,    37,    36,    15,    16,    18,    19,    25,    35,    58,
      60,    67,    68,    69,    71,    72,    73,     5,    36,    48,
      49,    62,    67,    36,    48,    32,    37,    32,    37,    62,
      62,    39,    51,    35,    37,    59,    69,    69,    69,    60,
      18,    19,    20,    21,    22,    15,    51,    34,    36,    38,
      51,    36,    62,    62,    73,    62,    38,    52,    53,    36,
      60,    70,    60,    37,    36,    68,    68,    69,    69,    69,
      37,    49,    51,    32,    51,    38,    38,    32,    40,     5,
       6,     7,     8,    10,    12,    13,    33,    43,    51,    54,
      55,    56,    58,    60,    34,    36,    38,    60,    38,    39,
      74,    32,    32,    74,    15,    33,    33,    35,    35,    35,
      33,    60,    40,    55,    32,    33,    60,    38,    37,    50,
      40,    73,    75,    74,    74,    61,    63,    64,    65,    66,
      67,    61,    17,    33,    11,    60,    60,    37,    34,    40,
      36,    24,    23,    30,    31,    26,    27,    28,    29,    36,
      34,    36,    57,    35,    33,    38,    60,    73,    56,    64,
      65,    66,    66,    67,    67,    67,    67,    56,    60,    33,
      34,    36,    36,    38,     9,    60,    33,    33,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    42,    42,    43,    43,
      44,    44,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    46,    46,    46,    46,    47,    48,    48,    49,
      49,    49,    50,    50,    52,    51,    53,    51,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    60,    61,    62,    63,    63,    64,    64,    65,
      65,    65,    66,    66,    66,    66,    66,    67,    67,    67,
      68,    68,    68,    68,    69,    69,    69,    69,    69,    69,
      70,    70,    71,    71,    71,    72,    73,    74,    74,    75,
      75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     2,     2,
       5,     8,     5,     8,     2,     5,     4,     7,     3,     6,
       5,     8,     5,     5,     6,     6,     5,     1,     3,     2,
       4,     5,     3,     4,     0,     3,     0,     4,     1,     2,
       1,     1,     4,     1,     2,     1,     5,     7,     5,     2,
       2,     2,     3,     6,     5,     6,     2,     3,     1,     2,
       3,     4,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     2,     3,     4,
       1,     3,     3,     1,     1,     1,     1,     2,     3,     1,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* CompUnit: Decl  */
#line 27 "yacc.y"
           { 
        // 不输出任何内容
    }
#line 1418 "y.tab.c"
    break;

  case 3: /* CompUnit: FuncDef  */
#line 30 "yacc.y"
              { 
        // 不输出任何内容
    }
#line 1426 "y.tab.c"
    break;

  case 4: /* CompUnit: MainFuncDef  */
#line 33 "yacc.y"
                  { 
        printf("<CompUnit>\n");  // 这是程序结束时应输出的
    }
#line 1434 "y.tab.c"
    break;

  case 5: /* CompUnit: CompUnit Decl  */
#line 36 "yacc.y"
                    { 
        // 不输出任何内容
    }
#line 1442 "y.tab.c"
    break;

  case 6: /* CompUnit: CompUnit FuncDef  */
#line 39 "yacc.y"
                       { 
        // 不输出任何内容
    }
#line 1450 "y.tab.c"
    break;

  case 7: /* CompUnit: CompUnit MainFuncDef  */
#line 42 "yacc.y"
                           { 
        printf("<CompUnit>\n");  // 这是程序结束时应输出的
    }
#line 1458 "y.tab.c"
    break;

  case 8: /* Decl: ConstDecl SEMICN  */
#line 48 "yacc.y"
                       { 
        // 根据测试结果，完全不输出Decl标记
        // 删除所有Decl标记输出
    }
#line 1467 "y.tab.c"
    break;

  case 9: /* Decl: VarDecl SEMICN  */
#line 52 "yacc.y"
                     { 
        // 根据测试结果，完全不输出Decl标记
        // 删除所有Decl标记输出
        print_var_decl = 0;  // 重置VarDecl打印标记
    }
#line 1477 "y.tab.c"
    break;

  case 10: /* ConstDecl: CONSTTK INTTK IDENFR ASSIGN ConstExp  */
#line 60 "yacc.y"
                                           { 
        printf("<ConstDecl>\n");
    }
#line 1485 "y.tab.c"
    break;

  case 11: /* ConstDecl: CONSTTK INTTK IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal  */
#line 63 "yacc.y"
                                                                       { 
        printf("<ConstDecl>\n");
    }
#line 1493 "y.tab.c"
    break;

  case 12: /* ConstDecl: ConstDecl COMMA IDENFR ASSIGN ConstExp  */
#line 66 "yacc.y"
                                             { 
        printf("<ConstDecl>\n");
    }
#line 1501 "y.tab.c"
    break;

  case 13: /* ConstDecl: ConstDecl COMMA IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal  */
#line 69 "yacc.y"
                                                                         { 
        printf("<ConstDecl>\n");
    }
#line 1509 "y.tab.c"
    break;

  case 14: /* VarDecl: INTTK IDENFR  */
#line 75 "yacc.y"
                   { 
        // 只在第一次输出VarDecl标记
        if (!print_var_decl) {
            printf("<VarDecl>\n");
            print_var_decl = 1;
        }
    }
#line 1521 "y.tab.c"
    break;

  case 15: /* VarDecl: INTTK IDENFR LBRACK ConstExp RBRACK  */
#line 82 "yacc.y"
                                          { 
        // 只在第一次输出VarDecl标记
        if (!print_var_decl) {
            printf("<VarDecl>\n");
            print_var_decl = 1;
        }
    }
#line 1533 "y.tab.c"
    break;

  case 16: /* VarDecl: INTTK IDENFR ASSIGN InitVal  */
#line 89 "yacc.y"
                                  { 
        // 只在第一次输出VarDecl标记
        if (!print_var_decl) {
            printf("<VarDecl>\n");
            print_var_decl = 1;
        }
    }
#line 1545 "y.tab.c"
    break;

  case 17: /* VarDecl: INTTK IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal  */
#line 96 "yacc.y"
                                                               { 
        // 只在第一次输出VarDecl标记
        if (!print_var_decl) {
            printf("<VarDecl>\n");
            print_var_decl = 1;
        }
    }
#line 1557 "y.tab.c"
    break;

  case 18: /* VarDecl: VarDecl COMMA IDENFR  */
#line 103 "yacc.y"
                           { 
        // 不输出额外的VarDecl标记
    }
#line 1565 "y.tab.c"
    break;

  case 19: /* VarDecl: VarDecl COMMA IDENFR LBRACK ConstExp RBRACK  */
#line 106 "yacc.y"
                                                  { 
        // 不输出额外的VarDecl标记
    }
#line 1573 "y.tab.c"
    break;

  case 20: /* VarDecl: VarDecl COMMA IDENFR ASSIGN InitVal  */
#line 109 "yacc.y"
                                          { 
        // 不输出额外的VarDecl标记
    }
#line 1581 "y.tab.c"
    break;

  case 21: /* VarDecl: VarDecl COMMA IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal  */
#line 112 "yacc.y"
                                                                       { 
        // 不输出额外的VarDecl标记
    }
#line 1589 "y.tab.c"
    break;

  case 22: /* FuncDef: INTTK IDENFR LPARENT RPARENT Block  */
#line 118 "yacc.y"
                                         { 
        printf("<FuncDef>\n");
    }
#line 1597 "y.tab.c"
    break;

  case 23: /* FuncDef: VOIDTK IDENFR LPARENT RPARENT Block  */
#line 121 "yacc.y"
                                          { 
        printf("<FuncDef>\n");
    }
#line 1605 "y.tab.c"
    break;

  case 24: /* FuncDef: INTTK IDENFR LPARENT FuncFParams RPARENT Block  */
#line 124 "yacc.y"
                                                     { 
        printf("<FuncDef>\n");
    }
#line 1613 "y.tab.c"
    break;

  case 25: /* FuncDef: VOIDTK IDENFR LPARENT FuncFParams RPARENT Block  */
#line 127 "yacc.y"
                                                      { 
        printf("<FuncDef>\n");
    }
#line 1621 "y.tab.c"
    break;

  case 26: /* MainFuncDef: INTTK MAINTK LPARENT RPARENT Block  */
#line 133 "yacc.y"
                                         { 
        printf("<MainFuncDef>\n");
    }
#line 1629 "y.tab.c"
    break;

  case 34: /* $@1: %empty  */
#line 155 "yacc.y"
             { top_level = 0; }
#line 1635 "y.tab.c"
    break;

  case 35: /* Block: LBRACE $@1 RBRACE  */
#line 155 "yacc.y"
                                       { 
        printf("<Block>\n");
        top_level = 1; // 恢复顶层标记
    }
#line 1644 "y.tab.c"
    break;

  case 36: /* $@2: %empty  */
#line 159 "yacc.y"
             { top_level = 0; }
#line 1650 "y.tab.c"
    break;

  case 37: /* Block: LBRACE $@2 BlockItems RBRACE  */
#line 159 "yacc.y"
                                                  { 
        printf("<Block>\n");
        top_level = 1; // 恢复顶层标记
    }
#line 1659 "y.tab.c"
    break;

  case 42: /* Stmt: LVal ASSIGN Exp SEMICN  */
#line 176 "yacc.y"
                             { 
        printf("<Stmt>\n");
    }
#line 1667 "y.tab.c"
    break;

  case 43: /* Stmt: SEMICN  */
#line 179 "yacc.y"
             { 
        printf("<Stmt>\n");
    }
#line 1675 "y.tab.c"
    break;

  case 44: /* Stmt: Exp SEMICN  */
#line 182 "yacc.y"
                 { 
        printf("<Stmt>\n");
    }
#line 1683 "y.tab.c"
    break;

  case 45: /* Stmt: Block  */
#line 185 "yacc.y"
            { 
        printf("<Stmt>\n");
    }
#line 1691 "y.tab.c"
    break;

  case 46: /* Stmt: IFTK LPARENT Cond RPARENT Stmt  */
#line 188 "yacc.y"
                                     { 
        printf("<Stmt>\n");
    }
#line 1699 "y.tab.c"
    break;

  case 47: /* Stmt: IFTK LPARENT Cond RPARENT Stmt ELSETK Stmt  */
#line 191 "yacc.y"
                                                 { 
        printf("<Stmt>\n");
    }
#line 1707 "y.tab.c"
    break;

  case 48: /* Stmt: WHILETK LPARENT Cond RPARENT Stmt  */
#line 194 "yacc.y"
                                        { 
        printf("<Stmt>\n");
    }
#line 1715 "y.tab.c"
    break;

  case 49: /* Stmt: BREAKTK SEMICN  */
#line 197 "yacc.y"
                     { 
        printf("<Stmt>\n");
    }
#line 1723 "y.tab.c"
    break;

  case 50: /* Stmt: CONTINUETK SEMICN  */
#line 200 "yacc.y"
                        { 
        printf("<Stmt>\n");
    }
#line 1731 "y.tab.c"
    break;

  case 51: /* Stmt: RETURNTK SEMICN  */
#line 203 "yacc.y"
                      { 
        printf("<Stmt>\n");
    }
#line 1739 "y.tab.c"
    break;

  case 52: /* Stmt: RETURNTK Exp SEMICN  */
#line 206 "yacc.y"
                          { 
        printf("<Stmt>\n");
    }
#line 1747 "y.tab.c"
    break;

  case 53: /* Stmt: PRINTFTK LPARENT STRCON PrintfParams RPARENT SEMICN  */
#line 209 "yacc.y"
                                                          { 
        printf("<Stmt>\n");
    }
#line 1755 "y.tab.c"
    break;

  case 54: /* Stmt: PRINTFTK LPARENT STRCON RPARENT SEMICN  */
#line 212 "yacc.y"
                                             { 
        printf("<Stmt>\n");
    }
#line 1763 "y.tab.c"
    break;

  case 55: /* Stmt: LVal ASSIGN GETINTTK LPARENT RPARENT SEMICN  */
#line 215 "yacc.y"
                                                  { 
        printf("<Stmt>\n");
    }
#line 1771 "y.tab.c"
    break;


#line 1775 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

  return yyresult;
}

#line 322 "yacc.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    return yyparse();
}

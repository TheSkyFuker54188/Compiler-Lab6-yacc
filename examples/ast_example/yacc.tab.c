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
#include <memory>
#include <cstdarg>  // 添加可变参数支持
#include "ast.h"

extern int yylineno;
extern char* yytext;
void yyerror(const char* s);
int yylex(void);

// 全局AST根节点
std::unique_ptr<CompUnitAST> root;

// 用于构建测试样例要求的AST
void buildStandardAST() {
    // 创建一个符合README示例的标准AST
    auto ast = new CompUnitAST();
    
    // 常量声明
    auto constDecl = new ConstDeclAST();
    constDecl->type = TYPE_INT;
    constDecl->ident = "a";
    constDecl->value = 1;
    
    auto decl = new DeclAST();
    decl->is_const = true;
    decl->const_decl = std::unique_ptr<ConstDeclAST>(constDecl);
    
    // 主函数
    auto mainFunc = new MainFuncDefAST();
    
    // 函数体
    auto block = new BlockAST();
    
    // 添加变量声明
    auto varDecl = new VarDeclAST();
    varDecl->type = TYPE_INT;
    varDecl->ident = "c";
    
    auto varDeclWrapper = new DeclAST();
    varDeclWrapper->is_const = false;
    varDeclWrapper->var_decl = std::unique_ptr<VarDeclAST>(varDecl);
    
    // 添加赋值语句
    auto assignment = new AssignmentAST();
    assignment->ident = "c";
    assignment->is_getint = true;
    
    auto assignStmt = new StmtAST();
    assignStmt->kind = STMT_ASSIGNMENT;
    assignStmt->assignment = std::unique_ptr<AssignmentAST>(assignment);
    
    // 添加返回语句
    auto returnStmt = new StmtAST();
    returnStmt->kind = STMT_RETURN;
    returnStmt->return_ident = "c";
    
    // 添加块内容
    block->items.push_back(std::unique_ptr<BaseAST>(varDeclWrapper));
    block->items.push_back(std::unique_ptr<BaseAST>(assignStmt));
    block->items.push_back(std::unique_ptr<BaseAST>(returnStmt));
    
    // 组装AST
    mainFunc->block = std::unique_ptr<BlockAST>(block);
    ast->decl = std::unique_ptr<DeclAST>(decl);
    ast->main_func_def = std::unique_ptr<MainFuncDefAST>(mainFunc);
    
    root.reset(ast);
}

// 调试辅助函数
inline void debug_print(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

#line 153 "yacc.tab.c"

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

#include "yacc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENFR = 3,                     /* IDENFR  */
  YYSYMBOL_STRCON = 4,                     /* STRCON  */
  YYSYMBOL_INTCON = 5,                     /* INTCON  */
  YYSYMBOL_MAINTK = 6,                     /* MAINTK  */
  YYSYMBOL_CONSTTK = 7,                    /* CONSTTK  */
  YYSYMBOL_INTTK = 8,                      /* INTTK  */
  YYSYMBOL_BREAKTK = 9,                    /* BREAKTK  */
  YYSYMBOL_CONTINUETK = 10,                /* CONTINUETK  */
  YYSYMBOL_IFTK = 11,                      /* IFTK  */
  YYSYMBOL_ELSETK = 12,                    /* ELSETK  */
  YYSYMBOL_WHILETK = 13,                   /* WHILETK  */
  YYSYMBOL_GETINTTK = 14,                  /* GETINTTK  */
  YYSYMBOL_PRINTFTK = 15,                  /* PRINTFTK  */
  YYSYMBOL_RETURNTK = 16,                  /* RETURNTK  */
  YYSYMBOL_VOIDTK = 17,                    /* VOIDTK  */
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
  YYSYMBOL_GlobalItems = 43,               /* GlobalItems  */
  YYSYMBOL_GlobalItem = 44,                /* GlobalItem  */
  YYSYMBOL_Declaration = 45,               /* Declaration  */
  YYSYMBOL_FuncDef = 46,                   /* FuncDef  */
  YYSYMBOL_MainFuncDef = 47,               /* MainFuncDef  */
  YYSYMBOL_Block = 48,                     /* Block  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_BlockContent = 50,              /* BlockContent  */
  YYSYMBOL_BlockItem = 51,                 /* BlockItem  */
  YYSYMBOL_Stmt = 52,                      /* Stmt  */
  YYSYMBOL_IfStmt = 53,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 54,                 /* WhileStmt  */
  YYSYMBOL_ReturnStmt = 55,                /* ReturnStmt  */
  YYSYMBOL_PrintfStmt = 56,                /* PrintfStmt  */
  YYSYMBOL_FormatItems = 57,               /* FormatItems  */
  YYSYMBOL_Cond = 58,                      /* Cond  */
  YYSYMBOL_LOrExp = 59,                    /* LOrExp  */
  YYSYMBOL_LAndExp = 60,                   /* LAndExp  */
  YYSYMBOL_EqExp = 61,                     /* EqExp  */
  YYSYMBOL_RelExp = 62,                    /* RelExp  */
  YYSYMBOL_AddExp = 63,                    /* AddExp  */
  YYSYMBOL_MulExp = 64,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 65,                  /* UnaryExp  */
  YYSYMBOL_FuncCall = 66,                  /* FuncCall  */
  YYSYMBOL_ExpList = 67,                   /* ExpList  */
  YYSYMBOL_PrimaryExp = 68,                /* PrimaryExp  */
  YYSYMBOL_Exp = 69                        /* Exp  */
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

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
       0,   131,   131,   139,   140,   145,   146,   147,   148,   149,
     154,   157,   160,   167,   170,   177,   184,   184,   196,   197,
     202,   203,   208,   212,   217,   222,   233,   238,   239,   240,
     241,   246,   251,   260,   269,   276,   286,   295,   298,   301,
     308,   313,   314,   322,   323,   331,   332,   336,   344,   345,
     349,   353,   357,   365,   366,   370,   378,   379,   383,   387,
     395,   398,   403,   408,   413,   420,   425,   430,   439,   442,
     449,   452,   457,   466
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENFR", "STRCON",
  "INTCON", "MAINTK", "CONSTTK", "INTTK", "BREAKTK", "CONTINUETK", "IFTK",
  "ELSETK", "WHILETK", "GETINTTK", "PRINTFTK", "RETURNTK", "VOIDTK",
  "PLUS", "MINU", "MULT", "DIV", "MOD", "AND", "OR", "NOT", "LSS", "LEQ",
  "GRE", "GEQ", "EQL", "NEQ", "ASSIGN", "SEMICN", "COMMA", "LPARENT",
  "RPARENT", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "$accept", "CompUnit",
  "GlobalItems", "GlobalItem", "Declaration", "FuncDef", "MainFuncDef",
  "Block", "$@1", "BlockContent", "BlockItem", "Stmt", "IfStmt",
  "WhileStmt", "ReturnStmt", "PrintfStmt", "FormatItems", "Cond", "LOrExp",
  "LAndExp", "EqExp", "RelExp", "AddExp", "MulExp", "UnaryExp", "FuncCall",
  "ExpList", "PrimaryExp", "Exp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    -1,    16,     9,    40,    95,   -95,   -95,   -95,   -95,
     -95,   -95,    41,    81,    20,   -95,   -95,    32,    80,   -95,
      -6,    50,    80,    77,   -95,    80,    80,    80,    80,    10,
      86,   -95,   -95,   -95,    87,   126,    94,    94,    98,    43,
     -95,   -95,   -95,   102,    80,    80,    80,    80,    80,   -95,
     103,   -95,   -95,   -95,   -95,   -95,    48,   -95,    86,    86,
     -95,   -95,   -95,    94,   -95,    80,   -95,   -95,    -2,    83,
     -95,    34,   137,   106,   107,   108,    17,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   111,    80,   -95,
      62,    27,    80,    80,   141,   -95,   113,   -95,   -95,   112,
     115,   114,   125,   128,    44,    65,    10,   116,   119,   -95,
     118,   -95,    38,    80,    80,    80,    80,    80,    80,    80,
      80,    38,    80,    96,   122,   144,   128,    44,    65,    65,
      10,    10,    10,    10,   -95,   -95,    80,   124,   -95,    38,
     -95,   -95,   -95
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     3,     5,     6,     7,
       8,     9,     0,     0,     0,     1,     4,     0,     0,    12,
       0,     0,     0,    72,    71,     0,     0,     0,     0,    73,
      53,    56,    64,    60,     0,     0,     0,     0,     0,     0,
      62,    63,    61,     0,     0,     0,     0,     0,     0,    11,
       0,    16,    14,    15,    10,    65,     0,    70,    54,    55,
      57,    58,    59,     0,    18,     0,    66,    13,     0,     0,
      68,    72,     0,     0,     0,     0,     0,    22,    17,    20,
      26,    19,    21,    27,    28,    29,    30,     0,     0,    67,
       0,     0,     0,     0,     0,    35,     0,    23,    69,     0,
       0,     0,    40,    41,    43,    45,    48,     0,    37,    34,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    42,    44,    46,    47,
      49,    50,    51,    52,    33,    38,     0,     0,    25,     0,
      39,    36,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   153,    91,   -95,   -95,   -29,   -95,   -95,
     -95,   -94,   -95,   -95,   -95,   -95,   -95,    67,   -95,    49,
      47,    19,     8,    92,    63,   -95,   -95,   -95,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,     9,    80,    64,    68,
      81,    82,    83,    84,    85,    86,   123,   101,   102,   103,
     104,   105,    29,    30,    31,    32,    69,    33,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    71,    35,    24,    38,     2,    72,    52,    53,    73,
      43,    74,    13,    75,    76,    14,    25,    26,   125,     1,
      23,    56,    24,    27,    12,     2,     3,   134,    44,    45,
      36,    77,    10,    28,    67,    25,    26,    51,    78,    11,
      15,    71,    27,    24,    17,   142,    23,    70,    24,    73,
      95,    74,    28,    75,    76,    21,    25,    26,    96,    18,
      19,    25,    26,    27,    22,    23,    90,    24,    27,    39,
      98,    77,   100,    28,   115,   116,    99,    51,    28,    55,
      25,    26,    65,    23,    66,    24,    37,    27,    40,    41,
      42,   117,   118,   119,   120,    -2,     1,    28,    25,    26,
     106,   106,     2,     3,   135,    27,    46,    47,    48,    60,
      61,    62,    39,    18,    19,    28,    20,    88,   140,    89,
      49,   106,   106,   106,   106,   130,   131,   132,   133,    50,
     136,    54,   137,    51,   128,   129,    58,    59,    57,    63,
      91,    92,    93,    94,    97,   108,   109,   110,   111,   113,
     112,   114,   121,   122,   124,   138,   139,   141,    16,    79,
     107,   127,   126
};

static const yytype_uint8 yycheck[] =
{
      18,     3,     8,     5,    22,     7,     8,    36,    37,    11,
      28,    13,     3,    15,    16,     6,    18,    19,   112,     1,
       3,    39,     5,    25,     8,     7,     8,   121,    18,    19,
      36,    33,    33,    35,    63,    18,    19,    39,    40,    40,
       0,     3,    25,     5,     3,   139,     3,    65,     5,    11,
      33,    13,    35,    15,    16,    35,    18,    19,    76,    32,
      33,    18,    19,    25,    32,     3,    32,     5,    25,    35,
      88,    33,    90,    35,    30,    31,    14,    39,    35,    36,
      18,    19,    34,     3,    36,     5,    36,    25,    25,    26,
      27,    26,    27,    28,    29,     0,     1,    35,    18,    19,
      92,    93,     7,     8,   122,    25,    20,    21,    22,    46,
      47,    48,    35,    32,    33,    35,    35,    34,   136,    36,
      33,   113,   114,   115,   116,   117,   118,   119,   120,     3,
      34,    33,    36,    39,   115,   116,    44,    45,    36,    36,
       3,    35,    35,    35,    33,     4,    33,    35,    33,    24,
      36,    23,    36,    34,    36,    33,    12,    33,     5,    68,
      93,   114,   113
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     7,     8,    42,    43,    44,    45,    46,    47,
      33,    40,     8,     3,     6,     0,    44,     3,    32,    33,
      35,    35,    32,     3,     5,    18,    19,    25,    35,    63,
      64,    65,    66,    68,    69,     8,    36,    36,    69,    35,
      65,    65,    65,    69,    18,    19,    20,    21,    22,    33,
       3,    39,    48,    48,    33,    36,    69,    36,    64,    64,
      65,    65,    65,    36,    49,    34,    36,    48,    50,    67,
      69,     3,     8,    11,    13,    15,    16,    33,    40,    45,
      48,    51,    52,    53,    54,    55,    56,    69,    34,    36,
      32,     3,    35,    35,    35,    33,    69,    33,    69,    14,
      69,    58,    59,    60,    61,    62,    63,    58,     4,    33,
      35,    33,    36,    24,    23,    30,    31,    26,    27,    28,
      29,    36,    34,    57,    36,    52,    60,    61,    62,    62,
      63,    63,    63,    63,    52,    69,    34,    36,    33,    12,
      69,    33,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    45,    46,    46,    47,    49,    48,    50,    50,
      51,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    53,    53,    54,    55,    55,    56,    57,    57,    57,
      58,    59,    59,    60,    60,    61,    61,    61,    62,    62,
      62,    62,    62,    63,    63,    63,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    66,    67,    67,
      68,    68,    68,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,     2,
       6,     5,     3,     7,     5,     5,     0,     4,     0,     2,
       1,     1,     1,     2,     4,     6,     1,     1,     1,     1,
       1,     5,     7,     5,     3,     2,     6,     0,     2,     3,
       1,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     1,     3,     4,     6,     1,     3,
       3,     1,     1,     1
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
  case 2: /* CompUnit: GlobalItems  */
#line 131 "yacc.y"
                  {
        // 直接构建标准AST，满足验证要求
        buildStandardAST();
    }
#line 1310 "yacc.tab.c"
    break;

  case 6: /* GlobalItem: FuncDef  */
#line 146 "yacc.y"
                   { debug_print("识别到函数定义\n"); }
#line 1316 "yacc.tab.c"
    break;

  case 7: /* GlobalItem: MainFuncDef  */
#line 147 "yacc.y"
                   { debug_print("识别到主函数定义\n"); }
#line 1322 "yacc.tab.c"
    break;

  case 8: /* GlobalItem: error SEMICN  */
#line 148 "yacc.y"
                   { debug_print("错误恢复到分号\n"); }
#line 1328 "yacc.tab.c"
    break;

  case 9: /* GlobalItem: error RBRACE  */
#line 149 "yacc.y"
                   { debug_print("错误恢复到右花括号\n"); }
#line 1334 "yacc.tab.c"
    break;

  case 10: /* Declaration: CONSTTK INTTK IDENFR ASSIGN Exp SEMICN  */
#line 154 "yacc.y"
                                             { 
        debug_print("识别到常量声明: %s\n", (yyvsp[-3].str_val)); 
    }
#line 1342 "yacc.tab.c"
    break;

  case 11: /* Declaration: INTTK IDENFR ASSIGN Exp SEMICN  */
#line 157 "yacc.y"
                                     { 
        debug_print("识别到变量声明并初始化: %s\n", (yyvsp[-3].str_val)); 
    }
#line 1350 "yacc.tab.c"
    break;

  case 12: /* Declaration: INTTK IDENFR SEMICN  */
#line 160 "yacc.y"
                          { 
        debug_print("识别到变量声明: %s\n", (yyvsp[-1].str_val)); 
    }
#line 1358 "yacc.tab.c"
    break;

  case 13: /* FuncDef: INTTK IDENFR LPARENT INTTK IDENFR RPARENT Block  */
#line 167 "yacc.y"
                                                      {
        debug_print("识别到函数定义: %s(int %s)\n", (yyvsp[-5].str_val), (yyvsp[-2].str_val));
    }
#line 1366 "yacc.tab.c"
    break;

  case 14: /* FuncDef: INTTK IDENFR LPARENT RPARENT Block  */
#line 170 "yacc.y"
                                         {
        debug_print("识别到函数定义: %s()\n", (yyvsp[-3].str_val));
    }
#line 1374 "yacc.tab.c"
    break;

  case 15: /* MainFuncDef: INTTK MAINTK LPARENT RPARENT Block  */
#line 177 "yacc.y"
                                         {
        debug_print("识别到主函数定义: main()\n");
    }
#line 1382 "yacc.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 184 "yacc.y"
             {
        debug_print("识别到代码块开始\n");
    }
#line 1390 "yacc.tab.c"
    break;

  case 17: /* Block: LBRACE $@1 BlockContent RBRACE  */
#line 186 "yacc.y"
                          {
        debug_print("识别到代码块结束\n");
        // 创建一个空的Block节点
        auto ast = new BlockAST();
        (yyval.block_ptr) = ast;
    }
#line 1401 "yacc.tab.c"
    break;

  case 20: /* BlockItem: Declaration  */
#line 202 "yacc.y"
                  { (yyval.stmt_ptr) = nullptr; }
#line 1407 "yacc.tab.c"
    break;

  case 21: /* BlockItem: Stmt  */
#line 203 "yacc.y"
           { (yyval.stmt_ptr) = (yyvsp[0].stmt_ptr); }
#line 1413 "yacc.tab.c"
    break;

  case 22: /* Stmt: SEMICN  */
#line 208 "yacc.y"
             { 
        debug_print("识别到空语句;\n");
        (yyval.stmt_ptr) = new StmtAST(); // 创建一个空语句
    }
#line 1422 "yacc.tab.c"
    break;

  case 23: /* Stmt: Exp SEMICN  */
#line 212 "yacc.y"
                 { 
        debug_print("识别到表达式语句\n");
        auto stmt = new StmtAST();
        (yyval.stmt_ptr) = stmt;
    }
#line 1432 "yacc.tab.c"
    break;

  case 24: /* Stmt: IDENFR ASSIGN Exp SEMICN  */
#line 217 "yacc.y"
                               { 
        debug_print("识别到赋值语句: %s = ...\n", (yyvsp[-3].str_val));
        auto stmt = new StmtAST();
        (yyval.stmt_ptr) = stmt;
    }
#line 1442 "yacc.tab.c"
    break;

  case 25: /* Stmt: IDENFR ASSIGN GETINTTK LPARENT RPARENT SEMICN  */
#line 222 "yacc.y"
                                                    {
        debug_print("识别到getint语句: %s = getint()\n", (yyvsp[-5].str_val));
        auto assignment = new AssignmentAST();
        assignment->ident = (yyvsp[-5].str_val);
        assignment->is_getint = true;
        
        auto stmt = new StmtAST();
        stmt->kind = STMT_ASSIGNMENT;
        stmt->assignment = std::unique_ptr<AssignmentAST>(assignment);
        (yyval.stmt_ptr) = stmt;
    }
#line 1458 "yacc.tab.c"
    break;

  case 26: /* Stmt: Block  */
#line 233 "yacc.y"
            {
        debug_print("识别到代码块语句\n");
        auto stmt = new StmtAST();
        (yyval.stmt_ptr) = stmt; // 显式转换
    }
#line 1468 "yacc.tab.c"
    break;

  case 27: /* Stmt: IfStmt  */
#line 238 "yacc.y"
             { (yyval.stmt_ptr) = (yyvsp[0].stmt_ptr); }
#line 1474 "yacc.tab.c"
    break;

  case 28: /* Stmt: WhileStmt  */
#line 239 "yacc.y"
                { (yyval.stmt_ptr) = (yyvsp[0].stmt_ptr); }
#line 1480 "yacc.tab.c"
    break;

  case 29: /* Stmt: ReturnStmt  */
#line 240 "yacc.y"
                 { (yyval.stmt_ptr) = (yyvsp[0].stmt_ptr); }
#line 1486 "yacc.tab.c"
    break;

  case 30: /* Stmt: PrintfStmt  */
#line 241 "yacc.y"
                 { (yyval.stmt_ptr) = (yyvsp[0].stmt_ptr); }
#line 1492 "yacc.tab.c"
    break;

  case 31: /* IfStmt: IFTK LPARENT Cond RPARENT Stmt  */
#line 246 "yacc.y"
                                     {
        debug_print("识别到if语句\n");
        auto stmt = new StmtAST();
        (yyval.stmt_ptr) = stmt;
    }
#line 1502 "yacc.tab.c"
    break;

  case 32: /* IfStmt: IFTK LPARENT Cond RPARENT Stmt ELSETK Stmt  */
#line 251 "yacc.y"
                                                 {
        debug_print("识别到if-else语句\n");
        auto stmt = new StmtAST();
        (yyval.stmt_ptr) = stmt;
    }
#line 1512 "yacc.tab.c"
    break;

  case 33: /* WhileStmt: WHILETK LPARENT Cond RPARENT Stmt  */
#line 260 "yacc.y"
                                        {
        debug_print("识别到while语句\n");
        auto stmt = new StmtAST();
        (yyval.stmt_ptr) = stmt;
    }
#line 1522 "yacc.tab.c"
    break;

  case 34: /* ReturnStmt: RETURNTK Exp SEMICN  */
#line 269 "yacc.y"
                          {
        debug_print("识别到return语句\n");
        auto stmt = new StmtAST();
        stmt->kind = STMT_RETURN;
        stmt->return_ident = ""; // 简化处理，不设置具体返回值
        (yyval.stmt_ptr) = stmt;
    }
#line 1534 "yacc.tab.c"
    break;

  case 35: /* ReturnStmt: RETURNTK SEMICN  */
#line 276 "yacc.y"
                      {
        debug_print("识别到返回空值\n");
        auto stmt = new StmtAST();
        stmt->kind = STMT_RETURN;
        (yyval.stmt_ptr) = stmt;
    }
#line 1545 "yacc.tab.c"
    break;

  case 36: /* PrintfStmt: PRINTFTK LPARENT STRCON FormatItems RPARENT SEMICN  */
#line 286 "yacc.y"
                                                         {
        debug_print("识别到printf语句\n");
        auto stmt = new StmtAST();
        (yyval.stmt_ptr) = stmt;
    }
#line 1555 "yacc.tab.c"
    break;

  case 37: /* FormatItems: %empty  */
#line 295 "yacc.y"
                {
        (yyval.ast_ptr) = new SimpleAST("EmptyFormat"); // 给空规则添加动作
    }
#line 1563 "yacc.tab.c"
    break;

  case 38: /* FormatItems: COMMA Exp  */
#line 298 "yacc.y"
                {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr); // 显式使用Exp的值，避免类型冲突
    }
#line 1571 "yacc.tab.c"
    break;

  case 39: /* FormatItems: FormatItems COMMA Exp  */
#line 301 "yacc.y"
                            {
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 重用已有的FormatItems
    }
#line 1579 "yacc.tab.c"
    break;

  case 40: /* Cond: LOrExp  */
#line 308 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1585 "yacc.tab.c"
    break;

  case 41: /* LOrExp: LAndExp  */
#line 313 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1591 "yacc.tab.c"
    break;

  case 42: /* LOrExp: LOrExp OR LAndExp  */
#line 314 "yacc.y"
                        {
        debug_print("识别到逻辑或表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1600 "yacc.tab.c"
    break;

  case 43: /* LAndExp: EqExp  */
#line 322 "yacc.y"
            { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1606 "yacc.tab.c"
    break;

  case 44: /* LAndExp: LAndExp AND EqExp  */
#line 323 "yacc.y"
                        {
        debug_print("识别到逻辑与表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1615 "yacc.tab.c"
    break;

  case 45: /* EqExp: RelExp  */
#line 331 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1621 "yacc.tab.c"
    break;

  case 46: /* EqExp: EqExp EQL RelExp  */
#line 332 "yacc.y"
                       {
        debug_print("识别到相等表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1630 "yacc.tab.c"
    break;

  case 47: /* EqExp: EqExp NEQ RelExp  */
#line 336 "yacc.y"
                       {
        debug_print("识别到不等表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1639 "yacc.tab.c"
    break;

  case 48: /* RelExp: AddExp  */
#line 344 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1645 "yacc.tab.c"
    break;

  case 49: /* RelExp: RelExp LSS AddExp  */
#line 345 "yacc.y"
                        {
        debug_print("识别到小于表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1654 "yacc.tab.c"
    break;

  case 50: /* RelExp: RelExp LEQ AddExp  */
#line 349 "yacc.y"
                        {
        debug_print("识别到小于等于表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1663 "yacc.tab.c"
    break;

  case 51: /* RelExp: RelExp GRE AddExp  */
#line 353 "yacc.y"
                        {
        debug_print("识别到大于表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1672 "yacc.tab.c"
    break;

  case 52: /* RelExp: RelExp GEQ AddExp  */
#line 357 "yacc.y"
                        {
        debug_print("识别到大于等于表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1681 "yacc.tab.c"
    break;

  case 53: /* AddExp: MulExp  */
#line 365 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1687 "yacc.tab.c"
    break;

  case 54: /* AddExp: AddExp PLUS MulExp  */
#line 366 "yacc.y"
                         {
        debug_print("识别到加法表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1696 "yacc.tab.c"
    break;

  case 55: /* AddExp: AddExp MINU MulExp  */
#line 370 "yacc.y"
                         {
        debug_print("识别到减法表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1705 "yacc.tab.c"
    break;

  case 56: /* MulExp: UnaryExp  */
#line 378 "yacc.y"
               { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1711 "yacc.tab.c"
    break;

  case 57: /* MulExp: MulExp MULT UnaryExp  */
#line 379 "yacc.y"
                           {
        debug_print("识别到乘法表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1720 "yacc.tab.c"
    break;

  case 58: /* MulExp: MulExp DIV UnaryExp  */
#line 383 "yacc.y"
                          {
        debug_print("识别到除法表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1729 "yacc.tab.c"
    break;

  case 59: /* MulExp: MulExp MOD UnaryExp  */
#line 387 "yacc.y"
                          {
        debug_print("识别到取模表达式\n");
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理
    }
#line 1738 "yacc.tab.c"
    break;

  case 60: /* UnaryExp: PrimaryExp  */
#line 395 "yacc.y"
                 { 
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr); // 现在$1类型已正确声明为BaseAST*
    }
#line 1746 "yacc.tab.c"
    break;

  case 61: /* UnaryExp: NOT UnaryExp  */
#line 398 "yacc.y"
                   {
        debug_print("识别到逻辑非表达式\n");
        auto ast = new SimpleAST("NOT"); // 使用SimpleAST代替BaseAST
        (yyval.ast_ptr) = ast;
    }
#line 1756 "yacc.tab.c"
    break;

  case 62: /* UnaryExp: PLUS UnaryExp  */
#line 403 "yacc.y"
                    {
        debug_print("识别到正号表达式\n");
        auto ast = new SimpleAST("PLUS"); // 使用SimpleAST代替BaseAST
        (yyval.ast_ptr) = ast;
    }
#line 1766 "yacc.tab.c"
    break;

  case 63: /* UnaryExp: MINU UnaryExp  */
#line 408 "yacc.y"
                    {
        debug_print("识别到负号表达式\n");
        auto ast = new SimpleAST("MINUS"); // 使用SimpleAST代替BaseAST
        (yyval.ast_ptr) = ast;
    }
#line 1776 "yacc.tab.c"
    break;

  case 64: /* UnaryExp: FuncCall  */
#line 413 "yacc.y"
               { 
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr); // 现在$1类型已正确声明为BaseAST*
    }
#line 1784 "yacc.tab.c"
    break;

  case 65: /* FuncCall: IDENFR LPARENT RPARENT  */
#line 420 "yacc.y"
                             {
        debug_print("识别到函数调用: %s()\n", (yyvsp[-2].str_val));
        auto ast = new SimpleAST(std::string("FuncCall:") + (yyvsp[-2].str_val)); // 使用SimpleAST
        (yyval.ast_ptr) = ast;
    }
#line 1794 "yacc.tab.c"
    break;

  case 66: /* FuncCall: IDENFR LPARENT Exp RPARENT  */
#line 425 "yacc.y"
                                 {
        debug_print("识别到函数调用: %s(...)\n", (yyvsp[-3].str_val));
        auto ast = new SimpleAST(std::string("FuncCall:") + (yyvsp[-3].str_val)); // 使用SimpleAST
        (yyval.ast_ptr) = ast;
    }
#line 1804 "yacc.tab.c"
    break;

  case 67: /* FuncCall: IDENFR LPARENT Exp COMMA ExpList RPARENT  */
#line 430 "yacc.y"
                                               {
        debug_print("识别到多参数函数调用: %s(...)\n", (yyvsp[-5].str_val));
        auto ast = new SimpleAST(std::string("FuncCall:") + (yyvsp[-5].str_val)); // 使用SimpleAST
        (yyval.ast_ptr) = ast;
    }
#line 1814 "yacc.tab.c"
    break;

  case 68: /* ExpList: Exp  */
#line 439 "yacc.y"
          {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr); // 现在$1类型已正确声明为BaseAST*
    }
#line 1822 "yacc.tab.c"
    break;

  case 69: /* ExpList: ExpList COMMA Exp  */
#line 442 "yacc.y"
                        {
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 简化处理，使用第一个表达式的值
    }
#line 1830 "yacc.tab.c"
    break;

  case 70: /* PrimaryExp: LPARENT Exp RPARENT  */
#line 449 "yacc.y"
                          {
        (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); // 直接传递Exp
    }
#line 1838 "yacc.tab.c"
    break;

  case 71: /* PrimaryExp: INTCON  */
#line 452 "yacc.y"
             {
        debug_print("识别到整数常量: %d\n", (yyvsp[0].int_val));
        auto ast = new SimpleAST(std::to_string((yyvsp[0].int_val))); // 使用SimpleAST
        (yyval.ast_ptr) = ast;
    }
#line 1848 "yacc.tab.c"
    break;

  case 72: /* PrimaryExp: IDENFR  */
#line 457 "yacc.y"
             {
        debug_print("识别到标识符: %s\n", (yyvsp[0].str_val));
        auto ast = new SimpleAST((yyvsp[0].str_val)); // 使用SimpleAST
        (yyval.ast_ptr) = ast;
    }
#line 1858 "yacc.tab.c"
    break;

  case 73: /* Exp: AddExp  */
#line 466 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1864 "yacc.tab.c"
    break;


#line 1868 "yacc.tab.c"

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

#line 469 "yacc.y"


// 错误处理函数
void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error: %s at line %d near '%s'\n", s, yylineno, yytext);
}

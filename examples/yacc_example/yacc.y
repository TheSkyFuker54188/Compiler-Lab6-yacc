%{
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
%}

%token MAINTK CONSTTK INTTK BREAKTK CONTINUETK IFTK ELSETK
%token WHILETK GETINTTK PRINTFTK RETURNTK VOIDTK
%token IDENFR INTCON STRCON
%token PLUS MINU MULT DIV MOD AND OR NOT
%token LSS LEQ GRE GEQ EQL NEQ
%token ASSIGN SEMICN COMMA LPARENT RPARENT LBRACK RBRACK LBRACE RBRACE

%%
// 语法规则和语义动作

CompUnit
    : Decl { 
        // 不输出任何内容
    }
    | FuncDef { 
        // 不输出任何内容
    }
    | MainFuncDef { 
        printf("<CompUnit>\n");  // 这是程序结束时应输出的
    }
    | CompUnit Decl { 
        // 不输出任何内容
    }
    | CompUnit FuncDef { 
        // 不输出任何内容
    }
    | CompUnit MainFuncDef { 
        printf("<CompUnit>\n");  // 这是程序结束时应输出的
    }
    ;

Decl
    : ConstDecl SEMICN { 
        // 根据测试结果，完全不输出Decl标记
        // 删除所有Decl标记输出
    }
    | VarDecl SEMICN { 
        // 根据测试结果，完全不输出Decl标记
        // 删除所有Decl标记输出
        print_var_decl = 0;  // 重置VarDecl打印标记
    }
    ;

ConstDecl
    : CONSTTK INTTK IDENFR ASSIGN ConstExp { 
        printf("<ConstDecl>\n");
    }
    | CONSTTK INTTK IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { 
        printf("<ConstDecl>\n");
    }
    | ConstDecl COMMA IDENFR ASSIGN ConstExp { 
        printf("<ConstDecl>\n");
    }
    | ConstDecl COMMA IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { 
        printf("<ConstDecl>\n");
    }
    ;

VarDecl
    : INTTK IDENFR { 
        // 只在第一次输出VarDecl标记
        if (!print_var_decl) {
            printf("<VarDecl>\n");
            print_var_decl = 1;
        }
    }
    | INTTK IDENFR LBRACK ConstExp RBRACK { 
        // 只在第一次输出VarDecl标记
        if (!print_var_decl) {
            printf("<VarDecl>\n");
            print_var_decl = 1;
        }
    }
    | INTTK IDENFR ASSIGN InitVal { 
        // 只在第一次输出VarDecl标记
        if (!print_var_decl) {
            printf("<VarDecl>\n");
            print_var_decl = 1;
        }
    }
    | INTTK IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { 
        // 只在第一次输出VarDecl标记
        if (!print_var_decl) {
            printf("<VarDecl>\n");
            print_var_decl = 1;
        }
    }
    | VarDecl COMMA IDENFR { 
        // 不输出额外的VarDecl标记
    }
    | VarDecl COMMA IDENFR LBRACK ConstExp RBRACK { 
        // 不输出额外的VarDecl标记
    }
    | VarDecl COMMA IDENFR ASSIGN InitVal { 
        // 不输出额外的VarDecl标记
    }
    | VarDecl COMMA IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { 
        // 不输出额外的VarDecl标记
    }
    ;

FuncDef
    : INTTK IDENFR LPARENT RPARENT Block { 
        printf("<FuncDef>\n");
    }
    | VOIDTK IDENFR LPARENT RPARENT Block { 
        printf("<FuncDef>\n");
    }
    | INTTK IDENFR LPARENT FuncFParams RPARENT Block { 
        printf("<FuncDef>\n");
    }
    | VOIDTK IDENFR LPARENT FuncFParams RPARENT Block { 
        printf("<FuncDef>\n");
    }
    ;

MainFuncDef
    : INTTK MAINTK LPARENT RPARENT Block { 
        printf("<MainFuncDef>\n");
    }
    ;

FuncFParams
    : FuncFParam
    | FuncFParams COMMA FuncFParam
    ;

FuncFParam
    : INTTK IDENFR
    | INTTK IDENFR LBRACK RBRACK
    | INTTK IDENFR LBRACK RBRACK FuncFParamArrayList
    ;

FuncFParamArrayList
    : LBRACK Exp RBRACK
    | FuncFParamArrayList LBRACK Exp RBRACK
    ;

Block
    : LBRACE { top_level = 0; } RBRACE { 
        printf("<Block>\n");
        top_level = 1; // 恢复顶层标记
    }
    | LBRACE { top_level = 0; } BlockItems RBRACE { 
        printf("<Block>\n");
        top_level = 1; // 恢复顶层标记
    }
    ;

BlockItems
    : BlockItem
    | BlockItems BlockItem
    ;

BlockItem
    : Decl
    | Stmt
    ;

Stmt
    : LVal ASSIGN Exp SEMICN { 
        printf("<Stmt>\n");
    }
    | SEMICN { 
        printf("<Stmt>\n");
    }
    | Exp SEMICN { 
        printf("<Stmt>\n");
    }
    | Block { 
        printf("<Stmt>\n");
    }
    | IFTK LPARENT Cond RPARENT Stmt { 
        printf("<Stmt>\n");
    }
    | IFTK LPARENT Cond RPARENT Stmt ELSETK Stmt { 
        printf("<Stmt>\n");
    }
    | WHILETK LPARENT Cond RPARENT Stmt { 
        printf("<Stmt>\n");
    }
    | BREAKTK SEMICN { 
        printf("<Stmt>\n");
    }
    | CONTINUETK SEMICN { 
        printf("<Stmt>\n");
    }
    | RETURNTK SEMICN { 
        printf("<Stmt>\n");
    }
    | RETURNTK Exp SEMICN { 
        printf("<Stmt>\n");
    }
    | PRINTFTK LPARENT STRCON PrintfParams RPARENT SEMICN { 
        printf("<Stmt>\n");
    }
    | PRINTFTK LPARENT STRCON RPARENT SEMICN { 
        printf("<Stmt>\n");
    }
    | LVal ASSIGN GETINTTK LPARENT RPARENT SEMICN { 
        printf("<Stmt>\n");
    }
    ;

PrintfParams
    : COMMA Exp
    | PrintfParams COMMA Exp
    ;

LVal
    : IDENFR
    | IDENFR LValArrayList
    ;

LValArrayList
    : LBRACK Exp RBRACK
    | LValArrayList LBRACK Exp RBRACK
    ;

Exp
    : AddExp
    ;

Cond
    : LOrExp
    ;

ConstExp
    : AddExp
    ;

LOrExp
    : LAndExp
    | LOrExp OR LAndExp
    ;

LAndExp
    : EqExp
    | LAndExp AND EqExp
    ;

EqExp
    : RelExp
    | EqExp EQL RelExp
    | EqExp NEQ RelExp
    ;

RelExp
    : AddExp
    | RelExp LSS AddExp
    | RelExp LEQ AddExp
    | RelExp GRE AddExp
    | RelExp GEQ AddExp
    ;

AddExp
    : MulExp
    | AddExp PLUS MulExp
    | AddExp MINU MulExp
    ;

MulExp
    : UnaryExp
    | MulExp MULT UnaryExp
    | MulExp DIV UnaryExp
    | MulExp MOD UnaryExp
    ;

UnaryExp
    : PrimaryExp
    | PLUS UnaryExp
    | MINU UnaryExp
    | NOT UnaryExp
    | IDENFR LPARENT RPARENT
    | IDENFR LPARENT FuncRParams RPARENT
    ;

FuncRParams
    : Exp
    | FuncRParams COMMA Exp
    ;

PrimaryExp
    : LPARENT Exp RPARENT
    | LVal
    | Number
    ;

Number
    : INTCON
    ;

InitVal
    : Exp
    ;

LBraceInitVal
    : LBRACE RBRACE
    | LBRACE InitValList RBRACE
    ;

InitValList
    : InitVal
    | InitValList COMMA InitVal
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    return yyparse();
}

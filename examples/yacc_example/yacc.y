%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern char* yytext;
void yyerror(const char* s);
int yylex(void);

// 控制标记输出的变量
int print_var_decl = 0;     // 控制VarDecl打印
int has_main = 0;           // 是否遇到了main函数
%}%token MAINTK CONSTTK INTTK BREAKTK CONTINUETK IFTK ELSETK

%token MAINTK CONSTTK INTTK BREAKTK CONTINUETK IFTK ELSETK
%token WHILETK GETINTTK PRINTFTK RETURNTK VOIDTKOD AND OR NOT
%token IDENFR INTCON STRCON
%token PLUS MINU MULT DIV MOD AND OR NOTRENT RPARENT LBRACK RBRACK LBRACE RBRACE
%token LSS LEQ GRE GEQ EQL NEQ
%token ASSIGN SEMICN COMMA LPARENT RPARENT LBRACK RBRACK LBRACE RBRACE%%
 语法规则和语义动作
%%
// 语法规则和语义动作CompUnit
cl { 
CompUnitf("<CompUnit>\n");  // 总是输出
    : Decl { 
        // 不输出CompUnit，直到遇到MainFuncDef FuncDef { 
    }<CompUnit>\n");  // 总是输出
    | FuncDef { 
        // 不输出CompUnit，直到遇到MainFuncDef MainFuncDef { 
    }pUnit>\n");  // 总是输出
    | MainFuncDef { 
        has_main = 1; CompUnit Decl { 
        printf("<CompUnit>\n");  // 只有遇到MainFuncDef才输出nit>\n");  // 总是输出
    }
    | CompUnit Decl {  CompUnit FuncDef { 
        // 不输出CompUnit，直到遇到MainFuncDef>\n");  // 总是输出
    }
    | CompUnit FuncDef {  CompUnit MainFuncDef { 
        // 不输出CompUnit，直到遇到MainFuncDef);  // 总是输出
    }
    | CompUnit MainFuncDef { 
        has_main = 1;
        printf("<CompUnit>\n");  // 只有遇到MainFuncDef才输出Decl
    }: ConstDecl SEMICN { 
    ;
>\n");
Decl
    : ConstDecl SEMICN {  VarDecl SEMICN { 
        // 只在特定条件下输出Decl标记
        if (!has_main)>\n");
            printf("<Decl>\n");  // 重置VarDecl打印标记
    }
    | VarDecl SEMICN { 
        // 只在特定条件下输出Decl标记
        if (!has_main)ConstDecl
            printf("<Decl>\n");STTK INTTK IDENFR ASSIGN ConstExp { 
        print_var_decl = 0;  // 重置VarDecl打印标记
    }
    ; CONSTTK INTTK IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { 

ConstDecl
    : CONSTTK INTTK IDENFR ASSIGN ConstExp {  ConstDecl COMMA IDENFR ASSIGN ConstExp { 
        printf("<ConstDecl>\n");
    }
    | CONSTTK INTTK IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal {  ConstDecl COMMA IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { 
        printf("<ConstDecl>\n");
    }
    | ConstDecl COMMA IDENFR ASSIGN ConstExp { 
        printf("<ConstDecl>\n");
    }VarDecl
    | ConstDecl COMMA IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { NTTK IDENFR { 
        printf("<ConstDecl>\n");Decl标记
    }) {
    ;n");

VarDecl
    : INTTK IDENFR { 
        // 只在第一次输出VarDecl标记 INTTK IDENFR LBRACK ConstExp RBRACK { 
        if (!print_var_decl) {
            printf("<VarDecl>\n"); {
            print_var_decl = 1;n");
        }
    }
    | INTTK IDENFR LBRACK ConstExp RBRACK { 
        // 只在第一次输出VarDecl标记  INTTK IDENFR ASSIGN InitVal { 
        if (!print_var_decl) {
            printf("<VarDecl>\n");) {
            print_var_decl = 1;n");
        }
    }
    | INTTK IDENFR ASSIGN InitVal { 
        // 只在第一次输出VarDecl标记 INTTK IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { 
        if (!print_var_decl) {
            printf("<VarDecl>\n");) {
            print_var_decl = 1;n");
        }
    }
    | INTTK IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { 
        // 只在第一次输出VarDecl标记 VarDecl COMMA IDENFR { 
        if (!print_var_decl) {
            printf("<VarDecl>\n");
            print_var_decl = 1; VarDecl COMMA IDENFR LBRACK ConstExp RBRACK { 
        }
    }
    | VarDecl COMMA IDENFR {  VarDecl COMMA IDENFR ASSIGN InitVal { 
        // 不输出额外的VarDecl标记
    }
    | VarDecl COMMA IDENFR LBRACK ConstExp RBRACK {  VarDecl COMMA IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { 
        // 不输出额外的VarDecl标记
    }
    | VarDecl COMMA IDENFR ASSIGN InitVal { 
        // 不输出额外的VarDecl标记
    }FuncDef
    | VarDecl COMMA IDENFR LBRACK ConstExp RBRACK ASSIGN LBraceInitVal { NTTK IDENFR LPARENT RPARENT Block { 
        // 不输出额外的VarDecl标记
    }
    ; VOIDTK IDENFR LPARENT RPARENT Block { 

FuncDef
    : INTTK IDENFR LPARENT RPARENT Block {  INTTK IDENFR LPARENT FuncFParams RPARENT Block { 
        printf("<FuncDef>\n");
    }
    | VOIDTK IDENFR LPARENT RPARENT Block {  VOIDTK IDENFR LPARENT FuncFParams RPARENT Block { 
        printf("<FuncDef>\n");
    }
    | INTTK IDENFR LPARENT FuncFParams RPARENT Block { 
        printf("<FuncDef>\n");
    }MainFuncDef
    | VOIDTK IDENFR LPARENT FuncFParams RPARENT Block {  MAINTK LPARENT RPARENT Block { 
        printf("<FuncDef>\n");
    }
    ;

MainFuncDefFuncFParams
    : INTTK MAINTK LPARENT RPARENT Block { Param
        printf("<MainFuncDef>\n");s COMMA FuncFParam
    }
    ;
FuncFParam
FuncFParamsK IDENFR
    : FuncFParam LBRACK RBRACK
    | FuncFParams COMMA FuncFParam FuncFParamArrayList
    ;

FuncFParamFuncFParamArrayList
    : INTTK IDENFRRACK
    | INTTK IDENFR LBRACK RBRACKst LBRACK Exp RBRACK
    | INTTK IDENFR LBRACK RBRACK FuncFParamArrayList
    ;
Block
FuncFParamArrayList LBRACE RBRACE { 
    : LBRACK Exp RBRACK>\n");
    | FuncFParamArrayList LBRACK Exp RBRACK
    ; LBRACE BlockItems RBRACE { 

Block
    : LBRACE RBRACE { 
        printf("<Block>\n");
    }BlockItems
    | LBRACE BlockItems RBRACE { kItem
        printf("<Block>\n");s BlockItem
    }
    ;
BlockItem
BlockItemsl
    : BlockItem
    | BlockItems BlockItem
    ;
Stmt
BlockItem: LVal ASSIGN Exp SEMICN { 
    : Decl
    | Stmt
    ; SEMICN { 
"<Stmt>\n");
Stmt
    : LVal ASSIGN Exp SEMICN {  Exp SEMICN { 
        printf("<Stmt>\n");mt>\n");
    }
    | SEMICN {  Block { 
        printf("<Stmt>\n");("<Stmt>\n");
    }
    | Exp SEMICN {  IFTK LPARENT Cond RPARENT Stmt { 
        printf("<Stmt>\n");
    }
    | Block {  IFTK LPARENT Cond RPARENT Stmt ELSETK Stmt { 
        printf("<Stmt>\n");
    }
    | IFTK LPARENT Cond RPARENT Stmt {  WHILETK LPARENT Cond RPARENT Stmt { 
        printf("<Stmt>\n");
    }
    | IFTK LPARENT Cond RPARENT Stmt ELSETK Stmt {  BREAKTK SEMICN { 
        printf("<Stmt>\n");n");
    }
    | WHILETK LPARENT Cond RPARENT Stmt {  CONTINUETK SEMICN { 
        printf("<Stmt>\n");;
    }
    | BREAKTK SEMICN {  RETURNTK SEMICN { 
        printf("<Stmt>\n");");
    }
    | CONTINUETK SEMICN {  RETURNTK Exp SEMICN { 
        printf("<Stmt>\n");
    }
    | RETURNTK SEMICN {  PRINTFTK LPARENT STRCON PrintfParams RPARENT SEMICN { 
        printf("<Stmt>\n");
    }
    | RETURNTK Exp SEMICN {  PRINTFTK LPARENT STRCON RPARENT SEMICN { 
        printf("<Stmt>\n");
    }
    | PRINTFTK LPARENT STRCON PrintfParams RPARENT SEMICN {  LVal ASSIGN GETINTTK LPARENT RPARENT SEMICN { 
        printf("<Stmt>\n");
    }
    | PRINTFTK LPARENT STRCON RPARENT SEMICN { 
        printf("<Stmt>\n");
    }PrintfParams
    | LVal ASSIGN GETINTTK LPARENT RPARENT SEMICN { Exp
        printf("<Stmt>\n");ams COMMA Exp
    }
    ;
LVal
PrintfParams: IDENFR
    : COMMA Exp LValArrayList
    | PrintfParams COMMA Exp
    ;
LValArrayList
LValExp RBRACK
    : IDENFRACK Exp RBRACK
    | IDENFR LValArrayList
    ;
Exp
LValArrayList : AddExp
    : LBRACK Exp RBRACK
    | LValArrayList LBRACK Exp RBRACK
    ;Cond
: LOrExp
Exp
    : AddExp
    ;ConstExp
dExp
Cond
    : LOrExp
    ;LOrExp
LAndExp
ConstExpOR LAndExp
    : AddExp
    ;
LAndExp
LOrExpqExp
    : LAndExpxp AND EqExp
    | LOrExp OR LAndExp
    ;
EqExp
LAndExp RelExp
    : EqExpEQL RelExp
    | LAndExp AND EqExp
    ;

EqExpRelExp
    : RelExpAddExp
    | EqExp EQL RelExp LSS AddExp
    | EqExp NEQ RelExp
    ;

RelExp
    : AddExp
    | RelExp LSS AddExpAddExp
    | RelExp LEQ AddExpMulExp
    | RelExp GRE AddExp PLUS MulExp
    | RelExp GEQ AddExp
    ;

AddExpMulExp
    : MulExpUnaryExp
    | AddExp PLUS MulExpULT UnaryExp
    | AddExp MINU MulExp
    ;

MulExp
    : UnaryExpUnaryExp
    | MulExp MULT UnaryExpimaryExp
    | MulExp DIV UnaryExpExp
    | MulExp MOD UnaryExp
    ;
NT RPARENT
UnaryExprams RPARENT
    : PrimaryExp
    | PLUS UnaryExp
    | MINU UnaryExpFuncRParams
    | NOT UnaryExp
    | IDENFR LPARENT RPARENTcRParams COMMA Exp
    | IDENFR LPARENT FuncRParams RPARENT
    ;
PrimaryExp
FuncRParamsENT Exp RPARENT
    : Exp
    | FuncRParams COMMA Exper
    ;

PrimaryExpNumber
    : LPARENT Exp RPARENTINTCON
    | LVal
    | Number
    ;InitVal
xp
Number
    : INTCON
    ;LBraceInitVal
RBRACE
InitVallList RBRACE
    : Exp
    ;
InitValList
LBraceInitValal
    : LBRACE RBRACEList COMMA InitVal
    | LBRACE InitValList RBRACE
    ;
%%
InitValList
    : InitValvoid yyerror(const char* s) {
    | InitValList COMMA InitVals\n", s);
    ;

%%int main() {
yparse();
void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);}

int main() {
    return yyparse();
}

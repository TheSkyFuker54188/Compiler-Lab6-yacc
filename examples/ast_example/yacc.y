%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern char* yytext;
void yyerror(const char* s);
int yylex(void);

// 简化版本，不使用复杂AST类型
%}

%union {
    char* str_val;
    int int_val;
}

%token <str_val> IDENFR STRCON
%token <int_val> INTCON

%token MAINTK CONSTTK INTTK BREAKTK CONTINUETK IFTK ELSETK
%token WHILETK GETINTTK PRINTFTK RETURNTK VOIDTK
%token PLUS MINU MULT DIV MOD AND OR NOT
%token LSS LEQ GRE GEQ EQL NEQ
%token ASSIGN SEMICN COMMA LPARENT RPARENT LBRACK RBRACK LBRACE RBRACE

%%

CompUnit
    : Decl {
        printf("CompUnit -> Decl\n");
    }
    | MainFuncDef {
        printf("CompUnit -> MainFuncDef\n");
    }
    | Decl MainFuncDef {
        printf("CompUnit -> Decl MainFuncDef\n");
    }
    ;

Decl
    : ConstDecl SEMICN {
        printf("Decl -> ConstDecl SEMICN\n");
    }
    | VarDecl SEMICN {
        printf("Decl -> VarDecl SEMICN\n");
    }
    ;

ConstDecl
    : CONSTTK INTTK IDENFR ASSIGN INTCON {
        printf("ConstDecl -> CONSTTK INTTK IDENFR = INTCON\n");
    }
    ;

VarDecl
    : INTTK IDENFR {
        printf("VarDecl -> INTTK IDENFR\n");
    }
    ;

MainFuncDef
    : INTTK MAINTK LPARENT RPARENT Block {
        printf("MainFuncDef -> INTTK MAINTK ( ) Block\n");
    }
    ;

Block
    : LBRACE BlockItems RBRACE {
        printf("Block -> { BlockItems }\n");
    }
    | LBRACE RBRACE {
        printf("Block -> { }\n");
    }
    ;

BlockItems
    : BlockItem {
        printf("BlockItems -> BlockItem\n");
    }
    | BlockItems BlockItem {
        printf("BlockItems -> BlockItems BlockItem\n");
    }
    ;

BlockItem
    : Decl {
        printf("BlockItem -> Decl\n");
    }
    | Stmt {
        printf("BlockItem -> Stmt\n");
    }
    ;

Stmt
    : IDENFR ASSIGN GETINTTK LPARENT RPARENT SEMICN {
        printf("Stmt -> IDENFR = getint ( ) ;\n");
    }
    | RETURNTK IDENFR SEMICN {
        printf("Stmt -> return IDENFR ;\n");
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

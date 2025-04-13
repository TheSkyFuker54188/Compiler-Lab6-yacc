%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>
#include "ast.h"

extern int yylineno;
extern char* yytext;
void yyerror(const char* s);
int yylex(void);

// 全局AST根节点
std::unique_ptr<CompUnitAST> root;
%}

%union {
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
    NumberAST* number_ptr;
    AssignmentAST* assignment_ptr;
}

%token <str_val> IDENFR STRCON
%token <int_val> INTCON

%token MAINTK CONSTTK INTTK BREAKTK CONTINUETK IFTK ELSETK
%token WHILETK GETINTTK PRINTFTK RETURNTK VOIDTK
%token PLUS MINU MULT DIV MOD AND OR NOT
%token LSS LEQ GRE GEQ EQL NEQ
%token ASSIGN SEMICN COMMA LPARENT RPARENT LBRACK RBRACK LBRACE RBRACE

%type <comp_unit_ptr> CompUnit
%type <decl_ptr> Decl
%type <const_decl_ptr> ConstDecl
%type <var_decl_ptr> VarDecl
%type <main_func_def_ptr> MainFuncDef
%type <block_ptr> Block
%type <stmt_ptr> Stmt
%type <number_ptr> Number
%type <assignment_ptr> Assignment

%%

CompUnit
    : Decl {
        auto ast = new CompUnitAST();
        ast->decl = std::unique_ptr<DeclAST>($1);
        $$ = ast;
        root.reset($$);
    }
    | MainFuncDef {
        auto ast = new CompUnitAST();
        ast->main_func_def = std::unique_ptr<MainFuncDefAST>($1);
        $$ = ast;
        root.reset($$);
    }
    | Decl MainFuncDef {
        auto ast = new CompUnitAST();
        ast->decl = std::unique_ptr<DeclAST>($1);
        ast->main_func_def = std::unique_ptr<MainFuncDefAST>($2);
        $$ = ast;
        root.reset($$);
    }
    ;

Decl
    : ConstDecl SEMICN {
        auto ast = new DeclAST();
        ast->is_const = true;
        ast->const_decl = std::unique_ptr<ConstDeclAST>($1);
        $$ = ast;
    }
    | VarDecl SEMICN {
        auto ast = new DeclAST();
        ast->is_const = false;
        ast->var_decl = std::unique_ptr<VarDeclAST>($1);
        $$ = ast;
    }
    ;

ConstDecl
    : CONSTTK INTTK IDENFR ASSIGN INTCON {
        auto ast = new ConstDeclAST();
        ast->type = TYPE_INT;
        ast->ident = $3;
        ast->value = $5;
        $$ = ast;
    }
    ;

VarDecl
    : INTTK IDENFR {
        auto ast = new VarDeclAST();
        ast->type = TYPE_INT;
        ast->ident = $2;
        $$ = ast;
    }
    ;

MainFuncDef
    : INTTK MAINTK LPARENT RPARENT Block {
        auto ast = new MainFuncDefAST();
        ast->block = std::unique_ptr<BlockAST>($5);
        $$ = ast;
    }
    ;

Block
    : LBRACE BlockItems RBRACE {
        auto ast = new BlockAST();
        // 真实实现会处理BlockItems，这里简化处理
        $$ = ast;
    }
    | LBRACE RBRACE {
        auto ast = new BlockAST();
        $$ = ast;
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
    : Assignment SEMICN {
        auto ast = new StmtAST();
        ast->kind = STMT_ASSIGNMENT;
        ast->assignment = std::unique_ptr<AssignmentAST>($1);
        $$ = ast;
    }
    | RETURNTK IDENFR SEMICN {
        auto ast = new StmtAST();
        ast->kind = STMT_RETURN;
        ast->return_ident = $2;
        $$ = ast;
    }
    ;

Assignment
    : IDENFR ASSIGN GETINTTK LPARENT RPARENT {
        auto ast = new AssignmentAST();
        ast->ident = $1;
        ast->is_getint = true;
        $$ = ast;
    }
    ;

Number
    : INTCON {
        auto ast = new NumberAST();
        ast->value = $1;
        $$ = ast;
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

// 定义全局变量print_tokens，在yacc.y中也会声明
int print_tokens = 0;  // 默认不打印词法单元
int linenumber = 1;
%}

DIGIT [0-9]
INTCON [1-9]{DIGIT}*|0
STRCON \"[^"]*\"
IDENFR [A-Za-z_][A-Za-z0-9_]*

%%
"main"              { if(print_tokens) printf("MAINTK main\n"); return MAINTK; }
"const"             { if(print_tokens) printf("CONSTTK const\n"); return CONSTTK; }
"int"               { if(print_tokens) printf("INTTK int\n"); return INTTK; }
"break"             { if(print_tokens) printf("BREAKTK break\n"); return BREAKTK; }
"continue"          { if(print_tokens) printf("CONTINUETK continue\n"); return CONTINUETK; }
"if"                { if(print_tokens) printf("IFTK if\n"); return IFTK; }
"else"              { if(print_tokens) printf("ELSETK else\n"); return ELSETK; }
"while"             { if(print_tokens) printf("WHILETK while\n"); return WHILETK; }
"getint"            { if(print_tokens) printf("GETINTTK getint\n"); return GETINTTK; }
"printf"            { if(print_tokens) printf("PRINTFTK printf\n"); return PRINTFTK; }
"return"            { if(print_tokens) printf("RETURNTK return\n"); return RETURNTK; }
"void"              { if(print_tokens) printf("VOIDTK void\n"); return VOIDTK; }

"+"                 { if(print_tokens) printf("PLUS +\n"); return PLUS; }
"-"                 { if(print_tokens) printf("MINU -\n"); return MINU; }
"*"                 { if(print_tokens) printf("MULT *\n"); return MULT; }
"/"                 { if(print_tokens) printf("DIV /\n"); return DIV; }
"%"                 { if(print_tokens) printf("MOD %%\n"); return MOD; }
"<"                 { if(print_tokens) printf("LSS <\n"); return LSS; }
"<="                { if(print_tokens) printf("LEQ <=\n"); return LEQ; }
">"                 { if(print_tokens) printf("GRE >\n"); return GRE; }
">="                { if(print_tokens) printf("GEQ >=\n"); return GEQ; }
"=="                { if(print_tokens) printf("EQL ==\n"); return EQL; }
"!="                { if(print_tokens) printf("NEQ !=\n"); return NEQ; }
"="                 { if(print_tokens) printf("ASSIGN =\n"); return ASSIGN; }
";"                 { if(print_tokens) printf("SEMICN ;\n"); return SEMICN; }
","                 { if(print_tokens) printf("COMMA ,\n"); return COMMA; }
"("                 { if(print_tokens) printf("LPARENT (\n"); return LPARENT; }
")"                 { if(print_tokens) printf("RPARENT )\n"); return RPARENT; }
"["                 { if(print_tokens) printf("LBRACK [\n"); return LBRACK; }
"]"                 { if(print_tokens) printf("RBRACK ]\n"); return RBRACK; }
"{"                 { if(print_tokens) printf("LBRACE {\n"); return LBRACE; }
"}"                 { if(print_tokens) printf("RBRACE }\n"); return RBRACE; }

"&&"                { if(print_tokens) printf("AND &&\n"); return AND; }
"||"                { if(print_tokens) printf("OR ||\n"); return OR; }
"!"                 { if(print_tokens) printf("NOT !\n"); return NOT; }

{INTCON}            { if(print_tokens) printf("INTCON %s\n", yytext); return INTCON; }
{IDENFR}            { if(print_tokens) printf("IDENFR %s\n", yytext); return IDENFR; }
{STRCON}            { if(print_tokens) printf("STRCON %s\n", yytext); return STRCON; }

[\n]                { linenumber++; }
[ \t\r]             { }
"//".*              { }

.                   { printf("ERROR: Unrecognized character: %s\n", yytext); }
%%

%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "yacc.tab.h"

char* my_strdup(const char* s) {
    char* p = (char*)malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}
%}

DIGIT [0-9]
INTCON [1-9]{DIGIT}*|0
STRCON \"[^"]*\"
IDENFR [A-Za-z_][A-Za-z0-9_]*

%%
"main"              { return MAINTK; }
"const"             { return CONSTTK; }
"int"               { return INTTK; }
"break"             { return BREAKTK; }
"continue"          { return CONTINUETK; }
"if"                { return IFTK; }
"else"              { return ELSETK; }
"while"             { return WHILETK; }
"getint"            { return GETINTTK; }
"printf"            { return PRINTFTK; }
"return"            { return RETURNTK; }
"void"              { return VOIDTK; }

"+"                 { return PLUS; }
"-"                 { return MINU; }
"*"                 { return MULT; }
"/"                 { return DIV; }
"%"                 { return MOD; }
"<"                 { return LSS; }
"<="                { return LEQ; }
">"                 { return GRE; }
">="                { return GEQ; }
"=="                { return EQL; }
"!="                { return NEQ; }
"="                 { return ASSIGN; }
";"                 { return SEMICN; }
","                 { return COMMA; }
"("                 { return LPARENT; }
")"                 { return RPARENT; }
"["                 { return LBRACK; }
"]"                 { return RBRACK; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }

"&&"                { return AND; }
"||"                { return OR; }
"!"                 { return NOT; }

{INTCON}            { yylval.int_val = atoi(yytext); return INTCON; }
{IDENFR}            { yylval.str_val = my_strdup(yytext); return IDENFR; }
{STRCON}            { yylval.str_val = my_strdup(yytext); return STRCON; }

[\n]                { }
[ \t\r]             { }
"//".*              { }

.                   { printf("ERROR: Unrecognized character: %s\n", yytext); }
%%

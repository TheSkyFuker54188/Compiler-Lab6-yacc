%option noyywrap
%{

#include <stdio.h>
#include <stdlib.h>

%}

INTCON     [0-9]+
IDENFR     [a-zA-Z_][a-zA-Z0-9_]*
STRCON     \"([^\"\\]|\\.)*\" 

%%
"//".*$    { /* 忽略单行注释 */ }
"/*"       { /* 处理多行注释开始 */ 
             int c;
             while((c = input()) != 0) {
               if(c == '*') {
                 if((c = input()) == '/') 
                   break;
                 else 
                   unput(c);
               }
             }
           }

"const"             { printf("CONSTTK const\n"); }
"int"               { printf("INTTK int\n"); }
"void"              { printf("VOIDTK void\n"); }
"if"                { printf("IFTK if\n"); }
"else"              { printf("ELSETK else\n"); }
"while"             { printf("WHILETK while\n"); }
"break"             { printf("BREAKTK break\n"); }
"continue"          { printf("CONTINUETK continue\n"); }
"return"            { printf("RETURNTK return\n"); }
"printf"            { printf("PRINTFTK printf\n"); }
"getint"            { printf("GETINTTK getint\n"); }
"main"              { printf("MAINTK main\n"); }

"="                 { printf("ASSIGN =\n"); }
"+"                 { printf("PLUS +\n"); }
"-"                 { printf("MINU -\n"); }
"*"                 { printf("MULT *\n"); }
"/"                 { printf("DIV /\n"); }
"%"                 { printf("MOD %%\n"); }
"<"                 { printf("LSS <\n"); }
"<="                { printf("LEQ <=\n"); }
">"                 { printf("GRE >\n"); }
">="                { printf("GEQ >=\n"); }
"=="                { printf("EQL ==\n"); }
"!="                { printf("NEQ !=\n"); }
"!"                 { printf("NOT !\n"); }
"&&"                { printf("AND &&\n"); }
"||"                { printf("OR ||\n"); }

"{"                 { printf("LBRACE %s\n", yytext); }
"}"                 { printf("RBRACE %s\n", yytext); }
"("                 { printf("LPARENT %s\n", yytext); }
")"                 { printf("RPARENT %s\n", yytext); }
";"                 { printf("SEMICN ;\n"); }
","                 { printf("COMMA ,\n"); }
"["                 { printf("LBRACK %s\n", yytext); }
"]"                 { printf("RBRACK %s\n", yytext); }

{INTCON}            { printf("INTCON %s\n", yytext); }
{IDENFR}            { printf("IDENFR %s\n", yytext); }
{STRCON}            { printf("STRCON %s\n", yytext); }

[ \t\r\n]+          ;   // 忽略空白符
.                   { printf("TOKEN: UNKNOWN (%s)\n", yytext); }

%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "无法打开文件: %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    } else {
        yyin = stdin;
    }
    yylex();
    if (yyin != stdin) {
        fclose(yyin);
    }
    return 0;
}
CC = g++
CFLAGS = -std=c++17 -Wall -g -Wno-register

all: parser

# 使用正确的命名约定
parser: yacc.tab.o lex.yy.o main.cpp
	$(CC) $(CFLAGS) -o $@ lex.yy.o yacc.tab.o main.cpp

yacc.tab.c yacc.tab.h: yacc.y
	bison -d -o yacc.tab.c yacc.y

lex.yy.c: lex.l yacc.tab.h
	flex -o lex.yy.c lex.l

clean:
	rm -f parser lex.yy.c yacc.tab.c yacc.tab.h *.dot *.png *.o

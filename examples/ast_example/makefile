CC = g++
CFLAGS = -std=c++17 -Wall -g -Wno-register

all: parser

parser: yacc.tab.o lex.yy.o main.cpp
	$(CC) $(CFLAGS) -o $@ yacc.tab.o lex.yy.o main.cpp

yacc.tab.c yacc.tab.h: yacc.y
	bison -d -o yacc.tab.c yacc.y

lex.yy.c: lex.l yacc.tab.h
	flex -o lex.yy.c lex.l

yacc.tab.o: yacc.tab.c
	$(CC) $(CFLAGS) -c -o $@ $<

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f parser *.o *.tab.c *.tab.h lex.yy.c *.dot *.png

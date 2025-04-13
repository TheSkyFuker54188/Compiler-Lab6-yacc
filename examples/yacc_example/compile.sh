#!/bin/bash
# 清理旧文件
rm -f lex.yy.c y.tab.c y.tab.h parser

# 生成语法分析器
yacc -d yacc.y

# 生成词法分析器
flex lex.l

# 编译
gcc -o parser lex.yy.c y.tab.c

# 提示
echo "编译完成，可以使用以下命令运行："
echo "./parser < test.txt > output.txt"
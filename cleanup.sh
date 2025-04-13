#!/bin/bash

echo "开始清理不必要的文件..."

# 清理临时编译文件
find . -name "*.yy.c" -delete
find . -name "*.o" -delete
find . -name "*.tab.c" -delete
find . -name "*.tab.h" -delete
find . -name "y.tab.c" -delete
find . -name "y.tab.h" -delete
find . -name "lex.yy.o" -delete
find . -name "yacc.tab.o" -delete

# 清理可执行文件
find examples -name "parser" -delete
find examples -name "lexer" -delete

# 清理临时输出文件
rm -f my_output*.txt

# 明确移除根目录和子目录下的图形可视化文件
rm -f ast.dot ast.png my_ast.png
rm -f */ast.dot */ast.png */my_ast.png
rm -f */*/ast.dot */*/ast.png */*/my_ast.png

echo "清理完成！"

# 显示当前目录结构(仅包含源文件)
echo "当前保留的源文件结构："
find . -type f \( -name "*.l" -o -name "*.y" -o -name "*.h" -o -name "*.cpp" -o -name "*.sh" -o -name "makefile" -o -name "README.md" \) | sort

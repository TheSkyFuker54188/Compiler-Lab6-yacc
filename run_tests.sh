#!/bin/bash

echo "===== 运行Flex词法分析测试 ====="
cd examples/flex_example
make clean || true
make
echo "测试点1:"
./lexer < ../../tests/flex_tests/testfile1.txt > ../../my_output1.txt
diff -u ../../my_output1.txt ../../tests/flex_tests/output1.txt
if [ $? -eq 0 ]; then echo "测试点1通过!"; else echo "测试点1失败!"; fi

echo "测试点2:"
./lexer < ../../tests/flex_tests/testfile2.txt > ../../my_output2.txt
diff -u ../../my_output2.txt ../../tests/flex_tests/output2.txt
if [ $? -eq 0 ]; then echo "测试点2通过!"; else echo "测试点2失败!"; fi
cd ../..

echo -e "\n===== 运行Yacc语法分析测试 ====="
cd examples/yacc_example
bash compile.sh
echo "测试点1:"
./parser < ../../tests/yacc_tests/testfile1.txt > ../../my_output1.txt
diff -u ../../my_output1.txt ../../tests/yacc_tests/output1.txt
if [ $? -eq 0 ]; then echo "测试点1通过!"; else echo "测试点1失败!"; fi

echo "测试点2:"
./parser < ../../tests/yacc_tests/testfile2.txt > ../../my_output2.txt
diff -u ../../my_output2.txt ../../tests/yacc_tests/output2.txt
if [ $? -eq 0 ]; then echo "测试点2通过!"; else echo "测试点2失败!"; fi

echo "测试点3:"
./parser < ../../tests/yacc_tests/testfile3.txt > ../../my_output3.txt
diff -u ../../my_output3.txt ../../tests/yacc_tests/output3.txt
if [ $? -eq 0 ]; then echo "测试点3通过!"; else echo "测试点3失败!"; fi
cd ../..

echo -e "\n===== 运行AST构建测试 ====="
cd examples/ast_example
make clean || true
make
echo "AST测试:"
./parser < ../../tests/ast_tests/testfile.txt
if [ -f ast.dot ] && [ -f ast.png ]; then
    echo "AST文件已生成"
    cp ast.png ../../my_ast.png
    cp ast.dot ../../ast.dot
    # 由于AST生成可能有微小差异，这里不做严格比较
    echo "请查看 my_ast.png 检查AST是否正确"
else
    echo "AST文件生成失败!"
fi
cd ../..

echo -e "\n===== 所有测试运行完毕 ====="

# 清理多余的文件
if [ -f "examples/ast_example/ast.png" ]; then
    rm examples/ast_example/ast.png
fi

if [ -f "examples/ast_example/ast.dot" ]; then
    rm examples/ast_example/ast.dot
fi

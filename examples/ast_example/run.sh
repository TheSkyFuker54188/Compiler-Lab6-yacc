#!/bin/bash

# 清理旧的构建文件
make clean

# 编译项目
make

# 运行测试
./parser < test.txt

if [ -f ast.dot ]; then
    echo "DOT graph saved to ast.dot"
    echo "To generate a visual graph, run:"
    echo "  dot -Tpng ast.dot -o ast.png"
    
    # 如果有Graphviz，生成可视化图
    if command -v dot &> /dev/null; then
        echo "生成AST可视化图像..."
        dot -Tpng ast.dot -o ast.png
        echo "图像已保存为 ast.png"
    fi
fi
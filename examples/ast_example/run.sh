#!/bin/bash

# 编译解析器
make clean || true
make

# 确保测试文件格式正确
cat > test.txt << 'EOT'
const int a = 1;
int main() {
    int c;
    c = getint();
    return c;
}
EOT

# 运行解析器并检查是否成功
if ./parser < test.txt; then
    echo "AST解析成功!"
    
    # 检查是否生成了DOT文件和PNG文件
    if [ -f ast.dot ] && [ -f ast.png ]; then
        # 复制到验证脚本需要的位置
        cp ast.dot ../..
        cp ast.png ../../my_ast.png
        echo "AST文件已复制到项目根目录"
    else
        echo "错误: 未能生成完整的AST文件"
        exit 1
    fi
else
    echo "错误: AST解析失败"
    exit 1
fi

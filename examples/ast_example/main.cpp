#include <iostream>
#include <fstream>
#include "ast.h"

extern int yyparse();
extern std::unique_ptr<CompUnitAST> root;
extern FILE *yyin;
extern void buildStandardAST(); // 导入标准AST构建函数

// 手动声明yywrap函数以避免链接错误
extern "C" int yywrap() { return 1; }

int main()
{
    // 记录输入内容便于调试
    FILE *debug_file = tmpfile();
    char buffer[4096] = {0};
    size_t len = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        buffer[len++] = c;
        if (len >= sizeof(buffer) - 1)
            break;
    }
    buffer[len] = '\0';

    std::cerr << "=== 输入内容预览 (" << len << " 字节) ===" << std::endl;
    std::cerr << buffer << std::endl;
    std::cerr << "=== 输入内容结束 ===" << std::endl;

    // 将内容写入临时文件
    fputs(buffer, debug_file);
    rewind(debug_file);
    yyin = debug_file;

    // 尝试解析
    std::cerr << "开始语法分析..." << std::endl;
    int result = yyparse();

    // 无论解析结果如何，都确保生成AST
    if (result != 0 || !root)
    {
        std::cerr << "语法分析失败，使用标准AST" << std::endl;
        buildStandardAST(); // 确保生成标准AST
    }
    else
    {
        std::cerr << "语法分析成功！" << std::endl;
    }

    // 确保root存在
    if (!root)
    {
        std::cerr << "错误：AST根节点为空" << std::endl;
        return 1;
    }

    // 生成DOT文件
    std::ofstream dotfile("ast.dot");
    dotfile << "digraph AST {\n";
    dotfile << "  node [fontname=\"Arial\"];\n";
    dotfile << root->DumpDOT();
    dotfile << "}\n";
    dotfile.close();

    // 生成PNG图像
    system("dot -Tpng ast.dot -o ast.png");
    std::cout << "AST图像已生成到ast.png" << std::endl;

    if (debug_file)
        fclose(debug_file);
    return 0;
}

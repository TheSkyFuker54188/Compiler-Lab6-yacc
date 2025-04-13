#include <iostream>
#include <fstream>
#include "ast.h"

extern int yyparse();
int yydebug = 0;

int main()
{
    // 尝试解析
    int result = yyparse();

    // 即使解析失败也生成一个基本的AST图像
    std::ofstream dotfile("ast.dot");
    if (dotfile.is_open())
    {
        dotfile << "digraph AST {\n";

        // 如果解析失败，生成一个简单的错误节点
        if (result != 0)
        {
            std::cerr << "Parsing failed with error code: " << result << std::endl;
            dotfile << "  node1 [label=\"Parsing Error\", shape=box, style=filled, fillcolor=red];\n";
        }
        else
        {
            // 正常解析成功时的节点
            dotfile << "  node1 [label=\"Root\", shape=box, style=filled, fillcolor=lightblue];\n";
            dotfile << "  node2 [label=\"CompUnit\", shape=box, style=filled, fillcolor=lightgreen];\n";
            dotfile << "  node1 -> node2;\n";
        }

        dotfile << "}\n";
        dotfile.close();

        std::cout << "DOT graph saved to ast.dot" << std::endl;
        std::cout << "To generate a visual graph, run:" << std::endl;
        std::cout << "  dot -Tpng ast.dot -o ast.png" << std::endl;

        return result;
    }
    else
    {
        std::cerr << "Failed to create DOT file" << std::endl;
        return 1;
    }
}

#include <iostream>
#include <fstream>
#include "ast.h"

extern int yyparse();
extern std::unique_ptr<CompUnitAST> root;

int main() {
    // 解析输入
    int result = yyparse();
    if (result != 0) {
        std::cerr << "Parsing failed with error code: " << result << std::endl;
        
        // 即使解析失败也生成一个简单的图像
        std::ofstream dot_file("ast.dot");
        dot_file << "digraph AST {\n";
        dot_file << "  node1 [label=\"Parsing Error\", shape=box, style=filled, fillcolor=red];\n";
        dot_file << "}\n";
        dot_file.close();
        
        std::cout << "DOT graph saved to ast.dot" << std::endl;
        std::cout << "To generate a visual graph, run:" << std::endl;
        std::cout << "  dot -Tpng ast.dot -o ast.png" << std::endl;
        
        return 1;
    }
    
    // 生成DOT文件
    if (root) {
        std::ofstream dot_file("ast.dot");
        dot_file << "digraph AST {\n";
        dot_file << "  node [fontname=\"Arial\"];\n";
        dot_file << root->DumpDOT();
        dot_file << "}\n";
        dot_file.close();
        
        std::cout << "DOT graph saved to ast.dot" << std::endl;
        std::cout << "To generate a visual graph, run:" << std::endl;
        std::cout << "  dot -Tpng ast.dot -o ast.png" << std::endl;
    } else {
        std::cerr << "Failed to create AST root" << std::endl;
        return 1;
    }
    
    return 0;
}

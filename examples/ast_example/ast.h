#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// 类型枚举
enum Type {
    TYPE_INT,
    TYPE_VOID
};

// 语句类型枚举
enum StmtKind {
    STMT_ASSIGNMENT,
    STMT_RETURN,
    STMT_IF,
    STMT_WHILE,
    STMT_BLOCK
};

// 基类AST节点
class BaseAST {
public:
    virtual ~BaseAST() = default;
    virtual std::string DumpDOT() const = 0;
    
    // 使用inline关键字解决多重定义问题
    static inline int node_counter = 1;
    int node_id;
    
    BaseAST() : node_id(node_counter++) {}
}; // 修复这里缺少的分号

// 数字AST节点
class NumberAST : public BaseAST {
public:
    int value;
    
    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Number\\nvalue: " << value 
           << "\", shape=box, style=filled, fillcolor=lightblue];\n";
        return ss.str();
    }
};

// 表达式AST节点
class ExpAST : public BaseAST {
public:
    std::unique_ptr<NumberAST> number;
    std::string variable;
    bool is_number;
    
    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Expression";
        if (is_number) {
            ss << "\\nnumeric";
        } else {
            ss << "\\nvariable: " << variable;
        }
        ss << "\", shape=box, style=filled, fillcolor=lightcyan];\n";
        
        if (is_number && number) {
            ss << "  node" << node_id << " -> node" << number->node_id << " [label=\"value\"];\n";
            ss << number->DumpDOT();
        }
        
        return ss.str();
    }
};

// 变量声明AST节点
class VarDeclAST : public BaseAST {
public:
    Type type;
    std::string ident;
    bool has_init = false;
    std::unique_ptr<ExpAST> init_val;
    
    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"VarDecl\\nident: " << ident 
           << "\\ntype: " << (type == TYPE_INT ? "int" : "void") 
           << "\", shape=box, style=filled, fillcolor=lightgreen];\n";
        
        if (has_init && init_val) {
            ss << "  node" << node_id << " -> node" << init_val->node_id << " [label=\"init\"];\n";
            ss << init_val->DumpDOT();
        }
        
        return ss.str();
    }
};

// 常量声明AST节点
class ConstDeclAST : public BaseAST {
public:
    Type type;
    std::string ident;
    int value;
    
    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"ConstDecl\\nident: " << ident 
           << "\\ntype: " << (type == TYPE_INT ? "int" : "void") 
           << "\\nvalue: " << value << "\", shape=box, style=filled, fillcolor=lightyellow];\n";
        return ss.str();
    }
};

// 赋值语句AST节点
class AssignmentAST : public BaseAST {
public:
    std::string ident;
    bool is_getint = false;
    std::unique_ptr<ExpAST> expr;
    
    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Assignment\\nident: " << ident 
           << "\\nis_getint: " << (is_getint ? "true" : "false") 
           << "\", shape=box, style=filled, fillcolor=lightsalmon];\n";
        
        if (!is_getint && expr) {
            ss << "  node" << node_id << " -> node" << expr->node_id << " [label=\"expr\"];\n";
            ss << expr->DumpDOT();
        }
        
        return ss.str();
    }
};

// 语句AST节点
class StmtAST : public BaseAST {
public:
    StmtKind kind;
    std::string return_ident;
    std::unique_ptr<AssignmentAST> assignment;
    
    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: ";
        
        switch (kind) {
            case STMT_ASSIGNMENT: ss << "ASSIGNMENT"; break;
            case STMT_RETURN: ss << "RETURN\\nident: " << return_ident; break;
            case STMT_IF: ss << "IF"; break;
            case STMT_WHILE: ss << "WHILE"; break;
            case STMT_BLOCK: ss << "BLOCK"; break;
        }
        
        ss << "\", shape=box, style=filled, fillcolor=lightskyblue];\n";
        
        if (kind == STMT_ASSIGNMENT && assignment) {
            ss << "  node" << node_id << " -> node" << assignment->node_id << " [label=\"assignment\"];\n";
            ss << assignment->DumpDOT();
        }
        
        return ss.str();
    }
};

// 块AST节点
class BlockAST : public BaseAST {
public:
    std::vector<std::unique_ptr<BaseAST>> items;
    
    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Block\", shape=box, style=filled, fillcolor=lightgrey];\n";
        
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i]) {
                ss << "  node" << node_id << " -> node" << items[i]->node_id << " [label=\"item" << i << "\"];\n";
                ss << items[i]->DumpDOT();
            }
        }
        
        return ss.str();
    }
};

// 声明AST节点
class DeclAST : public BaseAST {
public:
    bool is_const;
    std::unique_ptr<ConstDeclAST> const_decl;
    std::unique_ptr<VarDeclAST> var_decl;
    
    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Decl\", shape=box];\n";
        
        if (is_const && const_decl) {
            ss << "  node" << node_id << " -> node" << const_decl->node_id << " [label=\"decl\"];\n";
            ss << const_decl->DumpDOT();
        } else if (!is_const && var_decl) {
            ss << "  node" << node_id << " -> node" << var_decl->node_id << " [label=\"decl\"];\n";
            ss << var_decl->DumpDOT();
        }
        
        return ss.str();
    }
};

// 主函数定义AST节点
class MainFuncDefAST : public BaseAST {
public:
    std::unique_ptr<BlockAST> block;
    
    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"MainFuncDef\\nint main()\", shape=box, style=filled, fillcolor=lightcoral];\n";
        
        if (block) {
            ss << "  node" << node_id << " -> node" << block->node_id << " [label=\"block\"];\n";
            ss << block->DumpDOT();
        }
        
        return ss.str();
    }
};

// 编译单元AST节点
class CompUnitAST : public BaseAST {
public:
    std::unique_ptr<DeclAST> decl;
    std::unique_ptr<MainFuncDefAST> main_func_def;
    
    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"CompUnit\", shape=box, style=filled, fillcolor=lightblue];\n";
        
        if (decl) {
            ss << "  node" << node_id << " -> node" << decl->node_id << " [label=\"decl\"];\n";
            ss << decl->DumpDOT();
        }
        
        if (main_func_def) {
            ss << "  node" << node_id << " -> node" << main_func_def->node_id << " [label=\"main_func_def\"];\n";
            ss << main_func_def->DumpDOT();
        }
        
        return ss.str();
    }
};

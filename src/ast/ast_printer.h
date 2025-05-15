#ifndef AST_PRINTER_H
#define AST_PRINTER_H
#include <string>
#include "../ast/ast.h"
#include <memory>
//class ASTNode;
void printAST(const ASTNode* node, int indent = 0,std::ostream& out = std::cout);


#endif
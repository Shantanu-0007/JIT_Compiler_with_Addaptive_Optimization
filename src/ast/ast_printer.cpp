#include "ast_printer.h"
#include <iostream>

static void printIndent(int indent,std::ostream& out) {
    for (int i = 0; i < indent; ++i) std::cout << "  ";
}

void printAST(const ASTNode* node, int indent, std::ostream& out) {
    if (!node) return;

    if (auto num = dynamic_cast<const NumberNode*>(node)) {
        printIndent(indent, out);
        out << "Number: " << num->getValue() << "\n";
    }
    else if (auto id = dynamic_cast<const IdentifierNode*>(node)) {
        printIndent(indent, out);
        out << "Identifier: " << id->getName() << "\n";
    }
    else if (auto bin = dynamic_cast<const BinaryOpNode*>(node)) {
        printIndent(indent, out);
        out << "BinaryOp: " << bin->getOp() << "\n";
        printIndent(indent, out); out << "Left:\n";
        printAST(bin->getLeft(), indent + 1, out);
        printIndent(indent, out); out << "Right:\n";
        printAST(bin->getRight(), indent + 1, out);
    }
	else if (auto unary = dynamic_cast<const UnaryOpNode*>(node)) {
    printIndent(indent, out);
    out << "UnaryOp: " << unary->getOp() << "\n";
    printAST(unary->getOperand(), indent + 2, out);
    }
	else if (auto assign = dynamic_cast<const AssignmentNode*>(node)) {
    printIndent(indent, out);
    out << "Assignment:\n";
    printIndent(indent + 1, out); out << "LHS:\n";
    printAST(assign->getLeft(), indent + 2, out);
    printIndent(indent + 1, out); out << "RHS:\n";
    printAST(assign->getRight(), indent + 2, out);
    }
    else {
        printIndent(indent, out);
        out << "Unknown AST Node\n";
    }
}


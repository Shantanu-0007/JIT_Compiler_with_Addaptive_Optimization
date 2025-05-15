#include "ast.h"

NumberNode::NumberNode(double val) : value(val) {}
void NumberNode::print() const {
    std::cout << value;
}
std::string NumberNode::toString() const {
    return std::to_string(value);
}

IdentifierNode::IdentifierNode(const std::string& name) : name(name) {}
void IdentifierNode::print() const {
    std::cout << name;
}
std::string IdentifierNode::toString() const {
    return name;
}

BinaryOpNode::BinaryOpNode(std::string op, std::unique_ptr<ASTNode> lhs, std::unique_ptr<ASTNode> rhs)
    : op(std::move(op)), lhs(std::move(lhs)), rhs(std::move(rhs)) {}

void BinaryOpNode::print() const {
    std::cout << "(";
    lhs->print();
    std::cout << " " << op << " ";
    rhs->print();
    std::cout << ")";
}

std::string BinaryOpNode::toString() const {
    return "(" + lhs->toString() + " " + op + " " + rhs->toString() + ")";
}
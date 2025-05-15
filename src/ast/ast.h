#ifndef AST_H
#define AST_H

#include <string>
#include <memory>
#include <iostream>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print() const = 0;
    virtual std::string toString() const = 0;
};

class AssignmentNode : public ASTNode {
    std::unique_ptr<ASTNode> lhs;
    std::unique_ptr<ASTNode> rhs;

public:
    AssignmentNode(std::unique_ptr<ASTNode> lhs, std::unique_ptr<ASTNode> rhs)
        : lhs(std::move(lhs)), rhs(std::move(rhs)) {}

    const ASTNode* getLeft() const { return lhs.get(); }
    const ASTNode* getRight() const { return rhs.get(); }

    void print() const override {
        std::cout << "Assignment:" << std::endl;
        std::cout << "  LHS: ";
        lhs->print();
        std::cout << "  RHS: ";
        rhs->print();
    }

    std::string toString() const override {
        return lhs->toString() + " = " + rhs->toString();
    }
};


class NumberNode : public ASTNode {
    double value;
public:
    NumberNode(double val);
    void print() const override;
    std::string toString() const override;
    double getValue() const { return value; }
};

class IdentifierNode : public ASTNode {
    std::string name;
public:
    IdentifierNode(const std::string& name);
    void print() const override;
    std::string toString() const override;
    const std::string& getName() const { return name; }
};

class BinaryOpNode : public ASTNode {
    std::string op;
    std::unique_ptr<ASTNode> lhs;
    std::unique_ptr<ASTNode> rhs;
public:
    BinaryOpNode(std::string op, std::unique_ptr<ASTNode> lhs, std::unique_ptr<ASTNode> rhs);
    void print() const override;
    std::string toString() const override;
    const std::string& getOp() const { return op; }
    const ASTNode* getLeft() const { return lhs.get(); }
    const ASTNode* getRight() const { return rhs.get(); }
};

class UnaryOpNode : public ASTNode {
    std::string op;
    std::unique_ptr<ASTNode> operand;
public:
    UnaryOpNode(std::string op, std::unique_ptr<ASTNode> operand)
        : op(std::move(op)), operand(std::move(operand)) {}

    void print() const override {
        std::cout << "UnaryOp: " << op << "\n";
        operand->print();
    }

    std::string toString() const override {
        return "(" + op + operand->toString() + ")";
    }

    const std::string& getOp() const { return op; }
    const ASTNode* getOperand() const { return operand.get(); }
};
class PowerNode : public ASTNode {
public:
    std::shared_ptr<ASTNode> base;
    std::shared_ptr<ASTNode> exponent;
    PowerNode(std::shared_ptr<ASTNode> base, std::shared_ptr<ASTNode> exponent)
        : base(base), exponent(exponent) {}
};

#endif // AST_H
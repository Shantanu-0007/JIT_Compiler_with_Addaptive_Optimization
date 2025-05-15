// src/parser/parser.h
#pragma once
#include "../token/token.h"
#include "../ast/ast.h"
#include <vector>
#include <memory>

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    std::unique_ptr<ASTNode> parseExpression();

private:
    const std::vector<Token>& tokens;
    size_t current;

    Token peek() const;
    Token advance();
    const Token& previous() const;
    bool match(TokenType type);
    bool check(TokenType type) const;

    std::unique_ptr<ASTNode> parsePrimary();
    std::unique_ptr<ASTNode> parseTerm();
    std::unique_ptr<ASTNode> parseFactor();
    std::unique_ptr<ASTNode> parseUnary();

};

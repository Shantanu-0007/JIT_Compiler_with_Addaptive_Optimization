// src/parser/parser.cpp
#include "parser.h"
#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), current(0) {}

Token Parser::peek() const {
    if (current >= tokens.size()) {
        return Token{TokenType::EndOfFile, "", 0, 0};
    }
    return tokens[current];
}

Token Parser::advance() {
    if (current < tokens.size()) {
        return tokens[current++];
    }
    return Token{TokenType::EndOfFile, "", 0, 0};
}


bool Parser::check(TokenType type) const { return peek().type == type; }
bool Parser::match(TokenType type) {
    if (check(type)) {
        advance();
        return true;
    }
    return false;
}

std::unique_ptr<ASTNode> Parser::parseExpression() {
    auto lhs = parseTerm();

    if (match(TokenType::Assign)) {
        auto rhs = parseExpression();
        return std::make_unique<AssignmentNode>(std::move(lhs), std::move(rhs));
    }

    return lhs;
}


std::unique_ptr<ASTNode> Parser::parseTerm() {
    auto node = parseFactor();
    while (match(TokenType::Plus) || match(TokenType::Minus)) {
        std::string op = tokens[current - 1].text;
        auto right = parseFactor();
        node = std::make_unique<BinaryOpNode>(op, std::move(node), std::move(right));
    }
    return node;
}

std::unique_ptr<ASTNode> Parser::parseFactor() {
    auto node = parseUnary();
    while (match(TokenType::Star) || match(TokenType::Slash) || match(TokenType::Pow)) {
        std::string op = tokens[current - 1].text;
        auto right = parsePrimary();
        node = std::make_unique<BinaryOpNode>(op, std::move(node), std::move(right));
    }
    return node;
}
std::unique_ptr<ASTNode> Parser::parseUnary() {
    if (match(TokenType::Plus) || match(TokenType::Minus)) {
        std::string op = tokens[current - 1].text;
        auto operand = parseUnary();
        return std::make_unique<UnaryOpNode>(op, std::move(operand));
    }
    return parsePrimary();
}

std::unique_ptr<ASTNode> Parser::parsePrimary() {
    if (match(TokenType::Number)) {
        return std::make_unique<NumberNode>(std::stod(tokens[current - 1].text));
    } else if (match(TokenType::Identifier)) {
        return std::make_unique<IdentifierNode>(tokens[current - 1].text);
    } else if (match(TokenType::LeftParen)) {
        auto expr = parseExpression();
        if (!match(TokenType::RightParen)) {
            throw std::runtime_error("Expected ')' after expression");
        }
        return expr;
    } else {
        throw std::runtime_error("Unexpected token in expression: " + peek().text);
    }
}


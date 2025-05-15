#pragma once
#include <vector>
#include <string>
#include "token.h"

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();

private:
    char peek();
    char advance();
    void skipWhitespace();
    Token makeIdentifier();
    Token makeNumber();
    Token makeOperator();
    Token makeToken(TokenType type, const std::string& text);

    const std::string source;
    size_t pos;
    int line;
    int column;
};

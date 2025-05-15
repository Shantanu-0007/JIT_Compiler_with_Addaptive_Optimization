#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "../token/token.h"

class Lexer {
public:
    Lexer(const std::string& src);

    std::vector<Token> tokenize();
    char peek() const;
    char advance();
    Token makeToken(TokenType type, const std::string& text);
    void skipWhitespace();

    Token makeIdentifier();
    Token makeNumber();
    Token makeOperator();

private:
    std::string source;
    size_t pos;
    int line;
    int column;
};

#endif // LEXER_H

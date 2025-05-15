#include "lexer.h"
#include <stdexcept>
#include <cctype>
#include "../token/token.h"

Lexer::Lexer(const std::string& src) : source(src), pos(0), line(1), column(1) {}

char Lexer::peek() const {
    return (pos < source.length()) ? source[pos] : '\0';
}

char Lexer::advance() {
    char current = peek();
    pos++;
    column++;
    if (current == '\n') {
        line++;
        column = 1;
    }
    return current;
}

void Lexer::skipWhitespace() {
    while (isspace(peek())) advance();
}

Token Lexer::makeToken(TokenType type, const std::string& text) {
    return Token{ type, text, line, column - static_cast<int>(text.length()) };
}

Token Lexer::makeIdentifier() {
    std::string text;
    while (isalnum(peek()) || peek() == '_')
        text += advance();
    if (text == "if" || text == "while" || text == "return" || text == "int" || text == "main" || text == "else" 
	|| text == "else if" || text == "break" || text == "continue" || text == "switch" || text == "const" || text == "printf")
        return makeToken(TokenType::Keyword, text);
    return makeToken(TokenType::Identifier, text);
}

Token Lexer::makeNumber() {
    std::string text;
    while (isdigit(peek())) text += advance();
    return makeToken(TokenType::Number, text);
}

Token Lexer::makeOperator() {
    char op = advance();
    TokenType type;

    switch (op) {
        case '+': type = TokenType::Plus; break;
        case '-': type = TokenType::Minus; break;
        case '*': type = TokenType::Star; break;
        case '^': type = TokenType::Pow; break;
        case '/': type = TokenType::Slash; break;
        case '(': type = TokenType::LeftParen; break;
        case ')': type = TokenType::RightParen; break;
        default: throw std::runtime_error("Unknown operator: " + std::string(1, op));
    }

    return Token{ type, std::string(1, op), line, column - 1 };
}


std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;

    while (peek() != '\0') {
        skipWhitespace();
        char current = peek();

        if (isalpha(current)) tokens.push_back(makeIdentifier());
        else if (isdigit(current)) tokens.push_back(makeNumber());
        else if (current == '+' || current == '-' || current == '*' || current == '^' || current == '/') tokens.push_back(makeOperator());
        else if (current == '=') tokens.push_back(makeToken(TokenType::Assign, std::string(1, advance())));
        else if (current == '(') tokens.push_back(makeToken(TokenType::LeftParen, std::string(1, advance())));
        else if (current == ')') tokens.push_back(makeToken(TokenType::RightParen, std::string(1, advance())));
        else advance();
    }

    tokens.push_back(makeToken(TokenType::EndOfFile, ""));
    return tokens;
}

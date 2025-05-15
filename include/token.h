#ifndef TOKEN_H
#define TOKEN_H
#pragma once
#include <string>

enum class TokenType {
    Identifier,
    Number,
    Keyword,
    Operator,
    Delimiter,
    Assign,
    Plus,
    Minus,
    Star,
    Slash,
    LeftParen,
    RightParen,
    EndOfFile,
    Unknown
};

struct Token {
    TokenType type;
    std::string text;
    int line;
    int column;
};
#endif
#include "../src/lexer/lexer.h"
#include "../src/ast/ast_printer.h"
#include "../src/parser/parser.h"
#include <iostream>


int main() {
    std::string input = "x + 3 * y";
    Lexer lexer(input);
    auto tokens = lexer.tokenize();

    Parser parser(tokens);
    auto ast = parser.parseExpression();

    printAST(ast.get());
    return 0;
}
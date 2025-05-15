#include "../src/lexer/lexer.h"
#include "../src/parser/parser.h"
#include "../src/ast/ast_printer.h"
#include "../src/tar/tar_printer.h"
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, input);

    Lexer lexer(input);
    auto tokens = lexer.tokenize();
    Parser parser(tokens);
    auto ast = parser.parseExpression();
    std::cout << "ABSTRACT SYNTAX TREE \n" ;
    if (ast) {
        printAST(ast.get());
    } else {
        std::cerr << "Error: AST is null\n";
    }
    return 0;
}

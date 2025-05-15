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
    std::cout << "TOKENS:\n";
    for (const auto& token : tokens) {
        std::cout << "Token: " << token.text << " (type: " << tokenTypeToString(token.type) << ")\n";
    }
    return 0;
}

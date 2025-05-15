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
    std::cout << "TOKENS\n" ;
    for (const auto& token : tokens) {
        std::cout << "Token: " << token.text << " (type: " << tokenTypeToString(token.type) << ")\n";
    }

    Parser parser(tokens);
    auto ast = parser.parseExpression();
    std::cout << "ABSTRACT SYNTAX TREE \n" ;
    if (ast) {
        printAST(ast.get());
    } else {
        std::cerr << "Error: AST is null\n";
    }
    
    std::cout << "3-ADDRESS CODE REPRESENTATION \n" ;
    TACGenerator tacGen;
    TACList tar = tacGen.generate(ast.get());
    for (const auto& instr : tar) {
    if (instr.op == "=") {
        std::cout << instr.result << " = " << instr.arg1 << std::endl;
    } else {
        std::cout << instr.result << " = " << instr.arg1 << " " << instr.op << " " << instr.arg2 << std::endl;
    }
}

    return 0;
}

// src/ir_generator.h
class IRGenerator {
public:
    IRGenerator();
    std::unique_ptr<llvm::Module> generate(ASTNode* root);
private:
    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::IRBuilder<>> builder;
};
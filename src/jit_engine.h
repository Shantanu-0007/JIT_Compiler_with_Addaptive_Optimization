// src/jit_engine.h
class JITEngine {
public:
    void* compile(llvm::Function* function);
    void execute(void* code);
private:
    asmjit::JitRuntime runtime;
};
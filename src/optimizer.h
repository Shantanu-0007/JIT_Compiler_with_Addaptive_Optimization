// src/optimizer.h
class Optimizer {
public:
    void optimize(llvm::Module* module, Profiler& profiler);
private:
    void deadCodeElimination(llvm::Function* function);
    void loopUnrolling(llvm::Function* function);
};
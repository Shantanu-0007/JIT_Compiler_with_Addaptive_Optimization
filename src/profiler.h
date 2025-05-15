// src/profiler.h
class Profiler {
public:
    void instrument(llvm::Function* function);
    void recordExecution(llvm::Function* function);
    bool isHot(llvm::Function* function) const;
private:
    std::unordered_map<llvm::Function*, uint64_t> executionCounts;
};
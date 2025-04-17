#include <asmjit/asmjit.h>

using namespace asmjit;

void jitCompileExpression() {
    JitRuntime rt;
    CodeHolder code;
    code.init(rt.environment());

    x86::Assembler a(&code);
    a.mov(x86::eax, 2);
    a.add(x86::eax, 3);
    a.imul(x86::eax, 4);
    a.ret();

    auto fn = rt.add<int(*)()>(code);
    std::cout << "JIT Compiled Result: " << fn() << std::endl;
    rt.release(fn);
}

int main() {
    jitCompileExpression();
    return 0;
}

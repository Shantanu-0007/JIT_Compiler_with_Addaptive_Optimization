#ifndef RUNTIME_H
#define RUNTIME_H

#include <string>
#include <vector>

class JITRuntime {
public:
    JITRuntime();

    // Compiles and runs the given code, returns output or error message
    std::string compileAndRun(const std::string& code);

    // Returns list of recorded execution times (in milliseconds)
    std::vector<double> getExecutionTimes() const;

private:
    std::vector<double> executionTimes;

    // Example: internal compile and execute helpers
    std::string executeCode(const std::string& code);
};

#endif // RUNTIME_H

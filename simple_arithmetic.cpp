#include <iostream>
#include <sstream>
#include <stack>

int evaluateExpression(const std::string &expr) {
    std::istringstream iss(expr);
    std::stack<int> values;
    char op;
    int num;

    iss >> num;
    values.push(num);

    while (iss >> op >> num) {
        if (op == '+') values.top() += num;
        else if (op == '-') values.top() -= num;
        else if (op == '*') values.top() *= num;
        else if (op == '/') values.top() /= num;
    }

    return values.top();
}

int main() {
    std::string expression = "2 + 3 * 4";
    std::cout << "Interpreted Result: " << evaluateExpression(expression) << std::endl;
    return 0;
}

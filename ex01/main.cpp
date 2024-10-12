#include <iostream>
#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Incorrect number of arguments" << std::endl;
        return 1;
    }

    try {
        std::string rpnExpression = argv[1];
        RPN calculator;
        int result = calculator.evaluateRPN(rpnExpression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

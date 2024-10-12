#include "RPN.hpp"



RPNCalculator::RPNCalculator() {}


RPNCalculator::~RPNCalculator() {}

bool RPNCalculator::isOperator(const std::string &token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPNCalculator::evaluateRPN(const std::string &rpn) {
    std::istringstream iss(rpn);
    std::string token;

    while (iss >> token) {
        if (std::isdigit(token[0])) {
            int num = std::atoi(token.c_str());
            if (num < 0 || num > 9) {
                throw std::runtime_error("Error: Numbers must be between 0 and 9");
            }
            stack.push(num);
        }
        else if (isOperator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: Not enough operands");
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Error: Division by zero");
                stack.push(a / b);
            }
        } else {
            throw std::runtime_error("Invalid token in RPN expression");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error: Invalid RPN expression");
    }

    return stack.top();
}

#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib> 

class RPNCalculator {
private:
    std::stack<int> stack;

public:
    RPNCalculator(); 
    ~RPNCalculator();

    
    bool isOperator(const std::string &token) const;
    int evaluateRPN(const std::string &rpn);
};

#endif 

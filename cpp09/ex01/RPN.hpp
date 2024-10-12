#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib> 

class RPN {
private:
    std::stack<int> stack;

public:
    RPN(); 
    ~RPN();
    RPN& operator=(RPN const & other);
    RPN(RPN const & other);
    bool isOperator(const std::string &token) const;
    int evaluateRPN(const std::string &rpn);
};

#endif 

#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN &cpy) {
    if (this != &cpy) {
        this->stack = cpy.stack;
    }
}

RPN &RPN::operator = (const RPN &copy) {
    (void)copy;
    return *this;
}

RPN::~RPN() { }

int RPN::is_operator(char c) {
    int tmp_number;

    if (stack.size() < 2) {
        std::cout << "Error\n";
        exit(1);
    }

    if (c == '+') {
        tmp_number = stack.top();
        stack.pop();
        tmp_number = stack.top() + tmp_number;
        stack.pop();
        stack.push(tmp_number);
    } else if (c == '-') {
        tmp_number = stack.top();
        stack.pop();
        tmp_number = stack.top() - tmp_number;
        stack.pop();
        stack.push(tmp_number);
    } else if (c == '/') {
        tmp_number = stack.top();
        stack.pop();
        tmp_number = stack.top() / tmp_number;
        stack.pop();
        stack.push(tmp_number);  
    }else if (c == '*') {
        tmp_number = stack.top();
        stack.pop();
        tmp_number = stack.top() * tmp_number;
        stack.pop();
        stack.push(tmp_number);
    } else {
        std::cout << "Error\n";
        exit(1);
    }
    return 1;
}

void RPN::run(std::string str) {

    for (int i = 0; i < (int)str.length(); i++) {

        if (str[i] == ' ')
            continue;
        else if (str[i] >= '0' && str[i] <= '9')
            stack.push(str[i] - '0');
        else
            is_operator(str[i]);
    }
    if (stack.size() != 1) {
        std::cout << "Error\n";
        exit(1);
    }
    std::cout << stack.top() << std::endl;
}
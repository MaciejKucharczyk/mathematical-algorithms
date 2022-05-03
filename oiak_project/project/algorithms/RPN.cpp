
#include "RPN.h"
#include <iostream>
#include <sstream>
RPN::RPN() {}
RPN::~RPN() {}

void RPN::runRPN() {
    std::cout << "Welcome in rpn calculator!\n";
    isFinished = false;
    float result;
    while(!isFinished)
    {
        std::cout << "Enter the +,-,/,* or numbers, when finished press \"=\" \n";
        std::cin >> input;
        if(std::stringstream(input) >> numberValue)
        {
            calculationStack.push(numberValue);
            std::cout << numberValue << " has been added to a stack\n";
        }

        else if(isOperator(input) && isCorrect(calculationStack))
        {
            result = performOperation(input, calculationStack);
            std::cout <<"Now the result = "<< result << std::endl;

        }
        else if(input == "=")
        {
            if(calculationStack.size() > 2)
            {
                std::cout << "Final result = " << result << std::endl;
            }
            isFinished = true;
            break;
        }
        else
        {
            std::cout << "Invalid value\n";
        }
    }

}

bool RPN::isOperator(const std::string &input) {
    if(input == "/" || input == "+" || input == "-" || input == "*"){
        return true;
    }
    return false;
}

float RPN::performOperation(const std::string &operand, std::stack<float> &valueStack) {
    float value1, value2;
    float result;
    value1 = valueStack.top();
    valueStack.pop();
    value2 = valueStack.top();
    valueStack.pop();

    if(operand == "/")
    {
        result = value1 / value2;
        valueStack.push((result));
        return result;
    }
    if(operand == "*")
    {
        result = value1 * value2;
        valueStack.push((result));
        return result;
    }
    if(operand == "+")
    {
        result = value1 + value2;
        valueStack.push((result));
        return result;
    }
    if(operand == "-")
    {
        result = value1 - value2;
        valueStack.push((result));
        return result;
    }

}

bool RPN::isCorrect(const std::stack<float> &valueStack) {
    if(valueStack.size() >= 2)
    {
        return true;
    }
    return false;
}
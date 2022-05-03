#pragma once
#include <stack>
#include <string>
class RPN {
public:
    RPN();
    ~RPN();
    void runRPN();
private:
    std::stack<float> calculationStack;
    std::string input;
    int numberValue;
    bool isFinished;
    bool isOperator(const std::string& input);
    float performOperation(const std::string& operand, std::stack<float> &valueStack);
    bool isCorrect(const std::stack<float> &valueStack); // check if it is correct amount of numbers





};




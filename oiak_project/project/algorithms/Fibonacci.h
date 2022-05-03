#pragma once

class Fibonacci {
public:
    Fibonacci();
    ~Fibonacci();
    void runFibonacci();
    int calcFib(int &number);
private:
    int number;
    int getNumber();
};




#include "Fibonacci.h"
#include <iostream>

Fibonacci::Fibonacci() {}
Fibonacci::~Fibonacci() {}


void Fibonacci::runFibonacci() {
    std::cout << "Welcome to Fibonacci calculator\n";
    number = -1;
    while(number < 0)
    {
        std::cout << "Enter positive int number\n";
        number = getNumber();
        if(number < 0)
        {
            std::cout << "Invalid value\n";
        }
    }
    std::cout << "Result = " << calcFib(number) << std::endl;
}

int Fibonacci::calcFib(int &number) {
    int temp1, temp2, result = 1;
    if(number <= 2)
    {
        result = 1;
    }
    temp1 = 0;
    temp2 = 1;
    for(int i = 2; i <= number; i++)
    {
        result = temp1 + temp2;
        temp1 = temp2;
        temp2 = result;
    }
    return result;
}

int Fibonacci::getNumber() {
    int option = -1;
    std::cin >> option;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore();
        return -1;
    }
    if(option < 0)
    {
        return -1;
    }
    return option;
}
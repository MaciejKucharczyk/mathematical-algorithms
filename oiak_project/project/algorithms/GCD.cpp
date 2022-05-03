

#include "GCD.h"
#include <iostream>
GCD::GCD() {}
GCD::~GCD() {}

void GCD::runGCD() {
    std::cout << "Welcome to GCD calculator\n";
    firstNum = -1;
    secondNum = -1;
    while(firstNum < 0)
    {
        std::cout << "Enter first positive int number\n";
        firstNum = getNumber();
        if(firstNum < 0)
        {
            std::cout << "Invalid value\n";
        }
    }
    while(secondNum < 0)
    {
        std::cout << "Enter second positive int number\n";
        secondNum = getNumber();
        if(secondNum < 0)
        {
            std::cout << "Invalid value\n";
        }
    }

    std::cout << "Result = " << calcGCD(firstNum, secondNum) << std::endl;

}
int GCD::calcGCD(int &firstNum, int &secondNum) {
    int temp;
    while(secondNum != 0)
    {
        temp = firstNum % secondNum;
        firstNum = secondNum;
        secondNum = temp;
    }
    return firstNum;
}

int GCD::getNumber() {
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

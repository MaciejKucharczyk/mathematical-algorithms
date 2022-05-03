#pragma once


class GCD {
public:
    GCD();
    ~GCD();
    void runGCD();
    int calcGCD(int &firstNum, int &secondNum);
private:
    int getNumber();
    int firstNum;
    int secondNum;
};




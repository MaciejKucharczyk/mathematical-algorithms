
#include "AutomaticTests.h"
#include "algorithms/GCD.h"
#include "algorithms/Fibonacci.h"
#include "algorithms/SystemConversion.h"
#include <windows.h>
#include <string>
#include <numeric>
using namespace std;
AutomaticTests::AutomaticTests() {
    srand(time(nullptr));
}
AutomaticTests::~AutomaticTests() {
    delete this->timer;
}



void AutomaticTests::gcdTest() {
    int value1 = -1, value2 = -1;
    fileName = "C:/Users/majka/OneDrive/Pulpit/pwr/IVSEM/OiAK/projekt/oiak_project/project/output/gcdTest.csv";
    resultFile.open(fileName, ios::app);
    GCD *gcd = nullptr;
    double time = 0;
    for(size_t i = 0; i < generationCounter; i++)
    {
        gcd = new GCD();
        value1 = rand() %(maxData + 1);
        value2 = rand() %(maxData + 1);
        this->timer->start();
        gcd->calcGCD(value1, value2);
        this->timer->stop();
        cout << timer->result() << endl;
        resultFile << "gcd " << timer->result() << endl;
    }
    resultFile.close();
}
void AutomaticTests::fibTest() {
    int value = -1;
    fileName = "C:/Users/majka/OneDrive/Pulpit/pwr/IVSEM/OiAK/projekt/oiak_project/project/output/fibTest.csv";
    resultFile.open(fileName, ios::app);
    Fibonacci *fib = nullptr;
    double time = 0;
    for(size_t i = 0; i < generationCounter; i++)
    {
        fib = new Fibonacci();
        value = rand() %(maxData + 1);
        this->timer->start();
        fib->calcFib(value);
        this->timer->stop();
        cout << timer->result() << endl;
        resultFile << "fib " << timer->result() << endl;
    }
    resultFile.close();
}

void AutomaticTests::decToBinTest() {
    int value = -1;
    fileName = "C:/Users/majka/OneDrive/Pulpit/pwr/IVSEM/OiAK/projekt/oiak_project/project/output/binToDecTest.csv";
    resultFile.open(fileName, std::ios::app);
    SystemConversion *numeric = nullptr;
    double time = 0;
    for(size_t i = 0; i < generationCounter; i++)
    {
        numeric = new SystemConversion();
        value = rand() %(maxData + 1);
        this->timer->start();
        numeric->decToBin(value);
        this->timer->stop();
        std::cout << timer->result() << std::endl;
        resultFile << "fib " << timer->result() << std::endl;
    }
    resultFile.close();
}
void AutomaticTests::decToHexTest() {
    int value = -1;
    fileName = "C:/Users/majka/OneDrive/Pulpit/pwr/IVSEM/OiAK/projekt/oiak_project/project/output/binToHexTest.csv";
    resultFile.open(fileName, std::ios::app);
    SystemConversion *numeric = nullptr;
    double time = 0;
    for(size_t i = 0; i < generationCounter; i++)
    {
        numeric = new SystemConversion();
        value = rand() %(maxData + 1);
        this->timer->start();
        numeric->decToHex(value);
        this->timer->stop();
        std::cout << timer->result() << std::endl;
        resultFile << "fib " << timer->result() << std::endl;
    }
    resultFile.close();
}


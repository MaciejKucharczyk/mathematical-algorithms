#pragma once
#include <iostream>
#include <iomanip>
#include<cstdlib>
#include<ctime>
#include <stdexcept>
#include <fstream>
#include "other/Timer.h"

class AutomaticTests {
public:
    AutomaticTests();
    ~AutomaticTests();
    void gcdTest();
    void rpnTest();
    void fibTest();
    void binToHexTest();
    void binToDecTest();
    void hexToBinTest();
    void hexToDecTest();
    void decToBinTest();
    void decToHexTest();
private:
    std::ofstream resultFile;
    std::string fileName;
    const size_t generationCounter = 200;
    const size_t maxData = 100;
    Timer* timer = new Timer;
};





#include <iostream>
#include <string>
#include <sstream>

class SystemConversion {
public:
    SystemConversion();
    ~SystemConversion();
    std::string binToHex(int &number);
    void runBinToHex();
    int binToDec(int &number);
    void runBinToDec();
    std::string hexToBin(std::string &number);
    void runHexToBin();
    int hexToDec(std::string &number);
    void runHexToDec();
    int decToBin(int &number);
    void runDecToBin();
    std::string decToHex(int &number);
    void runDecToHex();
    private:
    std::string input;
    int inputNumber;
    bool isBinary(std::string &number);
    bool isHex(std::string &number);
    int stringToInt(std::string &number);
    int getPositiveNumber();




};




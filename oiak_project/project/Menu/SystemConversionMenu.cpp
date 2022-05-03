
#include "SystemConversionMenu.h"
#include "../algorithms/SystemConversion.h"
#include <iostream>
using namespace std;

SystemConversionMenu::SystemConversionMenu() {}
SystemConversionMenu::~SystemConversionMenu() {}
SystemConversion *conv = new SystemConversion();
void SystemConversionMenu::conversionMenu() {
    isFinished = false;
    while(!isFinished){
        cout << "Select an operation:\n";
        cout << "1. Bin to Hex\n";
        cout << "2. Bin to Dec\n";
        cout << "3. Hex to Bin\n";
        cout << "4. Hex to Dec\n";
        cout << "5. Dec to Bin\n";
        cout << "6. Dec to Hex\n";
        cout << "0. Back to te previous menu\n";
        selectedOption = getNumber();

        switch (selectedOption) {
            case 1:
                conv->runBinToHex();
                break;
            case 2:
                conv->runBinToDec();
                break;
            case 3:
                conv->runHexToBin();
                break;
            case 4:
                conv->runHexToDec();
                break;
            case 5:
                conv->runDecToBin();
                break;
            case 6:
                conv->runDecToHex();
                break;
            case 0:
                isFinished = true;
                break;
            default:
                cout << "Invalid value\n";
                break;

        }
    }
}

int SystemConversionMenu::getNumber() {


        int option = -1;
        cin >> option;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            return -1;
        }
        return option;
}

#include "AutoTestMenu.h"
#include <iostream>
#include "../AutomaticTests.h"

using namespace std;
AutomaticTests *autotest = new AutomaticTests();
AutoTestMenu::AutoTestMenu() {}
AutoTestMenu::~AutoTestMenu() {}

void AutoTestMenu::run() {
    isFinished = false;
    while(!isFinished){
        printMenu();
        selectedOption = getSelectedOption();

        switch (selectedOption) {
            case 1:
            autotest->gcdTest();
                break;
            case 2:
                break;
            case 3:
                autotest->fibTest();
                break;
            case 8:
                autotest->decToBinTest();
                break;
            case 9:
                autotest->decToHexTest();
            case 0:
                isFinished = true;
                break;
            default:
                cout << "Invalid value\n";
                break;

        }
    }
}
void AutoTestMenu::printMenu() {
    cout << "Select auto test:\n";
    cout << "1. gcd\n";
    cout << "2. rpn\n";
    cout << "3. fibonacci\n";
    cout << "4. Bin to Hex\n";
    cout << "5. Bin to Dec\n";
    cout << "6. Hex to Bin\n";
    cout << "7. Hex to Dec\n";
    cout << "8. Dec to Bin\n";
    cout << "9. Dec to Hex\n";
    cout << "0. Exit\n";
}

int AutoTestMenu::getSelectedOption() {
    int option = -1;
    cin >> option;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        return -1;
    }
    return option;
}
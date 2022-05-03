
#include "Menu.h"
#include "../algorithms/RPN.h"
#include "../algorithms/GCD.h"
#include "../algorithms/Fibonacci.h"
#include "SystemConversionMenu.h"
#include "AutoTestMenu.h"
#include <iostream>
using namespace std;
AutoTestMenu *testMenu = new AutoTestMenu();
Menu::Menu() {}
Menu::~Menu() {}

void Menu::run() {
    isFinished = false;
    while(!isFinished){
        printMenu();
        selectedOption = getSelectedOption();

        switch (selectedOption) {
            case 1:
            {
                RPN *rpn = new RPN();
                rpn->runRPN();
                delete rpn;
            }
                break;
            case 2:
            {
                GCD *gcd = new GCD();
                gcd->runGCD();
                delete gcd;
            }
                break;
            case 3:
            {
                Fibonacci *fib = new Fibonacci();
                fib->runFibonacci();
                delete fib;
            }
                break;
            case 4:
            {
                SystemConversionMenu *conversion = new SystemConversionMenu();
                conversion->conversionMenu();
                delete conversion;
            }
                break;
            case 5:
                testMenu->run();
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

void Menu::printMenu() {
    cout << "Select an operation:\n";
    cout << "1. Reverse Polish Notation\n";
    cout << "2. Greatest common division\n";
    cout << "3. Fibonacci number\n";
    cout << "4. Number system conversion\n";
    cout << "5. Automatic tests\n";
    cout << "0. Exit\n";

}

int Menu::getSelectedOption() {
    int option = -1;
    cin >> option;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        return -1;
    }
    return option;
}

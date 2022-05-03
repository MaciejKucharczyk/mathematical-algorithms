
#pragma once
#include <string>

class Menu {
public:
    Menu();
    ~Menu();
    void run();

private:
    //unsigned int value1, value2;
    int getSelectedOption();
    //unsigned int getNumber();
    void printMenu();
    bool isFinished;
    int selectedOption;





};




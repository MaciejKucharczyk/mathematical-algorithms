#pragma once

class AutoTestMenu {
public:
    AutoTestMenu();
    ~AutoTestMenu();
    void run();
private:
    void printMenu();
    bool isFinished;
    int getSelectedOption();
    int selectedOption;

};



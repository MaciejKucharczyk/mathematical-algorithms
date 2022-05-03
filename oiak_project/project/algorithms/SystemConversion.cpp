
#include "SystemConversion.h"

SystemConversion::SystemConversion() {}
SystemConversion::~SystemConversion() {}
using namespace std;
string SystemConversion::binToHex(int &number) {
    int hexValue = 0, decValue = 0;
    decValue = binToDec(number);
    string myHex, hexResult;
    while (decValue != 0)
    {
        hexValue = decValue % 16;
        if(hexValue > 9)
        {
            myHex.push_back((char)(hexValue + 55));
        }
        else
        {
            myHex.push_back((char)(hexValue + 48));
        }
        decValue = decValue / 16;
    }

    for(int j = myHex.size() - 1; j >= 0; j--)
    {
        hexResult.push_back(myHex[j]);
    }
    return hexResult;
}

void SystemConversion::runBinToHex() {
    cout << "Welcome to the binary to hexadecimal converter\n";
    string binaryNum;
    binaryNum = "2";
    while(!isBinary(binaryNum))
    {
        cout << "Enter a binary number\n";
        cin >> binaryNum;
        if(!isBinary(binaryNum))
        {
            cout << "Invalid value\n";
        }
    }
    int binNum;
    binNum = stringToInt(binaryNum);
    cout << "Result = " << binToHex(binNum) << endl;

}
void SystemConversion::runBinToDec() {
    cout << "Welcome to the binary to decimal converter\n";
    string binaryNum;
    binaryNum = "2";
    while(!isBinary(binaryNum))
    {
        cout << "Enter a binary number\n";
        cin >> binaryNum;
        if(!isBinary(binaryNum))
        {
            cout << "Invalid value\n";
        }
    }
    int binNum;
    binNum = stringToInt(binaryNum);
    cout << "Result = " << binToDec(binNum) << endl;

}
void SystemConversion::runHexToBin() {
    cout << "Welcome to the hexadecimal to binary converter\n";
    string hexNum;
    hexNum = "t";
    while(!isHex(hexNum))
    {
        cout << "Enter a hexadecimal number\n";
        cin >> hexNum;
        if(!isHex(hexNum))
        {
            cout << "Invalid value\n";
        }
    }
    cout << "Result = " << hexToBin(hexNum) << endl;

}

int SystemConversion::binToDec(int &number) {
    int decValue = 0, i = 1, r;
    while (number > 0)
    {
        r = number % 2;
        decValue = decValue + r * i;
        i = i * 2;
        number = number / 10;
    }
    return decValue;

}
string SystemConversion::hexToBin(string &number) {
    int i = 0;
    string binaryNum;
    while (number[i]) {

        switch (number[i]) {
            case '0':
                binaryNum = binaryNum + "0000";
                break;
            case '1':
                binaryNum = binaryNum + "0001";
                break;
            case '2':
                binaryNum = binaryNum + "0010";
                break;
            case '3':
                binaryNum = binaryNum + "0011";
                break;
            case '4':
                binaryNum = binaryNum + "0100";
                break;
            case '5':
                binaryNum = binaryNum + "0101";
                break;
            case '6':
                binaryNum = binaryNum + "0110";
                break;
            case '7':
                binaryNum = binaryNum + "0111";
                break;
            case '8':
                binaryNum = binaryNum + "1000";
                break;
            case '9':
                binaryNum = binaryNum + "1001";
                break;
            case 'A':
            case 'a':
                binaryNum = binaryNum + "1010";
                break;
            case 'B':
            case 'b':
                binaryNum = binaryNum + "1011";
                break;
            case 'C':
            case 'c':
                binaryNum = binaryNum + "1100";
                break;
            case 'D':
            case 'd':
                binaryNum = binaryNum + "1101";
                break;
            case 'E':
            case 'e':
                binaryNum = binaryNum + "1110";
                break;
            case 'F':
            case 'f':
                binaryNum = binaryNum + "1111";
                break;
            default:
                cout << "Invalid value\n";
        }
        i++;
    }
    return binaryNum;

}

int SystemConversion::hexToDec(string &number) {
    int len = number.size();
    int base = 1;
    int decValue = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (number[i] >= '0' && number[i] <= '9') {
            decValue += (int(number[i]) - 48) * base;
            base = base * 16;
        }
        else if (number[i] >= 'A' && number[i] <= 'F') {
            decValue += (int(number[i]) - 55) * base;
            base = base * 16;
        }
    }
    return decValue;
}

void SystemConversion::runHexToDec() {
    cout << "Welcome to the hexadecimal to decimal converter\n";
    string hexNum;
    hexNum = "t";
    while(!isHex(hexNum))
    {
        cout << "Enter a hexadecimal number\n";
        cin >> hexNum;
        if(!isHex(hexNum))
        {
            cout << "Invalid value\n";
        }
    }
    cout << "Result = " << hexToDec(hexNum) << endl;

}

int SystemConversion::decToBin(int &number) {
    int binary = 0, r, tmp = 1;
    while (number != 0) {
        r = number % 2;
        binary = binary + (r * tmp);
        number = number / 2;
        tmp *= 10;
    }
    return binary;
}
string SystemConversion::decToHex(int &number) {
    int r;
    string result;
    while (number > 0) {
        r = number % 16;
        if (r > 9) {
            switch (r) {
                case 10:
                    result = result + "A";
                    break;
                case 11:
                    result = result + "B";
                    break;
                case 12:
                    result = result + "C";
                    break;
                case 13:
                    result = result + "D";
                    break;
                case 14:
                    result = result + "E";
                    break;
                case 15:
                    result = result + "F";
                    break;
            }
        }
        else {
            result.push_back(char(r + 48));
        }
        number = number / 16;
    }
    reverse(result.begin(), result.end());
    return result;
}

void SystemConversion::runDecToHex() {
    std::cout << "Welcome to the decimal to binary converter\n";
    inputNumber = -1;
    while(inputNumber < 0)
    {
        std::cout << "Enter positive int number\n";
        inputNumber = getPositiveNumber();
        if(inputNumber < 0)
        {
            std::cout << "Invalid value\n";
        }
    }
    cout << "Result = " << decToHex(inputNumber) << endl;
}
void SystemConversion::runDecToBin() {
    std::cout << "Welcome to the decimal to binary converter\n";
    inputNumber = -1;
    while(inputNumber < 0)
    {
        std::cout << "Enter positive int number\n";
        inputNumber = getPositiveNumber();
        if(inputNumber < 0)
        {
            std::cout << "Invalid value\n";
        }
    }
    cout << "Result = " << decToBin(inputNumber) << endl;
}
bool SystemConversion::isBinary(string &number) {
    for(int i = 0 ; i < number.size() ; i++)
        if(number[i] > '1') {
            return false;
        }
    return true;
}
bool SystemConversion::isHex(string &number) {
    for(int i = 0; i < number.size(); i++)
    {
        if(!isxdigit(number[i]))
        {
            return false;
        }
    }
    return true;
}
int SystemConversion::getPositiveNumber() {
    int option = -1;
    cin >> option;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        return -1;
    }
        if(option < 0)
        {
            return -1;
        }
        return option;
}

int SystemConversion::stringToInt(string &number) {
    return stoi(number);
}



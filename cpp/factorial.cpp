#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

//typedef std::chrono::high_resolution_clock Time;
//typedef std::chrono::milliseconds ms;

long long unsigned int x, num;
long long unsigned int value = 996987;

void AddToFile(string filename, float time)
{
    fstream file;
    file.open(filename, ios::out | ios::app);
    file << time << endl;
    file.close();
}

int Factorial(int val)
{
    
    long long unsigned int result = 1;
    //int multiply = value;
    if(val==0)
        return val; 
    for(int i=1; i<=val; i++)
    {
        result=result*i;
    }

    return result;
}

int main()
{
    string filename="Factorial.csv";
    cout<<"Algorytm: Silnia "<< value <<endl;
    x = Factorial(value);
    cout <<"Wynik: "<< x << endl;
    fstream file;
    file.open(filename, ios::out | ios::app);
    file << endl << "Silnia "<< value << endl;
    file.close();
   
  for(int i=0; i<10; i++)
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        x = Factorial(value);
        auto endTime = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
        AddToFile(filename, time);
        cout<<"Czas: "<<time<<endl;
    }
    return 0;
}
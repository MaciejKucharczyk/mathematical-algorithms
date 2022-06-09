#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;

extern "C" int Silnia();

int x, num;
int value = 959863;

void AddToFile(string filename, float time)
{
    fstream file;
    file.open(filename, ios::out | ios::app);
    file << time << endl;
    file.close();
}

int main()
{
    string filename="Silnia.csv";
    cout<<"Algorytm: Silnia "<< value <<endl;

    x = Silnia();
    // time = getCurrentTime() - startTime;
    cout <<"Wynik: "<< x << endl;
    fstream file;
    file.open(filename, ios::out | ios::app);
    file << endl << "Silnia "<< value << endl;
    file.close();
   
   for(int i=0; i<10; i++)
    {
        //auto startTime, endTime;
        //cout<<"Wprowadz liczbe: "<<endl;
        //cin>>num;
        //startTime = getCurrentTime();
        auto startTime = std::chrono::high_resolution_clock::now();
        x = Silnia();
        auto endTime = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
        AddToFile(filename, time);
        cout<<"Czas: "<<time<<endl;
    }
    return 0;
}
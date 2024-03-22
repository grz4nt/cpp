#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    int *ptrInt;
    ptrInt = new int;

    double *ptrDouble;
    ptrDouble = new double;

    float *ptrFloat;
    ptrFloat = new float;

    const int rozmiarTablicy = 50;
    int *tablicaInt = new int[rozmiarTablicy];

    *ptrInt = 32;
    *ptrDouble = 128.256512;
    *ptrFloat = 64.128;

    for (int i = 0; i < rozmiarTablicy; i++) {
    tablicaInt[i] = rand() % 1001;
}

std::cout << "Zawartosc zmiennej typu int: " << *ptrInt << std::endl;
std::cout << "Zawartosc zmiennej typu double: " << *ptrDouble << std::endl;
std::cout << "Zawartosc zmiennej typu float: " << *ptrFloat << std::endl;
std::cout << "Zawartość tablicy z liczbami typu int: \n";
for (int i = 0; i < rozmiarTablicy; i++) {
    std::cout << tablicaInt[i] << " ";
    if (i % 10 == 9) std:cout << "\n";
    }
std::cout << std::endl;

    delete ptrInt;
    delete ptrDouble;
    delete ptrFloat;
    delete []tablicaInt;

return 0;
}
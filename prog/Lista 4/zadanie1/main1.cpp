#include "funkcje1.h"
#include <iostream>

int main() {
    char wybor;
    do {
        wykonajOperacje();
        std::cout << "Czy chcesz kontynuowac? (t/n): ";
        std::cin >> wybor;
    } while (wybor == 't' || wybor == 'T');
    return 0;
}
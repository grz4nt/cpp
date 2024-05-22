#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

class Statystyki {
public:
    static int minimum(const std::vector<int>& liczby) {
        return *std::min_element(liczby.begin(), liczby.end());
    }

    static int maksimum(const std::vector<int>& liczby) {
        return *std::max_element(liczby.begin(), liczby.end());
    }

    static double srednia(const std::vector<int>& liczby) {
        return std::accumulate(liczby.begin(), liczby.end(), 0.0) / liczby.size();
    }

    static double mediana(std::vector<int>& liczby) {
        std::sort(liczby.begin(), liczby.end());
        if (liczby.size() % 2 == 0)
            return (liczby[liczby.size()/2 - 1] + liczby[liczby.size()/2]) / 2.0;
        else
            return liczby[liczby.size()/2];
    }

    static int dominanta(const std::vector<int>& liczby) {
        std::vector<int> liczniki(*std::max_element(liczby.begin(), liczby.end()) + 1, 0);
        for (int liczba : liczby)
            liczniki[liczba]++;
        int dominanta = 0;
        int max_licznik = 0;
        for (int i = 0; i < liczniki.size(); i++) {
            if (liczniki[i] > max_licznik) {
                max_licznik = liczniki[i];
                dominanta = i;
            }
        }
        return dominanta;
    }
};

int main () {
    std::vector<int> liczby = {1, 2, 3, 7, 4, 6, 1, 8, 3, 6, 7, 3, 7, 3, 1, 3, 4, 9, 10, 11, 12, 11, 14, 15, 16, 17, 18, 13, 20, 7, 6, 13, 21, 22, 23};
    std::cout << "Minimum: " << Statystyki::minimum(liczby) << std::endl;
    std::cout << "Maksimum: " << Statystyki::maksimum(liczby) << std::endl;
    std::cout << "Srednia: " << Statystyki::srednia(liczby) << std::endl;
    std::cout << "Mediana: " << Statystyki::mediana(liczby) << std::endl;
    std::cout << "Dominanta: " << Statystyki::dominanta(liczby) << std::endl;
    return 0;
}
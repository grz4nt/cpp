#ifndef funkcje_header
#define funkcje_header

#include <vector>

void znajdzMinMax(const std::vector<int> &liczby, int &min, int &max, int &minPoz, int &maxPoz) {
    if (liczby.empty()) {
        min = max = minPoz = maxPoz = -1;
        return;
    }

    min = max = liczby[0];
    minPoz = maxPoz = 0;

    for (int i = 1; i < liczby.size(); i++) {
        if (liczby[i] < min) {
            min = liczby[i];
            minPoz = i;
        } else if (liczby[i] > max) {
            max = liczby[i];
            maxPoz = i;
        }
    }
}

// Funkcja obliczająca średnią wartość w wektorze
double obliczSrednia(const std::vector<int>& liczby) {
    if (liczby.empty()) return 0.0;

    int suma = 0;
    for (int x : liczby) {
        suma += x;
    }

    return static_cast<double>(suma) / liczby.size();
}

// Funkcja znajdująca pozycję danej wartości w wektorze
int znajdzPoz(const std::vector<int> &liczby, int szukanaLiczba) {
    for (int i = 0; i < liczby.size(); i++) {
        if (liczby[i] == szukanaLiczba) {
            return i;
        }
    }
    return -1;
}

#endif

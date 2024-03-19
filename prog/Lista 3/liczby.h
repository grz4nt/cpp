#ifndef liczby_h
#define liczby_h

#include <vector>
#include <climits>

void znajdzMinMax(std::vector<int> &liczby, int &min, int &max, int &minPoz, int &maxPoz) {
    if (liczby.empty()) return;

    min = INT_MAX;
    max = INT_MIN;
    minPoz = 0;
    maxPoz = 0;

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

double obliczSrednia(std::vector<int>& liczby) {
    if (liczby.empty()) return 0;
    int suma = 0;
    for (int x : liczby) suma += x;
    return static_cast<double>(suma) / liczby.size();
}

std::vector<int> znajdzPoz(std::vector<int> &liczby, int szukanaLiczba) {
    std::vector<int> indeksy;
    for (int i = 0; i < liczby.size(); ++i) {
        if (liczby[i] == szukanaLiczba) {
            indeksy.push_back(i);
        }
    }
    return indeksy;
}

#endif
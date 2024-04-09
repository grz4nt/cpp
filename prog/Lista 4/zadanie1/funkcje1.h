#ifndef FUNKCJE1_H
#define FUNKCJE1_H

#include <vector>

struct Macierz {
    std::vector<std::vector<int>> dane;
};

Macierz wczytajMacierz();
Macierz dodajMacierze(const Macierz& A, const Macierz& B);
Macierz odejmijMacierze(const Macierz& A, const Macierz& B);
Macierz pomnozMacierze(const Macierz& A, const Macierz& B);
void wykonajOperacje();

#endif // FUNKCJE1_H
#ifndef FUNKCJE1_H
#define FUNKCJE1_H

#include <vector>

struct Macierz {
    std::vector<std::vector<int>> dane;
    Macierz() {}
    Macierz(int rozmiar) : dane(rozmiar, std::vector<int>(rozmiar)) {}
    Macierz(int wiersze, int kolumny) : dane(wiersze, std::vector<int>(kolumny)) {}
};

int wczytajRozmiar();
Macierz wczytajElementy(int rozmiar);
bool wczytajMacierze(Macierz& A, Macierz& B);
Macierz dodajMacierze(Macierz& A, Macierz& B);
Macierz odejmijMacierze(Macierz& A, Macierz& B);
Macierz roznicaMacierzy(Macierz& A, Macierz& B);
Macierz pomnozMacierze(Macierz& A, Macierz& B);
void wykonajOperacje();

#endif
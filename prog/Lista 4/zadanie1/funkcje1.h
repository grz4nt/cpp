#ifndef FUNKCJE1_H
#define FUNKCJE1_H

#include <vector>

struct Macierz {
    std::vector<std::vector<int>> dane;
    Macierz() {}
    Macierz(int rozmiar) : dane(rozmiar, std::vector<int>(rozmiar)) {}
    Macierz(int wiersze, int kolumny) : dane(wiersze, std::vector<int>(kolumny)) {} // nowy konstruktor
};

int wczytajRozmiar();
Macierz wczytajElementy(int rozmiar);
bool wczytajMacierze(Macierz& A, Macierz& B);
Macierz dodajMacierze(const Macierz& A, const Macierz& B);
Macierz odejmijMacierze(const Macierz& A, const Macierz& B);
Macierz pomnozMacierze(const Macierz& A, const Macierz& B);
void wykonajOperacje();

#endif
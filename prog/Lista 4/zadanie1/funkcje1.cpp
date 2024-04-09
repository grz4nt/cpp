#include "funkcje1.h"
#include <iostream>

Macierz wczytajMacierz() {
    Macierz m;
    int wiersze, kolumny;
    std::cout << "Podaj liczbe wierszy: ";
    std::cin >> wiersze;
    std::cout << "Podaj liczbe kolumn: ";
    std::cin >> kolumny;
    m.dane.resize(wiersze, std::vector<int>(kolumny));
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            std::cin >> m.dane[i][j];
        }
    }
    return m;
}

Macierz dodajMacierze(const Macierz& A, const Macierz& B) {
    Macierz C;
    C.dane.resize(A.dane.size(), std::vector<int>(A.dane[0].size()));
    for (int i = 0; i < A.dane.size(); ++i) {
        for (int j = 0; j < A.dane[0].size(); ++j) {
            C.dane[i][j] = A.dane[i][j] + B.dane[i][j];
        }
    }
    return C;
}

Macierz odejmijMacierze(const Macierz& A, const Macierz& B) {
    Macierz C;
    C.dane.resize(A.dane.size(), std::vector<int>(A.dane[0].size()));
    for (int i = 0; i < A.dane.size(); ++i) {
        for (int j = 0; j < A.dane[0].size(); ++j) {
            C.dane[i][j] = A.dane[i][j] - B.dane[i][j];
        }
    }
    return C;
}

Macierz pomnozMacierze(const Macierz& A, const Macierz& B) {
    Macierz C;
    C.dane.resize(A.dane.size(), std::vector<int>(B.dane[0].size()));
    for (int i = 0; i < A.dane.size(); ++i) {
        for (int j = 0; j < B.dane[0].size(); ++j) {
            for (int k = 0; k < A.dane[0].size(); ++k) {
                C.dane[i][j] += A.dane[i][k] * B.dane[k][j];
            }
        }
    }
    return C;
}

void wykonajOperacje() {
    std::cout << "1. Dodawanie macierzy\n";
    std::cout << "2. Odejmowanie macierzy\n";
    std::cout << "3. Mnozenie macierzy\n";
    int operacja;
    std::cin >> operacja;
    Macierz A = wczytajMacierz();
    Macierz B = wczytajMacierz();
    Macierz C;
    switch (operacja) {
        case 1:
            C = dodajMacierze(A, B);
            break;
        case 2:
            C = odejmijMacierze(A, B);
            break;
        case 3:
            C = pomnozMacierze(A, B);
            break;
        default:
            std::cout << "Nieprawidlowa operacja\n";
            return;
    }
    for (const auto& wiersz : C.dane) {
        for (int liczba : wiersz) {
            std::cout << liczba << ' ';
        }
        std::cout << '\n';
    }
}
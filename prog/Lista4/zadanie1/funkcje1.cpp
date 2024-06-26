#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

typedef std::vector<std::vector<int>> Macierz;

int wczytajWiersze() {
    int wiersze;
    std::cin >> wiersze;
    return wiersze;
}

int wczytajKolumny() {
    int kolumny;
    std::cin >> kolumny;
    return kolumny;
}

Macierz wczytajElementy(int wiersze, int kolumny) {
    Macierz macierz(wiersze, std::vector<int>(kolumny));
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            while (!(std::cin >> macierz[i][j])) {
                std::cout << "Nieprawidlowe dane. Wprowadz liczbe:\n";
                std::cin.clear();
            }
        }
    }
    return macierz;
}

bool wczytajMacierze(Macierz& A, Macierz& B) {
    if (A.empty() || B.empty()) {
        int iloscWierszy, iloscKolumn;
        std::cout << "Podaj ilosc wierszy macierzy: ";
        std::cin >> iloscWierszy;
        std::cout << "Podaj ilosc kolumn macierzy: ";
        std::cin >> iloscKolumn;

        A = Macierz(iloscWierszy, std::vector<int>(iloscKolumn));
        B = Macierz(iloscWierszy, std::vector<int>(iloscKolumn));

        std::cout << "Podaj wartosci macierzy A:\n";
        for (auto& wiersz : A) {
            for (auto& liczba : wiersz) {
                std::cin >> liczba;
            }
        }

        std::cout << "Podaj wartosci macierzy B:\n";
        for (auto& wiersz : B) {
            for (auto& liczba : wiersz) {
                std::cin >> liczba;
            }
        }
    }

    return !A.empty() && !B.empty();
}

Macierz dodajMacierze( Macierz& A,  Macierz& B) {
    Macierz C = A;
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[0].size(); ++j) {
            C[i][j] += B[i][j];
        }
    }
    std::cout << "Wynik dodawania:\n";
    for ( auto& wiersz : C) {
        for ( auto& liczba : wiersz) {
            std::cout << liczba << ' ';
        }
        std::cout << '\n';
    }
    return C;
}

Macierz odejmijMacierze( Macierz& A,  Macierz& B) {
    Macierz C = A;
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[0].size(); ++j) {
            C[i][j] = C[i][j] - B[i][j];
        }
    }
    std::cout << "Wynik odejmowania:\n";
    for ( auto& wiersz : C) {
        for ( auto& liczba : wiersz) {
            std::cout << liczba << ' ';
        }
        std::cout << '\n';
    }
    return C;
}

Macierz rozniceMacierzy( Macierz& A,  Macierz& B) {
    Macierz C = A;
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[0].size(); ++j) {
            C[i][j] = std::abs(C[i][j] - B[i][j]);
        }
    }
    std::cout << "Wynik roznicy:\n";
    for (auto& wiersz : C) {
        for (auto& liczba : wiersz) {
            std::cout << liczba << ' ';
        }
        std::cout << '\n';
    }
    return C;
}

Macierz pomnozMacierze( Macierz& A,  Macierz& B) {
    if (A[0].size() != B.size()) {
        std::cerr << "Nie mozna pomnozyc macierzy (nieprawidlowy rozmiar).\n";
        return Macierz();
    }
    Macierz C(A.size(), std::vector<int>(B[0].size(), 0));
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < B[0].size(); ++j) {
            for (size_t k = 0; k < A[0].size(); ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    std::cout << "Wynik mnozenia:\n";
    for ( auto& wiersz : C) {
        for ( auto& liczba : wiersz) {
            std::cout << liczba << ' ';
        }
        std::cout << '\n';
    }
    return C;
}

void wykonajOperacje() {
    static Macierz A, B;
    Macierz C;
    char wybor;

        std::cout << "1. Wpisz wartosci macierzy\n";
        std::cout << "2. Dodawanie macierzy\n";
        std::cout << "3. Odejmowanie macierzy\n";
        std::cout << "4. Mnozenie macierzy\n";
        std::cout << "5. Roznica macierzy\n";
        std::cout << "Wybierz operacje: ";
        int operacja;
        std::cin >> operacja;

        if (operacja > 1 && operacja < 6 && (A.empty() || B.empty())) {
            wczytajMacierze(A, B);
        }

        switch (operacja) {
            case 1:
                wczytajMacierze(A, B);
                break;
            case 2:
                C = dodajMacierze(A, B);
                break;
            case 3:
                C = odejmijMacierze(A, B);
                break;
            case 4:
                C = pomnozMacierze(A, B);
                break;
            case 5:
                C = rozniceMacierzy(A, B);
                break;
            default:
                std::cerr << "Nieznana operacja: " << operacja << "\n";
                break;
        }
}
#include <iostream>

using namespace std;

const int MAX_SIZE = 20;

// Funkcja do wczytywania macierzy od użytkownika
void wczytajMacierz(int macierz[][MAX_SIZE], int rozmiar) {
    cout << "Wpisz elementy macierzy " << rozmiar << "x" << rozmiar << ":\n";
    for (int i = 0; i < rozmiar; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            cin >> macierz[i][j];
        }
    }
}

// Funkcja do wyświetlania macierzy
void wyswietlMacierz(int macierz[][MAX_SIZE], int rozmiar) {
    cout << "Macierz:\n";
    for (int i = 0; i < rozmiar; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
}

// Funkcja do wyznaczania sumy wartości poniżej przekątnej
int sumaPonizejPrzekatnej(int macierz[][MAX_SIZE], int rozmiar) {
    int suma = 0;
    for (int i = 1; i < rozmiar; ++i) {
        for (int j = 0; j < i; ++j) {
            suma += macierz[i][j];
        }
    }
    return suma;
}

// Funkcja do wyznaczania sumy wartości powyżej przekątnej
int sumaPowyzejPrzekatnej(int macierz[][MAX_SIZE], int rozmiar) {
    int suma = 0;
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = i + 1; j < rozmiar; ++j) {
            suma += macierz[i][j];
        }
    }
    return suma;
}

// Funkcja do wyznaczania sumy wartości wskazanego wiersza
int sumaWiersza(int macierz[][MAX_SIZE], int rozmiar, int wiersz) {
    int suma = 0;
    for (int j = 0; j < rozmiar; ++j) {
        suma += macierz[wiersz][j];
    }
    return suma;
}

// Funkcja do wyznaczania sumy wartości wskazanej kolumny
int sumaKolumny(int macierz[][MAX_SIZE], int rozmiar, int kolumna) {
    int suma = 0;
    for (int i = 0; i < rozmiar; ++i) {
        suma += macierz[i][kolumna];
    }
    return suma;
}

int main() {
    int rozmiar;
    cout << "Podaj rozmiar macierzy (max 20): ";
    cin >> rozmiar;

    if (rozmiar > MAX_SIZE || rozmiar <= 0) {
        cout << "Nieprawidlowy rozmiar macierzy.\n";
        return 1;
    }

    int macierz[MAX_SIZE][MAX_SIZE];
    wczytajMacierz(macierz, rozmiar);

    while (true) {
        wyswietlMacierz(macierz, rozmiar);

        cout << "Suma wartosci ponizej przekatnej: " << sumaPonizejPrzekatnej(macierz, rozmiar) << endl;
        cout << "Suma wartosci powyzej przekatnej: " << sumaPowyzejPrzekatnej(macierz, rozmiar) << endl;

        int nrWiersza, nrKolumny;
        cout << "Podaj numer wiersza: ";
        cin >> nrWiersza;
        cout << "Suma wartosci wiersza " << nrWiersza << ": " << sumaWiersza(macierz, rozmiar, nrWiersza - 1) << endl;

        cout << "Podaj numer kolumny: ";
        cin >> nrKolumny;
        cout << "Suma wartosci kolumny " << nrKolumny << ": " << sumaKolumny(macierz, rozmiar, nrKolumny - 1) << endl;

        char wybor;
        cout << "Czy chcesz wykonac kolejne obliczenia? (T/N): ";
        cin >> wybor;
        if (wybor != 'T' && wybor != 't')
            break;
    }

    return 0;
}

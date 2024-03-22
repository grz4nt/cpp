#include <iostream>

using namespace std;

const int rozmiarMax = 20;

void wczytajMacierz(int macierz[][rozmiarMax], int rozmiar) {
    cout << "Wpisz elementy macierzy " << rozmiar << "x" << rozmiar << ":\n";
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            cin >> macierz[i][j];
        }
    }
}

void wyswietlMacierz(int macierz[][rozmiarMax], int rozmiar) {
    cout << "Macierz:\n";
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
}

int sumaPonizejPrzekatnej(int macierz[][rozmiarMax], int rozmiar) {
    int suma = 0;
    for (int i = 1; i < rozmiar; i++) {
        for (int j = 0; j < i; j++) {
            suma += macierz[i][j];
        }
    }
    return suma;
}

int sumaPowyzejPrzekatnej(int macierz[][rozmiarMax], int rozmiar) {
    int suma = 0;
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = i + 1; j < rozmiar; j++) {
            suma += macierz[i][j];
        }
    }
    return suma;
}

int sumaWiersza(int macierz[][rozmiarMax], int rozmiar, int wiersz) {
    int suma = 0;
    for (int j = 0; j < rozmiar; j++) {
        suma += macierz[wiersz][j];
    }
    return suma;
}

int sumaKolumny(int macierz[][rozmiarMax], int rozmiar, int kolumna) {
    int suma = 0;
    for (int i = 0; i < rozmiar; i++) {
        suma += macierz[i][kolumna];
    }
    return suma;
}

int main() {
    int rozmiar;
    cout << "Podaj rozmiar macierzy (max 20): ";
    cin >> rozmiar;

    if (rozmiar > rozmiarMax || rozmiar <= 0) {
        cout << "Nieprawidlowy rozmiar macierzy.\n";
        return 1;
    }

    int macierz[rozmiarMax][rozmiarMax];
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

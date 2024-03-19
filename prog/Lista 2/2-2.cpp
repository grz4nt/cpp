#include <iostream>
#include <climits>

using namespace std;

const int rozmiar = 15;
int liczbaMin = INT_MAX;
int liczbaMax = INT_MIN;

void znajdzMinMax(int tab[], int rozmiar, int &liczbaMin, int &liczbaMax, int &pozMin, int &pozMax) {
    for (int i = 0; i < rozmiar; i++) {
        if (tab[i] < liczbaMin) {
            liczbaMin = tab[i];
            pozMin = i;
        }
        if (tab[i] > liczbaMax) {
            liczbaMax = tab[i];
            pozMax = i;
        }
    }
}

double srednia(int tab[], int rozmiar) {
    double suma = 0;
    for (int i = 0; i < rozmiar; i++) {
        suma += tab[i];
    }
    return suma / rozmiar;
}

int znajdzPozycje(int tab[], int rozmiar, int x, int pozycje[]) {
    int znalezione = 0;
    for (int i = 0; i < rozmiar; i++) {
        if (tab[i] == x) {
            pozycje[znalezione++] = i;
        }
    }
    return znalezione;
}

int main() {
    int tab[rozmiar];

    cout << "Podaj 15 roznych liczb calkowitych:\n";
    for (int i = 0; i < rozmiar; i++) {
        cin >> tab[i];
    }

    int pozMin, pozMax;
    znajdzMinMax(tab, rozmiar, liczbaMin, liczbaMax, pozMin, pozMax);

    cout << "Najmniejsza liczba: " << liczbaMin << ", znaleziona na indeksie: " << pozMin << '\n';
    cout << "Najwieksza liczba: " << liczbaMax << ", znaleziona na indeksie: " << pozMax << '\n';
    cout << "Srednia wartosc podanych liczb: " << srednia(tab, rozmiar) << '\n';

    int szukanaWartosc;
    cout << "Podaj liczbe, dla ktorej chcesz znalezc indeks: ";
    cin >> szukanaWartosc;
    int pozycje[rozmiar];
    int znalezione = znajdzPozycje(tab, rozmiar, szukanaWartosc, pozycje);
    if (znalezione > 0) {
        cout << "Pozycja (indeks) liczby " << szukanaWartosc << " w tablicy: ";
        for (int i = 0; i < znalezione; i++) {
            if (i < znalezione - 2) cout << pozycje[i] << ", ";
            if (i == znalezione - 1) cout << pozycje[i] << endl;
        }
    }
    else {
        cout << "Wartosc " << szukanaWartosc << " nie wystepuje w tablicy.\n";
    }

    return 0;
}

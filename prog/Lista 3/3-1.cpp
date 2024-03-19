#include <iostream>
#include <vector>
#include "funkcje.h"

using namespace std;

int main() {
    int n;
    cout << "Podaj ilosc liczb calkowitych do wczytania: ";
    cin >> n;

    vector<int> liczby(n);

    cout << "Podaj " << n << " liczb calkowitych:\n";
    for (int i = 0; i < n; ++i) {
        cin >> liczby[i];
    }

    int min, max, minPoz, maxPoz;
    znajdzMinMax(liczby, min, max, minPoz, maxPoz);
    cout << "Najmniejsza liczba: " << min << ", znaleziona na indeksie: " << minPoz << endl;
    cout << "Najwieksza liczba: " << max << ", znaleziona na indeksie: " << maxPoz << endl;

    double srednia = obliczSrednia(liczby);
    cout << "Srednia wartosc wpisanych liczb: " << srednia << endl;

    int szukanaLiczba;
    cout << "Podaj liczbe, aby sprawdzic jej indeks: ";
    cin >> szukanaLiczba;

    vector<int> pozycje = znajdzPoz(liczby, szukanaLiczba);
    if (!pozycje.empty()) {
        cout << "Liczba " << szukanaLiczba << " znajduje sie na indeksach: ";
        for (int i = 0; i < pozycje.size(); ++i) {
            cout << pozycje[i];
            if (i < pozycje.size() - 1) {
                cout << ", ";
            } 
        }
        cout << endl;
    } else {
        cout << "Liczba " << szukanaLiczba << " nie wystepuje w zbiorze." << endl;
    }

    return 0;
}

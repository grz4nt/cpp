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

    // Wywołanie funkcji do znajdowania największej i najmniejszej liczby
    int min, max, minPoz, maxPoz;
    znajdzMinMax(liczby, min, max, minPoz, maxPoz);
    cout << "Najmniejsza liczba: " << min << " na pozycji: " << minPoz << endl;
    cout << "Najwieksza liczba: " << max << " na pozycji: " << maxPoz << endl;

    // Wywołanie funkcji do obliczania średniej wartości
    double srednia = obliczSrednia(liczby);
    cout << "Srednia wartosc: " << srednia << endl;

    // Wywołanie funkcji do znajdowania pozycji wartości podanej przez użytkownika
    int szukanaLiczba;
    cout << "Podaj liczbe, aby sprawdzic jej pozycje: ";
    cin >> szukanaLiczba;
    int pozycja = znajdzPoz(liczby, szukanaLiczba);
    if (pozycja != -1) {
        cout << "Liczba " << szukanaLiczba << " znajduje sie na pozycji " << pozycja << endl;
    } else {
        cout << "Liczba " << szukanaLiczba << " nie wystepuje w zbiorze." << endl;
    }

    return 0;
}

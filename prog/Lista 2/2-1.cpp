#include <iostream>

using namespace std;

// Funkcja obliczająca czas trwania lokaty, aby osiągnąć zadaną wartość odsetek
int findLokataDuration(double poczatkowaKwota, double oprocentowanie, double okresKapitalizacji, double oczekiwaneOdsetki) {
    double kwota = poczatkowaKwota;
    int czas = 0;

    while (kwota < poczatkowaKwota + oczekiwaneOdsetki) {
        kwota += kwota * (oprocentowanie / 100) * (okresKapitalizacji / 12); // obliczenie nowej kwoty po okresie kapitalizacji
        czas += 1; // zwiększenie licznika miesięcy
    }

    return czas;
}

int main() {
    double poczatkowaKwota, oprocentowanie, okresKapitalizacji, oczekiwaneOdsetki;

    // Wczytanie danych od użytkownika
    cout << "Podaj kapital poczatkowy: ";
    cin >> poczatkowaKwota;

    cout << "Podaj oprocentowanie w skali roku (%): ";
    cin >> oprocentowanie;

    cout << "Podaj okres kapitalizacji (w miesiacach): ";
    cin >> okresKapitalizacji;

    cout << "Podaj oczekiwana kwote odsetek: ";
    cin >> oczekiwaneOdsetki;

    // Obliczenie czasu trwania lokaty
    int duration = findLokataDuration(poczatkowaKwota, oprocentowanie, okresKapitalizacji, oczekiwaneOdsetki);

    // Wyświetlenie wyniku
    cout << "Lokata powinna trwac " << duration << " miesiecy, aby osiagnac oczekiwana kwote odsetek." << endl;

    return 0;
}

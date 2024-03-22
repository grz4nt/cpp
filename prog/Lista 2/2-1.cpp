#include <iostream>

using namespace std;

int findLokataDuration(double poczatkowaKwota, double oprocentowanie, double okresKapitalizacji, double oczekiwaneOdsetki) {
    double kwota = poczatkowaKwota;
    int czas = 0;

    while (kwota < poczatkowaKwota + oczekiwaneOdsetki) {
        kwota += kwota * (oprocentowanie / 100) * (okresKapitalizacji / 12);
        czas += 1;
    }

    return czas;
}

int main() {
    double poczatkowaKwota, oprocentowanie, okresKapitalizacji, oczekiwaneOdsetki;

    cout << "Podaj kapital poczatkowy: ";
    cin >> poczatkowaKwota;

    cout << "Podaj oprocentowanie w skali roku (%): ";
    cin >> oprocentowanie;

    cout << "Podaj okres kapitalizacji (w miesiacach): ";
    cin >> okresKapitalizacji;

    cout << "Podaj oczekiwana kwote odsetek: ";
    cin >> oczekiwaneOdsetki;

    int duration = findLokataDuration(poczatkowaKwota, oprocentowanie, okresKapitalizacji, oczekiwaneOdsetki);

    cout << "Lokata powinna trwac " << duration*okresKapitalizacji << " miesiecy, aby osiagnac oczekiwana kwote odsetek." << endl;

    return 0;
}

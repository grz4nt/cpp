#include <iostream>
using namespace std;

int main() {
    int liczby[] = {3, 1, 5, 6, 7, 17, 10, 12, 14, 8};
    int szukanaLiczba = 10;
    int indeks = 0;
    int sof = sizeof(liczby) / sizeof(liczby[0]);
    int min = liczby[0];
    int minInd = 0;
    int max = liczby[sof - 1];
    int maxInd = sof - 1;
    cout << "sof: " << sof << endl;
    double total = 0;

    for (int x : liczby) {
        total += x;
        if (x < min) {
            min = x;
            minInd = indeks;
        }
        if (x > max) {
            max = x;
            maxInd = indeks;
        }
        if (x == szukanaLiczba) {
            cout << "Znaleziono szukana liczbe " << szukanaLiczba << " na indeksie " << indeks << endl;
        }
        indeks++;
    }

    cout << "Max: " << max << ", index: " << maxInd;
    cout << "\nMin: " << min << ", index: " << minInd;
    cout << "\nTotal: " << total << endl;
    auto avg = total / sof;
    cout << "Avg: " << avg << endl;

    return 0;
}

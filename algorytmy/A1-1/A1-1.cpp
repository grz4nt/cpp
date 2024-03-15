#include <iostream>
using namespace std;

unsigned int  silnia(int n) {
    if (n < 2) return 1;
    else return n * silnia(n - 1);
}

int main() {
    int liczba;
    cout << "Podaj liczbe, dla ktorej chcesz obliczyc silnie: ";
    cin >> liczba;

    if (liczba < 0) {
        cout << "Nie można obliczyc silni dla liczby ujemnej.\n";
        return 1;
    }

    cout << "Silnia z " << liczba << " wynosi: " << silnia(liczba) << endl;

    return 0;
}

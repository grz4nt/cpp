#include <iostream>

using namespace std;

int dzielnik(int a, int b) {
    if (b == 0)
        return a;
    else
        return dzielnik(b, a % b);
}

int main() {
    int n1, n2;

    cout << "Podaj dwie liczby calkowite: ";
    cin >> n1 >> n2;

    int wynik = dzielnik(n1, n2);

    cout << "Najwiekszy wspolny dzielnik: " << wynik << endl;

    return 0;
}
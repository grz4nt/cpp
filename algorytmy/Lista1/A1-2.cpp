#include <iostream>

using namespace std;

void poziom(int x) {
    if (x > 0) {
    cout << "*";
        poziom(x - 1);
    }
    else return;
}

void trojkat(int n) {
    if (n > 0) {
        poziom(n);
        cout << endl;
        trojkat(n - 1);
    }
    else return;
}

int main() {
    int n;
    cout << "Podaj n: ";
    cin >> n;
    if (n > 0 && n < 50) {
        cout << "Trojkat o wysokosci " << n << ":" << endl;
        trojkat(n);
    }
    else {
        cout << "Podaj liczbe z przedzialu (0, 50)" << endl;
        return 0;
    }
    return 0;
}
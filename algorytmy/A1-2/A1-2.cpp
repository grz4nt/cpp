#include <iostream>

using namespace std;

void poziom(int x) {
    if (x == 0) {
        return;
    }
    else {
        cout << "*";
        poziom(x - 1);
    }
}

void trojkat(int n, int i=0) {
    if (i == n) {
        return;
    }
    else {
        poziom(n - i);
        cout << endl;
        trojkat(n, i + 1);
    }
}

int main() {
    int n;
    cout << "Podaj n: ";
    cin >> n;
    trojkat(n);
    return 0;
}
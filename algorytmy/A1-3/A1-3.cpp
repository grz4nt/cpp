#include <iostream>

using namespace std;


int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Podaj liczbe calkowita n: ";
    cin >> n;

    if (n < 0) {
        cerr << "Liczba musi byc wieksza od 0" << endl;
        return 1;
    }

    int result = fibonacci(n);
    cout << "N-ty element ciagu Fibonacciego: " << result << endl;

    return 0;
}

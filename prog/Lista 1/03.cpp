#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "Podaj liczbe N: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            if (j % 2 == 0)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
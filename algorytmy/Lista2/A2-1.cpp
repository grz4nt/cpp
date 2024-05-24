#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int rozmiar = 10;

void element(int a[], int i = 0)
{
    if (i < rozmiar)
    {
        cout << "a[" << i << "]: " << *(&a[0] + i) << endl;
        element(a, i + 1);
    }
}

int main()
{
    srand(time(nullptr));
    int a[rozmiar];
    cout << "Losowe wartosci w tablicy:\n";
    for (int i = 0; i < rozmiar; i++)
    {
        a[i] = rand() % 100 + 1;
        cout << i << ": " << a[i] << endl;
    }
    cout << "Odwolania do wartosci w tablicy:" << endl;
    element(a);
    return 0;
}
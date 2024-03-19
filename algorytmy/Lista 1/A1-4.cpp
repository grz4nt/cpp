#include <iostream>
#include <cstdlib> // zawiera funkcje rand() i srand()
#include <ctime>   // zawiera funkcje time()

using namespace std;

// Funkcja rekurencyjna przeszukująca tablicę w poszukiwaniu maksymalnego elementu
int findMaxRecursive(int arr[], int size, int maxSoFar) {
    if (size == 0)
        return maxSoFar;
    else
        return findMaxRecursive(arr + 1, size - 1, max(arr[0], maxSoFar));
}

void fillArray(int arr[], int size) {
    if (size == 0)
        return;
    else {
        arr[size - 1] = rand() % 101;
        fillArray(arr, size - 1);
    }
}

int main() {
    // Inicjalizacja generatora liczb pseudolosowych
    srand(time(nullptr));

    const int size = 50;
    int arr[size];

    // Wypełnienie tablicy losowymi wartościami
    fillArray(arr, size);

    // Wywołanie funkcji rekurencyjnej do znalezienia maksymalnej wartości w tablicy
    int maxElement = findMaxRecursive(arr, size, arr[0]);

    // Wyświetlenie wyniku
    cout << "Maksymalny element w tablicy: " << maxElement << endl;

    return 0;
}

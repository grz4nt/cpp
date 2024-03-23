#include <iostream>

using namespace std;

void przeniesTab(int *tablicaPtr[], int tablica[], int rozmiar){
    for (int i = 0; i < rozmiar; i++) {
        tablicaPtr[i] = &tablica[i];
        cout << "tablicaPtr[" << i << "]: " << *tablicaPtr[i] << "\n";
        }
              
}

void sortujTab(int *tablicaPtr[], int rozmiar) {
    cout << "\nSortowanie tablicy... ";
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (*tablicaPtr[j] > *tablicaPtr[j + 1]) {
                int *temp = tablicaPtr[j];
                tablicaPtr[j] = tablicaPtr[j + 1];
                tablicaPtr[j + 1] = temp;
            }
        }
    }
    cout << "Tablica zostala posortowana.\n" << endl;
}

void wyswietlTab(int *tablicaPtr[], int rozmiar) {
    cout << "Wartosci w tablicy wskaznikow:\n";
    for (int i = 0; i < rozmiar; i++) {
        cout << *tablicaPtr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int rozmiar = 10;
    int tablica[rozmiar] = {2,8,4,1,12,19,24,10,6,5};
    int* tablicaPtr[rozmiar];
    cout << "Wartosci w tablicy:" << endl;
    for (int i = 0; i < rozmiar; i++) {
        cout << "tablica[" << i << "]: " << tablica[i] << "\n";
    }

    przeniesTab(tablicaPtr, tablica, rozmiar);
    sortujTab(tablicaPtr, rozmiar);
    wyswietlTab(tablicaPtr, rozmiar);
    
    cout << "\nZmiana wartosci tablica[0] na 99" << endl;
    tablica[0] = 99;
    wyswietlTab(tablicaPtr, rozmiar);

    return 0;
}
#include <iostream>

using namespace std;

struct Lista {
    int x;
    int p;
    Lista *pop;
};

Lista* dodaj(Lista *pocz, int a) {
    Lista* nowy = new Lista;
    nowy->x = a;
    nowy->p = a*a*a;
    nowy->pop = pocz;
    return nowy;
}

void wypisz(Lista* pocz) {
    Lista *temp = pocz;
    while (temp) {
        cout << temp->x << " " << temp->p << "\n";
        temp = temp->pop;
    }
}

Lista* usun(Lista* pocz) {
    if (pocz) {
        Lista* temp = pocz;
        pocz = pocz->pop;
        delete temp;
        }
    return pocz;
}

Lista* ujemne(Lista* pocz) {
    Lista* temp = pocz;
    while (temp) {
        if (temp->p < 0) {
            cout << temp->p << endl;
        }
        temp = temp->pop;
    }
    return pocz;
}

int main() {
    Lista* pocz = nullptr;
    pocz = dodaj(pocz, -2);
    pocz = dodaj(pocz, 2);
    pocz = dodaj(pocz, -3);
    pocz = dodaj(pocz, 3);
    pocz = dodaj(pocz, -4);
    pocz = dodaj(pocz, 4);
    
    wypisz(pocz);
    cout << "\n";
    pocz = usun(pocz);
    wypisz(pocz);
    
    cout << "\n";
    ujemne(pocz);

    return 0;
}
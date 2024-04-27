#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

struct Osoba {
    int id;
    string imie;
    string nazwisko;
    int wiek;
};

void wypelnijLosowymi(Osoba osobaTablica[], int rozmiar) {
    srand(time(nullptr));
    
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < 6; j++) {
            char litera;
            if (j == 0) {
            litera = (rand() % (90 - 65 + 1)) + 65;
            }
            else {
            litera = (rand() % (121 - 97 + 1)) + 97;
            }
            osobaTablica[i].imie += litera;
        }
        
        for (int j = 0; j < 6; j++) {
            char litera;
            if (j == 0) {
            litera = (rand() % (90 - 65 + 1)) + 65;
            }
            else {
            litera = (rand() % (121 - 97 + 1)) + 97;
            }
            osobaTablica[i].nazwisko += litera;
        }
        
        osobaTablica[i].wiek = rand() % (115 - 18 + 1) + 18;
    }
}

void wypelnijSam(Osoba osobaTablica[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        osobaTablica[i].id = i;
        cout << "ID: " << osobaTablica[i].id + 1 << "\n";
        cout << "Imie: ";
        cin >> osobaTablica[i].imie;
        cout << "Nazwisko: ";
        cin >> osobaTablica[i].nazwisko;
        cout << "Wiek: ";
        cin >> osobaTablica[i].wiek;
        cout << "\n";
    }
}

int main() {
    Osoba *osobaTablica;
    int rozmiar;

    cout << "Wpisz N dla rozmiaru tablicy: ";
    cin >> rozmiar;
    osobaTablica = new Osoba[rozmiar];

    char wybor;
    cout << "Czy wypelnic tablice losowymi danymi? [t/n] ";
    cin >> wybor;
    cout << "\n";

    if (wybor == 't') {
        wypelnijLosowymi(osobaTablica, rozmiar);
        for (int i = 0; i < rozmiar; i++) {
            cout << osobaTablica[i].imie << " " << osobaTablica[i].nazwisko << ", " << osobaTablica[i].wiek << " lat.\n";
        }
    }

    cout << "\nCzy chcesz teraz wypelnic tablice recznie? [t/n] ";
    cin >> wybor;

    if (wybor == 't') {
        wypelnijSam(osobaTablica, rozmiar);
        cout << "\n";
        for(int i = 0; i < rozmiar; i++) {
            osobaTablica[i].id = i;
            cout << osobaTablica[i].imie << " " << osobaTablica[i].nazwisko << ", " << osobaTablica[i].wiek << " lat" << endl;
        }
    }

    delete[] osobaTablica;

    return 0;
}
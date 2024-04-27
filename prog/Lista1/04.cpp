#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int dlugoscZdania(const string& zdanie) {
    return zdanie.length();
}

int znakiBezSpacji(const string& zdanie) {
    int licznik = 0;
    for (char znak : zdanie) {
        if (znak != ' ') {
            licznik++;
        }
    }
    return licznik;
}

int literyBezZnaku(const string& zdanie, char ignoruj) {
    int licznik = 0;
    for (char znak : zdanie) {
        if (znak != ' ' && znak != ignoruj) {
            licznik++;
        }
    }
    return licznik;
}

void wyrazyZdania(const string& zdanie) {
    stringstream strumien(zdanie);
    string wyraz;
    cout << "Wyrazy w zdaniu:" << endl;
    while (getline(strumien, wyraz, ' ')) {
        cout << wyraz << endl;
    }
}

void podzielZdanie(const string& zdanie, char znakPodzialu) {
    stringstream ss(zdanie);
    string podzial;
    cout << "Podziel zdania w oparciu o znak '" << znakPodzialu << "':" << endl;
    while (getline(ss, podzial, znakPodzialu)) {
        size_t poczatek = podzial.find_first_not_of(" \t");
        if (poczatek != string::npos) {
            cout << podzial.substr(poczatek) << endl;
        } else {
            cout << podzial << endl;
        }
    }
}

int main() {
    string zdanie;
    cout << "Podaj zdanie: ";
    getline(cin, zdanie);

    cout << "1. Ilosc wszystkich znakow: " << dlugoscZdania(zdanie) << endl;
    cout << "2. Ilosc liter bez spacji: " << znakiBezSpacji(zdanie) << endl;

    char ignoruj;
    cout << "Podaj znak do pominiecia: ";
    cin >> ignoruj;
    cin.ignore();

    cout << "3. Ilosc liter bez podanego znaku: " << literyBezZnaku(zdanie, ignoruj) << endl;

    wyrazyZdania(zdanie);

    char znakPodzialu;
    cout << "Podaj znak, przez ktory chcesz podzielic zdanie: ";
    cin >> znakPodzialu;
    cin.ignore();

    podzielZdanie(zdanie, znakPodzialu);

    return 0;
}

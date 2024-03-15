#include <iostream>
#include <vector>
using namespace std;


int main() {
    int liczbaOcen;
    cout << "Podaj liczbe ocen do wprowadzenia: ";
    cin >> liczbaOcen;
    vector<double> oceny;
    double sumaOcen = 0.0;

    for (int i = 0; i < liczbaOcen; i++) {
        double ocena;
        cout << "Podaj ocene " << i + 1 << ": ";
        cin >> ocena;
        oceny.push_back(ocena);
        sumaOcen += ocena;
    }

    double srednia = sumaOcen / liczbaOcen;
    cout << "Srednia wypisanych ocen to " << srednia << endl;

    if (srednia > 4.1) {
        cout << "Przysluguje ci stypendium naukowe (srednia 4.1 lub wyzsza)." << endl;
    }
    else {
        cout << "Nie przysluguje ci stypendium naukowe (srednia ponizej 4.1)." << endl;
    }
    return 0;
}

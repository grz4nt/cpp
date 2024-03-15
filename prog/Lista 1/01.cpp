#include <iostream>
#include <cmath>
using namespace std;


const double PI = 3.1415926536;

double KulaObjetosc(double r) {
    return (4.0 / 3.0) * PI * pow(r, 3);
}

double KulaPole(double r) {
    return 4 * PI * pow(r, 2);
}

double ProstopadloscianObjetosc(double a, double b, double c) {
    return a * b * c;
}

double ProstopadloscianPole(double a, double b, double c) {
    return (2 * a * b) + (2* a * c) + (2 * b * c);
}

double StozekObjetosc(double r, double h) {
    return (1.0 / 3.0) * PI * pow(r, 2) * h;
}

double StozekPole(double r, double h) {
    double tworzaca = sqrt(pow(r, 2) + pow(h, 2));
    return PI * r * (r + tworzaca);
}

char wyswietlMenu() {
    char wybor;
    cout << "Wybierz bryle do obliczen:\n"
        << "a. Kula\n"
        << "b. Prostopadloscian\n"
        << "c. Stozek\n"
        << "x. Zakoncz program\n"
        << "Twoj wybor: ";
    cin >> wybor;
    return wybor;
}

void restart() {
    char wybor;
    cout << "\nCzy chcesz kontynuowac? (t/n): ";
    cin >> wybor;
    if (wybor != 't') {
        cout << "Koniec programu." << endl;
        exit(0);
    }
}

int main() {
    char wybor;
    do {
        wybor = wyswietlMenu();
        double a, b, c, r, h;

        switch (wybor) {
        case 'a':
            cout << "Podaj promien kuli: ";
            cin >> r;
            cout << "Objetosc kuli = " << KulaObjetosc(r) << endl;
            cout << "Pole powierzchni kuli to = " << KulaPole(r) << endl;
            restart();
        break;

        case 'b':
            cout << "Podaj wymiary prostopadloscianu:\n";
            cout << "a: ";
            cin >> a;
            cout << "b: ";
            cin >> b;
            cout << "c: ";
            cin >> c;
            cout << "Objetosc prostopadloscianu = " << ProstopadloscianObjetosc(a, b, c) << endl;
            cout << "Pole powierzchni prostopadloscianu = " << ProstopadloscianPole(a, b, c) << endl;
            restart();
        break;

        case 'c':
            cout << "Podaj wymiary stozka:\n";
            cout << "Promien podstawy: ";
            cin >> r;
            cout << "Wysokosc stozka: ";
            cin >> h;
            cout << "Objetosc stozka = " << StozekObjetosc(r, h) << endl;
            cout << "Pole powierzchni calkowitej stozka = " << StozekPole(r, h) << endl;
            restart();
        break;

        case 'x':
            cout << "Zakonczono program." << endl;
            break;
        default:
            cout << "Niepoprawny wybor.\n" << endl;

    }
    } while (wybor != 'x');

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct lista
{
    string imie;
    string nazwisko;
    string PESEL;
    int wiek;
    lista *pop;
    lista *nast;
};

/*
1. dodającą element do listy dwukierunkowej z zachowaniem porządku klucza (nazwisko);
2. dodającą element do listy dwukierunkowej z zachowaniem porządku klucza (nazwisko)
wraz ze sprawdzeniem czy identyczny element jest już w liście;
3. usuwającą pierwszy element o podanej wartości klucza;
4. usuwającą wszystkie elementy o podanej wartości klucza;
5. edytującą wybrany element listy dwukierunkowej;
6. zapisującą do pliku tekstowego elementy listy dwukierunkowej na podstawie wybranych
kryteriów (wszystkie elementy listy, elementy o wybranym nazwisku, osoby pełnoletnie);
7. wyprowadzającą zawartość listy dwukierunkowej na ekran;
8. wyprowadzającą zawartość wcześniej utworzonego pliku tekstowego na ekran;
*/

lista *poczatek = NULL;
lista *koniec = NULL;

void wstawElement(lista* nowyElement) {
    if (poczatek == NULL) {
        poczatek = nowyElement;
        koniec = nowyElement;
    } else {
        lista* aktualny = poczatek;
        lista* poprzedni = NULL;

        while (aktualny != NULL && aktualny->nazwisko < nowyElement->nazwisko) {
            poprzedni = aktualny;
            aktualny = aktualny->nast;
        }

        if (poprzedni == NULL) {
            nowyElement->nast = poczatek;
            poczatek->pop = nowyElement;
            poczatek = nowyElement;
        } else if (aktualny == NULL) {
            poprzedni->nast = nowyElement;
            nowyElement->pop = poprzedni;
            koniec = nowyElement;
        } else {
            poprzedni->nast = nowyElement;
            nowyElement->pop = poprzedni;
            nowyElement->nast = aktualny;
            aktualny->pop = nowyElement;
        }
    }
}

void dodajElement(string imie, string nazwisko, string PESEL, int wiek) {
    lista* nowyElement = new lista;
    nowyElement->imie = imie;
    nowyElement->nazwisko = nazwisko;
    nowyElement->PESEL = PESEL;
    nowyElement->wiek = wiek;
    nowyElement->pop = NULL;
    nowyElement->nast = NULL;

    wstawElement(nowyElement);
}

void dodajElement(string imie, string nazwisko, string PESEL, int wiek) {
    lista* nowyElement = new lista;
    nowyElement->imie = imie;
    nowyElement->nazwisko = nazwisko;
    nowyElement->PESEL = PESEL;
    nowyElement->wiek = wiek;
    nowyElement->pop = NULL;
    nowyElement->nast = NULL;

    wstawElement(nowyElement);
}

void zwolnijPamiec() {
    lista *temp = poczatek;
    while (temp != NULL) {
        lista *nast = temp->nast;
        delete temp;
        temp = nast;
    }
    poczatek = NULL;
    koniec = NULL;
}

void wyswietlMenu() {
    cout << "********** MENU **********" << endl;
    cout << "1. Dodaj element do listy" << endl;
    cout << "2. Dodaj element do listy ze sprawdzeniem czy juz istnieje" << endl;
    cout << "3. Usun pierwszy element o podanym kluczu" << endl;
    cout << "4. Usun wszystkie elementy o podanym kluczu" << endl;
    cout << "5. Edytuj wybrany element listy" << endl;
    cout << "6. Zapisz elementy listy do pliku" << endl;
    cout << "7. Wypisz zawartosc listy" << endl;
    cout << "8. Wypisz zawartosc pliku na ekranie" << endl;
    cout << "9. Zakoncz" << endl;
    cout << "Wybierz opcje: ";
}

void operacje(int wybor) {
switch (wybor) {
        case 1:
            cout << "Funkcja 1" << endl;
            break;
        case 2:
            // Wywołaj funkcję do dodawania elementu do listy ze sprawdzeniem
            cout << "Funkcja 2" << endl;
            break;
        case 3:
            // Wywołaj funkcję do usuwania pierwszego elementu o podanym kluczu
            cout << "Funkcja 3" << endl;
            break;
        case 4:
            // Wywołaj funkcję do usuwania wszystkich elementów o podanym kluczu
            cout << "Funkcja 4" << endl;
            break;
        case 5:
            // Wywołaj funkcję do edycji wybranego elementu listy
            cout << "Funkcja 5" << endl;
            break;
        case 6:
            // Wywołaj funkcję do zapisywania elementów listy do pliku
            cout << "Funkcja 6" << endl;
            break;
        case 7:
            // Wywołaj funkcję do wyświetlania zawartości listy
            cout << "Funkcja 7" << endl;
            break;
        case 8:
            // Wywołaj funkcję do wyświetlania zawartości pliku na ekranie
            cout << "Funkcja 8" << endl;
            break;
        case 9:
            zwolnijPamiec();
            cout << "Koniec programu." << endl;
            exit(0);
        default:
            cout << "Nieznana opcja, sprobuj ponownie." << endl;
    }
}

int main() {
    int wybor;
    while (true) {
        wyswietlMenu();
        cin >> wybor;
        operacje(wybor);
        cout << endl;
    }
    return 0;
}
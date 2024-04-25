#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct lista
{
    string imie;
    string nazwisko;
    string PESEL;
    int wiek;
    lista *nast;
};

lista *pocz = nullptr;
lista *kon = nullptr;

void dodaj(string imie, string nazwisko, string PESEL, int wiek)
{
    lista *nowy = new lista;
    nowy->imie = imie;
    nowy->nazwisko = nazwisko;
    nowy->PESEL = PESEL;
    nowy->wiek = wiek;
    nowy->nast = nullptr;

    if (kon != nullptr)
        kon->nast = nowy;
    else
        pocz = nowy;

    kon = nowy;
}

void usun()
{
    if (pocz != nullptr)
    {
        lista *temp = pocz;
        pocz = pocz->nast;
        delete temp;

        if (pocz == nullptr)
            kon = nullptr;
    }
}

void wypisz()
{
    lista *temp = pocz;
    while (temp != nullptr)
    {
        cout << "Imie i nazwisko: " << temp->imie << " " << temp->nazwisko << ", PESEL: " << temp->PESEL << ", wiek: " << temp->wiek << endl;
        temp = temp->nast;
    }
}

void usunWszystko()
{
    while (pocz != nullptr)
        usun();
}

void zapiszDoPliku(string nazwaPliku)
{
    vector<lista *> wektor;
    lista *temp = pocz;
    while (temp != nullptr)
    {
        wektor.push_back(temp);
        temp = temp->nast;
    }

    sort(wektor.begin(), wektor.end(), [](lista *a, lista *b)
         { return a->wiek < b->wiek; });

    ofstream plik(nazwaPliku);
    if (plik.is_open())
    {
        for (lista *element : wektor)
            plik << element->imie << " " << element->nazwisko << ", " << element->PESEL << ", " << element->wiek << " lat\n";
        plik.close();
        cout << "Zapis do pliku " << nazwaPliku << " powiodl sie." << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku " << nazwaPliku << " do zapisu." << endl;
    }
}

bool sprawdzKolejke()
{
    if (pocz == nullptr)
    {
        cout << "Nie mozna wykonac operacji. Lista jest pusta!\n";
        return false;
    }
    return true;
}

int main()
{
    char wybor;
    string imie, nazwisko, PESEL;
    int wiek;
    dodaj("Jan Maria", "Rokita A", "12345678901", 11);
    dodaj("Anna", "Nowak", "23456789012", 33);
    dodaj("Piotr", "Zielinski", "34567890123", 22);
    dodaj("Katarzyna", "Wisniewska", "45678901234", 99);
    dodaj("Kasia", "Babs", "46346671234", 177);
    dodaj("Pioter", "Pjoter", "32220123", 7);
    do
    {
        cout << "a) Dodaj element na koniec kolejki\n"
             << "b) Usun element z poczatku kolejki\n"
             << "c) Pokaz zawartosc kolejki\n"
             << "d) Usun wszystkie elementy kolejki\n"
             << "e) Zapisz elementy do pliku (sortowanie wg wieku)\n"
             << "f) Zakoncz program\n"
             << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor)
        {
        case 'a':
            bool valid;
            cout << "Imie: ";
            cin.ignore();
            getline(cin, imie);
            cout << "Nazwisko: ";
            getline(cin, nazwisko);
            cout << "PESEL: ";
            do
            {
                cin >> PESEL;
                valid = true;
                for (char c : PESEL)
                {
                    if (c < '0' || c > '9')
                    {
                        valid = false;
                        break;
                    }
                }
                if (PESEL.length() != 11 || !valid)
                {
                    cout << "PESEL musi skladac sie z 11 cyfr. Wprowadz ponownie: ";
                }
            } while (PESEL.length() != 11 || !valid);
            cout << "Wiek: ";
            do
            {
                cin >> wiek;
                if (wiek < 1 || wiek > 125)
                {
                    cout << "Wprowadz ponownie: ";
                }
            } while (wiek < 1 || wiek > 125);
            dodaj(imie, nazwisko, PESEL, wiek);
            cout << "Dodano element na koniec kolejki.\n" << endl;
            break;
        case 'b':
            if (sprawdzKolejke())
                usun();
            cout << "Usunieto element z kolejki.\n" << endl;
            break;
        case 'c':
            if (sprawdzKolejke())
                wypisz();
            cout << endl;
            break;
        case 'd':
            if (sprawdzKolejke())
                usunWszystko();
            cout << endl;
            break;
        case 'e':
            if (sprawdzKolejke())
                zapiszDoPliku("kolejka.txt");
            cout << endl;
            break;
        case 'f':
            usunWszystko();
            break;
        default:
            cout << "Nieznana opcja." << endl;
        }
    } while (wybor != 'f');

    return 0;
}
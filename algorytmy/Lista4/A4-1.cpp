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

lista *poczatek = nullptr;
lista *koniec = nullptr;

string pobierzPESEL() {
    string PESEL;
    bool valid;
    cout << "Podaj PESEL: ";
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
    return PESEL;
}

int pobierzWiek() {
    int wiek;
    cout << "Podaj wiek: ";
    do
    {
        cin >> wiek;
        if (wiek < 1 || wiek > 125)
        {
            cout << "Wprowadz ponownie: ";
        }
    } while (wiek < 1 || wiek > 125);
    return wiek;
}

void dodaj(string imie, string nazwisko, string PESEL, int wiek)
{
    lista *nowy = new lista;
    nowy->imie = imie;
    nowy->nazwisko = nazwisko;
    nowy->PESEL = PESEL;
    nowy->wiek = wiek;
    nowy->nast = NULL;
    nowy->pop = koniec;
    if (koniec != NULL)
        koniec->nast = nowy;
    else
        poczatek = nowy;
    koniec = nowy;
}

void usunPierwszy(string nazwisko)
{
    lista *temp = poczatek;
    bool deleted = false;
    while (temp != NULL)
    {
        if (temp->nazwisko == nazwisko)
        {
            if (temp->pop != NULL)
                temp->pop->nast = temp->nast;
            else
                poczatek = temp->nast;
            if (temp->nast != NULL)
                temp->nast->pop = temp->pop;
            else
                koniec = temp->pop;
            delete temp;
            deleted = true;
            break;
        }
        temp = temp->nast;
    }
    if (deleted)
    {
        cout << "Pierwszy element o podanym nazwisku zostal usuniety." << endl;
    }
    else
    {
        cout << "Nie znaleziono elementu o podanym nazwisku." << endl;
    }
}

void usunWszystkie(string nazwisko)
{
    lista *temp = poczatek;
    bool deleted = false;
    while (temp != NULL)
    {
        lista *nast = temp->nast;
        if (temp->nazwisko == nazwisko)
        {
            if (temp->pop != NULL)
                temp->pop->nast = temp->nast;
            else
                poczatek = temp->nast;
            if (temp->nast != NULL)
                temp->nast->pop = temp->pop;
            else
                koniec = temp->pop;
            delete temp;
            deleted = true;
        }
        temp = nast;
    }
    if (deleted)
    {
        cout << "Usunieto wszystkie elementy o podanym nazwisku." << endl;
    }
    else
    {
        cout << "Nie znaleziono elementow o podanym nazwisku." << endl;
    }
}

void wypisz()
{
    lista *temp = poczatek;
    if (temp == NULL)
    {
        cout << "Lista jest pusta." << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << "Imie: " << temp->imie << ", Nazwisko: " << temp->nazwisko << ", PESEL: " << temp->PESEL << ", Wiek: " << temp->wiek << endl;
        temp = temp->nast;
    }
}

void wyszukaj(string klucz)
{
    lista *temp = poczatek;
    bool found = false;
    while (temp != NULL)
    {
        if (temp->imie.find(klucz) != string::npos || temp->nazwisko.find(klucz) != string::npos || temp->PESEL.find(klucz) != string::npos)
        {
            if (!found)
            {
                cout << "Znalezione elementy pasujace do klucza:" << endl;
                found = true;
            }
            cout << "Imie: " << temp->imie << ", Nazwisko: " << temp->nazwisko << ", PESEL: " << temp->PESEL << ", Wiek: " << temp->wiek << endl;
        }
        temp = temp->nast;
    }
    if (!found)
    {
        cout << "Nie znaleziono elementow pasujacych do klucza." << endl;
    }
}

lista *znajdz(string PESEL)
{
    lista *temp = poczatek;
    while (temp != NULL)
    {
        if (temp->PESEL == PESEL)
        {
            return temp;
        }
        temp = temp->nast;
    }
    return NULL;
}

void aktualizuj(lista *osoba, string noweImie, string noweNazwisko, int nowyWiek, string nowyPESEL)
{
    if (osoba != NULL)
    {
        osoba->imie = noweImie;
        osoba->nazwisko = noweNazwisko;
        osoba->wiek = nowyWiek;
        osoba->PESEL = nowyPESEL;
    }
    else
    {
        cout << "Nie znaleziono podanego nr PESEL." << endl;
    }
}

void edytujOsobe()
{
    string PESEL, noweImie, noweNazwisko, nowyPESEL;
    int nowyWiek;

    cout << "Podaj PESEL osoby do edycji: ";
    cin >> PESEL;

    lista *osoba = znajdz(PESEL);
    if (osoba != NULL)
    {
        cout << "Podaj nowe dane dla osoby o nr PESEL " << PESEL << ":" << endl;
        cout << "Podaj imie: ";
        cin >> noweImie;
        cout << "Podaj  nazwisko: ";
        cin >> noweNazwisko;
        nowyPESEL = pobierzPESEL();
        nowyWiek = pobierzWiek();
        aktualizuj(osoba, noweImie, noweNazwisko, nowyWiek, nowyPESEL);
    }
    else
    {
        cout << "Nie znaleziono podanego nr PESEL." << endl;
    }
}

void zapiszDoPliku(string nazwaPliku)
{
    ofstream plik(nazwaPliku);
    if (!plik)
    {
        cout << "Blad otwarcia pliku" << endl;
        return;
    }
    lista *temp = poczatek;
    while (temp != NULL)
    {
        plik << "Imie: " << temp->imie << ", Nazwisko: " << temp->nazwisko << ", PESEL: " << temp->PESEL << ", Wiek: " << temp->wiek << endl;
        temp = temp->nast;
    }
    plik.close();
    cout << "Dane zapisane do pliku " << nazwaPliku << " pomyslnie." << endl;
}

void zwolnijPamiec()
{
    lista *temp = poczatek;
    while (temp != NULL)
    {
        lista *nast = temp->nast;
        delete temp;
        temp = nast;
    }
    koniec = NULL;
}

int main()
{
    int wybor;
    string imie, nazwisko, PESEL, nazwaPliku, klucz, nowyPESEL;
    int wiek;
    lista *osoba = znajdz(PESEL);
    dodaj("Jan", "Doe", "1234561234", 30);
    dodaj("Jane", "Doever", "12312312312", 25);
    while (true)
    {
        cout << "1. Dodaj element do listy" << endl;
        cout << "2. Usun pierwszy element o podanym nazwisku" << endl;
        cout << "3. Usun wszystkie elementy o podanym nazwisku" << endl;
        cout << "4. Wyszukaj elementy na podstawie klucza" << endl;
        cout << "5. Wypisz zawartosc listy" << endl;
        cout << "6. Edytuj wybrany element listy" << endl;
        cout << "7. Zapisz elementy listy do pliku" << endl;
        cout << "8. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            cout << "Podaj imie: ";
            cin >> imie;
            cout << "Podaj nazwisko: ";
            cin >> nazwisko;
            PESEL = pobierzPESEL();
            wiek = pobierzWiek();
            dodaj(imie, nazwisko, PESEL, wiek);
            cout << endl;
            break;
        case 2:
            cout << "Podaj nazwisko: ";
            cin >> nazwisko;
            usunPierwszy(nazwisko);
            cout << endl;
            break;
        case 3:
            cout << "Podaj nazwisko: ";
            cin >> nazwisko;
            usunWszystkie(nazwisko);
            cout << endl;
            break;
        case 4:
            cout << "Podaj klucz: ";
            cin >> klucz;
            wyszukaj(klucz);
            cout << endl;
            break;
        case 5:
            wypisz();
            cout << endl;
            break;
        case 6:
            edytujOsobe();
            break;
        case 7:
            cout << "Podaj nazwe pliku z rozszerzeniem: ";
            cin >> nazwaPliku;
            zapiszDoPliku(nazwaPliku);
            cout << endl;
            break;
        case 8:
            zwolnijPamiec();
            cout << "Koniec programu" << endl;
            return 0;
        default:
            cout << "Nieznana opcja" << endl;
            break;
        }
    }

    return 0;
}
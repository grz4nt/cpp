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

lista *poczatek = NULL;
lista *koniec = NULL;

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
    nowy->pop = NULL;

    if (poczatek == NULL)
    {
        poczatek = nowy;
        koniec = nowy;
    }
    else if (nazwisko < poczatek->nazwisko)
    {
        nowy->nast = poczatek;
        poczatek->pop = nowy;
        poczatek = nowy;
    }
    else if (nazwisko >= koniec->nazwisko)
    {
        nowy->pop = koniec;
        koniec->nast = nowy;
        koniec = nowy;
    }
    else
    {
        lista *temp = poczatek->nast;
        while (temp != NULL && temp->nazwisko < nazwisko)
        {
            temp = temp->nast;
        }
        nowy->nast = temp;
        nowy->pop = temp->pop;
        temp->pop->nast = nowy;
        temp->pop = nowy;
    }
}

void dodajSprawdz(string imie, string nazwisko, string PESEL, int wiek)
{
    lista *temp = poczatek;
    while (temp != NULL)
    {
        if (temp->nazwisko == nazwisko)
        {
            cout << "Uwaga: Element o nazwisku " << nazwisko << " juz istnieje na liscie." << endl;
        }
        temp = temp->nast;
    }

    dodaj(imie, nazwisko, PESEL, wiek);
}

void usunPierwszy(string klucz, string wartosc)
{
    lista *temp = poczatek;
    bool deleted = false;
    while (temp != NULL)
    {
        if (klucz == "imie" && temp->imie == wartosc)
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
        else if (klucz == "nazwisko" && temp->nazwisko == wartosc)
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
        else if (klucz == "PESEL" && temp->PESEL == wartosc)
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
        else if (klucz == "wiek" && temp->wiek == stoi(wartosc))
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
        cout << "Pierwszy element o podanym kluczu zostal usuniety." << endl;
    }
    else
    {
        cout << "Nie znaleziono elementu o podanym kluczu." << endl;
    }
}

void usunWszystkie(string klucz, string wartosc)
{
    lista *temp = poczatek;
    bool deleted = false;
    while (temp != NULL)
    {
        lista *nast = temp->nast;
        if (klucz == "imie" && temp->imie == wartosc)
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
        else if (klucz == "nazwisko" && temp->nazwisko == wartosc)
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
        else if (klucz == "PESEL" && temp->PESEL == wartosc)
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
        else if (klucz == "wiek" && temp->wiek == stoi(wartosc))
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
        cout << "Usunieto wszystkie elementy o podanym kluczu." << endl;
    }
    else
    {
        cout << "Nie znaleziono elementow o podanym kluczu." << endl;
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
        cout << temp->imie << " " << temp->nazwisko << ", PESEL: " << temp->PESEL << ", Wiek: " << temp->wiek << endl;
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
            cout << temp->imie << " " << temp->nazwisko << ", PESEL: " << temp->PESEL << ", Wiek: " << temp->wiek << endl;
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

void zapiszElement(ofstream& plik, lista* element)
{
    plik << element->imie << "," << element->nazwisko << "," << element->PESEL << "," << element->wiek << endl;
}

void zapiszDoPliku(string nazwaPliku)
{
    ofstream plik(nazwaPliku);
    if (!plik)
    {
        cout << "Blad otwarcia pliku" << endl;
        return;
    }

    int wybor;
    cout << "Wybierz opcje zapisu:" << endl;
    cout << "1. Wszystkie elementy" << endl;
    cout << "2. Tylko o wybranym nazwisku" << endl;
    cout << "3. Tylko osoby pelnoletnie" << endl;
    cout << "Wybierz opcje: ";
    cin >> wybor;

    if (wybor == 2)
    {
        string wybraneNazwisko;
        cout << "Podaj nazwisko: ";
        cin >> wybraneNazwisko;
        lista *temp = poczatek;
        while (temp != NULL)
        {
            if (temp->nazwisko == wybraneNazwisko)
            {
                zapiszElement(plik, temp);
            }
            temp = temp->nast;
        }
    }
    else
    {
        lista *temp = poczatek;
        while (temp != NULL)
        {
            if (wybor == 1 || (wybor == 3 && temp->wiek >= 18))
            {
                zapiszElement(plik, temp);
            }
            temp = temp->nast;
        }
    }
    plik.close();
    cout << "Dane zapisane do pliku pomyslnie." << endl;
}

void wypiszPlik(string nazwaPliku)
{
    ifstream plik(nazwaPliku);
    if (!plik)
    {
        cout << "Plik nie istnieje." << endl;
        return;
    }

    string linia;
    while (getline(plik, linia))
    {
        cout << linia << endl;
    }

    plik.close();
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
    string imie, nazwisko, PESEL, klucz, nowyPESEL, wartosc;
    int wiek;
    lista *osoba = znajdz(PESEL);
    dodaj("Jan", "Doe", "1234561234", 30);
    dodaj("Jane", "Doever", "12312312312", 25);
    dodaj("Maria", "Kowalska", "00112233456", 20);
    dodaj("Jadwiga", "Hymel", "45011232167", 80);
    dodaj("Michal", "Kowalski", "90031233456", 40);
    dodaj("Michael", "Jackson", "65314245689", 60);
    while (true)
    {
        cout << "1. Dodaj element do listy (wg nazwiska)" << endl;
        cout << "2. Dodaj element do listy (wg nazwiska) i sprawdz czy istnieje" << endl;
        cout << "3. Usun pierwszy element o podanym kluczu" << endl;
        cout << "4. Usun wszystkie elementy o podanym kluczu" << endl;
        cout << "5. Edytuj wybrany element listy" << endl;
        cout << "6. Zapisz elementy listy do pliku CSV" << endl;
        cout << "7. Wypisz zawartosc listy" << endl;
        cout << "8. Wypisz zawartosc zapisanego pliku" << endl;
        cout << "9. Wyjscie" << endl;
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
            cout << "Podaj imie: ";
            cin >> imie;
            cout << "Podaj nazwisko: ";
            cin >> nazwisko;
            PESEL = pobierzPESEL();
            wiek = pobierzWiek();
            dodajSprawdz(imie, nazwisko, PESEL, wiek);
            cout << endl;
            break;
        case 3:
            cout << "Podaj klucz (imie/nazwisko/PESEL/wiek): ";
            cin >> klucz;
            cout << "Podaj wartosc klucza: ";
            cin >> wartosc;
            usunPierwszy(klucz, wartosc);
            cout << endl;
            break;
        case 4:
            cout << "Podaj klucz (imie/nazwisko/PESEL/wiek): ";
            cin >> klucz;
            cout << "Podaj wartosc klucza: ";
            cin >> wartosc;
            usunWszystkie(klucz, wartosc);
            cout << endl;
            break;
        case 5:
            edytujOsobe();
            break;
        case 6:
            zapiszDoPliku("lista.csv");
            cout << endl;
            break;
        case 7:
            wypisz();
            cout << endl;
            break;
        case 8:
            wypiszPlik("lista.csv");
            cout << endl;
            break;
        case 9:
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
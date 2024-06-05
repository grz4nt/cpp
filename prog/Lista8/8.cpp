#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Student
{
public:
    string imie;
    string nazwisko;
    int akt_sem;
    int semestry;
    int indeks;
    double avg;

    Student(string imie, string nazwisko, int akt_sem, int semestry, int indeks, double avg)
        : imie{ imie }, nazwisko{ nazwisko }, akt_sem{ akt_sem }, semestry{ semestry }, indeks{ indeks }, avg{ avg }
    {
    }

    friend ostream& operator<<(ostream& os, const Student& s)
    {
        os << "Imie: " << s.imie << endl;
        os << "Nazwisko: " << s.nazwisko << endl;
        os << "Aktualny semestr: " << s.akt_sem << endl;
        os << "Ilosc semestrow: " << s.semestry << endl;
        os << "Numer indeksu: " << s.indeks << endl;
        return os;
    }

    // Funkcja do edycji danych studenta
    void edytujDane()
    {
        cout << "Wprowadz imie studenta: ";
        cin >> imie;
        cout << "Wprowadz nazwisko studenta: ";
        cin >> nazwisko;
        cout << "Wprowadz aktualny semestr: ";
        cin >> akt_sem;
        while (akt_sem < 1 || akt_sem > 7)
        {
            cout << "Podaj raz jeszcze semestry od 1 do 7: ";
            cin >> akt_sem;
        }
        cout << "Ile semestrow zaliczonych: ";
        cin >> semestry;
        while (semestry != akt_sem - 1)
        {
            cout << "Wprowadz poprawna ilosc semestrow: ";
            cin >> semestry;
        }
        cout << "Wprowadz nr indeksu: ";
        cin >> indeks;
        cout << endl;
    }
};

class Ocena
{
public:
    int idx;
    string przedmiot;
    string imie_p;
    string nazwisko_p;
    int ocena;
    string data;
    int semestr;

    Ocena(int idx, string przedmiot, string imie_p, string nazwisko_p, int ocena, string data, int semestr)
        : idx{ idx }, przedmiot{ przedmiot }, imie_p{ imie_p }, nazwisko_p{ nazwisko_p }, ocena{ ocena }, data{ data }, semestr{ semestr }
    {
    }

    friend ostream& operator<<(ostream& c, const Ocena& o)
    {
        c << "Przedmiot: " << o.przedmiot << endl;
        c << "Imie prowadzacego: " << o.imie_p << endl;
        c << "Nazwisko prowadzacego: " << o.nazwisko_p << endl;
        c << "Ocena: " << o.ocena << endl;
        c << "Data wpisania: " << o.data << endl;
        c << "Semestr wpisania oceny: " << o.semestr << endl;
        return c;
    }
};

vector<Student> student;
vector<Ocena> oc;

// Funkcja do wprowadzania danych studenta
Student wprowadzDaneStudenta()
{
    string imie, nazwisko;
    int indeks, akt_sem, semestry;
    double avg = 0.0;

    cout << "Wprowadz imie studenta: ";
    cin >> imie;
    cout << "Wprowadz nazwisko studenta: ";
    cin >> nazwisko;
    cout << "Wprowadz aktualny semestr: ";
    cin >> akt_sem;
    while (akt_sem < 1 || akt_sem > 7)
    {
        cout << "Semestry od 1 do 7 podaj raz jeszcze: ";
        cin >> akt_sem;
    }
    cout << "Ile semestrow zaliczonych: ";
    cin >> semestry;
    while (semestry != akt_sem - 1)
    {
        cout << "Wprowadz poprawna ilosc semestrow: ";
        cin >> semestry;
    }
    cout << "Wprowadz nr indeksu: ";
    cin >> indeks;
    cout << endl;

    return Student(imie, nazwisko, akt_sem, semestry, indeks, avg);
}

void dodajStudenta()
{
    student.push_back(wprowadzDaneStudenta());
}

void listaStudentow()
{
    for (const auto& s : student)
    {
        cout << s;
        cout << "-----Lista Ocen:-----" << endl;

        bool hasGrades = false;
        for (const auto& o : oc)
        {
            if (s.indeks == o.idx)
            {
                cout << o << endl << "---";
                hasGrades = true;
            }
        }
        if (!hasGrades)
        {
            cout << "Student nie ma oceny" << endl;
        }
        cout << endl;
    }
}

void del()
{
    cout << "Ktorego studenta chcesz usunac, podaj jego indeks?" << endl;
    int del;
    cin >> del;
    auto it = find_if(student.begin(), student.end(), [&](const Student& s) { return s.indeks == del; });
    if (it != student.end())
    {
        student.erase(it);
        cout << "Student zostal usuniety z listy" << endl;
    }
    else
    {
        cout << "Nie znaleziono studenta o podanym indeksie" << endl;
    }
}

void ocena()
{
    string przedmiot, imie_p, nazwisko_p, data;
    int semestr, idx;
    double ocena;

    cout << "Podaj indeks ocenianego studenta: ";
    cin >> idx;
    cout << "Podaj nazwe przedmiotu: ";
    cin >> przedmiot;
    cout << "Imie prowadzacego: ";
    cin >> imie_p;
    cout << "Nazwisko prowadzacego: ";
    cin >> nazwisko_p;
    cout << "Ocena: ";
    cin >> ocena;
    while (ocena < 2 || ocena > 5)
    {
        cout << "Wpisz poprawna ocene (2-5): ";
        cin >> ocena;
    }
    cout << "Data wpisania oceny: ";
    cin >> data;
    cout << "Podaj semestr wpisania oceny: ";
    cin >> semestr;
    cout << endl;

    oc.push_back(Ocena(idx, przedmiot, imie_p, nazwisko_p, ocena, data, semestr));
}

void znaj()
{
    cout << "Wpisz nazwisko szukanego studenta: ";
    string nazwisko;
    cin >> nazwisko;

    auto it = find_if(begin(student), end(student), [&](const Student& s) { return s.nazwisko == nazwisko; });

    if (it != end(student))
    {
        cout << "Istnieje student o nazwisku: " << *it << endl;
    }
    else
    {
        cout << "Nie ma studenta o nazwisku " << nazwisko << endl;
    }
}

void edit()
{
    int idx;
    cout << "Podaj indeks studenta do edycji: ";
    cin >> idx;

    auto it = find_if(student.begin(), student.end(), [&](const Student& s) { return s.indeks == idx; });
    if (it != student.end())
    {
        Student& s = *it;
        int w;
        cout << "1 - edytuj imie" << endl
             << "2 - edytuj nazwisko" << endl
             << "3 - edytuj aktualny semestr" << endl
             << "4 - edytuj liczbe zaliczonych semestrow" << endl
             << "5 - edytuj numer indeksu" << endl
             << "6 - edytuj wszystko" << endl;
        cin >> w;
        switch (w)
        {
        case 1:
            cout << "Wprowadz nowe imie: ";
            cin >> s.imie;
            break;
        case 2:
            cout << "Wprowadz nowe nazwisko: ";
            cin >> s.nazwisko;
            break;
        case 3:
            cout << "Wprowadz aktualny semestr: ";
            cin >> s.akt_sem;
            while (s.akt_sem < 1 || s.akt_sem > 7)
            {
                cout << "Podaj raz jeszcze semestry od 1 do 7: ";
                cin >> s.akt_sem;
            }
            break;
        case 4:
            cout << "Wprowadz liczbe zaliczonych semestrow: ";
            cin >> s.semestry;
            while (s.semestry != s.akt_sem - 1)
            {
                cout << "Wprowadz poprawna ilosc semestrow: ";
                cin >> s.semestry;
            }
            break;
        case 5:
            cout << "Wprowadz numer indeksu: ";
            cin >> s.indeks;
            break;
        case 6:
            s.edytujDane();
            break;
        default:
            cout << "Niepoprawny wybor, sprobuj ponownie." << endl;
            break;
        }
    }
    else
    {
        cout << "Nie znaleziono studenta o podanym indeksie" << endl;
    }
}

void prog()
{
    double p = 4.4;

    for (auto& s : student)
    {
        int ile = 0;
        s.avg = 0;

        for (const auto& o : oc)
        {
            if (s.indeks == o.idx)
            {
                s.avg += o.ocena;
                ile++;
            }
        }

        if (ile > 0 && (s.avg / ile) >= p)
        {
            cout << "Studentowi " << s.nazwisko << " przysługuje stypendium" << endl;
        }
    }
}

int main()
{
    int w;
    bool exit = false;
    while (!exit)
    {
        cout << "1. Dodanie studenta" << endl;
        cout << "2. Usuniecie studenta" << endl;
        cout << "3. Edytowanie studenta" << endl;
        cout << "4. Przeglad studentow" << endl;
        cout << "5. Wyszukaj studenta" << endl;
        cout << "6. Wpisz ocene" << endl;
        cout << "7. Zakoncz" << endl;
        cin >> w;
        cout << "---------------------" << endl;

        switch (w)
        {
        case 1:
            dodajStudenta();
            break;
        case 2:
            del();
            break;
        case 3:
            edit();
            break;
        case 4:
            listaStudentow();
            break;
        case 5:
            znaj();
            break;
        case 6:
            ocena();
            break;
        case 7:
            exit = true;
            break;
        default:
            cout << "Niepoprawny wybor, sprobuj ponownie." << endl;
            break;
        }
    }
}

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Ocena
{
public:
    string przedmiot;
    string imie_p;
    string nazwisko_p;
    int ocena;
    string data;

    Ocena(string przedmiot, string imie_p, string nazwisko_p, int ocena, string data)
        : przedmiot{ przedmiot }, imie_p{ imie_p }, nazwisko_p{ nazwisko_p }, ocena{ ocena }, data{ data }
    {
    }

    friend ostream& operator<<(ostream& os, const Ocena& o)
    {
        os << "Przedmiot: " << o.przedmiot << " (" << o.imie_p << " " << o.nazwisko_p << ")" << endl;
        os << "Ocena: " << o.ocena << " (" << o.data << ")" << endl;
        return os;
    }
};

class Semestr
{
public:
    int numer;
    vector<Ocena> oceny;

    Semestr(int numer) : numer{ numer } {}

    void dodajOcene(const Ocena& ocena)
    {
        oceny.push_back(ocena);
    }

    friend ostream& operator<<(ostream& os, const Semestr& s)
    {
        os << "Semestr: " << s.numer << endl;
        for (const auto& ocena : s.oceny)
        {
            os << ocena << endl;
        }
        return os;
    }
};

class Student
{
public:
    string imie;
    string nazwisko;
    int aktSem;
    int album;
    double avg;
    vector<Semestr> historiaSemestrow;

    Student(string imie, string nazwisko, int aktSem, int album, double avg)
        : imie{ imie }, nazwisko{ nazwisko }, aktSem{ aktSem }, album{ album }, avg{ avg }
    {
        for (int i = 1; i <= aktSem; ++i)
        {
            historiaSemestrow.emplace_back(i);
        }
    }

    friend ostream& operator<<(ostream& os, const Student& s)
    {
        os << s.imie << " " << s.nazwisko << " (" << s.album << ")" << endl;
        os << "Aktualny semestr: " << s.aktSem << endl;
        os << "Historia semestrow: " << endl;
        for (const auto& sem : s.historiaSemestrow)
        {
            os << sem << endl;
        }
        os << "Srednia ocen: " << s.avg << endl;
        return os;
    }

    void edytujDane()
    {
        wprowadzDaneStudenta(*this);
    }

    static void wprowadzDaneStudenta(Student& student)
    {
        cout << "Imie: ";
        cin >> student.imie;
        cout << "Nazwisko: ";
        cin >> student.nazwisko;
        cout << "Aktualny semestr: ";
        cin >> student.aktSem;
        while (student.aktSem < 1 || student.aktSem > 7)
        {
            cout << "Niepoprawna wartosc (wpisz 1-7) : ";
            cin >> student.aktSem;
        }
        cout << "Nr albumu (indeks): ";
        cin >> student.album;
        cout << "Srednia ocen: ";
        cin >> student.avg;
        cout << endl;

        student.historiaSemestrow.clear();
        for (int i = 1; i <= student.aktSem; ++i)
        {
            student.historiaSemestrow.emplace_back(i);
        }
    }

    void dodajOcene(int numerSemestru, const Ocena& ocena)
    {
        auto it = find_if(historiaSemestrow.begin(), historiaSemestrow.end(), [&](const Semestr& s) { return s.numer == numerSemestru; });
        if (it != historiaSemestrow.end())
        {
            it->dodajOcene(ocena);
        }
    }
};

vector<Student> student;

Student wprowadzDaneStudenta()
{
    string imie, nazwisko;
    int aktSem, album;
    double avg;

    cout << "Imie: ";
    cin >> imie;
    cout << "Nazwisko: ";
    cin >> nazwisko;
    cout << "Aktualny semestr: ";
    cin >> aktSem;
    while (aktSem < 1 || aktSem > 7)
    {
        cout << "Niepoprawna wartosc (wpisz 1-7) : ";
        cin >> aktSem;
    }
    cout << "Nr albumu (indeks): ";
    cin >> album;
    cout << "Srednia ocen: ";
    cin >> avg;
    cout << endl;

    Student nowyStudent(imie, nazwisko, aktSem, album, avg);
    return nowyStudent;
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
    }
}

void del()
{
    cout << "Podaj nr albumu studenta do usuniecia: " << endl;
    int del;
    cin >> del;
    auto it = find_if(student.begin(), student.end(), [&](const Student& s) { return s.album == del; });
    if (it != student.end())
    {
        student.erase(it);
        cout << "Student zostal usuniety z listy" << endl;
    }
    else
    {
        cout << "Nie znaleziono studenta o podanym albumie" << endl;
    }
}

void ocena()
{
    string przedmiot, imie_p, nazwisko_p, data;
    int album, numerSemestru;
    double ocena;

    cout << "Nr albumu: ";
    cin >> album;
    cout << "Numer semestru: ";
    cin >> numerSemestru;
    cout << "Przedmiot: ";
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
    cout << endl;

    auto it = find_if(student.begin(), student.end(), [&](const Student& s) { return s.album == album; });
    if (it != student.end())
    {
        it->dodajOcene(numerSemestru, Ocena(przedmiot, imie_p, nazwisko_p, ocena, data));
    }
    else
    {
        cout << "Nie znaleziono studenta o podanym albumie" << endl;
    }
}

void znaj()
{
    cout << "Wpisz nazwisko studenta: ";
    string nazwisko;
    cin >> nazwisko;

    auto it = find_if(begin(student), end(student), [&](const Student& s) { return s.nazwisko == nazwisko; });

    if (it != end(student))
    {
        cout << "Wynik wyszukiwania: " << *it << endl;
    }
    else
    {
        cout << "Nie znaleziono studenta o nazwisku " << nazwisko << endl;
    }
}

void edit()
{
    int album;
    cout << "Podaj album studenta do edycji: ";
    cin >> album;

    auto it = find_if(student.begin(), student.end(), [&](const Student& s) { return s.album == album; });
    if (it != student.end())
    {
        Student* s = &(*it);
        int w;
        cout << "Wybierz dane do edycji:" << endl
             << " 1 Imie" << endl
             << " 2 Nazwisko" << endl
             << " 3 Aktualny semestr" << endl
             << " 4 Nr albumu" << endl
             << " 5 Wszystkie pola" << endl
             << "Wybor: " << endl;
        cin >> w;
        switch (w)
        {
        case 1:
            cout << "Nowe imie: ";
            cin >> s->imie;
            break;
        case 2:
            cout << "Nowe nazwisko: ";
            cin >> s->nazwisko;
            break;
        case 3:
            cout << "Aktualny semestr: ";
            cin >> s->aktSem;
            while (s->aktSem < 1 || s->aktSem > 7)
            {
                cout << "Niepoprawna wartosc (wpisz 1-7): ";
                cin >> s->aktSem;
            }
            s->historiaSemestrow.clear();
            for (int i = 1; i <= s->aktSem; ++i)
            {
                s->historiaSemestrow.emplace_back(i);
            }
            break;
        case 4:
            cout << "Wprowadz numer albumu: ";
            cin >> s->album;
            break;
        case 5:
            s->edytujDane();
            break;
        default:
            cout << "Niepoprawny wybor." << endl;
            break;
        }
    }
    else
    {
        cout << "Nie znaleziono studenta o podanym albumie" << endl;
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

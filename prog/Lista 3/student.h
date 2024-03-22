#ifndef student_header
#define student_header

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

struct Student {
    std::string imie;
    std::string nazwisko;
    int album;
    std::string kierunek;
    int semestr;
};

void dodajStudenta(std::vector<Student> &studenci) {
    Student nowyStudent;
    std::cout << "Imie: ";
    std::cin >> nowyStudent.imie;
    std::cout << "Nazwisko: ";
    std::cin >> nowyStudent.nazwisko;
    std::cout << "Nr albumu (ID): ";
    std::cin >> nowyStudent.album;
    std::cout << "Kierunek studiow: ";
    std::cin >> nowyStudent.kierunek;
    std::cout << "Numer semestru: ";
    std::cin >> nowyStudent.semestr;
    studenci.push_back(nowyStudent);
}

void edytujStudenta(std::vector<Student> &studenci) {
    int album;
    std::cout << "\nWybrales \"Edytuj Studenta\". \nPodaj numer albumu studenta (ID) do edycji jego danych: ";
    std::cin >> album;
    for (Student &student : studenci) {
        if (student.album == album) {
            std::cout << "Zamien imie " << student.imie << " na: ";
            std::cin >> student.imie;
            std::cout << "Zamien nazwisko " << student.nazwisko << " na: ";
            std::cin >> student.nazwisko;
            std::cout << "Zamien kierunek " << student.kierunek << " na: ";
            std::cin >> student.kierunek;
            std::cout << "Zamien numer semestru " << student.semestr << " na: ";
            std::cin >> student.semestr;
            std::cout << "Zamien numer albumu " << student.album << " na: ";
            std::cin >> student.album;
            std::cout << "Dane studenta zostaly zaktualizowane.\n";
            return;
        }
    }
    std::cout << "Nie znaleziono studenta o podanym nr ID.\n";
}

void usunStudenta(std::vector<Student> &studenci) {
    int album;
    std::cout << "\nWybrales \"Usun studenta\". Podaj nr albumu studenta do usuniecia: ";
    std::cin >> album;
    for (auto it = studenci.begin(); it != studenci.end(); it++) {
        if (it->album == album) {
            studenci.erase(it);
            std::cout << "Student zostal usuniety.\n";
            return;
        }
    }
    std::cout << "Nie znaleziono studenta o podanym numerze albumu.\n";
}

void wyswietlWynik(const Student &student, const std::string &kryterium) {
    std::cout << "Imie i nazwisko: " << student.imie << " " << student.nazwisko <<
    "\nNr albumu: " << student.album <<
    "\nKierunek: " << student.kierunek <<
    "\nSemestr: " << student.semestr << "\n" << std::endl;
}

void wyszukajStudentow(std::vector<Student> &studenci) {
    std::string kryterium;
    std::cout << "\nWybrales \"Wyszukaj studentow\". Wybierz pole wyszukiwania:\n";
    std::cout << " 1. Imie\n";
    std::cout << " 2. Nazwisko\n";
    std::cout << " 3. Nr albumu\n";
    std::cout << " 4. Kierunek\n";
    std::cout << " 5. Semestr\n";
    std::cout << "Wybor: ";
    std::cin >> kryterium;

    std::string fraza;
    std::cout << "Wyszukaj: ";
    std::cin >> fraza;

    if (kryterium == "1" || kryterium == "2" || kryterium == "4") {
        std::transform(fraza.begin(), fraza.end(), fraza.begin(), ::tolower);
    }

    std::cout << "\nZnalezieni studenci:\n";
    for (const Student &student : studenci) {
        std::string imie = student.imie;
        std::transform(imie.begin(), imie.end(), imie.begin(), ::tolower);
        std::string nazwisko = student.nazwisko;
        std::transform(nazwisko.begin(), nazwisko.end(), nazwisko.begin(), ::tolower);
        std::string kierunek = student.kierunek;
        std::transform(kierunek.begin(), kierunek.end(), kierunek.begin(), ::tolower);

        if (kryterium == "1" && imie.find(fraza) != std::string::npos) {
            wyswietlWynik(student, kryterium);
        }
        else if (kryterium == "2" && nazwisko.find(fraza) != std::string::npos) {
            wyswietlWynik(student, kryterium);
        }
        else if (kryterium == "3" && std::to_string(student.album) == fraza) {
            wyswietlWynik(student, kryterium);
        }
        else if (kryterium == "4" && kierunek.find(fraza) != std::string::npos) {
            wyswietlWynik(student, kryterium);
        }
        else if (kryterium == "5" && std::to_string(student.semestr) == fraza) {
            wyswietlWynik(student, kryterium);
        } 
}
}
#endif
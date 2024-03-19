#include <iostream>
#include <vector>
#include "student.h"

int main() {
    std::vector<Student> studenci;

    char wybor;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Dodaj studenta\n";
        std::cout << "2. Edytuj studenta\n";
        std::cout << "3. Usun studenta\n";
        std::cout << "4. Wyszukaj studentow\n";
        std::cout << "5. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;

        switch (wybor) {
            case '1':
                dodajStudenta(studenci);
                break;
            case '2':
                edytujStudenta(studenci);
                break;
            case '3':
                usunStudenta(studenci);
                break;
            case '4':
                wyszukajStudentow(studenci);
                break;
            case '5':
                std::cout << "Koniec programu.\n";
                break;
            default:
                std::cout << "Nieprawidlowy wybor. Wybierz ponownie.\n";
        }
    } while (wybor != '5');

    return 0;
}

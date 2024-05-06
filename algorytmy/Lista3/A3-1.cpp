#include <iostream>
#include <fstream>
#include <string>

struct lista
{
    std::string imie;
    std::string nazwisko;
    std::string PESEL;
    int wiek;
    lista *pop;
};

lista *dodajElement(lista *pocz, std::string imie, std::string nazwisko, std::string PESEL, int wiek)
{
    lista *nowyElement = new lista;
    nowyElement->imie = imie;
    nowyElement->nazwisko = nazwisko;
    nowyElement->PESEL = PESEL;
    nowyElement->wiek = wiek;
    nowyElement->pop = pocz;
    return nowyElement;
}

lista *zdejmijElement(lista *pocz)
{
    if (pocz)
    {
        lista *temp = pocz;
        pocz = pocz->pop;
        std::cout << "Usuniety element: " << temp->imie << " " << temp->nazwisko << ", PESEL: " << temp->PESEL << ", wiek: " << temp->wiek << "\n";
        delete temp;
    }
    return pocz;
}

void wypiszStos(lista *pocz)
{
    lista *temp = pocz;
    while (temp)
    {
        std::cout << "Imie i nazwisko: " << temp->imie << " " << temp->nazwisko << ", PESEL: " << temp->PESEL << ", wiek: " << temp->wiek << "\n";
        temp = temp->pop;
    }
}

void zapiszDoPliku(lista *pocz, const std::string &nazwaPliku)
{
    std::ofstream plik(nazwaPliku);
    if (plik.is_open())
    {
        lista *temp = pocz;
        while (temp)
        {
            plik << temp->imie << " " << temp->nazwisko << ", " << temp->PESEL << ", " << temp->wiek << " lat\n";
            temp = temp->pop;
        }
        plik.close();
        std::cout << "Zapis do pliku " << nazwaPliku << " powiodl sie." << std::endl;
    }
    else
    {
        std::cout << "Nie udalo sie otworzyc pliku " << nazwaPliku << " do zapisu." << std::endl;
    }
}

void wyswietlMenu()
{
    std::cout << "a. Dodaj element\n";
    std::cout << "b. Zdejmij element\n";
    std::cout << "c. Pokaz zawartosc stosu\n";
    std::cout << "d. Zapisz dane do pliku\n";
    std::cout << "f. Zakoncz program\n";
    std::cout << "Wybierz funkcje: ";
}

bool sprawdzStos(lista *pocz)
{
    if (pocz == nullptr)
    {
        std::cout << "Nie mozna wykonac wybranej funkcji. Stos jest pusty!\n" << std::endl;
        return true;
    }
    return false;
}

int main()
{
    lista *pocz = nullptr;
    char wybor;
    std::string imie, nazwisko, PESEL;
    int wiek;

    do
    {
        wyswietlMenu();
        std::cin >> wybor;
        switch (wybor)
        {
        case 'a':
            bool valid;
            std::cout << "Imie: ";
            std::cin.ignore();
            std::getline(std::cin, imie);
            std::cout << "Nazwisko: ";
            std::getline(std::cin, nazwisko);
            std::cout << "PESEL: ";
            do
            {
                std::cin >> PESEL;
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
                    std::cout << "PESEL musi skladac sie z 11 cyfr. Wprowadz ponownie: ";
                }
            } while (PESEL.length() != 11 || !valid);
            std::cout << "Wiek: ";
            do
            {
                std::cin >> wiek;
                if (wiek < 1 || wiek > 125)
                {
                    std::cout << "Wprowadz ponownie: ";
                }
            } while (wiek < 1 || wiek > 125);
            pocz = dodajElement(pocz, imie, nazwisko, PESEL, wiek);
            break;
            std::cout << std::endl;
        case 'b':
            if (!sprawdzStos(pocz))
            {
                pocz = zdejmijElement(pocz);
            }
            std::cout << std::endl;
            break;
        case 'c':
            if (!sprawdzStos(pocz))
            {
                wypiszStos(pocz);
            }
            std::cout << std::endl;
            break;
        case 'd':
            if (!sprawdzStos(pocz))
            {
                zapiszDoPliku(pocz, "dane.txt");
                std::cout << "Dane zapisane do pliku dane.txt\n" << std::endl;
            }
            break;
        case 'f':
            while (pocz)
            {
                pocz = zdejmijElement(pocz);
            }
            std::cout << "Program zakonczony.";
            break;
        default:
            std::cout << "Nieznana opcja\n";
            break;
        }
    } while (wybor != 'f');

    return 0;
}
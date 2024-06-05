#include <iostream>
#include <fstream>
#include <string>

struct Node
{
    std::string imie;
    std::string nazwisko;
    std::string PESEL;
    int wiek;
    Node *prev;
};

Node *dodajElement(Node *head, std::string imie, std::string nazwisko, std::string PESEL, int wiek)
{
    Node *nowy = new Node;
    nowy->imie = imie;
    nowy->nazwisko = nazwisko;
    nowy->PESEL = PESEL;
    nowy->wiek = wiek;
    nowy->prev = head;
    return nowy;
}

Node *zdejmijElement(Node *head)
{
    if (head)
    {
        Node *temp = head;
        head = head->prev;
        std::cout << "Usuniety element: " << temp->imie << " " << temp->nazwisko << ", PESEL: " << temp->PESEL << ", wiek: " << temp->wiek << "\n";
        delete temp;
    }
    return head;
}

void wypiszStos(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        std::cout << "Imie i nazwisko: " << temp->imie << " " << temp->nazwisko << ", PESEL: " << temp->PESEL << ", wiek: " << temp->wiek << "\n";
        temp = temp->prev;
    }
}

void zapiszDoPliku(Node *head, const std::string &nazwaPliku)
{
    std::ofstream plik(nazwaPliku);
    if (plik.is_open())
    {
        Node *temp = head;
        while (temp)
        {
            plik << temp->imie << " " << temp->nazwisko << ", " << temp->PESEL << ", " << temp->wiek << " lat\n";
            temp = temp->prev;
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

bool sprawdzStos(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Nie mozna wykonac wybranej funkcji. Stos jest pusty!\n" << std::endl;
        return true;
    }
    return false;
}

int main()
{
    Node *head = nullptr;
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
            head = dodajElement(head, imie, nazwisko, PESEL, wiek);
            break;
            std::cout << std::endl;
        case 'b':
            if (!sprawdzStos(head))
            {
                head = zdejmijElement(head);
            }
            std::cout << std::endl;
            break;
        case 'c':
            if (!sprawdzStos(head))
            {
                wypiszStos(head);
            }
            std::cout << std::endl;
            break;
        case 'd':
            if (!sprawdzStos(head))
            {
                zapiszDoPliku(head, "dane.txt");
                std::cout << "Dane zapisane do pliku dane.txt\n" << std::endl;
            }
            break;
        case 'f':
            while (head)
            {
                head = zdejmijElement(head);
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
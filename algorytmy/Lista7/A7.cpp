#include <iostream>
#include <vector>
#include <climits>

struct Drzewo {
    int liczba;
    Drzewo* lewy;
    Drzewo* prawy;
};

Drzewo* utworzElement(int liczba) {
    Drzewo* nowyElement = new Drzewo();
    if (!nowyElement) {
        return NULL;
    }
    nowyElement->liczba = liczba;
    nowyElement->lewy = nowyElement->prawy = NULL;
    return nowyElement;
}

Drzewo* dodajElement(Drzewo* element, int liczba) {
    if (element == NULL) {
        element = utworzElement(liczba);
        return element;
    }

    if (liczba < element->liczba) {
        element->lewy = dodajElement(element->lewy, liczba);
    }
    else {
        element->prawy = dodajElement(element->prawy, liczba);
    }

    return element;
}

Drzewo* minWartosc(Drzewo* element) {
    Drzewo* current = element;
    while (current && current->lewy != NULL)
        current = current->lewy;
    return current;
}

Drzewo* usunElement(Drzewo* element, int liczba) {
    if (element == NULL) return element;
    if (liczba < element->liczba)
        element->lewy = usunElement(element->lewy, liczba);
    else if (liczba > element->liczba)
        element->prawy = usunElement(element->prawy, liczba);
    else {
        if (element->lewy == NULL) {
            Drzewo* temp = element->prawy;
            delete element;
            return temp;
        }
        else if (element->prawy == NULL) {
            Drzewo* temp = element->lewy;
            delete element;
            return temp;
        }
        Drzewo* temp = minWartosc(element->prawy);
        element->liczba = temp->liczba;
        element->prawy = usunElement(element->prawy, temp->liczba);
    }
    return element;
}

void zwolnijPamiec(Drzewo* element) {
    if (element == NULL) return;
    zwolnijPamiec(element->lewy);
    zwolnijPamiec(element->prawy);
    delete element;
}

void inOrder(Drzewo* temp) {
    if (temp == NULL)
        return;

    inOrder(temp->lewy);
    std::cout << temp->liczba << ' ';
    inOrder(temp->prawy);
}

void postOrder(Drzewo* temp) {
    if (temp == NULL)
        return;

    postOrder(temp->lewy);
    postOrder(temp->prawy);
    std::cout << temp->liczba << ' ';
}

void preOrder(Drzewo* temp) {
    if (temp == NULL)
        return;

    std::cout << temp->liczba << ' ';
    preOrder(temp->lewy);
    preOrder(temp->prawy);
}

void menu(Drzewo* element) {
    int wybor;
    do {
        std::cout << "\n";
        std::cout << "  1. Dodaj element\n";
        std::cout << "  2. Usun element\n";
        std::cout << "  3. Wyswietl wszystkie elementy\n";
        std::cout << "  4. Przejdz metoda Inorder\n";
        std::cout << "  5. Przejdz metoda Postrder\n";
        std::cout << "  6. Przejdz metoda Preorder\n";
        std::cout << "  7. Zakoncz program\n";
        std::cout << "Wybor: ";
        std::cin >> wybor;

        switch (wybor) {
            case 1: {
                int wartosc;
                std::cout << "Dodaj element: ";
                std::cin >> wartosc;
                element = dodajElement(element, wartosc);
                break;
            }
            case 2: {
                int wartosc;
                std::cout << "Usun element: ";
                std::cin >> wartosc;
                element = usunElement(element, wartosc);
                break;
            }
            case 3: {
                std::cout << "Wszystkie elementy: ";
                inOrder(element);
                std::cout << "\n";
                break;
            }
            case 4: {
                std::cout << "Inorder: ";
                inOrder(element);
                std::cout << "\n";
                break;
            }
            case 5: {
                std::cout << "Postorder: ";
                postOrder(element);
                std::cout << "\n";
                break;
            }
            case 6: {
                std::cout << "Preorder: ";
                preOrder(element);
                std::cout << "\n";
                break;
            }
            case 7: {
                std::cout << "Koniec programu...\n";
                zwolnijPamiec(element);
                element = NULL;
                return;
            }
            default: {
                std::cout << "Nieprawidlowy wybor.\n";
                break;
            }
        }
    } while (true);
}

int main() {
    Drzewo* element = NULL;
    int wartosc;
    char wybor;
    std::cout << "Podaj wartosc korzenia: ";
    std::cin >> wartosc;
    element = utworzElement(wartosc);
    menu(element);
    return 0;
}
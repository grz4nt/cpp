#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

struct Subscriber {
    std::string name;
    std::string phone;
};

class AVLTree {
    struct Node {
        Subscriber data;
        Node* left;
        Node* right;
        int height;
    };

    Node* root;

    // ... (implementacja metod drzewa AVL)

public:
    void insert(Subscriber sub) {
        // ... (implementacja wstawiania)
    }

    void remove(std::string name) {
        // ... (implementacja usuwania)
    }

    Subscriber* find(std::string name) {
        // ... (implementacja wyszukiwania)
    }

    void print() {
        // ... (implementacja wyświetlania)
    }

    void saveToFile(std::string filename) {
        std::ofstream file(filename, std::ios::binary);
        // ... (implementacja zapisu do pliku)
    }

    void loadFromFile(std::string filename) {
        std::ifstream file(filename, std::ios::binary);
        // ... (implementacja odczytu z pliku)
    }
};
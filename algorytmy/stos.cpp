#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void add(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = head;
        head = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "\n" << temp->data;
            temp = temp->prev;
        }
        cout << endl;
    }
    
    void remove() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->prev;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.display();
    return 0;
}
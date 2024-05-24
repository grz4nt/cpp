#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void add(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "\n" << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
    void remove(int data) {
        if (head == nullptr) {
            return;
        }
        
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        Node* curr = head;
        Node* prev = nullptr;
        
        while (curr != nullptr && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }
        
        if (curr == nullptr) {
            return;
        }
        
        prev->next = curr->next;
        delete curr;
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
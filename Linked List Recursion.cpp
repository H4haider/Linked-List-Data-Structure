#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

    
    void printRecursive(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        printRecursive(node->next);
    }

  
    Node* insertAtBeginning(Node* node, int value) {
        Node* newNode = new Node(value);
        newNode->next = node;
        return newNode;
    }

    
    Node* insertAtEnd(Node* node, int value) {
        if (!node) return new Node(value);
        node->next = insertAtEnd(node->next, value);
        return node;
    }

   
    Node* insertAtPosition(Node* node, int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return node;
        }
        if (pos == 1) {
            Node* newNode = new Node(value);
            newNode->next = node;
            return newNode;
        }
        if (!node) {
            cout << "Position out of bounds!\n";
            return node;
        }
        node->next = insertAtPosition(node->next, value, pos - 1);
        return node;
    }

    
    Node* deleteByValue(Node* node, int value) {
        if (!node) return nullptr;
        if (node->data == value) {
            Node* temp = node->next;
            delete node;
            return temp;
        }
        node->next = deleteByValue(node->next, value);
        return node;
    }

    
    Node* deleteAtPosition(Node* node, int pos) {
        if (!node || pos < 1) return node;
        if (pos == 1) {
            Node* temp = node->next;
            delete node;
            return temp;
        }
        node->next = deleteAtPosition(node->next, pos - 1);
        return node;
    }

    
    int searchRecursive(Node* node, int value, int index) {
        if (!node) return -1;
        if (node->data == value) return index;
        return searchRecursive(node->next, value, index + 1);
    }

public:
    LinkedList() {
        head=nullptr;
    }


    void insertBeginning(int value) {
        head = insertAtBeginning(head, value);
        print();
    }

    void insertEnd(int value) {
        head = insertAtEnd(head, value);
        print();
    }

    void insertAt(int value, int pos) {
        head = insertAtPosition(head, value, pos);
        print();
    }

    void deleteValue(int value) {
        head = deleteByValue(head, value);
        print();
    }

    void deleteAt(int pos) {
        head = deleteAtPosition(head, pos);
        print();
    }

    int search(int value) {
        return searchRecursive(head, value, 1);
    }

    void print() {
        cout << "List: ";
        printRecursive(head);
        cout << endl;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertBeginning(10);    
    list.insertEnd(20);           
    list.insertEnd(30);           
    list.insertAt(15, 2);         
    list.insertAt(5, 1);         
    list.insertAt(50, 10);       

    list.deleteValue(15);         
    list.deleteAt(1);             
    list.deleteAt(10);            

    int value = 20;
    int pos = list.search(value);
    if (pos != -1)
        cout << value << " found at position: " << pos << endl;
    else
        cout << value << " not found\n";

    return 0;
}

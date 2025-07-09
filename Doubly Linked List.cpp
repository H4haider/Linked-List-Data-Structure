#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

    Node* insertAtBeginning(Node* node, int val) {
        Node* newNode = new Node(val);
        newNode->next = node;
        if (node) node->prev = newNode;
        return newNode;
    }

    Node* insertAtEnd(Node* node, int val) {
        if (!node) return new Node(val);
        node->next = insertAtEnd(node->next, val);
        if (node->next) node->next->prev = node;
        return node;
    }

 
    Node* insertAtPosition(Node* node, int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid position\n";
            return node;
        }
        if (pos == 1) {
            Node* newNode = new Node(val);
            newNode->next = node;
            if (node) node->prev = newNode;
            return newNode;
        }
        if (!node) {
            cout << "Position out of bounds\n";
            return node;
        }
        node->next = insertAtPosition(node->next, val, pos - 1);
        if (node->next) node->next->prev = node;
        return node;
    }


    Node* deleteByValue(Node* node, int val) {
        if (!node) return nullptr;
        if (node->data == val) {
            Node* temp = node->next;
            delete node;
            if (temp) temp->prev = nullptr;
            return temp;
        }
        node->next = deleteByValue(node->next, val);
        if (node->next) node->next->prev = node;
        return node;
    }

 
    Node* deleteAtPosition(Node* node, int pos) {
        if (!node || pos <= 0) return node;
        if (pos == 1) {
            Node* temp = node->next;
            delete node;
            if (temp) temp->prev = nullptr;
            return temp;
        }
        node->next = deleteAtPosition(node->next, pos - 1);
        if (node->next) node->next->prev = node;
        return node;
    }

  
    int searchValue(Node* node, int val, int index) {
        if (!node) return -1;
        if (node->data == val) return index;
        return searchValue(node->next, val, index + 1);
    }

    
    void printForward(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        printForward(node->next);
    }

    
    void printReverse(Node* node) {
        if (!node) return;
        printReverse(node->next);
        cout << node->data << " ";
    }

    Node* findLast(Node* node) {
        if (!node || !node->next) return node;
        return findLast(node->next);
    }


    bool isPalindromeHelper(Node*& left, Node* right) {
        if (!right) return true;
        bool res = isPalindromeHelper(left, right->next);
        if (!res || left->data != right->data) return false;
        left = left->next;
        return true;
    }

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertBeginning(int val) {
        head = insertAtBeginning(head, val);
        print();
    }

    void insertEnd(int val) {
        head = insertAtEnd(head, val);
        print();
    }

    void insertAt(int val, int pos) {
        head = insertAtPosition(head, val, pos);
        print();
    }

    void deleteValue(int val) {
        head = deleteByValue(head, val);
        print();
    }

    void deleteAt(int pos) {
        head = deleteAtPosition(head, pos);
        print();
    }

    int search(int val) {
        return searchValue(head, val, 1);
    }

    void print() {
        cout << "List (forward): ";
        printForward(head);
        cout << "\nList (reverse): ";
        printReverse(head);
        cout << "\n";
    }

    bool isPalindrome() {
        Node* left = head;
        return isPalindromeHelper(left, head);
    }

    
    ~DoublyLinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

// Driver
int main() {
    DoublyLinkedList list;

    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(2);
    list.insertEnd(1);

    if (list.isPalindrome())
        cout << "The list is a palindrome.\n";
    else
        cout << "The list is not a palindrome.\n";

    list.insertAt(99, 3);  
    list.deleteValue(2);
    list.deleteAt(4);     

    int pos = list.search(99);
    if (pos != -1)
        cout << "Value 99 found at position: " << pos << endl;
    else
        cout << "Value 99 not found.\n";

    return 0;
}

// Data Structure Used: Singly Circular Linked List 

/*First of all we will traverse to the starting node the, according to the nodes
to skip we will skip the in between nodes and then we will delete the very next
node to it, we'll keep repeating this process untill only single node is legt which
is considered as winner.*/

#include <iostream>
using namespace std;

// Node structure
template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T val) : data(val), next(nullptr) {}
};

// Circular Linked List class
template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    void addNode(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    T solve(int start, int skip) {
        if (!head) return -1;

        Node<T>* current = head;
        for (int i = 1; i < start; ++i) {
            current = current->next; }

        while (current->next != current) {
            for (int i = 0; i < skip; ++i){
                current = current->next;}

            Node<T>* toDelete = current->next;
            current->next = toDelete->next;
            if(toDelete == head) {
            head = head->next;}
            delete toDelete;
        }

        T win = current->data;
        delete current;
        head = nullptr;
        return win;
    }

};

int main() {
    CircularLinkedList<int> circle;
    int choice;

    do {
        
        cout << "1. Start the Game\n2. Exit the Program\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int n, start, skip;
            cout << "Enter the number of people in the circle: ";
            cin >> n;
            cout << "Enter the starting person: ";
            cin >> start;
            cout << "Enter the number of persons to be skipped: ";
            cin >> skip;

           
            for (int i = 1; i <= n; i++) {
                circle.addNode(i); }

          
            int win = circle.solve(start, skip);
            cout << "\nThe winner is person number: " << win << "\n";

        }
    } while (choice != 2);

    cout << "\nProgram exited.\n";
    
    return 0;
}

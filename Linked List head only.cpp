#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class LinkedList {
private:
    Node* head;
public:

    LinkedList(){
        head=nullptr;
    }

    void insert(int value) {
        Node* nn=new Node;
        nn->data=value;
        nn->next=nullptr;
        
        if (head == nullptr) {
            head = nn;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
                temp->next = nn;
        }
    }

    void printRecursive(Node* head) {
        
        if(head==nullptr) {
            return;
        }
        cout<<head->data<<" ";
        printRecursive(head->next);
    }
    
    void display() {
        printRecursive(head);
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    list.display();

    return 0;
}

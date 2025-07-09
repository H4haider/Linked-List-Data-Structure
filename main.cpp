#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

class Linkedlist {
protected:
	Node* head;
	Node* tail;
public:
	Linkedlist() {
		head = nullptr;
		tail = nullptr;
	}
	virtual void insertAtTail(int) = 0;
	virtual void insertAtHead(int) = 0;
	virtual void displayFromHead() = 0;
	virtual void displayFromTail() = 0;
	virtual bool isEmpty() = 0;
	virtual int deleteFromTail() = 0;
	virtual int deleteFromHead() = 0;
	virtual bool deleteValue(int) = 0;
};

class MyLL:public Linkedlist {
public:
	MyLL(): Linkedlist() {}
	void insertAtTail(int val) {
		Node* nn = new Node;
		nn->data = val;
		nn->next = nullptr;
		nn->prev = nullptr;

		if (head == nullptr && tail == nullptr) {
			head = nn;
			tail = nn;
			return;
		}

		else {
			tail->next = nn;
			nn->prev = tail;
			tail = nn;
		}
	}

	void insertAtHead(int val) {
		Node* nn = new Node;
		nn->data = val;
		nn->next = nullptr;
		nn->prev = nullptr;

		if (head == nullptr && tail == nullptr) {
			head = nn;
			tail = nn;
			return;
		}

		else {
			head->prev = nn;
			nn->next = head;
			head = nn;
		}
	}
	void displayFromHead() {
		if (head == nullptr && tail == nullptr) {
			cout << "Linked List is Empty." << endl;
			return;
		}

			Node* temp = head;
			while (temp != nullptr) {
				cout << temp->data << " ";
				temp = temp->next;
			}
	}
	void displayFromTail() {
		if (head == nullptr && tail == nullptr) {
			cout << "Linked List is Empty." << endl;
			return;
		}

		Node* temp = tail;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->prev;
		}
	}

	bool isEmpty() {
		return head == nullptr && tail == nullptr;
	}
	int deleteFromTail() {
		if (isEmpty()) {
			cout << "LinkedList is Empty" << endl;
			return;
		} 

		if (head == tail) {
			int retval = head->data;
			delete head;
			head = nullptr;
			return retval;
		}
		
		int retval = tail->data;
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
		return retval;
	}

	int deleteFromHead() {
		if (isEmpty()) {
			cout << "Linked List is Empty." << endl;
			return NULL;
		}

		if (head == tail) {
			int retval = head->data;
			delete tail;
			tail = nullptr;
			head = nullptr;
			return retval;
		}

		else {
			int retval = head->data;
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
			return retval;
		}
	}

	bool deleteValue(int val) {
		if (isEmpty()) {
			cout << "LinkedList is Empty. " << endl;
			return;
		}

		if (head == tail) {
			if (head->data = val) {
				delete head;
				head = nullptr;
				tail = nullptr;
				return true;
			}
		}

		if (head->data = val) {
			deleteFromHead();
			return true;
		}

		if (tail->data == val) {
			deleteFromTail();
			return true;
		}

		else {
			Node* temp = head;
			while (1) {
				if (temp->data == val) {
					break;
				}
				else {
					temp = temp->next;
				}
			}

			temp->prev->next = temp->next;
			delete temp;
			temp = nullptr;
			return true;
		}
		return false;
	}
}; 

int main() {
	MyLL L1;
	L1.insertAtHead(1);
	L1.insertAtTail(2);
	L1.insertAtHead(4);
	L1.insertAtHead(5);
	L1.deleteValue(4);
	L1.displayFromHead();

	return 0;
}
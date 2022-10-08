#include <iostream>
using namespace std;

class Node {
public:
	int a;
	//int b;
	Node* next;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() { head = nullptr; }

	void insertAtEnd(int);
	void deleteNode(int); //implement this
	void print();
};

void LinkedList::insertAtEnd(int data) {
	Node* temp = new Node;
	temp->a = data;
	//temp->b = b;
	temp->next = nullptr;

	if (!head) {
		head = temp;
		return;
	}
	else {
		Node* last = head;
		while (last->next) last = last->next;
		last->next = temp;
	}
}

void LinkedList::print() {
	Node* pom = head;
	while (pom) {
		cout << pom->a << " ";
		pom = pom->next;
	}
	cout << endl;
}

//taken from geeksforsth idr
void LinkedList::deleteNode(int nodeOffset) {
    Node* temp1 = head, * temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    if (ListLen < nodeOffset) {
        cout << "Index out of range"
            << endl;
        return;
    }

    temp1 = head;

    if (nodeOffset == 1) {

        // Update head
        head = head->next;
        delete temp1;
        return;
    }
    while (nodeOffset-- > 1) {

        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;

    delete temp1;
}
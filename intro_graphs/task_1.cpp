#include <iostream>
#include <vector>
#include <algorithm>
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

vector<LinkedList> wczytajListeKrawedzi();
void printAdjacencyList(vector<LinkedList> cl);

int main() {
	/*vector<int> A = { 11, 2, 3, 4 };
	A.push_back(10);
	vector<Node> B;*/
	vector<LinkedList> graf = wczytajListeKrawedzi();
	printAdjacencyList(graf);

	return 0;
}

vector<LinkedList> wczytajListeKrawedzi() {
	int wierzch, kraw;
	cout << "Podaj liczbe wierzcholkow i krawedzi: ";
	cin >> wierzch >> kraw;

	vector<LinkedList> graph(wierzch);
	int a, b;
	cout << "Wczytaj a i b:" << endl;
	for (int i = 0; i < kraw; i++) {
		cin >> a >> b;
		graph[a].insertAtEnd(b);
		graph[b].insertAtEnd(a);
	}
	return graph;
}

void printAdjacencyList(vector<LinkedList> cl) {
	for (int i = 0; i < cl.size(); i++) {
		LinkedList ob = cl[i];
		cout << i << ". ";
		ob.print();
	}
}

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
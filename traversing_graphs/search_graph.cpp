#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Node {
public:
	int a;
	Node* next;
};

class LinkedList {
private:
	int roz = 1; //rozmiar jest odpowiednio zwiekszany przy dod. elem.
public:
	Node* head; // niezbedne zeby miec dostep do wartosci w node
	LinkedList() { head = nullptr; }
	
	void insertAtEnd(int);
	void deleteNode(int);
	void print();
	int size();
};

class Graph {

    vector<LinkedList> adjacencyList;

public:
    void addNode();
    void printAdjacencyList();
};

vector<LinkedList> wczytajListeKrawedzi();
void printAdjacencyList(vector<LinkedList>);
set<int> czyNalezyDoGrafu(vector<LinkedList>, int, int); //iterative first depth search

int main() {
	//inicjalizacja listy sasiedztwa
	/*
	Dla danych z zajec wyglada tak:
	wierzcholek sasiedztwo
	0.			1
	1.			2
	2.			1
	(gdzie sąsiedztwo to lista powiązana)
	*/
	vector<LinkedList> graf = wczytajListeKrawedzi();
	cout << graf[1].size() << endl;
	printAdjacencyList(graf);
	
	cout << endl << endl;

	//testy dla danych z zajęć		output:
	czyNalezyDoGrafu(graf, 0, 1); //nalezy
	czyNalezyDoGrafu(graf, 1, 2); //nalezy
	czyNalezyDoGrafu(graf, 0, 2); //nalezy
	czyNalezyDoGrafu(graf, 2, 3); //nie nalezy
	return 0;
}

set<int> czyNalezyDoGrafu(vector<LinkedList> graph, int a, int b) {
	set<int> visited;
	vector<int> stack;
	stack.push_back(a);

	int node;
	while (stack.size() != 0) {
		node = stack[stack.size() - 1];
		stack.pop_back();

		if (node == b) {
			cout << "nalezy" << endl;
			return visited;
		}

		if (!(visited.find(node) != visited.end())) {
			visited.insert(node);
			LinkedList l = graph[node];
			for (int i = 0; i < l.size(); i++) {
				stack.push_back(l.head->a);
				l.head = l.head->next;
			}
		}
	}

	cout << "nie nalezy" << endl;
	return visited;
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
	cout << endl;
	for (int i = 0; i < cl.size(); i++) {
		LinkedList ob = cl[i];
		cout << i << ". ";
		ob.print();
	}
}

void LinkedList::insertAtEnd(int data) {
	Node* temp = new Node;
	temp->a = data;
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
	++roz;
}

int LinkedList::size() {
	return roz;
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
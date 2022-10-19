#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

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

    int V = 0;
    vector<LinkedList> adjacencyList;

public:
    Graph() = default;

    void addNode(int u, int v, bool bidir) {
        adjacencyList[u].insertAtEnd(v);
        V++;
        if (bidir == true) {
            adjacencyList[v].insertAtEnd(u);
        }
    }

    void printAdjacencyList() {
        cout << endl;
        for (int i = 0; i < adjacencyList.size(); i++) {
            LinkedList ob = adjacencyList[i];
            cout << i << ". ";
            ob.print();
		}
	}
    void dfs(int start) {
		set<int> visited;
		stack<int> Stack;
		Stack.push(start);
		while (!Stack.empty()) {
			int s = Stack.top();
			Stack.pop();
			if (visited.find(s) == visited.end()) {
				cout << s << " ";
				visited.insert(s);
			}

			LinkedList l = adjacencyList[s];

			for (int i = 0; i < l.size(); i++) {
				Stack.push(l.head->a);
				l.head = l.head->next;
			}
		}
	}
};

// vector<LinkedList> wczytajListeKrawedzi();
// void printAdjacencyList(vector<LinkedList>);
 //iterative depth first search

int main() {
	Graph grafik;
	grafik.addNode(0, 1, false);
	grafik.addNode(1, 2,false);
	grafik.addNode(1, 3,false);
	grafik.addNode(2, 4,false);
	grafik.addNode(2,5,false);
	grafik.addNode(3,6,false);
	grafik.addNode(3,7,false);
	grafik.printAdjacencyList();
	

	
	
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
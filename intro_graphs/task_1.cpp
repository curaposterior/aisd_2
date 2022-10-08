//task from class num. 1 6.10.2022
/*
Napisz program który: 

1. Odczyta z klawiatury definicję grafu (ilośc wierzchołków, ilość krawędzi, krawędzie po kolei)

Przykład:
3
2
0 1
1 2

2. Zapisze graf w postaci listy lub macierzy sąsiedstwa lub macierzy incydencji
3. Odpowie na pytanie czy podane prez użytkownika wierzołki a i b są ze sobą połączone (przez dowolną liczbę krawędzi)
*/
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int a; 
    int b;
    node* next;
};

node* wczytajListeKrawedzi();
void insertAtEnd(node*& first, int too, int dystans);
void print(node* head);
bool czyPolaczone(node* lista, int a, int b);

int main() {
    node* head = nullptr;
    
    head = wczytajListeKrawedzi();
    print(head);

    //testy polaczen (zwraca wartosc bool ale wyswietla odpowiedni komunikat)
    czyPolaczone(head, 0, 1);
    czyPolaczone(head, 1, 2);
    czyPolaczone(head, 1, 1);
    czyPolaczone(head, 4, 3);

    return 0;
}

bool czyPolaczone(node* lista, int a, int b) {
    node* pom = lista;

    while (pom) {
        if (a == pom->a && b == pom->b) {
            cout << "Polaczenie istnieje." << endl;
            return true;
        }
        else if (b == pom->a && a == pom->b) {
            cout << "Polaczenie istnieje." << endl;
            return true;
        }
        else {
            pom = pom->next;
        }
    }
    cout << "Polaczenie nie istnieje" << endl;
    return false;
}

node* wczytajListeKrawedzi() {
    node* head = nullptr;
    int wierz, kraw;
    cout << "Wczytaj liczbe wierzcholkow: ";
    cin >> wierz;
    cout << "Wczytaj liczbe krawedzi: ";
    cin >> kraw;

    int a, b;
    cout << "Wczytaj a i b: " << endl;
    for (int i = 0; i < kraw; i++) {
        cin >> a >> b;
        insertAtEnd(head, a, b);
    }

    return head;
}

void print(node* head) {
    node* p = head;
    int counter = 1;
    while (p != NULL) {
        cout << counter << ". " << p->a  << " " << p->b << endl;;
        p = p->next;
        counter++;
    }
}

void insertAtEnd(node*& first, int a, int b) {
    node* temp = new node;
    temp->a = a;
    temp->b = b;
    temp->next = nullptr;

    if (!first) {
        first = temp;
        return;
    }
    else {
        node* last = first;
        while (last->next) last = last->next;
        last->next = temp;
    }
}
#!/usr/bin/env python3
from typing import Dict, List

def wczytajListeSasiedztwa() -> Dict[int, List[int]]:
    wierz = int(input("Wczytaj wierzcholki: "))
    kraw =  int(input("Wczytaj liczbe krawedzi: "))
    graph = {key: [] for key in range(wierz)}

    print("Wczytaj po kolei krawedzie (a b):")
    for i in range(kraw):
        a = int(input())
        b = int(input())
        graph[a].append(b)
        graph[b].append(a)

    return  graph

def wypiszGraf(graph: Dict[int, List[int]]) -> None:
    print("Reprezentacja grafu:")
    for key,value in graph.items():
        if (len(value) != 0):
            print(str(key) + ".", value)

if __name__ == '__main__':
    graph = wczytajListeSasiedztwa()
    wypiszGraf(graph)
    print("It works...")
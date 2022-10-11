#!/usr/bin/env python3

def wczytajListeSasiedztwa() -> Dict[int, list[int]]:
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

def wypiszGraf(graph: dict[int, list[int]]) -> None:
    print("Reprezentacja grafu:")
    for key,value in graph.items():
        if (len(value) != 0):
            print(str(key) + ".", value)

#create dsf algo to search if graph has a path from a to b
def dfs(graph: dict[int, list[int]], x: int, target: int) -> bool:
    visited = set()
    stack = [graph[x]]
    while (len(stack) != 0):
        node = stack[-1]
        if (node == target):
            return True

        if node not in visited:
            visited.add(node)
            for nb in graph[node]:
                stack.append(nb)        

if __name__ == '__main__':
    graph = wczytajListeSasiedztwa()
    wypiszGraf(graph)

    print("It works...")
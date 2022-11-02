import math
from heapq import heappush, heappop


class Graph:

    def __init__(self, V: int):
        self.V = V
        self.adjList = {key: [] for key in range(self.V)} #lista sasiedztwa, slownik - {skad: }
        self.matrix = None #macierz sasiedztwa
        self.edgeList = None #slownik {(skad, dokad): waga}

    def addNode(self, u, v, w): #skad, dokad, waga
        self.adjList[u].append((v, w))

    def readMatrix(self, filename: str) -> list[list[int]]:
        with open(filename, 'r') as f:
            data = f.read().split()
        
        matrix = [[0] * self.V for _ in range(self.V)]

        for i in range(self.V*self.V):
            matrix[i // self.V][i%self.V] = int(data[i])
        
        self.matrix = matrix

    def convertMatrixToAdjList(self):
        for i in range(self.V):
            for j in range(self.V):
                if (self.matrix[i][j] != 0):
                    self.adjList[i].append((j, self.matrix[i][j]))

    def addEdge(self, s, d, w):
        if (s, d) in self.edgeList:
            self.edgeList[(s, d)] = min(self.edgeList[(s, d)], w)
        else:
            self.edgeList[(s, d)] = w

    def convertAdjListToEdgeList(self):
        self.edgeList = {}
        for key,value in self.adjList.items():
            for elem in value:
                self.addEdge(key, elem[0], elem[1])

    def printMatrix(self):
        for elem in self.matrix:
            print(elem)

    def printEdgeList(self):
        for key, value in self.edgeList.items():
            print(key, ":", value)

    def printAdjList(self):
        for key in self.adjList.keys():
            print(str(key) + ":", self.adjList[key])
    
    def prims_algo_edgelist(self):
        visited = [0]*self.V
        processed = set()
        mst = [] #minimal spanning tree
        cost = 0
        
        q = []
        min_cost = math.inf 
        i_s, i_d = 0, 0 
        for (s, d), w in self.edgeList.items():
            if min_cost > w:
                min_cost = w
                i_s, i_d = s, d

        heappush(q, (min_cost, i_s, i_d))

        while len(mst) < self.V-1 and q: #dopoki nie dodamy wszystkich V
            w, s, d = heappop(q)
            if (visited[s] + visited[d]) < 2:
                visited[d] = 1
                visited[s] = 1
                cost += w 
                mst.append([s, d, w])
                processed.discard((s, d))
            
                for edge, w in self.edgeList.items():
                    if (s in edge) or (d in edge):
                        if (visited[edge[0]] + visited[edge[1]]) < 2 and (edge[0], edge[1]) not in processed:
                            heappush(q, (w, edge[0], edge[1]))
                            processed.add((edge[0], edge[1]))
            
        return mst, cost #krotka (list[list[int]], int)


if __name__ == '__main__':
    grafik = Graph(8)
    grafik.readMatrix('graf.txt')
    print(grafik.matrix)
    grafik.convertMatrixToAdjList()
    grafik.printAdjList()
    grafik.convertAdjListToEdgeList()
    print(grafik.edgeList)
    mst = grafik.prims_algo_edgelist()
    print(mst)
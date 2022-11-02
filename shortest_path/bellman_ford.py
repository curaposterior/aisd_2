#only works in directed graph

class Graph:
    def __init__(self, V: int):
        self.V = V
        self.edgeList = []

    def convertMatrixToAdjList(self):
        for i in range(self.V):
            for j in range(self.V):
                if (self.matrix[i][j] != 0):
                    self.adjList[i].append((j, self.matrix[i][j]))

    def addEdge(self, s, d, w):
        self.edgeList.append((s, d, w))

    def bellman_ford(self, start):
        dist = [float("inf")] * self.V
        
        dist[start] = 0

        for _ in range(self.V-1): #relax edges
            for s, d, w in self.edgeList:
                if (dist[s] != float("inf") and dist[s] + w < dist[d]):
                    dist[d] = dist[s] + w

        for s, d, w in self.edgeList:
            if (dist[s] != float("inf") and dist[s] + w < dist[d]):
                raise Exception("Negative cycle detected")
        
        return {i: dist[i] for i in range(len(dist))}


if __name__ == '__main__':
    g = Graph(6)
    g.addEdge(0,1,2)
    g.addEdge(0,2,4)
    g.addEdge(1,2,1)
    g.addEdge(1,3,7)
    g.addEdge(2,4,3)
    g.addEdge(3,5,1)
    g.addEdge(4,3,2)
    g.addEdge(4,5,5)
    shrt = g.bellman_ford(0)
    print(shrt)
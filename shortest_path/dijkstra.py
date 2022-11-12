#undirected graph and directed graph
from collections import defaultdict
import heapq

class Graph:
    def __init__(self, V: int):
        self.V = V
        self.edgeList = []
        self.adjList = {}

    def convertMatrixToAdjList(self):
        for i in range(self.V):
            for j in range(self.V):
                if (self.matrix[i][j] != 0):
                    self.adjList[i].append((j, self.matrix[i][j]))

    def convertEdgeListToAdjList(self):
        self.adjList = {key: [] for key in range(self.V)}
        for edge in self.edgeList:
            self.adjList[edge[0]].append((edge[1], edge[2]))
        
    def addEdge(self, s, d, w):
        self.edgeList.append((s, d, w))

    def printEdgeList(self):
        print("From/To/Weight")
        for elem in self.edgeList:
            print(elem)

    def printAdjList(self):
        print("Vertices: Edges")
        for key,val in self.adjList.items():
            print(key, val)

    def dijkstra(self, edgeList, N: int, K: int) -> int:
        graph = defaultdict(dict)
        
        for frm, to, cost in edgeList:
            graph[frm][to] = cost
        
        distances = { i: float("inf") for i in range(0, N)}
        distances[K] = 0
        min_dist = [(0,K)]
        visited = set()

        while min_dist:
            
            cur_dist, cur = heapq.heappop(min_dist)
            if cur in visited: continue
            visited.add(cur)    
            
            for neighbor in graph[cur]:
                if neighbor in visited: continue
                this_dist = cur_dist + graph[cur][neighbor]
                if this_dist  < distances[neighbor]:
                    distances[neighbor] = this_dist
                    heapq.heappush(min_dist, (this_dist, neighbor))
            
        return distances #dict -> {V: weight of shortest path}




if __name__ == '__main__':
    my_Graph = Graph(6)
    my_Graph.addEdge(0,1,2)
    my_Graph.addEdge(0,2,4)
    my_Graph.addEdge(1,2,1)
    my_Graph.addEdge(1,3,7)
    my_Graph.addEdge(2,4,3)
    my_Graph.addEdge(3,5,1)
    my_Graph.addEdge(4,3,2)
    my_Graph.addEdge(4,5,5)

    my_Graph.printEdgeList()
    my_Graph.convertEdgeListToAdjList()
    my_Graph.printAdjList()
    dj = my_Graph.dijkstra(my_Graph.edgeList, my_Graph.V, 0)
    print(dj)
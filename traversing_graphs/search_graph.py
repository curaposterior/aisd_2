from queue import Queue


class Graph:

    def __init__(self, V):
        self.l_wierzch = V
        self.adjList = {key: [] for key in range(self.l_wierzch)}
    
    def addNode(self, u, v):
        self.adjList[u].append(v)

    def printGraph(self):
        for key in self.adjList.keys():
            print(str(key) + ":", self.adjList[key])
    
    def dfs(self, start): #wgłąb
        print("\nDFS:")
        visited = [False] * self.l_wierzch
        stack = []
        stack.append(start)
    
        while (len(stack)):
            s = stack[-1]
            stack.pop()

            if (not visited[s]):
                print(s, end=" ")
                visited[s] = True

            for n in self.adjList[s]:
                if (not visited[n]):
                    stack.append(n)

    def bfs(self, start): #wszerz
        print("\nBFS")
        
        q = Queue()
        visited = [False] * self.l_wierzch
        q.put(start)
        visited[start] = True

        while (not q.empty()):
            node = q.get()
            print(node, end=" ")
            for uv in self.adjList[node]:
                if visited[uv] == False:
                    q.put(uv)
                    visited[uv] = True


if __name__ == '__main__':
    grafik = Graph(8)

    grafik.addNode(0,1)
    grafik.addNode(1,0)
    grafik.addNode(1,2)
    grafik.addNode(1,3)
    grafik.addNode(2,4)
    grafik.addNode(2,5)
    grafik.addNode(3,6)
    grafik.addNode(3,7)
    
    grafik.printGraph()
    grafik.dfs(1)
    grafik.bfs(1)
    
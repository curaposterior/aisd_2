class Graph(object):
   def __init__(self, num_vertices):
       self.V = num_vertices
       self.graph = []
  
   def add_edge(self, u, v, w):
       self.graph.append([u, v, w])
  
   # union find
   def find(self, root, i):
       if root[i] == i:
           return i
       return self.find(root, root[i])
  
   def union(self, root, rank, x, y):
       xroot = self.find(root, x)
       yroot = self.find(root, y)
       if rank[xroot] < rank[yroot]:
           root[xroot] = yroot
       elif rank[xroot] > rank[yroot]:
           root[yroot] = xroot
       else:
           root[yroot] = xroot
           rank[xroot] += 1
  
   # applying kruskal's
   def kruskals(self):
       # initialize an empty MST list
       result = []
       # initialize i, the iteration and e, the edges added
       i, e  = 0, 0
       # sort the graph based on edge weights
       self.graph = sorted(self.graph, key = lambda item: item[2])
       # initialize root, which keeps track of the MST
       # and the rank, which keeps track of where each node belongs
       root = []
       rank = []
       for node in range(self.V):
           root.append(node)
           rank.append(0)
 
       # while we haven't yet added each edge
       # increment iterator and run the union find algorithm
       while e < self.V - 1:
           u, v, w = self.graph[i]
           i = i + 1
           x = self.find(root, u)
           y = self.find(root, v)
           if x != y:
               e = e + 1
               result.append([u, v, w])
               self.union(root, rank, x, y)
 
       for u, v, w in result:
           print(f'{u} - {v}: {w}')
       return result


if __name__ == '__main__':
    g = Graph(5)
    g.add_edge(0,1,3)
    g.add_edge(0,2,4)
    g.add_edge(0,3,5)
    g.add_edge(1,0,3)
    g.add_edge(2,0,4)
    g.add_edge(2,3,2)
    g.add_edge(2,4,1)
    g.add_edge(3,0,5)
    g.add_edge(3,2,2)
    g.add_edge(3,3,4)
    g.add_edge(4,2,1)
    g.add_edge(4,3,3)

    g.kruskals()

    
from collections import defaultdict

class GraphList:
    def __init__(self):
        self.vertices = 0
        self.adj_list = defaultdict(list)
    
    def create(self, v):
        self.vertices = v
        self.adj_list = defaultdict(list)
    
    def add_edge(self, src, dest):
        if src < self.vertices and dest < self.vertices:
            self.adj_list[src].append(dest)
            self.adj_list[dest].append(src)
    
    def count_vertices(self): return self.vertices
    
    def count_edges(self):
        return sum(len(self.adj_list[i]) for i in range(self.vertices)) // 2
    
    def find_adjacent(self, v): return self.adj_list[v]
    
    def search_vertex(self, v): return 0 <= v < self.vertices
    
    def display(self):
        for i in range(self.vertices):
            print(f"{i}: {self.adj_list[i]}")

g = GraphList()
while True:
    print("\n1.Create 2.Add 3.Count V 4.Count E 5.Adjacent 6.Search 7.Display 0.Exit")
    ch = int(input())
    if ch == 1: g.create(int(input("Vertices: ")))
    elif ch == 2: src, dest = map(int, input("Edge: ").split()); g.add_edge(src, dest)
    elif ch == 3: print("Vertices:", g.count_vertices())
    elif ch == 4: print("Edges:", g.count_edges())
    elif ch == 5: print("Adjacent:", g.find_adjacent(int(input("Vertex: "))))
    elif ch == 6: print("Found" if g.search_vertex(int(input("Vertex: "))) else "Not found")
    elif ch == 7: g.display()
    elif ch == 0: break
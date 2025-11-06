from collections import deque

class GraphMatrix:
    def __init__(self, vertices=0, directed=False):
        self.vertices = vertices
        self.directed = directed
        self.matrix = [[0 for _ in range(vertices)] for _ in range(vertices)]
    
    def add_edge(self, src, dest):
        """Add an edge between source and destination vertices"""
        if 0 <= src < self.vertices and 0 <= dest < self.vertices:
            self.matrix[src][dest] = 1
            if not self.directed:
                self.matrix[dest][src] = 1
            print(f"Edge added: {src} -> {dest}")
            if not self.directed:
                print(f"Edge added: {dest} -> {src} (undirected)")
        else:
            print(f"Invalid vertices: {src}, {dest}")
    
    def remove_edge(self, src, dest):
        """Remove an edge between source and destination vertices"""
        if 0 <= src < self.vertices and 0 <= dest < self.vertices:
            self.matrix[src][dest] = 0
            if not self.directed:
                self.matrix[dest][src] = 0
            print(f"Edge removed: {src} -> {dest}")
        else:
            print(f"Invalid vertices: {src}, {dest}")
    
    def count_vertices(self):
        """Count number of vertices in the graph"""
        return self.vertices
    
    def count_edges(self):
        """Count number of edges in the graph"""
        edges = 0
        for i in range(self.vertices):
            for j in range(self.vertices):
                if self.matrix[i][j] == 1:
                    edges += 1
        
        # For undirected graph, each edge is counted twice
        if not self.directed:
            edges //= 2
        
        return edges
    
    def find_adjacent_vertices(self, vertex):
        """Find all adjacent vertices of a given vertex"""
        if 0 <= vertex < self.vertices:
            adjacent = []
            for i in range(self.vertices):
                if self.matrix[vertex][i] == 1:
                    adjacent.append(i)
            return adjacent
        else:
            print(f"Invalid vertex: {vertex}")
            return []
    
    def search_vertex(self, vertex):
        """Search if a vertex exists in the graph"""
        return 0 <= vertex < self.vertices
    
    def display_graph(self):
        """Display the adjacency matrix"""
        print("\n=== Adjacency Matrix ===")
        print("   ", end="")
        for i in range(self.vertices):
            print(f"{i:2d} ", end="")
        print()
        
        for i in range(self.vertices):
            print(f"{i:2d} ", end="")
            for j in range(self.vertices):
                print(f"{self.matrix[i][j]:2d} ", end="")
            print()
    
    def get_degree(self, vertex):
        """Get degree of a vertex"""
        if 0 <= vertex < self.vertices:
            if self.directed:
                in_degree = sum(self.matrix[i][vertex] for i in range(self.vertices))
                out_degree = sum(self.matrix[vertex][i] for i in range(self.vertices))
                return in_degree, out_degree
            else:
                degree = sum(self.matrix[vertex][i] for i in range(self.vertices))
                return degree
        return None
    
    def graph_analysis(self):
        """Comprehensive graph analysis"""
        print("\n=== Graph Analysis ===")
        print(f"Number of vertices: {self.count_vertices()}")
        print(f"Number of edges: {self.count_edges()}")
        print(f"Graph type: {'Directed' if self.directed else 'Undirected'}")
        
        print(f"\nVertex degrees:")
        for i in range(self.vertices):
            if self.directed:
                in_deg, out_deg = self.get_degree(i)
                print(f"Vertex {i}: In-degree = {in_deg}, Out-degree = {out_deg}")
            else:
                degree = self.get_degree(i)
                print(f"Vertex {i}: Degree = {degree}")
        
        # Memory usage
        memory_usage = self.vertices * self.vertices * 4  # Assuming 4 bytes per integer
        print(f"\nMemory usage: {memory_usage} bytes")
        print(f"Space complexity: O(V²) where V = {self.vertices}")
    
    def dfs(self, start_vertex):
        """Depth-First Search traversal"""
        if not (0 <= start_vertex < self.vertices):
            print("Invalid start vertex!")
            return []
        
        visited = [False] * self.vertices
        result = []
        
        def dfs_util(vertex):
            visited[vertex] = True
            result.append(vertex)
            
            for i in range(self.vertices):
                if self.matrix[vertex][i] == 1 and not visited[i]:
                    dfs_util(i)
        
        dfs_util(start_vertex)
        return result
    
    def bfs(self, start_vertex):
        """Breadth-First Search traversal"""
        if not (0 <= start_vertex < self.vertices):
            print("Invalid start vertex!")
            return []
        
        visited = [False] * self.vertices
        queue = deque([start_vertex])
        visited[start_vertex] = True
        result = []
        
        while queue:
            vertex = queue.popleft()
            result.append(vertex)
            
            for i in range(self.vertices):
                if self.matrix[vertex][i] == 1 and not visited[i]:
                    visited[i] = True
                    queue.append(i)
        
        return result
    
    def create_graph_interactive(self):
        """Create graph interactively"""
        print("\n=== Creating Graph ===")
        try:
            vertices = int(input("Enter number of vertices: "))
            if vertices <= 0:
                print("Invalid number of vertices!")
                return
            
            directed = input("Is the graph directed? (y/n): ").lower() == 'y'
            
            self.vertices = vertices
            self.directed = directed
            self.matrix = [[0 for _ in range(vertices)] for _ in range(vertices)]
            
            edges = int(input("Enter number of edges: "))
            
            print("Enter edges (source destination):")
            for i in range(edges):
                src, dest = map(int, input(f"Edge {i + 1}: ").split())
                self.add_edge(src, dest)
            
            print("Graph created successfully!")
            
        except ValueError:
            print("Invalid input! Please enter integers only.")

def main():
    graph = GraphMatrix()
    
    print("=== Graph Implementation (Adjacency Matrix) ===")
    print("Adjacency Matrix: 2D array representation")
    print("Space Complexity: O(V²), Time Complexity: O(1) for edge operations\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Create Graph")
        print("2. Add Edge")
        print("3. Remove Edge")
        print("4. Count Vertices")
        print("5. Count Edges")
        print("6. Find Adjacent Vertices")
        print("7. Search Vertex")
        print("8. Display Graph")
        print("9. Graph Analysis")
        print("10. DFS Traversal")
        print("11. BFS Traversal")
        print("12. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                graph.create_graph_interactive()
            
            elif choice == 2:
                src, dest = map(int, input("Enter source and destination vertices: ").split())
                graph.add_edge(src, dest)
            
            elif choice == 3:
                src, dest = map(int, input("Enter source and destination vertices: ").split())
                graph.remove_edge(src, dest)
            
            elif choice == 4:
                count = graph.count_vertices()
                print(f"Number of vertices: {count}")
            
            elif choice == 5:
                count = graph.count_edges()
                print(f"Number of edges: {count}")
            
            elif choice == 6:
                vertex = int(input("Enter vertex: "))
                adjacent = graph.find_adjacent_vertices(vertex)
                print(f"Adjacent vertices of {vertex}: {adjacent}")
            
            elif choice == 7:
                vertex = int(input("Enter vertex to search: "))
                exists = graph.search_vertex(vertex)
                print(f"Vertex {vertex} {'exists' if exists else 'does not exist'} in the graph")
            
            elif choice == 8:
                graph.display_graph()
            
            elif choice == 9:
                graph.graph_analysis()
            
            elif choice == 10:
                start = int(input("Enter starting vertex for DFS: "))
                result = graph.dfs(start)
                print(f"DFS traversal starting from vertex {start}: {result}")
            
            elif choice == 11:
                start = int(input("Enter starting vertex for BFS: "))
                result = graph.bfs(start)
                print(f"BFS traversal starting from vertex {start}: {result}")
            
            elif choice == 12:
                print("Exiting program...")
                break
            
            else:
                print("Invalid choice! Please try again.")
        
        except ValueError:
            print("Invalid input! Please enter a valid number.")
        except KeyboardInterrupt:
            print("\nProgram interrupted. Exiting...")
            break

if __name__ == "__main__":
    main()
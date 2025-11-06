from collections import deque, defaultdict

class GraphList:
    def __init__(self, vertices=0, directed=False):
        self.vertices = vertices
        self.directed = directed
        self.adj_list = defaultdict(list)
    
    def add_edge(self, src, dest):
        """Add an edge between source and destination vertices"""
        if 0 <= src < self.vertices and 0 <= dest < self.vertices:
            self.adj_list[src].append(dest)
            if not self.directed:
                self.adj_list[dest].append(src)
            print(f"Edge added: {src} -> {dest}")
            if not self.directed:
                print(f"Edge added: {dest} -> {src} (undirected)")
        else:
            print(f"Invalid vertices: {src}, {dest}")
    
    def remove_edge(self, src, dest):
        """Remove an edge between source and destination vertices"""
        if 0 <= src < self.vertices and 0 <= dest < self.vertices:
            if dest in self.adj_list[src]:
                self.adj_list[src].remove(dest)
                print(f"Edge removed: {src} -> {dest}")
            
            if not self.directed and src in self.adj_list[dest]:
                self.adj_list[dest].remove(src)
        else:
            print(f"Invalid vertices: {src}, {dest}")
    
    def count_vertices(self):
        """Count number of vertices in the graph"""
        return self.vertices
    
    def count_edges(self):
        """Count number of edges in the graph"""
        edges = 0
        for vertex in range(self.vertices):
            edges += len(self.adj_list[vertex])
        
        # For undirected graph, each edge is counted twice
        if not self.directed:
            edges //= 2
        
        return edges
    
    def find_adjacent_vertices(self, vertex):
        """Find all adjacent vertices of a given vertex"""
        if 0 <= vertex < self.vertices:
            return list(self.adj_list[vertex])
        else:
            print(f"Invalid vertex: {vertex}")
            return []
    
    def search_vertex(self, vertex):
        """Search if a vertex exists in the graph"""
        return 0 <= vertex < self.vertices
    
    def display_graph(self):
        """Display the adjacency list"""
        print("\n=== Adjacency List ===")
        for i in range(self.vertices):
            adjacent = self.adj_list[i]
            print(f"Vertex {i}: {' -> '.join(map(str, adjacent)) if adjacent else 'NULL'}")
    
    def get_degree(self, vertex):
        """Get degree of a vertex"""
        if 0 <= vertex < self.vertices:
            if self.directed:
                out_degree = len(self.adj_list[vertex])
                in_degree = 0
                for v in range(self.vertices):
                    if vertex in self.adj_list[v]:
                        in_degree += 1
                return in_degree, out_degree
            else:
                degree = len(self.adj_list[vertex])
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
        
        # Memory usage estimation
        total_edges = sum(len(self.adj_list[i]) for i in range(self.vertices))
        memory_usage = self.vertices * 8 + total_edges * 4  # Rough estimation
        print(f"\nMemory usage: ~{memory_usage} bytes")
        print(f"Space complexity: O(V + E) where V = {self.vertices}, E = {self.count_edges()}")
    
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
            
            for neighbor in self.adj_list[vertex]:
                if not visited[neighbor]:
                    dfs_util(neighbor)
        
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
            
            for neighbor in self.adj_list[vertex]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)
        
        return result
    
    def has_cycle(self):
        """Check if the graph has a cycle"""
        if self.directed:
            return self._has_cycle_directed()
        else:
            return self._has_cycle_undirected()
    
    def _has_cycle_directed(self):
        """Check cycle in directed graph using DFS"""
        WHITE, GRAY, BLACK = 0, 1, 2
        color = [WHITE] * self.vertices
        
        def dfs_cycle(vertex):
            if color[vertex] == GRAY:
                return True
            if color[vertex] == BLACK:
                return False
            
            color[vertex] = GRAY
            for neighbor in self.adj_list[vertex]:
                if dfs_cycle(neighbor):
                    return True
            
            color[vertex] = BLACK
            return False
        
        for vertex in range(self.vertices):
            if color[vertex] == WHITE:
                if dfs_cycle(vertex):
                    return True
        return False
    
    def _has_cycle_undirected(self):
        """Check cycle in undirected graph using DFS"""
        visited = [False] * self.vertices
        
        def dfs_cycle(vertex, parent):
            visited[vertex] = True
            
            for neighbor in self.adj_list[vertex]:
                if not visited[neighbor]:
                    if dfs_cycle(neighbor, vertex):
                        return True
                elif neighbor != parent:
                    return True
            
            return False
        
        for vertex in range(self.vertices):
            if not visited[vertex]:
                if dfs_cycle(vertex, -1):
                    return True
        return False
    
    def is_connected(self):
        """Check if the graph is connected (for undirected graphs)"""
        if self.directed:
            print("Connectivity check is for undirected graphs only")
            return False
        
        if self.vertices == 0:
            return True
        
        # Start DFS from vertex 0
        visited = [False] * self.vertices
        
        def dfs_connect(vertex):
            visited[vertex] = True
            for neighbor in self.adj_list[vertex]:
                if not visited[neighbor]:
                    dfs_connect(neighbor)
        
        dfs_connect(0)
        
        # Check if all vertices are visited
        return all(visited)
    
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
            self.adj_list = defaultdict(list)
            
            edges = int(input("Enter number of edges: "))
            
            print("Enter edges (source destination):")
            for i in range(edges):
                src, dest = map(int, input(f"Edge {i + 1}: ").split())
                self.add_edge(src, dest)
            
            print("Graph created successfully!")
            
        except ValueError:
            print("Invalid input! Please enter integers only.")

def main():
    graph = GraphList()
    
    print("=== Graph Implementation (Adjacency List) ===")
    print("Adjacency List: Linked list representation")
    print("Space Complexity: O(V + E), Efficient for sparse graphs\n")
    
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
        print("12. Check Cycle")
        print("13. Check Connectivity")
        print("14. Exit")
        
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
                has_cycle = graph.has_cycle()
                print(f"Graph has cycle: {'Yes' if has_cycle else 'No'}")
            
            elif choice == 13:
                is_connected = graph.is_connected()
                print(f"Graph is connected: {'Yes' if is_connected else 'No'}")
            
            elif choice == 14:
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
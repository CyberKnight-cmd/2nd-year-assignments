# Assignment 10: Graph Implementation

## Overview
This assignment implements Graph data structure using two different representations: Adjacency Matrix and Adjacency List in both C and Python. Graphs are fundamental data structures used to represent relationships between objects, consisting of vertices (nodes) and edges (connections).

## Folder Structure
```
Assignment 10/
├── Systematic Solutions/
│   ├── C Programs/
│   │   ├── 1_graph_adjacency_matrix.c
│   │   └── 2_graph_adjacency_list.c
│   └── Python Programs/
│       ├── 1_graph_adjacency_matrix.py
│       └── 2_graph_adjacency_list.py
├── Compressed Solutions/
│   ├── C Programs/
│   │   ├── 1_graph_adjacency_matrix.c
│   │   └── 2_graph_adjacency_list.c
│   └── Python Programs/
│       ├── 1_graph_adjacency_matrix.py
│       └── 2_graph_adjacency_list.py
└── README.md
```

## Graph Theory Fundamentals

### Graph Definition
A Graph G = (V, E) consists of:
- **V**: Set of vertices (nodes)
- **E**: Set of edges (connections between vertices)

### Graph Types
1. **Directed Graph (Digraph)**: Edges have direction (A → B)
2. **Undirected Graph**: Edges are bidirectional (A ↔ B)
3. **Weighted Graph**: Edges have associated weights/costs
4. **Unweighted Graph**: All edges have equal weight

### Graph Terminology
- **Adjacent Vertices**: Vertices connected by an edge
- **Degree**: Number of edges incident to a vertex
- **Path**: Sequence of vertices connected by edges
- **Cycle**: Path that starts and ends at the same vertex
- **Connected Graph**: Path exists between any two vertices

## Graph Representations

### 1. Adjacency Matrix
A 2D array where matrix[i][j] = 1 if there's an edge from vertex i to vertex j.

**Advantages:**
- O(1) time to check if edge exists
- Simple implementation
- Good for dense graphs
- Easy to implement graph algorithms

**Disadvantages:**
- O(V²) space complexity
- Inefficient for sparse graphs
- Adding/removing vertices is expensive

**Memory Layout:**
```
    0  1  2  3
0 [ 0  1  1  0 ]
1 [ 1  0  0  1 ]
2 [ 1  0  0  1 ]
3 [ 0  1  1  0 ]
```

### 2. Adjacency List
Array of linked lists where each list contains adjacent vertices.

**Advantages:**
- O(V + E) space complexity
- Efficient for sparse graphs
- Fast vertex addition/removal
- Memory efficient

**Disadvantages:**
- O(V) time to check if edge exists
- More complex implementation
- Extra memory for pointers

**Memory Layout:**
```
0: [1, 2]
1: [0, 3]
2: [0, 3]
3: [1, 2]
```

## Core Operations Implementation

### 1. Count Vertices
```c
// Adjacency Matrix
int countVertices(Graph* g) {
    return g->vertices;
}

// Adjacency List
int countVertices(Graph* g) {
    return g->vertices;
}
```
**Time Complexity**: O(1)

### 2. Count Edges
```c
// Adjacency Matrix
int countEdges(Graph* g) {
    int edges = 0;
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            if (g->matrix[i][j] == 1) edges++;
        }
    }
    return g->directed ? edges : edges / 2;
}

// Adjacency List
int countEdges(Graph* g) {
    int edges = 0;
    for (int i = 0; i < g->vertices; i++) {
        Node* current = g->adjList[i];
        while (current != NULL) {
            edges++;
            current = current->next;
        }
    }
    return g->directed ? edges : edges / 2;
}
```
**Time Complexity**: 
- Adjacency Matrix: O(V²)
- Adjacency List: O(V + E)

### 3. Find Adjacent Vertices
```c
// Adjacency Matrix
void findAdjacentVertices(Graph* g, int vertex) {
    for (int i = 0; i < g->vertices; i++) {
        if (g->matrix[vertex][i] == 1) {
            printf("%d ", i);
        }
    }
}

// Adjacency List
void findAdjacentVertices(Graph* g, int vertex) {
    Node* current = g->adjList[vertex];
    while (current != NULL) {
        printf("%d ", current->vertex);
        current = current->next;
    }
}
```
**Time Complexity**:
- Adjacency Matrix: O(V)
- Adjacency List: O(degree(vertex))

### 4. Search Vertex
```c
int searchVertex(Graph* g, int vertex) {
    return (vertex >= 0 && vertex < g->vertices);
}
```
**Time Complexity**: O(1)

## Graph Traversal Algorithms

### 1. Depth-First Search (DFS)
Explores as far as possible along each branch before backtracking.

```c
void dfsUtil(Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    // For adjacency matrix
    for (int i = 0; i < g->vertices; i++) {
        if (g->matrix[vertex][i] == 1 && !visited[i]) {
            dfsUtil(g, i, visited);
        }
    }
}
```

**Applications:**
- Topological sorting
- Cycle detection
- Connected components
- Path finding

**Time Complexity**: O(V + E)
**Space Complexity**: O(V)

### 2. Breadth-First Search (BFS)
Explores all vertices at current depth before moving to next depth level.

```c
void bfs(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);
        
        for (int i = 0; i < g->vertices; i++) {
            if (g->matrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
```

**Applications:**
- Shortest path (unweighted)
- Level-order traversal
- Connected components
- Bipartite graph checking

**Time Complexity**: O(V + E)
**Space Complexity**: O(V)

## Complexity Comparison

| Operation | Adjacency Matrix | Adjacency List |
|-----------|------------------|----------------|
| Space | O(V²) | O(V + E) |
| Add Edge | O(1) | O(1) |
| Remove Edge | O(1) | O(V) |
| Check Edge | O(1) | O(V) |
| Find Adjacent | O(V) | O(degree) |
| Add Vertex | O(V²) | O(1) |
| Remove Vertex | O(V²) | O(V + E) |

## Advanced Graph Algorithms

### 1. Cycle Detection
```c
// For undirected graphs using DFS
int hasCycleUndirected(Graph* g) {
    int visited[MAX_VERTICES] = {0};
    
    for (int i = 0; i < g->vertices; i++) {
        if (!visited[i]) {
            if (dfsHasCycle(g, i, visited, -1)) {
                return 1;
            }
        }
    }
    return 0;
}
```

### 2. Connectivity Check
```c
int isConnected(Graph* g) {
    if (g->vertices == 0) return 1;
    
    int visited[MAX_VERTICES] = {0};
    dfsUtil(g, 0, visited);
    
    for (int i = 0; i < g->vertices; i++) {
        if (!visited[i]) return 0;
    }
    return 1;
}
```

## Applications of Graphs

### 1. Social Networks
- **Vertices**: Users
- **Edges**: Friendships/Connections
- **Algorithms**: Friend recommendations, community detection

### 2. Transportation Networks
- **Vertices**: Cities/Stations
- **Edges**: Roads/Routes
- **Algorithms**: Shortest path, route optimization

### 3. Computer Networks
- **Vertices**: Computers/Routers
- **Edges**: Network connections
- **Algorithms**: Routing protocols, network topology

### 4. Web Graph
- **Vertices**: Web pages
- **Edges**: Hyperlinks
- **Algorithms**: PageRank, web crawling

## Program Features

### Systematic Solutions
- **Interactive Menu System**: User-friendly interface
- **Both Representations**: Matrix and List implementations
- **Graph Analysis**: Comprehensive statistics and properties
- **Traversal Algorithms**: DFS and BFS implementations
- **Memory Management**: Proper allocation and deallocation
- **Error Handling**: Input validation and edge cases
- **Educational Features**: Algorithm explanations and complexity analysis

### Compressed Solutions
- **Minimal Implementation**: Essential functionality only
- **Core Operations**: All required functions in compact form
- **Efficient Code**: Optimized for brevity while maintaining correctness

## Usage Instructions

### Compilation (C Programs)
```bash
gcc 1_graph_adjacency_matrix.c -o graph_matrix
gcc 2_graph_adjacency_list.c -o graph_list
```

### Execution
```bash
# C Programs
./graph_matrix
./graph_list

# Python Programs
python 1_graph_adjacency_matrix.py
python 2_graph_adjacency_list.py
```

### Sample Graph Creation
```
Vertices: 4
Edges: 4
Edge connections:
0 1
1 2
2 3
3 0

Adjacency Matrix:
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0

Adjacency List:
0: 1 -> 3
1: 0 -> 2
2: 1 -> 3
3: 2 -> 0
```

## Key Learning Outcomes

1. **Graph Representations**: Understanding different ways to store graphs
2. **Space-Time Tradeoffs**: Matrix vs List efficiency analysis
3. **Graph Algorithms**: Traversal and analysis techniques
4. **Real-world Applications**: Practical uses of graph theory
5. **Algorithm Design**: Recursive and iterative approaches
6. **Memory Management**: Dynamic allocation in graph structures

## Best Practices

### 1. Choosing Representation
- **Dense Graphs (E ≈ V²)**: Use Adjacency Matrix
- **Sparse Graphs (E << V²)**: Use Adjacency List
- **Frequent Edge Queries**: Use Adjacency Matrix
- **Dynamic Graphs**: Use Adjacency List

### 2. Implementation Guidelines
- **Input Validation**: Check vertex bounds and edge validity
- **Memory Management**: Free allocated memory in C
- **Error Handling**: Handle invalid operations gracefully
- **Efficiency**: Choose appropriate algorithms for operations

### 3. Algorithm Selection
- **DFS**: For path finding, cycle detection, topological sort
- **BFS**: For shortest path, level-order operations
- **Both**: For connectivity and component analysis

This comprehensive graph implementation provides a solid foundation for understanding graph theory and its applications in computer science and real-world problem solving.
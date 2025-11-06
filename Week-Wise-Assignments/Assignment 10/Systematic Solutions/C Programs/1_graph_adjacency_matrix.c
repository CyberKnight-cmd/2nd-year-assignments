#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int vertices;
    int directed;
} Graph;

void initGraph(Graph* g, int vertices, int directed) {
    g->vertices = vertices;
    g->directed = directed;
    
    // Initialize matrix with 0s
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->matrix[i][j] = 0;
        }
    }
    
    printf("Graph initialized with %d vertices (%s)\n", 
           vertices, directed ? "Directed" : "Undirected");
}

void addEdge(Graph* g, int src, int dest) {
    if (src >= 0 && src < g->vertices && dest >= 0 && dest < g->vertices) {
        g->matrix[src][dest] = 1;
        
        if (!g->directed) {
            g->matrix[dest][src] = 1;  // For undirected graph
        }
        
        printf("Edge added: %d -> %d\n", src, dest);
        if (!g->directed) {
            printf("Edge added: %d -> %d (undirected)\n", dest, src);
        }
    } else {
        printf("Invalid vertices: %d, %d\n", src, dest);
    }
}

void removeEdge(Graph* g, int src, int dest) {
    if (src >= 0 && src < g->vertices && dest >= 0 && dest < g->vertices) {
        g->matrix[src][dest] = 0;
        
        if (!g->directed) {
            g->matrix[dest][src] = 0;
        }
        
        printf("Edge removed: %d -> %d\n", src, dest);
    } else {
        printf("Invalid vertices: %d, %d\n", src, dest);
    }
}

int countVertices(Graph* g) {
    return g->vertices;
}

int countEdges(Graph* g) {
    int edges = 0;
    
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            if (g->matrix[i][j] == 1) {
                edges++;
            }
        }
    }
    
    // For undirected graph, each edge is counted twice
    if (!g->directed) {
        edges /= 2;
    }
    
    return edges;
}

void findAdjacentVertices(Graph* g, int vertex) {
    if (vertex < 0 || vertex >= g->vertices) {
        printf("Invalid vertex: %d\n", vertex);
        return;
    }
    
    printf("Adjacent vertices of %d: ", vertex);
    int found = 0;
    
    for (int i = 0; i < g->vertices; i++) {
        if (g->matrix[vertex][i] == 1) {
            printf("%d ", i);
            found = 1;
        }
    }
    
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int searchVertex(Graph* g, int vertex) {
    if (vertex >= 0 && vertex < g->vertices) {
        return 1;  // Vertex exists
    }
    return 0;  // Vertex doesn't exist
}

void displayGraph(Graph* g) {
    printf("\n=== Adjacency Matrix ===\n");
    printf("   ");
    for (int i = 0; i < g->vertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->vertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < g->vertices; j++) {
            printf("%2d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

void graphAnalysis(Graph* g) {
    printf("\n=== Graph Analysis ===\n");
    printf("Number of vertices: %d\n", countVertices(g));
    printf("Number of edges: %d\n", countEdges(g));
    printf("Graph type: %s\n", g->directed ? "Directed" : "Undirected");
    
    // Calculate degree for each vertex
    printf("\nVertex degrees:\n");
    for (int i = 0; i < g->vertices; i++) {
        int inDegree = 0, outDegree = 0;
        
        // Calculate out-degree
        for (int j = 0; j < g->vertices; j++) {
            if (g->matrix[i][j] == 1) {
                outDegree++;
            }
        }
        
        // Calculate in-degree
        for (int j = 0; j < g->vertices; j++) {
            if (g->matrix[j][i] == 1) {
                inDegree++;
            }
        }
        
        if (g->directed) {
            printf("Vertex %d: In-degree = %d, Out-degree = %d\n", 
                   i, inDegree, outDegree);
        } else {
            printf("Vertex %d: Degree = %d\n", i, outDegree);
        }
    }
    
    // Memory usage
    int memoryUsage = g->vertices * g->vertices * sizeof(int);
    printf("\nMemory usage: %d bytes\n", memoryUsage);
    printf("Space complexity: O(V²) where V = %d\n", g->vertices);
}

void createGraphInteractive(Graph* g) {
    int vertices, directed, edges, src, dest;
    
    printf("\n=== Creating Graph ===\n");
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices!\n");
        return;
    }
    
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);
    
    initGraph(g, vertices, directed);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }
    
    printf("Graph created successfully!\n");
}

void dfsUtil(Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < g->vertices; i++) {
        if (g->matrix[vertex][i] == 1 && !visited[i]) {
            dfsUtil(g, i, visited);
        }
    }
}

void dfs(Graph* g, int startVertex) {
    if (startVertex < 0 || startVertex >= g->vertices) {
        printf("Invalid start vertex!\n");
        return;
    }
    
    int visited[MAX_VERTICES] = {0};
    
    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfsUtil(g, startVertex, visited);
    printf("\n");
}

void bfs(Graph* g, int startVertex) {
    if (startVertex < 0 || startVertex >= g->vertices) {
        printf("Invalid start vertex!\n");
        return;
    }
    
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    
    printf("BFS traversal starting from vertex %d: ", startVertex);
    
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
    printf("\n");
}

int main() {
    Graph g;
    int choice, vertex, src, dest, result;
    
    printf("=== Graph Implementation (Adjacency Matrix) ===\n");
    printf("Adjacency Matrix: 2D array representation\n");
    printf("Space Complexity: O(V²), Time Complexity: O(1) for edge operations\n\n");
    
    // Initialize with default values
    initGraph(&g, 0, 0);
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create Graph\n");
        printf("2. Add Edge\n");
        printf("3. Remove Edge\n");
        printf("4. Count Vertices\n");
        printf("5. Count Edges\n");
        printf("6. Find Adjacent Vertices\n");
        printf("7. Search Vertex\n");
        printf("8. Display Graph\n");
        printf("9. Graph Analysis\n");
        printf("10. DFS Traversal\n");
        printf("11. BFS Traversal\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createGraphInteractive(&g);
                break;
                
            case 2:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addEdge(&g, src, dest);
                break;
                
            case 3:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                removeEdge(&g, src, dest);
                break;
                
            case 4:
                result = countVertices(&g);
                printf("Number of vertices: %d\n", result);
                break;
                
            case 5:
                result = countEdges(&g);
                printf("Number of edges: %d\n", result);
                break;
                
            case 6:
                printf("Enter vertex: ");
                scanf("%d", &vertex);
                findAdjacentVertices(&g, vertex);
                break;
                
            case 7:
                printf("Enter vertex to search: ");
                scanf("%d", &vertex);
                result = searchVertex(&g, vertex);
                printf("Vertex %d %s in the graph\n", 
                       vertex, result ? "exists" : "does not exist");
                break;
                
            case 8:
                displayGraph(&g);
                break;
                
            case 9:
                graphAnalysis(&g);
                break;
                
            case 10:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &vertex);
                dfs(&g, vertex);
                break;
                
            case 11:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &vertex);
                bfs(&g, vertex);
                break;
                
            case 12:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
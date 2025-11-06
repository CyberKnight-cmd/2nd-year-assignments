#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node** adjList;
    int vertices;
    int directed;
} Graph;

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void initGraph(Graph* g, int vertices, int directed) {
    g->vertices = vertices;
    g->directed = directed;
    
    g->adjList = (Node**)malloc(vertices * sizeof(Node*));
    if (g->adjList == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Initialize all adjacency lists as empty
    for (int i = 0; i < vertices; i++) {
        g->adjList[i] = NULL;
    }
    
    printf("Graph initialized with %d vertices (%s)\n", 
           vertices, directed ? "Directed" : "Undirected");
}

void addEdge(Graph* g, int src, int dest) {
    if (src >= 0 && src < g->vertices && dest >= 0 && dest < g->vertices) {
        // Add edge from src to dest
        Node* newNode = createNode(dest);
        if (newNode != NULL) {
            newNode->next = g->adjList[src];
            g->adjList[src] = newNode;
            printf("Edge added: %d -> %d\n", src, dest);
        }
        
        // For undirected graph, add edge from dest to src
        if (!g->directed) {
            Node* newNode2 = createNode(src);
            if (newNode2 != NULL) {
                newNode2->next = g->adjList[dest];
                g->adjList[dest] = newNode2;
                printf("Edge added: %d -> %d (undirected)\n", dest, src);
            }
        }
    } else {
        printf("Invalid vertices: %d, %d\n", src, dest);
    }
}

void removeEdge(Graph* g, int src, int dest) {
    if (src >= 0 && src < g->vertices && dest >= 0 && dest < g->vertices) {
        // Remove edge from src to dest
        Node* current = g->adjList[src];
        Node* prev = NULL;
        
        while (current != NULL && current->vertex != dest) {
            prev = current;
            current = current->next;
        }
        
        if (current != NULL) {
            if (prev == NULL) {
                g->adjList[src] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Edge removed: %d -> %d\n", src, dest);
        }
        
        // For undirected graph, remove edge from dest to src
        if (!g->directed) {
            current = g->adjList[dest];
            prev = NULL;
            
            while (current != NULL && current->vertex != src) {
                prev = current;
                current = current->next;
            }
            
            if (current != NULL) {
                if (prev == NULL) {
                    g->adjList[dest] = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
            }
        }
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
        Node* current = g->adjList[i];
        while (current != NULL) {
            edges++;
            current = current->next;
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
    Node* current = g->adjList[vertex];
    
    if (current == NULL) {
        printf("None");
    } else {
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
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
    printf("\n=== Adjacency List ===\n");
    for (int i = 0; i < g->vertices; i++) {
        printf("Vertex %d: ", i);
        Node* current = g->adjList[i];
        
        if (current == NULL) {
            printf("NULL");
        } else {
            while (current != NULL) {
                printf("%d", current->vertex);
                if (current->next != NULL) {
                    printf(" -> ");
                }
                current = current->next;
            }
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
        int outDegree = 0;
        int inDegree = 0;
        
        // Calculate out-degree
        Node* current = g->adjList[i];
        while (current != NULL) {
            outDegree++;
            current = current->next;
        }
        
        // Calculate in-degree
        for (int j = 0; j < g->vertices; j++) {
            Node* temp = g->adjList[j];
            while (temp != NULL) {
                if (temp->vertex == i) {
                    inDegree++;
                }
                temp = temp->next;
            }
        }
        
        if (g->directed) {
            printf("Vertex %d: In-degree = %d, Out-degree = %d\n", 
                   i, inDegree, outDegree);
        } else {
            printf("Vertex %d: Degree = %d\n", i, outDegree);
        }
    }
    
    // Memory usage estimation
    int nodeCount = 0;
    for (int i = 0; i < g->vertices; i++) {
        Node* current = g->adjList[i];
        while (current != NULL) {
            nodeCount++;
            current = current->next;
        }
    }
    
    int memoryUsage = g->vertices * sizeof(Node*) + nodeCount * sizeof(Node);
    printf("\nMemory usage: ~%d bytes\n", memoryUsage);
    printf("Space complexity: O(V + E) where V = %d, E = %d\n", 
           g->vertices, countEdges(g));
}

void createGraphInteractive(Graph* g) {
    int vertices, directed, edges, src, dest;
    
    printf("\n=== Creating Graph ===\n");
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    if (vertices <= 0) {
        printf("Invalid number of vertices!\n");
        return;
    }
    
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);
    
    // Free existing graph if any
    if (g->adjList != NULL) {
        for (int i = 0; i < g->vertices; i++) {
            Node* current = g->adjList[i];
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                free(temp);
            }
        }
        free(g->adjList);
    }
    
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
    
    Node* current = g->adjList[vertex];
    while (current != NULL) {
        if (!visited[current->vertex]) {
            dfsUtil(g, current->vertex, visited);
        }
        current = current->next;
    }
}

void dfs(Graph* g, int startVertex) {
    if (startVertex < 0 || startVertex >= g->vertices) {
        printf("Invalid start vertex!\n");
        return;
    }
    
    int* visited = (int*)calloc(g->vertices, sizeof(int));
    if (visited == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfsUtil(g, startVertex, visited);
    printf("\n");
    
    free(visited);
}

void bfs(Graph* g, int startVertex) {
    if (startVertex < 0 || startVertex >= g->vertices) {
        printf("Invalid start vertex!\n");
        return;
    }
    
    int* visited = (int*)calloc(g->vertices, sizeof(int));
    int* queue = (int*)malloc(g->vertices * sizeof(int));
    
    if (visited == NULL || queue == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    int front = 0, rear = 0;
    
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    
    printf("BFS traversal starting from vertex %d: ", startVertex);
    
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);
        
        Node* current = g->adjList[vertex];
        while (current != NULL) {
            if (!visited[current->vertex]) {
                visited[current->vertex] = 1;
                queue[rear++] = current->vertex;
            }
            current = current->next;
        }
    }
    printf("\n");
    
    free(visited);
    free(queue);
}

void freeGraph(Graph* g) {
    if (g->adjList != NULL) {
        for (int i = 0; i < g->vertices; i++) {
            Node* current = g->adjList[i];
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                free(temp);
            }
        }
        free(g->adjList);
        g->adjList = NULL;
    }
}

int main() {
    Graph g = {NULL, 0, 0};
    int choice, vertex, src, dest, result;
    
    printf("=== Graph Implementation (Adjacency List) ===\n");
    printf("Adjacency List: Linked list representation\n");
    printf("Space Complexity: O(V + E), Efficient for sparse graphs\n\n");
    
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
                printf("Freeing memory and exiting...\n");
                freeGraph(&g);
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
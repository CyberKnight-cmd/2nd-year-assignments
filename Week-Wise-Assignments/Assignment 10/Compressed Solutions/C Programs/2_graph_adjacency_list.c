#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[100];
int vertices = 0;

Node* createNode(int v) {
    Node* n = malloc(sizeof(Node));
    n->vertex = v; n->next = NULL;
    return n;
}

void addEdge(int src, int dest) {
    if(src < vertices && dest < vertices) {
        Node* n1 = createNode(dest);
        n1->next = adjList[src];
        adjList[src] = n1;
        
        Node* n2 = createNode(src);
        n2->next = adjList[dest];
        adjList[dest] = n2;
    }
}

int countVertices() { return vertices; }

int countEdges() {
    int edges = 0;
    for(int i = 0; i < vertices; i++) {
        Node* temp = adjList[i];
        while(temp) { edges++; temp = temp->next; }
    }
    return edges / 2; // Undirected
}

void findAdjacent(int v) {
    printf("Adjacent to %d: ", v);
    Node* temp = adjList[v];
    while(temp) {
        printf("%d ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

int searchVertex(int v) {
    return v >= 0 && v < vertices;
}

void display() {
    for(int i = 0; i < vertices; i++) {
        printf("%d: ", i);
        Node* temp = adjList[i];
        while(temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, src, dest, v;
    while(1) {
        printf("\n1.Create 2.Add 3.Count V 4.Count E 5.Adjacent 6.Search 7.Display 0.Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Vertices: "); scanf("%d", &vertices); 
                   for(int i = 0; i < vertices; i++) adjList[i] = NULL; break;
            case 2: printf("Edge: "); scanf("%d %d", &src, &dest); addEdge(src, dest); break;
            case 3: printf("Vertices: %d\n", countVertices()); break;
            case 4: printf("Edges: %d\n", countEdges()); break;
            case 5: printf("Vertex: "); scanf("%d", &v); findAdjacent(v); break;
            case 6: printf("Vertex: "); scanf("%d", &v); printf("%s\n", searchVertex(v) ? "Found" : "Not found"); break;
            case 7: display(); break;
            case 0: return 0;
        }
    }
}
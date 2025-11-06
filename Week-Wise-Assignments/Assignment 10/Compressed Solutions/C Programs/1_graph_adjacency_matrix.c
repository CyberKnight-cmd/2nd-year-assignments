#include <stdio.h>
#define MAX 100

int matrix[MAX][MAX], vertices = 0;

void addEdge(int src, int dest) {
    if(src < vertices && dest < vertices) {
        matrix[src][dest] = 1;
        matrix[dest][src] = 1; // Undirected
    }
}

int countVertices() { return vertices; }

int countEdges() {
    int edges = 0;
    for(int i = 0; i < vertices; i++)
        for(int j = i; j < vertices; j++)
            if(matrix[i][j]) edges++;
    return edges;
}

void findAdjacent(int v) {
    printf("Adjacent to %d: ", v);
    for(int i = 0; i < vertices; i++)
        if(matrix[v][i]) printf("%d ", i);
    printf("\n");
}

int searchVertex(int v) {
    return v >= 0 && v < vertices;
}

void display() {
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int ch, src, dest, v;
    while(1) {
        printf("\n1.Create 2.Add 3.Count V 4.Count E 5.Adjacent 6.Search 7.Display 0.Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Vertices: "); scanf("%d", &vertices); break;
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
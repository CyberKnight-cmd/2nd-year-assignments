#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

typedef struct mygraph{
    int numNodes;
    bool **edges;
}graph;


void destroyGraph(graph *g) {
    if (g == NULL) return;

    if (g->edges != NULL) {
        for (int i = 0; i < g->numNodes; i++) {
            free(g->edges[i]);
        }
        free(g->edges);
    }

    free(g);
}

graph *createGraph(int numberOfNodes) {
    graph *g = malloc(sizeof(graph));
    if (g == NULL) return NULL;

    g->numNodes = numberOfNodes;

    g->edges = calloc(g->numNodes, sizeof(bool *));
    if (g->edges == NULL) {
        free(g);
        return NULL;
    }

    for (int i = 0; i < g->numNodes; i++) {
        g->edges[i] = calloc(g->numNodes, sizeof(bool));
        if (g->edges[i] == NULL) {
            destroyGraph(g);
            return NULL;
        }
    }

    printf("Graph initialized successfully!!\n");
    return g;
}



void printGraph(graph *g) {
    printf("Digraph {\n");
    for (int from = 0; from < g->numNodes; from++) {
        for (int to = 0; to < g->numNodes; to++) {
            if (g->edges[from][to]) {
                printf("  %d -> %d\n", from, to);
            }
        }
    }
    printf("}\n");
}
bool hasEdge(graph *g, int source, int destination){
    assert(g!=NULL);
    assert(source < g->numNodes);
    assert(destination <g->numNodes);
    return g->edges[source][destination];
}

bool addEdge(graph *g, int source, int destination){
    assert(g!=NULL);
    assert(source < g->numNodes);
    assert(destination <g->numNodes);
    if (hasEdge(g, source, destination)) return false;
    else    g->edges[source][destination] = true;
    return true;
}




int main(){
    graph *g = createGraph(5);
    addEdge(g, 0, 1);
    addEdge(g, 3, 0);
    addEdge(g, 4, 3);
    addEdge(g, 0, 4);
    addEdge(g, 0, 3);
    addEdge(g, 0, 2);
    printGraph(g);
    destroyGraph(g);
    return 0;
}
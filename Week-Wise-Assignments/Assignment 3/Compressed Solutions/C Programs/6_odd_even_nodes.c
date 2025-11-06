#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int data; struct Node* next; } Node;
Node* cn(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->next = NULL; return n; }
Node* ial(Node* h, int d) { Node* n = cn(d); if (!h) return n; Node* t = h; while (t->next) t = t->next; t->next = n; return h; }
void printOE(Node* h) {
    printf("Odd: "); Node* t = h; while (t) { if (t->data % 2) printf("%d ", t->data); t = t->next; } printf("\n");
    printf("Even: "); t = h; while (t) { if (!(t->data % 2)) printf("%d ", t->data); t = t->next; } printf("\n");
}
int main() {
    Node* h = NULL; int vals[] = {12, 7, 18, 3, 24, 9, 15, 6};
    for (int i = 0; i < 8; i++) h = ial(h, vals[i]);
    printOE(h);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int data; struct Node* next; } Node;
Node* cn(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->next = NULL; return n; }
Node* ial(Node* h, int d) { Node* n = cn(d); if (!h) return n; Node* t = h; while (t->next) t = t->next; t->next = n; return h; }
int count(Node* h) { int c = 0; while (h) c++, h = h->next; return c; }
int countr(Node* h) { return h ? 1 + countr(h->next) : 0; }
int main() {
    Node* h = NULL; int d, c;
    int vals[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) h = ial(h, vals[i]);
    while (scanf("%d", &c) && c != 5) {
        if (c == 1) scanf("%d", &d), h = ial(h, d);
        else if (c == 2) printf("%d\n", count(h));
        else if (c == 3) printf("%d\n", countr(h));
    }
    return 0;
}
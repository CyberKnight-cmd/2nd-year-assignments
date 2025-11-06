#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int data; struct Node* next; } Node;
Node* cn(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->next = NULL; return n; }
Node* iaf(Node* h, int d) { Node* n = cn(d); n->next = h; return n; }
Node* ial(Node* h, int d) { Node* n = cn(d); if (!h) return n; Node* t = h; while (t->next) t = t->next; t->next = n; return h; }
Node* iaa(Node* h, int d, int p) { if (p == 1) return iaf(h, d); Node* n = cn(d), *t = h; for (int i = 1; i < p-1 && t; i++) t = t->next; if (!t) return ial(h, d); n->next = t->next; t->next = n; return h; }
void disp(Node* h) { while (h) printf("%d -> ", h->data), h = h->next; printf("NULL\n"); }
int main() {
    Node* h = NULL; int c, d, p;
    while (scanf("%d", &c) && c != 6) {
        if (c == 1) scanf("%d", &d), h = iaf(h, d);
        else if (c == 2) scanf("%d", &d), h = ial(h, d);
        else if (c == 3) scanf("%d%d", &d, &p), h = iaa(h, d, p);
        else if (c == 4) disp(h);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int data; struct Node* next; } Node;
Node* cn(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->next = NULL; return n; }
Node* ial(Node* h, int d) { Node* n = cn(d); if (!h) return n; Node* t = h; while (t->next) t = t->next; t->next = n; return h; }
Node* df(Node* h) { if (!h) return NULL; Node* t = h; h = h->next; free(t); return h; }
Node* dl(Node* h) { if (!h || !h->next) { free(h); return NULL; } Node* t = h; while (t->next->next) t = t->next; free(t->next); t->next = NULL; return h; }
Node* da(Node* h, int p) { if (p == 1) return df(h); Node* t = h; for (int i = 1; i < p-1 && t; i++) t = t->next; if (!t || !t->next) return h; Node* d = t->next; t->next = d->next; free(d); return h; }
void disp(Node* h) { while (h) printf("%d -> ", h->data), h = h->next; printf("NULL\n"); }
int main() {
    Node* h = NULL; int c, p;
    for (int i = 1; i <= 5; i++) h = ial(h, i*10);
    while (scanf("%d", &c) && c != 7) {
        if (c == 1) h = df(h);
        else if (c == 2) h = dl(h);
        else if (c == 3) scanf("%d", &p), h = da(h, p);
        else if (c == 4) disp(h);
    }
    return 0;
}
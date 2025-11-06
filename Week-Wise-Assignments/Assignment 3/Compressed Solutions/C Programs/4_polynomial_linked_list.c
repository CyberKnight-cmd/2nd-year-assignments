#include <stdio.h>
#include <stdlib.h>
typedef struct PolyNode { int coeff, exp; struct PolyNode* next; } PolyNode;
PolyNode* cn(int c, int e) { PolyNode* n = malloc(sizeof(PolyNode)); n->coeff = c; n->exp = e; n->next = NULL; return n; }
PolyNode* insert(PolyNode* h, int c, int e) {
    if (!c) return h;
    PolyNode* n = cn(c, e);
    if (!h || h->exp > e) { n->next = h; return n; }
    if (h->exp == e) { h->coeff += c; free(n); return h->coeff ? h : (free(h), h->next); }
    PolyNode* t = h;
    while (t->next && t->next->exp < e) t = t->next;
    if (t->next && t->next->exp == e) { t->next->coeff += c; free(n); if (!t->next->coeff) { PolyNode* d = t->next; t->next = d->next; free(d); } return h; }
    n->next = t->next; t->next = n; return h;
}
void disp(PolyNode* h) { while (h) printf("%dx^%d%s", h->coeff, h->exp, h->next ? " + " : ""), h = h->next; printf("\n"); }
int main() {
    PolyNode* p = NULL; int c, e, ch;
    while (scanf("%d", &ch) && ch != 8) {
        if (ch == 1) scanf("%d%d", &c, &e), p = insert(p, c, e);
        else if (ch == 2) disp(p);
    }
    return 0;
}
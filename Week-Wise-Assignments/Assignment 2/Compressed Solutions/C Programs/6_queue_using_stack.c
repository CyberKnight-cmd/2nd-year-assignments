#include <stdio.h>
#include <stdlib.h>
typedef struct { int *d; int t, c; } S;
typedef struct { S *s1, *s2; } Q;
S* cs(int c) { S* s = malloc(sizeof(S)); s->d = malloc(c*sizeof(int)); s->t = -1; s->c = c; return s; }
void push(S* s, int e) { if(s->t < s->c-1) s->d[++s->t] = e; }
int pop(S* s) { return s->t >= 0 ? s->d[s->t--] : -1; }
Q* cq(int c) { Q* q = malloc(sizeof(Q)); q->s1 = cs(c); q->s2 = cs(c); return q; }
void enq(Q* q, int e) { push(q->s1, e); }
int deq(Q* q) { if(q->s2->t == -1) while(q->s1->t >= 0) push(q->s2, pop(q->s1)); return pop(q->s2); }
int main() {
    int c, ch, e; scanf("%d", &c); Q* q = cq(c);
    while(scanf("%d", &ch) && ch != 6) {
        if(ch == 1) scanf("%d", &e), enq(q, e);
        else if(ch == 2) printf("%d\n", deq(q));
    }
    return 0;
}
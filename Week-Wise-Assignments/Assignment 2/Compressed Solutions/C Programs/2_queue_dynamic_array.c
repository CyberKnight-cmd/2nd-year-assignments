#include <stdio.h>
#include <stdlib.h>
typedef struct { int *d, f, r, c, s; } Q;
Q* cq(int c) { Q* q = malloc(sizeof(Q)); q->d = malloc(c*sizeof(int)); q->f = 0; q->r = -1; q->c = c; q->s = 0; return q; }
void enq(Q* q, int e) { if(q->s < q->c) q->r = (q->r+1)%q->c, q->d[q->r] = e, q->s++; }
int deq(Q* q) { if(q->s > 0) { int e = q->d[q->f]; q->f = (q->f+1)%q->c; q->s--; return e; } return -1; }
void disp(Q* q) { int i = q->f; for(int c = 0; c < q->s; c++) printf("%d ", q->d[i]), i = (i+1)%q->c; printf("\n"); }
int main() {
    int c, ch, e; scanf("%d", &c); Q* q = cq(c);
    while(scanf("%d", &ch) && ch != 7) {
        if(ch == 1) scanf("%d", &e), enq(q, e);
        else if(ch == 2) deq(q);
        else if(ch == 3) printf("%d\n", q->s > 0 ? q->d[q->f] : -1);
        else if(ch == 5) disp(q);
    }
    free(q->d); free(q); return 0;
}
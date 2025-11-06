#include <stdio.h>
#include <stdlib.h>
typedef struct { int *d, f, r, c, s; } CQ;
CQ* ccq(int c) { CQ* q = malloc(sizeof(CQ)); q->d = malloc(c*sizeof(int)); q->f = q->r = -1; q->c = c; q->s = 0; return q; }
void enq(CQ* q, int e) { if(q->s < q->c) { if(q->s == 0) q->f = q->r = 0; else q->r = (q->r+1)%q->c; q->d[q->r] = e; q->s++; } }
int deq(CQ* q) { if(q->s > 0) { int e = q->d[q->f]; if(q->s == 1) q->f = q->r = -1; else q->f = (q->f+1)%q->c; q->s--; return e; } return -1; }
void disp(CQ* q) { int i = q->f; for(int c = 0; c < q->s; c++) printf("%d ", q->d[i]), i = (i+1)%q->c; printf("\n"); }
int main() {
    int c, ch, e; scanf("%d", &c); CQ* q = ccq(c);
    while(scanf("%d", &ch) && ch != 8) {
        if(ch == 1) scanf("%d", &e), enq(q, e);
        else if(ch == 2) deq(q);
        else if(ch == 5) disp(q);
    }
    free(q->d); free(q); return 0;
}
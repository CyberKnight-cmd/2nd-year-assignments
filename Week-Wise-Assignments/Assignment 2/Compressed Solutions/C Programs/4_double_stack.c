#include <stdio.h>
#include <stdlib.h>
typedef struct { int *d, t1, t2, c; } DS;
DS* cds(int c) { DS* ds = malloc(sizeof(DS)); ds->d = malloc(c*sizeof(int)); ds->t1 = -1; ds->t2 = c; ds->c = c; return ds; }
void p1(DS* ds, int e) { if(ds->t1+1 < ds->t2) ds->d[++ds->t1] = e; }
void p2(DS* ds, int e) { if(ds->t1+1 < ds->t2) ds->d[--ds->t2] = e; }
int pop1(DS* ds) { return ds->t1 >= 0 ? ds->d[ds->t1--] : -1; }
int pop2(DS* ds) { return ds->t2 < ds->c ? ds->d[ds->t2++] : -1; }
int main() {
    int c, ch, e; scanf("%d", &c); DS* ds = cds(c);
    while(scanf("%d", &ch) && ch != 10) {
        if(ch == 1) scanf("%d", &e), p1(ds, e);
        else if(ch == 2) scanf("%d", &e), p2(ds, e);
        else if(ch == 3) pop1(ds);
        else if(ch == 4) pop2(ds);
    }
    free(ds->d); free(ds); return 0;
}
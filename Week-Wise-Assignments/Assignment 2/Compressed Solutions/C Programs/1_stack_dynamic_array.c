#include <stdio.h>
#include <stdlib.h>
typedef struct { int *d; int t, c; } S;
S* cs(int c) { S* s = malloc(sizeof(S)); s->d = malloc(c*sizeof(int)); s->t = -1; s->c = c; return s; }
void push(S* s, int e) { if(s->t < s->c-1) s->d[++s->t] = e; }
int pop(S* s) { return s->t >= 0 ? s->d[s->t--] : -1; }
int peek(S* s) { return s->t >= 0 ? s->d[s->t] : -1; }
void disp(S* s) { for(int i = s->t; i >= 0; i--) printf("%d ", s->d[i]); printf("\n"); }
int main() {
    int c, ch, e; scanf("%d", &c); S* s = cs(c);
    while(scanf("%d", &ch) && ch != 5) {
        if(ch == 1) scanf("%d", &e), push(s, e);
        else if(ch == 2) pop(s);
        else if(ch == 3) printf("%d\n", peek(s));
        else if(ch == 4) disp(s);
    }
    free(s->d); free(s); return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct { char *d; int t; } S;
S* cs(int c) { S* s = malloc(sizeof(S)); s->d = malloc(c); s->t = -1; return s; }
void push(S* s, char c) { s->d[++s->t] = c; }
char pop(S* s) { return s->d[s->t--]; }
int main() {
    char str[1000]; scanf("%s", str); int l = strlen(str);
    S* s = cs(l); for(int i = 0; i < l; i++) push(s, str[i]);
    for(int i = 0; i < l; i++) str[i] = pop(s);
    printf("%s\n", str); free(s->d); free(s); return 0;
}
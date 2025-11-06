#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct { char *d; int t; } S;
S* cs(int c) { S* s = malloc(sizeof(S)); s->d = malloc(c); s->t = -1; return s; }
void push(S* s, char c) { s->d[++s->t] = c; }
char pop(S* s) { return s->t >= 0 ? s->d[s->t--] : 0; }
int ispal(char *t) {
    int l = strlen(t); S* s = cs(l);
    for(int i = 0; i < l; i++) if(isalnum(t[i])) push(s, tolower(t[i]));
    for(int i = 0; i < l; i++) if(isalnum(t[i]) && tolower(t[i]) != pop(s)) return 0;
    return 1;
}
int main() {
    char t[1000]; scanf("%[^\n]", t);
    printf("%s\n", ispal(t) ? "PALINDROME" : "NOT PALINDROME");
    return 0;
}
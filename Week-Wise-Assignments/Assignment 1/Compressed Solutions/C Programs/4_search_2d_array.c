#include <stdio.h>
#include <stdlib.h>
int main() {
    int r, c, e, **a, i, j, f = 0;
    scanf("%d%d", &r, &c);
    a = malloc(r * sizeof(int*));
    for (i = 0; i < r; i++) a[i] = malloc(c * sizeof(int));
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) scanf("%d", &a[i][j]);
    scanf("%d", &e);
    for (i = 0; i < r && !f; i++) for (j = 0; j < c; j++) if (a[i][j] == e) { printf("Found at [%d][%d]\n", i, j); f = 1; break; }
    if (!f) printf("Not found\n");
    for (i = 0; i < r; i++) free(a[i]);
    free(a);
    return 0;
}         
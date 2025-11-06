#include <stdio.h>
#include <stdlib.h>
int main() {
    int r, c, **a, i, j, m;
    scanf("%d%d", &r, &c);
    a = malloc(r * sizeof(int*));
    for (i = 0; i < r; i++) a[i] = malloc(c * sizeof(int));
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) scanf("%d", &a[i][j]);
    for (m = a[0][0], i = 0; i < r; i++) for (j = 0; j < c; j++) if (a[i][j] > m) m = a[i][j];
    printf("%d\n", m);
    for (i = 0; i < r; i++) free(a[i]);
    free(a);
    return 0;
}
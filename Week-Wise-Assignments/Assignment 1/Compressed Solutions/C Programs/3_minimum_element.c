#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, *a, i, m;
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (m = a[0], i = 1; i < n; i++) if (a[i] < m) m = a[i];
    printf("%d\n", m);
    free(a);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, s, e, *a, *b, i, k = 0;
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d%d", &s, &e);
    b = malloc((n - (e - s + 1)) * sizeof(int));
    for (i = 0; i < s; i++) b[k++] = a[i];
    for (i = e + 1; i < n; i++) b[k++] = a[i];
    for (i = 0; i < k; i++) printf("%d ", b[i]);
    free(a); free(b);
    return 0;
}
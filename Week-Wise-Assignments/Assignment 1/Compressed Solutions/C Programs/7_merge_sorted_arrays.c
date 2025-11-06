#include <stdio.h>
#include <stdlib.h>
int main() {
    int n1, n2, *a, *b, *m, i = 0, j = 0, k = 0;
    scanf("%d%d", &n1, &n2);
    a = malloc(n1 * sizeof(int)); b = malloc(n2 * sizeof(int)); m = malloc((n1 + n2) * sizeof(int));
    for (i = 0; i < n1; i++) scanf("%d", &a[i]);
    for (i = 0; i < n2; i++) scanf("%d", &b[i]);
    for (i = j = k = 0; i < n1 && j < n2; k++) m[k] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while (i < n1) m[k++] = a[i++];
    while (j < n2) m[k++] = b[j++];
    for (i = 0; i < n1 + n2; i++) printf("%d ", m[i]);
    free(a); free(b); free(m);
    return 0;
}
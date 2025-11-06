#include <stdio.h>
#include <stdlib.h>
int main() {
    int n1, n2, *a, *b, *m, i, j, k = 0, t;
    scanf("%d%d", &n1, &n2);
    a = malloc(n1 * sizeof(int)); b = malloc(n2 * sizeof(int)); m = malloc((n1 + n2) * sizeof(int));
    for (i = 0; i < n1; i++) scanf("%d", &a[i]);
    for (i = 0; i < n2; i++) scanf("%d", &b[i]);
    for (i = 0; i < n1; i++) m[k++] = a[i];
    for (i = 0; i < n2; i++) m[k++] = b[i];
    for (i = 0; i < k - 1; i++) for (j = 0; j < k - i - 1; j++) if (m[j] > m[j + 1]) t = m[j], m[j] = m[j + 1], m[j + 1] = t;
    for (i = 0; i < k; i++) printf("%d ", m[i]);
    free(a); free(b); free(m);
    return 0;
}
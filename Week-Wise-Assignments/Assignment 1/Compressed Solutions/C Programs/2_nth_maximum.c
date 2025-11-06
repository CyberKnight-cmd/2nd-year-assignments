#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, p, *a, i, j, t;
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &p);
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] < a[j + 1]) t = a[j], a[j] = a[j + 1], a[j + 1] = t;
    printf("%d\n", a[p - 1]);
    free(a);
    return 0;
}
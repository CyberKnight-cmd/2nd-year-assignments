#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, ns, *a, i;
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &ns);
    a = realloc(a, ns * sizeof(int));
    if (ns > n) for (i = n; i < ns; i++) scanf("%d", &a[i]);
    for (i = 0; i < ns; i++) printf("%d ", a[i]);
    free(a);
    return 0;
}
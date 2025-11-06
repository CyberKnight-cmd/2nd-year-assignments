#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, e, *a, i;
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &e);
    for (i = 0; i < n && a[i] != e; i++);
    printf(i < n ? "Found at %d\n" : "Not found\n", i);
    free(a);
    return 0;
}
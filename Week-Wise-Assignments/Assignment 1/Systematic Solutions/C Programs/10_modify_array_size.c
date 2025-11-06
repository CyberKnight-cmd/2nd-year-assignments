#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, newSize;
    int *arr;
    
    printf("Enter initial array size: ");
    scanf("%d", &n);
    
    // Dynamic memory allocation
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Current array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Enter new array size: ");
    scanf("%d", &newSize);
    
    // Resize the array
    arr = (int*)realloc(arr, newSize * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }
    
    if (newSize > n) {
        printf("Enter %d additional elements: ", newSize - n);
        for (int i = n; i < newSize; i++) {
            scanf("%d", &arr[i]);
        }
    }
    
    printf("Modified array (size %d): ", newSize);
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Demonstrate runtime utilization
    printf("\nDemonstrating runtime utilization:\n");
    printf("Original size: %d elements (%zu bytes)\n", n, n * sizeof(int));
    printf("New size: %d elements (%zu bytes)\n", newSize, newSize * sizeof(int));
    
    free(arr);
    
    return 0;
}
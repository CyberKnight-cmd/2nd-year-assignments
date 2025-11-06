#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, min;
    int *arr;
    
    printf("Enter the number of elements: ");
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
    
    // Find minimum element
    min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    printf("Minimum element in the array: %d\n", min);
    
    free(arr);
    return 0;
}
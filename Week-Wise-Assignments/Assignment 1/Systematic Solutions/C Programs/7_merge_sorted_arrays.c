#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2;
    int *arr1, *arr2, *merged;
    
    printf("Enter size of first sorted array: ");
    scanf("%d", &n1);
    printf("Enter size of second sorted array: ");
    scanf("%d", &n2);
    
    // Dynamic memory allocation
    arr1 = (int*)malloc(n1 * sizeof(int));
    arr2 = (int*)malloc(n2 * sizeof(int));
    merged = (int*)malloc((n1 + n2) * sizeof(int));
    
    if (arr1 == NULL || arr2 == NULL || merged == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter elements of first sorted array: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf("Enter elements of second sorted array: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    // Merge two sorted arrays
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    
    // Copy remaining elements
    while (i < n1) {
        merged[k++] = arr1[i++];
    }
    
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
    
    printf("Merged sorted array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");
    
    free(arr1);
    free(arr2);
    free(merged);
    
    return 0;
}
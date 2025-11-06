#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, start, end;
    int *arr, *newArr;
    
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
    
    printf("Enter start index to delete (0-based): ");
    scanf("%d", &start);
    printf("Enter end index to delete (0-based): ");
    scanf("%d", &end);
    
    if (start < 0 || end >= n || start > end) {
        printf("Invalid range!\n");
        free(arr);
        return 1;
    }
    
    int newSize = n - (end - start + 1);
    newArr = (int*)malloc(newSize * sizeof(int));
    if (newArr == NULL) {
        printf("Memory allocation failed!\n");
        free(arr);
        return 1;
    }
    
    // Copy elements before the range
    int k = 0;
    for (int i = 0; i < start; i++) {
        newArr[k++] = arr[i];
    }
    
    // Copy elements after the range
    for (int i = end + 1; i < n; i++) {
        newArr[k++] = arr[i];
    }
    
    printf("Array after deleting range [%d-%d]: ", start, end);
    for (int i = 0; i < newSize; i++) {
        printf("%d ", newArr[i]);
    }
    printf("\n");
    
    free(arr);
    free(newArr);
    
    return 0;
}
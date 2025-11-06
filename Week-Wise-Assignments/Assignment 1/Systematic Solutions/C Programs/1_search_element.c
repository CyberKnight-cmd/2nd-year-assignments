#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, element, found = 0;
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
    
    printf("Enter element to search: ");
    scanf("%d", &element);
    
    // Search for element
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            printf("Element %d found at index %d\n", element, i);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Element %d not found in the array\n", element);
    }
    
    free(arr);
    return 0;
}
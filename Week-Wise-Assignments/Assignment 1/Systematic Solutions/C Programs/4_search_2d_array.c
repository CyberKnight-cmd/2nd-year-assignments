#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, element, found = 0;
    int **arr;
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    // Dynamic memory allocation for 2D array
    arr = (int**)malloc(rows * sizeof(int*));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }
    
    printf("Enter elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("Enter element to search: ");
    scanf("%d", &element);
    
    // Search for element
    for (int i = 0; i < rows && !found; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == element) {
                printf("Element %d found at position [%d][%d]\n", element, i, j);
                found = 1;
                break;
            }
        }
    }
    
    if (!found) {
        printf("Element %d not found in the 2D array\n", element);
    }
    
    // Free memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}
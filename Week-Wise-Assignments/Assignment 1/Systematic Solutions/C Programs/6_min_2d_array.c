#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, min;
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
    
    // Find minimum element
    min = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    
    printf("Minimum element in the 2D array: %d\n", min);
    
    // Free memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}
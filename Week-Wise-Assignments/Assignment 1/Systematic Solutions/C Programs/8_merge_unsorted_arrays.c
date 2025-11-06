#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n1, n2;
    int *arr1, *arr2, *merged;
    
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    
    // Dynamic memory allocation
    arr1 = (int*)malloc(n1 * sizeof(int));
    arr2 = (int*)malloc(n2 * sizeof(int));
    merged = (int*)malloc((n1 + n2) * sizeof(int));
    
    if (arr1 == NULL || arr2 == NULL || merged == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter elements of first array: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf("Enter elements of second array: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    // Merge arrays
    int k = 0;
    for (int i = 0; i < n1; i++) {
        merged[k++] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        merged[k++] = arr2[i];
    }
    
    // Sort the merged array
    bubbleSort(merged, n1 + n2);
    
    printf("Merged array in sorted order: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");
    
    free(arr1);
    free(arr2);
    free(merged);
    
    return 0;
}
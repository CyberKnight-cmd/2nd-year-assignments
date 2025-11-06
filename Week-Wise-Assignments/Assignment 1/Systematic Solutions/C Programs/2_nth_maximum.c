#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, position;
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
    
    printf("Enter position (1 for max, 2 for 2nd max, etc.): ");
    scanf("%d", &position);
    
    if (position > n || position < 1) {
        printf("Invalid position!\n");
        free(arr);
        return 1;
    }
    
    // Sort array in descending order using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("The %d%s maximum element is: %d\n", position, 
           (position == 1) ? "st" : (position == 2) ? "nd" : (position == 3) ? "rd" : "th", 
           arr[position - 1]);
    
    free(arr);
    return 0;
}
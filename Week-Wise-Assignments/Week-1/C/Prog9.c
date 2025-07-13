#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));

    // Getting input
    for(int i = 0; i < n; i++){
        printf("%d : ", i);
        scanf("%d", &arr[i]);
    }

    int lower, upper;
    printf("Enter lower and upper indices to delete: ");
    scanf("%d %d", &lower, &upper);

    // Ensure lower <= upper
    if (lower > upper){
        int temp = lower;
        lower = upper;
        upper = temp;
    }

    // Validate range
    if(lower < 0 || upper >= n){
        printf("Invalid range.\n");
        free(arr);
        return 1;
    }

    int count = upper - lower + 1; // number of elements to delete

    // Shift elements left
    for(int i = upper + 1; i < n; i++){
        arr[i - count] = arr[i];
    }

    int old_n = n;
    n = n - count; // update size

    // Print array before realloc (for demo)
    printf("Array before realloc (logical size %d, allocated size %d):\n", n, old_n);
    for(int i = 0; i < old_n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate to shrink memory
    int *temp = realloc(arr, n * sizeof(int));
    if(temp != NULL){
        arr = temp;
    } else {
        printf("Memory reallocation failed. Array size remains same.\n");
    }

    // Print updated array (valid)
    printf("Updated array after realloc (size %d):\n", n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Demonstration: printing beyond new size (undefined behavior)
    printf("Trying to print beyond reallocated size (undefined behavior!):\n");
    for(int i = n; i < old_n; i++){
        printf("%d ", arr[i]); // This is invalid access
    }
    printf("\n");

    free(arr);
    return 0;
}

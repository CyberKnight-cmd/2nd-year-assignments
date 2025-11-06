#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int n, target;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    printf("Enter target: ");
    scanf("%d", &target);
    
    int result = linearSearch(arr, n, target);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    return 0;
}
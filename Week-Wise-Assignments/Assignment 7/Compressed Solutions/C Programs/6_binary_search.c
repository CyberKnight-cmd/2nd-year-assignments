#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n, target;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    printf("Enter target: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    return 0;
}
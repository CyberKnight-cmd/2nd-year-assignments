#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display array
void displayArray(int arr[], int n, const char* message) {
    printf("%s: ", message);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Algorithm for Selection Sort:
// 1. Find the minimum element in unsorted portion
// 2. Swap it with the first element of unsorted portion
// 3. Move the boundary of sorted and unsorted portions
// 4. Repeat until entire array is sorted
void selectionSort(int arr[], int n) {
    printf("\n=== Selection Sort Algorithm ===\n");
    printf("Array size: %d\n", n);
    printf("Algorithm: Find minimum element and place it at the beginning\n\n");
    
    displayArray(arr, n, "Initial array");
    
    int totalComparisons = 0;
    int totalSwaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        int passComparisons = 0;
        
        printf("Pass %d: Finding minimum in range [%d, %d]\n", i + 1, i, n - 1);
        printf("  Current minimum: arr[%d] = %d\n", minIndex, arr[minIndex]);
        
        // Find minimum element in remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            passComparisons++;
            totalComparisons++;
            
            printf("  Comparing arr[%d]=%d with current min arr[%d]=%d: ", 
                   j, arr[j], minIndex, arr[minIndex]);
            
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                printf("New minimum found at index %d\n", minIndex);
            } else {
                printf("No change\n");
            }
        }
        
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            printf("  Swapping arr[%d]=%d with arr[%d]=%d\n", 
                   i, arr[i], minIndex, arr[minIndex]);
            
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            totalSwaps++;
        } else {
            printf("  No swap needed - minimum is already at correct position\n");
        }
        
        printf("  After pass %d: ", i + 1);
        displayArray(arr, n, "");
        printf("  Sorted portion: [0, %d], Unsorted portion: [%d, %d]\n", 
               i, i + 1, n - 1);
        printf("  Pass statistics: %d comparisons, %s\n", 
               passComparisons, (minIndex != i) ? "1 swap" : "0 swaps");
        printf("\n");
    }
    
    printf("Selection Sort completed!\n");
    printf("Total statistics: %d comparisons, %d swaps\n", 
           totalComparisons, totalSwaps);
    displayArray(arr, n, "Final sorted array");
}

// Function to find kth smallest element using selection sort approach
int findKthSmallest(int arr[], int n, int k) {
    printf("\n=== Finding %d%s smallest element ===\n", k, 
           (k == 1) ? "st" : (k == 2) ? "nd" : (k == 3) ? "rd" : "th");
    
    // Create a copy to avoid modifying original array
    int* temp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    // Perform selection sort for first k elements
    for (int i = 0; i < k; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (temp[j] < temp[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            int swap = temp[minIndex];
            temp[minIndex] = temp[i];
            temp[i] = swap;
        }
        
        printf("After finding %d%s smallest: ", i + 1, 
               (i == 0) ? "st" : (i == 1) ? "nd" : (i == 2) ? "rd" : "th");
        for (int j = 0; j < n; j++) {
            printf("%d ", temp[j]);
        }
        printf("\n");
    }
    
    int result = temp[k - 1];
    free(temp);
    return result;
}

// Performance analysis function
void performanceAnalysis() {
    printf("\n=== Performance Analysis ===\n");
    
    int sizes[] = {10, 50, 100, 500};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Array Size | Comparisons | Swaps | Time Complexity\n");
    printf("-----------|-------------|-------|----------------\n");
    
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int* arr = (int*)malloc(n * sizeof(int));
        
        // Generate random array
        srand(time(NULL) + i);
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000;
        }
        
        int comparisons = 0, swaps = 0;
        
        // Count operations in selection sort
        for (int pass = 0; pass < n - 1; pass++) {
            int minIndex = pass;
            
            for (int j = pass + 1; j < n; j++) {
                comparisons++;
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            
            if (minIndex != pass) {
                int temp = arr[minIndex];
                arr[minIndex] = arr[pass];
                arr[pass] = temp;
                swaps++;
            }
        }
        
        printf("%10d | %11d | %5d | O(n²)\n", n, comparisons, swaps);
        free(arr);
    }
}

// Function to generate different types of arrays for testing
void generateTestArray(int arr[], int n, int type) {
    switch (type) {
        case 1: // Random array
            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                arr[i] = rand() % 100 + 1;
            }
            break;
            
        case 2: // Already sorted array
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
            }
            break;
            
        case 3: // Reverse sorted array
            for (int i = 0; i < n; i++) {
                arr[i] = n - i;
            }
            break;
            
        case 4: // Array with duplicates
            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                arr[i] = rand() % 10 + 1; // Values 1-10
            }
            break;
    }
}

// Function to check if array is sorted
int isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int choice, n;
    
    printf("=== Selection Sort Implementation ===\n");
    printf("Selection Sort: Finds minimum element and places it at correct position\n");
    printf("Time Complexity: O(n²) for all cases\n");
    printf("Space Complexity: O(1) - In-place sorting\n");
    printf("Stability: Not stable (may change relative order of equal elements)\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Sort custom array (step-by-step)\n");
        printf("2. Sort test arrays (different types)\n");
        printf("3. Find kth smallest element\n");
        printf("4. Performance analysis\n");
        printf("5. Algorithm explanation\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                printf("Enter array size: ");
                scanf("%d", &n);
                
                if (n <= 0 || n > 100) {
                    printf("Invalid size! Please enter size between 1 and 100.\n");
                    break;
                }
                
                int* arr = (int*)malloc(n * sizeof(int));
                
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                selectionSort(arr, n);
                
                printf("\nVerification: Array is %s\n", 
                       isSorted(arr, n) ? "correctly sorted" : "NOT sorted");
                
                free(arr);
                break;
            }
            
            case 2: {
                printf("Enter array size: ");
                scanf("%d", &n);
                
                if (n <= 0 || n > 100) {
                    printf("Invalid size! Please enter size between 1 and 100.\n");
                    break;
                }
                
                printf("\nSelect array type:\n");
                printf("1. Random array\n");
                printf("2. Already sorted array\n");
                printf("3. Reverse sorted array\n");
                printf("4. Array with duplicates\n");
                printf("Enter choice: ");
                
                int type;
                scanf("%d", &type);
                
                if (type < 1 || type > 4) {
                    printf("Invalid choice!\n");
                    break;
                }
                
                int* arr = (int*)malloc(n * sizeof(int));
                generateTestArray(arr, n, type);
                
                const char* typeNames[] = {"", "Random", "Sorted", "Reverse Sorted", "With Duplicates"};
                printf("\nGenerated %s Array:\n", typeNames[type]);
                
                selectionSort(arr, n);
                free(arr);
                break;
            }
            
            case 3: {
                printf("Enter array size: ");
                scanf("%d", &n);
                
                if (n <= 0 || n > 50) {
                    printf("Invalid size! Please enter size between 1 and 50.\n");
                    break;
                }
                
                int* arr = (int*)malloc(n * sizeof(int));
                
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                int k;
                printf("Enter k (1 to %d): ", n);
                scanf("%d", &k);
                
                if (k < 1 || k > n) {
                    printf("Invalid k! Must be between 1 and %d.\n", n);
                    free(arr);
                    break;
                }
                
                displayArray(arr, n, "Original array");
                int kthSmallest = findKthSmallest(arr, n, k);
                printf("The %d%s smallest element is: %d\n", k, 
                       (k == 1) ? "st" : (k == 2) ? "nd" : (k == 3) ? "rd" : "th", 
                       kthSmallest);
                
                free(arr);
                break;
            }
            
            case 4:
                performanceAnalysis();
                break;
                
            case 5:
                printf("\n=== Selection Sort Algorithm Explanation ===\n");
                printf("How it works:\n");
                printf("1. Divide the array into sorted and unsorted portions\n");
                printf("2. Initially, sorted portion is empty and unsorted portion is entire array\n");
                printf("3. Find the minimum element in the unsorted portion\n");
                printf("4. Swap it with the first element of unsorted portion\n");
                printf("5. Move the boundary between sorted and unsorted portions\n");
                printf("6. Repeat until entire array is sorted\n\n");
                
                printf("Characteristics:\n");
                printf("• Simple to understand and implement\n");
                printf("• Not stable (may change relative order of equal elements)\n");
                printf("• In-place sorting (O(1) extra space)\n");
                printf("• Not adaptive (same performance regardless of input)\n");
                printf("• Minimizes number of swaps (at most n-1 swaps)\n\n");
                
                printf("Time Complexity:\n");
                printf("• Best Case: O(n²)\n");
                printf("• Average Case: O(n²)\n");
                printf("• Worst Case: O(n²)\n");
                printf("• Always performs (n-1) + (n-2) + ... + 1 = n(n-1)/2 comparisons\n\n");
                
                printf("When to use:\n");
                printf("• Small datasets\n");
                printf("• When memory write is costly (minimizes swaps)\n");
                printf("• When simplicity is important\n");
                break;
                
            case 6:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
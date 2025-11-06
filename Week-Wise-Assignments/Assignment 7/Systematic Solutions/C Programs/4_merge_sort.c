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

// Global variables for tracking operations
int mergeOperations = 0;
int recursiveDepth = 0;
int maxDepth = 0;

// Algorithm for Merge operation:
// 1. Create temporary arrays for left and right subarrays
// 2. Copy data to temporary arrays
// 3. Merge temporary arrays back into original array in sorted order
// 4. Compare elements from both arrays and pick smaller one
void merge(int arr[], int left, int mid, int right, int showSteps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    if (showSteps) {
        printf("  Merging subarrays [%d, %d] and [%d, %d]\n", left, mid, mid + 1, right);
        printf("    Left subarray:  ");
        for (int i = 0; i < n1; i++) {
            printf("%d ", leftArr[i]);
        }
        printf("\n");
        printf("    Right subarray: ");
        for (int j = 0; j < n2; j++) {
            printf("%d ", rightArr[j]);
        }
        printf("\n");
    }
    
    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            if (showSteps) {
                printf("    Comparing %d <= %d: Choose %d\n", leftArr[i], rightArr[j], leftArr[i]);
            }
            i++;
        } else {
            arr[k] = rightArr[j];
            if (showSteps) {
                printf("    Comparing %d > %d: Choose %d\n", leftArr[i], rightArr[j], rightArr[j]);
            }
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        if (showSteps) {
            printf("    Copying remaining from left: %d\n", leftArr[i]);
        }
        i++;
        k++;
    }
    
    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        if (showSteps) {
            printf("    Copying remaining from right: %d\n", rightArr[j]);
        }
        j++;
        k++;
    }
    
    if (showSteps) {
        printf("    Merged result: ");
        for (int idx = left; idx <= right; idx++) {
            printf("%d ", arr[idx]);
        }
        printf("\n\n");
    }
    
    mergeOperations++;
    free(leftArr);
    free(rightArr);
}

// Algorithm for Merge Sort:
// 1. Divide the array into two halves
// 2. Recursively sort both halves
// 3. Merge the sorted halves
void mergeSort(int arr[], int left, int right, int showSteps) {
    if (left < right) {
        recursiveDepth++;
        if (recursiveDepth > maxDepth) {
            maxDepth = recursiveDepth;
        }
        
        int mid = left + (right - left) / 2;
        
        if (showSteps) {
            printf("Dividing array [%d, %d] at mid = %d\n", left, right, mid);
            printf("  Left half: [%d, %d], Right half: [%d, %d]\n", 
                   left, mid, mid + 1, right);
        }
        
        // Sort first and second halves
        mergeSort(arr, left, mid, showSteps);
        mergeSort(arr, mid + 1, right, showSteps);
        
        // Merge the sorted halves
        merge(arr, left, mid, right, showSteps);
        
        recursiveDepth--;
    }
}

// Iterative merge sort implementation
void mergeSortIterative(int arr[], int n) {
    printf("\n=== Iterative Merge Sort ===\n");
    displayArray(arr, n, "Initial array");
    
    int mergeCount = 0;
    
    // Current size of subarrays to be merged
    for (int currSize = 1; currSize < n; currSize = 2 * currSize) {
        printf("\nMerging subarrays of size %d:\n", currSize);
        
        // Pick starting point of left sub array
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            // Calculate mid and right points
            int mid = leftStart + currSize - 1;
            int rightEnd = (leftStart + 2 * currSize - 1 < n - 1) ? 
                          leftStart + 2 * currSize - 1 : n - 1;
            
            if (mid < rightEnd) {
                printf("  Merging [%d, %d] with [%d, %d]\n", 
                       leftStart, mid, mid + 1, rightEnd);
                merge(arr, leftStart, mid, rightEnd, 0);
                mergeCount++;
            }
        }
        
        printf("  After merging size %d: ", currSize);
        displayArray(arr, n, "");
    }
    
    printf("\nIterative Merge Sort completed!\n");
    printf("Total merge operations: %d\n", mergeCount);
}

// Performance analysis function
void performanceAnalysis() {
    printf("\n=== Performance Analysis ===\n");
    
    int sizes[] = {8, 16, 32, 64, 128};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Array Size | Merge Ops | Max Depth | Time Complexity\n");
    printf("-----------|-----------|-----------|----------------\n");
    
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int* arr = (int*)malloc(n * sizeof(int));
        
        // Generate random array
        srand(time(NULL) + i);
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000;
        }
        
        // Reset counters
        mergeOperations = 0;
        recursiveDepth = 0;
        maxDepth = 0;
        
        // Perform merge sort
        mergeSort(arr, 0, n - 1, 0);
        
        printf("%10d | %9d | %9d | O(n log n)\n", 
               n, mergeOperations, maxDepth);
        
        free(arr);
    }
}

// Function to demonstrate merge operation
void demonstrateMerge() {
    printf("\n=== Merge Operation Demonstration ===\n");
    
    int arr[] = {2, 5, 8, 1, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Demonstrating merge of two sorted subarrays:\n");
    displayArray(arr, n, "Array with two sorted parts");
    printf("Left sorted part: [0, 2] = {2, 5, 8}\n");
    printf("Right sorted part: [3, 5] = {1, 3, 9}\n\n");
    
    merge(arr, 0, 2, 5, 1);
    
    displayArray(arr, n, "After merging");
}

// Function to generate different types of arrays
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
                arr[i] = rand() % 10 + 1;
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
    
    printf("=== Merge Sort Implementation ===\n");
    printf("Merge Sort: Divide and conquer sorting algorithm\n");
    printf("Time Complexity: O(n log n) for all cases\n");
    printf("Space Complexity: O(n) - Requires additional space for merging\n");
    printf("Stability: Stable (maintains relative order of equal elements)\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Sort custom array (recursive, step-by-step)\n");
        printf("2. Sort custom array (recursive, fast)\n");
        printf("3. Sort using iterative merge sort\n");
        printf("4. Sort test arrays (different types)\n");
        printf("5. Demonstrate merge operation\n");
        printf("6. Performance analysis\n");
        printf("7. Algorithm explanation\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
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
                
                printf("\n=== Recursive Merge Sort (Step-by-step) ===\n");
                displayArray(arr, n, "Initial array");
                
                // Reset counters
                mergeOperations = 0;
                recursiveDepth = 0;
                maxDepth = 0;
                
                mergeSort(arr, 0, n - 1, 1);
                
                printf("Merge Sort completed!\n");
                printf("Statistics: %d merge operations, max recursion depth: %d\n", 
                       mergeOperations, maxDepth);
                displayArray(arr, n, "Final sorted array");
                
                printf("\nVerification: Array is %s\n", 
                       isSorted(arr, n) ? "correctly sorted" : "NOT sorted");
                
                free(arr);
                break;
            }
            
            case 2: {
                printf("Enter array size: ");
                scanf("%d", &n);
                
                if (n <= 0 || n > 1000) {
                    printf("Invalid size! Please enter size between 1 and 1000.\n");
                    break;
                }
                
                int* arr = (int*)malloc(n * sizeof(int));
                
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                printf("\n=== Recursive Merge Sort (Fast) ===\n");
                displayArray(arr, n, "Initial array");
                
                // Reset counters
                mergeOperations = 0;
                recursiveDepth = 0;
                maxDepth = 0;
                
                mergeSort(arr, 0, n - 1, 0);
                
                printf("Merge Sort completed!\n");
                printf("Statistics: %d merge operations, max recursion depth: %d\n", 
                       mergeOperations, maxDepth);
                displayArray(arr, n, "Final sorted array");
                
                free(arr);
                break;
            }
            
            case 3: {
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
                
                mergeSortIterative(arr, n);
                free(arr);
                break;
            }
            
            case 4: {
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
                displayArray(arr, n, "Before sorting");
                
                // Reset counters
                mergeOperations = 0;
                recursiveDepth = 0;
                maxDepth = 0;
                
                mergeSort(arr, 0, n - 1, 0);
                
                printf("Statistics: %d merge operations, max depth: %d\n", 
                       mergeOperations, maxDepth);
                displayArray(arr, n, "After sorting");
                
                free(arr);
                break;
            }
            
            case 5:
                demonstrateMerge();
                break;
                
            case 6:
                performanceAnalysis();
                break;
                
            case 7:
                printf("\n=== Merge Sort Algorithm Explanation ===\n");
                printf("How it works:\n");
                printf("1. Divide: Split the array into two halves\n");
                printf("2. Conquer: Recursively sort both halves\n");
                printf("3. Combine: Merge the sorted halves into a single sorted array\n\n");
                
                printf("Characteristics:\n");
                printf("• Divide and conquer algorithm\n");
                printf("• Stable sorting algorithm\n");
                printf("• Not in-place (requires O(n) extra space)\n");
                printf("• Consistent performance regardless of input\n");
                printf("• Parallelizable (can be implemented in parallel)\n\n");
                
                printf("Time Complexity:\n");
                printf("• Best Case: O(n log n)\n");
                printf("• Average Case: O(n log n)\n");
                printf("• Worst Case: O(n log n)\n");
                printf("• Always performs the same number of operations\n\n");
                
                printf("Space Complexity:\n");
                printf("• O(n) for the temporary arrays used in merging\n");
                printf("• O(log n) for the recursion stack\n");
                printf("• Total: O(n)\n\n");
                
                printf("Variants:\n");
                printf("• Iterative Merge Sort: Avoids recursion overhead\n");
                printf("• In-place Merge Sort: Reduces space complexity\n");
                printf("• Natural Merge Sort: Takes advantage of existing runs\n\n");
                
                printf("When to use:\n");
                printf("• Large datasets where O(n log n) is required\n");
                printf("• When stable sorting is needed\n");
                printf("• External sorting (sorting data that doesn't fit in memory)\n");
                printf("• When consistent performance is important\n");
                break;
                
            case 8:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
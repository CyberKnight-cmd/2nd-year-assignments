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

// Algorithm for Bubble Sort:
// 1. Compare adjacent elements
// 2. Swap if they are in wrong order
// 3. Repeat for all elements
// 4. After each pass, largest element reaches its correct position
// 5. Optimize by reducing comparisons in each pass
void bubbleSort(int arr[], int n) {
    printf("\n=== Bubble Sort Algorithm ===\n");
    printf("Array size: %d\n", n);
    printf("Algorithm: Compare adjacent elements and swap if in wrong order\n\n");
    
    displayArray(arr, n, "Initial array");
    
    int totalComparisons = 0;
    int totalSwaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        int passComparisons = 0;
        int passSwaps = 0;
        
        printf("Pass %d:\n", i + 1);
        
        for (int j = 0; j < n - i - 1; j++) {
            passComparisons++;
            totalComparisons++;
            
            printf("  Comparing arr[%d]=%d with arr[%d]=%d: ", 
                   j, arr[j], j + 1, arr[j + 1]);
            
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = 1;
                passSwaps++;
                totalSwaps++;
                
                printf("Swap needed\n");
            } else {
                printf("No swap\n");
            }
        }
        
        printf("  After pass %d: ", i + 1);
        displayArray(arr, n, "");
        printf("  Pass statistics: %d comparisons, %d swaps\n", 
               passComparisons, passSwaps);
        
        // Optimization: If no swapping occurred, array is sorted
        if (!swapped) {
            printf("  No swaps in this pass - Array is sorted!\n");
            break;
        }
        printf("\n");
    }
    
    printf("Bubble Sort completed!\n");
    printf("Total statistics: %d comparisons, %d swaps\n", 
           totalComparisons, totalSwaps);
    displayArray(arr, n, "Final sorted array");
}

// Optimized bubble sort with early termination
void optimizedBubbleSort(int arr[], int n) {
    printf("\n=== Optimized Bubble Sort ===\n");
    displayArray(arr, n, "Initial array");
    
    int totalComparisons = 0;
    int totalSwaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        
        for (int j = 0; j < n - i - 1; j++) {
            totalComparisons++;
            
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
                totalSwaps++;
            }
        }
        
        if (!swapped) break; // Early termination
    }
    
    printf("Optimized Bubble Sort completed!\n");
    printf("Total statistics: %d comparisons, %d swaps\n", 
           totalComparisons, totalSwaps);
    displayArray(arr, n, "Final sorted array");
}

// Function to copy array
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Function to generate random array
void generateRandomArray(int arr[], int n, int maxValue) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % maxValue + 1;
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
        
        // Generate worst case (reverse sorted)
        for (int j = 0; j < n; j++) {
            arr[j] = n - j;
        }
        
        int comparisons = 0, swaps = 0;
        
        // Count operations in bubble sort
        for (int pass = 0; pass < n - 1; pass++) {
            for (int j = 0; j < n - pass - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swaps++;
                }
            }
        }
        
        printf("%10d | %11d | %5d | O(n²)\n", n, comparisons, swaps);
        free(arr);
    }
}

int main() {
    int choice, n;
    
    printf("=== Bubble Sort Implementation ===\n");
    printf("Bubble Sort: Simple comparison-based sorting algorithm\n");
    printf("Time Complexity: O(n²) average and worst case, O(n) best case\n");
    printf("Space Complexity: O(1) - In-place sorting\n");
    printf("Stability: Stable (maintains relative order of equal elements)\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Sort custom array (step-by-step)\n");
        printf("2. Sort custom array (optimized)\n");
        printf("3. Sort random array\n");
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
                
                bubbleSort(arr, n);
                
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
                
                int* arr = (int*)malloc(n * sizeof(int));
                
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                optimizedBubbleSort(arr, n);
                free(arr);
                break;
            }
            
            case 3: {
                printf("Enter array size: ");
                scanf("%d", &n);
                
                if (n <= 0 || n > 1000) {
                    printf("Invalid size! Please enter size between 1 and 1000.\n");
                    break;
                }
                
                int* arr = (int*)malloc(n * sizeof(int));
                generateRandomArray(arr, n, 100);
                
                printf("Generated random array:\n");
                displayArray(arr, n, "Before sorting");
                
                optimizedBubbleSort(arr, n);
                free(arr);
                break;
            }
            
            case 4:
                performanceAnalysis();
                break;
                
            case 5:
                printf("\n=== Bubble Sort Algorithm Explanation ===\n");
                printf("How it works:\n");
                printf("1. Compare adjacent elements in the array\n");
                printf("2. If they are in wrong order, swap them\n");
                printf("3. Continue this process for the entire array\n");
                printf("4. After each complete pass, the largest element 'bubbles up' to its correct position\n");
                printf("5. Repeat until no more swaps are needed\n\n");
                
                printf("Characteristics:\n");
                printf("• Simple to understand and implement\n");
                printf("• Stable sorting algorithm\n");
                printf("• In-place sorting (O(1) extra space)\n");
                printf("• Adaptive (performs better on nearly sorted arrays)\n\n");
                
                printf("Time Complexity:\n");
                printf("• Best Case: O(n) - when array is already sorted\n");
                printf("• Average Case: O(n²)\n");
                printf("• Worst Case: O(n²) - when array is reverse sorted\n\n");
                
                printf("When to use:\n");
                printf("• Small datasets\n");
                printf("• Educational purposes\n");
                printf("• When simplicity is more important than efficiency\n");
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
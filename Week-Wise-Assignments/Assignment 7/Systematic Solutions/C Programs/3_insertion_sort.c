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

// Algorithm for Insertion Sort:
// 1. Start with second element (assume first is sorted)
// 2. Compare current element with elements in sorted portion
// 3. Shift larger elements to the right
// 4. Insert current element at correct position
// 5. Repeat for all elements
void insertionSort(int arr[], int n) {
    printf("\n=== Insertion Sort Algorithm ===\n");
    printf("Array size: %d\n", n);
    printf("Algorithm: Insert each element at its correct position in sorted portion\n\n");
    
    displayArray(arr, n, "Initial array");
    
    int totalComparisons = 0;
    int totalShifts = 0;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        int passComparisons = 0;
        int passShifts = 0;
        
        printf("Pass %d: Inserting arr[%d] = %d into sorted portion [0, %d]\n", 
               i, i, key, i - 1);
        printf("  Key to insert: %d\n", key);
        printf("  Sorted portion: ");
        for (int k = 0; k < i; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
        
        // Move elements that are greater than key one position ahead
        while (j >= 0) {
            passComparisons++;
            totalComparisons++;
            
            printf("  Comparing key %d with arr[%d] = %d: ", key, j, arr[j]);
            
            if (arr[j] > key) {
                printf("arr[%d] > key, shifting right\n", j);
                arr[j + 1] = arr[j];
                j--;
                passShifts++;
                totalShifts++;
                
                // Show array state after shift
                printf("    After shift: ");
                for (int k = 0; k < n; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            } else {
                printf("arr[%d] <= key, found insertion position\n", j);
                break;
            }
        }
        
        // Insert key at correct position
        arr[j + 1] = key;
        printf("  Inserted %d at position %d\n", key, j + 1);
        
        printf("  After pass %d: ", i);
        displayArray(arr, n, "");
        printf("  Sorted portion: [0, %d], Unsorted portion: [%d, %d]\n", 
               i, i + 1, n - 1);
        printf("  Pass statistics: %d comparisons, %d shifts\n", 
               passComparisons, passShifts);
        printf("\n");
    }
    
    printf("Insertion Sort completed!\n");
    printf("Total statistics: %d comparisons, %d shifts\n", 
           totalComparisons, totalShifts);
    displayArray(arr, n, "Final sorted array");
}

// Binary insertion sort - uses binary search to find insertion position
void binaryInsertionSort(int arr[], int n) {
    printf("\n=== Binary Insertion Sort ===\n");
    displayArray(arr, n, "Initial array");
    
    int totalComparisons = 0;
    int totalShifts = 0;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0, right = i - 1;
        int binaryComparisons = 0;
        
        printf("Pass %d: Finding position for %d using binary search\n", i, key);
        
        // Binary search to find insertion position
        while (left <= right) {
            int mid = left + (right - left) / 2;
            binaryComparisons++;
            totalComparisons++;
            
            printf("  Binary search: left=%d, right=%d, mid=%d, arr[mid]=%d\n", 
                   left, right, mid, arr[mid]);
            
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // Shift elements and insert
        int insertPos = left;
        printf("  Insertion position found: %d\n", insertPos);
        
        for (int j = i - 1; j >= insertPos; j--) {
            arr[j + 1] = arr[j];
            totalShifts++;
        }
        arr[insertPos] = key;
        
        printf("  After inserting %d: ", key);
        displayArray(arr, n, "");
        printf("  Binary search comparisons: %d, Shifts: %d\n", 
               binaryComparisons, i - insertPos);
        printf("\n");
    }
    
    printf("Binary Insertion Sort completed!\n");
    printf("Total statistics: %d comparisons, %d shifts\n", 
           totalComparisons, totalShifts);
}

// Performance analysis function
void performanceAnalysis() {
    printf("\n=== Performance Analysis ===\n");
    
    int sizes[] = {10, 50, 100, 500};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Test Case Analysis:\n");
    printf("Array Size | Best Case | Average Case | Worst Case\n");
    printf("-----------|-----------|--------------|------------\n");
    
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        
        // Best case: already sorted
        int* bestCase = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            bestCase[j] = j + 1;
        }
        
        // Average case: random
        int* avgCase = (int*)malloc(n * sizeof(int));
        srand(time(NULL) + i);
        for (int j = 0; j < n; j++) {
            avgCase[j] = rand() % 1000;
        }
        
        // Worst case: reverse sorted
        int* worstCase = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            worstCase[j] = n - j;
        }
        
        // Count comparisons for each case
        int bestComparisons = n - 1; // Best case always n-1 comparisons
        
        // Average case simulation
        int avgComparisons = 0;
        for (int pass = 1; pass < n; pass++) {
            avgComparisons += pass / 2; // Average case approximation
        }
        
        // Worst case
        int worstComparisons = 0;
        for (int pass = 1; pass < n; pass++) {
            worstComparisons += pass;
        }
        
        printf("%10d | %9d | %12d | %10d\n", 
               n, bestComparisons, avgComparisons, worstComparisons);
        
        free(bestCase);
        free(avgCase);
        free(worstCase);
    }
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
            
        case 2: // Nearly sorted array
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
            }
            // Swap a few elements
            if (n > 4) {
                int temp = arr[1];
                arr[1] = arr[3];
                arr[3] = temp;
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
                arr[i] = rand() % 5 + 1; // Values 1-5
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
    
    printf("=== Insertion Sort Implementation ===\n");
    printf("Insertion Sort: Builds sorted array one element at a time\n");
    printf("Time Complexity: O(n) best case, O(n²) average and worst case\n");
    printf("Space Complexity: O(1) - In-place sorting\n");
    printf("Stability: Stable (maintains relative order of equal elements)\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Sort custom array (step-by-step)\n");
        printf("2. Binary insertion sort\n");
        printf("3. Sort test arrays (different types)\n");
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
                
                insertionSort(arr, n);
                
                printf("\nVerification: Array is %s\n", 
                       isSorted(arr, n) ? "correctly sorted" : "NOT sorted");
                
                free(arr);
                break;
            }
            
            case 2: {
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
                
                binaryInsertionSort(arr, n);
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
                
                printf("\nSelect array type:\n");
                printf("1. Random array\n");
                printf("2. Nearly sorted array\n");
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
                
                const char* typeNames[] = {"", "Random", "Nearly Sorted", "Reverse Sorted", "With Duplicates"};
                printf("\nGenerated %s Array:\n", typeNames[type]);
                
                insertionSort(arr, n);
                free(arr);
                break;
            }
            
            case 4:
                performanceAnalysis();
                break;
                
            case 5:
                printf("\n=== Insertion Sort Algorithm Explanation ===\n");
                printf("How it works:\n");
                printf("1. Start with the second element (consider first element as sorted)\n");
                printf("2. Compare current element with elements in the sorted portion\n");
                printf("3. Shift all larger elements one position to the right\n");
                printf("4. Insert current element at the correct position\n");
                printf("5. Repeat for all remaining elements\n\n");
                
                printf("Characteristics:\n");
                printf("• Simple and intuitive algorithm\n");
                printf("• Stable sorting algorithm\n");
                printf("• In-place sorting (O(1) extra space)\n");
                printf("• Adaptive (efficient for nearly sorted arrays)\n");
                printf("• Online (can sort array as it receives data)\n\n");
                
                printf("Time Complexity:\n");
                printf("• Best Case: O(n) - when array is already sorted\n");
                printf("• Average Case: O(n²)\n");
                printf("• Worst Case: O(n²) - when array is reverse sorted\n\n");
                
                printf("Variants:\n");
                printf("• Binary Insertion Sort: Uses binary search to find insertion position\n");
                printf("  - Reduces comparisons but same number of shifts\n");
                printf("  - Time complexity remains O(n²) due to shifting\n\n");
                
                printf("When to use:\n");
                printf("• Small datasets (typically n < 50)\n");
                printf("• Nearly sorted arrays\n");
                printf("• Online algorithms (sorting data as it arrives)\n");
                printf("• As a subroutine in hybrid algorithms (like Quicksort)\n");
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
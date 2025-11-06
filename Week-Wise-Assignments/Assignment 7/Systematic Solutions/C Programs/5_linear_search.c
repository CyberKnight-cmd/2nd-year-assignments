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

// Algorithm for Linear Search:
// 1. Start from the first element
// 2. Compare each element with the target
// 3. If match found, return index
// 4. If end of array reached without match, return -1
int linearSearch(int arr[], int n, int target, int showSteps) {
    if (showSteps) {
        printf("\n=== Linear Search Process ===\n");
        printf("Searching for: %d\n", target);
        printf("Array size: %d\n", n);
        displayArray(arr, n, "Array");
        printf("\nStep-by-step search:\n");
    }
    
    for (int i = 0; i < n; i++) {
        if (showSteps) {
            printf("Step %d: Checking arr[%d] = %d", i + 1, i, arr[i]);
        }
        
        if (arr[i] == target) {
            if (showSteps) {
                printf(" -> FOUND!\n");
                printf("Target %d found at index %d\n", target, i);
            }
            return i;
        }
        
        if (showSteps) {
            printf(" -> Not a match\n");
        }
    }
    
    if (showSteps) {
        printf("Target %d not found in the array\n", target);
    }
    return -1;
}

// Linear search that finds all occurrences
int linearSearchAll(int arr[], int n, int target, int positions[]) {
    printf("\n=== Finding All Occurrences ===\n");
    printf("Searching for all occurrences of: %d\n", target);
    displayArray(arr, n, "Array");
    
    int count = 0;
    printf("\nSearch process:\n");
    
    for (int i = 0; i < n; i++) {
        printf("Step %d: Checking arr[%d] = %d", i + 1, i, arr[i]);
        
        if (arr[i] == target) {
            positions[count] = i;
            count++;
            printf(" -> MATCH! (Occurrence #%d)\n", count);
        } else {
            printf(" -> No match\n");
        }
    }
    
    if (count > 0) {
        printf("\nFound %d occurrence(s) at position(s): ", count);
        for (int i = 0; i < count; i++) {
            printf("%d", positions[i]);
            if (i < count - 1) printf(", ");
        }
        printf("\n");
    } else {
        printf("\nTarget %d not found in the array\n", target);
    }
    
    return count;
}

// Linear search with early termination for sorted arrays
int linearSearchSorted(int arr[], int n, int target) {
    printf("\n=== Linear Search on Sorted Array (with early termination) ===\n");
    printf("Searching for: %d\n", target);
    displayArray(arr, n, "Sorted array");
    
    printf("\nSearch process:\n");
    
    for (int i = 0; i < n; i++) {
        printf("Step %d: Checking arr[%d] = %d", i + 1, i, arr[i]);
        
        if (arr[i] == target) {
            printf(" -> FOUND!\n");
            printf("Target %d found at index %d\n", target, i);
            return i;
        } else if (arr[i] > target) {
            printf(" -> Element is larger than target\n");
            printf("Since array is sorted, target cannot exist beyond this point\n");
            printf("Early termination: Target %d not found\n", target);
            return -1;
        } else {
            printf(" -> Continue searching\n");
        }
    }
    
    printf("Target %d not found in the array\n", target);
    return -1;
}

// Performance analysis function
void performanceAnalysis() {
    printf("\n=== Performance Analysis ===\n");
    
    int sizes[] = {100, 500, 1000, 5000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Linear Search Performance:\n");
    printf("Array Size | Best Case | Average Case | Worst Case\n");
    printf("-----------|-----------|--------------|------------\n");
    
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int* arr = (int*)malloc(n * sizeof(int));
        
        // Generate array
        for (int j = 0; j < n; j++) {
            arr[j] = j + 1;
        }
        
        // Best case: element at first position
        int bestCase = 1;
        
        // Average case: element at middle position
        int avgCase = n / 2;
        
        // Worst case: element at last position or not found
        int worstCase = n;
        
        printf("%10d | %9d | %12d | %10d\n", 
               n, bestCase, avgCase, worstCase);
        
        free(arr);
    }
    
    printf("\nTime Complexity: O(n) in worst case\n");
    printf("Space Complexity: O(1)\n");
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
            
        case 2: // Sorted array
            for (int i = 0; i < n; i++) {
                arr[i] = (i + 1) * 2; // Even numbers
            }
            break;
            
        case 3: // Array with duplicates
            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                arr[i] = rand() % 10 + 1; // Values 1-10
            }
            break;
            
        case 4: // Reverse sorted array
            for (int i = 0; i < n; i++) {
                arr[i] = (n - i) * 2;
            }
            break;
    }
}

// Sentinel linear search (optimization)
int sentinelLinearSearch(int arr[], int n, int target) {
    printf("\n=== Sentinel Linear Search ===\n");
    printf("Optimization: Add target at end to eliminate bounds checking\n");
    printf("Searching for: %d\n", target);
    
    // Store the last element
    int last = arr[n - 1];
    
    // Put target at the end
    arr[n - 1] = target;
    
    printf("Modified array (target added at end): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nSearch process:\n");
    
    int i = 0;
    while (arr[i] != target) {
        printf("Step %d: arr[%d] = %d (not target)\n", i + 1, i, arr[i]);
        i++;
    }
    
    // Restore the last element
    arr[n - 1] = last;
    
    if (i < n - 1 || arr[n - 1] == target) {
        printf("Step %d: arr[%d] = %d -> FOUND!\n", i + 1, i, target);
        printf("Target found at index %d\n", i);
        return i;
    } else {
        printf("Target reached sentinel position - not found in original array\n");
        return -1;
    }
}

int main() {
    int choice, n;
    
    printf("=== Linear Search Implementation ===\n");
    printf("Linear Search: Sequential search through array elements\n");
    printf("Time Complexity: O(n) worst case, O(1) best case\n");
    printf("Space Complexity: O(1)\n");
    printf("Works on: Both sorted and unsorted arrays\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Search in custom array (step-by-step)\n");
        printf("2. Find all occurrences\n");
        printf("3. Search in sorted array (with early termination)\n");
        printf("4. Sentinel linear search\n");
        printf("5. Search in test arrays\n");
        printf("6. Performance analysis\n");
        printf("7. Algorithm explanation\n");
        printf("8. Exit\n");
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
                
                int target;
                printf("Enter target to search: ");
                scanf("%d", &target);
                
                int result = linearSearch(arr, n, target, 1);
                
                if (result != -1) {
                    printf("\nResult: Target %d found at index %d\n", target, result);
                } else {
                    printf("\nResult: Target %d not found in the array\n", target);
                }
                
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
                int* positions = (int*)malloc(n * sizeof(int));
                
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                int target;
                printf("Enter target to search: ");
                scanf("%d", &target);
                
                int count = linearSearchAll(arr, n, target, positions);
                
                if (count > 0) {
                    printf("\nResult: Found %d occurrence(s) of %d\n", count, target);
                } else {
                    printf("\nResult: Target %d not found\n", target);
                }
                
                free(arr);
                free(positions);
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
                
                printf("Enter %d elements in sorted order: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                int target;
                printf("Enter target to search: ");
                scanf("%d", &target);
                
                int result = linearSearchSorted(arr, n, target);
                
                if (result != -1) {
                    printf("\nResult: Target %d found at index %d\n", target, result);
                } else {
                    printf("\nResult: Target %d not found\n", target);
                }
                
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
                
                int* arr = (int*)malloc(n * sizeof(int));
                
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                int target;
                printf("Enter target to search: ");
                scanf("%d", &target);
                
                displayArray(arr, n, "Original array");
                int result = sentinelLinearSearch(arr, n, target);
                displayArray(arr, n, "Restored array");
                
                if (result != -1) {
                    printf("\nResult: Target %d found at index %d\n", target, result);
                } else {
                    printf("\nResult: Target %d not found\n", target);
                }
                
                free(arr);
                break;
            }
            
            case 5: {
                printf("Enter array size: ");
                scanf("%d", &n);
                
                if (n <= 0 || n > 100) {
                    printf("Invalid size! Please enter size between 1 and 100.\n");
                    break;
                }
                
                printf("\nSelect array type:\n");
                printf("1. Random array\n");
                printf("2. Sorted array\n");
                printf("3. Array with duplicates\n");
                printf("4. Reverse sorted array\n");
                printf("Enter choice: ");
                
                int type;
                scanf("%d", &type);
                
                if (type < 1 || type > 4) {
                    printf("Invalid choice!\n");
                    break;
                }
                
                int* arr = (int*)malloc(n * sizeof(int));
                generateTestArray(arr, n, type);
                
                const char* typeNames[] = {"", "Random", "Sorted", "With Duplicates", "Reverse Sorted"};
                printf("\nGenerated %s Array:\n", typeNames[type]);
                displayArray(arr, n, "Array");
                
                int target;
                printf("Enter target to search: ");
                scanf("%d", &target);
                
                int result = linearSearch(arr, n, target, 1);
                
                if (result != -1) {
                    printf("\nResult: Target %d found at index %d\n", target, result);
                } else {
                    printf("\nResult: Target %d not found\n", target);
                }
                
                free(arr);
                break;
            }
            
            case 6:
                performanceAnalysis();
                break;
                
            case 7:
                printf("\n=== Linear Search Algorithm Explanation ===\n");
                printf("How it works:\n");
                printf("1. Start from the first element of the array\n");
                printf("2. Compare each element with the target value\n");
                printf("3. If a match is found, return the index\n");
                printf("4. If the end of array is reached without finding the target, return -1\n\n");
                
                printf("Characteristics:\n");
                printf("• Simple and straightforward algorithm\n");
                printf("• Works on both sorted and unsorted arrays\n");
                printf("• Sequential access pattern\n");
                printf("• No preprocessing required\n");
                printf("• Can find multiple occurrences\n\n");
                
                printf("Time Complexity:\n");
                printf("• Best Case: O(1) - target is at first position\n");
                printf("• Average Case: O(n/2) - target is at middle position\n");
                printf("• Worst Case: O(n) - target is at last position or not found\n\n");
                
                printf("Space Complexity: O(1) - uses constant extra space\n\n");
                
                printf("Optimizations:\n");
                printf("• Sentinel Search: Add target at end to eliminate bounds checking\n");
                printf("• Early Termination: For sorted arrays, stop when element > target\n");
                printf("• Move to Front: Move found element to front for future searches\n\n");
                
                printf("When to use:\n");
                printf("• Small datasets\n");
                printf("• Unsorted arrays\n");
                printf("• When simplicity is important\n");
                printf("• When array is accessed infrequently\n");
                printf("• Finding all occurrences of an element\n");
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
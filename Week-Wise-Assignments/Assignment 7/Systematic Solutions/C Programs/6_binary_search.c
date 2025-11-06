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

// Algorithm for Binary Search (Recursive):
// 1. Find middle element
// 2. If middle element equals target, return index
// 3. If target is less than middle, search left half
// 4. If target is greater than middle, search right half
// 5. Repeat until found or search space is empty
int binarySearchRecursive(int arr[], int left, int right, int target, int depth) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Print search process
        printf("  Depth %d: Searching in range [%d, %d]\n", depth, left, right);
        printf("           Middle index: %d, Middle value: %d\n", mid, arr[mid]);
        printf("           Comparing target %d with middle %d: ", target, arr[mid]);
        
        if (arr[mid] == target) {
            printf("FOUND!\n");
            return mid;
        }
        
        if (arr[mid] > target) {
            printf("Target < Middle, search left half\n");
            return binarySearchRecursive(arr, left, mid - 1, target, depth + 1);
        } else {
            printf("Target > Middle, search right half\n");
            return binarySearchRecursive(arr, mid + 1, right, target, depth + 1);
        }
    }
    
    printf("  Search space exhausted - Target not found\n");
    return -1;
}

// Algorithm for Binary Search (Iterative):
// 1. Initialize left and right pointers
// 2. While left <= right:
//    a. Calculate middle index
//    b. If middle element equals target, return index
//    c. If target is less than middle, update right = mid - 1
//    d. If target is greater than middle, update left = mid + 1
// 3. Return -1 if not found
int binarySearchIterative(int arr[], int n, int target, int showSteps) {
    int left = 0, right = n - 1;
    int step = 1;
    
    if (showSteps) {
        printf("\n=== Iterative Binary Search Process ===\n");
        printf("Searching for: %d\n", target);
        displayArray(arr, n, "Sorted array");
        printf("\nStep-by-step search:\n");
    }
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (showSteps) {
            printf("Step %d: Range [%d, %d], Mid = %d, arr[%d] = %d\n", 
                   step, left, right, mid, mid, arr[mid]);
            printf("        Comparing target %d with arr[%d] = %d: ", 
                   target, mid, arr[mid]);
        }
        
        if (arr[mid] == target) {
            if (showSteps) {
                printf("FOUND!\n");
                printf("Target %d found at index %d\n", target, mid);
            }
            return mid;
        }
        
        if (arr[mid] > target) {
            if (showSteps) {
                printf("Target < arr[mid], search left half\n");
            }
            right = mid - 1;
        } else {
            if (showSteps) {
                printf("Target > arr[mid], search right half\n");
            }
            left = mid + 1;
        }
        
        step++;
    }
    
    if (showSteps) {
        printf("Search completed: Target %d not found\n", target);
    }
    return -1;
}

// Find first occurrence of target in sorted array with duplicates
int findFirstOccurrence(int arr[], int n, int target) {
    printf("\n=== Finding First Occurrence ===\n");
    printf("Searching for first occurrence of: %d\n", target);
    displayArray(arr, n, "Array with duplicates");
    
    int left = 0, right = n - 1;
    int result = -1;
    int step = 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        printf("Step %d: Range [%d, %d], Mid = %d, arr[%d] = %d\n", 
               step, left, right, mid, mid, arr[mid]);
        
        if (arr[mid] == target) {
            result = mid;
            printf("        Found target at %d, but searching for first occurrence\n", mid);
            right = mid - 1; // Continue searching in left half
        } else if (arr[mid] > target) {
            printf("        Target < arr[mid], search left half\n");
            right = mid - 1;
        } else {
            printf("        Target > arr[mid], search right half\n");
            left = mid + 1;
        }
        
        step++;
    }
    
    if (result != -1) {
        printf("First occurrence of %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found\n", target);
    }
    
    return result;
}

// Find last occurrence of target in sorted array with duplicates
int findLastOccurrence(int arr[], int n, int target) {
    printf("\n=== Finding Last Occurrence ===\n");
    printf("Searching for last occurrence of: %d\n", target);
    
    int left = 0, right = n - 1;
    int result = -1;
    int step = 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        printf("Step %d: Range [%d, %d], Mid = %d, arr[%d] = %d\n", 
               step, left, right, mid, mid, arr[mid]);
        
        if (arr[mid] == target) {
            result = mid;
            printf("        Found target at %d, but searching for last occurrence\n", mid);
            left = mid + 1; // Continue searching in right half
        } else if (arr[mid] > target) {
            printf("        Target < arr[mid], search left half\n");
            right = mid - 1;
        } else {
            printf("        Target > arr[mid], search right half\n");
            left = mid + 1;
        }
        
        step++;
    }
    
    if (result != -1) {
        printf("Last occurrence of %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found\n", target);
    }
    
    return result;
}

// Count occurrences of target using binary search
int countOccurrences(int arr[], int n, int target) {
    int first = findFirstOccurrence(arr, n, target);
    if (first == -1) {
        return 0;
    }
    
    int last = findLastOccurrence(arr, n, target);
    int count = last - first + 1;
    
    printf("\nTotal occurrences of %d: %d (from index %d to %d)\n", 
           target, count, first, last);
    
    return count;
}

// Performance analysis function
void performanceAnalysis() {
    printf("\n=== Performance Analysis ===\n");
    
    int sizes[] = {16, 64, 256, 1024, 4096};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Binary Search Performance (Sorted Arrays):\n");
    printf("Array Size | Max Steps | log₂(n) | Efficiency\n");
    printf("-----------|-----------|---------|------------\n");
    
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int maxSteps = 0;
        int temp = n;
        
        // Calculate log₂(n)
        while (temp > 1) {
            temp /= 2;
            maxSteps++;
        }
        maxSteps++; // Add 1 for the final comparison
        
        double logN = maxSteps;
        double efficiency = (double)n / maxSteps;
        
        printf("%10d | %9d | %7.0f | %10.0f\n", 
               n, maxSteps, logN, efficiency);
    }
    
    printf("\nTime Complexity: O(log n)\n");
    printf("Space Complexity: O(1) iterative, O(log n) recursive\n");
}

// Function to generate sorted array
void generateSortedArray(int arr[], int n, int type) {
    switch (type) {
        case 1: // Consecutive integers
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
            }
            break;
            
        case 2: // Even numbers
            for (int i = 0; i < n; i++) {
                arr[i] = (i + 1) * 2;
            }
            break;
            
        case 3: // Powers of 2
            arr[0] = 1;
            for (int i = 1; i < n; i++) {
                arr[i] = arr[i-1] * 2;
            }
            break;
            
        case 4: // Array with duplicates
            for (int i = 0; i < n; i++) {
                arr[i] = (i / 3) + 1; // Groups of 3 same numbers
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
    
    printf("=== Binary Search Implementation ===\n");
    printf("Binary Search: Efficient search for sorted arrays\n");
    printf("Time Complexity: O(log n)\n");
    printf("Space Complexity: O(1) iterative, O(log n) recursive\n");
    printf("Prerequisite: Array must be sorted\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Binary search (iterative, step-by-step)\n");
        printf("2. Binary search (recursive, step-by-step)\n");
        printf("3. Find first occurrence\n");
        printf("4. Find last occurrence\n");
        printf("5. Count occurrences\n");
        printf("6. Search in generated arrays\n");
        printf("7. Performance analysis\n");
        printf("8. Algorithm explanation\n");
        printf("9. Exit\n");
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
                
                printf("Enter %d elements in sorted order: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                if (!isSorted(arr, n)) {
                    printf("Warning: Array is not sorted! Binary search may not work correctly.\n");
                }
                
                int target;
                printf("Enter target to search: ");
                scanf("%d", &target);
                
                int result = binarySearchIterative(arr, n, target, 1);
                
                if (result != -1) {
                    printf("\nResult: Target %d found at index %d\n", target, result);
                } else {
                    printf("\nResult: Target %d not found\n", target);
                }
                
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
                
                printf("Enter %d elements in sorted order: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                if (!isSorted(arr, n)) {
                    printf("Warning: Array is not sorted!\n");
                }
                
                int target;
                printf("Enter target to search: ");
                scanf("%d", &target);
                
                printf("\n=== Recursive Binary Search Process ===\n");
                printf("Searching for: %d\n", target);
                displayArray(arr, n, "Sorted array");
                printf("\nRecursive search steps:\n");
                
                int result = binarySearchRecursive(arr, 0, n - 1, target, 1);
                
                if (result != -1) {
                    printf("\nResult: Target %d found at index %d\n", target, result);
                } else {
                    printf("\nResult: Target %d not found\n", target);
                }
                
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
                
                printf("Enter %d elements in sorted order (duplicates allowed): ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                int target;
                printf("Enter target to find first occurrence: ");
                scanf("%d", &target);
                
                findFirstOccurrence(arr, n, target);
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
                
                printf("Enter %d elements in sorted order (duplicates allowed): ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                int target;
                printf("Enter target to find last occurrence: ");
                scanf("%d", &target);
                
                findLastOccurrence(arr, n, target);
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
                
                int* arr = (int*)malloc(n * sizeof(int));
                
                printf("Enter %d elements in sorted order (duplicates allowed): ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                
                int target;
                printf("Enter target to count occurrences: ");
                scanf("%d", &target);
                
                countOccurrences(arr, n, target);
                free(arr);
                break;
            }
            
            case 6: {
                printf("Enter array size: ");
                scanf("%d", &n);
                
                if (n <= 0 || n > 100) {
                    printf("Invalid size! Please enter size between 1 and 100.\n");
                    break;
                }
                
                printf("\nSelect array type:\n");
                printf("1. Consecutive integers (1, 2, 3, ...)\n");
                printf("2. Even numbers (2, 4, 6, ...)\n");
                printf("3. Powers of 2 (1, 2, 4, 8, ...)\n");
                printf("4. Array with duplicates\n");
                printf("Enter choice: ");
                
                int type;
                scanf("%d", &type);
                
                if (type < 1 || type > 4) {
                    printf("Invalid choice!\n");
                    break;
                }
                
                int* arr = (int*)malloc(n * sizeof(int));
                generateSortedArray(arr, n, type);
                
                const char* typeNames[] = {"", "Consecutive", "Even Numbers", "Powers of 2", "With Duplicates"};
                printf("\nGenerated %s Array:\n", typeNames[type]);
                displayArray(arr, n, "Array");
                
                int target;
                printf("Enter target to search: ");
                scanf("%d", &target);
                
                int result = binarySearchIterative(arr, n, target, 1);
                
                if (result != -1) {
                    printf("\nResult: Target %d found at index %d\n", target, result);
                } else {
                    printf("\nResult: Target %d not found\n", target);
                }
                
                free(arr);
                break;
            }
            
            case 7:
                performanceAnalysis();
                break;
                
            case 8:
                printf("\n=== Binary Search Algorithm Explanation ===\n");
                printf("How it works:\n");
                printf("1. Array must be sorted in ascending order\n");
                printf("2. Compare target with middle element\n");
                printf("3. If target equals middle, return index\n");
                printf("4. If target is less than middle, search left half\n");
                printf("5. If target is greater than middle, search right half\n");
                printf("6. Repeat until found or search space is empty\n\n");
                
                printf("Characteristics:\n");
                printf("• Requires sorted array\n");
                printf("• Divide and conquer approach\n");
                printf("• Eliminates half of search space in each step\n");
                printf("• Much faster than linear search for large arrays\n");
                printf("• Can be implemented iteratively or recursively\n\n");
                
                printf("Time Complexity:\n");
                printf("• Best Case: O(1) - target is at middle\n");
                printf("• Average Case: O(log n)\n");
                printf("• Worst Case: O(log n) - target is at end or not found\n\n");
                
                printf("Space Complexity:\n");
                printf("• Iterative: O(1)\n");
                printf("• Recursive: O(log n) - due to recursion stack\n\n");
                
                printf("Variants:\n");
                printf("• Find first occurrence in array with duplicates\n");
                printf("• Find last occurrence in array with duplicates\n");
                printf("• Count occurrences using first and last positions\n");
                printf("• Search in rotated sorted array\n\n");
                
                printf("When to use:\n");
                printf("• Large sorted datasets\n");
                printf("• When fast search is required\n");
                printf("• When array doesn't change frequently\n");
                printf("• Database indexing and searching\n");
                break;
                
            case 9:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
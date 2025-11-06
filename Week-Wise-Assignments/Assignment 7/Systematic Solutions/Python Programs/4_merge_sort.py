def merge(arr, left, mid, right, show_steps=False):
    """
    Algorithm for Merge operation:
    1. Create temporary arrays for left and right subarrays
    2. Copy data to temporary arrays
    3. Merge temporary arrays back into original array in sorted order
    4. Compare elements from both arrays and pick smaller one
    """
    global merge_operations
    
    # Create temporary arrays
    left_arr = arr[left:mid + 1]
    right_arr = arr[mid + 1:right + 1]
    
    if show_steps:
        print(f"  Merging subarrays [{left}, {mid}] and [{mid + 1}, {right}]")
        print(f"    Left subarray:  {left_arr}")
        print(f"    Right subarray: {right_arr}")
    
    # Merge the temporary arrays back into arr[left..right]
    i = j = 0
    k = left
    
    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] <= right_arr[j]:
            arr[k] = left_arr[i]
            if show_steps:
                print(f"    Comparing {left_arr[i]} <= {right_arr[j]}: Choose {left_arr[i]}")
            i += 1
        else:
            arr[k] = right_arr[j]
            if show_steps:
                print(f"    Comparing {left_arr[i]} > {right_arr[j]}: Choose {right_arr[j]}")
            j += 1
        k += 1
    
    # Copy remaining elements of left_arr, if any
    while i < len(left_arr):
        arr[k] = left_arr[i]
        if show_steps:
            print(f"    Copying remaining from left: {left_arr[i]}")
        i += 1
        k += 1
    
    # Copy remaining elements of right_arr, if any
    while j < len(right_arr):
        arr[k] = right_arr[j]
        if show_steps:
            print(f"    Copying remaining from right: {right_arr[j]}")
        j += 1
        k += 1
    
    if show_steps:
        print(f"    Merged result: {arr[left:right + 1]}")
        print()
    
    merge_operations += 1

def merge_sort(arr, left, right, show_steps=False):
    """
    Algorithm for Merge Sort:
    1. Divide the array into two halves
    2. Recursively sort both halves
    3. Merge the sorted halves
    """
    global recursive_depth, max_depth
    
    if left < right:
        recursive_depth += 1
        if recursive_depth > max_depth:
            max_depth = recursive_depth
        
        mid = left + (right - left) // 2
        
        if show_steps:
            print(f"Dividing array [{left}, {right}] at mid = {mid}")
            print(f"  Left half: [{left}, {mid}], Right half: [{mid + 1}, {right}]")
        
        # Sort first and second halves
        merge_sort(arr, left, mid, show_steps)
        merge_sort(arr, mid + 1, right, show_steps)
        
        # Merge the sorted halves
        merge(arr, left, mid, right, show_steps)
        
        recursive_depth -= 1

def merge_sort_iterative(arr):
    """Iterative merge sort implementation"""
    n = len(arr)
    print(f"\n=== Iterative Merge Sort ===")
    print(f"Initial array: {arr}")
    
    merge_count = 0
    
    # Current size of subarrays to be merged
    curr_size = 1
    while curr_size < n:
        print(f"\nMerging subarrays of size {curr_size}:")
        
        # Pick starting point of left sub array
        left_start = 0
        while left_start < n - 1:
            # Calculate mid and right points
            mid = min(left_start + curr_size - 1, n - 1)
            right_end = min(left_start + 2 * curr_size - 1, n - 1)
            
            if mid < right_end:
                print(f"  Merging [{left_start}, {mid}] with [{mid + 1}, {right_end}]")
                merge(arr, left_start, mid, right_end, False)
                merge_count += 1
            
            left_start += 2 * curr_size
        
        print(f"  After merging size {curr_size}: {arr}")
        curr_size *= 2
    
    print(f"\nIterative Merge Sort completed!")
    print(f"Total merge operations: {merge_count}")
    
    return arr

def performance_analysis():
    """Analyze performance for different array sizes"""
    print(f"\n=== Performance Analysis ===")
    
    sizes = [8, 16, 32, 64, 128]
    
    print("Array Size | Merge Ops | Max Depth | Time Complexity")
    print("-----------|-----------|-----------|----------------")
    
    for size in sizes:
        # Generate random array
        import random
        arr = [random.randint(1, 1000) for _ in range(size)]
        
        # Reset counters
        global merge_operations, recursive_depth, max_depth
        merge_operations = 0
        recursive_depth = 0
        max_depth = 0
        
        # Perform merge sort
        merge_sort(arr, 0, size - 1, False)
        
        print(f"{size:10d} | {merge_operations:9d} | {max_depth:9d} | O(n log n)")

def demonstrate_merge():
    """Demonstrate merge operation"""
    print(f"\n=== Merge Operation Demonstration ===")
    
    arr = [2, 5, 8, 1, 3, 9]
    
    print("Demonstrating merge of two sorted subarrays:")
    print(f"Array with two sorted parts: {arr}")
    print("Left sorted part: [0, 2] = {2, 5, 8}")
    print("Right sorted part: [3, 5] = {1, 3, 9}")
    print()
    
    merge(arr, 0, 2, 5, True)
    
    print(f"After merging: {arr}")

def generate_test_array(size, array_type):
    """Generate different types of test arrays"""
    import random
    
    if array_type == 1:  # Random array
        return [random.randint(1, 100) for _ in range(size)]
    elif array_type == 2:  # Already sorted
        return list(range(1, size + 1))
    elif array_type == 3:  # Reverse sorted
        return list(range(size, 0, -1))
    elif array_type == 4:  # Array with duplicates
        return [random.randint(1, 10) for _ in range(size)]
    else:
        return [random.randint(1, 100) for _ in range(size)]

def is_sorted(arr):
    """Check if array is sorted"""
    return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))

# Global variables for tracking operations
merge_operations = 0
recursive_depth = 0
max_depth = 0

def main():
    """Main function with interactive menu"""
    print("=== Merge Sort Implementation ===")
    print("Merge Sort: Divide and conquer sorting algorithm")
    print("Time Complexity: O(n log n) for all cases")
    print("Space Complexity: O(n) - Requires additional space for merging")
    print("Stability: Stable (maintains relative order of equal elements)\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Sort custom array (recursive, step-by-step)")
        print("2. Sort custom array (recursive, fast)")
        print("3. Sort using iterative merge sort")
        print("4. Sort test arrays (different types)")
        print("5. Demonstrate merge operation")
        print("6. Performance analysis")
        print("7. Algorithm explanation")
        print("8. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 50:
                    print("Invalid size! Please enter size between 1 and 50.")
                    continue
                
                print(f"Enter {size} elements separated by spaces: ")
                arr = list(map(int, input().split()))
                
                if len(arr) != size:
                    print("Number of elements doesn't match the specified size!")
                    continue
                
                print(f"\n=== Recursive Merge Sort (Step-by-step) ===")
                print(f"Initial array: {arr}")
                
                # Reset counters
                global merge_operations, recursive_depth, max_depth
                merge_operations = 0
                recursive_depth = 0
                max_depth = 0
                
                merge_sort(arr, 0, len(arr) - 1, True)
                
                print("Merge Sort completed!")
                print(f"Statistics: {merge_operations} merge operations, max recursion depth: {max_depth}")
                print(f"Final sorted array: {arr}")
                
                print(f"\nVerification: Array is {'correctly sorted' if is_sorted(arr) else 'NOT sorted'}")
                
            elif choice == 2:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 1000:
                    print("Invalid size! Please enter size between 1 and 1000.")
                    continue
                
                print(f"Enter {size} elements separated by spaces: ")
                arr = list(map(int, input().split()))
                
                if len(arr) != size:
                    print("Number of elements doesn't match the specified size!")
                    continue
                
                print(f"\n=== Recursive Merge Sort (Fast) ===")
                print(f"Initial array: {arr}")
                
                # Reset counters
                merge_operations = 0
                recursive_depth = 0
                max_depth = 0
                
                merge_sort(arr, 0, len(arr) - 1, False)
                
                print("Merge Sort completed!")
                print(f"Statistics: {merge_operations} merge operations, max recursion depth: {max_depth}")
                print(f"Final sorted array: {arr}")
                
            elif choice == 3:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 100:
                    print("Invalid size! Please enter size between 1 and 100.")
                    continue
                
                print(f"Enter {size} elements separated by spaces: ")
                arr = list(map(int, input().split()))
                
                if len(arr) != size:
                    print("Number of elements doesn't match the specified size!")
                    continue
                
                merge_sort_iterative(arr)
                
            elif choice == 4:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 100:
                    print("Invalid size! Please enter size between 1 and 100.")
                    continue
                
                print("\nSelect array type:")
                print("1. Random array")
                print("2. Already sorted array")
                print("3. Reverse sorted array")
                print("4. Array with duplicates")
                
                array_type = int(input("Enter choice: "))
                
                if array_type < 1 or array_type > 4:
                    print("Invalid choice!")
                    continue
                
                arr = generate_test_array(size, array_type)
                
                type_names = ["", "Random", "Sorted", "Reverse Sorted", "With Duplicates"]
                print(f"\nGenerated {type_names[array_type]} Array:")
                print(f"Before sorting: {arr}")
                
                # Reset counters
                merge_operations = 0
                recursive_depth = 0
                max_depth = 0
                
                merge_sort(arr, 0, len(arr) - 1, False)
                
                print(f"Statistics: {merge_operations} merge operations, max depth: {max_depth}")
                print(f"After sorting: {arr}")
                
            elif choice == 5:
                demonstrate_merge()
                
            elif choice == 6:
                performance_analysis()
                
            elif choice == 7:
                print(f"\n=== Merge Sort Algorithm Explanation ===")
                print("How it works:")
                print("1. Divide: Split the array into two halves")
                print("2. Conquer: Recursively sort both halves")
                print("3. Combine: Merge the sorted halves into a single sorted array\n")
                
                print("Characteristics:")
                print("• Divide and conquer algorithm")
                print("• Stable sorting algorithm")
                print("• Not in-place (requires O(n) extra space)")
                print("• Consistent performance regardless of input")
                print("• Parallelizable (can be implemented in parallel)\n")
                
                print("Time Complexity:")
                print("• Best Case: O(n log n)")
                print("• Average Case: O(n log n)")
                print("• Worst Case: O(n log n)")
                print("• Always performs the same number of operations\n")
                
                print("Space Complexity:")
                print("• O(n) for the temporary arrays used in merging")
                print("• O(log n) for the recursion stack")
                print("• Total: O(n)\n")
                
                print("Variants:")
                print("• Iterative Merge Sort: Avoids recursion overhead")
                print("• In-place Merge Sort: Reduces space complexity")
                print("• Natural Merge Sort: Takes advantage of existing runs\n")
                
                print("When to use:")
                print("• Large datasets where O(n log n) is required")
                print("• When stable sorting is needed")
                print("• External sorting (sorting data that doesn't fit in memory)")
                print("• When consistent performance is important")
                
            elif choice == 8:
                print("Exiting program...")
                break
                
            else:
                print("Invalid choice! Please try again.")
                
        except ValueError:
            print("Invalid input! Please enter a valid number.")
        except Exception as e:
            print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
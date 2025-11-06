def insertion_sort(arr, show_steps=False):
    """
    Algorithm for Insertion Sort:
    1. Start with second element (assume first is sorted)
    2. Compare current element with elements in sorted portion
    3. Shift larger elements to the right
    4. Insert current element at correct position
    5. Repeat for all elements
    """
    n = len(arr)
    
    if show_steps:
        print(f"\n=== Insertion Sort Algorithm ===")
        print(f"Array size: {n}")
        print(f"Initial array: {arr}")
        print("Algorithm: Insert each element at its correct position in sorted portion\n")
    
    total_comparisons = 0
    total_shifts = 0
    
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        pass_comparisons = 0
        pass_shifts = 0
        
        if show_steps:
            print(f"Pass {i}: Inserting arr[{i}] = {key} into sorted portion [0, {i-1}]")
            print(f"  Key to insert: {key}")
            print(f"  Sorted portion: {arr[:i]}")
        
        # Move elements that are greater than key one position ahead
        while j >= 0:
            pass_comparisons += 1
            total_comparisons += 1
            
            if show_steps:
                print(f"  Comparing key {key} with arr[{j}] = {arr[j]}: ", end="")
            
            if arr[j] > key:
                if show_steps:
                    print(f"arr[{j}] > key, shifting right")
                
                arr[j + 1] = arr[j]
                j -= 1
                pass_shifts += 1
                total_shifts += 1
                
                if show_steps:
                    print(f"    After shift: {arr}")
            else:
                if show_steps:
                    print(f"arr[{j}] <= key, found insertion position")
                break
        
        # Insert key at correct position
        arr[j + 1] = key
        
        if show_steps:
            print(f"  Inserted {key} at position {j + 1}")
            print(f"  After pass {i}: {arr}")
            print(f"  Sorted portion: [0, {i}], Unsorted portion: [{i + 1}, {n - 1}]")
            print(f"  Pass statistics: {pass_comparisons} comparisons, {pass_shifts} shifts")
            print()
    
    if show_steps:
        print("Insertion Sort completed!")
        print(f"Total statistics: {total_comparisons} comparisons, {total_shifts} shifts")
        print(f"Final sorted array: {arr}")
    
    return arr, total_comparisons, total_shifts

def binary_insertion_sort(arr):
    """Binary insertion sort - uses binary search to find insertion position"""
    n = len(arr)
    print(f"\n=== Binary Insertion Sort ===")
    print(f"Initial array: {arr}")
    
    total_comparisons = 0
    total_shifts = 0
    
    for i in range(1, n):
        key = arr[i]
        left, right = 0, i - 1
        binary_comparisons = 0
        
        print(f"Pass {i}: Finding position for {key} using binary search")
        
        # Binary search to find insertion position
        while left <= right:
            mid = left + (right - left) // 2
            binary_comparisons += 1
            total_comparisons += 1
            
            print(f"  Binary search: left={left}, right={right}, mid={mid}, arr[mid]={arr[mid]}")
            
            if arr[mid] > key:
                right = mid - 1
            else:
                left = mid + 1
        
        # Shift elements and insert
        insert_pos = left
        print(f"  Insertion position found: {insert_pos}")
        
        shifts = i - insert_pos
        for j in range(i - 1, insert_pos - 1, -1):
            arr[j + 1] = arr[j]
            total_shifts += 1
        
        arr[insert_pos] = key
        
        print(f"  After inserting {key}: {arr}")
        print(f"  Binary search comparisons: {binary_comparisons}, Shifts: {shifts}")
        print()
    
    print("Binary Insertion Sort completed!")
    print(f"Total statistics: {total_comparisons} comparisons, {total_shifts} shifts")
    
    return arr

def performance_analysis():
    """Analyze performance for different test cases"""
    print(f"\n=== Performance Analysis ===")
    
    sizes = [10, 50, 100, 500]
    
    print("Test Case Analysis:")
    print("Array Size | Best Case | Average Case | Worst Case")
    print("-----------|-----------|--------------|------------")
    
    for size in sizes:
        # Best case: already sorted
        best_comparisons = size - 1
        
        # Average case approximation
        avg_comparisons = sum(i // 2 for i in range(1, size))
        
        # Worst case: reverse sorted
        worst_comparisons = sum(range(1, size))
        
        print(f"{size:10d} | {best_comparisons:9d} | {avg_comparisons:12d} | {worst_comparisons:10d}")

def generate_test_array(size, array_type):
    """Generate different types of test arrays"""
    import random
    
    if array_type == 1:  # Random array
        return [random.randint(1, 100) for _ in range(size)]
    elif array_type == 2:  # Nearly sorted array
        arr = list(range(1, size + 1))
        # Swap a few elements
        if size > 4:
            arr[1], arr[3] = arr[3], arr[1]
        return arr
    elif array_type == 3:  # Reverse sorted array
        return list(range(size, 0, -1))
    elif array_type == 4:  # Array with duplicates
        return [random.randint(1, 5) for _ in range(size)]
    else:
        return [random.randint(1, 100) for _ in range(size)]

def is_sorted(arr):
    """Check if array is sorted"""
    return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))

def main():
    """Main function with interactive menu"""
    print("=== Insertion Sort Implementation ===")
    print("Insertion Sort: Builds sorted array one element at a time")
    print("Time Complexity: O(n) best case, O(n²) average and worst case")
    print("Space Complexity: O(1) - In-place sorting")
    print("Stability: Stable (maintains relative order of equal elements)\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Sort custom array (step-by-step)")
        print("2. Binary insertion sort")
        print("3. Sort test arrays (different types)")
        print("4. Performance analysis")
        print("5. Algorithm explanation")
        print("6. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 100:
                    print("Invalid size! Please enter size between 1 and 100.")
                    continue
                
                print(f"Enter {size} elements separated by spaces: ")
                arr = list(map(int, input().split()))
                
                if len(arr) != size:
                    print("Number of elements doesn't match the specified size!")
                    continue
                
                sorted_arr, comparisons, shifts = insertion_sort(arr, show_steps=True)
                
                print(f"\nVerification: Array is {'correctly sorted' if is_sorted(sorted_arr) else 'NOT sorted'}")
                
            elif choice == 2:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 50:
                    print("Invalid size! Please enter size between 1 and 50.")
                    continue
                
                print(f"Enter {size} elements separated by spaces: ")
                arr = list(map(int, input().split()))
                
                if len(arr) != size:
                    print("Number of elements doesn't match the specified size!")
                    continue
                
                binary_insertion_sort(arr)
                
            elif choice == 3:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 100:
                    print("Invalid size! Please enter size between 1 and 100.")
                    continue
                
                print("\nSelect array type:")
                print("1. Random array")
                print("2. Nearly sorted array")
                print("3. Reverse sorted array")
                print("4. Array with duplicates")
                
                array_type = int(input("Enter choice: "))
                
                if array_type < 1 or array_type > 4:
                    print("Invalid choice!")
                    continue
                
                arr = generate_test_array(size, array_type)
                
                type_names = ["", "Random", "Nearly Sorted", "Reverse Sorted", "With Duplicates"]
                print(f"\nGenerated {type_names[array_type]} Array:")
                
                insertion_sort(arr, show_steps=True)
                
            elif choice == 4:
                performance_analysis()
                
            elif choice == 5:
                print(f"\n=== Insertion Sort Algorithm Explanation ===")
                print("How it works:")
                print("1. Start with the second element (consider first element as sorted)")
                print("2. Compare current element with elements in the sorted portion")
                print("3. Shift all larger elements one position to the right")
                print("4. Insert current element at the correct position")
                print("5. Repeat for all remaining elements\n")
                
                print("Characteristics:")
                print("• Simple and intuitive algorithm")
                print("• Stable sorting algorithm")
                print("• In-place sorting (O(1) extra space)")
                print("• Adaptive (efficient for nearly sorted arrays)")
                print("• Online (can sort array as it receives data)\n")
                
                print("Time Complexity:")
                print("• Best Case: O(n) - when array is already sorted")
                print("• Average Case: O(n²)")
                print("• Worst Case: O(n²) - when array is reverse sorted\n")
                
                print("Variants:")
                print("• Binary Insertion Sort: Uses binary search to find insertion position")
                print("  - Reduces comparisons but same number of shifts")
                print("  - Time complexity remains O(n²) due to shifting\n")
                
                print("When to use:")
                print("• Small datasets (typically n < 50)")
                print("• Nearly sorted arrays")
                print("• Online algorithms (sorting data as it arrives)")
                print("• As a subroutine in hybrid algorithms (like Quicksort)")
                
            elif choice == 6:
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
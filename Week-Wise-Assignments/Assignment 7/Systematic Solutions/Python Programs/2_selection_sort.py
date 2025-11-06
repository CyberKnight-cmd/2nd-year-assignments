def selection_sort(arr, show_steps=False):
    """
    Algorithm for Selection Sort:
    1. Find the minimum element in unsorted portion
    2. Swap it with the first element of unsorted portion
    3. Move the boundary of sorted and unsorted portions
    4. Repeat until entire array is sorted
    """
    n = len(arr)
    
    if show_steps:
        print(f"\n=== Selection Sort Algorithm ===")
        print(f"Array size: {n}")
        print(f"Initial array: {arr}")
        print("Algorithm: Find minimum element and place it at the beginning\n")
    
    total_comparisons = 0
    total_swaps = 0
    
    for i in range(n - 1):
        min_index = i
        pass_comparisons = 0
        
        if show_steps:
            print(f"Pass {i + 1}: Finding minimum in range [{i}, {n - 1}]")
            print(f"  Current minimum: arr[{min_index}] = {arr[min_index]}")
        
        # Find minimum element in remaining unsorted array
        for j in range(i + 1, n):
            pass_comparisons += 1
            total_comparisons += 1
            
            if show_steps:
                print(f"  Comparing arr[{j}]={arr[j]} with current min arr[{min_index}]={arr[min_index]}: ", end="")
            
            if arr[j] < arr[min_index]:
                min_index = j
                if show_steps:
                    print(f"New minimum found at index {min_index}")
            else:
                if show_steps:
                    print("No change")
        
        # Swap the found minimum element with the first element
        if min_index != i:
            if show_steps:
                print(f"  Swapping arr[{i}]={arr[i]} with arr[{min_index}]={arr[min_index]}")
            
            arr[i], arr[min_index] = arr[min_index], arr[i]
            total_swaps += 1
        else:
            if show_steps:
                print("  No swap needed - minimum is already at correct position")
        
        if show_steps:
            print(f"  After pass {i + 1}: {arr}")
            print(f"  Sorted portion: [0, {i}], Unsorted portion: [{i + 1}, {n - 1}]")
            print(f"  Pass statistics: {pass_comparisons} comparisons, {'1 swap' if min_index != i else '0 swaps'}")
            print()
    
    if show_steps:
        print("Selection Sort completed!")
        print(f"Total statistics: {total_comparisons} comparisons, {total_swaps} swaps")
        print(f"Final sorted array: {arr}")
    
    return arr, total_comparisons, total_swaps

def find_kth_smallest(arr, k):
    """Find kth smallest element using selection sort approach"""
    print(f"\n=== Finding {k}{'st' if k == 1 else 'nd' if k == 2 else 'rd' if k == 3 else 'th'} smallest element ===")
    
    # Create a copy to avoid modifying original array
    temp = arr.copy()
    n = len(temp)
    
    # Perform selection sort for first k elements
    for i in range(k):
        min_index = i
        
        for j in range(i + 1, n):
            if temp[j] < temp[min_index]:
                min_index = j
        
        if min_index != i:
            temp[i], temp[min_index] = temp[min_index], temp[i]
        
        print(f"After finding {i + 1}{'st' if i == 0 else 'nd' if i == 1 else 'rd' if i == 2 else 'th'} smallest: {temp}")
    
    return temp[k - 1]

def performance_analysis():
    """Analyze performance for different array sizes"""
    print(f"\n=== Performance Analysis ===")
    
    sizes = [10, 50, 100, 500]
    
    print("Array Size | Comparisons | Swaps | Time Complexity")
    print("-----------|-------------|-------|----------------")
    
    for size in sizes:
        # Generate random array
        import random
        arr = [random.randint(1, 1000) for _ in range(size)]
        
        comparisons = 0
        swaps = 0
        
        # Count operations in selection sort
        for i in range(size - 1):
            min_index = i
            
            for j in range(i + 1, size):
                comparisons += 1
                if arr[j] < arr[min_index]:
                    min_index = j
            
            if min_index != i:
                arr[i], arr[min_index] = arr[min_index], arr[i]
                swaps += 1
        
        print(f"{size:10d} | {comparisons:11d} | {swaps:5d} | O(n²)")

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

def main():
    """Main function with interactive menu"""
    print("=== Selection Sort Implementation ===")
    print("Selection Sort: Finds minimum element and places it at correct position")
    print("Time Complexity: O(n²) for all cases")
    print("Space Complexity: O(1) - In-place sorting")
    print("Stability: Not stable (may change relative order of equal elements)\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Sort custom array (step-by-step)")
        print("2. Sort test arrays (different types)")
        print("3. Find kth smallest element")
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
                
                sorted_arr, comparisons, swaps = selection_sort(arr, show_steps=True)
                
                print(f"\nVerification: Array is {'correctly sorted' if is_sorted(sorted_arr) else 'NOT sorted'}")
                
            elif choice == 2:
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
                
                selection_sort(arr, show_steps=True)
                
            elif choice == 3:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 50:
                    print("Invalid size! Please enter size between 1 and 50.")
                    continue
                
                print(f"Enter {size} elements separated by spaces: ")
                arr = list(map(int, input().split()))
                
                if len(arr) != size:
                    print("Number of elements doesn't match the specified size!")
                    continue
                
                k = int(input(f"Enter k (1 to {size}): "))
                
                if k < 1 or k > size:
                    print(f"Invalid k! Must be between 1 and {size}.")
                    continue
                
                print(f"Original array: {arr}")
                kth_smallest = find_kth_smallest(arr, k)
                print(f"The {k}{'st' if k == 1 else 'nd' if k == 2 else 'rd' if k == 3 else 'th'} smallest element is: {kth_smallest}")
                
            elif choice == 4:
                performance_analysis()
                
            elif choice == 5:
                print(f"\n=== Selection Sort Algorithm Explanation ===")
                print("How it works:")
                print("1. Divide the array into sorted and unsorted portions")
                print("2. Initially, sorted portion is empty and unsorted portion is entire array")
                print("3. Find the minimum element in the unsorted portion")
                print("4. Swap it with the first element of unsorted portion")
                print("5. Move the boundary between sorted and unsorted portions")
                print("6. Repeat until entire array is sorted\n")
                
                print("Characteristics:")
                print("• Simple to understand and implement")
                print("• Not stable (may change relative order of equal elements)")
                print("• In-place sorting (O(1) extra space)")
                print("• Not adaptive (same performance regardless of input)")
                print("• Minimizes number of swaps (at most n-1 swaps)\n")
                
                print("Time Complexity:")
                print("• Best Case: O(n²)")
                print("• Average Case: O(n²)")
                print("• Worst Case: O(n²)")
                print("• Always performs (n-1) + (n-2) + ... + 1 = n(n-1)/2 comparisons\n")
                
                print("When to use:")
                print("• Small datasets")
                print("• When memory write is costly (minimizes swaps)")
                print("• When simplicity is important")
                
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
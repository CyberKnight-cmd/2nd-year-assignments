def bubble_sort(arr, show_steps=False):
    """
    Algorithm for Bubble Sort:
    1. Compare adjacent elements
    2. Swap if they are in wrong order
    3. Repeat for all elements
    4. After each pass, largest element reaches its correct position
    """
    n = len(arr)
    
    if show_steps:
        print(f"\n=== Bubble Sort Algorithm ===")
        print(f"Array size: {n}")
        print(f"Initial array: {arr}")
        print("Algorithm: Compare adjacent elements and swap if in wrong order\n")
    
    total_comparisons = 0
    total_swaps = 0
    
    for i in range(n - 1):
        swapped = False
        pass_comparisons = 0
        pass_swaps = 0
        
        if show_steps:
            print(f"Pass {i + 1}:")
        
        for j in range(n - i - 1):
            pass_comparisons += 1
            total_comparisons += 1
            
            if show_steps:
                print(f"  Comparing arr[{j}]={arr[j]} with arr[{j+1}]={arr[j+1]}: ", end="")
            
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
                pass_swaps += 1
                total_swaps += 1
                
                if show_steps:
                    print("Swap needed")
            else:
                if show_steps:
                    print("No swap")
        
        if show_steps:
            print(f"  After pass {i + 1}: {arr}")
            print(f"  Pass statistics: {pass_comparisons} comparisons, {pass_swaps} swaps")
        
        # Optimization: If no swapping occurred, array is sorted
        if not swapped:
            if show_steps:
                print(f"  No swaps in this pass - Array is sorted!")
            break
        
        if show_steps:
            print()
    
    if show_steps:
        print("Bubble Sort completed!")
        print(f"Total statistics: {total_comparisons} comparisons, {total_swaps} swaps")
        print(f"Final sorted array: {arr}")
    
    return arr, total_comparisons, total_swaps

def optimized_bubble_sort(arr):
    """Optimized bubble sort with early termination"""
    n = len(arr)
    print(f"\n=== Optimized Bubble Sort ===")
    print(f"Initial array: {arr}")
    
    total_comparisons = 0
    total_swaps = 0
    
    for i in range(n - 1):
        swapped = False
        
        for j in range(n - i - 1):
            total_comparisons += 1
            
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
                total_swaps += 1
        
        if not swapped:
            break
    
    print("Optimized Bubble Sort completed!")
    print(f"Total statistics: {total_comparisons} comparisons, {total_swaps} swaps")
    print(f"Final sorted array: {arr}")
    
    return arr

def performance_analysis():
    """Analyze performance for different array sizes"""
    print(f"\n=== Performance Analysis ===")
    
    sizes = [10, 50, 100, 500]
    
    print("Array Size | Comparisons | Swaps | Time Complexity")
    print("-----------|-------------|-------|----------------")
    
    for size in sizes:
        # Generate worst case (reverse sorted)
        arr = list(range(size, 0, -1))
        
        comparisons = 0
        swaps = 0
        
        # Count operations in bubble sort
        for i in range(size - 1):
            for j in range(size - i - 1):
                comparisons += 1
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
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
    print("=== Bubble Sort Implementation ===")
    print("Bubble Sort: Simple comparison-based sorting algorithm")
    print("Time Complexity: O(n²) average and worst case, O(n) best case")
    print("Space Complexity: O(1) - In-place sorting")
    print("Stability: Stable (maintains relative order of equal elements)\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Sort custom array (step-by-step)")
        print("2. Sort custom array (optimized)")
        print("3. Sort random array")
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
                
                original_arr = arr.copy()
                sorted_arr, comparisons, swaps = bubble_sort(arr, show_steps=True)
                
                print(f"\nVerification: Array is {'correctly sorted' if is_sorted(sorted_arr) else 'NOT sorted'}")
                
            elif choice == 2:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 100:
                    print("Invalid size! Please enter size between 1 and 100.")
                    continue
                
                print(f"Enter {size} elements separated by spaces: ")
                arr = list(map(int, input().split()))
                
                if len(arr) != size:
                    print("Number of elements doesn't match the specified size!")
                    continue
                
                optimized_bubble_sort(arr)
                
            elif choice == 3:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 1000:
                    print("Invalid size! Please enter size between 1 and 1000.")
                    continue
                
                arr = generate_test_array(size, 1)  # Random array
                
                print("Generated random array:")
                print(f"Before sorting: {arr}")
                
                optimized_bubble_sort(arr)
                
            elif choice == 4:
                performance_analysis()
                
            elif choice == 5:
                print(f"\n=== Bubble Sort Algorithm Explanation ===")
                print("How it works:")
                print("1. Compare adjacent elements in the array")
                print("2. If they are in wrong order, swap them")
                print("3. Continue this process for the entire array")
                print("4. After each complete pass, the largest element 'bubbles up' to its correct position")
                print("5. Repeat until no more swaps are needed\n")
                
                print("Characteristics:")
                print("• Simple to understand and implement")
                print("• Stable sorting algorithm")
                print("• In-place sorting (O(1) extra space)")
                print("• Adaptive (performs better on nearly sorted arrays)\n")
                
                print("Time Complexity:")
                print("• Best Case: O(n) - when array is already sorted")
                print("• Average Case: O(n²)")
                print("• Worst Case: O(n²) - when array is reverse sorted\n")
                
                print("When to use:")
                print("• Small datasets")
                print("• Educational purposes")
                print("• When simplicity is more important than efficiency")
                
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
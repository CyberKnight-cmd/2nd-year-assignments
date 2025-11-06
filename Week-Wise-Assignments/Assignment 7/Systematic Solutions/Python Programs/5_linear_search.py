def linear_search(arr, target, show_steps=False):
    """
    Algorithm for Linear Search:
    1. Start from the first element
    2. Compare each element with the target
    3. If match found, return index
    4. If end of array reached without match, return -1
    """
    n = len(arr)
    
    if show_steps:
        print(f"\n=== Linear Search Process ===")
        print(f"Searching for: {target}")
        print(f"Array size: {n}")
        print(f"Array: {arr}")
        print(f"\nStep-by-step search:")
    
    for i in range(n):
        if show_steps:
            print(f"Step {i + 1}: Checking arr[{i}] = {arr[i]}", end="")
        
        if arr[i] == target:
            if show_steps:
                print(" -> FOUND!")
                print(f"Target {target} found at index {i}")
            return i
        
        if show_steps:
            print(" -> Not a match")
    
    if show_steps:
        print(f"Target {target} not found in the array")
    return -1

def linear_search_all(arr, target):
    """Linear search that finds all occurrences"""
    print(f"\n=== Finding All Occurrences ===")
    print(f"Searching for all occurrences of: {target}")
    print(f"Array: {arr}")
    
    positions = []
    print(f"\nSearch process:")
    
    for i in range(len(arr)):
        print(f"Step {i + 1}: Checking arr[{i}] = {arr[i]}", end="")
        
        if arr[i] == target:
            positions.append(i)
            print(f" -> MATCH! (Occurrence #{len(positions)})")
        else:
            print(" -> No match")
    
    if positions:
        print(f"\nFound {len(positions)} occurrence(s) at position(s): {positions}")
    else:
        print(f"\nTarget {target} not found in the array")
    
    return positions

def linear_search_sorted(arr, target):
    """Linear search with early termination for sorted arrays"""
    print(f"\n=== Linear Search on Sorted Array (with early termination) ===")
    print(f"Searching for: {target}")
    print(f"Sorted array: {arr}")
    
    print(f"\nSearch process:")
    
    for i in range(len(arr)):
        print(f"Step {i + 1}: Checking arr[{i}] = {arr[i]}", end="")
        
        if arr[i] == target:
            print(" -> FOUND!")
            print(f"Target {target} found at index {i}")
            return i
        elif arr[i] > target:
            print(" -> Element is larger than target")
            print("Since array is sorted, target cannot exist beyond this point")
            print(f"Early termination: Target {target} not found")
            return -1
        else:
            print(" -> Continue searching")
    
    print(f"Target {target} not found in the array")
    return -1

def sentinel_linear_search(arr, target):
    """Sentinel linear search (optimization)"""
    print(f"\n=== Sentinel Linear Search ===")
    print("Optimization: Add target at end to eliminate bounds checking")
    print(f"Searching for: {target}")
    
    # Store the last element
    last = arr[-1]
    
    # Put target at the end
    arr[-1] = target
    
    print(f"Modified array (target added at end): {arr}")
    print(f"\nSearch process:")
    
    i = 0
    while arr[i] != target:
        print(f"Step {i + 1}: arr[{i}] = {arr[i]} (not target)")
        i += 1
    
    # Restore the last element
    arr[-1] = last
    
    if i < len(arr) - 1 or arr[-1] == target:
        print(f"Step {i + 1}: arr[{i}] = {target} -> FOUND!")
        print(f"Target found at index {i}")
        return i
    else:
        print("Target reached sentinel position - not found in original array")
        return -1

def performance_analysis():
    """Analyze performance for different array sizes"""
    print(f"\n=== Performance Analysis ===")
    
    sizes = [100, 500, 1000, 5000]
    
    print("Linear Search Performance:")
    print("Array Size | Best Case | Average Case | Worst Case")
    print("-----------|-----------|--------------|------------")
    
    for size in sizes:
        # Best case: element at first position
        best_case = 1
        
        # Average case: element at middle position
        avg_case = size // 2
        
        # Worst case: element at last position or not found
        worst_case = size
        
        print(f"{size:10d} | {best_case:9d} | {avg_case:12d} | {worst_case:10d}")
    
    print(f"\nTime Complexity: O(n) in worst case")
    print(f"Space Complexity: O(1)")

def generate_test_array(size, array_type):
    """Generate different types of test arrays"""
    import random
    
    if array_type == 1:  # Random array
        return [random.randint(1, 100) for _ in range(size)]
    elif array_type == 2:  # Sorted array
        return [(i + 1) * 2 for i in range(size)]  # Even numbers
    elif array_type == 3:  # Array with duplicates
        return [random.randint(1, 10) for _ in range(size)]  # Values 1-10
    elif array_type == 4:  # Reverse sorted array
        return [(size - i) * 2 for i in range(size)]
    else:
        return [random.randint(1, 100) for _ in range(size)]

def main():
    """Main function with interactive menu"""
    print("=== Linear Search Implementation ===")
    print("Linear Search: Sequential search through array elements")
    print("Time Complexity: O(n) worst case, O(1) best case")
    print("Space Complexity: O(1)")
    print("Works on: Both sorted and unsorted arrays\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Search in custom array (step-by-step)")
        print("2. Find all occurrences")
        print("3. Search in sorted array (with early termination)")
        print("4. Sentinel linear search")
        print("5. Search in test arrays")
        print("6. Performance analysis")
        print("7. Algorithm explanation")
        print("8. Exit")
        
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
                
                target = int(input("Enter target to search: "))
                
                result = linear_search(arr, target, show_steps=True)
                
                if result != -1:
                    print(f"\nResult: Target {target} found at index {result}")
                else:
                    print(f"\nResult: Target {target} not found in the array")
                    
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
                
                target = int(input("Enter target to search: "))
                
                positions = linear_search_all(arr, target)
                
                if positions:
                    print(f"\nResult: Found {len(positions)} occurrence(s) of {target}")
                else:
                    print(f"\nResult: Target {target} not found")
                    
            elif choice == 3:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 100:
                    print("Invalid size! Please enter size between 1 and 100.")
                    continue
                
                print(f"Enter {size} elements in sorted order separated by spaces: ")
                arr = list(map(int, input().split()))
                
                if len(arr) != size:
                    print("Number of elements doesn't match the specified size!")
                    continue
                
                target = int(input("Enter target to search: "))
                
                result = linear_search_sorted(arr, target)
                
                if result != -1:
                    print(f"\nResult: Target {target} found at index {result}")
                else:
                    print(f"\nResult: Target {target} not found")
                    
            elif choice == 4:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 100:
                    print("Invalid size! Please enter size between 1 and 100.")
                    continue
                
                print(f"Enter {size} elements separated by spaces: ")
                arr = list(map(int, input().split()))
                
                if len(arr) != size:
                    print("Number of elements doesn't match the specified size!")
                    continue
                
                target = int(input("Enter target to search: "))
                
                print(f"Original array: {arr}")
                result = sentinel_linear_search(arr, target)
                print(f"Restored array: {arr}")
                
                if result != -1:
                    print(f"\nResult: Target {target} found at index {result}")
                else:
                    print(f"\nResult: Target {target} not found")
                    
            elif choice == 5:
                size = int(input("Enter array size: "))
                
                if size <= 0 or size > 100:
                    print("Invalid size! Please enter size between 1 and 100.")
                    continue
                
                print("\nSelect array type:")
                print("1. Random array")
                print("2. Sorted array")
                print("3. Array with duplicates")
                print("4. Reverse sorted array")
                
                array_type = int(input("Enter choice: "))
                
                if array_type < 1 or array_type > 4:
                    print("Invalid choice!")
                    continue
                
                arr = generate_test_array(size, array_type)
                
                type_names = ["", "Random", "Sorted", "With Duplicates", "Reverse Sorted"]
                print(f"\nGenerated {type_names[array_type]} Array:")
                print(f"Array: {arr}")
                
                target = int(input("Enter target to search: "))
                
                result = linear_search(arr, target, show_steps=True)
                
                if result != -1:
                    print(f"\nResult: Target {target} found at index {result}")
                else:
                    print(f"\nResult: Target {target} not found")
                    
            elif choice == 6:
                performance_analysis()
                
            elif choice == 7:
                print(f"\n=== Linear Search Algorithm Explanation ===")
                print("How it works:")
                print("1. Start from the first element of the array")
                print("2. Compare each element with the target value")
                print("3. If a match is found, return the index")
                print("4. If the end of array is reached without finding the target, return -1\n")
                
                print("Characteristics:")
                print("• Simple and straightforward algorithm")
                print("• Works on both sorted and unsorted arrays")
                print("• Sequential access pattern")
                print("• No preprocessing required")
                print("• Can find multiple occurrences\n")
                
                print("Time Complexity:")
                print("• Best Case: O(1) - target is at first position")
                print("• Average Case: O(n/2) - target is at middle position")
                print("• Worst Case: O(n) - target is at last position or not found\n")
                
                print("Space Complexity: O(1) - uses constant extra space\n")
                
                print("Optimizations:")
                print("• Sentinel Search: Add target at end to eliminate bounds checking")
                print("• Early Termination: For sorted arrays, stop when element > target")
                print("• Move to Front: Move found element to front for future searches\n")
                
                print("When to use:")
                print("• Small datasets")
                print("• Unsorted arrays")
                print("• When simplicity is important")
                print("• When array is accessed infrequently")
                print("• Finding all occurrences of an element")
                
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
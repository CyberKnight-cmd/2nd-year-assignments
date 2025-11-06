import array

# Create an array with some repeated values
arr = array.array('i', [10, 20, 30, 20, 40, 20, 50])

print("Original array:", arr)

# Get element to remove from user
element = int(input("Enter element to remove (first occurrence): "))

try:
    # Find the index of first occurrence
    index = arr.index(element)
    
    # Remove the first occurrence
    arr.remove(element)
    
    print(f"Removed first occurrence of {element} from index {index}")
    print("Array after removal:", arr)
    print(f"Array length is now: {len(arr)}")
    
    # Check if element still exists
    if element in arr:
        remaining_count = arr.count(element)
        print(f"Note: {remaining_count} more occurrence(s) of {element} still remain in the array")
    else:
        print(f"No more occurrences of {element} in the array")
        
except ValueError:
    print(f"Element {element} not found in the array")
import array

# Create an array with some values
arr = array.array('i', [10, 20, 30, 40, 50, 60])

print("Original array:", arr)
print("Array indices: 0   1   2   3   4   5")

# Get index from user
try:
    index = int(input(f"Enter index to remove (0 to {len(arr)-1}): "))
    
    if 0 <= index < len(arr):
        removed_item = arr[index]
        
        # Remove item at specified index
        arr.pop(index)
        
        print(f"Removed item {removed_item} from index {index}")
        print("Array after removal:", arr)
        print(f"Array length is now: {len(arr)}")
        
        # Show updated indices
        print("\nUpdated array with indices:")
        for i, value in enumerate(arr):
            print(f"Index {i}: {value}")
    else:
        print("Invalid index! Index should be between 0 and", len(arr)-1)
        
except ValueError:
    print("Please enter a valid integer index")
except IndexError:
    print("Index out of range!")
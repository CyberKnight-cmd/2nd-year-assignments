import array

def has_duplicates(arr):
    """
    Check if array contains any duplicate elements.
    Returns True if any value appears at least twice, False if all elements are distinct.
    """
    seen = set()
    for element in arr:
        if element in seen:
            return True
        seen.add(element)
    return False

def has_duplicates_alternative(arr):
    """Alternative method using length comparison"""
    return len(arr) != len(set(arr))

# Test with array containing duplicates
arr1 = array.array('i', [1, 2, 3, 4, 2, 5])
print("Array 1:", arr1)
print("Contains duplicates:", has_duplicates(arr1))
print("Alternative method:", has_duplicates_alternative(arr1))

# Test with array containing no duplicates
arr2 = array.array('i', [1, 2, 3, 4, 5, 6])
print("\nArray 2:", arr2)
print("Contains duplicates:", has_duplicates(arr2))
print("Alternative method:", has_duplicates_alternative(arr2))

# Interactive test
print("\n" + "="*50)
print("Interactive Test:")
size = int(input("Enter array size: "))
arr3 = array.array('i')

print(f"Enter {size} integers:")
for i in range(size):
    value = int(input(f"Element {i+1}: "))
    arr3.append(value)

print("Your array:", arr3)
result = has_duplicates(arr3)
print("Contains duplicates:", result)

if result:
    print("At least one value appears twice or more in the array")
else:
    print("All elements in the array are distinct")
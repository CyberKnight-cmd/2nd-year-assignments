import array

def remove_duplicates_preserve_order(arr):
    """
    Remove all duplicate elements and return a new array.
    Preserves the order of first occurrence.
    """
    seen = set()
    result = array.array(arr.typecode)
    
    for element in arr:
        if element not in seen:
            seen.add(element)
            result.append(element)
    
    return result

def remove_duplicates_using_dict(arr):
    """
    Alternative method using dictionary to preserve order (Python 3.7+)
    """
    return array.array(arr.typecode, dict.fromkeys(arr))

def remove_duplicates_set_method(arr):
    """
    Simple method using set (doesn't preserve order)
    """
    return array.array(arr.typecode, set(arr))

# Test with array containing duplicates
original_array = array.array('i', [1, 2, 3, 2, 4, 1, 5, 3, 6, 4])

print("Original array:", original_array)
print("Original length:", len(original_array))

# Method 1: Preserve order
result1 = remove_duplicates_preserve_order(original_array)
print("\nMethod 1 (preserve order):", result1)
print("New length:", len(result1))

# Method 2: Using dict.fromkeys
result2 = remove_duplicates_using_dict(original_array)
print("\nMethod 2 (using dict):", result2)
print("New length:", len(result2))

# Method 3: Using set (order not preserved)
result3 = remove_duplicates_set_method(original_array)
print("\nMethod 3 (using set):", result3)
print("New length:", len(result3))

# Interactive test
print("\n" + "="*50)
print("Interactive Test:")
size = int(input("Enter array size: "))
user_array = array.array('i')

print(f"Enter {size} integers (duplicates allowed):")
for i in range(size):
    value = int(input(f"Element {i+1}: "))
    user_array.append(value)

print("Your original array:", user_array)
print("Original length:", len(user_array))

# Remove duplicates
unique_array = remove_duplicates_preserve_order(user_array)
print("Array after removing duplicates:", unique_array)
print("New length:", len(unique_array))

# Show which elements were duplicates
duplicates = []
seen = set()
for element in user_array:
    if element in seen and element not in duplicates:
        duplicates.append(element)
    seen.add(element)

if duplicates:
    print("Duplicate elements that were removed:", duplicates)
else:
    print("No duplicates were found in the original array")
import array

# Create an array with some values
arr = array.array('i', [10, 20, 30, 40, 50])

print("Original array:", arr)
print("Array type:", type(arr))

# Method 1: Using tolist() method
list1 = arr.tolist()
print("\nConverted to list using tolist():", list1)
print("List type:", type(list1))

# Method 2: Using list() constructor
list2 = list(arr)
print("\nConverted to list using list():", list2)
print("List type:", type(list2))

# Method 3: Using list comprehension
list3 = [item for item in arr]
print("\nConverted to list using comprehension:", list3)
print("List type:", type(list3))

# Verify all methods produce the same result
print("\nVerification:")
print("All methods produce same result:", list1 == list2 == list3)

# Demonstrate that they are ordinary lists
print("\nDemonstrating list operations:")
list1.append(60)  # This works on lists but not on arrays of fixed type
print("After appending 60 to list:", list1)

# Show difference in flexibility
print("\nFlexibility comparison:")
print("Original array can only contain integers of type 'i'")
try:
    arr.append(3.14)  # This will cause an error
except TypeError as e:
    print("Array error when adding float:", e)

print("List can contain mixed types:")
list1.append(3.14)
list1.append("string")
print("List with mixed types:", list1)
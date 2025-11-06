import array

# Create arrays of different sizes
arr1 = array.array('i', [1, 2, 3, 4, 5])
arr2 = array.array('i', [10, 20, 30, 40, 50, 60, 70, 80, 90, 100])
arr3 = array.array('i')  # Empty array

print("Array 1:", arr1)
print("Length of array 1:", len(arr1))

print("\nArray 2:", arr2)
print("Length of array 2:", len(arr2))

print("\nArray 3 (empty):", arr3)
print("Length of array 3:", len(arr3))

# Interactive example
print("\n" + "="*40)
print("Interactive Example:")
size = int(input("How many elements do you want in your array? "))

user_array = array.array('i')
if size > 0:
    print(f"Enter {size} integers:")
    for i in range(size):
        value = int(input(f"Element {i+1}: "))
        user_array.append(value)

print("Your array:", user_array)
print("Length of your array:", len(user_array))

# Demonstrate length changes with operations
print("\n" + "="*40)
print("Demonstrating length changes:")
demo_array = array.array('i', [1, 2, 3])
print("Initial array:", demo_array)
print("Initial length:", len(demo_array))

# Add element
demo_array.append(4)
print("After appending 4:", demo_array)
print("New length:", len(demo_array))

# Insert element
demo_array.insert(0, 0)
print("After inserting 0 at beginning:", demo_array)
print("New length:", len(demo_array))

# Remove element
demo_array.pop()
print("After removing last element:", demo_array)
print("New length:", len(demo_array))

# Additional information
print("\n" + "="*40)
print("Additional Array Information:")
print(f"Array type code: {demo_array.typecode}")
print(f"Item size in bytes: {demo_array.itemsize}")
print(f"Total memory used: {len(demo_array) * demo_array.itemsize} bytes")
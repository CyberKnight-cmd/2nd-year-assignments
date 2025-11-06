import array

# Create an array containing six integers
arr = array.array('i', [10, 25, 30, 45, 50, 65])

print("Array containing six integers:", arr)

# Print all the members of the array
print("\nAll members of the array:")
for i, value in enumerate(arr):
    print(f"Index {i}: {value}")

# Alternative way to print all members
print("\nAlternative display:")
for value in arr:
    print(value, end=" ")
print()  # New line

# Display array information
print(f"\nArray type: {arr.typecode}")
print(f"Array length: {len(arr)}")
print(f"Array size in bytes: {arr.buffer_info()[1] * arr.itemsize}")
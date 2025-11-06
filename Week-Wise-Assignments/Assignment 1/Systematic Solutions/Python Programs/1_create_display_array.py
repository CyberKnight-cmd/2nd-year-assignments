import array

# Create an array of 5 integers
arr = array.array('i', [10, 20, 30, 40, 50])

# Display the array items
print("Array items:", arr)

# Access individual elements through indexes
print("Individual elements:")
for i in range(len(arr)):
    print(f"Index {i}: {arr[i]}")

# Alternative way to display individual elements
print("\nAlternative access:")
print(f"First element (index 0): {arr[0]}")
print(f"Second element (index 1): {arr[1]}")
print(f"Third element (index 2): {arr[2]}")
print(f"Fourth element (index 3): {arr[3]}")
print(f"Fifth element (index 4): {arr[4]}")
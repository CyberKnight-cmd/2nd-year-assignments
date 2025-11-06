import array

# Create an existing array
arr = array.array('i', [10, 20, 30, 40, 50])

print("Original array:", arr)

# Get new item from user
new_item = int(input("Enter new item to insert before second element: "))

# Insert new item before the second element (index 1)
arr.insert(1, new_item)

print("Array after inserting new item before second element:", arr)

# Display the positions
print("\nArray elements with their positions:")
for i, value in enumerate(arr):
    if i == 0:
        print(f"Index {i}: {value} (first element)")
    elif i == 1:
        print(f"Index {i}: {value} (newly inserted element)")
    elif i == 2:
        print(f"Index {i}: {value} (original second element)")
    else:
        print(f"Index {i}: {value}")

print(f"\nArray length is now: {len(arr)}")
import array

# Create an array with some initial values
arr = array.array('i', [1, 2, 3, 4, 5])

print("Original array:", arr)

# Append a new item to the end of the array
new_item = int(input("Enter a new item to append: "))
arr.append(new_item)

print("Array after appending:", arr)
print(f"New item {new_item} has been added at the end")
print(f"Array length is now: {len(arr)}")
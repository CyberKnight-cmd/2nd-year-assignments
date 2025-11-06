import array

# Create an array with some repeated values
arr = array.array('i', [1, 2, 3, 2, 4, 2, 5, 2])

print("Array:", arr)

# Get the element to count from user
element = int(input("Enter element to count occurrences: "))

# Method 1: Using count() method
count1 = arr.count(element)
print(f"Number of occurrences of {element} (using count()): {count1}")

# Method 2: Manual counting
count2 = 0
for item in arr:
    if item == element:
        count2 += 1

print(f"Number of occurrences of {element} (manual count): {count2}")

# Method 3: Using list comprehension
count3 = sum(1 for item in arr if item == element)
print(f"Number of occurrences of {element} (using comprehension): {count3}")
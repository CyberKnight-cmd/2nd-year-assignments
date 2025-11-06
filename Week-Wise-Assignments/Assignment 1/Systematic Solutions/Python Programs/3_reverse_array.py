import array

# Create an array with some values
arr = array.array('i', [1, 2, 3, 4, 5, 6])

print("Original array:", arr)

# Method 1: Using reverse() method
arr_copy1 = array.array('i', arr)
arr_copy1.reverse()
print("Reversed array (using reverse()):", arr_copy1)

# Method 2: Using slicing
arr_copy2 = array.array('i', arr[::-1])
print("Reversed array (using slicing):", arr_copy2)

# Method 3: Manual reversal
arr_copy3 = array.array('i', arr)
start = 0
end = len(arr_copy3) - 1

while start < end:
    # Swap elements
    temp = arr_copy3[start]
    arr_copy3[start] = arr_copy3[end]
    arr_copy3[end] = temp
    start += 1
    end -= 1

print("Reversed array (manual method):", arr_copy3)
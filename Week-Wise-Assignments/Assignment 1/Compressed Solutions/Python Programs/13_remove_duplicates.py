import array
a = array.array('i', [1, 2, 3, 2, 4, 1, 5, 3, 6, 4])
print("Original:", a)
print("No duplicates:", array.array('i', dict.fromkeys(a)))
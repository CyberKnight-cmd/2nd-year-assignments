import array
a = array.array('i', [1, 2, 3, 4, 2, 5])
print("Array:", a)
print("Has duplicates:", len(a) != len(set(a)))
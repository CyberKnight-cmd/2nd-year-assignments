import array
a = array.array('i', [10, 11, 12, 14, 15, 16, 17, 18, 19, 20])
print("Array:", a)
print("Missing:", list(set(range(10, 21)) - set(a)))
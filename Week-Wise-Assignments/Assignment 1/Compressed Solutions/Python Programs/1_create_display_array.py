import array
a = array.array('i', [10, 20, 30, 40, 50])
print("Array:", a)
[print(f"Index {i}: {a[i]}") for i in range(len(a))]
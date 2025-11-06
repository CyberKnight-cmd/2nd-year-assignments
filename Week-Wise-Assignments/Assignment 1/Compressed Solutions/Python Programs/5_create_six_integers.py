import array
a = array.array('i', [10, 25, 30, 45, 50, 65])
print("Array:", a)
[print(f"Index {i}: {a[i]}") for i in range(len(a))]
import array
a = array.array('i', [10, 20, 30, 40, 50])
print("Original:", a)
a.insert(1, int(input("Enter item: ")))
print("After insert:", a)
import array
a = array.array('i', [1, 2, 3, 4, 5])
print("Original:", a)
a.append(int(input("Enter item: ")))
print("After append:", a)
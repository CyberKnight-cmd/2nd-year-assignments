import array
a = array.array('i', [10, 20, 30, 20, 40, 20, 50])
print("Original:", a)
e = int(input("Enter element: "))
a.remove(e)
print("After removal:", a)
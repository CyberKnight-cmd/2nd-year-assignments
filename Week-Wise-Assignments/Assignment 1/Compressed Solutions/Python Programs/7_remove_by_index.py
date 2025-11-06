import array
a = array.array('i', [10, 20, 30, 40, 50, 60])
print("Original:", a)
i = int(input("Enter index: "))
print(f"Removed: {a.pop(i)}")
print("After removal:", a)
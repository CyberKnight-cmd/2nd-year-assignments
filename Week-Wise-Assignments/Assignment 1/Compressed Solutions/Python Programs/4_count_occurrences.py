import array
a = array.array('i', [1, 2, 3, 2, 4, 2, 5, 2])
e = int(input("Enter element: "))
print(f"Occurrences: {a.count(e)}")
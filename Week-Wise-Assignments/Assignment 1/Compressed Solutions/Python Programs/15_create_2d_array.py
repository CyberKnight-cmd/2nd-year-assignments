import array
a = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
[print(f"Row {i}: {row}") for i, row in enumerate(a)]
[print(f"[{i}][{j}]: {a[i][j]}") for i in range(len(a)) for j in range(len(a[i]))]
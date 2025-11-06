import array
a = array.array('i', [1, 2, 3, 4, 5, 6])
s = sorted(a)
p1, p2 = s[-1] * s[-2], s[0] * s[1]
print("Highest product pair:", (s[-1], s[-2]) if p1 >= p2 else (s[0], s[1]))
print("Product:", max(p1, p2))
class PN:
    def __init__(self, c, e): self.coeff, self.exp, self.next = c, e, None

class Poly:
    def __init__(self): self.head = None
    def insert(self, c, e):
        if not c: return
        n = PN(c, e)
        if not self.head or self.head.exp < e: n.next = self.head; self.head = n; return
        if self.head.exp == e: self.head.coeff += c; return
        t = self.head
        while t.next and t.next.exp > e: t = t.next
        if t.next and t.next.exp == e: t.next.coeff += c
        else: n.next = t.next; t.next = n
    def disp(self): 
        if not self.head: print('0'); return
        t = self.head; terms = []
        while t: terms.append(f"{t.coeff}x^{t.exp}" if t.exp else str(t.coeff)); t = t.next
        print(' + '.join(terms).replace('+ -', '- '))

p = Poly()
while True:
    c = input("1:Insert 2:Display 3:Exit: ")
    if c == '1': p.insert(int(input()), int(input()))
    elif c == '2': p.disp()
    elif c == '3': break
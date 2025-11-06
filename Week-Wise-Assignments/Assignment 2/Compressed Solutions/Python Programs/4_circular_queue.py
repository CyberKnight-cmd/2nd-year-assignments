class CircularQueue:
    def __init__(self, n): self.q, self.f, self.r, self.s, self.c = [None]*n, -1, -1, 0, n
    def enqueue(self, x):
        if self.s < self.c: self.f, self.r = (0, 0) if self.s == 0 else (self.f, (self.r+1)%self.c); self.q[self.r] = x; self.s += 1
    def dequeue(self):
        if self.s > 0: x = self.q[self.f]; self.f, self.r = (-1, -1) if self.s == 1 else ((self.f+1)%self.c, self.r); self.s -= 1; return x
    def display(self): print([self.q[(self.f+i)%self.c] for i in range(self.s)])

cq = CircularQueue(int(input("Capacity: ")))
while True:
    c = input("1:Enqueue 2:Dequeue 3:Display 4:Exit: ")
    if c == '1': cq.enqueue(input("Item: "))
    elif c == '2': print(cq.dequeue())
    elif c == '3': cq.display()
    elif c == '4': break
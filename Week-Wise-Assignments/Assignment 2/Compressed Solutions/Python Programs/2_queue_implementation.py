class Queue:
    def __init__(self): self.items = []
    def enqueue(self, x): self.items.append(x)
    def dequeue(self): return self.items.pop(0) if self.items else None
    def display(self): print(self.items)

q = Queue()
while True:
    c = input("1:Enqueue 2:Dequeue 3:Display 4:Exit: ")
    if c == '1': q.enqueue(input("Item: "))
    elif c == '2': print(q.dequeue())
    elif c == '3': q.display()
    elif c == '4': break
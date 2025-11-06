class Stack:
    def __init__(self): self.items = []
    def push(self, x): self.items.append(x)
    def pop(self): return self.items.pop() if self.items else None
    def peek(self): return self.items[-1] if self.items else None
    def display(self): print(self.items[::-1])

s = Stack()
while True:
    c = input("1:Push 2:Pop 3:Peek 4:Display 5:Exit: ")
    if c == '1': s.push(input("Item: "))
    elif c == '2': print(s.pop())
    elif c == '3': print(s.peek())
    elif c == '4': s.display()
    elif c == '5': break
class Stack:
    def __init__(self):
        self.arr = []
    
    def push(self, x : int):
        self.arr.append(x)
        print(f"{x} appended to Stack")
    
    def pop(self):
        if self.arr:
            return self.arr.pop()
        else:
            print("Empty Stack")
            return None

    def peek(self):
        if self.arr:
            return self.arr[-1]
        else:
            print("Empty Stack")
            return None
    
    def display(self):
        if len(self.arr) != 0:
            print(", ".join([str(x) for x in self.arr]))
        else:
            print("Empty Stack")
    
if __name__ == "__main__": 
    stack = Stack()
    stack.push(20)
    stack.push(30)
    stack.push(40)
    stack.push(50)

    print(stack.pop(), "popped")
    print(stack.pop(), "popped")

    print("Peeking..", stack.peek())
    stack.display()
    stack.pop()
    stack.pop()
    print("Peeking..",stack.peek())
    stack.display()    

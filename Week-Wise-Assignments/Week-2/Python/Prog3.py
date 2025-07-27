class Stack:
    def __init__(self):
        self.arr = []
    
    def push(self, x : chr):
        self.arr.append(x)
        print(f"{x} appended to Stack")
    
    def pop(self):
        if self.arr:
            return self.arr.pop()
        else:
            return None
        
if __name__ == "__main__":
    str = Stack()
    # Pushing
    _ = [str.push(ch) for ch in input("Enter a string : ")]
        
    
    # Popping
    while True:
        x = str.pop()
        if x == None:
            break
        print(x, end='')

    
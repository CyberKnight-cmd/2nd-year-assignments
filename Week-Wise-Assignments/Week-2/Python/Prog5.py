class Queue:
    
    def __init__(self):
        self.arr = []
    
    def enqueue(self, x : str):
        self.arr.append(x)
        print(f"\"{x}\"enqueued to queue.", end =' ')
    
    def display(self):
        if(len(self.arr))!=0:
            print(", ".join([x for x in self.arr]))
        else:
            print("Empty Queue")   

class Stack:
    def __init__(self):
        self.arr = []
        self.removedBoxes = Queue()
    
    def push(self, x : str):
        if x in ["Red", "Blue", "Green"]:
            self.arr.append(x)
            print(f"\"{x}\" appended to Stack")
        else:
            self.removedBoxes.enqueue(x)
            print(f"Not a primary color.")
    
    def display(self):
        if len(self.arr) != 0:
            print(", ".join([str(x) for x in self.arr]))
        else:
            print("Empty Stack")

if __name__ == "__main__":
    boxes = list(input("Enter the colors of the box (ex. Red, Blue, Green, Black)\nNote : Maintain the case sensitivity\n Input : ").split(' '))
    primaryBox = Stack()
    for box in boxes:
        primaryBox.push(box)
    
    primaryBox.display()
    primaryBox.removedBoxes.display()
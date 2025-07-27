class Queue:
    
    def __init__(self):
        self.arr = []
    
    def enqueue(self, x : int):
        self.arr.append(x)
        print(x, "pushed to queue")
    
    def dequeue(self):
        if len(self.arr)!=0:
            return self.arr.pop(0)
        else:
            print("Empty Queue")

    def peek(self):
        if len(self.arr)!=0:
            return self.arr[0]
        else:
            print("Empty Queue")
            return None
    
    def display(self):
        if(len(self.arr))!=0:
            print(",".join([str(x) for x in self.arr]))
        else:
            print("Empty Queue")

if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(10)
    queue.enqueue(20)
    queue.enqueue(30)

    print(queue.dequeue(), "popped")
    print(queue.dequeue(), "popped")
    queue.peek()
    queue.enqueue(19)
    queue.display()
class Queue: 
    
    def __init__(self, capacity):
        self.capacity = capacity
        self.arr = [None]*capacity
        self.front = self.rear = -1
    
    def isEmpty(self):
        return self.front==-1
    
    def isFull(self):
        return (self.rear+1) % self.capacity == self.front
    
    def enqueue(self, x : int):
        if self.isFull():
            print("Queue is full")
            return
        elif self.isEmpty():
            self.front = self.rear = 0
        else:
            self.rear = (self.rear + 1) % self.capacity
        
        self.arr[self.rear] = x
        print(x,"enqueued")

    def dequeue(self):
        if self.isEmpty():
            print("Queue is empty.")
            return None
        x = self.arr[self.front]
        if self.front == self.rear:
            self.front=self.rear=-1
        else:
            self.front = (self.front + 1) % self.capacity
        return x

    def peek(self):
        if self.isEmpty():
            print("Queue is empty.")
            return None
        return self.arr[self.front]
    
    def display(self):
        if self.isEmpty():
            print("Queue is empty")
        else:
            i = self.front
            while True:
                print("-->",self.arr[i], end=' ')
                if i==self.rear:
                    break
                i = (i + 1) % self.capacity
        print()

if __name__ == "__main__":
    q = Queue(5)

    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.enqueue(40)
    q.enqueue(50)  # Should fill the queue
    q.enqueue(60)  # Should print "Queue is full"

    q.display()

    print("Dequeued:", q.dequeue())
    print("Dequeued:", q.dequeue())

    q.display()

    q.enqueue(60)
    q.enqueue(70)  # Queue should be full again

    q.display()

    print("Peeked:", q.peek())

    print("Dequeued:", q.dequeue())
    print("Dequeued:", q.dequeue())
    print("Dequeued:", q.dequeue())
    print("Dequeued:", q.dequeue())  # Should empty the queue
    print("Dequeued:", q.dequeue())  # Should print "Queue is empty"

    q.display()
    print("Peeked:", q.peek())  # Should print "Queue is empty"


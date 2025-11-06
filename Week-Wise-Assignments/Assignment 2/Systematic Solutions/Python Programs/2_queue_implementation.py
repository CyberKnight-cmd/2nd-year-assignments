class Queue:
    """
    Queue implementation using Python list
    """
    
    def __init__(self, capacity=None):
        """
        Initialize queue with optional capacity limit
        """
        self.items = []
        self.capacity = capacity
    
    def is_empty(self):
        """
        Check if queue is empty
        """
        return len(self.items) == 0
    
    def is_full(self):
        """
        Check if queue is full (only if capacity is set)
        """
        if self.capacity is None:
            return False
        return len(self.items) >= self.capacity
    
    def enqueue(self, item):
        """
        Add item to rear of queue
        """
        if self.is_full():
            raise OverflowError("Queue overflow! Cannot enqueue to full queue")
        
        self.items.append(item)
        print(f"Enqueued {item} to queue")
    
    def dequeue(self):
        """
        Remove and return front item from queue
        """
        if self.is_empty():
            raise IndexError("Queue underflow! Cannot dequeue from empty queue")
        
        item = self.items.pop(0)
        print(f"Dequeued {item} from queue")
        return item
    
    def front(self):
        """
        Return front item without removing it
        """
        if self.is_empty():
            raise IndexError("Queue is empty! No front element")
        
        return self.items[0]
    
    def rear(self):
        """
        Return rear item without removing it
        """
        if self.is_empty():
            raise IndexError("Queue is empty! No rear element")
        
        return self.items[-1]
    
    def size(self):
        """
        Return number of items in queue
        """
        return len(self.items)
    
    def display(self):
        """
        Display queue contents
        """
        if self.is_empty():
            print("Queue is empty!")
            return
        
        print("Queue contents (front to rear):", " ".join(map(str, self.items)))
    
    def clear(self):
        """
        Remove all items from queue
        """
        self.items.clear()
        print("Queue cleared")

class EfficientQueue:
    """
    More efficient queue implementation using collections.deque
    """
    
    def __init__(self, capacity=None):
        from collections import deque
        self.items = deque()
        self.capacity = capacity
    
    def is_empty(self):
        return len(self.items) == 0
    
    def is_full(self):
        if self.capacity is None:
            return False
        return len(self.items) >= self.capacity
    
    def enqueue(self, item):
        if self.is_full():
            raise OverflowError("Queue overflow! Cannot enqueue to full queue")
        
        self.items.append(item)
        print(f"Enqueued {item} to queue")
    
    def dequeue(self):
        if self.is_empty():
            raise IndexError("Queue underflow! Cannot dequeue from empty queue")
        
        item = self.items.popleft()
        print(f"Dequeued {item} from queue")
        return item
    
    def front(self):
        if self.is_empty():
            raise IndexError("Queue is empty! No front element")
        return self.items[0]
    
    def rear(self):
        if self.is_empty():
            raise IndexError("Queue is empty! No rear element")
        return self.items[-1]
    
    def size(self):
        return len(self.items)
    
    def display(self):
        if self.is_empty():
            print("Queue is empty!")
            return
        print("Queue contents (front to rear):", " ".join(map(str, self.items)))
    
    def clear(self):
        self.items.clear()
        print("Queue cleared")

def demonstrate_queue():
    """
    Demonstrate queue operations
    """
    print("=== Queue Demonstration ===")
    
    # Create queue with capacity
    queue = Queue(capacity=5)
    
    try:
        # Enqueue some items
        queue.enqueue(10)
        queue.enqueue(20)
        queue.enqueue(30)
        queue.display()
        
        # Check front and rear
        print(f"Front element: {queue.front()}")
        print(f"Rear element: {queue.rear()}")
        print(f"Queue size: {queue.size()}")
        
        # Dequeue items
        queue.dequeue()
        queue.dequeue()
        queue.display()
        
        # Enqueue more items
        queue.enqueue(40)
        queue.enqueue(50)
        queue.enqueue(60)
        queue.enqueue(70)
        queue.display()
        
        # Try to overflow
        try:
            queue.enqueue(80)  # This should cause overflow
        except OverflowError as e:
            print(f"Error: {e}")
        
        # Dequeue all items
        while not queue.is_empty():
            queue.dequeue()
        
        # Try to underflow
        try:
            queue.dequeue()  # This should cause underflow
        except IndexError as e:
            print(f"Error: {e}")
            
    except Exception as e:
        print(f"Unexpected error: {e}")

def compare_implementations():
    """
    Compare different queue implementations
    """
    print("\n=== Comparing Queue Implementations ===")
    
    import time
    
    # Test with large number of operations
    n = 10000
    
    # Test basic queue
    print("Testing basic Queue implementation...")
    queue1 = Queue()
    start_time = time.time()
    
    for i in range(n):
        queue1.enqueue(i)
    
    for i in range(n):
        queue1.dequeue()
    
    basic_time = time.time() - start_time
    print(f"Basic Queue time: {basic_time:.4f} seconds")
    
    # Test efficient queue
    print("Testing efficient Queue implementation...")
    queue2 = EfficientQueue()
    start_time = time.time()
    
    for i in range(n):
        queue2.enqueue(i)
    
    for i in range(n):
        queue2.dequeue()
    
    efficient_time = time.time() - start_time
    print(f"Efficient Queue time: {efficient_time:.4f} seconds")
    
    print(f"Efficiency improvement: {basic_time/efficient_time:.2f}x faster")

def interactive_queue():
    """
    Interactive queue operations
    """
    print("\n=== Interactive Queue Operations ===")
    
    print("Choose queue implementation:")
    print("1. Basic Queue (using list)")
    print("2. Efficient Queue (using deque)")
    
    impl_choice = input("Enter choice (1 or 2): ")
    
    capacity = input("Enter queue capacity (press Enter for unlimited): ")
    
    if impl_choice == "2":
        if capacity.strip():
            queue = EfficientQueue(capacity=int(capacity))
        else:
            queue = EfficientQueue()
    else:
        if capacity.strip():
            queue = Queue(capacity=int(capacity))
        else:
            queue = Queue()
    
    while True:
        print("\n--- Queue Menu ---")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Front")
        print("4. Rear")
        print("5. Display")
        print("6. Size")
        print("7. Clear")
        print("8. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                item = input("Enter item to enqueue: ")
                try:
                    # Try to convert to number if possible
                    if item.isdigit() or (item.startswith('-') and item[1:].isdigit()):
                        item = int(item)
                    elif item.replace('.', '').replace('-', '').isdigit():
                        item = float(item)
                except:
                    pass  # Keep as string
                
                try:
                    queue.enqueue(item)
                except OverflowError as e:
                    print(f"Error: {e}")
            
            elif choice == 2:
                try:
                    queue.dequeue()
                except IndexError as e:
                    print(f"Error: {e}")
            
            elif choice == 3:
                try:
                    print(f"Front element: {queue.front()}")
                except IndexError as e:
                    print(f"Error: {e}")
            
            elif choice == 4:
                try:
                    print(f"Rear element: {queue.rear()}")
                except IndexError as e:
                    print(f"Error: {e}")
            
            elif choice == 5:
                queue.display()
            
            elif choice == 6:
                print(f"Queue size: {queue.size()}")
            
            elif choice == 7:
                queue.clear()
            
            elif choice == 8:
                print("Exiting...")
                break
            
            else:
                print("Invalid choice! Please try again.")
        
        except ValueError:
            print("Please enter a valid number!")
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    # Run demonstration
    demonstrate_queue()
    
    # Compare implementations
    compare_implementations()
    
    # Run interactive mode
    interactive_queue()
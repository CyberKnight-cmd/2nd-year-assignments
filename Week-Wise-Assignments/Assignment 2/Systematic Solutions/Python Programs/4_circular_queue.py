class CircularQueue:
    """
    Circular Queue implementation using array (Python list)
    """
    
    def __init__(self, capacity):
        """
        Initialize circular queue with fixed capacity
        
        Args:
            capacity (int): Maximum number of elements the queue can hold
        """
        self.capacity = capacity
        self.queue = [None] * capacity
        self.front = -1
        self.rear = -1
        self.size = 0
    
    def is_empty(self):
        """
        Check if queue is empty
        
        Returns:
            bool: True if queue is empty, False otherwise
        """
        return self.size == 0
    
    def is_full(self):
        """
        Check if queue is full
        
        Returns:
            bool: True if queue is full, False otherwise
        """
        return self.size == self.capacity
    
    def enqueue(self, item):
        """
        Add item to rear of queue
        
        Args:
            item: Item to add to queue
        
        Raises:
            OverflowError: If queue is full
        """
        if self.is_full():
            raise OverflowError("Circular Queue overflow! Cannot enqueue to full queue")
        
        if self.is_empty():
            self.front = 0
            self.rear = 0
        else:
            self.rear = (self.rear + 1) % self.capacity
        
        self.queue[self.rear] = item
        self.size += 1
        print(f"Enqueued {item} to circular queue")
    
    def dequeue(self):
        """
        Remove and return front item from queue
        
        Returns:
            Item from front of queue
        
        Raises:
            IndexError: If queue is empty
        """
        if self.is_empty():
            raise IndexError("Circular Queue underflow! Cannot dequeue from empty queue")
        
        item = self.queue[self.front]
        self.queue[self.front] = None  # Clear the slot
        
        if self.size == 1:
            self.front = -1
            self.rear = -1
        else:
            self.front = (self.front + 1) % self.capacity
        
        self.size -= 1
        print(f"Dequeued {item} from circular queue")
        return item
    
    def front_item(self):
        """
        Return front item without removing it
        
        Returns:
            Front item of queue
        
        Raises:
            IndexError: If queue is empty
        """
        if self.is_empty():
            raise IndexError("Circular queue is empty! No front element")
        
        return self.queue[self.front]
    
    def rear_item(self):
        """
        Return rear item without removing it
        
        Returns:
            Rear item of queue
        
        Raises:
            IndexError: If queue is empty
        """
        if self.is_empty():
            raise IndexError("Circular queue is empty! No rear element")
        
        return self.queue[self.rear]
    
    def get_size(self):
        """
        Get current size of queue
        
        Returns:
            int: Number of items in queue
        """
        return self.size
    
    def display(self):
        """
        Display queue contents
        """
        if self.is_empty():
            print("Circular queue is empty!")
            return
        
        print("Circular queue contents (front to rear):", end=" ")
        i = self.front
        for count in range(self.size):
            print(self.queue[i], end=" ")
            i = (i + 1) % self.capacity
        print()
    
    def display_with_visualization(self):
        """
        Display queue with array visualization
        """
        print(f"\nCircular Queue Visualization:")
        print(f"Capacity: {self.capacity}, Size: {self.size}")
        print(f"Front: {self.front}, Rear: {self.rear}")
        
        print("Index: ", end="")
        for i in range(self.capacity):
            print(f"{i:2d} ", end="")
        print()
        
        print("Value: ", end="")
        for i in range(self.capacity):
            if self.queue[i] is not None:
                print(f"{self.queue[i]:2} ", end="")
            else:
                print(" - ", end="")
        print()
        
        print("Pos:   ", end="")
        for i in range(self.capacity):
            if i == self.front and i == self.rear and not self.is_empty():
                print("FR ", end="")
            elif i == self.front and not self.is_empty():
                print("F  ", end="")
            elif i == self.rear and not self.is_empty():
                print("R  ", end="")
            else:
                print("   ", end="")
        print()
    
    def clear(self):
        """
        Clear all items from queue
        """
        self.queue = [None] * self.capacity
        self.front = -1
        self.rear = -1
        self.size = 0
        print("Circular queue cleared")

def demonstrate_circular_queue():
    """
    Demonstrate circular queue operations
    """
    print("=== Circular Queue Demonstration ===")
    
    # Create circular queue with capacity 5
    cq = CircularQueue(5)
    
    try:
        print("\n1. Testing basic enqueue operations:")
        cq.enqueue(10)
        cq.enqueue(20)
        cq.enqueue(30)
        cq.display()
        cq.display_with_visualization()
        
        print(f"\nFront item: {cq.front_item()}")
        print(f"Rear item: {cq.rear_item()}")
        print(f"Queue size: {cq.get_size()}")
        
        print("\n2. Testing dequeue operations:")
        cq.dequeue()
        cq.dequeue()
        cq.display()
        cq.display_with_visualization()
        
        print("\n3. Testing circular nature - adding more items:")
        cq.enqueue(40)
        cq.enqueue(50)
        cq.enqueue(60)
        cq.enqueue(70)
        cq.display()
        cq.display_with_visualization()
        
        print("\n4. Testing overflow condition:")
        try:
            cq.enqueue(80)  # This should cause overflow
        except OverflowError as e:
            print(f"Error: {e}")
        
        print("\n5. Testing circular wrap-around:")
        cq.dequeue()  # Remove 30
        cq.dequeue()  # Remove 40
        cq.display_with_visualization()
        
        cq.enqueue(80)  # This should wrap around
        cq.enqueue(90)  # This should also wrap around
        cq.display()
        cq.display_with_visualization()
        
        print("\n6. Emptying the queue:")
        while not cq.is_empty():
            cq.dequeue()
        
        print("\n7. Testing underflow condition:")
        try:
            cq.dequeue()  # This should cause underflow
        except IndexError as e:
            print(f"Error: {e}")
            
    except Exception as e:
        print(f"Unexpected error: {e}")

def interactive_circular_queue():
    """
    Interactive circular queue operations
    """
    print("\n=== Interactive Circular Queue Operations ===")
    
    try:
        capacity = int(input("Enter circular queue capacity: "))
        cq = CircularQueue(capacity)
        
        while True:
            print("\n--- Circular Queue Menu ---")
            print("1. Enqueue")
            print("2. Dequeue")
            print("3. Front")
            print("4. Rear")
            print("5. Display")
            print("6. Display with Visualization")
            print("7. Size")
            print("8. Clear")
            print("9. Exit")
            
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
                        cq.enqueue(item)
                    except OverflowError as e:
                        print(f"Error: {e}")
                
                elif choice == 2:
                    try:
                        cq.dequeue()
                    except IndexError as e:
                        print(f"Error: {e}")
                
                elif choice == 3:
                    try:
                        print(f"Front element: {cq.front_item()}")
                    except IndexError as e:
                        print(f"Error: {e}")
                
                elif choice == 4:
                    try:
                        print(f"Rear element: {cq.rear_item()}")
                    except IndexError as e:
                        print(f"Error: {e}")
                
                elif choice == 5:
                    cq.display()
                
                elif choice == 6:
                    cq.display_with_visualization()
                
                elif choice == 7:
                    print(f"Queue size: {cq.get_size()}")
                
                elif choice == 8:
                    cq.clear()
                
                elif choice == 9:
                    print("Exiting...")
                    break
                
                else:
                    print("Invalid choice! Please try again.")
            
            except ValueError:
                print("Please enter a valid number!")
            except Exception as e:
                print(f"Error: {e}")
    
    except ValueError:
        print("Please enter a valid capacity!")

def test_circular_queue_edge_cases():
    """
    Test edge cases for circular queue
    """
    print("\n=== Testing Circular Queue Edge Cases ===")
    
    # Test with capacity 1
    print("\n1. Testing with capacity 1:")
    cq1 = CircularQueue(1)
    cq1.enqueue("A")
    cq1.display_with_visualization()
    cq1.dequeue()
    cq1.display_with_visualization()
    
    # Test with capacity 2
    print("\n2. Testing with capacity 2:")
    cq2 = CircularQueue(2)
    cq2.enqueue("X")
    cq2.enqueue("Y")
    cq2.display_with_visualization()
    cq2.dequeue()
    cq2.enqueue("Z")
    cq2.display_with_visualization()
    
    # Test multiple wrap-arounds
    print("\n3. Testing multiple wrap-arounds:")
    cq3 = CircularQueue(3)
    
    for i in range(10):
        try:
            if cq3.is_full():
                cq3.dequeue()
            cq3.enqueue(f"Item{i}")
            print(f"After operation {i+1}:")
            cq3.display_with_visualization()
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    # Run demonstration
    demonstrate_circular_queue()
    
    # Test edge cases
    test_circular_queue_edge_cases()
    
    # Run interactive mode
    interactive_circular_queue()
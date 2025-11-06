class Stack:
    """
    Stack implementation using Python list
    """
    
    def __init__(self, capacity=None):
        """
        Initialize stack with optional capacity limit
        """
        self.items = []
        self.capacity = capacity
    
    def is_empty(self):
        """
        Check if stack is empty
        """
        return len(self.items) == 0
    
    def is_full(self):
        """
        Check if stack is full (only if capacity is set)
        """
        if self.capacity is None:
            return False
        return len(self.items) >= self.capacity
    
    def push(self, item):
        """
        Add item to top of stack
        """
        if self.is_full():
            raise OverflowError("Stack overflow! Cannot push to full stack")
        
        self.items.append(item)
        print(f"Pushed {item} to stack")
    
    def pop(self):
        """
        Remove and return top item from stack
        """
        if self.is_empty():
            raise IndexError("Stack underflow! Cannot pop from empty stack")
        
        item = self.items.pop()
        print(f"Popped {item} from stack")
        return item
    
    def peek(self):
        """
        Return top item without removing it
        """
        if self.is_empty():
            raise IndexError("Stack is empty! No top element")
        
        return self.items[-1]
    
    def size(self):
        """
        Return number of items in stack
        """
        return len(self.items)
    
    def display(self):
        """
        Display stack contents
        """
        if self.is_empty():
            print("Stack is empty!")
            return
        
        print("Stack contents (top to bottom):", end=" ")
        for i in range(len(self.items) - 1, -1, -1):
            print(self.items[i], end=" ")
        print()
    
    def clear(self):
        """
        Remove all items from stack
        """
        self.items.clear()
        print("Stack cleared")

def demonstrate_stack():
    """
    Demonstrate stack operations
    """
    print("=== Stack Demonstration ===")
    
    # Create stack with capacity
    stack = Stack(capacity=5)
    
    # Push some items
    try:
        stack.push(10)
        stack.push(20)
        stack.push(30)
        stack.display()
        
        # Peek at top
        print(f"Top element: {stack.peek()}")
        print(f"Stack size: {stack.size()}")
        
        # Pop items
        stack.pop()
        stack.pop()
        stack.display()
        
        # Push more items
        stack.push(40)
        stack.push(50)
        stack.push(60)
        stack.push(70)
        stack.display()
        
        # Try to overflow
        try:
            stack.push(80)  # This should cause overflow
        except OverflowError as e:
            print(f"Error: {e}")
        
        # Pop all items
        while not stack.is_empty():
            stack.pop()
        
        # Try to underflow
        try:
            stack.pop()  # This should cause underflow
        except IndexError as e:
            print(f"Error: {e}")
            
    except Exception as e:
        print(f"Unexpected error: {e}")

def interactive_stack():
    """
    Interactive stack operations
    """
    print("\n=== Interactive Stack Operations ===")
    
    capacity = input("Enter stack capacity (press Enter for unlimited): ")
    if capacity.strip():
        stack = Stack(capacity=int(capacity))
    else:
        stack = Stack()
    
    while True:
        print("\n--- Stack Menu ---")
        print("1. Push")
        print("2. Pop")
        print("3. Peek")
        print("4. Display")
        print("5. Size")
        print("6. Clear")
        print("7. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                item = input("Enter item to push: ")
                try:
                    # Try to convert to number if possible
                    if item.isdigit() or (item.startswith('-') and item[1:].isdigit()):
                        item = int(item)
                    elif item.replace('.', '').replace('-', '').isdigit():
                        item = float(item)
                except:
                    pass  # Keep as string
                
                try:
                    stack.push(item)
                except OverflowError as e:
                    print(f"Error: {e}")
            
            elif choice == 2:
                try:
                    stack.pop()
                except IndexError as e:
                    print(f"Error: {e}")
            
            elif choice == 3:
                try:
                    print(f"Top element: {stack.peek()}")
                except IndexError as e:
                    print(f"Error: {e}")
            
            elif choice == 4:
                stack.display()
            
            elif choice == 5:
                print(f"Stack size: {stack.size()}")
            
            elif choice == 6:
                stack.clear()
            
            elif choice == 7:
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
    demonstrate_stack()
    
    # Run interactive mode
    interactive_stack()
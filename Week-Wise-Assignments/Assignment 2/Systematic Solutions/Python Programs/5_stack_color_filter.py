class Stack:
    """
    Stack implementation for box management
    """
    
    def __init__(self, capacity=None):
        """
        Initialize stack with optional capacity
        """
        self.items = []
        self.capacity = capacity
    
    def is_empty(self):
        """Check if stack is empty"""
        return len(self.items) == 0
    
    def is_full(self):
        """Check if stack is full"""
        if self.capacity is None:
            return False
        return len(self.items) >= self.capacity
    
    def push(self, item):
        """Push item to stack"""
        if self.is_full():
            raise OverflowError("Stack overflow!")
        self.items.append(item)
    
    def pop(self):
        """Pop item from stack"""
        if self.is_empty():
            raise IndexError("Stack underflow!")
        return self.items.pop()
    
    def peek(self):
        """Peek at top item"""
        if self.is_empty():
            raise IndexError("Stack is empty!")
        return self.items[-1]
    
    def size(self):
        """Get stack size"""
        return len(self.items)
    
    def display(self):
        """Display stack contents"""
        if self.is_empty():
            print("Stack is empty!")
        else:
            print("Stack (top to bottom):", " -> ".join(reversed(self.items)))

class Queue:
    """
    Queue implementation for removed boxes
    """
    
    def __init__(self, capacity=None):
        """
        Initialize queue with optional capacity
        """
        self.items = []
        self.capacity = capacity
    
    def is_empty(self):
        """Check if queue is empty"""
        return len(self.items) == 0
    
    def is_full(self):
        """Check if queue is full"""
        if self.capacity is None:
            return False
        return len(self.items) >= self.capacity
    
    def enqueue(self, item):
        """Add item to rear of queue"""
        if self.is_full():
            raise OverflowError("Queue overflow!")
        self.items.append(item)
    
    def dequeue(self):
        """Remove item from front of queue"""
        if self.is_empty():
            raise IndexError("Queue underflow!")
        return self.items.pop(0)
    
    def display(self):
        """Display queue contents"""
        if self.is_empty():
            print("Queue is empty!")
        else:
            print("Queue (front to rear):", " -> ".join(self.items))

def filter_primary_colors(box_stack):
    """
    Filter boxes to keep only primary colors (Red, Green, Blue) in the stack.
    Remove non-primary colored boxes and enqueue them into a new queue.
    
    Args:
        box_stack (Stack): Stack of boxes with different colors
    
    Returns:
        Queue: Queue containing removed boxes (non-primary colors)
    
    Note:
        - Primary colors: "Red", "Green", "Blue" (case sensitive)
        - Original stack order must be maintained for primary colors
        - Queue size equals original stack size
    """
    if box_stack.is_empty():
        return Queue(capacity=0)
    
    # Primary colors (case sensitive as specified)
    primary_colors = {"Red", "Green", "Blue"}
    
    # Create temporary stack to maintain order
    temp_stack = Stack()
    
    # Create queue with same capacity as original stack
    original_size = box_stack.size()
    removed_queue = Queue(capacity=original_size)
    
    print(f"Original stack size: {original_size}")
    print("Primary colors (case sensitive): Red, Green, Blue")
    print("\nProcessing boxes...")
    
    # Step 1: Pop all boxes from original stack and categorize
    primary_boxes = []
    
    while not box_stack.is_empty():
        box = box_stack.pop()
        print(f"Processing box: '{box}'")
        
        if box in primary_colors:
            print(f"  -> '{box}' is a primary color, keeping in stack")
            primary_boxes.append(box)
        else:
            print(f"  -> '{box}' is not a primary color, adding to queue")
            removed_queue.enqueue(box)
    
    # Step 2: Push primary color boxes back to maintain original order
    # Reverse the list to maintain original order when pushing back
    for box in reversed(primary_boxes):
        box_stack.push(box)
    
    print(f"\nFiltering complete!")
    print(f"Primary color boxes remaining in stack: {box_stack.size()}")
    print(f"Non-primary color boxes in queue: {removed_queue.size()}")
    
    return removed_queue

def demonstrate_color_filtering():
    """
    Demonstrate the color filtering functionality
    """
    print("=== Stack Color Filtering Demonstration ===\n")
    
    # Test case 1: Mixed colors
    print("Test Case 1: Mixed colors")
    stack1 = Stack()
    colors1 = ["Yellow", "Red", "Purple", "Green", "Orange", "Blue", "Pink", "Red"]
    
    print("Creating stack with colors:", colors1)
    for color in colors1:
        stack1.push(color)
    
    print("\nBefore filtering:")
    stack1.display()
    
    removed_queue1 = filter_primary_colors(stack1)
    
    print("\nAfter filtering:")
    print("Stack (primary colors only):")
    stack1.display()
    print("Queue (removed non-primary colors):")
    removed_queue1.display()
    
    # Test case 2: Only primary colors
    print("\n" + "="*60)
    print("Test Case 2: Only primary colors")
    stack2 = Stack()
    colors2 = ["Red", "Green", "Blue", "Red", "Green"]
    
    print("Creating stack with colors:", colors2)
    for color in colors2:
        stack2.push(color)
    
    print("\nBefore filtering:")
    stack2.display()
    
    removed_queue2 = filter_primary_colors(stack2)
    
    print("\nAfter filtering:")
    print("Stack (primary colors only):")
    stack2.display()
    print("Queue (removed non-primary colors):")
    removed_queue2.display()
    
    # Test case 3: No primary colors
    print("\n" + "="*60)
    print("Test Case 3: No primary colors")
    stack3 = Stack()
    colors3 = ["Yellow", "Purple", "Orange", "Pink", "Brown"]
    
    print("Creating stack with colors:", colors3)
    for color in colors3:
        stack3.push(color)
    
    print("\nBefore filtering:")
    stack3.display()
    
    removed_queue3 = filter_primary_colors(stack3)
    
    print("\nAfter filtering:")
    print("Stack (primary colors only):")
    stack3.display()
    print("Queue (removed non-primary colors):")
    removed_queue3.display()
    
    # Test case 4: Case sensitivity test
    print("\n" + "="*60)
    print("Test Case 4: Case sensitivity test")
    stack4 = Stack()
    colors4 = ["red", "RED", "Red", "green", "GREEN", "Green", "blue", "BLUE", "Blue"]
    
    print("Creating stack with colors:", colors4)
    for color in colors4:
        stack4.push(color)
    
    print("\nBefore filtering:")
    stack4.display()
    
    removed_queue4 = filter_primary_colors(stack4)
    
    print("\nAfter filtering:")
    print("Stack (primary colors only):")
    stack4.display()
    print("Queue (removed non-primary colors):")
    removed_queue4.display()

def interactive_color_filtering():
    """
    Interactive color filtering
    """
    print("\n=== Interactive Color Filtering ===")
    
    stack = Stack()
    
    print("Enter box colors (press Enter on empty line to finish):")
    print("Note: Primary colors are 'Red', 'Green', 'Blue' (case sensitive)")
    
    box_count = 1
    while True:
        color = input(f"Box {box_count} color: ").strip()
        if not color:
            break
        stack.push(color)
        box_count += 1
    
    if stack.is_empty():
        print("No boxes entered!")
        return
    
    print(f"\nCreated stack with {stack.size()} boxes")
    print("Original stack:")
    stack.display()
    
    # Create a copy for demonstration
    original_colors = stack.items.copy()
    
    # Filter colors
    removed_queue = filter_primary_colors(stack)
    
    print("\nResults:")
    print("Final stack (primary colors only):")
    stack.display()
    print("Queue (removed non-primary colors):")
    removed_queue.display()
    
    # Summary
    print(f"\nSummary:")
    print(f"Original boxes: {len(original_colors)}")
    print(f"Primary color boxes kept: {stack.size()}")
    print(f"Non-primary color boxes removed: {removed_queue.size()}")
    
    # Show categorization
    primary_colors = {"Red", "Green", "Blue"}
    print(f"\nColor categorization:")
    for color in original_colors:
        category = "Primary" if color in primary_colors else "Non-primary"
        print(f"  '{color}' -> {category}")

def test_edge_cases():
    """
    Test edge cases for color filtering
    """
    print("\n=== Testing Edge Cases ===")
    
    # Test case 1: Empty stack
    print("\n1. Empty stack:")
    empty_stack = Stack()
    removed_queue = filter_primary_colors(empty_stack)
    print("Empty stack result:")
    empty_stack.display()
    removed_queue.display()
    
    # Test case 2: Single box (primary)
    print("\n2. Single primary color box:")
    single_stack1 = Stack()
    single_stack1.push("Red")
    print("Before filtering:")
    single_stack1.display()
    removed_queue1 = filter_primary_colors(single_stack1)
    print("After filtering:")
    single_stack1.display()
    removed_queue1.display()
    
    # Test case 3: Single box (non-primary)
    print("\n3. Single non-primary color box:")
    single_stack2 = Stack()
    single_stack2.push("Yellow")
    print("Before filtering:")
    single_stack2.display()
    removed_queue2 = filter_primary_colors(single_stack2)
    print("After filtering:")
    single_stack2.display()
    removed_queue2.display()

if __name__ == "__main__":
    # Run demonstration
    demonstrate_color_filtering()
    
    # Test edge cases
    test_edge_cases()
    
    # Run interactive mode
    interactive_color_filtering()
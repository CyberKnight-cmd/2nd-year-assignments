class Stack:
    """
    Stack implementation using array (Python list) for string reversal
    """
    
    def __init__(self, capacity=None):
        """
        Initialize stack with optional capacity
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
        Check if stack is full
        """
        if self.capacity is None:
            return False
        return len(self.items) >= self.capacity
    
    def push(self, item):
        """
        Push item to stack
        """
        if self.is_full():
            raise OverflowError("Stack overflow!")
        self.items.append(item)
    
    def pop(self):
        """
        Pop item from stack
        """
        if self.is_empty():
            raise IndexError("Stack underflow!")
        return self.items.pop()
    
    def peek(self):
        """
        Peek at top item
        """
        if self.is_empty():
            raise IndexError("Stack is empty!")
        return self.items[-1]
    
    def size(self):
        """
        Get stack size
        """
        return len(self.items)
    
    def display(self):
        """
        Display stack contents
        """
        print("Stack:", self.items)

def reverse_string_using_stack(text):
    """
    Reverse a string using stack data structure
    
    Args:
        text (str): Input string to reverse
    
    Returns:
        str: Reversed string
    """
    if not text:
        return text
    
    # Create stack with capacity equal to string length
    stack = Stack(capacity=len(text))
    
    print(f"Original string: '{text}'")
    print("Pushing characters to stack...")
    
    # Push all characters to stack
    for i, char in enumerate(text):
        stack.push(char)
        print(f"  Step {i+1}: Pushed '{char}' -> Stack: {stack.items}")
    
    print("\nPopping characters from stack...")
    
    # Pop all characters to create reversed string
    reversed_string = ""
    step = 1
    while not stack.is_empty():
        char = stack.pop()
        reversed_string += char
        print(f"  Step {step}: Popped '{char}' -> Reversed so far: '{reversed_string}'")
        step += 1
    
    print(f"\nReversed string: '{reversed_string}'")
    return reversed_string

def reverse_string_efficient(text):
    """
    Efficient string reversal using stack (without step-by-step display)
    
    Args:
        text (str): Input string to reverse
    
    Returns:
        str: Reversed string
    """
    if not text:
        return text
    
    stack = Stack()
    
    # Push all characters
    for char in text:
        stack.push(char)
    
    # Pop all characters
    reversed_string = ""
    while not stack.is_empty():
        reversed_string += stack.pop()
    
    return reversed_string

def reverse_multiple_strings(strings):
    """
    Reverse multiple strings using stack
    
    Args:
        strings (list): List of strings to reverse
    
    Returns:
        list: List of reversed strings
    """
    reversed_strings = []
    
    for i, string in enumerate(strings):
        print(f"\n--- Reversing String {i+1}: '{string}' ---")
        reversed_str = reverse_string_efficient(string)
        reversed_strings.append(reversed_str)
        print(f"Result: '{reversed_str}'")
    
    return reversed_strings

def demonstrate_string_reversal():
    """
    Demonstrate string reversal using stack
    """
    print("=== String Reversal Using Stack (Array) ===\n")
    
    # Test cases
    test_strings = [
        "hello",
        "world",
        "Python",
        "Stack",
        "12345",
        "a",
        "",
        "racecar",
        "Hello World!",
        "Programming is fun"
    ]
    
    print("Testing with predefined strings:\n")
    
    for test_string in test_strings:
        print(f"Input: '{test_string}'")
        reversed_str = reverse_string_efficient(test_string)
        print(f"Output: '{reversed_str}'")
        print("-" * 40)

def interactive_string_reversal():
    """
    Interactive string reversal
    """
    print("\n=== Interactive String Reversal ===")
    
    while True:
        print("\n--- String Reversal Menu ---")
        print("1. Reverse single string (with steps)")
        print("2. Reverse single string (efficient)")
        print("3. Reverse multiple strings")
        print("4. Compare with built-in reversal")
        print("5. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                text = input("Enter string to reverse: ")
                reverse_string_using_stack(text)
            
            elif choice == 2:
                text = input("Enter string to reverse: ")
                reversed_text = reverse_string_efficient(text)
                print(f"Original: '{text}'")
                print(f"Reversed: '{reversed_text}'")
            
            elif choice == 3:
                print("Enter strings (press Enter on empty line to finish):")
                strings = []
                while True:
                    string = input(f"String {len(strings)+1}: ")
                    if not string:
                        break
                    strings.append(string)
                
                if strings:
                    reversed_strings = reverse_multiple_strings(strings)
                    print("\nSummary:")
                    for orig, rev in zip(strings, reversed_strings):
                        print(f"'{orig}' -> '{rev}'")
                else:
                    print("No strings entered.")
            
            elif choice == 4:
                text = input("Enter string to reverse: ")
                
                # Using stack
                stack_reversed = reverse_string_efficient(text)
                
                # Using built-in slicing
                builtin_reversed = text[::-1]
                
                print(f"Original string: '{text}'")
                print(f"Stack reversal: '{stack_reversed}'")
                print(f"Built-in reversal: '{builtin_reversed}'")
                print(f"Results match: {stack_reversed == builtin_reversed}")
            
            elif choice == 5:
                print("Exiting...")
                break
            
            else:
                print("Invalid choice! Please try again.")
        
        except ValueError:
            print("Please enter a valid number!")
        except Exception as e:
            print(f"Error: {e}")

def performance_comparison():
    """
    Compare performance of stack-based reversal vs built-in methods
    """
    print("\n=== Performance Comparison ===")
    
    import time
    
    # Test with different string sizes
    test_sizes = [100, 1000, 10000]
    
    for size in test_sizes:
        test_string = "a" * size
        
        print(f"\nTesting with string of length {size}:")
        
        # Stack-based reversal
        start_time = time.time()
        stack_result = reverse_string_efficient(test_string)
        stack_time = time.time() - start_time
        
        # Built-in reversal
        start_time = time.time()
        builtin_result = test_string[::-1]
        builtin_time = time.time() - start_time
        
        print(f"Stack method: {stack_time:.6f} seconds")
        print(f"Built-in method: {builtin_time:.6f} seconds")
        print(f"Built-in is {stack_time/builtin_time:.2f}x faster")
        print(f"Results match: {stack_result == builtin_result}")

if __name__ == "__main__":
    # Run demonstration
    demonstrate_string_reversal()
    
    # Run interactive mode
    interactive_string_reversal()
    
    # Performance comparison
    performance_comparison()
class Stack:
    """Stack implementation for string operations"""
    def __init__(self):
        self.items = []
    
    def is_empty(self):
        return len(self.items) == 0
    
    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        if self.is_empty():
            return None
        return self.items.pop()
    
    def peek(self):
        if self.is_empty():
            return None
        return self.items[-1]
    
    def size(self):
        return len(self.items)
    
    def display(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            display_items = []
            for item in reversed(self.items):
                if item == ' ':
                    display_items.append('[SPACE]')
                else:
                    display_items.append(f"'{item}'")
            print(f"Stack contents (top to bottom): {' '.join(display_items)}")

def reverse_string(original):
    """
    Algorithm for String Reversal using Stack:
    1. Push all characters of the string onto the stack
    2. Pop all characters from the stack to get reversed string
    3. LIFO property of stack naturally reverses the order
    """
    stack = Stack()
    length = len(original)
    
    print(f"\n=== String Reversal using Stack ===")
    print(f"Original string: \"{original}\"")
    print(f"String length: {length}")
    print("Algorithm: Push all characters, then pop to get reverse\n")
    
    # Phase 1: Push all characters onto stack
    print("Phase 1: Pushing characters onto stack")
    for i, char in enumerate(original):
        stack.push(char)
        print(f"Step {i + 1}: Pushed '{char}'")
        
        if length <= 10:  # Show stack state for short strings
            print("         ", end="")
            stack.display()
        print()
    
    print("All characters pushed to stack.")
    if length <= 20:
        stack.display()
    
    # Phase 2: Pop all characters to create reversed string
    print(f"\nPhase 2: Popping characters to create reversed string")
    reversed_string = ""
    index = 0
    
    while not stack.is_empty():
        char = stack.pop()
        reversed_string += char
        print(f"Step {index + 1}: Popped '{char}' -> reversed[{index}] = '{char}'")
        
        if length <= 10:  # Show remaining stack for short strings
            print("         Remaining stack: ", end="")
            stack.display()
        
        index += 1
        print()
    
    print("String reversal completed!")
    print(f"Reversed string: \"{reversed_string}\"")
    return reversed_string

def reverse_words(original):
    """Reverse only words in a string (keep word order, reverse each word)"""
    stack = Stack()
    result = ""
    
    print(f"\n=== Reverse Words using Stack ===")
    print(f"Original: \"{original}\"")
    print("Algorithm: Reverse each word individually using stack\n")
    
    i = 0
    while i <= len(original):
        if i < len(original) and original[i] != ' ':
            # Push character to stack
            stack.push(original[i])
            print(f"Pushed '{original[i]}' to stack")
        else:
            # End of word or string, pop all characters
            if not stack.is_empty():
                print("End of word reached, popping characters:")
                while not stack.is_empty():
                    char = stack.pop()
                    result += char
                    print(f"Popped '{char}'")
            
            # Add space if not end of string
            if i < len(original) and original[i] == ' ':
                result += ' '
                print("Added space")
            print()
        i += 1
    
    print(f"Result: \"{result}\"")
    return result

def is_palindrome(string):
    """Check if string is palindrome using stack"""
    stack = Stack()
    length = len(string)
    
    print(f"\n=== Palindrome Check using Stack ===")
    print(f"String: \"{string}\"")
    print("Algorithm: Push first half, compare with second half\n")
    
    # Push first half of string
    mid = length // 2
    print(f"Pushing first half ({mid} characters):")
    for i in range(mid):
        stack.push(string[i])
        print(f"Pushed '{string[i]}'")
    
    # Start comparing from middle (skip middle character for odd length)
    start = mid + 1 if length % 2 == 1 else mid
    print(f"\nComparing with second half (starting from index {start}):")
    
    for i in range(start, length):
        if stack.is_empty():
            print("Stack empty but string continues - Not palindrome")
            return False
        
        stack_char = stack.pop()
        print(f"Comparing '{stack_char}' (from stack) with '{string[i]}' (from string)")
        
        if stack_char != string[i]:
            print("Mismatch found - Not palindrome")
            return False
    
    if not stack.is_empty():
        print("Stack not empty - Not palindrome")
        return False
    
    print("All characters matched - Is palindrome!")
    return True

def preprocess_string(original):
    """Remove spaces and convert to lowercase for better palindrome checking"""
    processed = ""
    for char in original:
        if char != ' ':
            processed += char.lower()
    return processed

def main():
    """Main function with interactive menu"""
    print("=== String Reversal using Stack ===")
    print("This program demonstrates various string operations using stack")
    print("Stack's LIFO property naturally reverses the order of elements\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Reverse entire string")
        print("2. Reverse words in string")
        print("3. Check if string is palindrome")
        print("4. Demonstrate with sample strings")
        print("5. Show algorithm explanation")
        print("6. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                original = input("Enter a string to reverse: ")
                
                if len(original) == 0:
                    print("Empty string!")
                    continue
                
                reverse_string(original)
                
            elif choice == 2:
                original = input("Enter a string to reverse words: ")
                
                if len(original) == 0:
                    print("Empty string!")
                    continue
                
                reverse_words(original)
                
            elif choice == 3:
                original = input("Enter a string to check palindrome: ")
                
                if len(original) == 0:
                    print("Empty string!")
                    continue
                
                # Check with original string
                result1 = is_palindrome(original)
                
                # Check with preprocessed string (no spaces, lowercase)
                processed = preprocess_string(original)
                print(f"\nChecking preprocessed string (no spaces, lowercase): \"{processed}\"")
                result2 = is_palindrome(processed)
                
                print(f"\nResults:")
                print(f"Original string: {'Palindrome' if result1 else 'Not palindrome'}")
                print(f"Preprocessed string: {'Palindrome' if result2 else 'Not palindrome'}")
                
            elif choice == 4:
                print(f"\n=== Sample Demonstrations ===")
                
                samples = [
                    "hello",
                    "racecar",
                    "A man a plan a canal Panama",
                    "hello world",
                    "12321"
                ]
                
                for i, sample in enumerate(samples):
                    print(f"\n--- Sample {i + 1} ---")
                    reverse_string(sample)
                    
                    # Also check if palindrome
                    processed = preprocess_string(sample)
                    is_palin = is_palindrome(processed)
                    print(f"Is palindrome (preprocessed): {'Yes' if is_palin else 'No'}")
                    
            elif choice == 5:
                print(f"\n=== Algorithm Explanation ===")
                print("String Reversal using Stack:")
                print("1. Push all characters of string onto stack (LIFO)")
                print("2. Pop all characters from stack to get reversed order")
                print("3. Time Complexity: O(n), Space Complexity: O(n)\n")
                
                print("Why Stack Works for Reversal:")
                print("- Last In, First Out (LIFO) property")
                print("- First character pushed becomes last character popped")
                print("- Natural reversal without additional logic\n")
                
                print("Applications:")
                print("- Undo operations in text editors")
                print("- Expression evaluation (postfix)")
                print("- Palindrome checking")
                print("- Backtracking algorithms")
                
            elif choice == 6:
                print("Exiting program...")
                break
                
            else:
                print("Invalid choice! Please try again.")
                
        except ValueError:
            print("Invalid input! Please enter a valid number.")
        except Exception as e:
            print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
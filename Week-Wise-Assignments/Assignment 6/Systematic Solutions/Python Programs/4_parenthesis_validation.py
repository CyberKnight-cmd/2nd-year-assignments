class Stack:
    """Stack implementation for parenthesis validation"""
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
            return "Empty"
        else:
            return f"Bottom -> {' '.join([f\"'{item}'\" for item in self.items])} <- Top"

def is_opening_bracket(char):
    """Check if character is opening bracket"""
    return char in '([{'

def is_closing_bracket(char):
    """Check if character is closing bracket"""
    return char in ')]}'

def get_matching_opening(closing):
    """Get matching opening bracket for a closing bracket"""
    matching = {')': '(', ']': '[', '}': '{'}
    return matching.get(closing)

def get_matching_closing(opening):
    """Get matching closing bracket for an opening bracket"""
    matching = {'(': ')', '[': ']', '{': '}'}
    return matching.get(opening)

def validate_parentheses(expression):
    """
    Algorithm for Parenthesis Validation:
    1. Scan expression from left to right
    2. If opening bracket, push to stack
    3. If closing bracket, check if it matches top of stack
    4. If matches, pop from stack; if not, expression is invalid
    5. At end, stack should be empty for valid expression
    """
    stack = Stack()
    length = len(expression)
    
    print(f"\n=== Parenthesis Validation Process ===")
    print(f"Expression: {expression}")
    print("Algorithm: Use stack to match opening and closing brackets\n")
    
    print("Step-by-step validation:")
    
    for i, char in enumerate(expression):
        print(f"Step {i + 1}: Processing '{char}' at position {i}")
        
        if is_opening_bracket(char):
            stack.push(char)
            print("         Opening bracket found, pushed to stack")
        elif is_closing_bracket(char):
            print("         Closing bracket found")
            
            if stack.is_empty():
                print("         ERROR: No matching opening bracket (stack is empty)")
                print("         Expression is INVALID")
                return False
            
            top = stack.peek()
            expected = get_matching_opening(char)
            
            print(f"         Top of stack: '{top}', Expected: '{expected}'")
            
            if top == expected:
                stack.pop()
                print(f"         Match found! Popped '{top}' from stack")
            else:
                print(f"         ERROR: Mismatch! Found '{top}' but expected '{expected}'")
                print("         Expression is INVALID")
                return False
        else:
            print("         Non-bracket character, ignoring")
        
        print(f"         Stack status: {stack.display()}")
        print()
    
    # Check if stack is empty at the end
    if stack.is_empty():
        print("Final check: Stack is empty - Expression is VALID")
        return True
    else:
        print("Final check: Stack is not empty - Expression is INVALID")
        print(f"Unmatched opening brackets: {stack.display()}")
        return False

def detailed_validation(expression):
    """Find and report all bracket errors"""
    stack = Stack()
    length = len(expression)
    error_count = 0
    
    print(f"\n=== Detailed Error Analysis ===")
    print(f"Expression: {expression}")
    
    # Track positions for better error reporting
    positions = []
    
    for i, char in enumerate(expression):
        if is_opening_bracket(char):
            stack.push(char)
            positions.append(i)
        elif is_closing_bracket(char):
            if stack.is_empty():
                error_count += 1
                print(f"Error {error_count}: Unmatched closing '{char}' at position {i}")
            else:
                top = stack.peek()
                expected = get_matching_opening(char)
                
                if top == expected:
                    stack.pop()
                    positions.pop()
                else:
                    error_count += 1
                    pos = positions.pop() if positions else -1
                    print(f"Error {error_count}: Mismatched brackets - '{char}' at position {i} doesn't match '{top}' at position {pos}")
                    stack.pop()
    
    # Report unmatched opening brackets
    while not stack.is_empty():
        unmatched = stack.pop()
        pos = positions.pop() if positions else -1
        error_count += 1
        print(f"Error {error_count}: Unmatched opening '{unmatched}' at position {pos}")
    
    if error_count == 0:
        print("No errors found - Expression is valid!")
    else:
        print(f"Total errors found: {error_count}")

def suggest_fixes(expression):
    """Generate suggestions for fixing bracket errors"""
    print(f"\n=== Fix Suggestions ===")
    
    # Count different types of brackets
    open_count = {'(': 0, '[': 0, '{': 0}
    close_count = {')': 0, ']': 0, '}': 0}
    
    for char in expression:
        if char in open_count:
            open_count[char] += 1
        elif char in close_count:
            close_count[char] += 1
    
    brackets = [('(', ')'), ('[', ']'), ('{', '}')]
    
    for opening, closing in brackets:
        open_cnt = open_count[opening]
        close_cnt = close_count[closing]
        
        if open_cnt != close_cnt:
            if open_cnt > close_cnt:
                print(f"Add {open_cnt - close_cnt} closing '{closing}' bracket(s)")
            else:
                print(f"Remove {close_cnt - open_cnt} closing '{closing}' bracket(s) or add {close_cnt - open_cnt} opening '{opening}' bracket(s)")

def main():
    """Main function with interactive menu"""
    print("=== Parenthesis Validation using Stack ===")
    print("This program validates balanced parentheses, brackets, and braces")
    print("Supported brackets: (), [], {}")
    print("Stack is used to match opening and closing brackets\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Validate expression")
        print("2. Detailed error analysis")
        print("3. Test with sample expressions")
        print("4. Show algorithm explanation")
        print("5. Generate fix suggestions")
        print("6. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                expression = input("Enter expression to validate: ")
                
                if len(expression) == 0:
                    print("Empty expression is considered valid!")
                    continue
                
                is_valid = validate_parentheses(expression)
                print(f"\nResult: Expression is {'VALID' if is_valid else 'INVALID'}")
                
            elif choice == 2:
                expression = input("Enter expression for detailed analysis: ")
                
                if len(expression) == 0:
                    print("Empty expression!")
                    continue
                
                detailed_validation(expression)
                
            elif choice == 3:
                print(f"\n=== Sample Expression Tests ===")
                
                samples = [
                    "()",
                    "()[]{}",
                    "([{}])",
                    "((()))",
                    "([)]",
                    "(((",
                    ")))",
                    "{[}]",
                    "a(b[c{d}e]f)g",
                    "if(x>0){print(\"positive\");}"
                ]
                
                for i, sample in enumerate(samples):
                    print(f"\n--- Sample {i + 1} ---")
                    result = validate_parentheses(sample)
                    print(f"Result: {'VALID' if result else 'INVALID'}")
                    
            elif choice == 4:
                print(f"\n=== Algorithm Explanation ===")
                print("Parenthesis Validation Algorithm:")
                print("1. Initialize empty stack")
                print("2. Scan expression from left to right:")
                print("   - If opening bracket: push to stack")
                print("   - If closing bracket: check if matches top of stack")
                print("     * If matches: pop from stack")
                print("     * If doesn't match or stack empty: invalid")
                print("3. After scanning: stack should be empty for valid expression\n")
                
                print("Time Complexity: O(n) - single pass through expression")
                print("Space Complexity: O(n) - worst case all opening brackets\n")
                
                print("Why Stack Works:")
                print("- LIFO property matches bracket nesting structure")
                print("- Most recent opening bracket should match first closing bracket")
                print("- Natural handling of nested structures")
                
            elif choice == 5:
                expression = input("Enter expression for fix suggestions: ")
                
                if len(expression) == 0:
                    print("Empty expression!")
                    continue
                
                suggest_fixes(expression)
                
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
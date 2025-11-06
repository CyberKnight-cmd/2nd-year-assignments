class Stack:
    """Stack implementation for factorial calculation"""
    def __init__(self):
        self.items = []
    
    def is_empty(self):
        return len(self.items) == 0
    
    def push(self, item):
        self.items.append(item)
        print(f"Pushed {item} to stack")
    
    def pop(self):
        if self.is_empty():
            print("Stack underflow!")
            return None
        item = self.items.pop()
        print(f"Popped {item} from stack")
        return item
    
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
            print(f"Stack contents (top to bottom): {self.items[::-1]}")

def factorial_using_stack(n):
    """
    Algorithm for Factorial using Stack:
    1. Push all numbers from n down to 1 onto stack
    2. Pop numbers one by one and multiply to get factorial
    3. This simulates the recursive nature of factorial calculation
    """
    if n < 0:
        print("Factorial is not defined for negative numbers!")
        return None
    
    if n == 0 or n == 1:
        print(f"Factorial of {n} is 1 (base case)")
        return 1
    
    stack = Stack()
    
    print(f"\n=== Factorial Calculation using Stack ===")
    print(f"Calculating factorial of {n}")
    print("Algorithm: Push numbers n to 1, then pop and multiply\n")
    
    # Phase 1: Push numbers from n down to 1
    print(f"Phase 1: Pushing numbers from {n} down to 1")
    for i in range(n, 0, -1):
        stack.push(i)
    
    print(f"\nStack after pushing all numbers:")
    stack.display()
    
    # Phase 2: Pop numbers and calculate factorial
    print(f"\nPhase 2: Popping numbers and calculating factorial")
    factorial = 1
    step = 1
    
    while not stack.is_empty():
        num = stack.pop()
        factorial *= num
        print(f"Step {step}: factorial = factorial * {num} = {factorial}")
        
        if not stack.is_empty():
            print(f"Remaining stack: {stack.items[::-1]}")
        step += 1
        print()
    
    return factorial

def factorial_iterative(n):
    """Iterative factorial for comparison"""
    if n < 0:
        return None
    if n == 0 or n == 1:
        return 1
    
    factorial = 1
    print(f"\nIterative calculation for comparison:")
    for i in range(1, n + 1):
        factorial *= i
        print(f"{i}! (up to {i}) = {factorial}")
    return factorial

def factorial_recursive(n):
    """Recursive factorial for comparison"""
    if n < 0:
        return None
    if n == 0 or n == 1:
        return 1
    return n * factorial_recursive(n - 1)

def demonstrate_stack_approach(n):
    """Demonstrate why stack works for factorial"""
    print(f"\n=== Demonstration: Why Stack Works for Factorial ===")
    print(f"Factorial definition: n! = n * (n-1) * (n-2) * ... * 2 * 1")
    print(f"For {n}!: {n}", end="")
    for i in range(n-1, 0, -1):
        print(f" * {i}", end="")
    print("\n")
    
    print("Stack approach mimics the recursive nature:")
    print(f"1. Push all numbers from {n} to 1 (like recursive calls)")
    print("2. Pop and multiply (like returning from recursive calls)")
    print("3. LIFO property ensures correct multiplication order\n")
    
    print("Stack visualization:")
    print("Push phase:     Pop phase:")
    for i in range(1, n + 1):
        print(f"Push {n - i + 1:2d}          Pop {i:2d} (multiply)")

def main():
    """Main function with interactive menu"""
    print("=== Factorial Calculation using Stack ===")
    print("This program calculates factorial using stack data structure")
    print("Stack simulates the recursive nature of factorial calculation\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Calculate factorial using stack")
        print("2. Compare with iterative method")
        print("3. Compare with recursive method")
        print("4. Demonstrate stack approach")
        print("5. Show factorial table")
        print("6. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                number = int(input("Enter a number to calculate factorial: "))
                
                if number > 20:
                    print("Warning: Large numbers may cause overflow!")
                    cont = input("Continue? (y/n): ").lower()
                    if cont != 'y':
                        continue
                
                result = factorial_using_stack(number)
                if result is not None:
                    print(f"\nFinal Result: {number}! = {result}")
                    
            elif choice == 2:
                number = int(input("Enter a number to compare methods: "))
                
                print(f"\n=== Method Comparison ===")
                result = factorial_using_stack(number)
                if result is not None:
                    print(f"Stack method result: {result}")
                
                iter_result = factorial_iterative(number)
                if iter_result is not None:
                    print(f"Iterative method result: {iter_result}")
                
                if result == iter_result and result is not None:
                    print("✓ Both methods give the same result!")
                    
            elif choice == 3:
                number = int(input("Enter a number to compare with recursive method: "))
                
                result = factorial_using_stack(number)
                rec_result = factorial_recursive(number)
                
                print(f"\nStack method: {result}")
                print(f"Recursive method: {rec_result}")
                
                if result == rec_result and result is not None:
                    print("✓ Both methods give the same result!")
                    
            elif choice == 4:
                number = int(input("Enter a number to demonstrate (recommended: 5 or less): "))
                demonstrate_stack_approach(number)
                
            elif choice == 5:
                print(f"\n=== Factorial Table ===")
                print("n\tn!")
                print("---\t---")
                for i in range(11):
                    print(f"{i}\t{factorial_recursive(i)}")
                    
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
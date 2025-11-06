def is_valid(expr):
    stack = []
    pairs = {'(': ')', '[': ']', '{': '}'}
    
    for char in expr:
        if char in pairs:
            stack.append(char)
        elif char in pairs.values():
            if not stack or pairs[stack.pop()] != char:
                return False
    
    return len(stack) == 0

expr = input("Enter expression: ")
print(f"Result: {'Valid' if is_valid(expr) else 'Invalid'}")
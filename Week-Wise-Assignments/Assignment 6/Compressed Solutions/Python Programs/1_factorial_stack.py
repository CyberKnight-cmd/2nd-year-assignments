def factorial_stack(n):
    if n <= 1: return 1
    stack = list(range(n, 0, -1))
    result = 1
    while stack:
        result *= stack.pop()
    return result

n = int(input("Enter number: "))
print(f"Factorial: {factorial_stack(n)}")
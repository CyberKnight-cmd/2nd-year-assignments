def reverse_string(s):
    stack = list(s)
    return ''.join(stack.pop() for _ in range(len(stack)))

s = input("Enter string: ")
print(f"Reversed: {reverse_string(s)}")
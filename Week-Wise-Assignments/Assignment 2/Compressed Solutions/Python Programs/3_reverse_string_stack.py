def reverse_string(s):
    stack = list(s)
    return ''.join(stack.pop() for _ in range(len(stack)))

text = input("Enter string: ")
print("Reversed:", reverse_string(text))
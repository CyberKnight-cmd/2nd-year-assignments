def filter_primary_colors(stack):
    primary = {"Red", "Green", "Blue"}
    temp, queue = [], []
    while stack: 
        box = stack.pop()
        (temp if box in primary else queue).append(box)
    stack.extend(reversed(temp))
    return queue

stack = input("Enter colors (space separated): ").split()
queue = filter_primary_colors(stack)
print("Stack:", stack)
print("Queue:", queue)
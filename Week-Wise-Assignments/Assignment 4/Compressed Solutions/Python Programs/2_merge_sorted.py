class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def merge_recursive(l1, l2):
    if not l1: return l2
    if not l2: return l1
    
    if l1.data <= l2.data:
        l1.next = merge_recursive(l1.next, l2)
        return l1
    else:
        l2.next = merge_recursive(l1, l2.next)
        return l2

def display(head):
    while head:
        print(head.data, end=" -> " if head.next else " -> NULL\n")
        head = head.next

# Test
l1 = Node(1)
l1.next = Node(3)
l1.next.next = Node(5)

l2 = Node(2)
l2.next = Node(4)
l2.next.next = Node(6)

print("List 1: ", end="")
display(l1)
print("List 2: ", end="")
display(l2)

merged = merge_recursive(l1, l2)
print("Merged: ", end="")
display(merged)
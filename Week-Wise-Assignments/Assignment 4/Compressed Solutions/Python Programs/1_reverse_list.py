class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reverse_iterative(head):
    prev, curr = None, head
    while curr:
        next_node = curr.next
        curr.next = prev
        prev, curr = curr, next_node
    return prev

def reverse_recursive(head):
    if not head or not head.next:
        return head
    new_head = reverse_recursive(head.next)
    head.next.next = head
    head.next = None
    return new_head

def display(head):
    while head:
        print(head.data, end=" -> " if head.next else " -> NULL\n")
        head = head.next

# Test
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)

print("Original: ", end="")
display(head)

head = reverse_iterative(head)
print("Reversed: ", end="")
display(head)
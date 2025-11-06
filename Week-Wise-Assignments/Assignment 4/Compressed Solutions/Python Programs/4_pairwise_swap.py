class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def pairwise_swap(head):
    if not head or not head.next:
        return head
    
    new_head = head.next
    head.next = pairwise_swap(new_head.next)
    new_head.next = head
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

head = pairwise_swap(head)
print("Swapped: ", end="")
display(head)
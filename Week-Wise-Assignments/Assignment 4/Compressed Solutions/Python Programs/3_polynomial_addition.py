class Node:
    def __init__(self, coeff, exp):
        self.coeff = coeff
        self.exp = exp
        self.next = None

def add_polynomials(p1, p2):
    dummy = Node(0, 0)
    tail = dummy
    
    while p1 or p2:
        if not p1:
            tail.next = Node(p2.coeff, p2.exp)
            p2 = p2.next
        elif not p2:
            tail.next = Node(p1.coeff, p1.exp)
            p1 = p1.next
        elif p1.exp > p2.exp:
            tail.next = Node(p1.coeff, p1.exp)
            p1 = p1.next
        elif p1.exp < p2.exp:
            tail.next = Node(p2.coeff, p2.exp)
            p2 = p2.next
        else:
            sum_coeff = p1.coeff + p2.coeff
            if sum_coeff != 0:
                tail.next = Node(sum_coeff, p1.exp)
            p1, p2 = p1.next, p2.next
        
        if tail.next:
            tail = tail.next
    
    return dummy.next

def display(head):
    while head:
        print(f"{head.coeff}x^{head.exp}", end=" + " if head.next else "\n")
        head = head.next

# Test
p1 = Node(3, 2)
p1.next = Node(2, 1)
p1.next.next = Node(1, 0)

p2 = Node(4, 2)
p2.next = Node(3, 1)

print("P1: ", end="")
display(p1)
print("P2: ", end="")
display(p2)

result = add_polynomials(p1, p2)
print("Sum: ", end="")
display(result)
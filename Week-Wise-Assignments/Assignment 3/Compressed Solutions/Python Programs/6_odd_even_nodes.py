class Node:
    def __init__(self, d): self.data, self.next = d, None

class LL:
    def __init__(self): self.head = None
    def add(self, d): n = Node(d); (setattr(self, 'head', n) if not self.head else [t for t in [self.head] if not [setattr(t, 'next', n) for t in iter(lambda x=self.head: x.next if x.next else None, None)]])
    def printOE(self):
        odd, even, t = [], [], self.head
        while t: (odd if t.data % 2 else even).append(t.data); t = t.next
        print(f"Odd: {' -> '.join(map(str, odd)) + ' -> None' if odd else 'None'}")
        print(f"Even: {' -> '.join(map(str, even)) + ' -> None' if even else 'None'}")

ll = LL()
[ll.add(i) for i in [12, 7, 18, 3, 24, 9, 15, 6]]
ll.printOE()
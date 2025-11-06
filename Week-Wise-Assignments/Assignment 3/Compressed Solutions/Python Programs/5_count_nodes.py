class Node:
    def __init__(self, d): self.data, self.next = d, None

class LL:
    def __init__(self): self.head = None
    def add(self, d): n = Node(d); (setattr(self, 'head', n) if not self.head else [t for t in [self.head] if not [setattr(t, 'next', n) for t in iter(lambda x=self.head: x.next if x.next else None, None)]])
    def count(self): c, t = 0, self.head; [(c := c + 1, t := t.next) for _ in iter(lambda: t, None)]; return c
    def countr(self, n=None): n = n or self.head; return 0 if not n else 1 + self.countr(n.next)

ll = LL()
[ll.add(i) for i in [10, 20, 30, 40, 50]]
print(f"Iterative: {ll.count()}")
print(f"Recursive: {ll.countr()}")
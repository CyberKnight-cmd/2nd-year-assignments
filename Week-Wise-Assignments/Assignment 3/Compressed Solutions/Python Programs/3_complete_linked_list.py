class Node:
    def __init__(self, d): self.data, self.next = d, None

class LL:
    def __init__(self): self.head = None
    def iaf(self, d): n = Node(d); n.next = self.head; self.head = n
    def ial(self, d): n = Node(d); (setattr(self, 'head', n) if not self.head else [t for t in [self.head] if not [setattr(t, 'next', n) for t in iter(lambda x=self.head: x.next if x.next else None, None)]])
    def iaa(self, d, p): self.iaf(d) if p == 1 else (lambda t: [setattr(t, 'next', Node(d)), setattr(Node(d), 'next', t.next)] if t else self.ial(d))([self.head] + [self.head := self.head.next for _ in range(p-2) if self.head and self.head.next][-1:] or [None])[0] if self.head else self.ial(d)
    def df(self): self.head = self.head.next if self.head else None
    def dl(self): (setattr(self, 'head', None) if not self.head.next else [setattr(t, 'next', None) for t in iter(lambda x=self.head: x.next if x.next.next else None, None)]) if self.head else None
    def da(self, p): self.df() if p == 1 else ([setattr(t, 'next', t.next.next) for t in [self.head] + [self.head := self.head.next for _ in range(p-2) if self.head and self.head.next] if t and t.next] or None)
    def disp(self): print(' -> '.join([str(t.data) for t in iter(lambda x=[self.head]: x[0] and (x.append(x[0].next), x.pop(0))[1] or None, None)]) + ' -> None' if self.head else 'Empty')

ll = LL()
while True:
    c = input("1:IF 2:IL 3:IA 4:DF 5:DL 6:DA 7:Show 8:Exit: ")
    if c == '1': ll.iaf(int(input()))
    elif c == '2': ll.ial(int(input()))
    elif c == '3': ll.iaa(int(input()), int(input()))
    elif c == '4': ll.df()
    elif c == '5': ll.dl()
    elif c == '6': ll.da(int(input()))
    elif c == '7': ll.disp()
    elif c == '8': break
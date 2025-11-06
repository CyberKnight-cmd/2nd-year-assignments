class Node:
    def __init__(self, d): self.data, self.next = d, None

class LL:
    def __init__(self): self.head = None
    def ial(self, d): n = Node(d); (setattr(self, 'head', n) if not self.head else [t for t in [self.head] if not [setattr(t, 'next', n) for t in iter(lambda x=self.head: x.next if x.next else None, None)]])
    def df(self): 
        if not self.head: return None
        self.head = self.head.next; return True
    def dl(self):
        if not self.head: return None
        if not self.head.next: self.head = None; return True
        t = self.head; [t := t.next for _ in iter(lambda: t.next.next, None)]; t.next = None; return True
    def da(self, p):
        if not self.head or p < 1: return None
        if p == 1: return self.df()
        t = self.head; [t := t.next for _ in range(p-2) if t and t.next]; 
        if not t or not t.next: return None
        t.next = t.next.next; return True
    def disp(self): 
        if not self.head: print('Empty'); return
        t = self.head; print(' -> '.join([str(t.data)] + [str((t := t.next).data) for _ in iter(lambda: t.next, None)]) + ' -> None')

ll = LL()
[ll.ial(i*10) for i in range(1, 6)]
while True:
    c = input("1:DelFirst 2:DelLast 3:DelAny 4:Show 5:Exit: ")
    if c == '1': ll.df()
    elif c == '2': ll.dl()
    elif c == '3': ll.da(int(input()))
    elif c == '4': ll.disp()
    elif c == '5': break
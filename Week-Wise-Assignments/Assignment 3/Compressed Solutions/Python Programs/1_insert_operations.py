class Node:
    def __init__(self, d): self.data, self.next = d, None

class LL:
    def __init__(self): self.head = None
    def iaf(self, d): n = Node(d); n.next = self.head; self.head = n
    def ial(self, d): 
        n = Node(d)
        if not self.head: self.head = n
        else: t = self.head; [t := t.next for _ in iter(lambda: t.next, None)]; t.next = n
    def iaa(self, d, p):
        if p == 1: return self.iaf(d)
        t = self.head; [t := t.next for _ in range(p-2) if t]; 
        if not t: return self.ial(d)
        n = Node(d); n.next = t.next; t.next = n
    def disp(self): 
        if not self.head: print('Empty'); return
        t = self.head; print(' -> '.join([str(t.data)] + [str((t := t.next).data) for _ in iter(lambda: t.next, None)]) + ' -> None')

ll = LL()
while True:
    c = input("1:First 2:Last 3:Any 4:Show 5:Exit: ")
    if c == '1': ll.iaf(int(input()))
    elif c == '2': ll.ial(int(input()))
    elif c == '3': ll.iaa(int(input()), int(input()))
    elif c == '4': ll.disp()
    elif c == '5': break
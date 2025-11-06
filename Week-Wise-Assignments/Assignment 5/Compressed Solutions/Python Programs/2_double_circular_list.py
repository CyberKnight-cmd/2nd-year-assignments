class Node:
    def __init__(self, data):
        self.data = data
        self.next = self.prev = self

class DoublyCircularList:
    def __init__(self):
        self.head = None
    
    def display(self):
        if not self.head: print("Empty"); return
        temp = self.head
        while True:
            print(temp.data, end=" ")
            temp = temp.next
            if temp == self.head: break
        print()
    
    def insert_begin(self, data):
        node = Node(data)
        if not self.head:
            self.head = node
        else:
            node.next = self.head
            node.prev = self.head.prev
            self.head.prev.next = node
            self.head.prev = node
            self.head = node
    
    def insert_end(self, data):
        node = Node(data)
        if not self.head:
            self.head = node
        else:
            node.next = self.head
            node.prev = self.head.prev
            self.head.prev.next = node
            self.head.prev = node
    
    def search(self, key):
        if not self.head: return -1
        temp, pos = self.head, 0
        while True:
            if temp.data == key: return pos
            temp, pos = temp.next, pos + 1
            if temp == self.head: break
        return -1
    
    def count(self):
        if not self.head: return 0
        c, temp = 0, self.head
        while True:
            c, temp = c + 1, temp.next
            if temp == self.head: break
        return c
    
    def delete_begin(self):
        if not self.head: return
        if self.head.next == self.head:
            self.head = None
        else:
            self.head.prev.next = self.head.next
            self.head.next.prev = self.head.prev
            self.head = self.head.next
    
    def delete_end(self):
        if not self.head: return
        if self.head.next == self.head:
            self.head = None
        else:
            last = self.head.prev
            last.prev.next = self.head
            self.head.prev = last.prev

dcl = DoublyCircularList()
while True:
    choice = int(input("1.Display 2.InsertBegin 3.InsertEnd 4.Search 5.Count 6.DelBegin 7.DelEnd 8.Exit: "))
    if choice == 1: dcl.display()
    elif choice == 2: dcl.insert_begin(int(input("Data: ")))
    elif choice == 3: dcl.insert_end(int(input("Data: ")))
    elif choice == 4: print(f"Found at: {dcl.search(int(input('Key: ')))}")
    elif choice == 5: print(f"Count: {dcl.count()}")
    elif choice == 6: dcl.delete_begin()
    elif choice == 7: dcl.delete_end()
    elif choice == 8: break
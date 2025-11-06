class Node:
    def __init__(self, data):
        self.data = data
        self.next = self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = self.tail = None
    
    def display(self):
        if not self.head: print("Empty"); return
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()
    
    def insert_begin(self, data):
        node = Node(data)
        if self.head: self.head.prev = node
        else: self.tail = node
        node.next = self.head
        self.head = node
    
    def insert_end(self, data):
        node = Node(data)
        if self.tail: self.tail.next = node
        else: self.head = node
        node.prev = self.tail
        self.tail = node
    
    def insert_pos(self, data, pos):
        if pos == 0: self.insert_begin(data); return
        node = Node(data)
        temp = self.head
        for _ in range(pos):
            if not temp: return
            temp = temp.next
        if not temp: self.insert_end(data); return
        node.next = temp
        node.prev = temp.prev
        temp.prev.next = node
        temp.prev = node
    
    def search(self, key):
        temp, pos = self.head, 0
        while temp:
            if temp.data == key: return pos
            temp, pos = temp.next, pos + 1
        return -1
    
    def count(self):
        c, temp = 0, self.head
        while temp: c, temp = c + 1, temp.next
        return c
    
    def delete_begin(self):
        if not self.head: return
        if self.head == self.tail: self.head = self.tail = None
        else: self.head, self.head.prev = self.head.next, None
    
    def delete_end(self):
        if not self.tail: return
        if self.head == self.tail: self.head = self.tail = None
        else: self.tail, self.tail.next = self.tail.prev, None
    
    def delete_pos(self, pos):
        if pos == 0: self.delete_begin(); return
        temp = self.head
        for _ in range(pos):
            if not temp: return
            temp = temp.next
        if not temp: return
        if temp.prev: temp.prev.next = temp.next
        if temp.next: temp.next.prev = temp.prev
        if temp == self.tail: self.tail = temp.prev

dll = DoublyLinkedList()
while True:
    choice = int(input("1.Display 2.InsertBegin 3.InsertEnd 4.InsertPos 5.Search 6.Count 7.DelBegin 8.DelEnd 9.DelPos 10.Exit: "))
    if choice == 1: dll.display()
    elif choice == 2: dll.insert_begin(int(input("Data: ")))
    elif choice == 3: dll.insert_end(int(input("Data: ")))
    elif choice == 4: dll.insert_pos(int(input("Data: ")), int(input("Pos: ")))
    elif choice == 5: print(f"Found at: {dll.search(int(input('Key: ')))}")
    elif choice == 6: print(f"Count: {dll.count()}")
    elif choice == 7: dll.delete_begin()
    elif choice == 8: dll.delete_end()
    elif choice == 9: dll.delete_pos(int(input("Pos: ")))
    elif choice == 10: break
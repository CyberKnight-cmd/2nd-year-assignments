class Node:
    """Node class for doubly linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    """Doubly Linked List implementation with comprehensive operations"""
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def display(self):
        """
        Algorithm for Display:
        1. Check if list is empty
        2. Traverse forward from head using next pointers
        3. Also provide reverse traversal from tail using prev pointers
        """
        if not self.head:
            print("List is empty!")
            return
        
        print("\nForward Display: ", end="")
        current = self.head
        while current:
            print(current.data, end=" <-> " if current.next else " <-> NULL\n")
            current = current.next
        
        print("Reverse Display: ", end="")
        current = self.tail
        while current:
            print(current.data, end=" <-> " if current.prev else " <-> NULL\n")
            current = current.prev
        
        print(f"List size: {self.size}")
    
    def insert_at_beginning(self, data):
        """
        Algorithm for Insert at Beginning:
        1. Create new node
        2. If list is empty, set both head and tail to new node
        3. Otherwise, link new node to current head and update head
        """
        print(f"\n=== Insert at Beginning ===")
        print(f"Inserting {data} at the beginning")
        
        new_node = Node(data)
        
        if not self.head:
            print("List is empty, setting both head and tail to new node")
            self.head = self.tail = new_node
        else:
            print("Linking new node to current head")
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        
        self.size += 1
        print(f"Element {data} inserted at beginning successfully! (Size: {self.size})")
    
    def insert_at_end(self, data):
        """
        Algorithm for Insert at End:
        1. Create new node
        2. If list is empty, set both head and tail to new node
        3. Otherwise, link new node to current tail and update tail
        """
        print(f"\n=== Insert at End ===")
        print(f"Inserting {data} at the end")
        
        new_node = Node(data)
        
        if not self.tail:
            print("List is empty, setting both head and tail to new node")
            self.head = self.tail = new_node
        else:
            print("Linking new node to current tail")
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
        
        self.size += 1
        print(f"Element {data} inserted at end successfully! (Size: {self.size})")
    
    def insert_at_position(self, data, position):
        """
        Algorithm for Insert at Position:
        1. Validate position (0 to size)
        2. If position is 0, insert at beginning
        3. If position is size, insert at end
        4. Otherwise, traverse to position and insert
        """
        print(f"\n=== Insert at Position {position} ===")
        
        if position < 0 or position > self.size:
            print(f"Invalid position! Valid range: 0 to {self.size}")
            return
        
        if position == 0:
            self.insert_at_beginning(data)
            return
        
        if position == self.size:
            self.insert_at_end(data)
            return
        
        print(f"Inserting {data} at position {position}")
        new_node = Node(data)
        current = self.head
        
        # Traverse to position
        for i in range(position):
            current = current.next
        
        print("Linking new node between existing nodes")
        new_node.next = current
        new_node.prev = current.prev
        current.prev.next = new_node
        current.prev = new_node
        
        self.size += 1
        print(f"Element {data} inserted at position {position} successfully! (Size: {self.size})")
    
    def search(self, key):
        """
        Algorithm for Search:
        1. Start from head
        2. Traverse the list comparing each node's data
        3. Return position if found, -1 if not found
        """
        print(f"\n=== Search Element {key} ===")
        
        if not self.head:
            print("List is empty!")
            return -1
        
        current = self.head
        position = 0
        
        print("Searching process:")
        while current:
            print(f"Position {position}: {current.data}", end="")
            if current.data == key:
                print(" <- FOUND!")
                print(f"Element {key} found at position {position}")
                return position
            print()
            current = current.next
            position += 1
        
        print(f"Element {key} not found in the list")
        return -1
    
    def count_nodes(self):
        """Function to count nodes"""
        print(f"\n=== Count Nodes ===")
        print(f"Total nodes in the list: {self.size}")
        return self.size
    
    def delete_at_beginning(self):
        """
        Algorithm for Delete at Beginning:
        1. Check if list is empty
        2. If only one node, set head and tail to None
        3. Otherwise, update head to next node and set its prev to None
        """
        print(f"\n=== Delete at Beginning ===")
        
        if not self.head:
            print("List is empty! Cannot delete.")
            return
        
        node_to_delete = self.head
        print(f"Deleting element {node_to_delete.data} from beginning")
        
        if self.head == self.tail:
            print("Only one node in list, setting head and tail to None")
            self.head = self.tail = None
        else:
            print("Updating head to next node")
            self.head = self.head.next
            self.head.prev = None
        
        self.size -= 1
        print(f"Element deleted from beginning successfully! (Size: {self.size})")
    
    def delete_at_end(self):
        """
        Algorithm for Delete at End:
        1. Check if list is empty
        2. If only one node, set head and tail to None
        3. Otherwise, update tail to previous node and set its next to None
        """
        print(f"\n=== Delete at End ===")
        
        if not self.tail:
            print("List is empty! Cannot delete.")
            return
        
        node_to_delete = self.tail
        print(f"Deleting element {node_to_delete.data} from end")
        
        if self.head == self.tail:
            print("Only one node in list, setting head and tail to None")
            self.head = self.tail = None
        else:
            print("Updating tail to previous node")
            self.tail = self.tail.prev
            self.tail.next = None
        
        self.size -= 1
        print(f"Element deleted from end successfully! (Size: {self.size})")
    
    def delete_at_position(self, position):
        """
        Algorithm for Delete at Position:
        1. Validate position
        2. If position is 0, delete at beginning
        3. If position is last, delete at end
        4. Otherwise, traverse to position and delete
        """
        print(f"\n=== Delete at Position {position} ===")
        
        if position < 0 or position >= self.size:
            print(f"Invalid position! Valid range: 0 to {self.size - 1}")
            return
        
        if position == 0:
            self.delete_at_beginning()
            return
        
        if position == self.size - 1:
            self.delete_at_end()
            return
        
        current = self.head
        
        # Traverse to position
        for i in range(position):
            current = current.next
        
        print(f"Deleting element {current.data} from position {position}")
        print("Updating links to bypass the node")
        
        current.prev.next = current.next
        current.next.prev = current.prev
        
        self.size -= 1
        print(f"Element deleted from position {position} successfully! (Size: {self.size})")
    
    def get_size(self):
        """Get the size of the list"""
        return self.size

def main():
    """Main function with interactive menu"""
    dll = DoublyLinkedList()
    
    print("=== Doubly Linked List Implementation ===")
    print("Features: Bidirectional traversal, efficient insertion/deletion")
    print("Each node has both next and prev pointers for forward and backward navigation\n")
    
    while True:
        print("\n--- Doubly Linked List Menu ---")
        print("1. Display list")
        print("2. Insert at beginning")
        print("3. Insert at end")
        print("4. Insert at position")
        print("5. Search element")
        print("6. Count nodes")
        print("7. Delete at beginning")
        print("8. Delete at end")
        print("9. Delete at position")
        print("10. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                dll.display()
                
            elif choice == 2:
                data = int(input("Enter data to insert at beginning: "))
                dll.insert_at_beginning(data)
                
            elif choice == 3:
                data = int(input("Enter data to insert at end: "))
                dll.insert_at_end(data)
                
            elif choice == 4:
                data = int(input("Enter data to insert: "))
                position = int(input(f"Enter position (0 to {dll.get_size()}): "))
                dll.insert_at_position(data, position)
                
            elif choice == 5:
                data = int(input("Enter element to search: "))
                dll.search(data)
                
            elif choice == 6:
                dll.count_nodes()
                
            elif choice == 7:
                dll.delete_at_beginning()
                
            elif choice == 8:
                dll.delete_at_end()
                
            elif choice == 9:
                if dll.get_size() == 0:
                    print("List is empty!")
                else:
                    position = int(input(f"Enter position to delete (0 to {dll.get_size() - 1}): "))
                    dll.delete_at_position(position)
                
            elif choice == 10:
                print("Exiting program...")
                break
                
            else:
                print("Invalid choice! Please try again.")
                
        except ValueError:
            print("Invalid input! Please enter a valid number.")
        except Exception as e:
            print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
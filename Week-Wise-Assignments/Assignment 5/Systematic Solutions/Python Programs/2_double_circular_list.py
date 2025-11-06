class Node:
    """Node class for doubly circular linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyCircularLinkedList:
    """Doubly Circular Linked List implementation with comprehensive operations"""
    def __init__(self):
        self.head = None
        self.size = 0
    
    def display(self):
        """
        Algorithm for Display (Doubly Circular):
        1. Check if list is empty
        2. Start from head and traverse using next pointers
        3. Stop when we reach head again (circular nature)
        4. Also provide reverse display option
        """
        if not self.head:
            print("List is empty!")
            return
        
        print("\nForward Display (Circular): ", end="")
        current = self.head
        while True:
            print(current.data, end="")
            current = current.next
            if current == self.head:
                break
            print(" <-> ", end="")
        print(" <-> [CIRCULAR]")
        
        print("Reverse Display (Circular): ", end="")
        current = self.head.prev  # Start from last node
        while True:
            print(current.data, end="")
            current = current.prev
            if current == self.head.prev:
                break
            print(" <-> ", end="")
        print(" <-> [CIRCULAR]")
        
        print(f"List size: {self.size}")
    
    def insert_at_beginning(self, data):
        """
        Algorithm for Insert at Beginning (Doubly Circular):
        1. Create new node
        2. If list is empty, make node point to itself
        3. Otherwise, insert between last node and head
        4. Update head to new node
        """
        print(f"\n=== Insert at Beginning (Doubly Circular) ===")
        print(f"Inserting {data} at the beginning")
        
        new_node = Node(data)
        
        if not self.head:
            print("List is empty, making node circular (pointing to itself)")
            new_node.next = new_node.prev = new_node
            self.head = new_node
        else:
            print("Inserting between last node and current head")
            last = self.head.prev
            
            new_node.next = self.head
            new_node.prev = last
            last.next = new_node
            self.head.prev = new_node
            self.head = new_node
        
        self.size += 1
        print(f"Element {data} inserted at beginning successfully! (Size: {self.size})")
    
    def insert_at_end(self, data):
        """
        Algorithm for Insert at End (Doubly Circular):
        1. Create new node
        2. If list is empty, make node point to itself and set as head
        3. Otherwise, insert between last node and head
        """
        print(f"\n=== Insert at End (Doubly Circular) ===")
        print(f"Inserting {data} at the end")
        
        new_node = Node(data)
        
        if not self.head:
            print("List is empty, making node circular (pointing to itself)")
            new_node.next = new_node.prev = new_node
            self.head = new_node
        else:
            print("Inserting between last node and head")
            last = self.head.prev
            
            new_node.next = self.head
            new_node.prev = last
            last.next = new_node
            self.head.prev = new_node
        
        self.size += 1
        print(f"Element {data} inserted at end successfully! (Size: {self.size})")
    
    def insert_at_position(self, data, position):
        """
        Algorithm for Insert at Position (Doubly Circular):
        1. Validate position
        2. If position is 0, insert at beginning
        3. Otherwise, traverse to position and insert
        """
        print(f"\n=== Insert at Position {position} (Doubly Circular) ===")
        
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
        
        print("Linking new node in circular fashion")
        new_node.next = current
        new_node.prev = current.prev
        current.prev.next = new_node
        current.prev = new_node
        
        self.size += 1
        print(f"Element {data} inserted at position {position} successfully! (Size: {self.size})")
    
    def search(self, key):
        """
        Algorithm for Search (Doubly Circular):
        1. Start from head
        2. Traverse using next pointers
        3. Stop when we reach head again or find element
        """
        print(f"\n=== Search Element {key} (Doubly Circular) ===")
        
        if not self.head:
            print("List is empty!")
            return -1
        
        current = self.head
        position = 0
        
        print("Searching process:")
        while True:
            print(f"Position {position}: {current.data}", end="")
            if current.data == key:
                print(" <- FOUND!")
                print(f"Element {key} found at position {position}")
                return position
            print()
            current = current.next
            position += 1
            if current == self.head:
                break
        
        print(f"Element {key} not found in the list")
        return -1
    
    def count_nodes(self):
        """Function to count nodes"""
        print(f"\n=== Count Nodes (Doubly Circular) ===")
        print(f"Total nodes in the list: {self.size}")
        return self.size
    
    def delete_at_beginning(self):
        """
        Algorithm for Delete at Beginning (Doubly Circular):
        1. Check if list is empty
        2. If only one node, set head to None
        3. Otherwise, update links to bypass head node
        """
        print(f"\n=== Delete at Beginning (Doubly Circular) ===")
        
        if not self.head:
            print("List is empty! Cannot delete.")
            return
        
        node_to_delete = self.head
        print(f"Deleting element {node_to_delete.data} from beginning")
        
        if self.size == 1:
            print("Only one node in list, setting head to None")
            self.head = None
        else:
            print("Updating circular links to bypass head node")
            last = self.head.prev
            second = self.head.next
            
            last.next = second
            second.prev = last
            self.head = second
        
        self.size -= 1
        print(f"Element deleted from beginning successfully! (Size: {self.size})")
    
    def delete_at_end(self):
        """
        Algorithm for Delete at End (Doubly Circular):
        1. Check if list is empty
        2. If only one node, set head to None
        3. Otherwise, update links to bypass last node
        """
        print(f"\n=== Delete at End (Doubly Circular) ===")
        
        if not self.head:
            print("List is empty! Cannot delete.")
            return
        
        if self.size == 1:
            print("Only one node in list, deleting it")
            self.head = None
            self.size -= 1
            print(f"Element deleted from end successfully! (Size: {self.size})")
            return
        
        last = self.head.prev
        print(f"Deleting element {last.data} from end")
        
        print("Updating circular links to bypass last node")
        second_last = last.prev
        
        second_last.next = self.head
        self.head.prev = second_last
        
        self.size -= 1
        print(f"Element deleted from end successfully! (Size: {self.size})")
    
    def delete_at_position(self, position):
        """
        Algorithm for Delete at Position (Doubly Circular):
        1. Validate position
        2. If position is 0, delete at beginning
        3. Otherwise, traverse to position and delete
        """
        print(f"\n=== Delete at Position {position} (Doubly Circular) ===")
        
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
        print("Updating circular links to bypass the node")
        
        current.prev.next = current.next
        current.next.prev = current.prev
        
        self.size -= 1
        print(f"Element deleted from position {position} successfully! (Size: {self.size})")
    
    def get_size(self):
        """Get the size of the list"""
        return self.size

def main():
    """Main function with interactive menu"""
    dcll = DoublyCircularLinkedList()
    
    print("=== Doubly Circular Linked List Implementation ===")
    print("Features: Bidirectional circular traversal, efficient operations")
    print("Each node connects to form a circular structure with both next and prev pointers\n")
    
    while True:
        print("\n--- Doubly Circular Linked List Menu ---")
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
                dcll.display()
                
            elif choice == 2:
                data = int(input("Enter data to insert at beginning: "))
                dcll.insert_at_beginning(data)
                
            elif choice == 3:
                data = int(input("Enter data to insert at end: "))
                dcll.insert_at_end(data)
                
            elif choice == 4:
                data = int(input("Enter data to insert: "))
                position = int(input(f"Enter position (0 to {dcll.get_size()}): "))
                dcll.insert_at_position(data, position)
                
            elif choice == 5:
                data = int(input("Enter element to search: "))
                dcll.search(data)
                
            elif choice == 6:
                dcll.count_nodes()
                
            elif choice == 7:
                dcll.delete_at_beginning()
                
            elif choice == 8:
                dcll.delete_at_end()
                
            elif choice == 9:
                if dcll.get_size() == 0:
                    print("List is empty!")
                else:
                    position = int(input(f"Enter position to delete (0 to {dcll.get_size() - 1}): "))
                    dcll.delete_at_position(position)
                
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
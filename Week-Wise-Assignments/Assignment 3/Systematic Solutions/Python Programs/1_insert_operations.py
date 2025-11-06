class Node:
    """
    Node class for single linked list
    """
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """
    Single Linked List implementation with insert operations
    """
    
    def __init__(self):
        """
        Initialize empty linked list
        """
        self.head = None
    
    def createList(self):
        """
        Create an empty linked list
        """
        self.head = None
        print("Empty linked list created successfully!")
    
    def insertAtFirst(self, data):
        """
        Insert node at the beginning of the list
        
        Args:
            data: Data to insert
        """
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        print(f"Inserted {data} at the beginning")
    
    def insertAtLast(self, data):
        """
        Insert node at the end of the list
        
        Args:
            data: Data to insert
        """
        new_node = Node(data)
        
        # If list is empty
        if self.head is None:
            self.head = new_node
            print(f"Inserted {data} as the first node")
            return
        
        # Traverse to the last node
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        
        temp.next = new_node
        print(f"Inserted {data} at the end")
    
    def insertAtAny(self, data, position):
        """
        Insert node at any position in the list
        
        Args:
            data: Data to insert
            position: Position to insert (1-based indexing)
        """
        if position < 1:
            print("Invalid position! Position should be >= 1")
            return
        
        # If inserting at first position
        if position == 1:
            self.insertAtFirst(data)
            return
        
        new_node = Node(data)
        
        # Traverse to (position-1)th node
        temp = self.head
        for i in range(1, position - 1):
            if temp is None:
                break
            temp = temp.next
        
        # If position is beyond the list
        if temp is None:
            print(f"Position {position} is beyond the list. Inserting at the end.")
            self.insertAtLast(data)
            return
        
        new_node.next = temp.next
        temp.next = new_node
        print(f"Inserted {data} at position {position}")
    
    def displayList(self):
        """
        Display the linked list
        """
        if self.head is None:
            print("List is empty!")
            return
        
        print("Linked List: ", end="")
        temp = self.head
        while temp is not None:
            print(temp.data, end="")
            if temp.next is not None:
                print(" -> ", end="")
            temp = temp.next
        print(" -> None")
    
    def countNodes(self):
        """
        Count the number of nodes in the list
        
        Returns:
            int: Number of nodes
        """
        count = 0
        temp = self.head
        while temp is not None:
            count += 1
            temp = temp.next
        return count
    
    def isEmpty(self):
        """
        Check if the list is empty
        
        Returns:
            bool: True if empty, False otherwise
        """
        return self.head is None
    
    def search(self, value):
        """
        Search for a value in the list
        
        Args:
            value: Value to search
            
        Returns:
            int: Position of value (1-based) or -1 if not found
        """
        temp = self.head
        position = 1
        
        while temp is not None:
            if temp.data == value:
                return position
            temp = temp.next
            position += 1
        
        return -1

def demonstrate_insert_operations():
    """
    Demonstrate insert operations
    """
    print("=== Single Linked List - Insert Operations Demonstration ===")
    
    ll = LinkedList()
    ll.createList()
    
    # Test insertAtFirst
    print("\n1. Testing insertAtFirst:")
    ll.insertAtFirst(10)
    ll.insertAtFirst(20)
    ll.insertAtFirst(30)
    ll.displayList()
    
    # Test insertAtLast
    print("\n2. Testing insertAtLast:")
    ll.insertAtLast(40)
    ll.insertAtLast(50)
    ll.displayList()
    
    # Test insertAtAny
    print("\n3. Testing insertAtAny:")
    ll.insertAtAny(25, 3)  # Insert 25 at position 3
    ll.insertAtAny(5, 1)   # Insert 5 at position 1 (beginning)
    ll.insertAtAny(60, 10) # Insert 60 at position beyond list
    ll.displayList()
    
    # Display statistics
    print(f"\nTotal nodes: {ll.countNodes()}")
    print(f"Is empty: {ll.isEmpty()}")
    
    # Test search
    search_value = 25
    position = ll.search(search_value)
    if position != -1:
        print(f"Value {search_value} found at position {position}")
    else:
        print(f"Value {search_value} not found")

def interactive_insert_operations():
    """
    Interactive insert operations
    """
    print("\n=== Interactive Insert Operations ===")
    
    ll = LinkedList()
    ll.createList()
    
    while True:
        print("\n--- Menu ---")
        print("1. Insert at First")
        print("2. Insert at Last")
        print("3. Insert at Any Position")
        print("4. Display List")
        print("5. Count Nodes")
        print("6. Search Value")
        print("7. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                data = int(input("Enter data to insert at first: "))
                ll.insertAtFirst(data)
            
            elif choice == 2:
                data = int(input("Enter data to insert at last: "))
                ll.insertAtLast(data)
            
            elif choice == 3:
                data = int(input("Enter data to insert: "))
                position = int(input("Enter position (1-based): "))
                ll.insertAtAny(data, position)
            
            elif choice == 4:
                ll.displayList()
            
            elif choice == 5:
                print(f"Number of nodes: {ll.countNodes()}")
            
            elif choice == 6:
                value = int(input("Enter value to search: "))
                position = ll.search(value)
                if position != -1:
                    print(f"Value {value} found at position {position}")
                else:
                    print(f"Value {value} not found")
            
            elif choice == 7:
                print("Exiting...")
                break
            
            else:
                print("Invalid choice! Please try again.")
        
        except ValueError:
            print("Please enter a valid number!")
        except Exception as e:
            print(f"Error: {e}")

def test_edge_cases():
    """
    Test edge cases for insert operations
    """
    print("\n=== Testing Edge Cases ===")
    
    ll = LinkedList()
    
    # Test operations on empty list
    print("\n1. Operations on empty list:")
    ll.displayList()
    print(f"Count: {ll.countNodes()}")
    print(f"Search 10: {ll.search(10)}")
    
    # Test invalid positions
    print("\n2. Invalid positions:")
    ll.insertAtAny(100, 0)   # Invalid position
    ll.insertAtAny(100, -1)  # Invalid position
    
    # Test single node operations
    print("\n3. Single node operations:")
    ll.insertAtFirst(42)
    ll.displayList()
    ll.insertAtAny(99, 2)    # Insert at position 2
    ll.displayList()
    
    # Test large position
    print("\n4. Large position:")
    ll.insertAtAny(200, 100) # Position beyond list
    ll.displayList()

if __name__ == "__main__":
    # Run demonstration
    demonstrate_insert_operations()
    
    # Test edge cases
    test_edge_cases()
    
    # Run interactive mode
    interactive_insert_operations()
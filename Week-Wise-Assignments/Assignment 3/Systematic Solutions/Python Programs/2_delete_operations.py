class Node:
    """
    Node class for single linked list
    """
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """
    Single Linked List implementation with delete operations
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
    
    def insertAtLast(self, data):
        """
        Insert node at the end (for testing purposes)
        
        Args:
            data: Data to insert
        """
        new_node = Node(data)
        
        if self.head is None:
            self.head = new_node
            return
        
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        
        temp.next = new_node
    
    def deleteFromFirst(self):
        """
        Delete node from the beginning of the list
        
        Returns:
            Data of deleted node or None if list is empty
        """
        if self.head is None:
            print("List is empty! Cannot delete from first.")
            return None
        
        deleted_data = self.head.data
        self.head = self.head.next
        print(f"Deleted {deleted_data} from the beginning")
        return deleted_data
    
    def deleteFromLast(self):
        """
        Delete node from the end of the list
        
        Returns:
            Data of deleted node or None if list is empty
        """
        if self.head is None:
            print("List is empty! Cannot delete from last.")
            return None
        
        # If only one node
        if self.head.next is None:
            deleted_data = self.head.data
            self.head = None
            print(f"Deleted {deleted_data} from the end")
            return deleted_data
        
        # Traverse to second last node
        temp = self.head
        while temp.next.next is not None:
            temp = temp.next
        
        deleted_data = temp.next.data
        temp.next = None
        print(f"Deleted {deleted_data} from the end")
        return deleted_data
    
    def deleteFromAny(self, position):
        """
        Delete node from any position in the list
        
        Args:
            position: Position to delete from (1-based indexing)
            
        Returns:
            Data of deleted node or None if position is invalid
        """
        if self.head is None:
            print(f"List is empty! Cannot delete from position {position}.")
            return None
        
        if position < 1:
            print("Invalid position! Position should be >= 1")
            return None
        
        # If deleting first node
        if position == 1:
            return self.deleteFromFirst()
        
        # Traverse to (position-1)th node
        temp = self.head
        for i in range(1, position - 1):
            if temp is None or temp.next is None:
                break
            temp = temp.next
        
        # If position is beyond the list
        if temp is None or temp.next is None:
            print(f"Position {position} is beyond the list!")
            return None
        
        deleted_data = temp.next.data
        temp.next = temp.next.next
        print(f"Deleted {deleted_data} from position {position}")
        return deleted_data
    
    def deleteByValue(self, value):
        """
        Delete first occurrence of a value
        
        Args:
            value: Value to delete
            
        Returns:
            bool: True if deleted, False if not found
        """
        if self.head is None:
            print(f"List is empty! Cannot delete value {value}.")
            return False
        
        # If first node contains the value
        if self.head.data == value:
            self.head = self.head.next
            print(f"Deleted value {value} from the beginning")
            return True
        
        # Search for the value
        temp = self.head
        while temp.next is not None:
            if temp.next.data == value:
                temp.next = temp.next.next
                print(f"Deleted value {value} from the list")
                return True
            temp = temp.next
        
        print(f"Value {value} not found in the list")
        return False
    
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
    
    def populateList(self, values):
        """
        Populate list with given values
        
        Args:
            values: List of values to insert
        """
        print(f"Populating list with values: {values}")
        for value in values:
            self.insertAtLast(value)

def demonstrate_delete_operations():
    """
    Demonstrate delete operations
    """
    print("=== Single Linked List - Delete Operations Demonstration ===")
    
    ll = LinkedList()
    ll.createList()
    
    # Populate with sample data
    sample_data = [10, 20, 30, 40, 50]
    ll.populateList(sample_data)
    ll.displayList()
    
    # Test deleteFromFirst
    print("\n1. Testing deleteFromFirst:")
    ll.deleteFromFirst()
    ll.displayList()
    
    # Test deleteFromLast
    print("\n2. Testing deleteFromLast:")
    ll.deleteFromLast()
    ll.displayList()
    
    # Test deleteFromAny
    print("\n3. Testing deleteFromAny:")
    ll.deleteFromAny(2)  # Delete from position 2
    ll.displayList()
    
    # Test deleteByValue
    print("\n4. Testing deleteByValue:")
    ll.deleteByValue(30)  # Delete value 30
    ll.displayList()
    
    # Display statistics
    print(f"\nTotal nodes: {ll.countNodes()}")
    print(f"Is empty: {ll.isEmpty()}")

def interactive_delete_operations():
    """
    Interactive delete operations
    """
    print("\n=== Interactive Delete Operations ===")
    
    ll = LinkedList()
    ll.createList()
    
    while True:
        print("\n--- Menu ---")
        print("1. Delete from First")
        print("2. Delete from Last")
        print("3. Delete from Any Position")
        print("4. Delete by Value")
        print("5. Display List")
        print("6. Count Nodes")
        print("7. Populate with Sample Data")
        print("8. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                ll.deleteFromFirst()
            
            elif choice == 2:
                ll.deleteFromLast()
            
            elif choice == 3:
                position = int(input("Enter position to delete (1-based): "))
                ll.deleteFromAny(position)
            
            elif choice == 4:
                value = int(input("Enter value to delete: "))
                ll.deleteByValue(value)
            
            elif choice == 5:
                ll.displayList()
            
            elif choice == 6:
                print(f"Number of nodes: {ll.countNodes()}")
            
            elif choice == 7:
                sample_data = [10, 20, 30, 40, 50]
                ll.populateList(sample_data)
                ll.displayList()
            
            elif choice == 8:
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
    Test edge cases for delete operations
    """
    print("\n=== Testing Edge Cases ===")
    
    ll = LinkedList()
    
    # Test operations on empty list
    print("\n1. Operations on empty list:")
    ll.deleteFromFirst()
    ll.deleteFromLast()
    ll.deleteFromAny(1)
    ll.deleteByValue(10)
    
    # Test single node deletion
    print("\n2. Single node deletion:")
    ll.insertAtLast(42)
    ll.displayList()
    ll.deleteFromLast()
    ll.displayList()
    
    # Test invalid positions
    print("\n3. Invalid positions:")
    ll.populateList([1, 2, 3])
    ll.displayList()
    ll.deleteFromAny(0)   # Invalid position
    ll.deleteFromAny(-1)  # Invalid position
    ll.deleteFromAny(10)  # Position beyond list
    ll.displayList()
    
    # Test deleting all nodes
    print("\n4. Deleting all nodes:")
    while not ll.isEmpty():
        ll.deleteFromFirst()
        ll.displayList()

def performance_test():
    """
    Performance test for delete operations
    """
    print("\n=== Performance Test ===")
    
    import time
    
    # Test with large list
    ll = LinkedList()
    n = 1000
    
    print(f"Creating list with {n} nodes...")
    start_time = time.time()
    for i in range(n):
        ll.insertAtLast(i)
    creation_time = time.time() - start_time
    
    print(f"List creation time: {creation_time:.4f} seconds")
    print(f"Initial node count: {ll.countNodes()}")
    
    # Test deleteFromFirst performance
    start_time = time.time()
    for i in range(n // 2):
        ll.deleteFromFirst()
    delete_first_time = time.time() - start_time
    
    print(f"Delete from first (500 operations): {delete_first_time:.4f} seconds")
    print(f"Remaining nodes: {ll.countNodes()}")
    
    # Test deleteFromLast performance
    start_time = time.time()
    while not ll.isEmpty():
        ll.deleteFromLast()
    delete_last_time = time.time() - start_time
    
    print(f"Delete from last (500 operations): {delete_last_time:.4f} seconds")
    print(f"Final node count: {ll.countNodes()}")

if __name__ == "__main__":
    # Run demonstration
    demonstrate_delete_operations()
    
    # Test edge cases
    test_edge_cases()
    
    # Performance test
    performance_test()
    
    # Run interactive mode
    interactive_delete_operations()
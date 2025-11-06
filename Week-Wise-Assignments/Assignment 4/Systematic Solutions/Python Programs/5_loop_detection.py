class Node:
    """Node class for single linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """Single Linked List implementation with loop detection functionality"""
    def __init__(self):
        self.head = None
        self.size = 0
    
    def insert_at_end(self, data):
        """Insert element at the end of the list"""
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
        self.size += 1
        print(f"Element {data} inserted successfully!")
    
    def display(self, max_nodes=20):
        """Display the linked list with loop protection"""
        if not self.head:
            print("List is empty!")
            return
        
        print("List: ", end="")
        current = self.head
        count = 0
        
        while current and count < max_nodes:
            print(current.data, end=" -> ")
            current = current.next
            count += 1
        
        if count == max_nodes:
            print("... (stopped to prevent infinite display)")
        else:
            print("NULL")
    
    def detect_loop_floyd(self):
        """
        Algorithm: Floyd's Cycle Detection (Tortoise and Hare)
        1. Use two pointers: slow (moves 1 step) and fast (moves 2 steps)
        2. If there's a loop, fast will eventually meet slow inside the loop
        3. If fast reaches NULL, there's no loop
        4. Time Complexity: O(n), Space Complexity: O(1)
        """
        print("\n=== Floyd's Cycle Detection Algorithm ===")
        print("Using two pointers: slow (1 step) and fast (2 steps)")
        
        if not self.head or not self.head.next:
            print("List has less than 2 nodes, no loop possible")
            return False
        
        slow = self.head
        fast = self.head
        step = 1
        
        print("\nStep-by-step detection process:")
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            print(f"Step {step}: Slow at {slow.data}, Fast at {fast.data if fast else 'NULL'}")
            
            if slow == fast:
                print(f"Loop detected! Pointers met at node with data: {slow.data}")
                return True
            
            step += 1
            
            # Safety check to prevent infinite loop in case of implementation error
            if step > self.size + 10:
                print("Safety limit reached, stopping detection")
                break
        
        print("No loop detected - Fast pointer reached end")
        return False
    
    def detect_loop_hashset(self):
        """
        Algorithm: Hash Set Method
        1. Traverse the list and store each node in a hash set
        2. If we encounter a node that's already in the set, there's a loop
        3. If we reach the end (NULL), there's no loop
        4. Time Complexity: O(n), Space Complexity: O(n)
        """
        print("\n=== Hash Set Loop Detection Algorithm ===")
        print("Using a set to track visited nodes")
        
        if not self.head:
            print("List is empty, no loop possible")
            return False
        
        visited = set()
        current = self.head
        step = 1
        
        print("\nStep-by-step detection process:")
        
        while current:
            print(f"Step {step}: Visiting node with data {current.data}")
            
            if current in visited:
                print(f"Node {current.data} already visited - Loop detected!")
                return True
            
            visited.add(current)
            print(f"         Added node {current.data} to visited set")
            current = current.next
            step += 1
            
            # Safety check
            if step > self.size + 10:
                print("Safety limit reached, stopping detection")
                break
        
        print("Reached end of list - No loop detected")
        return False
    
    def create_loop(self, position):
        """Create a loop for testing by connecting last node to node at given position"""
        if not self.head or position < 0:
            print("Invalid position or empty list!")
            return False
        
        # Find the node at given position
        current = self.head
        loop_node = None
        pos = 0
        
        while current:
            if pos == position:
                loop_node = current
            
            if not current.next:  # Last node
                if loop_node:
                    current.next = loop_node
                    print(f"Loop created! Last node now points to node at position {position} (data: {loop_node.data})")
                    return True
                else:
                    print(f"Position {position} not found in list!")
                    return False
            
            current = current.next
            pos += 1
        
        return False
    
    def get_size(self):
        """Get the size of the list"""
        return self.size

def main():
    """Main function with interactive menu"""
    linked_list = LinkedList()
    
    print("=== Loop Detection in Single Linked List ===")
    print("This program demonstrates different algorithms for detecting loops")
    print("in a single linked list.\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Insert element")
        print("2. Display list")
        print("3. Detect loop (Floyd's Algorithm)")
        print("4. Detect loop (Hash Set Method)")
        print("5. Create loop (for testing)")
        print("6. Get list size")
        print("7. Create sample list")
        print("8. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                data = int(input("Enter data to insert: "))
                linked_list.insert_at_end(data)
                
            elif choice == 2:
                linked_list.display()
                
            elif choice == 3:
                if not linked_list.head:
                    print("List is empty! Add some elements first.")
                else:
                    has_loop = linked_list.detect_loop_floyd()
                    print(f"\nResult: {'LOOP DETECTED' if has_loop else 'NO LOOP FOUND'}")
                    
            elif choice == 4:
                if not linked_list.head:
                    print("List is empty! Add some elements first.")
                else:
                    has_loop = linked_list.detect_loop_hashset()
                    print(f"\nResult: {'LOOP DETECTED' if has_loop else 'NO LOOP FOUND'}")
                    
            elif choice == 5:
                if not linked_list.head:
                    print("List is empty! Add some elements first.")
                else:
                    position = int(input("Enter position to create loop (0-based): "))
                    success = linked_list.create_loop(position)
                    if success:
                        print("Warning: Display function will be limited to prevent infinite output")
                        
            elif choice == 6:
                print(f"List size: {linked_list.get_size()}")
                
            elif choice == 7:
                linked_list = LinkedList()
                for i in range(1, 6):
                    linked_list.insert_at_end(i)
                print("Sample list created: 1 -> 2 -> 3 -> 4 -> 5")
                linked_list.display()
                
            elif choice == 8:
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
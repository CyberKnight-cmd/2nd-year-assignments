class Node:
    """Node class for single linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """Single Linked List implementation with reverse functionality"""
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
    
    def display(self):
        """Display the linked list"""
        if not self.head:
            print("List is empty!")
            return
        
        print("List: ", end="")
        current = self.head
        while current:
            print(current.data, end=" -> " if current.next else " -> NULL\n")
            current = current.next
    
    def reverse_iterative(self):
        """
        Algorithm for Iterative Reverse:
        1. Initialize three pointers: prev=None, current=head, next=None
        2. Traverse the list and for each node:
           - Store next node
           - Reverse the link (current.next = prev)
           - Move pointers forward
        3. Update head to prev
        """
        print("\n=== Iterative Reverse Process ===")
        print("Algorithm: Use three pointers (prev, current, next)")
        print("Step-by-step process:")
        
        prev = None
        current = self.head
        step = 1
        
        while current:
            next_node = current.next
            print(f"Step {step}: Current={current.data}, Next={next_node.data if next_node else 'NULL'}")
            
            # Reverse the link
            current.next = prev
            print(f"         Reversed link: {current.data} -> {prev.data if prev else 'NULL'}")
            
            # Move pointers
            prev = current
            current = next_node
            print(f"         Move pointers: prev={prev.data}, current={current.data if current else 'NULL'}")
            print()
            step += 1
        
        self.head = prev
        print("Iterative reverse completed!")
    
    def reverse_recursive(self):
        """
        Algorithm for Recursive Reverse:
        1. Base case: if head is None or head.next is None, return head
        2. Recursively reverse the rest of the list
        3. Reverse the current link
        4. Set current node's next to None
        """
        print("\n=== Recursive Reverse Process ===")
        print("Algorithm: Recursively reverse from the end")
        
        def reverse_util(node, depth=0):
            indent = "  " * depth
            print(f"{indent}Recursive call for node: {node.data if node else 'NULL'}")
            
            # Base case
            if not node or not node.next:
                print(f"{indent}Base case reached, returning: {node.data if node else 'NULL'}")
                return node
            
            # Recursive call
            print(f"{indent}Making recursive call for next node...")
            new_head = reverse_util(node.next, depth + 1)
            
            # Reverse the link
            print(f"{indent}Reversing link: {node.next.data} -> {node.data}")
            node.next.next = node
            node.next = None
            
            print(f"{indent}Returning new_head: {new_head.data}")
            return new_head
        
        self.head = reverse_util(self.head)
        print("Recursive reverse completed!")
    
    def get_size(self):
        """Get the size of the list"""
        return self.size

def main():
    """Main function with interactive menu"""
    linked_list = LinkedList()
    
    print("=== Single Linked List Reverse Implementation ===")
    print("This program demonstrates both iterative and recursive approaches")
    print("for reversing a single linked list.\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Insert element")
        print("2. Display list")
        print("3. Reverse list (Iterative)")
        print("4. Reverse list (Recursive)")
        print("5. Get list size")
        print("6. Exit")
        
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
                    print("Original list:")
                    linked_list.display()
                    linked_list.reverse_iterative()
                    print("List after iterative reverse:")
                    linked_list.display()
                    
            elif choice == 4:
                if not linked_list.head:
                    print("List is empty! Add some elements first.")
                else:
                    print("Original list:")
                    linked_list.display()
                    linked_list.reverse_recursive()
                    print("List after recursive reverse:")
                    linked_list.display()
                    
            elif choice == 5:
                print(f"List size: {linked_list.get_size()}")
                
            elif choice == 6:
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
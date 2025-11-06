class Node:
    """Node class for single linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """Single Linked List implementation with pairwise swap functionality"""
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
    
    def pairwise_swap_iterative(self):
        """
        Algorithm for Iterative Pairwise Swap:
        1. Use a dummy node to handle edge cases
        2. Keep track of previous node for linking
        3. For each pair of nodes:
           - Store the second node
           - Link previous to second node
           - Link first node to second's next
           - Link second node to first node
        4. Move to next pair
        """
        if not self.head or not self.head.next:
            print("List has less than 2 elements, no swapping needed!")
            return
        
        print("\n=== Iterative Pairwise Swap Process ===")
        print("Algorithm: Swap adjacent nodes iteratively")
        
        dummy = Node(0)
        dummy.next = self.head
        prev = dummy
        step = 1
        
        print("Step-by-step swapping process:")
        
        while prev.next and prev.next.next:
            # Identify the two nodes to be swapped
            first = prev.next
            second = prev.next.next
            
            print(f"Step {step}: Swapping {first.data} and {second.data}")
            print(f"         Before: ... -> {first.data} -> {second.data} -> ...")
            
            # Perform the swap
            prev.next = second
            first.next = second.next
            second.next = first
            
            print(f"         After:  ... -> {second.data} -> {first.data} -> ...")
            
            # Move to next pair
            prev = first
            step += 1
            print()
        
        self.head = dummy.next
        print("Iterative pairwise swap completed!")
    
    def pairwise_swap_recursive(self):
        """
        Algorithm for Recursive Pairwise Swap:
        1. Base case: if less than 2 nodes, return head
        2. Store the second node (new head of current pair)
        3. Recursively swap the rest of the list
        4. Link first node to the result of recursive call
        5. Link second node to first node
        6. Return second node as new head
        """
        print("\n=== Recursive Pairwise Swap Process ===")
        print("Algorithm: Recursively swap pairs from the beginning")
        
        def swap_pairs(node, depth=0):
            indent = "  " * depth
            
            if not node:
                print(f"{indent}Base case: Empty node, returning None")
                return None
            
            if not node.next:
                print(f"{indent}Base case: Single node {node.data}, returning as is")
                return node
            
            print(f"{indent}Swapping pair: {node.data} and {node.next.data}")
            
            # Store the second node
            second = node.next
            print(f"{indent}Second node: {second.data}")
            
            # Recursively swap the rest
            print(f"{indent}Recursively swapping rest of the list...")
            node.next = swap_pairs(second.next, depth + 1)
            
            # Complete the swap
            second.next = node
            print(f"{indent}Completed swap: {second.data} -> {node.data}")
            print(f"{indent}Returning new head: {second.data}")
            
            return second
        
        self.head = swap_pairs(self.head)
        print("Recursive pairwise swap completed!")
    
    def get_size(self):
        """Get the size of the list"""
        return self.size

def main():
    """Main function with interactive menu"""
    linked_list = LinkedList()
    
    print("=== Pairwise Swap in Single Linked List ===")
    print("This program demonstrates both iterative and recursive approaches")
    print("for swapping adjacent elements in a linked list.\n")
    print("Example: 1 -> 2 -> 3 -> 4 becomes 2 -> 1 -> 4 -> 3\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Insert element")
        print("2. Display list")
        print("3. Pairwise swap (Iterative)")
        print("4. Pairwise swap (Recursive)")
        print("5. Get list size")
        print("6. Create sample list")
        print("7. Exit")
        
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
                    linked_list.pairwise_swap_iterative()
                    print("List after iterative pairwise swap:")
                    linked_list.display()
                    
            elif choice == 4:
                if not linked_list.head:
                    print("List is empty! Add some elements first.")
                else:
                    print("Original list:")
                    linked_list.display()
                    linked_list.pairwise_swap_recursive()
                    print("List after recursive pairwise swap:")
                    linked_list.display()
                    
            elif choice == 5:
                print(f"List size: {linked_list.get_size()}")
                
            elif choice == 6:
                linked_list = LinkedList()
                for i in range(1, 6):
                    linked_list.insert_at_end(i)
                print("Sample list created: 1 -> 2 -> 3 -> 4 -> 5")
                linked_list.display()
                
            elif choice == 7:
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
class Node:
    """Node class for single linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """Single Linked List implementation"""
    def __init__(self):
        self.head = None
        self.size = 0
    
    def insert_sorted(self, data):
        """Insert element in sorted order"""
        new_node = Node(data)
        
        # If list is empty or new data is smaller than head
        if not self.head or data < self.head.data:
            new_node.next = self.head
            self.head = new_node
        else:
            current = self.head
            while current.next and current.next.data < data:
                current = current.next
            new_node.next = current.next
            current.next = new_node
        
        self.size += 1
        print(f"Element {data} inserted in sorted order!")
    
    def display(self):
        """Display the linked list"""
        if not self.head:
            print("List is empty!")
            return
        
        elements = []
        current = self.head
        while current:
            elements.append(str(current.data))
            current = current.next
        print(" -> ".join(elements) + " -> NULL")
    
    def get_size(self):
        """Get the size of the list"""
        return self.size

def merge_iterative(list1_head, list2_head):
    """
    Algorithm for Iterative Merge:
    1. Create a dummy node to simplify edge cases
    2. Use a tail pointer to build the result list
    3. Compare nodes from both lists and add smaller one to result
    4. Move the pointer of the list from which node was taken
    5. Continue until one list is exhausted
    6. Append remaining nodes from the other list
    """
    print("\n=== Iterative Merge Process ===")
    print("Algorithm: Compare nodes and build result list iteratively")
    
    # Create dummy node
    dummy = Node(0)
    tail = dummy
    step = 1
    
    print("Step-by-step merging process:")
    
    while list1_head and list2_head:
        print(f"Step {step}: Comparing {list1_head.data} and {list2_head.data}")
        
        if list1_head.data <= list2_head.data:
            print(f"         {list1_head.data} is smaller, adding to result")
            tail.next = list1_head
            list1_head = list1_head.next
        else:
            print(f"         {list2_head.data} is smaller, adding to result")
            tail.next = list2_head
            list2_head = list2_head.next
        
        tail = tail.next
        step += 1
        print()
    
    # Append remaining nodes
    if list1_head:
        print("Appending remaining nodes from list 1")
        tail.next = list1_head
    elif list2_head:
        print("Appending remaining nodes from list 2")
        tail.next = list2_head
    
    print("Iterative merge completed!")
    return dummy.next

def merge_recursive(list1_head, list2_head, depth=0):
    """
    Algorithm for Recursive Merge:
    1. Base cases: if one list is empty, return the other
    2. Compare the first nodes of both lists
    3. Choose the smaller one and recursively merge the rest
    4. Return the chosen node with its next pointing to merged result
    """
    indent = "  " * depth
    print(f"{indent}Recursive merge call:")
    print(f"{indent}List1: {list1_head.data if list1_head else 'NULL'}")
    print(f"{indent}List2: {list2_head.data if list2_head else 'NULL'}")
    
    # Base cases
    if not list1_head:
        print(f"{indent}List1 is empty, returning List2")
        return list2_head
    if not list2_head:
        print(f"{indent}List2 is empty, returning List1")
        return list1_head
    
    # Recursive case
    if list1_head.data <= list2_head.data:
        print(f"{indent}{list1_head.data} <= {list2_head.data}, choosing from List1")
        list1_head.next = merge_recursive(list1_head.next, list2_head, depth + 1)
        print(f"{indent}Returning node with data: {list1_head.data}")
        return list1_head
    else:
        print(f"{indent}{list2_head.data} < {list1_head.data}, choosing from List2")
        list2_head.next = merge_recursive(list1_head, list2_head.next, depth + 1)
        print(f"{indent}Returning node with data: {list2_head.data}")
        return list2_head

def copy_list(head):
    """Create a copy of the linked list"""
    if not head:
        return None
    
    new_head = Node(head.data)
    current_new = new_head
    current_old = head.next
    
    while current_old:
        current_new.next = Node(current_old.data)
        current_new = current_new.next
        current_old = current_old.next
    
    return new_head

def display_list(head, name="List"):
    """Display a linked list given its head"""
    if not head:
        print(f"{name}: Empty")
        return
    
    elements = []
    current = head
    while current:
        elements.append(str(current.data))
        current = current.next
    print(f"{name}: " + " -> ".join(elements) + " -> NULL")

def main():
    """Main function with interactive menu"""
    list1 = LinkedList()
    list2 = LinkedList()
    
    print("=== Merge Two Sorted Linked Lists ===")
    print("This program demonstrates both iterative and recursive approaches")
    print("for merging two sorted linked lists.\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Insert into List 1 (sorted)")
        print("2. Insert into List 2 (sorted)")
        print("3. Display both lists")
        print("4. Merge lists (Iterative)")
        print("5. Merge lists (Recursive)")
        print("6. Clear lists")
        print("7. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                data = int(input("Enter data for List 1: "))
                list1.insert_sorted(data)
                
            elif choice == 2:
                data = int(input("Enter data for List 2: "))
                list2.insert_sorted(data)
                
            elif choice == 3:
                print("\nCurrent Lists:")
                print("List 1: ", end="")
                list1.display()
                print("List 2: ", end="")
                list2.display()
                print(f"List 1 size: {list1.get_size()}")
                print(f"List 2 size: {list2.get_size()}")
                
            elif choice == 4:
                if not list1.head and not list2.head:
                    print("Both lists are empty!")
                else:
                    print("\n=== Iterative Merge ===")
                    print("Original Lists:")
                    display_list(list1.head, "List 1")
                    display_list(list2.head, "List 2")
                    
                    # Create copies to preserve original lists
                    list1_copy = copy_list(list1.head)
                    list2_copy = copy_list(list2.head)
                    
                    merged_head = merge_iterative(list1_copy, list2_copy)
                    print("\nMerged List:")
                    display_list(merged_head, "Result")
                    
            elif choice == 5:
                if not list1.head and not list2.head:
                    print("Both lists are empty!")
                else:
                    print("\n=== Recursive Merge ===")
                    print("Original Lists:")
                    display_list(list1.head, "List 1")
                    display_list(list2.head, "List 2")
                    print("\nRecursive merge process:")
                    
                    # Create copies to preserve original lists
                    list1_copy = copy_list(list1.head)
                    list2_copy = copy_list(list2.head)
                    
                    merged_head = merge_recursive(list1_copy, list2_copy)
                    print("\nMerged List:")
                    display_list(merged_head, "Result")
                    
            elif choice == 6:
                list1 = LinkedList()
                list2 = LinkedList()
                print("Both lists cleared!")
                
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
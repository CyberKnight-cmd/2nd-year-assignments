class Node:
    """
    Node class for single linked list
    """
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """
    Complete Single Linked List implementation with all operations
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
    
    # INSERT OPERATIONS
    
    def insertAtFirst(self, data):
        """
        Insert node at the beginning of the list
        """
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        print(f"Inserted {data} at the beginning")
    
    def insertAtLast(self, data):
        """
        Insert node at the end of the list
        """
        new_node = Node(data)
        
        if self.head is None:
            self.head = new_node
            print(f"Inserted {data} as the first node")
            return
        
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        
        temp.next = new_node
        print(f"Inserted {data} at the end")
    
    def insertAtAny(self, data, position):
        """
        Insert node at any position in the list
        """
        if position < 1:
            print("Invalid position! Position should be >= 1")
            return
        
        if position == 1:
            self.insertAtFirst(data)
            return
        
        new_node = Node(data)
        temp = self.head
        
        for i in range(1, position - 1):
            if temp is None:
                break
            temp = temp.next
        
        if temp is None:
            print(f"Position {position} is beyond the list. Inserting at the end.")
            self.insertAtLast(data)
            return
        
        new_node.next = temp.next
        temp.next = new_node
        print(f"Inserted {data} at position {position}")
    
    # DELETE OPERATIONS
    
    def deleteFromFirst(self):
        """
        Delete node from the beginning of the list
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
        """
        if self.head is None:
            print("List is empty! Cannot delete from last.")
            return None
        
        if self.head.next is None:
            deleted_data = self.head.data
            self.head = None
            print(f"Deleted {deleted_data} from the end")
            return deleted_data
        
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
        """
        if self.head is None:
            print(f"List is empty! Cannot delete from position {position}.")
            return None
        
        if position < 1:
            print("Invalid position! Position should be >= 1")
            return None
        
        if position == 1:
            return self.deleteFromFirst()
        
        temp = self.head
        for i in range(1, position - 1):
            if temp is None or temp.next is None:
                break
            temp = temp.next
        
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
        """
        if self.head is None:
            print(f"List is empty! Cannot delete value {value}.")
            return False
        
        if self.head.data == value:
            self.head = self.head.next
            print(f"Deleted value {value} from the beginning")
            return True
        
        temp = self.head
        while temp.next is not None:
            if temp.next.data == value:
                temp.next = temp.next.next
                print(f"Deleted value {value} from the list")
                return True
            temp = temp.next
        
        print(f"Value {value} not found in the list")
        return False
    
    # UTILITY OPERATIONS
    
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
        """
        return self.head is None
    
    def search(self, value):
        """
        Search for a value in the list
        """
        temp = self.head
        position = 1
        
        while temp is not None:
            if temp.data == value:
                return position
            temp = temp.next
            position += 1
        
        return -1
    
    def getNodeAtPosition(self, position):
        """
        Get data at specific position
        """
        if position < 1:
            return None
        
        temp = self.head
        for i in range(1, position):
            if temp is None:
                return None
            temp = temp.next
        
        return temp.data if temp else None
    
    def reverse(self):
        """
        Reverse the linked list
        """
        prev = None
        current = self.head
        
        while current is not None:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        
        self.head = prev
        print("List reversed successfully")
    
    def clear(self):
        """
        Clear the entire list
        """
        self.head = None
        print("List cleared successfully")
    
    def toList(self):
        """
        Convert linked list to Python list
        """
        result = []
        temp = self.head
        while temp is not None:
            result.append(temp.data)
            temp = temp.next
        return result
    
    def fromList(self, data_list):
        """
        Create linked list from Python list
        """
        self.clear()
        for data in data_list:
            self.insertAtLast(data)
        print(f"Created linked list from list: {data_list}")

def display_menu():
    """
    Display the menu options
    """
    print("\n=== Complete Single Linked List Operations ===")
    print("1.  Insert at First")
    print("2.  Insert at Last")
    print("3.  Insert at Any Position")
    print("4.  Delete from First")
    print("5.  Delete from Last")
    print("6.  Delete from Any Position")
    print("7.  Delete by Value")
    print("8.  Display List")
    print("9.  Count Nodes")
    print("10. Search Value")
    print("11. Get Node at Position")
    print("12. Reverse List")
    print("13. Clear List")
    print("14. Convert to Python List")
    print("15. Create from Python List")
    print("16. Exit")
    print("Enter your choice: ", end="")

def main():
    """
    Main function with interactive menu
    """
    ll = LinkedList()
    ll.createList()
    
    while True:
        display_menu()
        
        try:
            choice = int(input())
            
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
                ll.deleteFromFirst()
            
            elif choice == 5:
                ll.deleteFromLast()
            
            elif choice == 6:
                position = int(input("Enter position to delete (1-based): "))
                ll.deleteFromAny(position)
            
            elif choice == 7:
                value = int(input("Enter value to delete: "))
                ll.deleteByValue(value)
            
            elif choice == 8:
                ll.displayList()
            
            elif choice == 9:
                print(f"Number of nodes: {ll.countNodes()}")
            
            elif choice == 10:
                value = int(input("Enter value to search: "))
                position = ll.search(value)
                if position != -1:
                    print(f"Value {value} found at position {position}")
                else:
                    print(f"Value {value} not found")
            
            elif choice == 11:
                position = int(input("Enter position to get data (1-based): "))
                data = ll.getNodeAtPosition(position)
                if data is not None:
                    print(f"Data at position {position}: {data}")
                else:
                    print(f"No data at position {position}")
            
            elif choice == 12:
                ll.reverse()
            
            elif choice == 13:
                ll.clear()
            
            elif choice == 14:
                python_list = ll.toList()
                print(f"Python list: {python_list}")
            
            elif choice == 15:
                input_str = input("Enter numbers separated by spaces: ")
                try:
                    data_list = [int(x) for x in input_str.split()]
                    ll.fromList(data_list)
                except ValueError:
                    print("Please enter valid integers separated by spaces")
            
            elif choice == 16:
                print("Exiting...")
                break
            
            else:
                print("Invalid choice! Please try again.")
        
        except ValueError:
            print("Please enter a valid number!")
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    main()
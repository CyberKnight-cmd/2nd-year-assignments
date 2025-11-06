class Node:
    """
    Node class for single linked list
    """
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """
    Linked List with various node counting functions
    """
    
    def __init__(self):
        """
        Initialize empty linked list
        """
        self.head = None
    
    def insertAtEnd(self, data):
        """
        Insert node at the end of the list
        
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
        Count total number of nodes - Iterative approach
        
        Returns:
            int: Number of nodes
        """
        count = 0
        temp = self.head
        
        print("Counting nodes iteratively:")
        while temp is not None:
            count += 1
            print(f"Node {count}: {temp.data}")
            temp = temp.next
        
        return count
    
    def countNodesRecursive(self, node=None):
        """
        Count total number of nodes - Recursive approach
        
        Args:
            node: Current node (None means start from head)
            
        Returns:
            int: Number of nodes
        """
        # If first call, start from head
        if node is None:
            node = self.head
        
        # Base case
        if node is None:
            return 0
        
        # Recursive case
        return 1 + self.countNodesRecursive(node.next)
    
    def countNodesWithValue(self, value):
        """
        Count nodes with specific value
        
        Args:
            value: Value to count
            
        Returns:
            int: Number of nodes with the value
        """
        count = 0
        temp = self.head
        position = 1
        
        print(f"Counting nodes with value {value}:")
        while temp is not None:
            if temp.data == value:
                count += 1
                print(f"Found at position {position}")
            temp = temp.next
            position += 1
        
        return count
    
    def countEvenOddNodes(self):
        """
        Count even and odd valued nodes
        
        Returns:
            tuple: (even_count, odd_count)
        """
        even_count = 0
        odd_count = 0
        temp = self.head
        
        print("Analyzing even and odd values:")
        while temp is not None:
            if temp.data % 2 == 0:
                even_count += 1
                print(f"{temp.data} is even")
            else:
                odd_count += 1
                print(f"{temp.data} is odd")
            temp = temp.next
        
        return even_count, odd_count
    
    def countNodesInRange(self, min_val, max_val):
        """
        Count nodes with values in specified range
        
        Args:
            min_val: Minimum value (inclusive)
            max_val: Maximum value (inclusive)
            
        Returns:
            int: Number of nodes in range
        """
        count = 0
        temp = self.head
        
        print(f"Counting nodes with values between {min_val} and {max_val}:")
        while temp is not None:
            if min_val <= temp.data <= max_val:
                count += 1
                print(f"Node with value {temp.data} is in range")
            temp = temp.next
        
        return count
    
    def countPositiveNegativeNodes(self):
        """
        Count positive and negative valued nodes
        
        Returns:
            tuple: (positive_count, negative_count, zero_count)
        """
        positive_count = 0
        negative_count = 0
        zero_count = 0
        temp = self.head
        
        print("Analyzing positive, negative, and zero values:")
        while temp is not None:
            if temp.data > 0:
                positive_count += 1
                print(f"{temp.data} is positive")
            elif temp.data < 0:
                negative_count += 1
                print(f"{temp.data} is negative")
            else:
                zero_count += 1
                print(f"{temp.data} is zero")
            temp = temp.next
        
        return positive_count, negative_count, zero_count
    
    def countNodesByCondition(self, condition_func, description=""):
        """
        Count nodes based on custom condition
        
        Args:
            condition_func: Function that takes data and returns boolean
            description: Description of the condition
            
        Returns:
            int: Number of nodes satisfying condition
        """
        count = 0
        temp = self.head
        
        if description:
            print(f"Counting nodes {description}:")
        
        while temp is not None:
            if condition_func(temp.data):
                count += 1
                if description:
                    print(f"Node with value {temp.data} satisfies condition")
            temp = temp.next
        
        return count
    
    def getNodeStatistics(self):
        """
        Get comprehensive statistics about nodes
        
        Returns:
            dict: Dictionary with various statistics
        """
        if self.head is None:
            return {"total": 0, "min": None, "max": None, "sum": 0, "avg": 0}
        
        total = 0
        min_val = self.head.data
        max_val = self.head.data
        sum_val = 0
        temp = self.head
        
        while temp is not None:
            total += 1
            sum_val += temp.data
            min_val = min(min_val, temp.data)
            max_val = max(max_val, temp.data)
            temp = temp.next
        
        avg_val = sum_val / total if total > 0 else 0
        
        return {
            "total": total,
            "min": min_val,
            "max": max_val,
            "sum": sum_val,
            "avg": avg_val
        }
    
    def clear(self):
        """
        Clear the list
        """
        self.head = None
        print("List cleared successfully")

def demonstrate_counting():
    """
    Demonstrate various counting functions
    """
    print("=== Node Counting Functions Demonstration ===")
    
    ll = LinkedList()
    
    # Create sample list
    sample_data = [10, -5, 20, 10, 30, -5, 15, 0, 25, 10]
    print(f"Creating list with data: {sample_data}")
    
    for data in sample_data:
        ll.insertAtEnd(data)
    
    ll.displayList()
    
    # Test different counting methods
    print(f"\n1. Total nodes (iterative): {ll.countNodes()}")
    print(f"2. Total nodes (recursive): {ll.countNodesRecursive()}")
    
    print(f"\n3. Nodes with value 10: {ll.countNodesWithValue(10)}")
    
    even_count, odd_count = ll.countEvenOddNodes()
    print(f"\n4. Even nodes: {even_count}, Odd nodes: {odd_count}")
    
    range_count = ll.countNodesInRange(10, 25)
    print(f"\n5. Nodes in range [10, 25]: {range_count}")
    
    pos_count, neg_count, zero_count = ll.countPositiveNegativeNodes()
    print(f"\n6. Positive: {pos_count}, Negative: {neg_count}, Zero: {zero_count}")
    
    # Custom condition examples
    print(f"\n7. Custom conditions:")
    divisible_by_5 = ll.countNodesByCondition(lambda x: x % 5 == 0, "divisible by 5")
    print(f"Nodes divisible by 5: {divisible_by_5}")
    
    greater_than_15 = ll.countNodesByCondition(lambda x: x > 15, "greater than 15")
    print(f"Nodes greater than 15: {greater_than_15}")
    
    # Statistics
    stats = ll.getNodeStatistics()
    print(f"\n8. Node statistics: {stats}")

def interactive_counting():
    """
    Interactive counting operations
    """
    print("\n=== Interactive Node Counting ===")
    
    ll = LinkedList()
    
    while True:
        print("\n--- Menu ---")
        print("1. Insert Node")
        print("2. Display List")
        print("3. Count Total Nodes (Iterative)")
        print("4. Count Total Nodes (Recursive)")
        print("5. Count Nodes with Specific Value")
        print("6. Count Even and Odd Nodes")
        print("7. Count Nodes in Range")
        print("8. Count Positive/Negative/Zero Nodes")
        print("9. Count Nodes with Custom Condition")
        print("10. Get Node Statistics")
        print("11. Create Sample List")
        print("12. Clear List")
        print("13. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                data = int(input("Enter data to insert: "))
                ll.insertAtEnd(data)
                print(f"Inserted {data} into the list")
            
            elif choice == 2:
                ll.displayList()
            
            elif choice == 3:
                result = ll.countNodes()
                print(f"Total number of nodes (iterative): {result}")
            
            elif choice == 4:
                result = ll.countNodesRecursive()
                print(f"Total number of nodes (recursive): {result}")
            
            elif choice == 5:
                value = int(input("Enter value to count: "))
                result = ll.countNodesWithValue(value)
                print(f"Number of nodes with value {value}: {result}")
            
            elif choice == 6:
                even_count, odd_count = ll.countEvenOddNodes()
                print(f"Even nodes: {even_count}, Odd nodes: {odd_count}")
            
            elif choice == 7:
                min_val = int(input("Enter minimum value: "))
                max_val = int(input("Enter maximum value: "))
                result = ll.countNodesInRange(min_val, max_val)
                print(f"Number of nodes in range [{min_val}, {max_val}]: {result}")
            
            elif choice == 8:
                pos_count, neg_count, zero_count = ll.countPositiveNegativeNodes()
                print(f"Positive: {pos_count}, Negative: {neg_count}, Zero: {zero_count}")
            
            elif choice == 9:
                print("Available conditions:")
                print("1. Divisible by a number")
                print("2. Greater than a number")
                print("3. Less than a number")
                print("4. Perfect squares")
                
                cond_choice = int(input("Choose condition: "))
                
                if cond_choice == 1:
                    divisor = int(input("Enter divisor: "))
                    result = ll.countNodesByCondition(
                        lambda x: x % divisor == 0,
                        f"divisible by {divisor}"
                    )
                elif cond_choice == 2:
                    threshold = int(input("Enter threshold: "))
                    result = ll.countNodesByCondition(
                        lambda x: x > threshold,
                        f"greater than {threshold}"
                    )
                elif cond_choice == 3:
                    threshold = int(input("Enter threshold: "))
                    result = ll.countNodesByCondition(
                        lambda x: x < threshold,
                        f"less than {threshold}"
                    )
                elif cond_choice == 4:
                    result = ll.countNodesByCondition(
                        lambda x: x >= 0 and int(x**0.5)**2 == x,
                        "perfect squares"
                    )
                else:
                    print("Invalid condition choice")
                    continue
                
                print(f"Nodes satisfying condition: {result}")
            
            elif choice == 10:
                stats = ll.getNodeStatistics()
                print("Node Statistics:")
                for key, value in stats.items():
                    print(f"  {key.capitalize()}: {value}")
            
            elif choice == 11:
                ll.clear()
                sample_data = [10, -5, 20, 10, 30, -5, 15, 0, 25, 10]
                for data in sample_data:
                    ll.insertAtEnd(data)
                print(f"Created sample list: {sample_data}")
                ll.displayList()
            
            elif choice == 12:
                ll.clear()
            
            elif choice == 13:
                print("Exiting...")
                break
            
            else:
                print("Invalid choice! Please try again.")
        
        except ValueError:
            print("Please enter a valid number!")
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    # Run demonstration
    demonstrate_counting()
    
    # Run interactive mode
    interactive_counting()
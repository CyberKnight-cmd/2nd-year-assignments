class Node:
    """
    Node class for single linked list
    """
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """
    Linked List with odd/even number separation functionality
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
    
    def printOddEvenNumbers(self):
        """
        Print odd and even numbers separately from the list
        """
        if self.head is None:
            print("List is empty!")
            return
        
        print("\n=== Separating Odd and Even Numbers ===")
        
        # Collect odd numbers
        odd_numbers = []
        even_numbers = []
        temp = self.head
        
        while temp is not None:
            if temp.data % 2 == 0:
                even_numbers.append(temp.data)
            else:
                odd_numbers.append(temp.data)
            temp = temp.next
        
        # Print odd numbers
        print("Odd numbers: ", end="")
        if odd_numbers:
            print(" -> ".join(map(str, odd_numbers)) + " -> None")
        else:
            print("None")
        
        # Print even numbers
        print("Even numbers: ", end="")
        if even_numbers:
            print(" -> ".join(map(str, even_numbers)) + " -> None")
        else:
            print("None")
    
    def createOddEvenLists(self):
        """
        Create separate linked lists for odd and even numbers
        
        Returns:
            tuple: (odd_list, even_list) - Two separate LinkedList objects
        """
        odd_list = LinkedList()
        even_list = LinkedList()
        
        if self.head is None:
            print("Original list is empty!")
            return odd_list, even_list
        
        temp = self.head
        print("\nCreating separate lists for odd and even numbers:")
        
        while temp is not None:
            if temp.data % 2 == 0:
                even_list.insertAtEnd(temp.data)
                print(f"Added {temp.data} to even list")
            else:
                odd_list.insertAtEnd(temp.data)
                print(f"Added {temp.data} to odd list")
            temp = temp.next
        
        return odd_list, even_list
    
    def countOddEvenNumbers(self):
        """
        Count odd and even numbers in the list
        
        Returns:
            tuple: (odd_count, even_count)
        """
        if self.head is None:
            print("List is empty!")
            return 0, 0
        
        odd_count = 0
        even_count = 0
        temp = self.head
        
        print("\nCounting odd and even numbers:")
        
        while temp is not None:
            if temp.data % 2 == 0:
                even_count += 1
                print(f"{temp.data} is even (count: {even_count})")
            else:
                odd_count += 1
                print(f"{temp.data} is odd (count: {odd_count})")
            temp = temp.next
        
        print(f"\nSummary:")
        print(f"Total odd numbers: {odd_count}")
        print(f"Total even numbers: {even_count}")
        print(f"Total numbers: {odd_count + even_count}")
        
        return odd_count, even_count
    
    def printOddEvenPositions(self):
        """
        Print nodes at odd and even positions (1-based indexing)
        """
        if self.head is None:
            print("List is empty!")
            return
        
        print("\n=== Nodes at Odd and Even Positions ===")
        
        odd_position_nodes = []
        even_position_nodes = []
        temp = self.head
        position = 1
        
        while temp is not None:
            if position % 2 == 1:  # Odd position
                odd_position_nodes.append(temp.data)
            else:  # Even position
                even_position_nodes.append(temp.data)
            temp = temp.next
            position += 1
        
        # Print nodes at odd positions
        print("Nodes at odd positions (1st, 3rd, 5th, ...): ", end="")
        if odd_position_nodes:
            print(" -> ".join(map(str, odd_position_nodes)) + " -> None")
        else:
            print("None")
        
        # Print nodes at even positions
        print("Nodes at even positions (2nd, 4th, 6th, ...): ", end="")
        if even_position_nodes:
            print(" -> ".join(map(str, even_position_nodes)) + " -> None")
        else:
            print("None")
    
    def filterNumbers(self, condition_func, description=""):
        """
        Filter numbers based on custom condition
        
        Args:
            condition_func: Function that takes a number and returns boolean
            description: Description of the condition
            
        Returns:
            list: List of numbers satisfying the condition
        """
        filtered_numbers = []
        temp = self.head
        
        if description:
            print(f"\nFiltering numbers {description}:")
        
        while temp is not None:
            if condition_func(temp.data):
                filtered_numbers.append(temp.data)
                if description:
                    print(f"{temp.data} satisfies condition")
            temp = temp.next
        
        return filtered_numbers
    
    def getNumberStatistics(self):
        """
        Get statistics about odd and even numbers
        
        Returns:
            dict: Dictionary with statistics
        """
        if self.head is None:
            return {
                "total": 0, "odd_count": 0, "even_count": 0,
                "odd_sum": 0, "even_sum": 0, "odd_avg": 0, "even_avg": 0
            }
        
        odd_numbers = []
        even_numbers = []
        temp = self.head
        
        while temp is not None:
            if temp.data % 2 == 0:
                even_numbers.append(temp.data)
            else:
                odd_numbers.append(temp.data)
            temp = temp.next
        
        odd_sum = sum(odd_numbers) if odd_numbers else 0
        even_sum = sum(even_numbers) if even_numbers else 0
        odd_avg = odd_sum / len(odd_numbers) if odd_numbers else 0
        even_avg = even_sum / len(even_numbers) if even_numbers else 0
        
        return {
            "total": len(odd_numbers) + len(even_numbers),
            "odd_count": len(odd_numbers),
            "even_count": len(even_numbers),
            "odd_sum": odd_sum,
            "even_sum": even_sum,
            "odd_avg": odd_avg,
            "even_avg": even_avg,
            "odd_numbers": odd_numbers,
            "even_numbers": even_numbers
        }
    
    def clear(self):
        """
        Clear the list
        """
        self.head = None
        print("List cleared successfully")

def demonstrate_odd_even_separation():
    """
    Demonstrate odd/even number separation
    """
    print("=== Odd and Even Number Separation Demonstration ===")
    
    ll = LinkedList()
    
    # Create sample list with mixed odd and even numbers
    sample_data = [12, 7, 18, 3, 24, 9, 15, 6, 11, 20]
    print(f"Creating list with data: {sample_data}")
    
    for data in sample_data:
        ll.insertAtEnd(data)
    
    print("\nOriginal List:")
    ll.displayList()
    
    # Test different separation methods
    print("\n1. Print odd and even numbers separately:")
    ll.printOddEvenNumbers()
    
    print("\n2. Count odd and even numbers:")
    odd_count, even_count = ll.countOddEvenNumbers()
    
    print("\n3. Create separate lists:")
    odd_list, even_list = ll.createOddEvenLists()
    print("\nSeparate Lists Created:")
    print("Odd List: ", end="")
    odd_list.displayList()
    print("Even List: ", end="")
    even_list.displayList()
    
    print("\n4. Nodes at odd and even positions:")
    ll.printOddEvenPositions()
    
    # Get statistics
    stats = ll.getNumberStatistics()
    print(f"\n5. Number statistics:")
    print(f"   Total numbers: {stats['total']}")
    print(f"   Odd numbers: {stats['odd_count']} (sum: {stats['odd_sum']}, avg: {stats['odd_avg']:.2f})")
    print(f"   Even numbers: {stats['even_count']} (sum: {stats['even_sum']}, avg: {stats['even_avg']:.2f})")

def interactive_odd_even_operations():
    """
    Interactive odd/even operations
    """
    print("\n=== Interactive Odd/Even Operations ===")
    
    ll = LinkedList()
    
    while True:
        print("\n--- Menu ---")
        print("1. Insert Node")
        print("2. Display List")
        print("3. Print Odd and Even Numbers Separately")
        print("4. Count Odd and Even Numbers")
        print("5. Create Separate Odd and Even Lists")
        print("6. Print Nodes at Odd and Even Positions")
        print("7. Filter Numbers by Custom Condition")
        print("8. Get Number Statistics")
        print("9. Create Sample List")
        print("10. Clear List")
        print("11. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                data = int(input("Enter data to insert: "))
                ll.insertAtEnd(data)
                print(f"Inserted {data} into the list")
            
            elif choice == 2:
                print("\nCurrent List:")
                ll.displayList()
            
            elif choice == 3:
                ll.printOddEvenNumbers()
            
            elif choice == 4:
                ll.countOddEvenNumbers()
            
            elif choice == 5:
                odd_list, even_list = ll.createOddEvenLists()
                print("\nSeparate Lists Created:")
                print("Odd List: ", end="")
                odd_list.displayList()
                print("Even List: ", end="")
                even_list.displayList()
            
            elif choice == 6:
                ll.printOddEvenPositions()
            
            elif choice == 7:
                print("Available filters:")
                print("1. Divisible by a number")
                print("2. Greater than a number")
                print("3. Prime numbers")
                print("4. Perfect squares")
                
                filter_choice = int(input("Choose filter: "))
                
                if filter_choice == 1:
                    divisor = int(input("Enter divisor: "))
                    filtered = ll.filterNumbers(
                        lambda x: x % divisor == 0,
                        f"divisible by {divisor}"
                    )
                elif filter_choice == 2:
                    threshold = int(input("Enter threshold: "))
                    filtered = ll.filterNumbers(
                        lambda x: x > threshold,
                        f"greater than {threshold}"
                    )
                elif filter_choice == 3:
                    def is_prime(n):
                        if n < 2:
                            return False
                        for i in range(2, int(n**0.5) + 1):
                            if n % i == 0:
                                return False
                        return True
                    
                    filtered = ll.filterNumbers(is_prime, "prime numbers")
                elif filter_choice == 4:
                    filtered = ll.filterNumbers(
                        lambda x: x >= 0 and int(x**0.5)**2 == x,
                        "perfect squares"
                    )
                else:
                    print("Invalid filter choice")
                    continue
                
                print(f"Filtered numbers: {filtered}")
            
            elif choice == 8:
                stats = ll.getNumberStatistics()
                print("\nNumber Statistics:")
                for key, value in stats.items():
                    if key not in ['odd_numbers', 'even_numbers']:
                        print(f"  {key.replace('_', ' ').title()}: {value}")
            
            elif choice == 9:
                ll.clear()
                sample_data = [12, 7, 18, 3, 24, 9, 15, 6, 11, 20]
                for data in sample_data:
                    ll.insertAtEnd(data)
                print(f"Created sample list: {sample_data}")
                ll.displayList()
            
            elif choice == 10:
                ll.clear()
            
            elif choice == 11:
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
    Test edge cases for odd/even operations
    """
    print("\n=== Testing Edge Cases ===")
    
    # Test empty list
    print("\n1. Empty list:")
    empty_list = LinkedList()
    empty_list.printOddEvenNumbers()
    empty_list.countOddEvenNumbers()
    
    # Test single node (odd)
    print("\n2. Single odd node:")
    single_odd = LinkedList()
    single_odd.insertAtEnd(7)
    single_odd.displayList()
    single_odd.printOddEvenNumbers()
    
    # Test single node (even)
    print("\n3. Single even node:")
    single_even = LinkedList()
    single_even.insertAtEnd(8)
    single_even.displayList()
    single_even.printOddEvenNumbers()
    
    # Test all odd numbers
    print("\n4. All odd numbers:")
    all_odd = LinkedList()
    for num in [1, 3, 5, 7, 9]:
        all_odd.insertAtEnd(num)
    all_odd.displayList()
    all_odd.printOddEvenNumbers()
    
    # Test all even numbers
    print("\n5. All even numbers:")
    all_even = LinkedList()
    for num in [2, 4, 6, 8, 10]:
        all_even.insertAtEnd(num)
    all_even.displayList()
    all_even.printOddEvenNumbers()

if __name__ == "__main__":
    # Run demonstration
    demonstrate_odd_even_separation()
    
    # Test edge cases
    test_edge_cases()
    
    # Run interactive mode
    interactive_odd_even_operations()
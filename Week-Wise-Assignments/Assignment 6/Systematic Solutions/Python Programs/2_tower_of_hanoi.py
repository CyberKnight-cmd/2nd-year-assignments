class Stack:
    """Stack implementation for Tower of Hanoi"""
    def __init__(self, name):
        self.items = []
        self.name = name
    
    def is_empty(self):
        return len(self.items) == 0
    
    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        if self.is_empty():
            return None
        return self.items.pop()
    
    def peek(self):
        if self.is_empty():
            return None
        return self.items[-1]
    
    def size(self):
        return len(self.items)
    
    def display(self):
        if self.is_empty():
            return f"Tower {self.name}: Empty"
        else:
            return f"Tower {self.name}: Bottom -> {' '.join(map(str, self.items))} <- Top"

def display_towers(source, auxiliary, destination):
    """Display all three towers"""
    print("\n=== Current State of Towers ===")
    print(source.display())
    print(auxiliary.display())
    print(destination.display())
    print("================================")

def visualize_towers(towers, n):
    """Visual representation of towers"""
    print("\nVisual Representation:")
    
    # Print from top to bottom
    max_height = max(len(tower.items) for tower in towers)
    
    for level in range(max_height - 1, -1, -1):
        for tower in towers:
            print("  ", end="")
            if len(tower.items) > level:
                disk = tower.items[level]
                # Print disk with visual representation
                spaces = " " * (n - disk)
                stars = "*" * (disk * 2 + 1)
                print(f"{spaces}{stars}{spaces}", end="")
            else:
                # Print empty space with pole
                spaces = " " * n
                print(f"{spaces}|{spaces}", end="")
            print("    ", end="")
        print()
    
    # Print base
    for tower in towers:
        print("  ", end="")
        print("-" * (n * 2 + 1), end="")
        print("    ", end="")
    print()
    
    # Print tower labels
    for tower in towers:
        print(f"    {tower.name}", end="")
        print(" " * (n * 2 - 1), end="")
        print("      ", end="")
    print()

def move_disk(from_tower, to_tower, move_count):
    """Move disk from one tower to another"""
    if from_tower.is_empty():
        print(f"Error: Cannot move from empty tower {from_tower.name}")
        return False
    
    disk = from_tower.pop()
    
    if not to_tower.is_empty() and to_tower.peek() < disk:
        print(f"Error: Cannot place larger disk {disk} on smaller disk {to_tower.peek()}")
        from_tower.push(disk)  # Put it back
        return False
    
    to_tower.push(disk)
    move_count[0] += 1
    print(f"Move {move_count[0]}: Moved disk {disk} from Tower {from_tower.name} to Tower {to_tower.name}")
    return True

def tower_of_hanoi_stack(n, source, auxiliary, destination):
    """
    Algorithm for Tower of Hanoi using Stack:
    1. Use three stacks to represent the three towers
    2. Implement the recursive algorithm iteratively using explicit stack operations
    3. For n disks: move n-1 disks to auxiliary, move largest to destination, move n-1 from auxiliary to destination
    """
    print(f"\n=== Tower of Hanoi Solution using Stacks ===")
    print(f"Number of disks: {n}")
    print(f"Source: Tower {source.name}, Auxiliary: Tower {auxiliary.name}, Destination: Tower {destination.name}")
    print("Algorithm: Use stacks to simulate the three towers\n")
    
    # Initialize source tower with disks (largest at bottom)
    for i in range(n, 0, -1):
        source.push(i)
    
    print("Initial setup:")
    towers = [source, auxiliary, destination]
    if n <= 4:
        visualize_towers(towers, n)
    else:
        display_towers(source, auxiliary, destination)
    
    total_moves = (2 ** n) - 1
    move_count = [0]
    
    print(f"\nTotal moves required: {total_moves}")
    print("Starting solution...\n")
    
    # For even number of disks, swap auxiliary and destination
    if n % 2 == 0:
        auxiliary, destination = destination, auxiliary
        towers[1], towers[2] = towers[2], towers[1]
    
    # Iterative solution using the pattern
    for i in range(1, total_moves + 1):
        if i % 3 == 1:
            # Move between source and destination
            if (source.is_empty() or 
                (not destination.is_empty() and source.peek() > destination.peek())):
                move_disk(destination, source, move_count)
            else:
                move_disk(source, destination, move_count)
        elif i % 3 == 2:
            # Move between source and auxiliary
            if (source.is_empty() or 
                (not auxiliary.is_empty() and source.peek() > auxiliary.peek())):
                move_disk(auxiliary, source, move_count)
            else:
                move_disk(source, auxiliary, move_count)
        else:
            # Move between auxiliary and destination
            if (auxiliary.is_empty() or 
                (not destination.is_empty() and auxiliary.peek() > destination.peek())):
                move_disk(destination, auxiliary, move_count)
            else:
                move_disk(auxiliary, destination, move_count)
        
        # Display state after each move
        if n <= 3:  # Only show visual for small numbers
            visualize_towers(towers, n)
            input("Press Enter to continue...")
        elif n <= 5:
            display_towers(source, auxiliary, destination)
            print()
    
    print(f"Solution completed! All disks moved to Tower {destination.name}")
    print(f"Total moves made: {move_count[0]}")

def tower_of_hanoi_recursive(n, source, auxiliary, destination, move_count):
    """Recursive solution for comparison"""
    if n == 1:
        move_count[0] += 1
        print(f"Move {move_count[0]}: Move disk 1 from {source} to {destination}")
        return
    
    tower_of_hanoi_recursive(n - 1, source, destination, auxiliary, move_count)
    move_count[0] += 1
    print(f"Move {move_count[0]}: Move disk {n} from {source} to {destination}")
    tower_of_hanoi_recursive(n - 1, auxiliary, source, destination, move_count)

def main():
    """Main function with interactive menu"""
    print("=== Tower of Hanoi using Stacks ===")
    print("This program solves the Tower of Hanoi puzzle using stack data structure")
    print("Three stacks represent the three towers (rods)")
    print("Goal: Move all disks from source to destination tower\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Solve Tower of Hanoi using stacks")
        print("2. Compare with recursive solution")
        print("3. Show algorithm explanation")
        print("4. Show complexity analysis")
        print("5. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                n = int(input("Enter number of disks (recommended: 3-5 for visualization): "))
                
                if n <= 0:
                    print("Number of disks must be positive!")
                    continue
                
                if n > 10:
                    cont = input("Warning: Large numbers will generate many moves! Continue? (y/n): ")
                    if cont.lower() != 'y':
                        continue
                
                source = Stack('A')
                auxiliary = Stack('B')
                destination = Stack('C')
                
                tower_of_hanoi_stack(n, source, auxiliary, destination)
                
            elif choice == 2:
                n = int(input("Enter number of disks for recursive comparison: "))
                
                if n <= 0:
                    print("Number of disks must be positive!")
                    continue
                
                print(f"\n=== Recursive Solution ===")
                move_count = [0]
                tower_of_hanoi_recursive(n, 'A', 'B', 'C', move_count)
                print(f"Total moves: {move_count[0]}")
                
            elif choice == 3:
                print(f"\n=== Algorithm Explanation ===")
                print("Tower of Hanoi Rules:")
                print("1. Only one disk can be moved at a time")
                print("2. Only the top disk from a tower can be moved")
                print("3. A larger disk cannot be placed on a smaller disk\n")
                
                print("Stack-based Approach:")
                print("1. Use three stacks to represent the three towers")
                print("2. Implement iterative solution using the pattern:")
                print("   - For odd n: alternate between (source,destination) and (source,auxiliary) and (auxiliary,destination)")
                print("   - For even n: swap auxiliary and destination in the pattern")
                print("3. Always move the smaller disk onto the larger disk\n")
                
                print("Why Stacks Work:")
                print("- LIFO property ensures only top disk is accessible")
                print("- Natural representation of the tower structure")
                print("- Easy to check validity of moves")
                
            elif choice == 4:
                print(f"\n=== Complexity Analysis ===")
                print("Time Complexity: O(2^n)")
                print("Space Complexity: O(n) for the stacks")
                print("Number of moves: 2^n - 1\n")
                
                print("Move count for different values of n:")
                print("n\tMoves\tTime (if 1 move/second)")
                print("---\t-----\t--------------------")
                for i in range(1, 11):
                    moves = (2 ** i) - 1
                    print(f"{i}\t{moves}\t", end="")
                    if moves < 60:
                        print(f"{moves} seconds")
                    elif moves < 3600:
                        print(f"{moves / 60:.1f} minutes")
                    else:
                        print(f"{moves / 3600:.1f} hours")
                        
            elif choice == 5:
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
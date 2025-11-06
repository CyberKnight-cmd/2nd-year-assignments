import math
from collections import deque

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None
    
    def insert(self, data):
        """Insert a node into BST"""
        self.root = self._insert_recursive(self.root, data)
    
    def _insert_recursive(self, root, data):
        if root is None:
            return TreeNode(data)
        
        if data < root.data:
            root.left = self._insert_recursive(root.left, data)
        elif data > root.data:
            root.right = self._insert_recursive(root.right, data)
        else:
            print(f"Duplicate value {data} not inserted")
        
        return root
    
    def delete(self, data):
        """Delete a node from BST"""
        self.root = self._delete_recursive(self.root, data)
    
    def _delete_recursive(self, root, data):
        if root is None:
            print(f"Node {data} not found")
            return root
        
        if data < root.data:
            root.left = self._delete_recursive(root.left, data)
        elif data > root.data:
            root.right = self._delete_recursive(root.right, data)
        else:
            # Node to be deleted found
            if root.left is None:
                print(f"Node {data} deleted")
                return root.right
            elif root.right is None:
                print(f"Node {data} deleted")
                return root.left
            
            # Node with two children
            min_node = self._find_min(root.right)
            root.data = min_node.data
            root.right = self._delete_recursive(root.right, min_node.data)
            print(f"Node {data} deleted")
        
        return root
    
    def search(self, key):
        """Search for a key in BST"""
        return self._search_recursive(self.root, key)
    
    def _search_recursive(self, root, key):
        if root is None or root.data == key:
            return root
        
        if key < root.data:
            return self._search_recursive(root.left, key)
        
        return self._search_recursive(root.right, key)
    
    def inorder_traversal(self, root=None):
        """Inorder traversal: Left -> Root -> Right (gives sorted order)"""
        if root is None:
            root = self.root
        
        result = []
        if root is not None:
            result.extend(self.inorder_traversal(root.left))
            result.append(root.data)
            result.extend(self.inorder_traversal(root.right))
        
        return result
    
    def preorder_traversal(self, root=None):
        """Preorder traversal: Root -> Left -> Right"""
        if root is None:
            root = self.root
        
        result = []
        if root is not None:
            result.append(root.data)
            result.extend(self.preorder_traversal(root.left))
            result.extend(self.preorder_traversal(root.right))
        
        return result
    
    def postorder_traversal(self, root=None):
        """Postorder traversal: Left -> Right -> Root"""
        if root is None:
            root = self.root
        
        result = []
        if root is not None:
            result.extend(self.postorder_traversal(root.left))
            result.extend(self.postorder_traversal(root.right))
            result.append(root.data)
        
        return result
    
    def count_nodes(self, root=None):
        """Count total number of nodes"""
        if root is None:
            root = self.root
        
        if root is None:
            return 0
        
        return 1 + self.count_nodes(root.left) + self.count_nodes(root.right)
    
    def find_height(self, root=None):
        """Find height of the tree"""
        if root is None:
            root = self.root
        
        if root is None:
            return -1
        
        left_height = self.find_height(root.left)
        right_height = self.find_height(root.right)
        
        return 1 + max(left_height, right_height)
    
    def count_leaf_nodes(self, root=None):
        """Count number of leaf nodes"""
        if root is None:
            root = self.root
        
        if root is None:
            return 0
        
        if root.left is None and root.right is None:
            return 1
        
        return self.count_leaf_nodes(root.left) + self.count_leaf_nodes(root.right)
    
    def count_internal_nodes(self, root=None):
        """Count number of internal nodes"""
        if root is None:
            root = self.root
        
        if root is None or (root.left is None and root.right is None):
            return 0
        
        return 1 + self.count_internal_nodes(root.left) + self.count_internal_nodes(root.right)
    
    def find_min(self):
        """Find minimum value in BST"""
        return self._find_min(self.root)
    
    def _find_min(self, root):
        if root is None:
            return None
        
        while root.left is not None:
            root = root.left
        
        return root
    
    def find_max(self):
        """Find maximum value in BST"""
        return self._find_max(self.root)
    
    def _find_max(self, root):
        if root is None:
            return None
        
        while root.right is not None:
            root = root.right
        
        return root
    
    def is_complete_binary_tree(self):
        """Check if BST is a complete binary tree"""
        return self._is_complete_recursive(self.root, 0, self.count_nodes())
    
    def _is_complete_recursive(self, root, index, node_count):
        if root is None:
            return True
        
        if index >= node_count:
            return False
        
        return (self._is_complete_recursive(root.left, 2 * index + 1, node_count) and
                self._is_complete_recursive(root.right, 2 * index + 2, node_count))
    
    def balance_factor(self, root=None):
        """Calculate balance factor of a node"""
        if root is None:
            root = self.root
        
        if root is None:
            return 0
        
        return self.find_height(root.left) - self.find_height(root.right)
    
    def count_null_pointers(self, root=None):
        """Count number of NULL pointers"""
        if root is None:
            if self.root is None:
                return 1
            root = self.root
        
        if root is None:
            return 1
        
        return self.count_null_pointers(root.left) + self.count_null_pointers(root.right)
    
    def create_bst(self):
        """Create BST interactively"""
        print("\n=== Creating Binary Search Tree ===")
        try:
            n = int(input("Enter number of nodes: "))
            if n <= 0:
                print("Invalid number of nodes!")
                return
            
            print(f"Enter {n} values:")
            for i in range(n):
                data = int(input(f"Value {i + 1}: "))
                self.insert(data)
            
            print("BST created successfully!")
            
        except ValueError:
            print("Invalid input! Please enter integers only.")
    
    def display_tree_structure(self, root=None, space=0):
        """Display tree structure (rotated 90° clockwise)"""
        COUNT = 10
        
        if root is None:
            if space == 0:  # Initial call
                root = self.root
            if root is None:
                return
        
        space += COUNT
        
        self.display_tree_structure(root.right, space)
        
        print()
        for i in range(COUNT, space):
            print(" ", end="")
        print(root.data)
        
        self.display_tree_structure(root.left, space)
    
    def bst_analysis(self):
        """Comprehensive BST analysis"""
        print("\n=== BST Analysis ===")
        if self.root is None:
            print("BST is empty!")
            return
        
        total_nodes = self.count_nodes()
        leaf_nodes = self.count_leaf_nodes()
        internal_nodes = self.count_internal_nodes()
        height = self.find_height()
        null_pointers = self.count_null_pointers()
        
        min_node = self.find_min()
        max_node = self.find_max()
        
        print(f"Root Node: {self.root.data}")
        print(f"Total Nodes: {total_nodes}")
        print(f"Leaf Nodes: {leaf_nodes}")
        print(f"Internal Nodes: {internal_nodes}")
        print(f"Tree Height: {height}")
        print(f"Minimum Value: {min_node.data if min_node else 'N/A'}")
        print(f"Maximum Value: {max_node.data if max_node else 'N/A'}")
        print(f"NULL Pointers: {null_pointers}")
        print(f"Root Balance Factor: {self.balance_factor()}")
        
        # Check if complete binary tree
        is_complete = self.is_complete_binary_tree()
        print(f"Complete Binary Tree: {'Yes' if is_complete else 'No'}")
        
        # BST properties
        print(f"\nBST Properties:")
        print(f"• Inorder traversal gives sorted sequence")
        print(f"• Search time complexity: O(h) where h is height")
        print(f"• Best case height: O(log n)")
        print(f"• Worst case height: O(n)")
        
        # Balance analysis
        if height >= 0:
            optimal_height = int(math.log2(total_nodes)) if total_nodes > 0 else 0
            balance_ratio = (optimal_height / (height + 1)) * 100 if height >= 0 else 0
            print(f"• Tree balance efficiency: {balance_ratio:.1f}%")
    
    def traversal_comparison(self):
        """Compare all traversal methods"""
        print("\n=== Traversal Comparison ===")
        if self.root is None:
            print("BST is empty!")
            return
        
        inorder = self.inorder_traversal()
        preorder = self.preorder_traversal()
        postorder = self.postorder_traversal()
        
        print(f"Inorder (Sorted):     {inorder}")
        print(f"Preorder (Root-L-R):  {preorder}")
        print(f"Postorder (L-R-Root): {postorder}")
        
        print(f"\nNote: Inorder traversal of BST gives elements in sorted order")
        print(f"This is the key property that makes BST useful for sorting")
    
    def balance_analysis(self):
        """Analyze balance factors of nodes"""
        print("\n=== Balance Analysis ===")
        if self.root is None:
            print("BST is empty!")
            return
        
        print("Node\tBalance Factor")
        print("----\t--------------")
        
        # Display balance factors for root and immediate children
        print(f"{self.root.data}\t{self.balance_factor(self.root)}")
        
        if self.root.left:
            print(f"{self.root.left.data}\t{self.balance_factor(self.root.left)}")
        
        if self.root.right:
            print(f"{self.root.right.data}\t{self.balance_factor(self.root.right)}")
        
        print(f"\nBalance Factor = Height(Left) - Height(Right)")
        print(f"Balanced if |Balance Factor| <= 1")
        print(f"AVL trees maintain this property automatically")
    
    def validate_bst(self, root=None, min_val=float('-inf'), max_val=float('inf')):
        """Validate if tree maintains BST property"""
        if root is None:
            root = self.root
        
        if root is None:
            return True
        
        if root.data <= min_val or root.data >= max_val:
            return False
        
        return (self.validate_bst(root.left, min_val, root.data) and
                self.validate_bst(root.right, root.data, max_val))

def main():
    bst = BinarySearchTree()
    
    print("=== Binary Search Tree Implementation (Python) ===")
    print("BST: Left subtree < Root < Right subtree")
    print("Efficient searching, insertion, and deletion")
    print("Object-oriented design with comprehensive functionality\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Create BST")
        print("2. Insert Node")
        print("3. Delete Node")
        print("4. Search Data")
        print("5. Inorder Traversal (Sorted)")
        print("6. Preorder Traversal")
        print("7. Postorder Traversal")
        print("8. Count Nodes")
        print("9. Find Height")
        print("10. Count Leaf Nodes")
        print("11. Count Internal Nodes")
        print("12. Find Minimum")
        print("13. Find Maximum")
        print("14. Check Complete Binary Tree")
        print("15. Balance Factor of Root")
        print("16. Count NULL Pointers")
        print("17. Display Tree Structure")
        print("18. BST Analysis")
        print("19. Traversal Comparison")
        print("20. Balance Analysis")
        print("21. Validate BST Property")
        print("22. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                bst = BinarySearchTree()  # Reset BST
                bst.create_bst()
            
            elif choice == 2:
                data = int(input("Enter data to insert: "))
                bst.insert(data)
                print(f"Node {data} inserted successfully")
            
            elif choice == 3:
                data = int(input("Enter data to delete: "))
                bst.delete(data)
            
            elif choice == 4:
                key = int(input("Enter data to search: "))
                result = bst.search(key)
                if result:
                    print(f"Data {key} found in BST")
                else:
                    print(f"Data {key} not found in BST")
            
            elif choice == 5:
                result = bst.inorder_traversal()
                print(f"Inorder Traversal (Sorted): {result}")
            
            elif choice == 6:
                result = bst.preorder_traversal()
                print(f"Preorder Traversal: {result}")
            
            elif choice == 7:
                result = bst.postorder_traversal()
                print(f"Postorder Traversal: {result}")
            
            elif choice == 8:
                count = bst.count_nodes()
                print(f"Total number of nodes: {count}")
            
            elif choice == 9:
                height = bst.find_height()
                print(f"Height of BST: {height}")
            
            elif choice == 10:
                count = bst.count_leaf_nodes()
                print(f"Number of leaf nodes: {count}")
            
            elif choice == 11:
                count = bst.count_internal_nodes()
                print(f"Number of internal nodes: {count}")
            
            elif choice == 12:
                min_node = bst.find_min()
                if min_node:
                    print(f"Minimum value: {min_node.data}")
                else:
                    print("BST is empty!")
            
            elif choice == 13:
                max_node = bst.find_max()
                if max_node:
                    print(f"Maximum value: {max_node.data}")
                else:
                    print("BST is empty!")
            
            elif choice == 14:
                is_complete = bst.is_complete_binary_tree()
                print(f"Complete Binary Tree: {'Yes' if is_complete else 'No'}")
            
            elif choice == 15:
                balance = bst.balance_factor()
                print(f"Balance factor of root: {balance}")
            
            elif choice == 16:
                count = bst.count_null_pointers()
                print(f"Number of NULL pointers: {count}")
            
            elif choice == 17:
                print("BST Structure (Rotated 90° clockwise):")
                if bst.root:
                    bst.display_tree_structure()
                else:
                    print("BST is empty!")
            
            elif choice == 18:
                bst.bst_analysis()
            
            elif choice == 19:
                bst.traversal_comparison()
            
            elif choice == 20:
                bst.balance_analysis()
            
            elif choice == 21:
                is_valid = bst.validate_bst()
                print(f"Valid BST: {'Yes' if is_valid else 'No'}")
            
            elif choice == 22:
                print("Exiting program...")
                break
            
            else:
                print("Invalid choice! Please try again.")
        
        except ValueError:
            print("Invalid input! Please enter a valid number.")
        except KeyboardInterrupt:
            print("\nProgram interrupted. Exiting...")
            break

if __name__ == "__main__":
    main()
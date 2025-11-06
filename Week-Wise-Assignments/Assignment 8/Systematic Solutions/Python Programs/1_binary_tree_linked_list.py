import math
from collections import deque

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None
    
    def create_tree(self):
        """Create a binary tree interactively"""
        print("\n=== Creating Binary Tree ===")
        try:
            n = int(input("Enter number of nodes: "))
            if n <= 0:
                print("Invalid number of nodes!")
                return
            
            root_data = int(input("Enter root node data: "))
            self.root = TreeNode(root_data)
            print(f"Root node {root_data} created")
            
            for i in range(1, n):
                data = int(input(f"\nEnter data for node {i + 1}: "))
                self._insert_node(self.root, data)
            
            print("\nBinary tree created successfully!")
            
        except ValueError:
            print("Invalid input! Please enter integers only.")
    
    def _insert_node(self, root, data):
        """Helper method to insert node interactively"""
        if root is None:
            return TreeNode(data)
        
        choice = input(f"Insert {data} to the left or right of {root.data}? (l/r): ").lower()
        
        if choice == 'l':
            if root.left is None:
                root.left = TreeNode(data)
                print(f"Node {data} inserted to the left of {root.data}")
            else:
                print("Left child already exists. Inserting recursively...")
                self._insert_node(root.left, data)
        elif choice == 'r':
            if root.right is None:
                root.right = TreeNode(data)
                print(f"Node {data} inserted to the right of {root.data}")
            else:
                print("Right child already exists. Inserting recursively...")
                self._insert_node(root.right, data)
        else:
            print("Invalid choice! Node not inserted.")
        
        return root
    
    def inorder_traversal(self, root=None):
        """Inorder traversal: Left -> Root -> Right"""
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
    
    def search_data(self, key, root=None):
        """Search for data in the tree"""
        if root is None:
            root = self.root
        
        if root is None:
            return False
        
        if root.data == key:
            return True
        
        return (self.search_data(key, root.left) or 
                self.search_data(key, root.right))
    
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
    
    def level_order_traversal(self):
        """Level order traversal using queue"""
        if self.root is None:
            return []
        
        result = []
        queue = deque([self.root])
        
        while queue:
            node = queue.popleft()
            result.append(node.data)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        return result
    
    def tree_analysis(self):
        """Comprehensive tree analysis"""
        print("\n=== Tree Analysis ===")
        if self.root is None:
            print("Tree is empty!")
            return
        
        total_nodes = self.count_nodes()
        leaf_nodes = self.count_leaf_nodes()
        internal_nodes = self.count_internal_nodes()
        height = self.find_height()
        
        print(f"Root Node: {self.root.data}")
        print(f"Total Nodes: {total_nodes}")
        print(f"Leaf Nodes: {leaf_nodes}")
        print(f"Internal Nodes: {internal_nodes}")
        print(f"Tree Height: {height}")
        
        # Tree properties
        print(f"\nTree Properties:")
        print(f"• Maximum nodes at height {height}: {(2 ** (height + 1)) - 1}")
        print(f"• Minimum height for {total_nodes} nodes: {int(math.log2(total_nodes)) if total_nodes > 0 else 0}")
        
        # Balance factor
        if height >= 0:
            max_possible_nodes = (2 ** (height + 1)) - 1
            balance_ratio = (total_nodes / max_possible_nodes) * 100
            print(f"• Tree density: {balance_ratio:.1f}%")
        
        # Verify node count
        if total_nodes == leaf_nodes + internal_nodes:
            print("✓ Node count verification: PASSED")
        else:
            print("✗ Node count verification: FAILED")
    
    def traversal_comparison(self):
        """Compare all traversal methods"""
        print("\n=== Traversal Comparison ===")
        if self.root is None:
            print("Tree is empty!")
            return
        
        inorder = self.inorder_traversal()
        preorder = self.preorder_traversal()
        postorder = self.postorder_traversal()
        level_order = self.level_order_traversal()
        
        print(f"Inorder (Left-Root-Right):   {inorder}")
        print(f"Preorder (Root-Left-Right):  {preorder}")
        print(f"Postorder (Left-Right-Root): {postorder}")
        print(f"Level Order (BFS):           {level_order}")
        
        print(f"\nTraversal Uses:")
        print(f"• Inorder: Binary Search Trees (gives sorted order)")
        print(f"• Preorder: Tree copying, expression trees")
        print(f"• Postorder: Tree deletion, calculating directory sizes")
        print(f"• Level Order: Tree printing, finding nodes at specific level")
    
    def find_path_to_node(self, target, root=None, path=None):
        """Find path from root to target node"""
        if root is None:
            root = self.root
        if path is None:
            path = []
        
        if root is None:
            return False
        
        path.append(root.data)
        
        if root.data == target:
            return True
        
        if (self.find_path_to_node(target, root.left, path) or 
            self.find_path_to_node(target, root.right, path)):
            return True
        
        path.pop()
        return False

def main():
    tree = BinaryTree()
    
    print("=== Binary Tree Implementation (Python) ===")
    print("Dynamic binary tree with comprehensive functionality")
    print("Object-oriented design with efficient algorithms\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Create Binary Tree")
        print("2. Inorder Traversal")
        print("3. Preorder Traversal")
        print("4. Postorder Traversal")
        print("5. Count Nodes")
        print("6. Find Height")
        print("7. Count Leaf Nodes")
        print("8. Count Internal Nodes")
        print("9. Search Data")
        print("10. Display Tree Structure")
        print("11. Tree Analysis")
        print("12. Traversal Comparison")
        print("13. Level Order Traversal")
        print("14. Find Path to Node")
        print("15. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                tree.create_tree()
            
            elif choice == 2:
                result = tree.inorder_traversal()
                print(f"\nInorder Traversal (Left-Root-Right): {result}")
            
            elif choice == 3:
                result = tree.preorder_traversal()
                print(f"\nPreorder Traversal (Root-Left-Right): {result}")
            
            elif choice == 4:
                result = tree.postorder_traversal()
                print(f"\nPostorder Traversal (Left-Right-Root): {result}")
            
            elif choice == 5:
                count = tree.count_nodes()
                print(f"\nTotal number of nodes: {count}")
            
            elif choice == 6:
                height = tree.find_height()
                print(f"\nHeight of tree: {height}")
            
            elif choice == 7:
                count = tree.count_leaf_nodes()
                print(f"\nNumber of leaf nodes: {count}")
            
            elif choice == 8:
                count = tree.count_internal_nodes()
                print(f"\nNumber of internal nodes: {count}")
            
            elif choice == 9:
                key = int(input("Enter data to search: "))
                found = tree.search_data(key)
                if found:
                    print(f"Data {key} found in tree")
                else:
                    print(f"Data {key} not found in tree")
            
            elif choice == 10:
                print("\nTree Structure (Rotated 90° clockwise):")
                if tree.root:
                    tree.display_tree_structure()
                else:
                    print("Tree is empty!")
            
            elif choice == 11:
                tree.tree_analysis()
            
            elif choice == 12:
                tree.traversal_comparison()
            
            elif choice == 13:
                result = tree.level_order_traversal()
                print(f"\nLevel Order Traversal (BFS): {result}")
            
            elif choice == 14:
                target = int(input("Enter node to find path to: "))
                path = []
                if tree.find_path_to_node(target, path=path):
                    print(f"Path from root to {target}: {path}")
                else:
                    print(f"Node {target} not found in tree")
            
            elif choice == 15:
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
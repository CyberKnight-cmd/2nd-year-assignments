class Node:
    def __init__(self, data):
        self.data, self.left, self.right = data, None, None

class BinaryTree:
    def __init__(self):
        self.root = None
    
    def create(self):
        n = int(input("Nodes: "))
        self.root = Node(int(input("Root: ")))
        for _ in range(n-1):
            data = int(input("Data: "))
            self._insert(self.root, data)
    
    def _insert(self, root, data):
        c = input(f"Left/Right of {root.data} (l/r): ")
        if c == 'l':
            if not root.left: root.left = Node(data)
            else: self._insert(root.left, data)
        else:
            if not root.right: root.right = Node(data)
            else: self._insert(root.right, data)
    
    def inorder(self, root=None):
        if root is None: root = self.root
        return (self.inorder(root.left) + [root.data] + self.inorder(root.right)) if root else []
    
    def preorder(self, root=None):
        if root is None: root = self.root
        return ([root.data] + self.preorder(root.left) + self.preorder(root.right)) if root else []
    
    def postorder(self, root=None):
        if root is None: root = self.root
        return (self.postorder(root.left) + self.postorder(root.right) + [root.data]) if root else []
    
    def count(self, root=None):
        if root is None: root = self.root
        return 1 + self.count(root.left) + self.count(root.right) if root else 0
    
    def height(self, root=None):
        if root is None: root = self.root
        return 1 + max(self.height(root.left), self.height(root.right)) if root else -1
    
    def leafs(self, root=None):
        if root is None: root = self.root
        if not root: return 0
        if not root.left and not root.right: return 1
        return self.leafs(root.left) + self.leafs(root.right)
    
    def internal(self, root=None):
        if root is None: root = self.root
        if not root or (not root.left and not root.right): return 0
        return 1 + self.internal(root.left) + self.internal(root.right)
    
    def search(self, key, root=None):
        if root is None: root = self.root
        if not root: return False
        return root.data == key or self.search(key, root.left) or self.search(key, root.right)

tree = BinaryTree()
while True:
    print("\n1.Create 2.Inorder 3.Preorder 4.Postorder 5.Count 6.Height 7.Leafs 8.Internal 9.Search 0.Exit")
    ch = int(input())
    if ch == 1: tree.create()
    elif ch == 2: print("Inorder:", tree.inorder())
    elif ch == 3: print("Preorder:", tree.preorder())
    elif ch == 4: print("Postorder:", tree.postorder())
    elif ch == 5: print("Nodes:", tree.count())
    elif ch == 6: print("Height:", tree.height())
    elif ch == 7: print("Leafs:", tree.leafs())
    elif ch == 8: print("Internal:", tree.internal())
    elif ch == 9: print("Found" if tree.search(int(input("Key: "))) else "Not found")
    elif ch == 0: break
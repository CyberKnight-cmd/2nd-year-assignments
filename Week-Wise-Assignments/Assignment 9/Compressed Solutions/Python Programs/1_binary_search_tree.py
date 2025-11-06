class Node:
    def __init__(self, data):
        self.data, self.left, self.right = data, None, None

class BST:
    def __init__(self):
        self.root = None
    
    def insert(self, data):
        self.root = self._insert(self.root, data)
    
    def _insert(self, root, data):
        if not root: return Node(data)
        if data < root.data: root.left = self._insert(root.left, data)
        elif data > root.data: root.right = self._insert(root.right, data)
        return root
    
    def delete(self, data):
        self.root = self._delete(self.root, data)
    
    def _delete(self, root, data):
        if not root: return root
        if data < root.data: root.left = self._delete(root.left, data)
        elif data > root.data: root.right = self._delete(root.right, data)
        else:
            if not root.left: return root.right
            if not root.right: return root.left
            min_node = self._min(root.right)
            root.data = min_node.data
            root.right = self._delete(root.right, min_node.data)
        return root
    
    def search(self, key):
        return self._search(self.root, key)
    
    def _search(self, root, key):
        if not root or root.data == key: return root
        return self._search(root.left, key) if key < root.data else self._search(root.right, key)
    
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
    
    def _min(self, root):
        while root and root.left: root = root.left
        return root
    
    def _max(self, root):
        while root and root.right: root = root.right
        return root
    
    def min_val(self):
        node = self._min(self.root)
        return node.data if node else None
    
    def max_val(self):
        node = self._max(self.root)
        return node.data if node else None
    
    def is_complete(self, root=None, i=0, n=None):
        if root is None: root, n = self.root, self.count()
        if not root: return True
        if i >= n: return False
        return self.is_complete(root.left, 2*i+1, n) and self.is_complete(root.right, 2*i+2, n)
    
    def balance(self, root=None):
        if root is None: root = self.root
        return self.height(root.left) - self.height(root.right) if root else 0
    
    def null_count(self, root=None):
        if root is None: root = self.root
        return self.null_count(root.left) + self.null_count(root.right) if root else 1

bst = BST()
while True:
    print("\n1.Create 2.Insert 3.Delete 4.Search 5.Inorder 6.Preorder 7.Postorder 8.Count 9.Height 10.Leafs 11.Internal 12.Min 13.Max 14.Complete 15.Balance 16.NullCount 0.Exit")
    ch = int(input())
    if ch == 1:
        n = int(input("Nodes: "))
        for _ in range(n):
            bst.insert(int(input("Data: ")))
    elif ch == 2: bst.insert(int(input("Data: ")))
    elif ch == 3: bst.delete(int(input("Data: ")))
    elif ch == 4: print("Found" if bst.search(int(input("Key: "))) else "Not found")
    elif ch == 5: print("Inorder:", bst.inorder())
    elif ch == 6: print("Preorder:", bst.preorder())
    elif ch == 7: print("Postorder:", bst.postorder())
    elif ch == 8: print("Nodes:", bst.count())
    elif ch == 9: print("Height:", bst.height())
    elif ch == 10: print("Leafs:", bst.leafs())
    elif ch == 11: print("Internal:", bst.internal())
    elif ch == 12: print("Min:", bst.min_val())
    elif ch == 13: print("Max:", bst.max_val())
    elif ch == 14: print("Complete:", "Yes" if bst.is_complete() else "No")
    elif ch == 15: print("Balance:", bst.balance())
    elif ch == 16: print("NULL:", bst.null_count())
    elif ch == 0: break
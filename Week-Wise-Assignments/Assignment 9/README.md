# Assignment 9: Binary Search Tree Implementation

## Overview
This assignment implements Binary Search Tree (BST) data structure using linked lists in both C and Python. BST is a specialized binary tree where the left subtree contains values less than the root, and the right subtree contains values greater than the root.

## Folder Structure
```
Assignment 9/
├── Systematic Solutions/
│   ├── C Programs/
│   │   └── 1_binary_search_tree.c
│   └── Python Programs/
│       └── 1_binary_search_tree.py
├── Compressed Solutions/
│   ├── C Programs/
│   │   └── 1_binary_search_tree.c
│   └── Python Programs/
│       └── 1_binary_search_tree.py
└── README.md
```

## Binary Search Tree Properties

### BST Definition
A Binary Search Tree is a binary tree with the following properties:
1. **Left Subtree**: All nodes have values less than the root
2. **Right Subtree**: All nodes have values greater than the root
3. **Recursive Property**: Both left and right subtrees are also BSTs
4. **No Duplicates**: Typically, duplicate values are not allowed

### Key Advantages
- **Efficient Search**: O(log n) average case
- **Sorted Order**: Inorder traversal gives sorted sequence
- **Dynamic Size**: Can grow and shrink during runtime
- **Efficient Insert/Delete**: O(log n) average case

## Core Operations Implementation

### 1. Tree Creation and Insertion
```c
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
```

**Time Complexity**: O(h) where h is height
**Space Complexity**: O(h) for recursion stack

### 2. Search Operation
```c
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}
```

**Time Complexity**: O(h)
**Space Complexity**: O(h)

### 3. Deletion (Three Cases)
1. **Leaf Node**: Simply remove the node
2. **One Child**: Replace node with its child
3. **Two Children**: Replace with inorder successor/predecessor

```c
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node to be deleted found
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
        
        // Two children case
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
```

## Traversal Algorithms

### 1. Inorder Traversal (Left-Root-Right)
- **Special Property**: Gives elements in sorted order
- **Use Cases**: Sorting, validation, range queries
- **Time Complexity**: O(n)

### 2. Preorder Traversal (Root-Left-Right)
- **Use Cases**: Tree copying, serialization
- **Time Complexity**: O(n)

### 3. Postorder Traversal (Left-Right-Root)
- **Use Cases**: Tree deletion, expression evaluation
- **Time Complexity**: O(n)

## Advanced Operations

### 1. Finding Minimum/Maximum
```c
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}
```

**Time Complexity**: O(h)

### 2. Height Calculation
```c
int findHeight(Node* root) {
    if (root == NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}
```

**Time Complexity**: O(n)

### 3. Balance Factor
```c
int balanceFactor(Node* root) {
    if (root == NULL) return 0;
    return findHeight(root->left) - findHeight(root->right);
}
```

**Interpretation**:
- Balance Factor = 0: Perfectly balanced
- Balance Factor = ±1: Well balanced
- |Balance Factor| > 1: Unbalanced (needs rotation in AVL)

### 4. Complete Binary Tree Check
```c
int isCompleteBinaryTree(Node* root, int index, int nodeCount) {
    if (root == NULL) return 1;
    if (index >= nodeCount) return 0;
    return isCompleteBinaryTree(root->left, 2*index+1, nodeCount) &&
           isCompleteBinaryTree(root->right, 2*index+2, nodeCount);
}
```

## Complexity Analysis

| Operation | Average Case | Worst Case | Best Case |
|-----------|-------------|------------|-----------|
| Search | O(log n) | O(n) | O(1) |
| Insert | O(log n) | O(n) | O(1) |
| Delete | O(log n) | O(n) | O(1) |
| Traversal | O(n) | O(n) | O(n) |
| Find Min/Max | O(log n) | O(n) | O(1) |
| Height | O(n) | O(n) | O(n) |

**Space Complexity**: O(n) for storage, O(h) for operations

## BST Variants and Applications

### 1. Self-Balancing BSTs
- **AVL Trees**: Height-balanced BST
- **Red-Black Trees**: Color-based balancing
- **Splay Trees**: Self-adjusting BST

### 2. Applications
- **Database Indexing**: B-trees and B+ trees
- **File Systems**: Directory structures
- **Expression Parsing**: Syntax trees
- **Priority Queues**: Heap implementation
- **Set/Map Data Structures**: STL implementations

## Program Features

### Systematic Solutions
- **Interactive Menu System**: User-friendly interface
- **Comprehensive Analysis**: Tree statistics and properties
- **Memory Management**: Proper allocation and deallocation
- **Error Handling**: Input validation and edge cases
- **Educational Features**: Algorithm explanations and complexity analysis
- **Tree Visualization**: Structure display and balance analysis

### Compressed Solutions
- **Minimal Implementation**: Essential functionality only
- **Optimized Code**: Reduced to core operations
- **Efficient Memory Usage**: Compact data structures

## Usage Instructions

### Compilation (C Programs)
```bash
gcc 1_binary_search_tree.c -o bst -lm
```

### Execution
```bash
# C Programs
./bst

# Python Programs
python 1_binary_search_tree.py
```

### Sample Operations
```
Create BST: 50, 30, 70, 20, 40, 60, 80

Tree Structure:
        80
    70
        60
50
        40
    30
        20

Inorder (Sorted): 20 30 40 50 60 70 80
Preorder: 50 30 20 40 70 60 80
Postorder: 20 40 30 60 80 70 50
```

## Key Learning Outcomes

1. **BST Properties**: Understanding ordering constraints
2. **Recursive Algorithms**: Tree operations using recursion
3. **Search Efficiency**: Logarithmic search in balanced trees
4. **Tree Balancing**: Impact of tree shape on performance
5. **Memory Management**: Dynamic node allocation/deallocation
6. **Algorithm Analysis**: Time and space complexity evaluation

## Best Practices

### 1. Implementation Guidelines
- **Null Checks**: Always validate pointers before use
- **Memory Management**: Free allocated memory to prevent leaks
- **Recursive Base Cases**: Handle empty tree conditions
- **Duplicate Handling**: Define policy for duplicate values

### 2. Performance Optimization
- **Iterative vs Recursive**: Consider stack overflow for deep trees
- **Balancing**: Use self-balancing variants for guaranteed performance
- **Caching**: Store frequently accessed values (height, size)

### 3. Error Handling
- **Input Validation**: Check for valid data ranges
- **Memory Allocation**: Handle malloc failures gracefully
- **Edge Cases**: Empty trees, single nodes, duplicate operations

## Common Pitfalls

1. **Unbalanced Trees**: Can degrade to O(n) performance
2. **Memory Leaks**: Forgetting to free deleted nodes
3. **Incorrect Deletion**: Not handling all three deletion cases
4. **Stack Overflow**: Deep recursion in skewed trees
5. **Duplicate Values**: Inconsistent handling policies

## Extensions and Improvements

1. **Self-Balancing**: Implement AVL or Red-Black tree rotations
2. **Iterative Operations**: Convert recursive functions to iterative
3. **Range Queries**: Find all elements in a given range
4. **Predecessor/Successor**: Find next/previous elements
5. **Serialization**: Save/load tree structure to/from file

This comprehensive BST implementation provides a solid foundation for understanding tree-based data structures and their applications in computer science.
# Assignment 8: Binary Tree Implementation

## Overview
This assignment implements Binary Tree data structure using both array-based and linked list-based approaches in C and Python. Binary trees are hierarchical data structures where each node has at most two children (left and right).

## Folder Structure
```
Assignment 8/
├── Systematic Solutions/
│   ├── C Programs/
│   │   ├── 1_binary_tree_array.c
│   │   └── 2_binary_tree_linked_list.c
│   └── Python Programs/
│       └── 1_binary_tree_linked_list.py
├── Compressed Solutions/
│   ├── C Programs/
│   │   ├── 1_binary_tree_array.c
│   │   └── 2_binary_tree_linked_list.c
│   └── Python Programs/
│       └── 1_binary_tree_linked_list.py
└── README.md
```

## Binary Tree Concepts

### Tree Terminology
- **Node**: Basic unit containing data and references to children
- **Root**: Top node of the tree (no parent)
- **Leaf**: Node with no children
- **Internal Node**: Node with at least one child
- **Height**: Maximum distance from root to any leaf
- **Level**: Distance from root (root is at level 0)

### Tree Properties
- **Maximum nodes at level i**: 2^i
- **Maximum nodes in tree of height h**: 2^(h+1) - 1
- **Minimum height for n nodes**: ⌊log₂(n)⌋

## Implementation Approaches

### 1. Array-Based Implementation
**Advantages:**
- Memory efficient for complete trees
- Simple parent-child relationship calculation
- Cache-friendly access patterns

**Disadvantages:**
- Wastes space for sparse trees
- Fixed maximum size
- Difficult insertion/deletion

**Array Indexing:**
- Root at index 0
- Left child of node i: 2i + 1
- Right child of node i: 2i + 2
- Parent of node i: (i - 1) / 2

### 2. Linked List Implementation
**Advantages:**
- Dynamic memory allocation
- Efficient for sparse trees
- Easy insertion/deletion

**Disadvantages:**
- Extra memory for pointers
- No direct access to nodes
- Potential cache misses

## Tree Traversal Algorithms

### 1. Inorder Traversal (Left-Root-Right)
```
Algorithm:
1. Traverse left subtree
2. Visit root
3. Traverse right subtree

Use Cases:
- Binary Search Trees (gives sorted order)
- Expression evaluation
```

### 2. Preorder Traversal (Root-Left-Right)
```
Algorithm:
1. Visit root
2. Traverse left subtree
3. Traverse right subtree

Use Cases:
- Tree copying
- Prefix expression evaluation
- Directory listing
```

### 3. Postorder Traversal (Left-Right-Root)
```
Algorithm:
1. Traverse left subtree
2. Traverse right subtree
3. Visit root

Use Cases:
- Tree deletion
- Postfix expression evaluation
- Directory size calculation
```

## Core Operations

### 1. Tree Creation
- **Array**: Initialize array with sentinel values (-1)
- **Linked List**: Create nodes dynamically with user input

### 2. Node Counting
```
count(node):
    if node is null: return 0
    return 1 + count(left) + count(right)

Time Complexity: O(n)
Space Complexity: O(h) - recursion stack
```

### 3. Height Calculation
```
height(node):
    if node is null: return -1
    leftHeight = height(left)
    rightHeight = height(right)
    return 1 + max(leftHeight, rightHeight)

Time Complexity: O(n)
Space Complexity: O(h)
```

### 4. Leaf Node Counting
```
countLeafs(node):
    if node is null: return 0
    if node is leaf: return 1
    return countLeafs(left) + countLeafs(right)

Time Complexity: O(n)
Space Complexity: O(h)
```

### 5. Internal Node Counting
```
countInternal(node):
    if node is null or leaf: return 0
    return 1 + countInternal(left) + countInternal(right)

Time Complexity: O(n)
Space Complexity: O(h)
```

### 6. Data Search
```
search(node, key):
    if node is null: return false
    if node.data == key: return true
    return search(left, key) || search(right, key)

Time Complexity: O(n)
Space Complexity: O(h)
```

## Complexity Analysis

| Operation | Array Implementation | Linked List Implementation |
|-----------|---------------------|---------------------------|
| Creation | O(n) | O(n) |
| Traversal | O(n) | O(n) |
| Search | O(n) | O(n) |
| Count Nodes | O(n) | O(n) |
| Height | O(n) | O(n) |
| Space | O(max_size) | O(n) |

## Program Features

### Systematic Solutions
- **Interactive Menus**: User-friendly interface
- **Error Handling**: Input validation and memory management
- **Tree Visualization**: Structure display and analysis
- **Educational Features**: Algorithm explanations and complexity analysis
- **Multiple Operations**: All required functions with detailed output

### Compressed Solutions
- **Minimal Code**: Essential functionality only
- **Efficient Implementation**: Optimized for brevity
- **Core Operations**: All required functions in minimal lines

## Usage Instructions

### Compilation (C Programs)
```bash
gcc 1_binary_tree_array.c -o array_tree -lm
gcc 2_binary_tree_linked_list.c -o linked_tree
```

### Execution
```bash
# C Programs
./array_tree
./linked_tree

# Python Programs
python 1_binary_tree_linked_list.py
```

### Sample Input/Output
```
Enter number of nodes: 7
Enter elements: 1 2 3 4 5 -1 6

Tree Structure:
Level 0: 1
Level 1: 2 3
Level 2: 4 5 - 6

Inorder: 4 2 5 1 3 6
Preorder: 1 2 4 5 3 6
Postorder: 4 5 2 6 3 1
```

## Key Learning Outcomes
1. **Tree Structure Understanding**: Hierarchical data organization
2. **Traversal Algorithms**: Different ways to visit nodes
3. **Recursive Thinking**: Problem decomposition techniques
4. **Memory Management**: Dynamic vs static allocation
5. **Algorithm Analysis**: Time and space complexity evaluation

## Applications
- **File Systems**: Directory structure representation
- **Expression Trees**: Mathematical expression parsing
- **Decision Trees**: AI and machine learning
- **Huffman Coding**: Data compression algorithms
- **Binary Search Trees**: Efficient searching and sorting

## Best Practices
1. **Memory Management**: Always free allocated memory in C
2. **Input Validation**: Check for valid inputs and edge cases
3. **Recursive Base Cases**: Properly handle null/empty conditions
4. **Code Modularity**: Separate functions for different operations
5. **Documentation**: Clear comments and function descriptions

This implementation provides a comprehensive understanding of binary tree operations and their practical applications in computer science.
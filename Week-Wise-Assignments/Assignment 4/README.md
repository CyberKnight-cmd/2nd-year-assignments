# Assignment 4: Advanced Single Linked List Operations

This assignment contains comprehensive implementations of advanced single linked list algorithms in both C and Python programming languages.

## 📁 Folder Structure

```
Assignment 4/
├── Systematic Solutions/
│   ├── C Programs/
│   │   ├── 1_reverse_list.c
│   │   ├── 2_merge_sorted.c
│   │   ├── 3_left_shift.c
│   │   ├── 4_polynomial_addition.c
│   │   ├── 5_pairwise_swap.c
│   │   ├── 6_loop_detection.c
│   │   ├── 7_polynomial_multiplication.c
│   │   ├── 8_stack_using_linkedlist.c
│   │   └── 9_queue_using_linkedlist.c
│   └── Python Programs/
│       ├── 1_reverse_list.py
│       ├── 2_merge_sorted.py
│       ├── 3_polynomial_addition.py
│       ├── 4_pairwise_swap.py
│       └── 5_loop_detection.py
├── Compressed Solutions/
│   ├── C Programs/
│   │   ├── 1_reverse_list.c
│   │   ├── 2_merge_sorted.c
│   │   ├── 3_left_shift.c
│   │   ├── 4_polynomial_addition.c
│   │   ├── 5_pairwise_swap.c
│   │   ├── 6_loop_detection.c
│   │   ├── 7_polynomial_multiplication.c
│   │   ├── 8_stack_using_linkedlist.c
│   │   └── 9_queue_using_linkedlist.c
│   └── Python Programs/
│       ├── 1_reverse_list.py
│       ├── 2_merge_sorted.py
│       ├── 3_polynomial_addition.py
│       ├── 4_pairwise_swap.py
│       └── 5_loop_detection.py
└── README.md
```

## 🎯 Problem Statements

### C Programming Problems (9 Programs)

1. **Reverse Linked List**: Reverse an already created single linked list
2. **Merge Sorted Lists**: Merge two already sorted linked lists
3. **Left Shift**: Left-shift a linked list by k nodes
4. **Polynomial Addition**: Add two polynomials using linked lists
5. **Pairwise Swap**: Swap elements in linked list pairwise
6. **Loop Detection**: Detect a loop in a single linked list
7. **Polynomial Multiplication**: Multiply two polynomials using linked lists
8. **Stack Implementation**: Implement stack using single linked list
9. **Queue Implementation**: Implement queue using single linked list

### Python Programming Problems (5 Programs)

1. **Reverse Linked List**: Reverse an already created single linked list
2. **Merge Sorted Lists**: Merge two already sorted linked lists
3. **Polynomial Addition**: Add two polynomials using linked lists
4. **Pairwise Swap**: Swap elements in linked list pairwise
5. **Loop Detection**: Detect a loop in a single linked list

## 🔧 Implementation Approaches

### Systematic Solutions
- **Comprehensive Error Handling**: Robust input validation and edge case management
- **Interactive Menus**: User-friendly interfaces for testing all functionalities
- **Algorithm Explanations**: Detailed step-by-step algorithm descriptions
- **Educational Features**: Process visualization and learning aids
- **Memory Management**: Proper allocation and deallocation (C programs)
- **Multiple Approaches**: Different algorithmic solutions where applicable

### Compressed Solutions
- **Minimal Code**: Shortest possible implementations while maintaining correctness
- **Essential Functionality**: Core algorithm implementation without extra features
- **Optimized for Brevity**: Focused on algorithmic efficiency and code conciseness
- **Direct Testing**: Simple test cases to demonstrate functionality

## 📚 Key Algorithms Implemented

### 1. Reverse Linked List
- **Iterative Approach**: Three-pointer technique (prev, current, next)
- **Recursive Approach**: Recursive reversal with proper linking
- **Time Complexity**: O(n), **Space Complexity**: O(1) iterative, O(n) recursive

### 2. Merge Sorted Lists
- **Iterative Merge**: Compare and merge using dummy node technique
- **Recursive Merge**: Elegant recursive solution with base cases
- **Time Complexity**: O(m+n), **Space Complexity**: O(1) iterative, O(m+n) recursive

### 3. Left Shift by K Nodes
- **Circular Connection**: Connect tail to head, then break at appropriate position
- **Modular Arithmetic**: Handle k > length cases efficiently
- **Time Complexity**: O(n), **Space Complexity**: O(1)

### 4. Polynomial Operations
- **Addition**: Compare exponents and add coefficients for like terms
- **Multiplication**: Multiply each term with every other term
- **Sorted Insertion**: Maintain descending order of exponents
- **Time Complexity**: O(m+n) addition, O(m*n) multiplication

### 5. Pairwise Swap
- **Iterative Swap**: Use dummy node and careful pointer manipulation
- **Recursive Swap**: Elegant recursive solution with proper base cases
- **Time Complexity**: O(n), **Space Complexity**: O(1) iterative, O(n) recursive

### 6. Loop Detection
- **Floyd's Algorithm**: Tortoise and Hare technique (two pointers)
- **Hash Set Method**: Track visited nodes using additional space
- **Time Complexity**: O(n), **Space Complexity**: O(1) Floyd's, O(n) Hash Set

### 7. Stack Using Linked List
- **LIFO Operations**: Push (insert at head), Pop (remove from head)
- **Dynamic Size**: No fixed size limitations
- **Time Complexity**: O(1) for all operations

### 8. Queue Using Linked List
- **FIFO Operations**: Enqueue (insert at rear), Dequeue (remove from front)
- **Two Pointers**: Maintain front and rear pointers
- **Time Complexity**: O(1) for all operations

## 🚀 How to Run

### C Programs
```bash
# Compile
gcc filename.c -o filename

# Run
./filename
```

### Python Programs
```bash
# Run directly
python filename.py
```

## 💡 Learning Outcomes

1. **Advanced Pointer Manipulation**: Master complex pointer operations and memory management
2. **Algorithm Design**: Understand different approaches to solve the same problem
3. **Time-Space Tradeoffs**: Learn when to choose different algorithmic approaches
4. **Data Structure Applications**: See practical applications of linked lists
5. **Recursive vs Iterative**: Compare and contrast different implementation strategies
6. **Edge Case Handling**: Develop robust programming practices

## 🔍 Key Features

### Systematic Solutions
- ✅ Complete error handling and input validation
- ✅ Interactive menu-driven interfaces
- ✅ Step-by-step algorithm visualization
- ✅ Multiple implementation approaches
- ✅ Comprehensive test cases
- ✅ Educational comments and explanations

### Compressed Solutions
- ✅ Minimal, optimized code
- ✅ Essential functionality only
- ✅ Quick testing and demonstration
- ✅ Focus on core algorithms
- ✅ Maximum efficiency in minimum lines

## 📈 Complexity Analysis

| Algorithm | Time Complexity | Space Complexity | Approach |
|-----------|----------------|------------------|----------|
| Reverse (Iterative) | O(n) | O(1) | Three pointers |
| Reverse (Recursive) | O(n) | O(n) | Call stack |
| Merge (Iterative) | O(m+n) | O(1) | Two pointers |
| Merge (Recursive) | O(m+n) | O(m+n) | Call stack |
| Left Shift | O(n) | O(1) | Circular connection |
| Polynomial Add | O(m+n) | O(m+n) | Compare exponents |
| Polynomial Multiply | O(m*n) | O(m*n) | Nested loops |
| Pairwise Swap | O(n) | O(1)/O(n) | Iterative/Recursive |
| Loop Detection | O(n) | O(1) | Floyd's algorithm |
| Stack Operations | O(1) | O(1) | Head insertion/deletion |
| Queue Operations | O(1) | O(1) | Front/rear pointers |

This assignment provides a comprehensive understanding of advanced linked list operations with both educational and practical implementations.
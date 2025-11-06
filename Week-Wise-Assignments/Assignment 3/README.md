# Assignment 3 - Single Linked List Data Structure

This folder contains solutions to Assignment 3 problems focusing on Single Linked List data structure in both C and Python programming languages.

## Folder Structure

```
Assignment 3/
├── Systematic Solutions/
│   ├── C Programs/          # Detailed C solutions with algorithms and comprehensive features
│   └── Python Programs/     # Detailed Python solutions with OOP design and multiple methods
├── Compressed Solutions/
│   ├── C Programs/          # Minimal C code solutions
│   └── Python Programs/     # Minimal Python code solutions
└── README.md               # This file
```

## C Programming Problems (Single Linked List)

1. **1_insert_operations.c** - Insert operations (createList, insertAtFirst, insertAtLast, insertAtAny, displayList) with algorithms
2. **2_delete_operations.c** - Delete operations (createList, deleteFromFirst, deleteFromLast, deleteFromAny, displayList) with algorithms
3. **3_complete_linked_list.c** - Complete implementation with all insert/delete functions and interactive menu
4. **4_polynomial_linked_list.c** - Polynomial storage using linked list in ascending order of exponents
5. **5_count_nodes.c** - Function to count nodes with iterative and recursive approaches
6. **6_odd_even_nodes.c** - Print odd and even number nodes separately with various separation methods

## Python Programming Problems (Single Linked List)

1. **1_insert_operations.py** - Insert operations (createList, insertAtFirst, insertAtLast, insertAtAny, displayList)
2. **2_delete_operations.py** - Delete operations (createList, deleteFromFirst, deleteFromLast, deleteFromAny, displayList)
3. **3_complete_linked_list.py** - Complete implementation with all insert/delete functions and interactive menu
4. **4_polynomial_linked_list.py** - Polynomial storage using linked list in descending order of exponents
5. **5_count_nodes.py** - Function to count nodes with various counting methods
6. **6_odd_even_nodes.py** - Print odd and even number nodes separately with comprehensive analysis

## Key Features

### C Solutions
- **Dynamic memory allocation** for all node operations
- **Comprehensive algorithms** with step-by-step explanations
- **Error handling** and input validation
- **Memory management** best practices with proper cleanup
- **Interactive menus** for testing all operations
- **Detailed comments** explaining each algorithm

### Python Solutions
- **Object-oriented design** with proper encapsulation
- **Multiple implementation approaches** for comparison
- **Comprehensive error handling** with exception management
- **Interactive demonstrations** and testing modes
- **Performance analysis** and optimization
- **Edge case testing** and validation

## Algorithms Implemented

### Insert Operations
```
insertAtFirst Algorithm:
1. Create new node
2. Set new node's next to current head
3. Update head to point to new node

insertAtLast Algorithm:
1. Create new node
2. If list is empty, make new node as head
3. Else traverse to last node
4. Set last node's next to new node

insertAtAny Algorithm:
1. If position is 1, call insertAtFirst
2. Traverse to (position-1)th node
3. Set new node's next to current node's next
4. Set current node's next to new node
```

### Delete Operations
```
deleteFromFirst Algorithm:
1. Check if list is empty
2. Store head in temp
3. Update head to head->next
4. Free temp node

deleteFromLast Algorithm:
1. Check if list is empty
2. If only one node, delete it
3. Traverse to second last node
4. Free last node and set second last's next to NULL

deleteFromAny Algorithm:
1. If position is 1, call deleteFromFirst
2. Traverse to (position-1)th node
3. Store position node in temp
4. Set (position-1)th node's next to temp->next
5. Free temp node
```

## Special Implementations

### Polynomial Storage
- **C Version**: Stores terms in ascending order of exponents
- **Python Version**: Stores terms in descending order of exponents
- Handles coefficient addition for same exponents
- Removes terms with zero coefficients
- Supports polynomial evaluation and operations

### Node Counting
- **Iterative approach**: Simple loop-based counting
- **Recursive approach**: Recursive function calls
- **Conditional counting**: Count nodes with specific values
- **Statistical analysis**: Even/odd, positive/negative counts

### Odd/Even Separation
- **Value-based separation**: Separate by odd/even numbers
- **Position-based separation**: Separate by odd/even positions
- **Multiple display formats**: Various output representations
- **Statistical analysis**: Comprehensive number analysis

## Compilation and Execution

### For C Programs:
```bash
# Systematic solutions
cd "Systematic Solutions/C Programs"
gcc 1_insert_operations.c -o insert_ops
./insert_ops

# Compressed solutions
cd "Compressed Solutions/C Programs"
gcc 1_insert_operations.c -o insert_ops
./insert_ops
```

### For Python Programs:
```bash
# Systematic solutions
cd "Systematic Solutions/Python Programs"
python 1_insert_operations.py

# Compressed solutions
cd "Compressed Solutions/Python Programs"
python 1_insert_operations.py
```

## Testing Examples

### Insert Operations
```
insertAtFirst(10) -> [10] -> None
insertAtFirst(20) -> [20] -> [10] -> None
insertAtLast(30)  -> [20] -> [10] -> [30] -> None
insertAtAny(25, 3) -> [20] -> [10] -> [25] -> [30] -> None
```

### Delete Operations
```
Original: [10] -> [20] -> [30] -> [40] -> None
deleteFromFirst() -> [20] -> [30] -> [40] -> None
deleteFromLast()  -> [20] -> [30] -> None
deleteFromAny(2)  -> [20] -> None
```

### Polynomial Examples
```
C (Ascending):  3x^0 + 2x^1 + 5x^2 + x^3
Python (Descending): x^3 + 5x^2 + 2x^1 + 3x^0
```

### Odd/Even Separation
```
Original: [12] -> [7] -> [18] -> [3] -> [24] -> [9] -> None
Odd:      [7] -> [3] -> [9] -> None
Even:     [12] -> [18] -> [24] -> None
```

## Memory Management

### C Programs
- Proper `malloc()` and `free()` usage
- Memory leak prevention
- Error handling for allocation failures
- Complete cleanup on program exit

### Python Programs
- Automatic garbage collection
- Proper object lifecycle management
- Memory-efficient implementations
- Resource cleanup in edge cases

## Performance Characteristics

### Time Complexity
- **Insert at First**: O(1)
- **Insert at Last**: O(n)
- **Insert at Any**: O(n)
- **Delete from First**: O(1)
- **Delete from Last**: O(n)
- **Delete from Any**: O(n)
- **Search**: O(n)
- **Display**: O(n)

### Space Complexity
- **All Operations**: O(1) additional space
- **Total Space**: O(n) for n nodes

## Notes

- All C programs use dynamic memory allocation
- Python programs include both basic and advanced implementations
- Systematic solutions include comprehensive testing and demonstrations
- Compressed solutions focus on minimal code while maintaining functionality
- All solutions handle edge cases and error conditions
- Interactive modes available for hands-on testing
- Polynomial implementations differ in ordering (C: ascending, Python: descending)
- Both iterative and recursive approaches provided where applicable
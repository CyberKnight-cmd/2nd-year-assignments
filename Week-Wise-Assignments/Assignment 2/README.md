# Assignment 2 - Stack & Queue Data Structures

This folder contains solutions to Assignment 2 problems focusing on Stack and Queue data structures in both C and Python programming languages.

## Folder Structure

```
Assignment 2/
├── Systematic Solutions/
│   ├── C Programs/          # Detailed C solutions with algorithms and comprehensive features
│   └── Python Programs/     # Detailed Python solutions with multiple methods and examples
├── Compressed Solutions/
│   ├── C Programs/          # Minimal C code solutions
│   └── Python Programs/     # Minimal Python code solutions
└── README.md               # This file
```

## C Programming Problems (Stack & Queue)

1. **1_stack_dynamic_array.c** - Stack implementation using dynamic array with PUSH, POP, PEEK, DISPLAY operations and algorithms
2. **2_queue_dynamic_array.c** - Queue implementation using dynamic array with all necessary functions
3. **3_reverse_string_stack.c** - String reversal using appropriate stack ADT
4. **4_double_stack.c** - Double stack implementation where both ends can be used for operations
5. **5_palindrome_stack.c** - Palindrome checker using stack ADT with case-insensitive and punctuation-ignoring functionality
6. **6_queue_using_stack.c** - Queue implementation using two stacks
7. **7_circular_queue.c** - Circular queue implementation with visualization

## Python Programming Problems (Stack & Queue)

1. **1_stack_implementation.py** - Complete stack implementation with error handling and interactive features
2. **2_queue_implementation.py** - Queue implementation with multiple approaches (list and deque)
3. **3_reverse_string_stack.py** - String reversal using stack with array implementation
4. **4_circular_queue.py** - Circular queue implementation using array with visualization
5. **5_stack_color_filter.py** - Stack color filtering function that removes non-primary colored boxes to a queue

## Key Features

### C Solutions
- **Dynamic memory allocation** for all data structures
- **Comprehensive algorithms** with step-by-step explanations
- **Error handling** and input validation
- **Memory management** best practices
- **Interactive menus** for testing operations
- **Visualization features** for better understanding

### Python Solutions
- **Object-oriented design** with proper encapsulation
- **Multiple implementation approaches** for comparison
- **Comprehensive error handling** with custom exceptions
- **Interactive demonstrations** and testing
- **Performance comparisons** between different methods
- **Edge case testing** and validation

## Algorithms Included

### Stack Operations
```
PUSH Algorithm:
1. Check if stack is full
2. If not full, increment top
3. Insert element at top position

POP Algorithm:
1. Check if stack is empty
2. If not empty, get top element
3. Decrement top and return element

PEEK Algorithm:
1. Check if stack is empty
2. If not empty, return top element

DISPLAY Algorithm:
1. Check if stack is empty
2. Traverse from top to bottom
3. Print all elements
```

### Queue Operations
```
ENQUEUE Algorithm:
1. Check if queue is full
2. If not full, increment rear
3. Insert element at rear position

DEQUEUE Algorithm:
1. Check if queue is empty
2. If not empty, get front element
3. Increment front and return element
```

## Special Implementations

### Double Stack
- Uses both ends of a single array
- Stack1 grows from left (index 0)
- Stack2 grows from right (index n-1)
- Efficient space utilization

### Circular Queue
- Overcomes limitation of linear queue
- Uses modular arithmetic for wrap-around
- Efficient space utilization
- No memory wastage

### Queue using Stack
- Uses two stacks to simulate queue behavior
- Stack1 for enqueue operations
- Stack2 for dequeue operations
- Maintains FIFO order

### Palindrome Checker
- Case-insensitive comparison
- Ignores whitespace and punctuation
- Uses stack for character reversal
- Handles complex palindromes

## Compilation and Execution

### For C Programs:
```bash
# Systematic solutions
cd "Systematic Solutions/C Programs"
gcc 1_stack_dynamic_array.c -o stack
./stack

# Compressed solutions
cd "Compressed Solutions/C Programs"
gcc 1_stack_dynamic_array.c -o stack
./stack
```

### For Python Programs:
```bash
# Systematic solutions
cd "Systematic Solutions/Python Programs"
python 1_stack_implementation.py

# Compressed solutions
cd "Compressed Solutions/Python Programs"
python 1_stack_implementation.py
```

## Testing Examples

### Stack Operations
```
Push: 10, 20, 30
Stack: [30, 20, 10] (top to bottom)
Pop: 30
Stack: [20, 10]
Peek: 20
```

### Queue Operations
```
Enqueue: 10, 20, 30
Queue: [10, 20, 30] (front to rear)
Dequeue: 10
Queue: [20, 30]
```

### Palindrome Examples
- "madam" → True
- "Taco cat" → True
- "A man, a plan, a canal: Panama" → True
- "hello" → False

### Color Filtering Example
```
Input Stack: ["Yellow", "Red", "Purple", "Green", "Orange", "Blue"]
Primary Colors: ["Red", "Green", "Blue"]
Final Stack: ["Red", "Green", "Blue"]
Removed Queue: ["Yellow", "Purple", "Orange"]
```

## Notes

- All C programs use dynamic memory allocation
- Python programs include both basic and efficient implementations
- Systematic solutions include comprehensive testing and demonstrations
- Compressed solutions focus on minimal code while maintaining functionality
- All solutions handle edge cases and error conditions
- Interactive modes available for hands-on testing
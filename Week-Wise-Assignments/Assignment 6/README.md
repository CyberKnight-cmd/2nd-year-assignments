# Assignment 6: Applications of Stack & Queue

This assignment contains comprehensive implementations of various applications of stack and queue data structures in both C and Python programming languages.

## 📁 Folder Structure

```
Assignment 6/
├── Systematic Solutions/
│   ├── C Programs/
│   │   ├── 1_postfix_evaluation.c
│   │   ├── 2_infix_to_postfix.c
│   │   ├── 3_priority_queue.c
│   │   ├── 4_factorial_stack.c
│   │   ├── 5_tower_of_hanoi.c
│   │   ├── 6_reverse_string.c
│   │   ├── 7_parenthesis_validation.c
│   │   └── 8_html_validation.c
│   └── Python Programs/
│       ├── 1_factorial_stack.py
│       ├── 2_tower_of_hanoi.py
│       ├── 3_reverse_string.py
│       └── 4_parenthesis_validation.py
├── Compressed Solutions/
│   ├── C Programs/
│   │   ├── 1_postfix_evaluation.c
│   │   ├── 2_infix_to_postfix.c
│   │   ├── 3_priority_queue.c
│   │   ├── 4_factorial_stack.c
│   │   ├── 5_tower_of_hanoi.c
│   │   ├── 6_reverse_string.c
│   │   ├── 7_parenthesis_validation.c
│   │   └── 8_html_validation.c
│   └── Python Programs/
│       ├── 1_factorial_stack.py
│       ├── 2_tower_of_hanoi.py
│       ├── 3_reverse_string.py
│       └── 4_parenthesis_validation.py
└── README.md
```

## 🎯 Problem Statements

### C Programming Problems (8 Programs)

1. **Postfix Expression Evaluation**: Evaluate postfix expressions using stack
2. **Infix to Postfix Conversion**: Convert infix expressions to postfix using stack
3. **Priority Queue Implementation**: Implement priority queue with enqueue/dequeue operations
4. **Factorial using Stack**: Calculate factorial using stack data structure
5. **Tower of Hanoi using Stack**: Solve Tower of Hanoi puzzle using stacks
6. **String Reversal using Stack**: Reverse strings using stack operations
7. **Parenthesis Validation**: Validate balanced parentheses using stack
8. **HTML Validation**: Validate HTML tag structure using stack

### Python Programming Problems (4 Programs)

1. **Factorial using Stack**: Calculate factorial using stack data structure
2. **Tower of Hanoi using Stack**: Solve Tower of Hanoi puzzle using stacks
3. **String Reversal using Stack**: Reverse strings using stack operations
4. **Parenthesis Validation**: Validate balanced parentheses using stack

## 🔧 Implementation Approaches

### Systematic Solutions
- **Interactive Menu Systems**: User-friendly interfaces for all operations
- **Step-by-Step Algorithms**: Detailed process explanations and visualizations
- **Comprehensive Error Handling**: Robust input validation and edge cases
- **Educational Features**: Algorithm explanations and learning aids
- **Multiple Examples**: Sample inputs and demonstrations
- **Comparison Methods**: Alternative approaches for verification

### Compressed Solutions
- **Minimal Code**: Essential functionality in shortest form
- **Core Algorithms**: Focus on primary logic without verbose features
- **Direct Implementation**: Quick execution and testing
- **Optimized for Brevity**: Maximum efficiency in minimum lines

## 📚 Key Applications Implemented

### 1. Expression Evaluation & Conversion
**Postfix Evaluation Algorithm:**
```
1. Scan expression left to right
2. If operand: push to stack
3. If operator: pop two operands, compute, push result
4. Final result is stack top
```

**Infix to Postfix Algorithm:**
```
1. Scan infix left to right
2. If operand: add to output
3. If '(': push to stack
4. If ')': pop until '(' and add to output
5. If operator: pop higher/equal precedence, then push
6. Pop remaining operators
```

### 2. Priority Queue Operations
**Enqueue Algorithm:**
```
1. Find correct position based on priority
2. Shift elements to make space
3. Insert element at correct position
```

**Dequeue Algorithm:**
```
1. Remove highest priority element (first)
2. Shift remaining elements forward
```

### 3. Mathematical Applications
**Factorial using Stack:**
```
1. Push numbers n to 1 onto stack
2. Pop and multiply to calculate factorial
3. Simulates recursive nature using LIFO
```

**Tower of Hanoi using Stack:**
```
1. Use three stacks for three towers
2. Implement iterative solution with pattern
3. Move disks following rules using stack operations
```

### 4. String Processing
**String Reversal:**
```
1. Push all characters onto stack
2. Pop characters to get reversed string
3. LIFO naturally reverses order
```

**Parenthesis Validation:**
```
1. Push opening brackets onto stack
2. For closing brackets, check match with stack top
3. Valid if stack empty at end
```

### 5. Markup Validation
**HTML Validation:**
```
1. Extract HTML tags from content
2. Push opening tags, match closing tags
3. Handle self-closing tags appropriately
4. Valid if all tags properly matched
```

## 📊 Algorithm Analysis

### Time & Space Complexities

| Application | Time Complexity | Space Complexity | Notes |
|-------------|----------------|------------------|-------|
| Postfix Evaluation | O(n) | O(n) | Single pass, stack for operands |
| Infix to Postfix | O(n) | O(n) | Single pass, stack for operators |
| Priority Queue Insert | O(n) | O(1) | Linear search for position |
| Priority Queue Remove | O(n) | O(1) | Shift elements after removal |
| Factorial Stack | O(n) | O(n) | Push n elements, pop n elements |
| Tower of Hanoi | O(2^n) | O(n) | Exponential moves, linear space |
| String Reversal | O(n) | O(n) | Push n chars, pop n chars |
| Parenthesis Validation | O(n) | O(n) | Single pass, stack for brackets |
| HTML Validation | O(n) | O(d) | n = content length, d = nesting depth |

## 🔍 Key Algorithms & Techniques

### 1. Stack-Based Expression Processing
- **Operator Precedence Handling**: Using stack to manage operator priorities
- **Parentheses Processing**: Stack naturally handles nested expressions
- **Postfix Evaluation**: Stack-based computation of mathematical expressions

### 2. Priority Queue Implementation
- **Insertion Sort Approach**: Maintain sorted order during insertion
- **Linear Search**: Find correct position for new elements
- **Array-Based Implementation**: Simple and efficient for moderate sizes

### 3. Recursive Simulation
- **Stack as Call Stack**: Simulating recursive calls with explicit stack
- **LIFO for Backtracking**: Natural fit for problems requiring backtracking
- **State Management**: Using stack to maintain problem state

### 4. Pattern Matching
- **Bracket Matching**: Using stack to match opening/closing pairs
- **Nested Structure Validation**: Stack handles arbitrary nesting levels
- **Error Detection**: Identifying mismatched or unbalanced structures

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

1. **Stack Applications**: Understanding practical uses of stack data structure
2. **Algorithm Design**: Learning to choose appropriate data structures for problems
3. **Expression Processing**: Mastering infix/postfix conversion and evaluation
4. **Priority Systems**: Implementing priority-based data structures
5. **Recursive Simulation**: Using stacks to simulate recursive processes
6. **Pattern Recognition**: Applying stacks to pattern matching problems
7. **Error Handling**: Developing robust validation and error detection

## 🔍 Key Features

### Systematic Solutions
- ✅ Interactive menu-driven interfaces
- ✅ Step-by-step algorithm visualization
- ✅ Comprehensive error handling and validation
- ✅ Educational explanations and demonstrations
- ✅ Multiple test cases and examples
- ✅ Comparison with alternative methods

### Compressed Solutions
- ✅ Minimal, optimized implementations
- ✅ Core algorithm focus
- ✅ Essential functionality only
- ✅ Quick testing and demonstration
- ✅ Maximum efficiency in minimum code

## 🎯 Real-World Applications

### Expression Processing
- **Calculators**: Postfix evaluation for mathematical expressions
- **Compilers**: Infix to postfix conversion in expression parsing
- **Spreadsheets**: Formula evaluation and precedence handling

### Priority Systems
- **Operating Systems**: Process scheduling with priorities
- **Network Routing**: Packet prioritization in routers
- **Task Management**: Priority-based task scheduling

### Validation Systems
- **Code Editors**: Bracket matching and syntax validation
- **Web Browsers**: HTML/XML tag validation
- **Compilers**: Syntax checking and error detection

### Problem Solving
- **Game AI**: Tower of Hanoi and similar puzzles
- **Backtracking**: Using stack for state management
- **Undo Systems**: Stack-based operation reversal

## 📈 Complexity Comparison

### Stack vs Other Approaches

| Problem | Stack Approach | Alternative | Advantage |
|---------|---------------|-------------|-----------|
| String Reversal | O(n) time, O(n) space | Two pointers O(n) time, O(1) space | Natural, intuitive |
| Parentheses | O(n) time, O(n) space | Counter-based O(n) time, O(1) space | Handles multiple types |
| Postfix Eval | O(n) time, O(n) space | Recursive O(n) time, O(n) space | Iterative, clear |
| Factorial | O(n) time, O(n) space | Iterative O(n) time, O(1) space | Educational, recursive simulation |

## 🔧 Advanced Features

### Error Handling
- **Input Validation**: Comprehensive checking of user inputs
- **Edge Case Management**: Handling empty inputs, overflow conditions
- **Graceful Degradation**: Meaningful error messages and recovery

### Educational Tools
- **Algorithm Visualization**: Step-by-step process demonstration
- **Comparison Methods**: Multiple approaches for same problem
- **Interactive Learning**: Menu-driven exploration of concepts

### Performance Optimization
- **Memory Management**: Efficient allocation and deallocation
- **Algorithm Efficiency**: Optimal time and space complexity
- **Code Optimization**: Clean, readable, and maintainable code

This assignment provides comprehensive understanding of stack and queue applications with both theoretical knowledge and practical implementation skills.
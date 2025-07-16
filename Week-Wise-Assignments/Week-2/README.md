Here is a **complete detailed explanation** of **Stacks** for your fundamentals, coding, and conceptual mastery, before moving to queues.

---

# 📚 **STACK – In-depth Study Note**

## **I. What is a Stack?**

✅ A **linear data structure** that follows **LIFO** (Last In First Out) principle.
✅ Think of a **stack of plates** – you place (push) a plate on top and remove (pop) the topmost plate first.

---

### **II. How does it work?**

| Operation          | Description                                               |
| ------------------ | --------------------------------------------------------- |
| **PUSH(x)**        | Adds element x to top of stack                            |
| **POP()**          | Removes and returns top element                           |
| **PEEK() / TOP()** | Returns top element without removing                      |
| **isEmpty()**      | Checks if stack has no elements                           |
| **isFull()**       | (For static array stack) Checks if stack reached max size |

---

### **III. Memory Structure**

✅ Uses a **single pointer: TOP** to keep track of the stack's topmost item.
✅ Initially `TOP = -1` (empty stack).
✅ On PUSH, increment `TOP` and insert.
✅ On POP, retrieve value at `TOP` and decrement `TOP`.

---

### **IV. Stack Implementation**

#### **A. Static Array Implementation**

* Fixed size, easy to code, fast access.
* Limitation: Cannot expand beyond defined size.

#### **B. Dynamic Array Implementation**

* Uses `malloc`/`realloc` in C or dynamic lists in Python.
* Expands when needed.

#### **C. Linked List Implementation**

* Each node is a stack item with pointer to next.
* No size limit (except system memory).

---

## **V. Coding Stack – C Implementation**

Here is a **simple static array stack** implementation in C with all operations:

```c
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
    printf("%d pushed to stack\n", x);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top];
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Top element is %d\n", peek());
    printf("%d popped from stack\n", pop());
    display();
    return 0;
}
```

✅ **Output Explanation**

```
10 pushed to stack
20 pushed to stack
30 pushed to stack
Stack elements: 30 20 10
Top element is 30
30 popped from stack
Stack elements: 20 10
```

---

### **VI. Coding Stack – Python Implementation**

In Python, **lists are dynamic arrays** and can be used directly as stack:

```python
stack = []

# PUSH operation
stack.append(10)
stack.append(20)
stack.append(30)
print("Stack after pushes:", stack)

# PEEK operation
print("Top element is", stack[-1])

# POP operation
print("Popped element:", stack.pop())
print("Stack after pop:", stack)

# Checking if stack is empty
if not stack:
    print("Stack is empty")
else:
    print("Stack is not empty")
```

✅ **Output**

```
Stack after pushes: [10, 20, 30]
Top element is 30
Popped element: 30
Stack after pop: [10, 20]
Stack is not empty
```

---

### **VII. Different Behaviours & Edge Cases**

✅ **1. Empty Stack (Underflow)**

* Attempting POP or PEEK on empty stack leads to underflow error.
* Example: `top = -1` and POP called.

✅ **2. Full Stack (Overflow)**

* Only in static array implementation.
* If `top == MAX-1`, further PUSH leads to overflow.

✅ **3. Stack with Dynamic Size**

* Using dynamic arrays or linked lists removes overflow issue unless memory is exhausted.

✅ **4. Order of Operations**

* LIFO behaviour must be maintained.
* e.g. Pushing 10, 20, 30 will have 30 popped first.

---

### **VIII. Real-World Use Cases**

| Application               | Description                                                      |
| ------------------------- | ---------------------------------------------------------------- |
| **Recursion Call Stack**  | System stack stores function calls and returns in reverse order. |
| **Undo/Redo**             | Most recent operation undone first.                              |
| **Backtracking**          | E.g. maze solving, N-Queens – store states to backtrack.         |
| **Expression Evaluation** | Infix to Postfix conversion and evaluation uses stacks.          |
| **Syntax Parsing**        | Compilers use stacks to parse nested structures.                 |

---

### **IX. Advanced Topics for Stack**

✅ **Two Stacks in One Array** – Optimize space by growing from two ends.
✅ **Min Stack Problem** – Design stack supporting getMin() in O(1).
✅ **Implement Stack using Queues** – Interview conceptual question.
✅ **Multiple Stacks Sharing Space** – Useful in OS resource optimization.

---

### **X. Key Takeaways for Coding**

1. Always check for **underflow/overflow** in static stacks.
2. Free memory in linked list stack implementation.
3. Use meaningful function names for clarity.
4. Test edge cases (empty stack, single element stack).
5. Understand LIFO deeply; most stack problems derive from this property.

---


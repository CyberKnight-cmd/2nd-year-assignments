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

Here is a [**dynamic stack**](dynamic-array-stack.c) implementation in C.

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

- **Two Stacks in One Array** – Optimize space by growing from two ends.
- **Min Stack Problem** – Design stack supporting getMin() in O(1).
- **Implement Stack using Queues** – Interview conceptual question.
- **Multiple Stacks Sharing Space** – Useful in OS resource optimization.

---

### **X. Key Takeaways for Coding**

1. Always check for **underflow/overflow** in static stacks.
2. Free memory in linked list stack implementation.
3. Use meaningful function names for clarity.
4. Test edge cases (empty stack, single element stack).
5. Understand LIFO deeply; most stack problems derive from this property.

---

# 📚 **QUEUE – In-depth Study Note**

## **I. What is a Queue?**

✅ A **linear data structure** that follows **FIFO** (First In First Out) principle.

> **Example:**
> People standing in a line – the first person in the line is served first.

---

### **II. Basic Operations**

| Operation            | Description                                                |
| -------------------- | ---------------------------------------------------------- |
| **ENQUEUE(x)**       | Insert element x at the rear.                              |
| **DEQUEUE()**        | Remove element from front.                                 |
| **PEEK() / FRONT()** | View front element without removing.                       |
| **isEmpty()**        | Checks if queue has no elements.                           |
| **isFull()**         | (For static array queue) Checks if queue reached max size. |

---

## **III. Implementation Methods**

### **1. Static Array Queue**

* Uses fixed size array.
* Simple to implement.
* Problem: **False Overflow** if front moves ahead but rear reaches end.

---

### **2. Dynamic Array Queue**

* Uses `malloc`/`realloc` to adjust size dynamically.
* Complex shifting of elements after dequeue unless implemented as **circular queue**.
* Here is the [**dynamic queue implementation**](dynamic-array-queue.c)

---

### **3. Circular Queue**

* Treats array as circular buffer.
* Front and rear wrap around when reaching end of array.
* Solves **false overflow problem**.

---

### **4. Linked List Queue**

* Uses dynamically allocated nodes.
* No size limitation except system memory.
* Maintains **front and rear pointers**.

---

## **IV. Coding Queue – Static Array Implementation**

Here is a **simple queue code using static array** in C with basic explanation.

---

### 📝 **Queue Code (C)**

```c
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) // first insertion
        front = 0;
    queue[++rear] = x;
    printf("%d enqueued to queue\n", x);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue[front];
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Front element is %d\n", peek());

    printf("%d dequeued from queue\n", dequeue());
    display();

    return 0;
}
```

---

### ✅ **Short Explanation**

1. **front** points to first element
2. **rear** points to last inserted element
3. On **enqueue**, increment rear and insert
4. On **dequeue**, increment front and return removed item

---

## **V. Queue in Python**

In Python, you can use **lists or collections.deque** as queues.

### 📝 **Simple Queue using List**

```python
queue = []

# ENQUEUE
queue.append(10)
queue.append(20)
queue.append(30)
print("Queue after enqueues:", queue)

# DEQUEUE
print("Dequeued element:", queue.pop(0))
print("Queue after dequeue:", queue)

# PEEK
if queue:
    print("Front element is", queue[0])
else:
    print("Queue is empty")
```

✅ Using `pop(0)` is O(n) as it shifts elements. For efficient queues, use `collections.deque`.

---

## **VI. Different Behaviours & Edge Cases**

✅ **1. Empty Queue (Underflow)**

* Attempting dequeue or peek on empty queue results in underflow error.

✅ **2. Full Queue (Overflow)**

* Only in static array implementation.
* If `rear == MAX-1` → cannot insert more.

✅ **3. False Overflow**

* In static array queue, if front moves ahead due to dequeues, but rear reached MAX-1, you cannot insert even though empty slots are at start.
* **Circular queue** solves this problem.

---

## **VII. Real-world Use Cases**

| Application                    | Description                                               |
| ------------------------------ | --------------------------------------------------------- |
| **CPU Scheduling**             | Round Robin uses queue to manage process execution order. |
| **Printer Queue**              | Print jobs are processed in order of arrival.             |
| **Breadth First Search (BFS)** | Uses queue to traverse levels of graphs/trees.            |
| **Message Queues**             | OS and networking use queues for data packets.            |

---

# 📚 **CIRCULAR QUEUE – Study Note**

## **I. What is a Queue? (Quick Recap)**

✅ **Queue** is a **linear data structure** following **FIFO** principle.

| Operation  | Description                          |
| ---------- | ------------------------------------ |
| ENQUEUE(x) | Insert element x at rear.            |
| DEQUEUE()  | Remove element from front.           |
| PEEK()     | View front element without removing. |

### **Example:**

People standing in line at ticket counter.

---

### **Implementation – Static Array Queue**

✅ Uses an array with two pointers: **front** and **rear**.

* `front`: Index of first element.
* `rear`: Index of last element.

---

## **II. Problem with Normal Array Queue**

### ⚠️ **False Overflow Problem**

After multiple dequeue operations:

```
Initial: [10,20,30]
front = 0, rear = 2

After dequeue:
front = 1, rear = 2

After two more dequeues:
front = 3, rear = 2
Queue is empty, but rear reached end.
```

✅ Even if there are empty slots at the start, **you cannot insert more** because rear reached MAX size.

---

## **III. What is a Circular Queue?**

✅ **Circular Queue** is a linear queue concept **implemented circularly**, treating array as a ring buffer.

### **How it works?**

* When **rear** reaches the end of array, it wraps around to **index 0** if there is space.

---

### 🔁 **Visual Example**

Array size = 5

| Step        | Front           | Rear | Queue Array           |
| ----------- | --------------- | ---- | --------------------- |
| ENQUEUE(10) | 0               | 0    | \[10, \_, \_, \_, \_] |
| ENQUEUE(20) | 0               | 1    | \[10,20,*,*,\_]       |
| ENQUEUE(30) | 0               | 2    | \[10,20,30,*,*]       |
| DEQUEUE()   | 1               | 2    | \[*,20,30,*,\_]       |
| ENQUEUE(40) | 1               | 3    | \[*,20,30,40,*]       |
| ENQUEUE(50) | 1               | 4    | \[\_,20,30,40,50]     |
| ENQUEUE(60) | rear wraps to 0 | 0    | \[60,20,30,40,50]     |

---

### ✅ **Key Concept**

* **Queue is full** when next position of rear is front:

```c
(rear + 1) % size == front
```

* **Queue is empty** when front == -1.

---

## **IV. Circular Queue Operations Summary**

| Operation   | Steps                                                                                          |
| ----------- | ---------------------------------------------------------------------------------------------- |
| **ENQUEUE** | Check if full → insert at rear → `(rear + 1) % size`                                           |
| **DEQUEUE** | Check if empty → remove at front → if front == rear reset both to -1 else `(front + 1) % size` |
| **PEEK**    | Return item at front if not empty                                                              |

---

## **V. Advantages of Circular Queue**

✅ **Efficient Space Utilisation**

* Reuses vacant slots at start of array
* No need to shift elements as in normal queue

✅ **Widely used in**

* CPU Scheduling (Round Robin)
* Circular Buffers in streaming systems
* Embedded systems queue management

---

## **VI. Coding Circular Queue – Static Array Implementation (C)**

Here is **simple clean code with minimal explanation**:

```c
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;
    queue[rear] = x;
    printf("%d enqueued to queue\n", x);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) // only one element
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
    return item;
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // fills queue
    display();

    printf("%d dequeued from queue\n", dequeue());
    display();

    enqueue(60); // inserts at wrapped around index
    display();

    return 0;
}
```

---

### ✅ **Output**

```
10 enqueued to queue
20 enqueued to queue
30 enqueued to queue
40 enqueued to queue
50 enqueued to queue
Queue elements: 10 20 30 40 50 
10 dequeued from queue
Queue elements: 20 30 40 50 
60 enqueued to queue
Queue elements: 20 30 40 50 60 
```

---

## **VII. Final Summary**

| **Normal Queue**         | **Circular Queue**             |
| ------------------------ | ------------------------------ |
| Can face false overflow  | No false overflow              |
| Front moves only forward | Front and rear wrap around     |
| Inefficient space usage  | Efficient space usage          |
| Easy logic               | Slightly complex but practical |

---
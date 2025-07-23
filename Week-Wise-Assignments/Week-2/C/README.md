# Assignment – II

**Subject:** Data Structures (Stack & Queue)
**Language:** C Programming
**Date:** 24 July 2025

---

## Contents

| Program     | Description                                                                                                                                                                                | Solution Link        |
| ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | -------------------- |
| **Prog1.c** | Stack implementation using dynamic array with **PUSH**, **POP**, **PEEK**, **DISPLAY** operations.                                                                                         | [Prog1.c](./Prog1.c) |
| **Prog2.c** | Queue implementation using dynamic array with all fundamental queue functions.                                                                                                             | [Prog2.c](./Prog2.c) |
| **Prog3.c** | Reversing a string using an appropriate ADT (stack).                                                                                                                                       | [Prog3.c](./Prog3.c) |
| **Prog4.c** | Double stack implementation allowing operations from both ends.                                                                                                                            | [Prog4.c](./Prog4.c) |
| **Prog5.c** | Palindrome verification using appropriate ADT with `is_palindrome(char *text)` function. Includes: ignoring whitespaces/punctuation, case-insensitive comparison, and multiple test cases. | [Prog5.c](./Prog5.c) |
| **Prog6.c** | Queue implementation using stack (two stacks approach).                                                                                                                                    | [Prog6.c](./Prog6.c) |
| **Prog7.c** | Circular queue implementation using dynamic array.                                                                                                                                         | [Prog7.c](./Prog7.c) |

---

## Execution Instructions

1. **Compile** each program:

   ```bash
   gcc ProgX.c -o ProgX.exe
   ```

   Replace `X` with respective program number.

2. **Run** each executable:

   ```bash
   ./ProgX.exe
   ```

3. Ensure GCC is installed and terminal path is set to the project directory.

---

## Algorithms & Notes

1. **Stack (Prog1.c)**

   * Uses `malloc` / `realloc` for dynamic sizing.
   * Includes **underflow checks** for pop and peek.

2. **Queue (Prog2.c)**

   * Dynamic array with front and rear index management.

3. **String Reversal (Prog3.c)**

   * Push each character into a stack, then pop to reverse.

4. **Double Stack (Prog4.c)**

   * Single array, two pointers growing from opposite ends.

5. **Palindrome Checker (Prog5.c)**

   * Removes punctuation, ignores whitespace, case-insensitive.
   * Uses ADT for efficient reversal and comparison.

6. **Queue using Stack (Prog6.c)**

   * Two stacks: enqueue stack and dequeue stack for O(1) amortized dequeue.

7. **Circular Queue (Prog7.c)**

   * Front and rear managed using modulo to wrap around.

---

## Author

* **Arya Gupta**
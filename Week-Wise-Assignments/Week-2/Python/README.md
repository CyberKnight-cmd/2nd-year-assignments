# Assignment – II

**Subject:** Data Structures (Stack & Queue)
**Language:** Python
**Date:** 27 July 2025

---

## Contents

| Program       | Description                                                                                                                                             | Solution Link            |
| ------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------ |
| **Prog1.py**  | Stack implementation using Python class with `push`, `pop`, `peek`, and `display` operations.                                                           | [Prog1.py](./Prog1.py)   |
| **Prog2.py**  | Queue implementation using Python list with `enqueue`, `dequeue`, `peek`, and `display` functions.                                                      | [Prog2.py](./Prog2.py)   |
| **Prog3.py**  | Reversing a string using a stack (implemented via list). Push all characters, then pop to reverse.                                                      | [Prog3.py](./Prog3.py)   |
| **Prog4.py**  | Circular Queue using array (list) with `front`, `rear`, and modular arithmetic to wrap around.                                                          | [Prog4.py](./Prog4.py)   |
| **Prog5.py**  | Accepts a stack of colored boxes. Removes all non-primary colors (`Red`, `Green`, `Blue`) to a queue. Maintains original order in both stack and queue. | [Prog5.py](./Prog5.py)   |
| **GUIApp.py** | Bonus GUI-based sorting visualizer built using `Tkinter` and `matplotlib`. User can interactively observe sorting algorithms in action.                 | [GUIApp.py](./GUIApp.py) |

---

## Execution Instructions

1. **Ensure Python 3 is installed**
   You can check with `python --version` or `python3 --version`.

2. **Run a specific program**:

   ```bash
   python ProgX.py
   ```

   Replace `X` with the respective program number.

3. **Run GUI application**:

   ```bash
   python GUIApp.py
   ```

   Make sure you have the required packages:

   ```bash
   pip install matplotlib
   ```

---

## Algorithms & Notes

1. **Stack (Prog1.py)**

   * Implemented using a simple list with O(1) push/pop.
   * Uses Python exceptions to handle underflow gracefully.
   * Includes functions for `push`, `pop`, `peek`, `display`.

2. **Queue (Prog2.py)**

   * Uses list for enqueue and dequeue.
   * Proper front/back index handling.
   * Checks for underflow/overflow conditions.

3. **String Reversal (Prog3.py)**

   * Push all characters to stack.
   * Pop them out to get reversed string.

4. **Circular Queue (Prog4.py)**

   * Uses modulo arithmetic for circular indexing.
   * Fixed-size queue simulation using array/list.
   * Handles wraparound conditions and full/empty cases.

5. **Color Stack & Queue (Prog5.py)**

   * Accepts a list of colors.
   * Pushes primary colors (`Red`, `Green`, `Blue`) to stack.
   * Non-primary colors go to a queue.
   * Case-sensitive comparison included.
   * Queue class is re-used and well-integrated.

6. **GUI Sorting Visualizer (GUIApp.py)**

   * Visual interface for observing sorting algorithms.
   * Interactive controls: number of elements, sorting speed, algorithm type.
   * Real-time bar graph updates using `matplotlib`.

---

## Author

* **Arya Gupta**

---

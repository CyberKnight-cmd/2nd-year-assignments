# 📝 Dynamic Array Programs in C

This repository contains **10 programs** demonstrating dynamic array operations in C using `malloc`, `calloc`, `realloc`, and pointer techniques.

---

## 📌 **Programs List with Explanations, Use Cases, and Test Cases**

### **1. Search an Element in a Dynamic Array**

🔷 **Problem:**  
Input an array dynamically and search for a user-defined element.

🔷 **Use case:**  
Searching student IDs, roll numbers, or item codes from runtime inputs.

🔷 **Test case example:**  
```

Input: n = 5
Array: \[10, 20, 30, 40, 50]
Key: 30
Output: 30 found at index 2

```

🔗 **[Solution](./Prog1.c)**

---

### **2. Find kth Maximum Element in a Dynamic Array**

🔷 **Problem:**  
Find the kth largest element (e.g. 3rd maximum) in a dynamic array.

🔷 **Use case:**  
Leaderboard ranking, top scores, or priority data extraction.

🔷 **Test case example:**  
```

Input: n = 6
Array: \[11, 25, 43, 89, 57, 99]
k = 3
Output: 57 is the 3rd maximum number

```

🔗 **[Solution](./Prog2.c)**

---

### **3. Find Minimum Element in a Dynamic Array**

🔷 **Problem:**  
Input elements and find the minimum value using dynamic memory.

🔷 **Use case:**  
Finding minimum marks, minimum temperature readings, etc.

🔷 **Test case example:**  
```

Input: n = 4
Array: \[55, 12, 78, 33]
Output: Minimum = 12

```

🔗 **[Solution](./Prog3.c)**

---

### **4. Search an Element in a 2D Dynamic Array**

🔷 **Problem:**  
Search for a user-defined value in a dynamically allocated 2D matrix.

🔷 **Use case:**  
Finding items in grid data like seating plans, matrices, or tables.

🔷 **Test case example:**  
```

Input: m=2, n=3
Array: \[\[1,2,3],\[4,5,6]]
Key: 5
Output: 5 found at (1,1)

```

🔗 **[Solution](./Prog4.c)**

---

### **5. Find Maximum Element in a 2D Dynamic Array**

🔷 **Problem:**  
Find the largest value in a dynamically created 2D array.

🔷 **Use case:**  
Maximum rainfall data in a grid, highest temperature across regions, etc.

🔷 **Test case example:**  
```

Input: \[\[7,2],\[3,9]]
Output: Maximum = 9

```

🔗 **[Solution](./Prog5.c)**

---

### **6. Find Minimum Element in a 2D Dynamic Array**

🔷 **Problem:**  
Find the smallest value in a 2D array using dynamic memory allocation.

🔷 **Use case:**  
Lowest prices across a store grid, minimum elevation data, etc.

🔷 **Test case example:**  
```

Input: \[\[8,3],\[6,4]]
Output: Minimum = 3

```

🔗 **[Solution](./Prog6.c)**

---

### **7. Merge Two Sorted Dynamic Arrays**

🔷 **Problem:**  
Merge two sorted arrays into a single sorted array.

🔷 **Use case:**  
Merging two ordered datasets like student lists from two classes.

🔷 **Test case example:**  
```

Input: arr1 = \[10,20,30], arr2 = \[15,25,35]
Output: \[10,15,20,25,30,35]

```

🔗 **[Solution](./Prog7.c)**

---

### **8. Merge Two Unsorted Dynamic Arrays in Sorted Order**

🔷 **Problem:**  
Merge two unsorted arrays and sort the final merged array.

🔷 **Use case:**  
Combining unordered inventory from two warehouses and sorting it.

🔷 **Test case example:**  
```

Input: arr1 = \[5,2,8], arr2 = \[7,1,6]
Output: \[1,2,5,6,7,8]

```

🔗 **[Solution](./Prog8.c)**

---

### **9. Delete a Range of Data from a Dynamic Array**

🔷 **Problem:**  
Delete elements between a given lower and upper index (inclusive) and resize the array dynamically.

🔷 **Use case:**  
Removing invalid entries or bulk-deleting data within a range.

🔷 **Test case example:**  
```

Input: \[10,20,30,40,50], lower=1, upper=3
Output: \[10,50]

```

🔗 **[Solution](./Prog9.c)**

---

### **10. Modify the Size of an Array at Runtime**

🔷 **Problem:**  
Change the size of a dynamic array during runtime using `realloc`.

🔷 **Use case:**  
Adding new data entries dynamically, extending array capacity, or shrinking to optimize memory.

🔷 **Test case example:**  
```

Initial input: \[1,2,3]
Extend to: \[1,2,3,4,5] after realloc

```

🔗 **[Solution](./Prog10.c)**

---

## 💻 **Compilation & Execution**

```bash
gcc Prog1.c -o Prog1.exe
./Prog1.exe
````

Repeat for each program (`Prog2.c`, `Prog3.c`, ..., `Prog10.c`).

---

## 🔑 **Key Concepts**

* Dynamic memory allocation (`malloc`, `calloc`, `realloc`, `free`)
* Pointers and 2D arrays
* Searching, merging, sorting, deleting, resizing arrays at runtime

---

### ✨ **Author**

Programs written as part of **Dynamic Array practice in C Programming** for University Data Structures learning.

---


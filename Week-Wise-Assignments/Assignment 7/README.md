# Assignment 7: Searching & Sorting Algorithms

This assignment contains comprehensive implementations of fundamental searching and sorting algorithms in both C and Python programming languages.

## 📁 Folder Structure

```
Assignment 7/
├── Systematic Solutions/
│   ├── C Programs/
│   │   ├── 1_bubble_sort.c
│   │   ├── 2_selection_sort.c
│   │   ├── 3_insertion_sort.c
│   │   ├── 4_merge_sort.c
│   │   ├── 5_linear_search.c
│   │   ├── 6_binary_search.c
│   │   └── 7_hashing.c
│   └── Python Programs/
│       ├── 1_bubble_sort.py
│       ├── 2_selection_sort.py
│       ├── 3_insertion_sort.py
│       ├── 4_merge_sort.py
│       └── 5_linear_search.py
├── Compressed Solutions/
│   ├── C Programs/
│   │   ├── 1_bubble_sort.c
│   │   ├── 2_selection_sort.c
│   │   ├── 3_insertion_sort.c
│   │   ├── 4_merge_sort.c
│   │   ├── 5_linear_search.c
│   │   ├── 6_binary_search.c
│   │   └── 7_hashing.c
│   └── Python Programs/
│       ├── 1_bubble_sort.py
│       ├── 2_selection_sort.py
│       ├── 3_insertion_sort.py
│       ├── 4_merge_sort.py
│       └── 5_linear_search.py
└── README.md
```

## 🎯 Problem Statements

### C Programming Problems (7 Programs)

1. **Bubble Sort**: Simple comparison-based sorting with adjacent element swapping
2. **Selection Sort**: Find minimum element and place at correct position
3. **Insertion Sort**: Build sorted array one element at a time
4. **Merge Sort**: Divide and conquer sorting algorithm
5. **Linear Search**: Sequential search through array elements
6. **Binary Search**: Efficient search for sorted arrays
7. **Hashing**: Hash table implementation with collision resolution

### Python Programming Problems (5 Programs)

1. **Bubble Sort**: Simple comparison-based sorting algorithm
2. **Selection Sort**: Minimum element selection and placement
3. **Insertion Sort**: Incremental sorted array construction
4. **Merge Sort**: Recursive divide and conquer sorting
5. **Linear Search**: Sequential element searching

## 🔧 Implementation Approaches

### Systematic Solutions
- **Interactive Menu Systems**: User-friendly interfaces for all algorithms
- **Step-by-Step Visualizations**: Detailed process demonstrations
- **Performance Analysis**: Complexity analysis and benchmarking
- **Multiple Variants**: Different implementations and optimizations
- **Educational Features**: Algorithm explanations and learning aids
- **Comprehensive Testing**: Various test cases and edge scenarios

### Compressed Solutions
- **Minimal Code**: Essential algorithm implementation only
- **Core Logic Focus**: Primary functionality without verbose features
- **Quick Execution**: Direct implementation for immediate testing
- **Optimized for Brevity**: Maximum efficiency in minimum lines

## 📚 Sorting Algorithms Implemented

### 1. Bubble Sort
**Algorithm:**
```
1. Compare adjacent elements
2. Swap if they are in wrong order
3. Repeat for all elements
4. Largest element "bubbles up" after each pass
```

**Characteristics:**
- **Time Complexity**: O(n²) average/worst, O(n) best
- **Space Complexity**: O(1)
- **Stability**: Stable
- **In-place**: Yes
- **Adaptive**: Yes

### 2. Selection Sort
**Algorithm:**
```
1. Find minimum element in unsorted portion
2. Swap with first element of unsorted portion
3. Move boundary between sorted/unsorted
4. Repeat until entire array is sorted
```

**Characteristics:**
- **Time Complexity**: O(n²) all cases
- **Space Complexity**: O(1)
- **Stability**: Not stable
- **In-place**: Yes
- **Adaptive**: No

### 3. Insertion Sort
**Algorithm:**
```
1. Start with second element
2. Compare with elements in sorted portion
3. Shift larger elements right
4. Insert current element at correct position
```

**Characteristics:**
- **Time Complexity**: O(n²) average/worst, O(n) best
- **Space Complexity**: O(1)
- **Stability**: Stable
- **In-place**: Yes
- **Adaptive**: Yes

### 4. Merge Sort
**Algorithm:**
```
1. Divide array into two halves
2. Recursively sort both halves
3. Merge sorted halves back together
```

**Characteristics:**
- **Time Complexity**: O(n log n) all cases
- **Space Complexity**: O(n)
- **Stability**: Stable
- **In-place**: No
- **Adaptive**: No

## 🔍 Searching Algorithms Implemented

### 1. Linear Search
**Algorithm:**
```
1. Start from first element
2. Compare each element with target
3. Return index if found
4. Return -1 if not found
```

**Characteristics:**
- **Time Complexity**: O(n) worst, O(1) best
- **Space Complexity**: O(1)
- **Prerequisites**: None (works on unsorted arrays)
- **Variants**: Sentinel search, early termination

### 2. Binary Search
**Algorithm:**
```
1. Find middle element
2. Compare with target
3. Search left half if target < middle
4. Search right half if target > middle
5. Repeat until found or search space empty
```

**Characteristics:**
- **Time Complexity**: O(log n)
- **Space Complexity**: O(1) iterative, O(log n) recursive
- **Prerequisites**: Sorted array
- **Variants**: First/last occurrence, count occurrences

## 🗂️ Hashing Implementation

### Hash Functions
1. **Division Method**: h(k) = k mod m
2. **Multiplication Method**: h(k) = floor(m * (k*A mod 1))
3. **Mid-Square Method**: h(k) = middle digits of k²

### Collision Resolution
1. **Linear Probing**: h'(k) = (h(k) + i) mod m
2. **Quadratic Probing**: h'(k) = (h(k) + i²) mod m

## 📊 Complexity Analysis

### Sorting Algorithms Comparison

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable |
|-----------|-----------|--------------|------------|-------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |

### Searching Algorithms Comparison

| Algorithm | Best Case | Average Case | Worst Case | Space | Prerequisites |
|-----------|-----------|--------------|------------|-------|---------------|
| Linear Search | O(1) | O(n) | O(n) | O(1) | None |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) | Sorted Array |

### Hashing Performance

| Operation | Average Case | Worst Case | Load Factor Impact |
|-----------|--------------|------------|-------------------|
| Insert | O(1) | O(n) | Higher α → More collisions |
| Search | O(1) | O(n) | Keep α < 0.7 for good performance |
| Delete | O(1) | O(n) | Clustering affects performance |

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

1. **Algorithm Analysis**: Understanding time and space complexity
2. **Sorting Techniques**: Mastering different sorting approaches
3. **Search Strategies**: Learning efficient search methods
4. **Data Structure Design**: Hash table implementation and optimization
5. **Performance Optimization**: Comparing and choosing appropriate algorithms
6. **Problem Solving**: Applying algorithms to real-world scenarios

## 🔍 Key Features

### Systematic Solutions
- ✅ Interactive menu-driven interfaces
- ✅ Step-by-step algorithm visualization
- ✅ Performance analysis and benchmarking
- ✅ Multiple algorithm variants and optimizations
- ✅ Comprehensive error handling and validation
- ✅ Educational explanations and demonstrations

### Compressed Solutions
- ✅ Minimal, optimized implementations
- ✅ Core algorithm focus
- ✅ Essential functionality only
- ✅ Quick testing and demonstration
- ✅ Maximum efficiency in minimum code

## 🎯 Algorithm Selection Guide

### When to Use Each Sorting Algorithm

**Bubble Sort:**
- Small datasets (n < 50)
- Educational purposes
- Nearly sorted data
- Simplicity over efficiency

**Selection Sort:**
- Small datasets
- Memory writes are expensive
- Minimizing number of swaps
- Simple implementation needed

**Insertion Sort:**
- Small datasets (n < 50)
- Nearly sorted data
- Online algorithms
- Hybrid algorithm component

**Merge Sort:**
- Large datasets
- Stable sorting required
- Consistent O(n log n) performance
- External sorting

### When to Use Each Search Algorithm

**Linear Search:**
- Unsorted data
- Small datasets
- Simple implementation
- Finding all occurrences

**Binary Search:**
- Large sorted datasets
- Frequent searches
- Logarithmic performance required
- Range queries

**Hashing:**
- Frequent insertions/deletions
- Average O(1) performance needed
- Key-value pair storage
- Large datasets with unique keys

## 📈 Performance Benchmarks

### Sorting Performance (1000 elements)

| Algorithm | Random Array | Sorted Array | Reverse Sorted |
|-----------|--------------|--------------|----------------|
| Bubble Sort | ~500,000 ops | ~1,000 ops | ~500,000 ops |
| Selection Sort | ~500,000 ops | ~500,000 ops | ~500,000 ops |
| Insertion Sort | ~250,000 ops | ~1,000 ops | ~500,000 ops |
| Merge Sort | ~10,000 ops | ~10,000 ops | ~10,000 ops |

### Search Performance (1000 elements)

| Algorithm | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Linear Search | 1 comparison | 500 comparisons | 1000 comparisons |
| Binary Search | 1 comparison | 10 comparisons | 10 comparisons |

## 🔧 Advanced Features

### Optimization Techniques
- **Early Termination**: Stop when no swaps needed (Bubble Sort)
- **Binary Search Integration**: Reduce comparisons (Binary Insertion Sort)
- **Sentinel Values**: Eliminate bounds checking (Linear Search)
- **Adaptive Behavior**: Better performance on partially sorted data

### Educational Tools
- **Algorithm Visualization**: Step-by-step process demonstration
- **Complexity Analysis**: Real-time performance measurement
- **Comparison Tools**: Side-by-side algorithm comparison
- **Interactive Learning**: Menu-driven exploration

### Real-World Applications
- **Database Systems**: Indexing and query optimization
- **Operating Systems**: Process scheduling and memory management
- **Web Applications**: Search functionality and data organization
- **Game Development**: Leaderboards and collision detection

This assignment provides a comprehensive foundation in fundamental algorithms with both theoretical understanding and practical implementation skills.
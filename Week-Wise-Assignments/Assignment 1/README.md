# Assignment 1 - Dynamic Arrays and Python Arrays

This folder contains solutions to Assignment 1 problems in both C and Python programming languages.

## Folder Structure

```
Assignment 1/
├── Systematic Solutions/
│   ├── C Programs/          # Detailed C solutions with comments and error handling
│   └── Python Programs/     # Detailed Python solutions with multiple methods and examples
├── Compressed Solutions/
│   ├── C Programs/          # Minimal C code solutions
│   └── Python Programs/     # Minimal Python code solutions
└── README.md               # This file
```

## C Programming Problems (Dynamic Arrays)

1. **1_search_element.c** - Search an element in an array using dynamic memory allocation
2. **2_nth_maximum.c** - Find the 3rd/user defined position based maximum element
3. **3_minimum_element.c** - Find the minimum element in an array
4. **4_search_2d_array.c** - Search an element in a 2D-Array
5. **5_max_2d_array.c** - Find the maximum element in a 2D-array
6. **6_min_2d_array.c** - Find the minimum element in a 2D-array
7. **7_merge_sorted_arrays.c** - Merge two sorted dynamic arrays
8. **8_merge_unsorted_arrays.c** - Merge two unsorted dynamic arrays in sorted order
9. **9_delete_range.c** - Delete a range of data from a dynamic array
10. **10_modify_array_size.c** - Modify the size of an array and utilize during runtime

## Python Programming Problems (Arrays)

1. **1_create_display_array.py** - Create array of 5 integers and display with index access
2. **2_append_item.py** - Append a new item to the end of the array
3. **3_reverse_array.py** - Reverse the order of items in the array
4. **4_count_occurrences.py** - Get number of occurrences of a specified element
5. **5_create_six_integers.py** - Create array containing six integers and print all members
6. **6_insert_before_second.py** - Insert new item before the second element
7. **7_remove_by_index.py** - Remove specified item using index
8. **8_remove_first_occurrence.py** - Remove first occurrence of specified element
9. **9_array_to_list.py** - Convert array to ordinary list with same items
10. **10_find_duplicates.py** - Find whether array contains duplicate elements
11. **11_highest_product_pair.py** - Find pair with highest product from array
12. **12_array_length.py** - Get the length of an array
13. **13_remove_duplicates.py** - Remove all duplicate elements and return new array
14. **14_find_missing_number.py** - Find missing number in array between 10 and 20
15. **15_create_2d_array.py** - Create 2D array containing 12 integers and print all members

## How to Use

### Systematic Solutions
- **C Programs**: Compile with `gcc filename.c -o filename` and run `./filename`
- **Python Programs**: Run with `python filename.py`
- These solutions include detailed comments, error handling, and multiple approaches

### Compressed Solutions
- **C Programs**: Minimal code focusing on core functionality
- **Python Programs**: One-liner or very short implementations
- These solutions prioritize brevity while maintaining correctness

## Key Features

### C Solutions
- Dynamic memory allocation using `malloc()`, `realloc()`, and `free()`
- Proper memory management and error handling
- Input validation and user-friendly output
- Both systematic (detailed) and compressed (minimal) versions

### Python Solutions
- Use of `array` module for type-specific arrays
- Multiple implementation approaches in systematic solutions
- Interactive examples with user input
- Comprehensive error handling and edge case management

## Compilation and Execution

### For C Programs:
```bash
# Systematic solutions
cd "Systematic Solutions/C Programs"
gcc 1_search_element.c -o search_element
./search_element

# Compressed solutions
cd "Compressed Solutions/C Programs"
gcc 1_search_element.c -o search_element
./search_element
```

### For Python Programs:
```bash
# Systematic solutions
cd "Systematic Solutions/Python Programs"
python 1_create_display_array.py

# Compressed solutions
cd "Compressed Solutions/Python Programs"
python 1_create_display_array.py
```

## Notes

- All C programs use dynamic memory allocation as required
- Python programs use the `array` module for type-specific arrays
- Systematic solutions include comprehensive examples and multiple methods
- Compressed solutions focus on minimal code while maintaining functionality
- All solutions are tested and working implementations
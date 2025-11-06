import array

def create_2d_array_method1():
    """
    Method 1: Using list of arrays (most common approach)
    """
    # Create a 2D array with 3 rows and 4 columns (12 integers total)
    arr_2d = []
    
    # Initialize with sample data
    data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    
    for i in range(3):  # 3 rows
        row = array.array('i')
        for j in range(4):  # 4 columns
            row.append(data[i * 4 + j])
        arr_2d.append(row)
    
    return arr_2d

def create_2d_array_method2():
    """
    Method 2: Direct initialization
    """
    row1 = array.array('i', [1, 2, 3, 4])
    row2 = array.array('i', [5, 6, 7, 8])
    row3 = array.array('i', [9, 10, 11, 12])
    
    return [row1, row2, row3]

def print_2d_array(arr_2d):
    """
    Function to print 2D array in a formatted way
    """
    print("2D Array contents:")
    for i, row in enumerate(arr_2d):
        print(f"Row {i}: {list(row)}")

def print_all_members(arr_2d):
    """
    Print all members of the 2D array with their positions
    """
    print("\nAll members with positions:")
    for i, row in enumerate(arr_2d):
        for j, value in enumerate(row):
            print(f"Position [{i}][{j}]: {value}")

# Method 1: Create 2D array
print("Method 1: Creating 2D array using loops")
arr2d_1 = create_2d_array_method1()
print_2d_array(arr2d_1)
print_all_members(arr2d_1)

print("\n" + "="*50)

# Method 2: Create 2D array
print("Method 2: Creating 2D array with direct initialization")
arr2d_2 = create_2d_array_method2()
print_2d_array(arr2d_2)

print("\n" + "="*50)

# Interactive creation
print("Interactive 2D Array Creation:")
rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

if rows * cols == 12:
    print(f"Perfect! This will create a 2D array with exactly 12 integers.")
else:
    print(f"Note: This will create a 2D array with {rows * cols} integers.")

interactive_2d = []
element_count = 1

print(f"Enter {rows * cols} integers:")
for i in range(rows):
    row = array.array('i')
    for j in range(cols):
        value = int(input(f"Element {element_count} [Row {i}, Col {j}]: "))
        row.append(value)
        element_count += 1
    interactive_2d.append(row)

print("\nYour 2D array:")
print_2d_array(interactive_2d)
print_all_members(interactive_2d)

# Additional operations
print("\n" + "="*50)
print("Additional Information:")
print(f"Number of rows: {len(interactive_2d)}")
print(f"Number of columns: {len(interactive_2d[0]) if interactive_2d else 0}")
print(f"Total elements: {sum(len(row) for row in interactive_2d)}")

# Demonstrate accessing elements
if interactive_2d:
    print(f"First element: {interactive_2d[0][0]}")
    print(f"Last element: {interactive_2d[-1][-1]}")
    
    # Sum of all elements
    total_sum = sum(sum(row) for row in interactive_2d)
    print(f"Sum of all elements: {total_sum}")
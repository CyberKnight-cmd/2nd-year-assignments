import array

def find_highest_product_pair(arr):
    """
    Find a pair with the highest product from given array of integers.
    Returns the pair and their product.
    """
    if len(arr) < 2:
        return None, None, None
    
    max_product = float('-inf')
    best_pair = None
    
    # Check all possible pairs
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            product = arr[i] * arr[j]
            if product > max_product:
                max_product = product
                best_pair = (arr[i], arr[j])
    
    return best_pair[0], best_pair[1], max_product

def find_highest_product_pair_optimized(arr):
    """
    Optimized version: Find two largest or two smallest (if negative) numbers
    """
    if len(arr) < 2:
        return None, None, None
    
    # Convert to list for sorting
    sorted_arr = sorted(arr)
    
    # Product of two largest numbers
    product1 = sorted_arr[-1] * sorted_arr[-2]
    
    # Product of two smallest numbers (in case of negative numbers)
    product2 = sorted_arr[0] * sorted_arr[1]
    
    if product1 >= product2:
        return sorted_arr[-1], sorted_arr[-2], product1
    else:
        return sorted_arr[0], sorted_arr[1], product2

# Test with positive numbers
arr1 = array.array('i', [1, 2, 3, 4, 5, 6])
print("Array 1:", arr1)
num1, num2, product = find_highest_product_pair(arr1)
print(f"Highest product pair: {num1} and {num2}")
print(f"Product: {num1} × {num2} = {product}")

# Test with mixed positive and negative numbers
arr2 = array.array('i', [-10, -3, 5, 6, -2])
print("\nArray 2:", arr2)
num1, num2, product = find_highest_product_pair(arr2)
print(f"Highest product pair: {num1} and {num2}")
print(f"Product: {num1} × {num2} = {product}")

# Test optimized version
print("\nUsing optimized method:")
num1, num2, product = find_highest_product_pair_optimized(arr2)
print(f"Highest product pair: {num1} and {num2}")
print(f"Product: {num1} × {num2} = {product}")

# Interactive test
print("\n" + "="*50)
print("Interactive Test:")
size = int(input("Enter array size: "))
arr3 = array.array('i')

print(f"Enter {size} integers:")
for i in range(size):
    value = int(input(f"Element {i+1}: "))
    arr3.append(value)

print("Your array:", arr3)
num1, num2, product = find_highest_product_pair(arr3)

if num1 is not None:
    print(f"Pair with highest product: {num1} and {num2}")
    print(f"Highest product: {num1} × {num2} = {product}")
else:
    print("Array must have at least 2 elements")
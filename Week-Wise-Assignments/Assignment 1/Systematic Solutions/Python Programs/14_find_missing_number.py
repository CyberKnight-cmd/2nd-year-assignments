import array

def find_missing_number(arr, start=10, end=20):
    """
    Find the missing number in a given array of numbers between start and end.
    Assumes only one number is missing.
    """
    # Create set of expected numbers
    expected = set(range(start, end + 1))
    
    # Create set of actual numbers in array
    actual = set(arr)
    
    # Find missing numbers
    missing = expected - actual
    
    return list(missing)

def find_missing_using_sum(arr, start=10, end=20):
    """
    Alternative method using sum formula
    """
    expected_sum = sum(range(start, end + 1))
    actual_sum = sum(arr)
    missing_number = expected_sum - actual_sum
    return missing_number if missing_number != 0 else None

# Test case 1: Array with one missing number
arr1 = array.array('i', [10, 11, 12, 14, 15, 16, 17, 18, 19, 20])  # Missing 13
print("Array 1:", arr1)
missing1 = find_missing_number(arr1)
print("Missing number(s):", missing1)

# Using sum method
missing_sum1 = find_missing_using_sum(arr1)
print("Missing number (sum method):", missing_sum1)

# Test case 2: Array with multiple missing numbers
arr2 = array.array('i', [10, 12, 14, 16, 18, 20])  # Missing 11, 13, 15, 17, 19
print("\nArray 2:", arr2)
missing2 = find_missing_number(arr2)
print("Missing number(s):", missing2)

# Test case 3: Complete array (no missing numbers)
arr3 = array.array('i', [10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20])
print("\nArray 3 (complete):", arr3)
missing3 = find_missing_number(arr3)
print("Missing number(s):", missing3 if missing3 else "None")

# Interactive test
print("\n" + "="*50)
print("Interactive Test:")
print("Enter numbers between 10 and 20 (you can skip some numbers)")

user_array = array.array('i')
print("Enter numbers one by one (enter -1 to stop):")

while True:
    try:
        num = int(input("Enter number: "))
        if num == -1:
            break
        if 10 <= num <= 20:
            if num not in user_array:
                user_array.append(num)
            else:
                print("Number already entered, skipping...")
        else:
            print("Please enter numbers between 10 and 20 only")
    except ValueError:
        print("Please enter a valid integer")

print("Your array:", sorted(user_array))
missing_numbers = find_missing_number(user_array)

if missing_numbers:
    print("Missing number(s) between 10 and 20:", missing_numbers)
else:
    print("No missing numbers! Your array contains all numbers from 10 to 20")

# Show complete range for reference
print("Complete range should be:", list(range(10, 21)))
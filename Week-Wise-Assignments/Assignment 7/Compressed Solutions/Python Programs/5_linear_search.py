def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

n = int(input("Enter size: "))
arr = list(map(int, input("Enter elements: ").split()))
target = int(input("Enter target: "))

result = linear_search(arr, target)
if result != -1:
    print(f"Found at index {result}")
else:
    print("Not found")
def hanoi_stack(n):
    A, B, C = list(range(n, 0, -1)), [], []
    towers = [A, B, C]
    names = ['A', 'B', 'C']
    
    if n % 2 == 0: B, C = C, B
    
    moves = 0
    total = (2 ** n) - 1
    
    for i in range(1, total + 1):
        if i % 3 == 1:
            # A <-> C
            if not A or (C and A[-1] > C[-1]):
                A.append(C.pop())
                print(f"Move {moves + 1}: C -> A")
            else:
                C.append(A.pop())
                print(f"Move {moves + 1}: A -> C")
        elif i % 3 == 2:
            # A <-> B
            if not A or (B and A[-1] > B[-1]):
                A.append(B.pop())
                print(f"Move {moves + 1}: B -> A")
            else:
                B.append(A.pop())
                print(f"Move {moves + 1}: A -> B")
        else:
            # B <-> C
            if not B or (C and B[-1] > C[-1]):
                B.append(C.pop())
                print(f"Move {moves + 1}: C -> B")
            else:
                C.append(B.pop())
                print(f"Move {moves + 1}: B -> C")
        moves += 1

n = int(input("Enter number of disks: "))
hanoi_stack(n)
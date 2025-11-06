#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
    char name;
};

// Initialize stack
void initStack(struct Stack* stack, char name) {
    stack->top = -1;
    stack->name = name;
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push element to stack
void push(struct Stack* stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Pop element from stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Peek top element
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->data[stack->top];
}

// Display a single stack (tower)
void displayTower(struct Stack* stack, int maxDisks) {
    printf("Tower %c: ", stack->name);
    
    if (isEmpty(stack)) {
        printf("Empty");
    } else {
        printf("Bottom -> ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->data[i]);
        }
        printf("<- Top");
    }
    printf("\n");
}

// Display all three towers
void displayTowers(struct Stack* source, struct Stack* auxiliary, struct Stack* destination, int n) {
    printf("\n=== Current State of Towers ===\n");
    displayTower(source, n);
    displayTower(auxiliary, n);
    displayTower(destination, n);
    printf("================================\n");
}

// Visual representation of towers
void visualizeTowers(struct Stack* towers[], int n) {
    printf("\nVisual Representation:\n");
    
    // Print from top to bottom
    for (int level = n - 1; level >= 0; level--) {
        for (int tower = 0; tower < 3; tower++) {
            printf("  ");
            if (towers[tower]->top >= level) {
                int disk = towers[tower]->data[level];
                // Print disk with visual representation
                for (int i = 0; i < n - disk; i++) printf(" ");
                for (int i = 0; i < disk * 2 + 1; i++) printf("*");
                for (int i = 0; i < n - disk; i++) printf(" ");
            } else {
                // Print empty space with pole
                for (int i = 0; i < n; i++) printf(" ");
                printf("|");
                for (int i = 0; i < n; i++) printf(" ");
            }
            printf("    ");
        }
        printf("\n");
    }
    
    // Print base
    for (int tower = 0; tower < 3; tower++) {
        printf("  ");
        for (int i = 0; i < n * 2 + 1; i++) printf("-");
        printf("    ");
    }
    printf("\n");
    
    // Print tower labels
    printf("    %c", towers[0]->name);
    for (int i = 0; i < n * 2 - 1; i++) printf(" ");
    printf("      %c", towers[1]->name);
    for (int i = 0; i < n * 2 - 1; i++) printf(" ");
    printf("      %c\n", towers[2]->name);
}

// Move disk from one tower to another
void moveDisk(struct Stack* from, struct Stack* to, int* moveCount) {
    if (isEmpty(from)) {
        printf("Error: Cannot move from empty tower %c\n", from->name);
        return;
    }
    
    int disk = pop(from);
    
    if (!isEmpty(to) && peek(to) < disk) {
        printf("Error: Cannot place larger disk %d on smaller disk %d\n", disk, peek(to));
        push(from, disk); // Put it back
        return;
    }
    
    push(to, disk);
    (*moveCount)++;
    printf("Move %d: Moved disk %d from Tower %c to Tower %c\n", 
           *moveCount, disk, from->name, to->name);
}

// Algorithm for Tower of Hanoi using Stack:
// 1. Use three stacks to represent the three towers
// 2. Implement the recursive algorithm iteratively using explicit stack operations
// 3. For n disks: move n-1 disks to auxiliary, move largest to destination, move n-1 from auxiliary to destination
void towerOfHanoiStack(int n, struct Stack* source, struct Stack* auxiliary, struct Stack* destination) {
    printf("\n=== Tower of Hanoi Solution using Stacks ===\n");
    printf("Number of disks: %d\n", n);
    printf("Source: Tower %c, Auxiliary: Tower %c, Destination: Tower %c\n", 
           source->name, auxiliary->name, destination->name);
    printf("Algorithm: Use stacks to simulate the three towers\n\n");
    
    // Initialize source tower with disks (largest at bottom)
    for (int i = n; i >= 1; i--) {
        push(source, i);
    }
    
    printf("Initial setup:\n");
    struct Stack* towers[] = {source, auxiliary, destination};
    visualizeTowers(towers, n);
    
    int totalMoves = (1 << n) - 1; // 2^n - 1
    int moveCount = 0;
    
    printf("\nTotal moves required: %d\n", totalMoves);
    printf("Starting solution...\n\n");
    
    // For even number of disks, swap auxiliary and destination
    if (n % 2 == 0) {
        struct Stack* temp = auxiliary;
        auxiliary = destination;
        destination = temp;
        towers[1] = auxiliary;
        towers[2] = destination;
    }
    
    // Iterative solution using the pattern
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            // Move between source and destination
            if (isEmpty(source) || (!isEmpty(destination) && peek(source) > peek(destination))) {
                moveDisk(destination, source, &moveCount);
            } else {
                moveDisk(source, destination, &moveCount);
            }
        }
        else if (i % 3 == 2) {
            // Move between source and auxiliary
            if (isEmpty(source) || (!isEmpty(auxiliary) && peek(source) > peek(auxiliary))) {
                moveDisk(auxiliary, source, &moveCount);
            } else {
                moveDisk(source, auxiliary, &moveCount);
            }
        }
        else {
            // Move between auxiliary and destination
            if (isEmpty(auxiliary) || (!isEmpty(destination) && peek(auxiliary) > peek(destination))) {
                moveDisk(destination, auxiliary, &moveCount);
            } else {
                moveDisk(auxiliary, destination, &moveCount);
            }
        }
        
        // Display state after each move
        if (n <= 4) { // Only show visual for small numbers
            visualizeTowers(towers, n);
            printf("\n");
        } else {
            displayTowers(source, auxiliary, destination, n);
        }
        
        // Pause for user input if requested
        if (n <= 3) {
            printf("Press Enter to continue...");
            getchar();
        }
    }
    
    printf("Solution completed! All disks moved to Tower %c\n", destination->name);
    printf("Total moves made: %d\n", moveCount);
}

// Recursive solution for comparison
void towerOfHanoiRecursive(int n, char source, char auxiliary, char destination, int* moveCount) {
    if (n == 1) {
        (*moveCount)++;
        printf("Move %d: Move disk 1 from %c to %c\n", *moveCount, source, destination);
        return;
    }
    
    towerOfHanoiRecursive(n - 1, source, destination, auxiliary, moveCount);
    (*moveCount)++;
    printf("Move %d: Move disk %d from %c to %c\n", *moveCount, n, source, destination);
    towerOfHanoiRecursive(n - 1, auxiliary, source, destination, moveCount);
}

int main() {
    int choice, n;
    
    printf("=== Tower of Hanoi using Stacks ===\n");
    printf("This program solves the Tower of Hanoi puzzle using stack data structure\n");
    printf("Three stacks represent the three towers (rods)\n");
    printf("Goal: Move all disks from source to destination tower\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Solve Tower of Hanoi using stacks\n");
        printf("2. Compare with recursive solution\n");
        printf("3. Show algorithm explanation\n");
        printf("4. Show complexity analysis\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter number of disks (recommended: 3-5 for visualization): ");
                scanf("%d", &n);
                getchar();
                
                if (n <= 0) {
                    printf("Number of disks must be positive!\n");
                    break;
                }
                
                if (n > 10) {
                    printf("Warning: Large numbers will generate many moves!\n");
                    printf("Continue? (y/n): ");
                    char cont;
                    scanf("%c", &cont);
                    if (cont != 'y' && cont != 'Y') break;
                }
                
                struct Stack source, auxiliary, destination;
                initStack(&source, 'A');
                initStack(&auxiliary, 'B');
                initStack(&destination, 'C');
                
                towerOfHanoiStack(n, &source, &auxiliary, &destination);
                break;
                
            case 2:
                printf("Enter number of disks for recursive comparison: ");
                scanf("%d", &n);
                
                if (n <= 0) {
                    printf("Number of disks must be positive!\n");
                    break;
                }
                
                printf("\n=== Recursive Solution ===\n");
                int moveCount = 0;
                towerOfHanoiRecursive(n, 'A', 'B', 'C', &moveCount);
                printf("Total moves: %d\n", moveCount);
                break;
                
            case 3:
                printf("\n=== Algorithm Explanation ===\n");
                printf("Tower of Hanoi Rules:\n");
                printf("1. Only one disk can be moved at a time\n");
                printf("2. Only the top disk from a tower can be moved\n");
                printf("3. A larger disk cannot be placed on a smaller disk\n\n");
                
                printf("Stack-based Approach:\n");
                printf("1. Use three stacks to represent the three towers\n");
                printf("2. Implement iterative solution using the pattern:\n");
                printf("   - For odd n: alternate between (source,destination) and (source,auxiliary) and (auxiliary,destination)\n");
                printf("   - For even n: swap auxiliary and destination in the pattern\n");
                printf("3. Always move the smaller disk onto the larger disk\n\n");
                
                printf("Why Stacks Work:\n");
                printf("- LIFO property ensures only top disk is accessible\n");
                printf("- Natural representation of the tower structure\n");
                printf("- Easy to check validity of moves\n");
                break;
                
            case 4:
                printf("\n=== Complexity Analysis ===\n");
                printf("Time Complexity: O(2^n)\n");
                printf("Space Complexity: O(n) for the stacks\n");
                printf("Number of moves: 2^n - 1\n\n");
                
                printf("Move count for different values of n:\n");
                printf("n\tMoves\tTime (if 1 move/second)\n");
                printf("---\t-----\t--------------------\n");
                for (int i = 1; i <= 10; i++) {
                    int moves = (1 << i) - 1;
                    printf("%d\t%d\t", i, moves);
                    if (moves < 60) {
                        printf("%d seconds\n", moves);
                    } else if (moves < 3600) {
                        printf("%.1f minutes\n", moves / 60.0);
                    } else {
                        printf("%.1f hours\n", moves / 3600.0);
                    }
                }
                break;
                
            case 5:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
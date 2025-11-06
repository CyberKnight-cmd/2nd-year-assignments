#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Initialize stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push element to stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = value;
    printf("Pushed %d to stack\n", value);
}

// Pop element from stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    int value = stack->data[stack->top--];
    printf("Popped %d from stack\n", value);
    return value;
}

// Display stack contents
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack contents (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Algorithm for Factorial using Stack:
// 1. Push all numbers from n down to 1 onto stack
// 2. Pop numbers one by one and multiply to get factorial
// 3. This simulates the recursive nature of factorial calculation
long long factorialUsingStack(int n) {
    if (n < 0) {
        printf("Factorial is not defined for negative numbers!\n");
        return -1;
    }
    
    if (n == 0 || n == 1) {
        printf("Factorial of %d is 1 (base case)\n", n);
        return 1;
    }
    
    struct Stack stack;
    initStack(&stack);
    
    printf("\n=== Factorial Calculation using Stack ===\n");
    printf("Calculating factorial of %d\n", n);
    printf("Algorithm: Push numbers n to 1, then pop and multiply\n\n");
    
    // Phase 1: Push numbers from n down to 1
    printf("Phase 1: Pushing numbers from %d down to 1\n", n);
    for (int i = n; i >= 1; i--) {
        push(&stack, i);
    }
    
    printf("\nStack after pushing all numbers:\n");
    displayStack(&stack);
    
    // Phase 2: Pop numbers and calculate factorial
    printf("\nPhase 2: Popping numbers and calculating factorial\n");
    long long factorial = 1;
    int step = 1;
    
    while (!isEmpty(&stack)) {
        int num = pop(&stack);
        factorial *= num;
        printf("Step %d: factorial = factorial * %d = %lld\n", step++, num, factorial);
        
        if (!isEmpty(&stack)) {
            printf("Remaining stack: ");
            displayStack(&stack);
        }
        printf("\n");
    }
    
    return factorial;
}

// Iterative factorial for comparison
long long factorialIterative(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    
    long long factorial = 1;
    printf("\nIterative calculation for comparison:\n");
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        printf("%d! (up to %d) = %lld\n", i, i, factorial);
    }
    return factorial;
}

// Recursive factorial for comparison
long long factorialRecursive(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    return n * factorialRecursive(n - 1);
}

// Function to demonstrate the stack-based approach step by step
void demonstrateStackApproach(int n) {
    printf("\n=== Demonstration: Why Stack Works for Factorial ===\n");
    printf("Factorial definition: n! = n * (n-1) * (n-2) * ... * 2 * 1\n");
    printf("For %d!: %d", n, n);
    for (int i = n-1; i >= 1; i--) {
        printf(" * %d", i);
    }
    printf("\n\n");
    
    printf("Stack approach mimics the recursive nature:\n");
    printf("1. Push all numbers from %d to 1 (like recursive calls)\n", n);
    printf("2. Pop and multiply (like returning from recursive calls)\n");
    printf("3. LIFO property ensures correct multiplication order\n\n");
    
    printf("Stack visualization:\n");
    printf("Push phase:     Pop phase:\n");
    for (int i = 1; i <= n; i++) {
        printf("Push %d          ", n - i + 1);
        if (i <= n) {
            printf("Pop %d (multiply)\n", i);
        }
    }
}

int main() {
    int choice, number;
    long long result;
    
    printf("=== Factorial Calculation using Stack ===\n");
    printf("This program calculates factorial using stack data structure\n");
    printf("Stack simulates the recursive nature of factorial calculation\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Calculate factorial using stack\n");
        printf("2. Compare with iterative method\n");
        printf("3. Compare with recursive method\n");
        printf("4. Demonstrate stack approach\n");
        printf("5. Show factorial table\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a number to calculate factorial: ");
                scanf("%d", &number);
                
                if (number > 20) {
                    printf("Warning: Large numbers may cause overflow!\n");
                    printf("Continue? (1 for yes, 0 for no): ");
                    int cont;
                    scanf("%d", &cont);
                    if (!cont) break;
                }
                
                result = factorialUsingStack(number);
                if (result != -1) {
                    printf("\nFinal Result: %d! = %lld\n", number, result);
                }
                break;
                
            case 2:
                printf("Enter a number to compare methods: ");
                scanf("%d", &number);
                
                printf("\n=== Method Comparison ===\n");
                result = factorialUsingStack(number);
                if (result != -1) {
                    printf("Stack method result: %lld\n", result);
                }
                
                long long iterResult = factorialIterative(number);
                if (iterResult != -1) {
                    printf("Iterative method result: %lld\n", iterResult);
                }
                
                if (result == iterResult && result != -1) {
                    printf("✓ Both methods give the same result!\n");
                }
                break;
                
            case 3:
                printf("Enter a number to compare with recursive method: ");
                scanf("%d", &number);
                
                result = factorialUsingStack(number);
                long long recResult = factorialRecursive(number);
                
                printf("\nStack method: %lld\n", result);
                printf("Recursive method: %lld\n", recResult);
                
                if (result == recResult && result != -1) {
                    printf("✓ Both methods give the same result!\n");
                }
                break;
                
            case 4:
                printf("Enter a number to demonstrate (recommended: 5 or less): ");
                scanf("%d", &number);
                demonstrateStackApproach(number);
                break;
                
            case 5:
                printf("\n=== Factorial Table ===\n");
                printf("n\tn!\n");
                printf("---\t---\n");
                for (int i = 0; i <= 10; i++) {
                    printf("%d\t%lld\n", i, factorialRecursive(i));
                }
                break;
                
            case 6:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
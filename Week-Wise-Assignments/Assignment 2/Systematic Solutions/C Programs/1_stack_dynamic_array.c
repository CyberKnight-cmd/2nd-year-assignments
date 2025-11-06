#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack structure
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

/*
ALGORITHM FOR STACK OPERATIONS:

PUSH Algorithm:
1. Check if stack is full (top == capacity - 1)
2. If full, display overflow message
3. If not full, increment top
4. Insert element at data[top]

POP Algorithm:
1. Check if stack is empty (top == -1)
2. If empty, display underflow message
3. If not empty, get element at data[top]
4. Decrement top
5. Return the element

PEEK Algorithm:
1. Check if stack is empty (top == -1)
2. If empty, display error message
3. If not empty, return data[top]

DISPLAY Algorithm:
1. Check if stack is empty (top == -1)
2. If empty, display "Stack is empty"
3. If not empty, traverse from top to 0
4. Print all elements
*/

// Initialize stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    stack->data = (int*)malloc(capacity * sizeof(int));
    if (!stack->data) {
        printf("Memory allocation failed!\n");
        free(stack);
        return NULL;
    }
    
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Check if stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// PUSH operation
void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", element);
        return;
    }
    
    stack->data[++stack->top] = element;
    printf("Pushed %d to stack\n", element);
}

// POP operation
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1;
    }
    
    int element = stack->data[stack->top--];
    printf("Popped %d from stack\n", element);
    return element;
}

// PEEK operation
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No top element\n");
        return -1;
    }
    
    return stack->data[stack->top];
}

// DISPLAY operation
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Stack contents (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Free stack memory
void destroyStack(Stack* stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}

int main() {
    int capacity, choice, element;
    
    printf("Enter stack capacity: ");
    scanf("%d", &capacity);
    
    Stack* stack = createStack(capacity);
    if (!stack) return 1;
    
    do {
        printf("\n=== Stack Operations ===\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(stack, element);
                break;
                
            case 2:
                pop(stack);
                break;
                
            case 3:
                element = peek(stack);
                if (element != -1) {
                    printf("Top element: %d\n", element);
                }
                break;
                
            case 4:
                display(stack);
                break;
                
            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    destroyStack(stack);
    return 0;
}
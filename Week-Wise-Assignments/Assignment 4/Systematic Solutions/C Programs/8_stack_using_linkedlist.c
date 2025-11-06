#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
    int size;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Algorithm for Push Operation:
// 1. Create a new node with given data
// 2. Set new node's next to current top
// 3. Update top to point to new node
// 4. Increment size
void push(struct Stack* stack, int data) {
    printf("\nPush Operation - Adding %d to stack:\n", data);
    printf("Step 1: Create new node with data %d\n", data);
    
    struct Node* newNode = createNode(data);
    
    printf("Step 2: Set new node's next to current top\n");
    newNode->next = stack->top;
    
    printf("Step 3: Update top to point to new node\n");
    stack->top = newNode;
    stack->size++;
    
    printf("Step 4: Increment size (now %d)\n", stack->size);
    printf("Push successful! %d is now at the top of stack.\n", data);
}

// Algorithm for Pop Operation:
// 1. Check if stack is empty
// 2. Store top node's data
// 3. Update top to next node
// 4. Free the old top node
// 5. Decrement size and return data
int pop(struct Stack* stack) {
    printf("\nPop Operation:\n");
    
    if (stack->top == NULL) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return -1;
    }
    
    printf("Step 1: Stack is not empty, proceeding with pop\n");
    printf("Step 2: Store top node's data (%d)\n", stack->top->data);
    
    int data = stack->top->data;
    struct Node* temp = stack->top;
    
    printf("Step 3: Update top to next node\n");
    stack->top = stack->top->next;
    
    printf("Step 4: Free the old top node\n");
    free(temp);
    stack->size--;
    
    printf("Step 5: Decrement size (now %d) and return data\n", stack->size);
    printf("Pop successful! Removed %d from top of stack.\n", data);
    
    return data;
}

// Function to peek at top element without removing it
int peek(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty! No top element to peek.\n");
        return -1;
    }
    return stack->top->data;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to get stack size
int getSize(struct Stack* stack) {
    return stack->size;
}

// Function to display stack
void displayStack(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("\nStack contents (top to bottom):\n");
    printf("TOP -> ");
    
    struct Node* temp = stack->top;
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Stack size: %d\n", stack->size);
}

// Function to free stack memory
void freeStack(struct Stack* stack) {
    while (stack->top != NULL) {
        struct Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
}

int main() {
    struct Stack* stack = createStack();
    int choice, data;
    
    printf("=== Stack Implementation using Single Linked List ===\n");
    printf("Stack follows LIFO (Last In First Out) principle\n");
    printf("Operations: Push (insert at top), Pop (remove from top)\n\n");
    
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push (Insert element)\n");
        printf("2. Pop (Remove element)\n");
        printf("3. Peek (View top element)\n");
        printf("4. Display stack\n");
        printf("5. Check if empty\n");
        printf("6. Get stack size\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;
                
            case 2:
                data = pop(stack);
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
                
            case 3:
                data = peek(stack);
                if (data != -1) {
                    printf("Top element: %d\n", data);
                }
                break;
                
            case 4:
                displayStack(stack);
                break;
                
            case 5:
                if (isEmpty(stack)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
                
            case 6:
                printf("Stack size: %d\n", getSize(stack));
                break;
                
            case 7:
                printf("Exiting program...\n");
                freeStack(stack);
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
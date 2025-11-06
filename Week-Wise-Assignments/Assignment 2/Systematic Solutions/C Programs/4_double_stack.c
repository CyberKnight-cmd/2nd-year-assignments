#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Double Stack structure - uses both ends of array
typedef struct {
    int *data;
    int top1;    // Top of first stack (grows from left)
    int top2;    // Top of second stack (grows from right)
    int capacity;
} DoubleStack;

// Initialize double stack
DoubleStack* createDoubleStack(int capacity) {
    DoubleStack* ds = (DoubleStack*)malloc(sizeof(DoubleStack));
    if (!ds) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    ds->data = (int*)malloc(capacity * sizeof(int));
    if (!ds->data) {
        printf("Memory allocation failed!\n");
        free(ds);
        return NULL;
    }
    
    ds->top1 = -1;              // First stack starts from left
    ds->top2 = capacity;        // Second stack starts from right
    ds->capacity = capacity;
    return ds;
}

// Check if stack1 is empty
bool isEmpty1(DoubleStack* ds) {
    return ds->top1 == -1;
}

// Check if stack2 is empty
bool isEmpty2(DoubleStack* ds) {
    return ds->top2 == ds->capacity;
}

// Check if double stack is full
bool isFull(DoubleStack* ds) {
    return ds->top1 + 1 == ds->top2;
}

// Push to stack1 (left side)
void push1(DoubleStack* ds, int element) {
    if (isFull(ds)) {
        printf("Double Stack Overflow! Cannot push %d to Stack1\n", element);
        return;
    }
    
    ds->data[++ds->top1] = element;
    printf("Pushed %d to Stack1\n", element);
}

// Push to stack2 (right side)
void push2(DoubleStack* ds, int element) {
    if (isFull(ds)) {
        printf("Double Stack Overflow! Cannot push %d to Stack2\n", element);
        return;
    }
    
    ds->data[--ds->top2] = element;
    printf("Pushed %d to Stack2\n", element);
}

// Pop from stack1
int pop1(DoubleStack* ds) {
    if (isEmpty1(ds)) {
        printf("Stack1 Underflow! Cannot pop from empty Stack1\n");
        return -1;
    }
    
    int element = ds->data[ds->top1--];
    printf("Popped %d from Stack1\n", element);
    return element;
}

// Pop from stack2
int pop2(DoubleStack* ds) {
    if (isEmpty2(ds)) {
        printf("Stack2 Underflow! Cannot pop from empty Stack2\n");
        return -1;
    }
    
    int element = ds->data[ds->top2++];
    printf("Popped %d from Stack2\n", element);
    return element;
}

// Peek stack1
int peek1(DoubleStack* ds) {
    if (isEmpty1(ds)) {
        printf("Stack1 is empty! No top element\n");
        return -1;
    }
    return ds->data[ds->top1];
}

// Peek stack2
int peek2(DoubleStack* ds) {
    if (isEmpty2(ds)) {
        printf("Stack2 is empty! No top element\n");
        return -1;
    }
    return ds->data[ds->top2];
}

// Display stack1
void display1(DoubleStack* ds) {
    if (isEmpty1(ds)) {
        printf("Stack1 is empty!\n");
        return;
    }
    
    printf("Stack1 contents (top to bottom): ");
    for (int i = ds->top1; i >= 0; i--) {
        printf("%d ", ds->data[i]);
    }
    printf("\n");
}

// Display stack2
void display2(DoubleStack* ds) {
    if (isEmpty2(ds)) {
        printf("Stack2 is empty!\n");
        return;
    }
    
    printf("Stack2 contents (top to bottom): ");
    for (int i = ds->top2; i < ds->capacity; i++) {
        printf("%d ", ds->data[i]);
    }
    printf("\n");
}

// Display both stacks with array visualization
void displayBoth(DoubleStack* ds) {
    printf("\nArray visualization:\n");
    printf("Index: ");
    for (int i = 0; i < ds->capacity; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    printf("Value: ");
    for (int i = 0; i < ds->capacity; i++) {
        if (i <= ds->top1) {
            printf("%2d ", ds->data[i]);
        } else if (i >= ds->top2) {
            printf("%2d ", ds->data[i]);
        } else {
            printf(" - ");
        }
    }
    printf("\n");
    
    printf("Stack: ");
    for (int i = 0; i < ds->capacity; i++) {
        if (i <= ds->top1) {
            printf("S1 ");
        } else if (i >= ds->top2) {
            printf("S2 ");
        } else {
            printf("   ");
        }
    }
    printf("\n");
    
    printf("Stack1 size: %d, Stack2 size: %d\n", 
           ds->top1 + 1, ds->capacity - ds->top2);
}

// Free double stack memory
void destroyDoubleStack(DoubleStack* ds) {
    if (ds) {
        free(ds->data);
        free(ds);
    }
}

int main() {
    int capacity, choice, element;
    
    printf("Enter double stack capacity: ");
    scanf("%d", &capacity);
    
    DoubleStack* ds = createDoubleStack(capacity);
    if (!ds) return 1;
    
    do {
        printf("\n=== Double Stack Operations ===\n");
        printf("1. Push to Stack1\n");
        printf("2. Push to Stack2\n");
        printf("3. Pop from Stack1\n");
        printf("4. Pop from Stack2\n");
        printf("5. Peek Stack1\n");
        printf("6. Peek Stack2\n");
        printf("7. Display Stack1\n");
        printf("8. Display Stack2\n");
        printf("9. Display Both Stacks\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to push to Stack1: ");
                scanf("%d", &element);
                push1(ds, element);
                break;
                
            case 2:
                printf("Enter element to push to Stack2: ");
                scanf("%d", &element);
                push2(ds, element);
                break;
                
            case 3:
                pop1(ds);
                break;
                
            case 4:
                pop2(ds);
                break;
                
            case 5:
                element = peek1(ds);
                if (element != -1) {
                    printf("Stack1 top element: %d\n", element);
                }
                break;
                
            case 6:
                element = peek2(ds);
                if (element != -1) {
                    printf("Stack2 top element: %d\n", element);
                }
                break;
                
            case 7:
                display1(ds);
                break;
                
            case 8:
                display2(ds);
                break;
                
            case 9:
                displayBoth(ds);
                break;
                
            case 10:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 10);
    
    destroyDoubleStack(ds);
    return 0;
}
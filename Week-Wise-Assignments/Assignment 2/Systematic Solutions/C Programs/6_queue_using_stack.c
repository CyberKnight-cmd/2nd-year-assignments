#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack structure
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Queue using two stacks
typedef struct {
    Stack* stack1;  // For enqueue operations
    Stack* stack2;  // For dequeue operations
    int capacity;
} QueueUsingStack;

// Initialize stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;
    
    stack->data = (int*)malloc(capacity * sizeof(int));
    if (!stack->data) {
        free(stack);
        return NULL;
    }
    
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Check if stack is empty
bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
bool isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push to stack
void pushToStack(Stack* stack, int element) {
    if (!isStackFull(stack)) {
        stack->data[++stack->top] = element;
    }
}

// Pop from stack
int popFromStack(Stack* stack) {
    if (!isStackEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return -1;
}

// Initialize queue using stacks
QueueUsingStack* createQueue(int capacity) {
    QueueUsingStack* queue = (QueueUsingStack*)malloc(sizeof(QueueUsingStack));
    if (!queue) return NULL;
    
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    
    if (!queue->stack1 || !queue->stack2) {
        free(queue);
        return NULL;
    }
    
    queue->capacity = capacity;
    return queue;
}

// Check if queue is empty
bool isQueueEmpty(QueueUsingStack* queue) {
    return isStackEmpty(queue->stack1) && isStackEmpty(queue->stack2);
}

// Check if queue is full
bool isQueueFull(QueueUsingStack* queue) {
    return (queue->stack1->top + 1) + (queue->stack2->top + 1) >= queue->capacity;
}

// Enqueue operation
void enqueue(QueueUsingStack* queue, int element) {
    if (isQueueFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", element);
        return;
    }
    
    // Always push to stack1
    pushToStack(queue->stack1, element);
    printf("Enqueued %d to queue\n", element);
}

// Dequeue operation
int dequeue(QueueUsingStack* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    
    // If stack2 is empty, transfer all elements from stack1 to stack2
    if (isStackEmpty(queue->stack2)) {
        while (!isStackEmpty(queue->stack1)) {
            int element = popFromStack(queue->stack1);
            pushToStack(queue->stack2, element);
        }
    }
    
    // Pop from stack2
    int element = popFromStack(queue->stack2);
    printf("Dequeued %d from queue\n", element);
    return element;
}

// Peek front element
int front(QueueUsingStack* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty! No front element\n");
        return -1;
    }
    
    // If stack2 is empty, transfer all elements from stack1 to stack2
    if (isStackEmpty(queue->stack2)) {
        while (!isStackEmpty(queue->stack1)) {
            int element = popFromStack(queue->stack1);
            pushToStack(queue->stack2, element);
        }
    }
    
    return queue->stack2->data[queue->stack2->top];
}

// Display queue contents
void display(QueueUsingStack* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue contents (front to rear): ");
    
    // First, display elements in stack2 (these are at the front)
    for (int i = queue->stack2->top; i >= 0; i--) {
        printf("%d ", queue->stack2->data[i]);
    }
    
    // Then, display elements in stack1 (these are at the rear)
    for (int i = 0; i <= queue->stack1->top; i++) {
        printf("%d ", queue->stack1->data[i]);
    }
    
    printf("\n");
}

// Display internal stack states
void displayInternalState(QueueUsingStack* queue) {
    printf("\nInternal Stack States:\n");
    
    printf("Stack1 (enqueue stack): ");
    if (isStackEmpty(queue->stack1)) {
        printf("Empty");
    } else {
        for (int i = 0; i <= queue->stack1->top; i++) {
            printf("%d ", queue->stack1->data[i]);
        }
    }
    printf("\n");
    
    printf("Stack2 (dequeue stack): ");
    if (isStackEmpty(queue->stack2)) {
        printf("Empty");
    } else {
        for (int i = 0; i <= queue->stack2->top; i++) {
            printf("%d ", queue->stack2->data[i]);
        }
    }
    printf("\n");
}

// Free queue memory
void destroyQueue(QueueUsingStack* queue) {
    if (queue) {
        if (queue->stack1) {
            free(queue->stack1->data);
            free(queue->stack1);
        }
        if (queue->stack2) {
            free(queue->stack2->data);
            free(queue->stack2);
        }
        free(queue);
    }
}

int main() {
    int capacity, choice, element;
    
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);
    
    QueueUsingStack* queue = createQueue(capacity);
    if (!queue) {
        printf("Failed to create queue!\n");
        return 1;
    }
    
    do {
        printf("\n=== Queue Using Stack Operations ===\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. DISPLAY\n");
        printf("5. SHOW INTERNAL STATE\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
                
            case 2:
                dequeue(queue);
                break;
                
            case 3:
                element = front(queue);
                if (element != -1) {
                    printf("Front element: %d\n", element);
                }
                break;
                
            case 4:
                display(queue);
                break;
                
            case 5:
                displayInternalState(queue);
                break;
                
            case 6:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    destroyQueue(queue);
    return 0;
}
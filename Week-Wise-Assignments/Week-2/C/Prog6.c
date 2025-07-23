#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int top;
}Stack;

Stack* createStack(int capacity){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity*sizeof(int));
}

void resize(Stack *stack){
    stack->capacity *= 2;
    stack->arr = (int*)realloc(stack->arr, stack->capacity*sizeof(int));
}

void enqueue(Stack *stack, int x){
    if(stack->top==stack->capacity-1)
        resize(stack);

    stack->arr[++stack->top] = x;    
}

int dequeue(Stack *stack1, Stack *stack2){
    if(stack2->top==-1){
        while(stack1->top!=-1){
            enqueue(stack2, stack1->arr[stack1->top--]);
        }
    }
    if(stack2->top==-1) printf("Queue is empty!!\n");
    else return stack2->arr[stack2->top--];
}

int peek(Stack *stack1, Stack *stack2){
    if(stack2->top!=-1)
        return stack2->arr[stack2->top];
    
    else if(stack1->top!=-1){

        while(stack1->top!=-1)
            enqueue(stack2, stack1->arr[stack1->top--]);
        
        return stack2->arr[stack2->top];
    }

    else
        printf("Queue is empty!!");

    return -1;
}

void display(Stack *stack1, Stack *stack2){
    // Display stack2 from top to bottom
    printf("Queue: ");
    
    if(stack2->top == -1 && stack1->top == -1){
        printf("Queue is empty!!\n");
        return;
    }

    for(int i = stack2->top; i >= 0; i--){
        printf("%d ", stack2->arr[i]);
    }

    // Display stack1 from bottom to top
    for(int i = 0; i <= stack1->top; i++){
        printf("%d ", stack1->arr[i]);
    }

    printf("\n");
}


int main() {
    // Create two stacks with initial capacity
    Stack *stack1 = createStack(5);
    Stack *stack2 = createStack(5);

    // Enqueue some elements
    enqueue(stack1, 10);
    enqueue(stack1, 20);
    enqueue(stack1, 30);

    // Display queue
    display(stack1, stack2); // Expected: 10 20 30

    // Dequeue one element
    printf("Dequeued: %d\n", dequeue(stack1, stack2)); // Expected: 10

    // Display queue
    display(stack1, stack2); // Expected: 20 30

    // Peek front element
    printf("Front element: %d\n", peek(stack1, stack2)); // Expected: 20

    // Enqueue more elements
    enqueue(stack1, 40);
    enqueue(stack1, 50);

    // Display queue
    display(stack1, stack2); // Expected: 20 30 40 50

    // Dequeue remaining elements
    printf("Dequeued: %d\n", dequeue(stack1, stack2)); // 20
    printf("Dequeued: %d\n", dequeue(stack1, stack2)); // 30
    printf("Dequeued: %d\n", dequeue(stack1, stack2)); // 40
    printf("Dequeued: %d\n", dequeue(stack1, stack2)); // 50

    // Try dequeueing from empty queue
    printf("Dequeued: %d\n", dequeue(stack1, stack2)); // Queue is empty

    // Display queue
    display(stack1, stack2); // Expected: Queue is empty

    return 0;
}

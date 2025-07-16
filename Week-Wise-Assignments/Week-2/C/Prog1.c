#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int *arr;
    int top;
    int capacity;
}Stack;

Stack* createStack(int capacity){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> arr = (int*)malloc(capacity*sizeof(int));
    return stack;
}

void resize(Stack *stack){
    stack->capacity *= 2;
    stack->arr = (int*)realloc(stack->arr, stack->capacity*sizeof(int));
}

void push(Stack *stack, int x){
    if(stack->top + 1 >= stack->capacity)
        resize(stack);
    
    stack->arr[++stack->top] = x;
}

int pop(Stack *stack){
    if(stack->top==-1){
        printf("Queue empty!");
        return -1;
    }

    return stack->arr[stack->top--];
}

int peek(Stack *stack){
    if(stack->top==-1){
        printf("Queue empty!");
        return -1;
    }
    return stack->arr[stack->top];
}

void display(Stack *stack){
    if(stack->top==-1){
        printf("Queue empty!");
        return;
    }

    for(int i = stack->top; i >= 0; i--)
        printf("%d ", stack->arr[i]);

    printf("\n");
}

int main(){
    Stack *stack = createStack(1);
    for(int i = 1;i<6;i++){
        push(stack,i*10);
    }
    display(stack);
    pop(stack);
    display(stack);
    printf("%d\n", peek(stack));
    return 0;
}
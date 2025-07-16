#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *arr;
    int top;
    int capacity;
}Stack;

Stack* createStack(int capacity){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity*sizeof(int));
    return stack;
}

void resize(Stack *stack){
    stack->capacity *=2;
    stack->arr = (int*)realloc(stack->arr, stack->capacity*sizeof(int));
}

void push(Stack *stack, int x){
    if(stack->top==stack->capacity)
        resize(stack);
    stack->arr[++stack->top] = x;
}

int pop(Stack *stack){
    if(stack->top==-1){
        printf("Stack Empty!");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack){
    if(stack->top==-1){
        printf("Stack empty!");
        return -1;
    }
    return stack->arr[stack->top];
}

void display(Stack *stack){
    if(stack->top==-1){
        printf("Stack empty!");
        return;
    }
    for(int i = stack->top; i >= 0; i--){
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}


int main(){
    Stack *abc = createStack(5);
    for(int i = 10;i<16;i++){
        push(abc,i);
        display(abc);
    }

    for(int i = 15;i>10;i--){
        pop(abc);
        display(abc);
    }

    free(abc->arr);
    free(abc);

    return 0;
}
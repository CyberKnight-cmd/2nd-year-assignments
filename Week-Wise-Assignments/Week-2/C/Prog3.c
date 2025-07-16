#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char *arr;
    int capacity;
    int top;
}Stack;

Stack* createStack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = 1;
    stack->top = -1;
    stack->arr = (char*)malloc(stack->capacity*sizeof(char));
    return stack;
}

void resize(Stack *stack){
    stack->capacity *= 2;
    stack->arr = (char*)realloc(stack->arr, stack->capacity*sizeof(char));
}

void push(Stack *stack, char a){
    if(stack->top+1 >= stack->capacity)
        resize(stack);
    stack->arr[++stack->top] = a;
    printf("%c pushed to stack.\n", a);
}

char pop(Stack *stack){
    if(stack->top==-1)
        return '\0';
    
    return stack->arr[stack->top--];
}


int main(){
    char a;
    Stack *str = createStack();
    while (1)
    {
        scanf("%c", &a);
        if(a=='\n')
            break;
        push(str,a);
    }
    
    printf("Reversed String : ");
    // Printing in reverse order
    while(1){
        a = pop(str);
        if(a=='\0')
            break;
        printf("%c", a);
    }
    
    free(str->arr);
    free(str);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int *arr;
    int top1;
    int top2;
    int totalSize;
}DoubleStack;

DoubleStack* createDoubleStack(int totalSize){
    DoubleStack *doubleStack = (DoubleStack*)malloc(sizeof(DoubleStack));
    doubleStack->totalSize = totalSize;
    doubleStack->top1 = -1;
    doubleStack->top2 = totalSize;
    doubleStack->arr = (int*)malloc((doubleStack->totalSize)*sizeof(int));
    return doubleStack;
}

void resize(DoubleStack *doubleStack){
    int oldSize = doubleStack->totalSize;
    doubleStack->totalSize *= 2;
    int newTop = doubleStack->totalSize;
    doubleStack->arr = (int*)realloc(doubleStack->arr, doubleStack->totalSize*sizeof(int));
    int shift = doubleStack->totalSize - oldSize;
    for(int i = oldSize - 1; i >= doubleStack->top2; i--){
        doubleStack->arr[i + shift] = doubleStack->arr[i];
    }
    doubleStack->top2 += shift;
}

void push(DoubleStack *doubleStack, int x, int flag){
    if(doubleStack->top1 + 1 >= doubleStack->top2){
        resize(doubleStack);
    }

    if(!flag)
        doubleStack->arr[++doubleStack->top1] = x;
    else
        doubleStack->arr[--doubleStack->top2] = x;
}

int pop(DoubleStack *doubleStack, int flag){
    if(!flag){
        if(doubleStack->top1==-1){
            printf("Stack empty!!\n");
            return -1;
        }
        return doubleStack->arr[doubleStack->top1--];
    }
    if(doubleStack->top2==doubleStack->totalSize){
            printf("Stack empty!!\n");
            return -1;
        }
        return doubleStack->arr[doubleStack->top2++];
}
int peek(DoubleStack *doubleStack, int flag){
    if(!flag)
        if(doubleStack->top1!=-1)
            return doubleStack->arr[doubleStack->top1];
    if(doubleStack->top2!=doubleStack->totalSize)
        return doubleStack->arr[doubleStack->top2];
    return -1;
}

void display(DoubleStack *doubleStack){
    // For Stack 1
    printf("Stack 1 : ");
    for(int i = doubleStack->top1; i >= 0; i--){
        printf("%d ", doubleStack->arr[i]);
    }
    printf("\nStack 2 : ");
    for(int i = doubleStack->top2; i < doubleStack->totalSize; i++){
        printf("%d ", doubleStack->arr[i]);
    }
}

int main() {
    // Create double stack with initial size 4
    DoubleStack *ds = createDoubleStack(4);

    // Push elements into Stack1 (flag = 0)
    push(ds, 10, 0);
    push(ds, 20, 0);
    push(ds, 30, 0);

    // Push elements into Stack2 (flag = 1)
    push(ds, 100, 1);
    push(ds, 200, 1);
    push(ds, 300, 1);

    // Display both stacks
    display(ds);
    printf("\n");

    // Peek top of Stack1
    int val = peek(ds, 0);
    if(val != -1)
        printf("Peek Stack1: %d\n", val);
    else
        printf("Stack1 is empty.\n");

    // Peek top of Stack2
    val = peek(ds, 1);
    if(val != -1)
        printf("Peek Stack2: %d\n", val);
    else
        printf("Stack2 is empty.\n");

    // Pop elements from Stack1
    printf("Pop Stack1: %d\n", pop(ds, 0));
    printf("Pop Stack1: %d\n", pop(ds, 0));

    // Pop elements from Stack2
    printf("Pop Stack2: %d\n", pop(ds, 1));
    printf("Pop Stack2: %d\n", pop(ds, 1));

    // Display stacks again after popping
    display(ds);
    printf("\n");

    // Free memory
    free(ds->arr);
    free(ds);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
    char *arr;
    int capacity;
    int rear;
    int front;
}Queue;

Queue* createQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = 1;
    queue->rear = queue->front = -1;
    queue->arr = (char*)malloc(queue->capacity * sizeof(char));
    return queue;
}

void resize(Queue *queue){
    queue->capacity *= 2;
    queue->arr = (char*)realloc(queue->arr, queue->capacity*sizeof(char));
}

void enqueue(Queue* queue, int x){
    if(queue->rear + 1 >=queue->capacity)
        resize(queue);
    if(queue->front==-1)
        queue->front = 0;
    queue->arr[++queue->rear] = x;
}


void display(Queue *queue){
    if(queue->front==-1 || queue->front > queue->rear){
        printf("Queue empty.");
        return;
    }
    for(int i = queue->front; i <= queue->rear; i++){
        printf("%c", queue->arr[i]);
    }

    printf("\n");
}

bool filtered(char c){
    if((c >= '0' && c <= '9') || 
       (c >= 'A' && c <= 'Z') || 
       (c >= 'a' && c <= 'z'))
        return true;
    else
        return false;
}


bool is_palindrome(Queue *queue){
    int tempFront = queue->front, tempRear = queue->rear;
    bool isPalindrome = true;
    while(tempFront<tempRear){
        if (queue->arr[tempFront]!=queue->arr[tempRear])
        {
            
            isPalindrome = false;
            break;
        }
        tempFront++;
        tempRear--;
    }
    return isPalindrome;
}

int main(){
    char a;
    Queue *str = createQueue();

    printf("Enter a string (end input with Enter key):\n");
    while (1){
        scanf("%c", &a);
        if(a == '\n')
            break;
        
        if(filtered(a)){
            if(a >= 'A' && a <= 'Z')
                a = a + 32;
            enqueue(str, a);
        }
    }

    printf("The entered queue is: ");
    display(str);

    if(is_palindrome(str))
        printf("It is a palindrome.\n");
    else
        printf("It is not a palindrome.\n");

    // Free memory
    free(str->arr);
    free(str);

    return 0;
}
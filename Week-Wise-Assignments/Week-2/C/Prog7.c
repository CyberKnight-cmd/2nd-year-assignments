#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *arr;
    int capacity;
    int size;
    int front;
    int rear;
}Queue;

Queue* createQueue(int capacity){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = queue->rear = -1;
    queue->arr = (int*)malloc(capacity*sizeof(int));
    return queue;
}


bool isFull(Queue *queue){
    return (queue->size == queue->capacity);
}


bool isEmpty(Queue *queue){
    if(queue->size == 0){
        printf("Queue is empty!!!!!\n");
        return true;
    }
    else 
        return false;    
}

void resize(Queue *queue){
    int oldCapacity = queue->capacity;
    queue->capacity *= 2;
    queue->arr = (int*)realloc(queue->arr, queue->capacity*sizeof(int));
    if(queue->front <= queue->rear)
        return;

    for(int i = 0; i <= queue->rear; i++){
        queue->arr[i + oldCapacity] = queue->arr[i];
    }
    queue->rear = queue->rear + oldCapacity;
}

void enqueue(Queue *queue, int x){
    if(isFull(queue))
        resize(queue);
    
    if(isEmpty(queue))
        queue->front = queue->rear = 0; 
    else
        queue->rear = (queue->rear + 1)%queue->capacity;

    queue->arr[queue->rear] = x;
    queue->size++;
}

int dequeue(Queue *queue){
    if(isEmpty(queue))  return -1;
    
    int element = queue->arr[queue->front];
    if(queue->front==queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->capacity;
    
    queue->size--;
    return element;
}

int peek(Queue *queue){
    if(isEmpty(queue))  return -1;
    else return queue->arr[queue->front];
}

void display(Queue *queue){
    if(isEmpty(queue))  return;
    else{
        int index = queue->front;
        for(int i = 0; i < queue->size; i++){
            printf("%d ", queue->arr[index]);
            index = (index+1) % queue->capacity;
        }
    }
    printf("\n");
}

int main(){
    Queue *q = createQueue(3);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    enqueue(q,40);
    display(q);

    printf("Peek: %d\n", peek(q));

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *arr;
    int capacity;
    int front;
    int rear;
}Queue;

Queue* createQueue(int size){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = size;
    queue->front = queue->rear = -1;
    queue->arr = (int*)malloc(size*sizeof(int));
    return queue;
}

int isFull(Queue *queue){
    return (queue->rear == queue->capacity - 1);
}

int isEmpty(Queue *queue){
    return (queue->front == -1 || queue->front>queue->rear);
}

void resize(Queue *queue){
    queue-> capacity*= 2;
    queue->arr = (int*)realloc(queue->arr, queue->capacity*sizeof(int));
}

void enqueue(Queue* queue, int x){
    if(isFull(queue))
        resize(queue);
    
    // For first insertion
    if(queue->front==-1)
        queue->front = 0;
    
    queue->arr[++queue->rear] = x;
    printf("%d enqueued to queue \n", x);
}

int dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty!");
        if(queue->front>queue->rear)
        queue->front = queue->rear = -1;
        return -1;
    }

    return queue->arr[queue->front++];
}

int peek(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty!");
        return -1;
    }
    return queue->arr[queue->front];
}

void display(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty!");
        return;
    }
    printf("Queue elements : ");
    for(int i = queue->front; i <= queue->rear; i++){
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}




int main(){
    Queue *queue = createQueue(3);
    printf("%d\n",isEmpty(queue));
    enqueue(queue, 20);
    display(queue);
    enqueue(queue, 30);
    display(queue);
    enqueue(queue, 30);
    display(queue);
    // printf("%d\n", queue->capacity);
    enqueue(queue, 40);
    display(queue);
    // printf("%d", queue->capacity);
    dequeue(queue);
    display(queue);
    free(queue->arr);
    free(queue);
    return 0;
}
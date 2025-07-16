#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int *arr;
    int capacity;
    int rear;
    int front;
}Queue;

Queue* createQueue(int capacity){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->rear = queue->front = -1;
    return queue;
}

void resize(Queue *queue){
    queue->capacity *= 2;
    queue->arr = (int*)realloc(queue->arr, queue->capacity*sizeof(int));
}

void enqueue(Queue* queue, int x){
    if(queue->rear + 1 >=queue->capacity)
        resize(queue);
    if(queue->front==-1)
        queue->front = 0;
    queue->arr[++queue->rear] = x;
}

int dequeue(Queue* queue){
    if(queue->front==-1 || queue->front > queue->rear){
        printf("Queue empty.");
        return -1;
    }
    return queue->arr[queue->front--];
}

int peek(Queue *queue){
    if(queue->front==-1 || queue->front > queue->rear){
        printf("Queue empty.");
        return -1;
    }
    return queue->arr[queue->front];
}

void display(Queue *queue){
    if(queue->front==-1 || queue->front > queue->rear){
        printf("Queue empty.");
        return;
    }
    for(int i = queue->front; i <= queue->rear; i++){
        printf("%d ", queue->arr[i]);
    }

    printf("\n");
}

int main() {
    // 1. Create a queue with initial capacity 4
    Queue *q = createQueue(4);
    // 2. Enqueue elements to fill initial capacity and force a resize
    for (int i = 1; i <= 8; i++) {
        enqueue(q, i);
        printf("Enqueued %d (size now %d / capacity %d)\n", i, q->rear - q->front + 1, q->capacity);
    }

    // 3. Display current contents
    printf("Queue after enqueues: ");
    display(q);

    // 4. Peek at the front element
    printf("Peek: %d\n", peek(q));

    // 5. Dequeue a few elements
    for (int i = 0; i < 3; i++) {
        int val = dequeue(q);
        printf("Dequeued %d\n", val);
    }

    // 6. Display again after dequeues
    printf("Queue now: ");
    display(q);

    // 7. Enqueue more to trigger another resize
    for (int i = 9; i <= 12; i++) {
        enqueue(q, i);
        printf("Enqueued %d (size now %d / capacity %d)\n", i, q->rear - q->front + 1, q->capacity);
    }

    printf("Final queue: ");
    display(q);

    // Clean up
    free(q->arr);
    free(q);
    return 0;
}
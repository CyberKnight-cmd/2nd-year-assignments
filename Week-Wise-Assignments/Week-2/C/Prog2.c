#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int rear;
    int front;
    int size;
} Queue;

Queue* createQueue(int capacity) {
    Queue *queue = malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->arr = malloc(capacity * sizeof(int));
    if (!queue->arr) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return queue;
}

void resize(Queue *queue) {
    int oldCap = queue->capacity;
    int newCap = oldCap * 2;
    int *newArr = malloc(newCap * sizeof(int));
    if (!newArr) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Copy elements in order from front to rear
    for (int i = 0; i < queue->size; i++) {
        newArr[i] = queue->arr[(queue->front + i) % oldCap];
    }

    free(queue->arr);
    queue->arr = newArr;
    queue->capacity = newCap;
    queue->front = 0;
    queue->rear = queue->size - 1;
}

void enqueue(Queue *queue, int x) {
    if (queue->size == queue->capacity)
        resize(queue);
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = x;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue empty.\n");
        return -1;
    }
    int val = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    if (queue->size == 0) {
        // Reset to initial state when empty
        queue->front = 0;
        queue->rear = -1;
    }
    return val;
}

int peek(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue empty.\n");
        return -1;
    }
    return queue->arr[queue->front];
}

void display(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue empty.\n");
        return;
    }
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d ", queue->arr[index]);
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue(4);

    for (int i = 1; i <= 8; i++) {
        enqueue(q, i);
        printf("Enqueued %d (size now %d / capacity %d)\n", i, q->size, q->capacity);
    }

    printf("Queue after enqueues: ");
    display(q);

    printf("Peek: %d\n", peek(q));

    for (int i = 0; i < 3; i++) {
        int val = dequeue(q);
        printf("Dequeued %d\n", val);
    }

    printf("Queue now: ");
    display(q);

    for (int i = 9; i <= 12; i++) {
        enqueue(q, i);
        printf("Enqueued %d (size now %d / capacity %d)\n", i, q->size, q->capacity);
    }

    printf("Final queue: ");
    display(q);

    free(q->arr);
    free(q);
    return 0;
}

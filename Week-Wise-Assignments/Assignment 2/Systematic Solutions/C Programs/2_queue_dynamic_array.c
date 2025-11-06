#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue structure
typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;

// Initialize queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    queue->data = (int*)malloc(capacity * sizeof(int));
    if (!queue->data) {
        printf("Memory allocation failed!\n");
        free(queue);
        return NULL;
    }
    
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

// Check if queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Check if queue is full
bool isFull(Queue* queue) {
    return queue->size == queue->capacity;
}

// ENQUEUE operation
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", element);
        return;
    }
    
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = element;
    queue->size++;
    printf("Enqueued %d to queue\n", element);
}

// DEQUEUE operation
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    
    int element = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    printf("Dequeued %d from queue\n", element);
    return element;
}

// FRONT operation (peek at front element)
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No front element\n");
        return -1;
    }
    
    return queue->data[queue->front];
}

// REAR operation (peek at rear element)
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No rear element\n");
        return -1;
    }
    
    return queue->data[queue->rear];
}

// DISPLAY operation
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue contents (front to rear): ");
    int i = queue->front;
    for (int count = 0; count < queue->size; count++) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

// Get queue size
int getSize(Queue* queue) {
    return queue->size;
}

// Free queue memory
void destroyQueue(Queue* queue) {
    if (queue) {
        free(queue->data);
        free(queue);
    }
}

int main() {
    int capacity, choice, element;
    
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);
    
    Queue* queue = createQueue(capacity);
    if (!queue) return 1;
    
    do {
        printf("\n=== Queue Operations ===\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. REAR\n");
        printf("5. DISPLAY\n");
        printf("6. SIZE\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
                
            case 2:
                dequeue(queue);
                break;
                
            case 3:
                element = front(queue);
                if (element != -1) {
                    printf("Front element: %d\n", element);
                }
                break;
                
            case 4:
                element = rear(queue);
                if (element != -1) {
                    printf("Rear element: %d\n", element);
                }
                break;
                
            case 5:
                display(queue);
                break;
                
            case 6:
                printf("Queue size: %d\n", getSize(queue));
                break;
                
            case 7:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    
    destroyQueue(queue);
    return 0;
}
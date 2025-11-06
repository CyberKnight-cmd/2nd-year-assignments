#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Circular Queue structure
typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
    int size;
} CircularQueue;

// Initialize circular queue
CircularQueue* createCircularQueue(int capacity) {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
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
    
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

// Check if queue is empty
bool isEmpty(CircularQueue* queue) {
    return queue->size == 0;
}

// Check if queue is full
bool isFull(CircularQueue* queue) {
    return queue->size == queue->capacity;
}

// Enqueue operation
void enqueue(CircularQueue* queue, int element) {
    if (isFull(queue)) {
        printf("Circular Queue Overflow! Cannot enqueue %d\n", element);
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    
    queue->data[queue->rear] = element;
    queue->size++;
    printf("Enqueued %d to circular queue\n", element);
}

// Dequeue operation
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue Underflow! Cannot dequeue from empty queue\n");
        return -1;
    }
    
    int element = queue->data[queue->front];
    
    if (queue->size == 1) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    
    queue->size--;
    printf("Dequeued %d from circular queue\n", element);
    return element;
}

// Peek front element
int front(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty! No front element\n");
        return -1;
    }
    
    return queue->data[queue->front];
}

// Peek rear element
int rear(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty! No rear element\n");
        return -1;
    }
    
    return queue->data[queue->rear];
}

// Display queue contents
void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty!\n");
        return;
    }
    
    printf("Circular queue contents (front to rear): ");
    int i = queue->front;
    for (int count = 0; count < queue->size; count++) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

// Display queue with array visualization
void displayWithVisualization(CircularQueue* queue) {
    printf("\nCircular Queue Visualization:\n");
    printf("Capacity: %d, Size: %d\n", queue->capacity, queue->size);
    printf("Front: %d, Rear: %d\n", queue->front, queue->rear);
    
    printf("Index: ");
    for (int i = 0; i < queue->capacity; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    printf("Value: ");
    for (int i = 0; i < queue->capacity; i++) {
        if (isEmpty(queue)) {
            printf(" - ");
        } else {
            bool isOccupied = false;
            int j = queue->front;
            for (int count = 0; count < queue->size; count++) {
                if (j == i) {
                    isOccupied = true;
                    break;
                }
                j = (j + 1) % queue->capacity;
            }
            
            if (isOccupied) {
                printf("%2d ", queue->data[i]);
            } else {
                printf(" - ");
            }
        }
    }
    printf("\n");
    
    printf("Pos:   ");
    for (int i = 0; i < queue->capacity; i++) {
        if (i == queue->front && i == queue->rear && !isEmpty(queue)) {
            printf("FR ");
        } else if (i == queue->front && !isEmpty(queue)) {
            printf("F  ");
        } else if (i == queue->rear && !isEmpty(queue)) {
            printf("R  ");
        } else {
            printf("   ");
        }
    }
    printf("\n");
}

// Get queue size
int getSize(CircularQueue* queue) {
    return queue->size;
}

// Free queue memory
void destroyCircularQueue(CircularQueue* queue) {
    if (queue) {
        free(queue->data);
        free(queue);
    }
}

int main() {
    int capacity, choice, element;
    
    printf("Enter circular queue capacity: ");
    scanf("%d", &capacity);
    
    CircularQueue* queue = createCircularQueue(capacity);
    if (!queue) return 1;
    
    do {
        printf("\n=== Circular Queue Operations ===\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. REAR\n");
        printf("5. DISPLAY\n");
        printf("6. DISPLAY WITH VISUALIZATION\n");
        printf("7. SIZE\n");
        printf("8. Exit\n");
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
                displayWithVisualization(queue);
                break;
                
            case 7:
                printf("Queue size: %d\n", getSize(queue));
                break;
                
            case 8:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);
    
    destroyCircularQueue(queue);
    return 0;
}
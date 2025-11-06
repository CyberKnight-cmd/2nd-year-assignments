#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Algorithm for Enqueue Operation (Insert at rear):
// 1. Create a new node with given data
// 2. If queue is empty, set both front and rear to new node
// 3. Otherwise, link current rear to new node and update rear
// 4. Increment size
void enqueue(struct Queue* queue, int data) {
    printf("\nEnqueue Operation - Adding %d to queue:\n", data);
    printf("Step 1: Create new node with data %d\n", data);
    
    struct Node* newNode = createNode(data);
    
    if (queue->rear == NULL) {
        printf("Step 2: Queue is empty, set both front and rear to new node\n");
        queue->front = queue->rear = newNode;
    } else {
        printf("Step 2: Queue not empty, link current rear to new node\n");
        queue->rear->next = newNode;
        printf("Step 3: Update rear to point to new node\n");
        queue->rear = newNode;
    }
    
    queue->size++;
    printf("Step 4: Increment size (now %d)\n", queue->size);
    printf("Enqueue successful! %d added to rear of queue.\n", data);
}

// Algorithm for Dequeue Operation (Remove from front):
// 1. Check if queue is empty
// 2. Store front node's data
// 3. Update front to next node
// 4. If queue becomes empty, set rear to NULL
// 5. Free the old front node and decrement size
int dequeue(struct Queue* queue) {
    printf("\nDequeue Operation:\n");
    
    if (queue->front == NULL) {
        printf("Queue Underflow! Cannot dequeue from empty queue.\n");
        return -1;
    }
    
    printf("Step 1: Queue is not empty, proceeding with dequeue\n");
    printf("Step 2: Store front node's data (%d)\n", queue->front->data);
    
    int data = queue->front->data;
    struct Node* temp = queue->front;
    
    printf("Step 3: Update front to next node\n");
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        printf("Step 4: Queue became empty, set rear to NULL\n");
        queue->rear = NULL;
    }
    
    printf("Step 5: Free old front node and decrement size\n");
    free(temp);
    queue->size--;
    
    printf("Dequeue successful! Removed %d from front of queue (size now %d).\n", data, queue->size);
    return data;
}

// Function to peek at front element without removing it
int front(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty! No front element to peek.\n");
        return -1;
    }
    return queue->front->data;
}

// Function to peek at rear element
int rear(struct Queue* queue) {
    if (queue->rear == NULL) {
        printf("Queue is empty! No rear element to peek.\n");
        return -1;
    }
    return queue->rear->data;
}

// Function to check if queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to get queue size
int getSize(struct Queue* queue) {
    return queue->size;
}

// Function to display queue
void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("\nQueue contents (front to rear):\n");
    printf("FRONT -> ");
    
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL <- REAR\n");
    printf("Queue size: %d\n", queue->size);
}

// Function to free queue memory
void freeQueue(struct Queue* queue) {
    while (queue->front != NULL) {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;
    
    printf("=== Queue Implementation using Single Linked List ===\n");
    printf("Queue follows FIFO (First In First Out) principle\n");
    printf("Operations: Enqueue (insert at rear), Dequeue (remove from front)\n\n");
    
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue (Insert element)\n");
        printf("2. Dequeue (Remove element)\n");
        printf("3. Front (View front element)\n");
        printf("4. Rear (View rear element)\n");
        printf("5. Display queue\n");
        printf("6. Check if empty\n");
        printf("7. Get queue size\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
                
            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
                
            case 3:
                data = front(queue);
                if (data != -1) {
                    printf("Front element: %d\n", data);
                }
                break;
                
            case 4:
                data = rear(queue);
                if (data != -1) {
                    printf("Rear element: %d\n", data);
                }
                break;
                
            case 5:
                displayQueue(queue);
                break;
                
            case 6:
                if (isEmpty(queue)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
                
            case 7:
                printf("Queue size: %d\n", getSize(queue));
                break;
                
            case 8:
                printf("Exiting program...\n");
                freeQueue(queue);
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
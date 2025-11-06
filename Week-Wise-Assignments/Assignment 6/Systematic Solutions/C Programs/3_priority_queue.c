#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Element {
    int data;
    int priority;
};

struct PriorityQueue {
    struct Element elements[MAX_SIZE];
    int size;
};

// Initialize priority queue
void initPriorityQueue(struct PriorityQueue* pq) {
    pq->size = 0;
}

// Check if priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return pq->size == 0;
}

// Check if priority queue is full
int isFull(struct PriorityQueue* pq) {
    return pq->size == MAX_SIZE;
}

// Algorithm for Enqueue (Insert with Priority):
// 1. Check if queue is full
// 2. Find correct position based on priority (higher priority first)
// 3. Shift elements to make space
// 4. Insert new element at correct position
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    printf("\n=== Enqueue Operation ===\n");
    printf("Inserting element %d with priority %d\n", data, priority);
    
    if (isFull(pq)) {
        printf("Priority Queue is full! Cannot insert.\n");
        return;
    }
    
    // Find correct position (higher priority first)
    int position = 0;
    while (position < pq->size && pq->elements[position].priority >= priority) {
        position++;
    }
    
    printf("Found insertion position: %d\n", position);
    
    // Shift elements to make space
    printf("Shifting elements to make space...\n");
    for (int i = pq->size; i > position; i--) {
        pq->elements[i] = pq->elements[i - 1];
        printf("Moved element %d (priority %d) from position %d to %d\n", 
               pq->elements[i].data, pq->elements[i].priority, i-1, i);
    }
    
    // Insert new element
    pq->elements[position].data = data;
    pq->elements[position].priority = priority;
    pq->size++;
    
    printf("Element %d inserted at position %d with priority %d\n", data, position, priority);
    printf("Queue size is now: %d\n", pq->size);
}

// Algorithm for Dequeue (Remove Highest Priority):
// 1. Check if queue is empty
// 2. Remove first element (highest priority)
// 3. Shift remaining elements forward
struct Element dequeue(struct PriorityQueue* pq) {
    printf("\n=== Dequeue Operation ===\n");
    
    struct Element emptyElement = {-1, -1};
    
    if (isEmpty(pq)) {
        printf("Priority Queue is empty! Cannot dequeue.\n");
        return emptyElement;
    }
    
    struct Element removedElement = pq->elements[0];
    printf("Removing element %d with highest priority %d\n", 
           removedElement.data, removedElement.priority);
    
    // Shift elements forward
    printf("Shifting remaining elements forward...\n");
    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
        printf("Moved element %d (priority %d) from position %d to %d\n", 
               pq->elements[i].data, pq->elements[i].priority, i+1, i);
    }
    
    pq->size--;
    printf("Element %d dequeued successfully\n", removedElement.data);
    printf("Queue size is now: %d\n", pq->size);
    
    return removedElement;
}

// Peek at highest priority element
struct Element peek(struct PriorityQueue* pq) {
    struct Element emptyElement = {-1, -1};
    
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return emptyElement;
    }
    
    return pq->elements[0];
}

// Display priority queue
void display(struct PriorityQueue* pq) {
    printf("\n=== Priority Queue Contents ===\n");
    
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return;
    }
    
    printf("Queue size: %d\n", pq->size);
    printf("Elements (sorted by priority - highest first):\n");
    printf("Position | Data | Priority\n");
    printf("---------|------|----------\n");
    
    for (int i = 0; i < pq->size; i++) {
        printf("   %2d    | %4d |    %2d\n", 
               i, pq->elements[i].data, pq->elements[i].priority);
    }
    
    if (pq->size > 0) {
        printf("\nFront (highest priority): Data=%d, Priority=%d\n", 
               pq->elements[0].data, pq->elements[0].priority);
    }
}

// Get size of priority queue
int getSize(struct PriorityQueue* pq) {
    return pq->size;
}

// Search for element by data
int search(struct PriorityQueue* pq, int data) {
    printf("\n=== Search Operation ===\n");
    printf("Searching for element %d\n", data);
    
    for (int i = 0; i < pq->size; i++) {
        if (pq->elements[i].data == data) {
            printf("Element %d found at position %d with priority %d\n", 
                   data, i, pq->elements[i].priority);
            return i;
        }
    }
    
    printf("Element %d not found in priority queue\n", data);
    return -1;
}

// Change priority of an element
void changePriority(struct PriorityQueue* pq, int data, int newPriority) {
    printf("\n=== Change Priority Operation ===\n");
    printf("Changing priority of element %d to %d\n", data, newPriority);
    
    // Find element
    int position = -1;
    for (int i = 0; i < pq->size; i++) {
        if (pq->elements[i].data == data) {
            position = i;
            break;
        }
    }
    
    if (position == -1) {
        printf("Element %d not found in priority queue\n", data);
        return;
    }
    
    printf("Element %d found at position %d with current priority %d\n", 
           data, position, pq->elements[position].priority);
    
    // Remove element
    struct Element element = pq->elements[position];
    for (int i = position; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }
    pq->size--;
    
    // Re-insert with new priority
    enqueue(pq, data, newPriority);
    printf("Priority changed successfully!\n");
}

int main() {
    struct PriorityQueue pq;
    initPriorityQueue(&pq);
    
    int choice, data, priority;
    struct Element element;
    
    printf("=== Priority Queue Implementation ===\n");
    printf("Higher priority numbers have higher precedence\n");
    printf("Elements are automatically sorted by priority\n\n");
    
    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1.  Enqueue (Insert with priority)\n");
        printf("2.  Dequeue (Remove highest priority)\n");
        printf("3.  Peek (View highest priority)\n");
        printf("4.  Display queue\n");
        printf("5.  Search element\n");
        printf("6.  Change priority\n");
        printf("7.  Get queue size\n");
        printf("8.  Check if empty\n");
        printf("9.  Check if full\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority (higher number = higher priority): ");
                scanf("%d", &priority);
                enqueue(&pq, data, priority);
                break;
                
            case 2:
                element = dequeue(&pq);
                if (element.data != -1) {
                    printf("Dequeued: Data=%d, Priority=%d\n", element.data, element.priority);
                }
                break;
                
            case 3:
                element = peek(&pq);
                if (element.data != -1) {
                    printf("Front element: Data=%d, Priority=%d\n", element.data, element.priority);
                } else {
                    printf("Queue is empty!\n");
                }
                break;
                
            case 4:
                display(&pq);
                break;
                
            case 5:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(&pq, data);
                break;
                
            case 6:
                printf("Enter data of element to change priority: ");
                scanf("%d", &data);
                printf("Enter new priority: ");
                scanf("%d", &priority);
                changePriority(&pq, data, priority);
                break;
                
            case 7:
                printf("Queue size: %d\n", getSize(&pq));
                break;
                
            case 8:
                printf("Queue is %s\n", isEmpty(&pq) ? "empty" : "not empty");
                break;
                
            case 9:
                printf("Queue is %s\n", isFull(&pq) ? "full" : "not full");
                break;
                
            case 10:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
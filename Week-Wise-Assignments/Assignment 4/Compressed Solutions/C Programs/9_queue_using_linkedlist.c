#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL, *rear = NULL;

void enqueue(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    
    if (!rear) {
        front = rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
}

int dequeue() {
    if (!front) return -1;
    int data = front->data;
    struct Node* temp = front;
    front = front->next;
    if (!front) rear = NULL;
    free(temp);
    return data;
}

void display() {
    for (struct Node* temp = front; temp; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    printf("Queue: ");
    display();
    
    printf("Dequeued: %d\n", dequeue());
    printf("Queue: ");
    display();
    
    return 0;
}
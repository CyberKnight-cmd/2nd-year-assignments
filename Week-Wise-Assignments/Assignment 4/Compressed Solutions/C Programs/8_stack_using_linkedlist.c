#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = top;
    top = node;
}

int pop() {
    if (!top) return -1;
    int data = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return data;
}

void display() {
    for (struct Node* temp = top; temp; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    
    printf("Stack: ");
    display();
    
    printf("Popped: %d\n", pop());
    printf("Stack: ");
    display();
    
    return 0;
}
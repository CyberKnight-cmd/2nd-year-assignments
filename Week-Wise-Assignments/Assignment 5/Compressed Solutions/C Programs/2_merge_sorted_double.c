#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

struct Node* merge(struct Node* l1, struct Node* l2) {
    struct Node dummy = {0, NULL, NULL};
    struct Node* tail = &dummy;
    
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1->prev = tail;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2->prev = tail;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    if (l1) { tail->next = l1; l1->prev = tail; }
    if (l2) { tail->next = l2; l2->prev = tail; }
    
    if (dummy.next) dummy.next->prev = NULL;
    return dummy.next;
}

void display(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->prev = l1;
    l1->next->next = createNode(5);
    l1->next->next->prev = l1->next;
    
    struct Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->prev = l2;
    l2->next->next = createNode(6);
    l2->next->next->prev = l2->next;
    
    printf("List 1: "); display(l1);
    printf("List 2: "); display(l2);
    
    struct Node* merged = merge(l1, l2);
    printf("Merged: "); display(merged);
    
    return 0;
}
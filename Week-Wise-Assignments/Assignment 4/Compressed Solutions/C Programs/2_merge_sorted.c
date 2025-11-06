#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* merge(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    if (l1->data <= l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
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
    l1->next->next = createNode(5);
    
    struct Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);
    
    printf("List 1: ");
    display(l1);
    printf("List 2: ");
    display(l2);
    
    struct Node* merged = merge(l1, l2);
    printf("Merged: ");
    display(merged);
    
    return 0;
}
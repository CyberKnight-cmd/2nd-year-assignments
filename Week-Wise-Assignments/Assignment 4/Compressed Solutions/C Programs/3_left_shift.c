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

struct Node* leftShift(struct Node* head, int k) {
    if (!head || k == 0) return head;
    
    struct Node* curr = head;
    int len = 1;
    while (curr->next) {
        curr = curr->next;
        len++;
    }
    
    k = k % len;
    if (k == 0) return head;
    
    curr->next = head;
    for (int i = 0; i < len - k; i++) {
        curr = curr->next;
    }
    
    head = curr->next;
    curr->next = NULL;
    return head;
}

void display(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    printf("Original: ");
    display(head);
    
    head = leftShift(head, 2);
    printf("Left shifted by 2: ");
    display(head);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* node = malloc(sizeof(struct Node));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (!*head || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next && temp->next->exp > exp) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

struct Node* multiply(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    for (struct Node* t1 = p1; t1; t1 = t1->next) {
        for (struct Node* t2 = p2; t2; t2 = t2->next) {
            insertTerm(&result, t1->coeff * t2->coeff, t1->exp + t2->exp);
        }
    }
    return result;
}

void display(struct Node* head) {
    while (head) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next) printf(" + ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* p1 = createNode(2, 1);
    p1->next = createNode(1, 0);
    
    struct Node* p2 = createNode(3, 1);
    p2->next = createNode(2, 0);
    
    printf("P1: ");
    display(p1);
    printf("P2: ");
    display(p2);
    
    struct Node* result = multiply(p1, p2);
    printf("Product: ");
    display(result);
    
    return 0;
}
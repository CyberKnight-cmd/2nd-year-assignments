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

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL, *tail = NULL;
    
    while (p1 || p2) {
        struct Node* newNode;
        if (!p1) {
            newNode = createNode(p2->coeff, p2->exp);
            p2 = p2->next;
        } else if (!p2) {
            newNode = createNode(p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp > p2->exp) {
            newNode = createNode(p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            newNode = createNode(p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            newNode = createNode(p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if (!result) result = tail = newNode;
        else tail = tail->next = newNode;
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
    struct Node* p1 = createNode(3, 2);
    p1->next = createNode(2, 1);
    p1->next->next = createNode(1, 0);
    
    struct Node* p2 = createNode(4, 2);
    p2->next = createNode(3, 1);
    
    printf("P1: ");
    display(p1);
    printf("P2: ");
    display(p2);
    
    struct Node* result = addPolynomials(p1, p2);
    printf("Sum: ");
    display(result);
    
    return 0;
}
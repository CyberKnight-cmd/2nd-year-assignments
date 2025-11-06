#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = node->prev = node;
    return node;
}

void display() {
    if (!head) { printf("Empty\n"); return; }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertBegin(int data) {
    struct Node* node = createNode(data);
    if (!head) {
        head = node;
    } else {
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
        head = node;
    }
}

void insertEnd(int data) {
    struct Node* node = createNode(data);
    if (!head) {
        head = node;
    } else {
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
    }
}

int search(int key) {
    if (!head) return -1;
    struct Node* temp = head;
    int pos = 0;
    do {
        if (temp->data == key) return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}

int count() {
    if (!head) return 0;
    int c = 0;
    struct Node* temp = head;
    do {
        c++;
        temp = temp->next;
    } while (temp != head);
    return c;
}

void deleteBegin() {
    if (!head) return;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        free(temp);
    }
}

void deleteEnd() {
    if (!head) return;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* last = head->prev;
        last->prev->next = head;
        head->prev = last->prev;
        free(last);
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("1.Display 2.InsertBegin 3.InsertEnd 4.Search 5.Count 6.DelBegin 7.DelEnd 8.Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: display(); break;
            case 2: scanf("%d", &data); insertBegin(data); break;
            case 3: scanf("%d", &data); insertEnd(data); break;
            case 4: scanf("%d", &data); printf("Found at: %d\n", search(data)); break;
            case 5: printf("Count: %d\n", count()); break;
            case 6: deleteBegin(); break;
            case 7: deleteEnd(); break;
            case 8: exit(0);
        }
    }
}
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
    node->next = node->prev = NULL;
    return node;
}

void display() {
    if (!head) { printf("Empty\n"); return; }
    for (struct Node* temp = head; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

void insertBegin(int data) {
    struct Node* node = createNode(data);
    if (head) head->prev = node;
    node->next = head;
    head = node;
}

void insertEnd(int data) {
    struct Node* node = createNode(data);
    if (!head) { head = node; return; }
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    node->prev = temp;
}

void insertPos(int data, int pos) {
    if (pos == 0) { insertBegin(data); return; }
    struct Node* node = createNode(data);
    struct Node* temp = head;
    for (int i = 0; i < pos && temp; i++) temp = temp->next;
    if (!temp) return;
    node->next = temp;
    node->prev = temp->prev;
    if (temp->prev) temp->prev->next = node;
    temp->prev = node;
}

int search(int key) {
    int pos = 0;
    for (struct Node* temp = head; temp; temp = temp->next, pos++)
        if (temp->data == key) return pos;
    return -1;
}

int count() {
    int c = 0;
    for (struct Node* temp = head; temp; temp = temp->next) c++;
    return c;
}

void deleteBegin() {
    if (!head) return;
    struct Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
}

void deleteEnd() {
    if (!head) return;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = NULL;
    else head = NULL;
    free(temp);
}

void deletePos(int pos) {
    if (pos == 0) { deleteBegin(); return; }
    struct Node* temp = head;
    for (int i = 0; i < pos && temp; i++) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
}

int main() {
    int choice, data, pos;
    while (1) {
        printf("1.Display 2.InsertBegin 3.InsertEnd 4.InsertPos 5.Search 6.Count 7.DelBegin 8.DelEnd 9.DelPos 10.Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: display(); break;
            case 2: scanf("%d", &data); insertBegin(data); break;
            case 3: scanf("%d", &data); insertEnd(data); break;
            case 4: scanf("%d%d", &data, &pos); insertPos(data, pos); break;
            case 5: scanf("%d", &data); printf("Found at: %d\n", search(data)); break;
            case 6: printf("Count: %d\n", count()); break;
            case 7: deleteBegin(); break;
            case 8: deleteEnd(); break;
            case 9: scanf("%d", &pos); deletePos(pos); break;
            case 10: exit(0);
        }
    }
}
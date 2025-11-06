#include <stdio.h>

struct Element { int data, priority; };
struct Element pq[100];
int size = 0;

void enqueue(int data, int priority) {
    int i = size - 1;
    while (i >= 0 && pq[i].priority < priority) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1].data = data;
    pq[i + 1].priority = priority;
    size++;
}

struct Element dequeue() {
    return size > 0 ? pq[--size] : (struct Element){-1, -1};
}

void display() {
    for (int i = 0; i < size; i++)
        printf("Data: %d, Priority: %d\n", pq[i].data, pq[i].priority);
}

int main() {
    int choice, data, priority;
    while (1) {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d%d", &data, &priority); enqueue(data, priority); break;
            case 2: { struct Element e = dequeue(); printf("Dequeued: %d\n", e.data); break; }
            case 3: display(); break;
            case 4: return 0;
        }
    }
}
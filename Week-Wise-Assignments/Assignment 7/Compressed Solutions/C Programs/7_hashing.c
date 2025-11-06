#include <stdio.h>
#include <string.h>

#define SIZE 10

struct Entry {
    int key;
    char value[50];
    int occupied;
} table[SIZE];

int hash(int key) { return key % SIZE; }

void insert(int key, char* value) {
    int index = hash(key);
    while (table[index].occupied && table[index].key != key) {
        index = (index + 1) % SIZE;
    }
    table[index].key = key;
    strcpy(table[index].value, value);
    table[index].occupied = 1;
    printf("Inserted at index %d\n", index);
}

int search(int key) {
    int index = hash(key);
    while (table[index].occupied) {
        if (table[index].key == key) return index;
        index = (index + 1) % SIZE;
    }
    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (table[i].occupied) {
            printf("[%d]: %d -> %s\n", i, table[i].key, table[i].value);
        } else {
            printf("[%d]: Empty\n", i);
        }
    }
}

int main() {
    int choice, key;
    char value[50];
    
    while (1) {
        printf("1.Insert 2.Search 3.Display 4.Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d%s", &key, value); insert(key, value); break;
            case 2: scanf("%d", &key); 
                   int idx = search(key);
                   if (idx != -1) printf("Found at %d: %s\n", idx, table[idx].value);
                   else printf("Not found\n");
                   break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}
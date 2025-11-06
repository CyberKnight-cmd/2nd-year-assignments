#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct DoublyLinkedList {
    struct Node* head;
    struct Node* tail;
    int size;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize the doubly linked list
struct DoublyLinkedList* createList() {
    struct DoublyLinkedList* list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    if (!list) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Algorithm for Display:
// 1. Start from head node
// 2. Traverse forward using next pointers
// 3. Print each node's data
// 4. Also provide reverse display option
void display(struct DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("\nForward Display: ");
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf(" <-> NULL\n");
    
    printf("Reverse Display: ");
    temp = list->tail;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->prev != NULL) printf(" <-> ");
        temp = temp->prev;
    }
    printf(" <-> NULL\n");
    printf("List size: %d\n", list->size);
}

// Algorithm for Insert at Beginning:
// 1. Create new node
// 2. If list is empty, set both head and tail to new node
// 3. Otherwise, set new node's next to current head
// 4. Set current head's prev to new node
// 5. Update head to new node
void insertAtBeginning(struct DoublyLinkedList* list, int data) {
    printf("\n=== Insert at Beginning ===\n");
    printf("Inserting %d at the beginning\n", data);
    
    struct Node* newNode = createNode(data);
    
    if (list->head == NULL) {
        printf("List is empty, setting both head and tail to new node\n");
        list->head = list->tail = newNode;
    } else {
        printf("Linking new node to current head\n");
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    
    list->size++;
    printf("Element %d inserted at beginning successfully! (Size: %d)\n", data, list->size);
}

// Algorithm for Insert at End:
// 1. Create new node
// 2. If list is empty, set both head and tail to new node
// 3. Otherwise, set current tail's next to new node
// 4. Set new node's prev to current tail
// 5. Update tail to new node
void insertAtEnd(struct DoublyLinkedList* list, int data) {
    printf("\n=== Insert at End ===\n");
    printf("Inserting %d at the end\n", data);
    
    struct Node* newNode = createNode(data);
    
    if (list->tail == NULL) {
        printf("List is empty, setting both head and tail to new node\n");
        list->head = list->tail = newNode;
    } else {
        printf("Linking new node to current tail\n");
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    
    list->size++;
    printf("Element %d inserted at end successfully! (Size: %d)\n", data, list->size);
}

// Algorithm for Insert at Position:
// 1. Validate position (0 to size)
// 2. If position is 0, insert at beginning
// 3. If position is size, insert at end
// 4. Otherwise, traverse to position and insert
void insertAtPosition(struct DoublyLinkedList* list, int data, int position) {
    printf("\n=== Insert at Position %d ===\n", position);
    
    if (position < 0 || position > list->size) {
        printf("Invalid position! Valid range: 0 to %d\n", list->size);
        return;
    }
    
    if (position == 0) {
        insertAtBeginning(list, data);
        return;
    }
    
    if (position == list->size) {
        insertAtEnd(list, data);
        return;
    }
    
    printf("Inserting %d at position %d\n", data, position);
    struct Node* newNode = createNode(data);
    struct Node* temp = list->head;
    
    // Traverse to position
    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }
    
    printf("Linking new node between existing nodes\n");
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    
    list->size++;
    printf("Element %d inserted at position %d successfully! (Size: %d)\n", data, position, list->size);
}

// Algorithm for Search:
// 1. Start from head
// 2. Traverse the list comparing each node's data
// 3. Return position if found, -1 if not found
int search(struct DoublyLinkedList* list, int key) {
    printf("\n=== Search Element %d ===\n", key);
    
    if (list->head == NULL) {
        printf("List is empty!\n");
        return -1;
    }
    
    struct Node* temp = list->head;
    int position = 0;
    
    printf("Searching process:\n");
    while (temp != NULL) {
        printf("Position %d: %d", position, temp->data);
        if (temp->data == key) {
            printf(" <- FOUND!\n");
            printf("Element %d found at position %d\n", key, position);
            return position;
        }
        printf("\n");
        temp = temp->next;
        position++;
    }
    
    printf("Element %d not found in the list\n", key);
    return -1;
}

// Function to count nodes
int countNodes(struct DoublyLinkedList* list) {
    printf("\n=== Count Nodes ===\n");
    printf("Total nodes in the list: %d\n", list->size);
    return list->size;
}

// Algorithm for Delete at Beginning:
// 1. Check if list is empty
// 2. If only one node, set head and tail to NULL
// 3. Otherwise, update head to next node and set its prev to NULL
// 4. Free the old head node
void deleteAtBeginning(struct DoublyLinkedList* list) {
    printf("\n=== Delete at Beginning ===\n");
    
    if (list->head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    struct Node* nodeToDelete = list->head;
    printf("Deleting element %d from beginning\n", nodeToDelete->data);
    
    if (list->head == list->tail) {
        printf("Only one node in list, setting head and tail to NULL\n");
        list->head = list->tail = NULL;
    } else {
        printf("Updating head to next node\n");
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    
    free(nodeToDelete);
    list->size--;
    printf("Element deleted from beginning successfully! (Size: %d)\n", list->size);
}

// Algorithm for Delete at End:
// 1. Check if list is empty
// 2. If only one node, set head and tail to NULL
// 3. Otherwise, update tail to previous node and set its next to NULL
// 4. Free the old tail node
void deleteAtEnd(struct DoublyLinkedList* list) {
    printf("\n=== Delete at End ===\n");
    
    if (list->tail == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    struct Node* nodeToDelete = list->tail;
    printf("Deleting element %d from end\n", nodeToDelete->data);
    
    if (list->head == list->tail) {
        printf("Only one node in list, setting head and tail to NULL\n");
        list->head = list->tail = NULL;
    } else {
        printf("Updating tail to previous node\n");
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    
    free(nodeToDelete);
    list->size--;
    printf("Element deleted from end successfully! (Size: %d)\n", list->size);
}

// Algorithm for Delete at Position:
// 1. Validate position
// 2. If position is 0, delete at beginning
// 3. If position is last, delete at end
// 4. Otherwise, traverse to position and delete
void deleteAtPosition(struct DoublyLinkedList* list, int position) {
    printf("\n=== Delete at Position %d ===\n", position);
    
    if (position < 0 || position >= list->size) {
        printf("Invalid position! Valid range: 0 to %d\n", list->size - 1);
        return;
    }
    
    if (position == 0) {
        deleteAtBeginning(list);
        return;
    }
    
    if (position == list->size - 1) {
        deleteAtEnd(list);
        return;
    }
    
    struct Node* temp = list->head;
    
    // Traverse to position
    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }
    
    printf("Deleting element %d from position %d\n", temp->data, position);
    printf("Updating links to bypass the node\n");
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    free(temp);
    list->size--;
    printf("Element deleted from position %d successfully! (Size: %d)\n", position, list->size);
}

// Function to free the entire list
void freeList(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    struct DoublyLinkedList* list = createList();
    int choice, data, position;
    
    printf("=== Doubly Linked List Implementation ===\n");
    printf("Features: Bidirectional traversal, efficient insertion/deletion\n\n");
    
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1.  Display list\n");
        printf("2.  Insert at beginning\n");
        printf("3.  Insert at end\n");
        printf("4.  Insert at position\n");
        printf("5.  Search element\n");
        printf("6.  Count nodes\n");
        printf("7.  Delete at beginning\n");
        printf("8.  Delete at end\n");
        printf("9.  Delete at position\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display(list);
                break;
                
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(list, data);
                break;
                
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(list, data);
                break;
                
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (0 to %d): ", list->size);
                scanf("%d", &position);
                insertAtPosition(list, data, position);
                break;
                
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(list, data);
                break;
                
            case 6:
                countNodes(list);
                break;
                
            case 7:
                deleteAtBeginning(list);
                break;
                
            case 8:
                deleteAtEnd(list);
                break;
                
            case 9:
                printf("Enter position to delete (0 to %d): ", list->size - 1);
                scanf("%d", &position);
                deleteAtPosition(list, position);
                break;
                
            case 10:
                printf("Exiting program...\n");
                freeList(list);
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
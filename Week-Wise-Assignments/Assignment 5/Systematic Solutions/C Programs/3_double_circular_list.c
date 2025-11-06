#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct DoublyCircularList {
    struct Node* head;
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

// Function to initialize the doubly circular linked list
struct DoublyCircularList* createList() {
    struct DoublyCircularList* list = (struct DoublyCircularList*)malloc(sizeof(struct DoublyCircularList));
    if (!list) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// Algorithm for Display (Doubly Circular):
// 1. Check if list is empty
// 2. Start from head and traverse using next pointers
// 3. Stop when we reach head again (circular nature)
// 4. Also provide reverse display option
void display(struct DoublyCircularList* list) {
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("\nForward Display (Circular): ");
    struct Node* temp = list->head;
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != list->head) printf(" <-> ");
    } while (temp != list->head);
    printf(" <-> [CIRCULAR]\n");
    
    printf("Reverse Display (Circular): ");
    temp = list->head->prev;  // Start from last node
    do {
        printf("%d", temp->data);
        temp = temp->prev;
        if (temp != list->head->prev) printf(" <-> ");
    } while (temp != list->head->prev);
    printf(" <-> [CIRCULAR]\n");
    printf("List size: %d\n", list->size);
}

// Algorithm for Insert at Beginning (Doubly Circular):
// 1. Create new node
// 2. If list is empty, make node point to itself
// 3. Otherwise, insert between last node and head
// 4. Update head to new node
void insertAtBeginning(struct DoublyCircularList* list, int data) {
    printf("\n=== Insert at Beginning (Doubly Circular) ===\n");
    printf("Inserting %d at the beginning\n", data);
    
    struct Node* newNode = createNode(data);
    
    if (list->head == NULL) {
        printf("List is empty, making node circular (pointing to itself)\n");
        newNode->next = newNode->prev = newNode;
        list->head = newNode;
    } else {
        printf("Inserting between last node and current head\n");
        struct Node* last = list->head->prev;
        
        newNode->next = list->head;
        newNode->prev = last;
        last->next = newNode;
        list->head->prev = newNode;
        list->head = newNode;
    }
    
    list->size++;
    printf("Element %d inserted at beginning successfully! (Size: %d)\n", data, list->size);
}

// Algorithm for Insert at End (Doubly Circular):
// 1. Create new node
// 2. If list is empty, make node point to itself and set as head
// 3. Otherwise, insert between last node and head
void insertAtEnd(struct DoublyCircularList* list, int data) {
    printf("\n=== Insert at End (Doubly Circular) ===\n");
    printf("Inserting %d at the end\n", data);
    
    struct Node* newNode = createNode(data);
    
    if (list->head == NULL) {
        printf("List is empty, making node circular (pointing to itself)\n");
        newNode->next = newNode->prev = newNode;
        list->head = newNode;
    } else {
        printf("Inserting between last node and head\n");
        struct Node* last = list->head->prev;
        
        newNode->next = list->head;
        newNode->prev = last;
        last->next = newNode;
        list->head->prev = newNode;
    }
    
    list->size++;
    printf("Element %d inserted at end successfully! (Size: %d)\n", data, list->size);
}

// Algorithm for Insert at Position (Doubly Circular):
// 1. Validate position
// 2. If position is 0, insert at beginning
// 3. Otherwise, traverse to position and insert
void insertAtPosition(struct DoublyCircularList* list, int data, int position) {
    printf("\n=== Insert at Position %d (Doubly Circular) ===\n", position);
    
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
    
    printf("Linking new node in circular fashion\n");
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    
    list->size++;
    printf("Element %d inserted at position %d successfully! (Size: %d)\n", data, position, list->size);
}

// Algorithm for Search (Doubly Circular):
// 1. Start from head
// 2. Traverse using next pointers
// 3. Stop when we reach head again or find element
int search(struct DoublyCircularList* list, int key) {
    printf("\n=== Search Element %d (Doubly Circular) ===\n", key);
    
    if (list->head == NULL) {
        printf("List is empty!\n");
        return -1;
    }
    
    struct Node* temp = list->head;
    int position = 0;
    
    printf("Searching process:\n");
    do {
        printf("Position %d: %d", position, temp->data);
        if (temp->data == key) {
            printf(" <- FOUND!\n");
            printf("Element %d found at position %d\n", key, position);
            return position;
        }
        printf("\n");
        temp = temp->next;
        position++;
    } while (temp != list->head);
    
    printf("Element %d not found in the list\n", key);
    return -1;
}

// Function to count nodes
int countNodes(struct DoublyCircularList* list) {
    printf("\n=== Count Nodes (Doubly Circular) ===\n");
    printf("Total nodes in the list: %d\n", list->size);
    return list->size;
}

// Algorithm for Delete at Beginning (Doubly Circular):
// 1. Check if list is empty
// 2. If only one node, set head to NULL
// 3. Otherwise, update links to bypass head node
void deleteAtBeginning(struct DoublyCircularList* list) {
    printf("\n=== Delete at Beginning (Doubly Circular) ===\n");
    
    if (list->head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    struct Node* nodeToDelete = list->head;
    printf("Deleting element %d from beginning\n", nodeToDelete->data);
    
    if (list->size == 1) {
        printf("Only one node in list, setting head to NULL\n");
        list->head = NULL;
    } else {
        printf("Updating circular links to bypass head node\n");
        struct Node* last = list->head->prev;
        struct Node* second = list->head->next;
        
        last->next = second;
        second->prev = last;
        list->head = second;
    }
    
    free(nodeToDelete);
    list->size--;
    printf("Element deleted from beginning successfully! (Size: %d)\n", list->size);
}

// Algorithm for Delete at End (Doubly Circular):
// 1. Check if list is empty
// 2. If only one node, set head to NULL
// 3. Otherwise, update links to bypass last node
void deleteAtEnd(struct DoublyCircularList* list) {
    printf("\n=== Delete at End (Doubly Circular) ===\n");
    
    if (list->head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    if (list->size == 1) {
        printf("Only one node in list, deleting it\n");
        free(list->head);
        list->head = NULL;
        list->size--;
        printf("Element deleted from end successfully! (Size: %d)\n", list->size);
        return;
    }
    
    struct Node* last = list->head->prev;
    printf("Deleting element %d from end\n", last->data);
    
    printf("Updating circular links to bypass last node\n");
    struct Node* secondLast = last->prev;
    
    secondLast->next = list->head;
    list->head->prev = secondLast;
    
    free(last);
    list->size--;
    printf("Element deleted from end successfully! (Size: %d)\n", list->size);
}

// Algorithm for Delete at Position (Doubly Circular):
// 1. Validate position
// 2. If position is 0, delete at beginning
// 3. Otherwise, traverse to position and delete
void deleteAtPosition(struct DoublyCircularList* list, int position) {
    printf("\n=== Delete at Position %d (Doubly Circular) ===\n", position);
    
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
    printf("Updating circular links to bypass the node\n");
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    free(temp);
    list->size--;
    printf("Element deleted from position %d successfully! (Size: %d)\n", position, list->size);
}

// Function to free the entire list
void freeList(struct DoublyCircularList* list) {
    if (list->head == NULL) {
        free(list);
        return;
    }
    
    struct Node* current = list->head;
    struct Node* next;
    
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != list->head);
    
    free(list);
}

int main() {
    struct DoublyCircularList* list = createList();
    int choice, data, position;
    
    printf("=== Doubly Circular Linked List Implementation ===\n");
    printf("Features: Bidirectional circular traversal, efficient operations\n\n");
    
    while (1) {
        printf("\n--- Doubly Circular Linked List Menu ---\n");
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
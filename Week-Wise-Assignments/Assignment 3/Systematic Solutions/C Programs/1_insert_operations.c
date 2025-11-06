#include <stdio.h>
#include <stdlib.h>

// Node structure for single linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
ALGORITHMS FOR LINKED LIST OPERATIONS:

createList Algorithm:
1. Initialize head pointer to NULL
2. Return head pointer

insertAtFirst Algorithm:
1. Create new node
2. Set new node's data
3. Set new node's next to current head
4. Update head to point to new node

insertAtLast Algorithm:
1. Create new node
2. Set new node's data and next to NULL
3. If list is empty, make new node as head
4. Else traverse to last node
5. Set last node's next to new node

insertAtAny Algorithm:
1. Create new node
2. If position is 1, call insertAtFirst
3. Else traverse to (position-1)th node
4. Set new node's next to current node's next
5. Set current node's next to new node

displayList Algorithm:
1. Start from head
2. While current node is not NULL
3. Print current node's data
4. Move to next node
*/

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty list
Node* createList() {
    printf("Empty linked list created successfully!\n");
    return NULL;
}

// Function to insert at the beginning
Node* insertAtFirst(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning\n", data);
    return head;
}

// Function to insert at the end
Node* insertAtLast(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    // If list is empty
    if (head == NULL) {
        printf("Inserted %d as the first node\n", data);
        return newNode;
    }
    
    // Traverse to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    printf("Inserted %d at the end\n", data);
    return head;
}

// Function to insert at any position
Node* insertAtAny(Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position! Position should be >= 1\n");
        return head;
    }
    
    // If inserting at first position
    if (position == 1) {
        return insertAtFirst(head, data);
    }
    
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    // Traverse to (position-1)th node
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    // If position is beyond the list
    if (temp == NULL) {
        printf("Position %d is beyond the list. Inserting at the end.\n", position);
        free(newNode);
        return insertAtLast(head, data);
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", data, position);
    return head;
}

// Function to display the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Function to count nodes in the list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to free the entire list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Memory freed successfully!\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;
    
    printf("=== Single Linked List - Insert Operations ===\n");
    
    // Create empty list
    head = createList();
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Any Position\n");
        printf("4. Display List\n");
        printf("5. Count Nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                head = insertAtFirst(head, data);
                break;
                
            case 2:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                head = insertAtLast(head, data);
                break;
                
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (1-based): ");
                scanf("%d", &position);
                head = insertAtAny(head, data, position);
                break;
                
            case 4:
                displayList(head);
                break;
                
            case 5:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
                
            case 6:
                printf("Exiting...\n");
                freeList(head);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
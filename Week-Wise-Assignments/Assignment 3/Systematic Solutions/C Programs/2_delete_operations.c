#include <stdio.h>
#include <stdlib.h>

// Node structure for single linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
ALGORITHMS FOR DELETE OPERATIONS:

deleteFromFirst Algorithm:
1. Check if list is empty
2. If empty, return NULL
3. Store head in temp
4. Update head to head->next
5. Free temp node
6. Return new head

deleteFromLast Algorithm:
1. Check if list is empty
2. If only one node, delete it and return NULL
3. Traverse to second last node
4. Store last node in temp
5. Set second last node's next to NULL
6. Free temp node

deleteFromAny Algorithm:
1. Check if position is valid
2. If position is 1, call deleteFromFirst
3. Traverse to (position-1)th node
4. Store position node in temp
5. Set (position-1)th node's next to temp->next
6. Free temp node
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

// Function to insert at the end (for testing purposes)
Node* insertAtLast(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (head == NULL) {
        return newNode;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    return head;
}

// Function to delete from the beginning
Node* deleteFromFirst(Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete from first.\n");
        return NULL;
    }
    
    Node* temp = head;
    head = head->next;
    printf("Deleted %d from the beginning\n", temp->data);
    free(temp);
    return head;
}

// Function to delete from the end
Node* deleteFromLast(Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete from last.\n");
        return NULL;
    }
    
    // If only one node
    if (head->next == NULL) {
        printf("Deleted %d from the end\n", head->data);
        free(head);
        return NULL;
    }
    
    // Traverse to second last node
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    Node* lastNode = temp->next;
    printf("Deleted %d from the end\n", lastNode->data);
    temp->next = NULL;
    free(lastNode);
    return head;
}

// Function to delete from any position
Node* deleteFromAny(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty! Cannot delete from position %d.\n", position);
        return NULL;
    }
    
    if (position < 1) {
        printf("Invalid position! Position should be >= 1\n");
        return head;
    }
    
    // If deleting first node
    if (position == 1) {
        return deleteFromFirst(head);
    }
    
    // Traverse to (position-1)th node
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    // If position is beyond the list
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is beyond the list!\n", position);
        return head;
    }
    
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted %d from position %d\n", nodeToDelete->data, position);
    free(nodeToDelete);
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

// Function to populate list with sample data
Node* populateList(Node* head) {
    printf("Populating list with sample data: 10, 20, 30, 40, 50\n");
    head = insertAtLast(head, 10);
    head = insertAtLast(head, 20);
    head = insertAtLast(head, 30);
    head = insertAtLast(head, 40);
    head = insertAtLast(head, 50);
    return head;
}

int main() {
    Node* head = NULL;
    int choice, position;
    
    printf("=== Single Linked List - Delete Operations ===\n");
    
    // Create empty list
    head = createList();
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Delete from First\n");
        printf("2. Delete from Last\n");
        printf("3. Delete from Any Position\n");
        printf("4. Display List\n");
        printf("5. Count Nodes\n");
        printf("6. Populate with Sample Data\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                head = deleteFromFirst(head);
                break;
                
            case 2:
                head = deleteFromLast(head);
                break;
                
            case 3:
                printf("Enter position to delete (1-based): ");
                scanf("%d", &position);
                head = deleteFromAny(head, position);
                break;
                
            case 4:
                displayList(head);
                break;
                
            case 5:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
                
            case 6:
                head = populateList(head);
                displayList(head);
                break;
                
            case 7:
                printf("Exiting...\n");
                freeList(head);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}
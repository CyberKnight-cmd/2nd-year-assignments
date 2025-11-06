#include <stdio.h>
#include <stdlib.h>

// Node structure for single linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

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

// INSERT FUNCTIONS

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
    
    if (head == NULL) {
        printf("Inserted %d as the first node\n", data);
        return newNode;
    }
    
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
    
    if (position == 1) {
        return insertAtFirst(head, data);
    }
    
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
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

// DELETE FUNCTIONS

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
    
    if (head->next == NULL) {
        printf("Deleted %d from the end\n", head->data);
        free(head);
        return NULL;
    }
    
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
    
    if (position == 1) {
        return deleteFromFirst(head);
    }
    
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
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

// UTILITY FUNCTIONS

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

// Function to search for a value
int searchValue(Node* head, int value) {
    Node* temp = head;
    int position = 1;
    
    while (temp != NULL) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; // Not found
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

// Function to display menu
void displayMenu() {
    printf("\n=== Single Linked List Operations ===\n");
    printf("1.  Insert at First\n");
    printf("2.  Insert at Last\n");
    printf("3.  Insert at Any Position\n");
    printf("4.  Delete from First\n");
    printf("5.  Delete from Last\n");
    printf("6.  Delete from Any Position\n");
    printf("7.  Display List\n");
    printf("8.  Count Nodes\n");
    printf("9.  Search Value\n");
    printf("10. Clear List\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Node* head = NULL;
    int choice, data, position, searchVal, result;
    
    printf("=== Complete Single Linked List Implementation ===\n");
    
    // Create empty list
    head = createList();
    
    do {
        displayMenu();
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
                head = deleteFromFirst(head);
                break;
                
            case 5:
                head = deleteFromLast(head);
                break;
                
            case 6:
                printf("Enter position to delete (1-based): ");
                scanf("%d", &position);
                head = deleteFromAny(head, position);
                break;
                
            case 7:
                displayList(head);
                break;
                
            case 8:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
                
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &searchVal);
                result = searchValue(head, searchVal);
                if (result != -1) {
                    printf("Value %d found at position %d\n", searchVal, result);
                } else {
                    printf("Value %d not found in the list\n", searchVal);
                }
                break;
                
            case 10:
                freeList(head);
                head = NULL;
                printf("List cleared successfully!\n");
                break;
                
            case 11:
                printf("Exiting...\n");
                freeList(head);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 11);
    
    return 0;
}
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

// Function to insert at the end
Node* insertAtEnd(Node* head, int data) {
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

// Function to count nodes - Iterative approach
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    
    printf("Counting nodes iteratively:\n");
    while (temp != NULL) {
        count++;
        printf("Node %d: %d\n", count, temp->data);
        temp = temp->next;
    }
    
    return count;
}

// Function to count nodes - Recursive approach
int countNodesRecursive(Node* head) {
    // Base case
    if (head == NULL) {
        return 0;
    }
    
    // Recursive case
    return 1 + countNodesRecursive(head->next);
}

// Function to count nodes with specific value
int countNodesWithValue(Node* head, int value) {
    int count = 0;
    Node* temp = head;
    
    printf("Counting nodes with value %d:\n", value);
    while (temp != NULL) {
        if (temp->data == value) {
            count++;
            printf("Found at position %d\n", count);
        }
        temp = temp->next;
    }
    
    return count;
}

// Function to count even and odd nodes
void countEvenOddNodes(Node* head, int* evenCount, int* oddCount) {
    *evenCount = 0;
    *oddCount = 0;
    Node* temp = head;
    
    printf("Analyzing even and odd values:\n");
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            (*evenCount)++;
            printf("%d is even\n", temp->data);
        } else {
            (*oddCount)++;
            printf("%d is odd\n", temp->data);
        }
        temp = temp->next;
    }
}

// Function to count nodes in range
int countNodesInRange(Node* head, int min, int max) {
    int count = 0;
    Node* temp = head;
    
    printf("Counting nodes with values between %d and %d:\n", min, max);
    while (temp != NULL) {
        if (temp->data >= min && temp->data <= max) {
            count++;
            printf("Node with value %d is in range\n", temp->data);
        }
        temp = temp->next;
    }
    
    return count;
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

// Function to create sample list
Node* createSampleList() {
    Node* head = NULL;
    int values[] = {10, 25, 30, 15, 40, 25, 50, 15};
    int size = sizeof(values) / sizeof(values[0]);
    
    printf("Creating sample list with values: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", values[i]);
        head = insertAtEnd(head, values[i]);
    }
    printf("\n");
    
    return head;
}

int main() {
    Node* head = NULL;
    int choice, data, value, min, max, result;
    int evenCount, oddCount;
    
    printf("=== Node Counting Functions for Linked List ===\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Count Total Nodes (Iterative)\n");
        printf("4. Count Total Nodes (Recursive)\n");
        printf("5. Count Nodes with Specific Value\n");
        printf("6. Count Even and Odd Nodes\n");
        printf("7. Count Nodes in Range\n");
        printf("8. Create Sample List\n");
        printf("9. Clear List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Inserted %d into the list\n", data);
                break;
                
            case 2:
                displayList(head);
                break;
                
            case 3:
                result = countNodes(head);
                printf("Total number of nodes (iterative): %d\n", result);
                break;
                
            case 4:
                result = countNodesRecursive(head);
                printf("Total number of nodes (recursive): %d\n", result);
                break;
                
            case 5:
                printf("Enter value to count: ");
                scanf("%d", &value);
                result = countNodesWithValue(head, value);
                printf("Number of nodes with value %d: %d\n", value, result);
                break;
                
            case 6:
                countEvenOddNodes(head, &evenCount, &oddCount);
                printf("Even nodes: %d, Odd nodes: %d\n", evenCount, oddCount);
                break;
                
            case 7:
                printf("Enter minimum value: ");
                scanf("%d", &min);
                printf("Enter maximum value: ");
                scanf("%d", &max);
                result = countNodesInRange(head, min, max);
                printf("Number of nodes in range [%d, %d]: %d\n", min, max, result);
                break;
                
            case 8:
                if (head != NULL) {
                    freeList(head);
                }
                head = createSampleList();
                displayList(head);
                break;
                
            case 9:
                freeList(head);
                head = NULL;
                printf("List cleared successfully!\n");
                break;
                
            case 10:
                printf("Exiting...\n");
                if (head != NULL) {
                    freeList(head);
                }
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 10);
    
    return 0;
}
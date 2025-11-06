#include <stdio.h>
#include <stdlib.h>

// Node structure for single linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
ALGORITHM FOR REVERSING A LINKED LIST:

Iterative Approach:
1. Initialize three pointers: prev = NULL, current = head, next = NULL
2. While current is not NULL:
   a. Store next node: next = current->next
   b. Reverse the link: current->next = prev
   c. Move pointers one step ahead: prev = current, current = next
3. Update head to prev (new first node)

Recursive Approach:
1. Base case: if head is NULL or head->next is NULL, return head
2. Recursively reverse the rest of the list
3. Reverse the current link: head->next->next = head
4. Set head->next = NULL
5. Return the new head
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

// Function to display the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("List: ");
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

// Function to reverse linked list - Iterative approach
Node* reverseListIterative(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("List is empty or has only one node. No reversal needed.\n");
        return head;
    }
    
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    printf("Reversing list iteratively:\n");
    int step = 1;
    
    while (current != NULL) {
        // Store next node
        next = current->next;
        
        // Reverse the link
        current->next = prev;
        
        printf("Step %d: Reversed link for node %d\n", step++, current->data);
        
        // Move pointers one step ahead
        prev = current;
        current = next;
    }
    
    printf("List reversed successfully!\n");
    return prev; // prev is now the new head
}

// Function to reverse linked list - Recursive approach
Node* reverseListRecursive(Node* head) {
    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursively reverse the rest of the list
    Node* newHead = reverseListRecursive(head->next);
    
    // Reverse the current link
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

// Function to count nodes
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to free the list
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
    int values[] = {1, 2, 3, 4, 5};
    int size = sizeof(values) / sizeof(values[0]);
    
    printf("Creating sample list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", values[i]);
        head = insertAtEnd(head, values[i]);
    }
    printf("\n");
    
    return head;
}

int main() {
    Node* head = NULL;
    int choice, data;
    
    printf("=== Linked List Reversal Program ===\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Reverse List (Iterative)\n");
        printf("4. Reverse List (Recursive)\n");
        printf("5. Count Nodes\n");
        printf("6. Create Sample List\n");
        printf("7. Clear List\n");
        printf("8. Exit\n");
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
                printf("Original list:\n");
                displayList(head);
                head = reverseListIterative(head);
                printf("Reversed list:\n");
                displayList(head);
                break;
                
            case 4:
                printf("Original list:\n");
                displayList(head);
                head = reverseListRecursive(head);
                printf("List reversed recursively!\n");
                printf("Reversed list:\n");
                displayList(head);
                break;
                
            case 5:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
                
            case 6:
                if (head != NULL) {
                    freeList(head);
                }
                head = createSampleList();
                displayList(head);
                break;
                
            case 7:
                freeList(head);
                head = NULL;
                printf("List cleared!\n");
                break;
                
            case 8:
                printf("Exiting...\n");
                if (head != NULL) {
                    freeList(head);
                }
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);
    
    return 0;
}
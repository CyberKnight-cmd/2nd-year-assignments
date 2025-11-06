#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
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
    return newNode;
}

// Function to insert at end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Algorithm: Floyd's Cycle Detection (Tortoise and Hare)
// 1. Use two pointers: slow (moves 1 step) and fast (moves 2 steps)
// 2. If there's a loop, fast will eventually meet slow
// 3. If fast reaches NULL, there's no loop
int detectLoop(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return 0; // No loop possible
    }
    
    struct Node* slow = head;
    struct Node* fast = head;
    
    printf("\nLoop Detection Process:\n");
    printf("Using Floyd's Cycle Detection Algorithm (Tortoise and Hare)\n");
    printf("Slow pointer moves 1 step, Fast pointer moves 2 steps\n\n");
    
    int step = 1;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        printf("Step %d: Slow at %d, Fast at %d\n", step++, slow->data, fast->data);
        
        if (slow == fast) {
            printf("Loop detected! Pointers met at node with data: %d\n", slow->data);
            return 1; // Loop found
        }
    }
    
    printf("No loop detected - Fast pointer reached end\n");
    return 0; // No loop
}

// Function to create a loop for testing (connects last node to a specific position)
void createLoop(struct Node* head, int position) {
    if (head == NULL) return;
    
    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int count = 0;
    
    // Find the node at given position
    while (temp != NULL) {
        if (count == position) {
            loopNode = temp;
        }
        if (temp->next == NULL) {
            temp->next = loopNode; // Create loop
            break;
        }
        temp = temp->next;
        count++;
    }
}

// Function to display list (with loop protection)
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("List: ");
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL && count < 20) { // Limit to prevent infinite loop
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    if (count == 20) {
        printf("... (stopped to prevent infinite display)");
    }
    printf("\n");
}

// Function to free memory (only works for non-looped lists)
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    printf("=== Single Linked List Loop Detection ===\n");
    printf("Algorithm: Floyd's Cycle Detection (Tortoise and Hare)\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert element\n");
        printf("2. Display list\n");
        printf("3. Detect loop\n");
        printf("4. Create loop (for testing)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Element %d inserted successfully!\n", data);
                break;
                
            case 2:
                displayList(head);
                break;
                
            case 3:
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    printf("\n=== Loop Detection Analysis ===\n");
                    if (detectLoop(head)) {
                        printf("\nResult: LOOP DETECTED in the linked list!\n");
                    } else {
                        printf("\nResult: NO LOOP found in the linked list.\n");
                    }
                }
                break;
                
            case 4:
                if (head == NULL) {
                    printf("List is empty! Add some elements first.\n");
                } else {
                    printf("Enter position to create loop (0-based indexing): ");
                    scanf("%d", &position);
                    createLoop(head, position);
                    printf("Loop created! Last node now points to node at position %d\n", position);
                    printf("Warning: Display function will be limited to prevent infinite output\n");
                }
                break;
                
            case 5:
                printf("Exiting program...\n");
                if (!detectLoop(head)) {
                    freeList(head);
                }
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
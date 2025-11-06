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

// Function to print odd and even nodes separately
void printOddEvenNodes(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("\n=== Separating Odd and Even Numbers ===\n");
    
    // Print odd numbers
    printf("Odd numbers: ");
    Node* temp = head;
    int oddFound = 0;
    
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            if (oddFound) printf(" -> ");
            printf("%d", temp->data);
            oddFound = 1;
        }
        temp = temp->next;
    }
    
    if (!oddFound) {
        printf("None");
    } else {
        printf(" -> NULL");
    }
    printf("\n");
    
    // Print even numbers
    printf("Even numbers: ");
    temp = head;
    int evenFound = 0;
    
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            if (evenFound) printf(" -> ");
            printf("%d", temp->data);
            evenFound = 1;
        }
        temp = temp->next;
    }
    
    if (!evenFound) {
        printf("None");
    } else {
        printf(" -> NULL");
    }
    printf("\n");
}

// Function to create separate linked lists for odd and even numbers
void createOddEvenLists(Node* head, Node** oddHead, Node** evenHead) {
    *oddHead = NULL;
    *evenHead = NULL;
    
    if (head == NULL) {
        printf("Original list is empty!\n");
        return;
    }
    
    Node* temp = head;
    
    printf("\nCreating separate lists for odd and even numbers:\n");
    
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            // Odd number
            *oddHead = insertAtEnd(*oddHead, temp->data);
            printf("Added %d to odd list\n", temp->data);
        } else {
            // Even number
            *evenHead = insertAtEnd(*evenHead, temp->data);
            printf("Added %d to even list\n", temp->data);
        }
        temp = temp->next;
    }
}

// Function to count odd and even nodes
void countOddEvenNodes(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    int oddCount = 0, evenCount = 0;
    Node* temp = head;
    
    printf("\nCounting odd and even numbers:\n");
    
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            oddCount++;
            printf("%d is odd (count: %d)\n", temp->data, oddCount);
        } else {
            evenCount++;
            printf("%d is even (count: %d)\n", temp->data, evenCount);
        }
        temp = temp->next;
    }
    
    printf("\nSummary:\n");
    printf("Total odd numbers: %d\n", oddCount);
    printf("Total even numbers: %d\n", evenCount);
    printf("Total numbers: %d\n", oddCount + evenCount);
}

// Function to print nodes at odd and even positions
void printOddEvenPositions(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("\n=== Nodes at Odd and Even Positions ===\n");
    
    // Print nodes at odd positions (1st, 3rd, 5th, ...)
    printf("Nodes at odd positions: ");
    Node* temp = head;
    int position = 1;
    int oddPosFound = 0;
    
    while (temp != NULL) {
        if (position % 2 != 0) {
            if (oddPosFound) printf(" -> ");
            printf("%d", temp->data);
            oddPosFound = 1;
        }
        temp = temp->next;
        position++;
    }
    
    if (!oddPosFound) {
        printf("None");
    } else {
        printf(" -> NULL");
    }
    printf("\n");
    
    // Print nodes at even positions (2nd, 4th, 6th, ...)
    printf("Nodes at even positions: ");
    temp = head;
    position = 1;
    int evenPosFound = 0;
    
    while (temp != NULL) {
        if (position % 2 == 0) {
            if (evenPosFound) printf(" -> ");
            printf("%d", temp->data);
            evenPosFound = 1;
        }
        temp = temp->next;
        position++;
    }
    
    if (!evenPosFound) {
        printf("None");
    } else {
        printf(" -> NULL");
    }
    printf("\n");
}

// Function to free the entire list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to create sample list
Node* createSampleList() {
    Node* head = NULL;
    int values[] = {12, 7, 18, 3, 24, 9, 15, 6, 11, 20};
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
    Node* oddHead = NULL;
    Node* evenHead = NULL;
    int choice, data;
    
    printf("=== Odd and Even Number Separation in Linked List ===\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Print Odd and Even Numbers Separately\n");
        printf("4. Count Odd and Even Numbers\n");
        printf("5. Create Separate Odd and Even Lists\n");
        printf("6. Print Nodes at Odd and Even Positions\n");
        printf("7. Create Sample List\n");
        printf("8. Clear All Lists\n");
        printf("9. Exit\n");
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
                printf("\nOriginal List:\n");
                displayList(head);
                break;
                
            case 3:
                printOddEvenNodes(head);
                break;
                
            case 4:
                countOddEvenNodes(head);
                break;
                
            case 5:
                // Free previous odd and even lists
                if (oddHead != NULL) {
                    freeList(oddHead);
                    oddHead = NULL;
                }
                if (evenHead != NULL) {
                    freeList(evenHead);
                    evenHead = NULL;
                }
                
                createOddEvenLists(head, &oddHead, &evenHead);
                
                printf("\nSeparate Lists Created:\n");
                printf("Odd List: ");
                displayList(oddHead);
                printf("Even List: ");
                displayList(evenHead);
                break;
                
            case 6:
                printOddEvenPositions(head);
                break;
                
            case 7:
                if (head != NULL) {
                    freeList(head);
                }
                head = createSampleList();
                displayList(head);
                break;
                
            case 8:
                if (head != NULL) {
                    freeList(head);
                    head = NULL;
                }
                if (oddHead != NULL) {
                    freeList(oddHead);
                    oddHead = NULL;
                }
                if (evenHead != NULL) {
                    freeList(evenHead);
                    evenHead = NULL;
                }
                printf("All lists cleared successfully!\n");
                break;
                
            case 9:
                printf("Exiting...\n");
                if (head != NULL) freeList(head);
                if (oddHead != NULL) freeList(oddHead);
                if (evenHead != NULL) freeList(evenHead);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 9);
    
    return 0;
}
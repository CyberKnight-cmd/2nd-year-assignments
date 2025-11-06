#include <stdio.h>
#include <stdlib.h>

// Node structure for single linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
ALGORITHM FOR LEFT-SHIFTING A LINKED LIST BY K NODES:

1. Check if list is empty or k is 0
2. Find the length of the linked list
3. Normalize k: k = k % length (handle cases where k > length)
4. If k is 0 after normalization, no shift needed
5. Find the (k+1)th node from the beginning - this will be the new head
6. Find the kth node from the beginning - this will be the new tail
7. Make the new tail point to NULL
8. Find the original tail and make it point to the original head
9. Return the new head

Example: 1->2->3->4->5, k=2
Step 1: Find length = 5
Step 2: k = 2 % 5 = 2
Step 3: New head = 3rd node (3)
Step 4: New tail = 2nd node (2)
Step 5: Break link: 1->2->NULL
Step 6: Connect: 5->1
Result: 3->4->5->1->2->NULL
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

// Function to left-shift linked list by k nodes
Node* leftShiftList(Node* head, int k) {
    // Check if list is empty or k is 0
    if (head == NULL || k == 0) {
        printf("No shift needed (empty list or k=0)\n");
        return head;
    }
    
    // Find the length of the list
    int length = countNodes(head);
    printf("List length: %d\n", length);
    
    // Normalize k to handle cases where k > length
    k = k % length;
    printf("Normalized k: %d\n", k);
    
    // If k is 0 after normalization, no shift needed
    if (k == 0) {
        printf("No shift needed (k is multiple of length)\n");
        return head;
    }
    
    printf("Left-shifting list by %d positions:\n", k);
    
    // Find the kth node (new tail) and (k+1)th node (new head)
    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }
    
    Node* newHead = newTail->next;
    printf("New head will be: %d\n", newHead->data);
    printf("New tail will be: %d\n", newTail->data);
    
    // Break the connection
    newTail->next = NULL;
    
    // Find the original tail
    Node* originalTail = newHead;
    while (originalTail->next != NULL) {
        originalTail = originalTail->next;
    }
    
    // Connect original tail to original head
    originalTail->next = head;
    printf("Connected original tail (%d) to original head (%d)\n", 
           originalTail->data, head->data);
    
    printf("Left shift completed!\n");
    return newHead;
}

// Function to left-shift using array approach (alternative method)
Node* leftShiftListArray(Node* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }
    
    // Convert list to array
    int length = countNodes(head);
    int* arr = (int*)malloc(length * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    
    Node* temp = head;
    for (int i = 0; i < length; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    
    // Normalize k
    k = k % length;
    
    // Create new list with shifted elements
    Node* newHead = NULL;
    for (int i = 0; i < length; i++) {
        int index = (i + k) % length;
        newHead = insertAtEnd(newHead, arr[index]);
    }
    
    free(arr);
    return newHead;
}

// Function to free the list
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
    int values[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(values) / sizeof(values[0]);
    
    printf("Creating sample list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", values[i]);
        head = insertAtEnd(head, values[i]);
    }
    printf("\n");
    
    return head;
}

// Function to demonstrate left shift with different k values
void demonstrateLeftShift(Node* originalHead) {
    int length = countNodes(originalHead);
    printf("\nDemonstrating left shift with different k values:\n");
    printf("Original list: ");
    displayList(originalHead);
    
    for (int k = 1; k <= length + 2; k++) {
        // Create a copy of the original list for each demonstration
        Node* copyHead = NULL;
        Node* temp = originalHead;
        while (temp != NULL) {
            copyHead = insertAtEnd(copyHead, temp->data);
            temp = temp->next;
        }
        
        printf("\nLeft shift by k=%d:\n", k);
        Node* shiftedHead = leftShiftList(copyHead, k);
        printf("Result: ");
        displayList(shiftedHead);
        
        freeList(shiftedHead);
    }
}

int main() {
    Node* head = NULL;
    int choice, data, k;
    
    printf("=== Left Shift Linked List Program ===\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Left Shift by K positions\n");
        printf("4. Left Shift using Array Method\n");
        printf("5. Count Nodes\n");
        printf("6. Create Sample List\n");
        printf("7. Demonstrate All Shifts\n");
        printf("8. Clear List\n");
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
                displayList(head);
                break;
                
            case 3:
                if (head == NULL) {
                    printf("List is empty! Please create a list first.\n");
                    break;
                }
                
                printf("Enter k (number of positions to left shift): ");
                scanf("%d", &k);
                
                if (k < 0) {
                    printf("k should be non-negative!\n");
                    break;
                }
                
                printf("Original list:\n");
                displayList(head);
                
                head = leftShiftList(head, k);
                
                printf("After left shift by %d positions:\n", k);
                displayList(head);
                break;
                
            case 4:
                if (head == NULL) {
                    printf("List is empty! Please create a list first.\n");
                    break;
                }
                
                printf("Enter k (number of positions to left shift): ");
                scanf("%d", &k);
                
                if (k < 0) {
                    printf("k should be non-negative!\n");
                    break;
                }
                
                printf("Original list:\n");
                displayList(head);
                
                // Free original list and use array method result
                Node* originalHead = head;
                head = leftShiftListArray(head, k);
                freeList(originalHead);
                
                printf("After left shift by %d positions (array method):\n", k);
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
                if (head == NULL) {
                    printf("List is empty! Creating sample list first.\n");
                    head = createSampleList();
                }
                demonstrateLeftShift(head);
                break;
                
            case 8:
                if (head != NULL) {
                    freeList(head);
                    head = NULL;
                }
                printf("List cleared!\n");
                break;
                
            case 9:
                printf("Exiting...\n");
                if (head != NULL) {
                    freeList(head);
                }
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 9);
    
    return 0;
}
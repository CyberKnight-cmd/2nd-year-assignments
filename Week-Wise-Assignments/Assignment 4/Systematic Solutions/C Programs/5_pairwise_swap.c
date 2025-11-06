#include <stdio.h>
#include <stdlib.h>

// Node structure for single linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
ALGORITHM FOR PAIRWISE SWAPPING IN LINKED LIST:

Method 1 - Swap Data:
1. Traverse the list with two pointers
2. For each pair of adjacent nodes, swap their data values
3. Move to the next pair

Method 2 - Swap Nodes (Change Links):
1. Use dummy node to simplify edge cases
2. Keep track of previous node
3. For each pair:
   a. Store the two nodes to be swapped
   b. Update previous node's next to second node
   c. Update second node's next to first node
   d. Update first node's next to next pair
4. Move to next pair

Example: 1->2->3->4->5->6
Result:  2->1->4->3->6->5

Time Complexity: O(n)
Space Complexity: O(1)
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

// Method 1: Pairwise swap by swapping data values
void pairwiseSwapData(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node* temp = head;
    printf("Swapping data values pairwise:\n");
    
    while (temp != NULL && temp->next != NULL) {
        // Swap data of current node and next node
        printf("Swapping %d and %d\n", temp->data, temp->next->data);
        
        int tempData = temp->data;
        temp->data = temp->next->data;
        temp->next->data = tempData;
        
        // Move to next pair
        temp = temp->next->next;
    }
    
    printf("Pairwise swap (data) completed!\n");
}

// Method 2: Pairwise swap by changing node links
Node* pairwiseSwapNodes(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("List has less than 2 nodes. No swap needed.\n");
        return head;
    }
    
    // Create dummy node to simplify edge cases
    Node* dummy = createNode(0);
    dummy->next = head;
    Node* prev = dummy;
    
    printf("Swapping nodes pairwise:\n");
    
    while (prev->next != NULL && prev->next->next != NULL) {
        // Identify the two nodes to be swapped
        Node* first = prev->next;
        Node* second = prev->next->next;
        
        printf("Swapping nodes %d and %d\n", first->data, second->data);
        
        // Perform the swap
        prev->next = second;
        first->next = second->next;
        second->next = first;
        
        // Move prev to the end of the swapped pair
        prev = first;
    }
    
    // Store new head
    Node* newHead = dummy->next;
    
    // Free dummy node
    free(dummy);
    
    printf("Pairwise swap (nodes) completed!\n");
    return newHead;
}

// Recursive approach for pairwise swapping
Node* pairwiseSwapRecursive(Node* head) {
    // Base case: if less than 2 nodes
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Store the second node
    Node* second = head->next;
    
    // Recursively swap the rest of the list
    head->next = pairwiseSwapRecursive(second->next);
    
    // Swap the first two nodes
    second->next = head;
    
    // Return new head (which is the second node)
    return second;
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

// Function to create a copy of the list
Node* copyList(Node* head) {
    Node* newHead = NULL;
    Node* temp = head;
    
    while (temp != NULL) {
        newHead = insertAtEnd(newHead, temp->data);
        temp = temp->next;
    }
    
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

// Function to demonstrate all swap methods
void demonstrateAllMethods(Node* originalHead) {
    printf("\n=== Demonstrating All Pairwise Swap Methods ===\n");
    printf("Original list: ");
    displayList(originalHead);
    
    // Method 1: Swap data
    printf("\n1. Swapping data values:\n");
    Node* copy1 = copyList(originalHead);
    pairwiseSwapData(copy1);
    printf("Result: ");
    displayList(copy1);
    freeList(copy1);
    
    // Method 2: Swap nodes
    printf("\n2. Swapping nodes (iterative):\n");
    Node* copy2 = copyList(originalHead);
    copy2 = pairwiseSwapNodes(copy2);
    printf("Result: ");
    displayList(copy2);
    freeList(copy2);
    
    // Method 3: Recursive swap
    printf("\n3. Swapping nodes (recursive):\n");
    Node* copy3 = copyList(originalHead);
    copy3 = pairwiseSwapRecursive(copy3);
    printf("Result: ");
    displayList(copy3);
    freeList(copy3);
}

int main() {
    Node* head = NULL;
    int choice, data;
    
    printf("=== Pairwise Swap in Linked List Program ===\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Pairwise Swap (Data Values)\n");
        printf("4. Pairwise Swap (Node Links)\n");
        printf("5. Pairwise Swap (Recursive)\n");
        printf("6. Count Nodes\n");
        printf("7. Create Sample List\n");
        printf("8. Demonstrate All Methods\n");
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
                if (head == NULL) {
                    printf("List is empty! Please create a list first.\n");
                    break;
                }
                
                printf("Before pairwise swap (data):\n");
                displayList(head);
                
                pairwiseSwapData(head);
                
                printf("After pairwise swap (data):\n");
                displayList(head);
                break;
                
            case 4:
                if (head == NULL) {
                    printf("List is empty! Please create a list first.\n");
                    break;
                }
                
                printf("Before pairwise swap (nodes):\n");
                displayList(head);
                
                head = pairwiseSwapNodes(head);
                
                printf("After pairwise swap (nodes):\n");
                displayList(head);
                break;
                
            case 5:
                if (head == NULL) {
                    printf("List is empty! Please create a list first.\n");
                    break;
                }
                
                printf("Before pairwise swap (recursive):\n");
                displayList(head);
                
                head = pairwiseSwapRecursive(head);
                
                printf("After pairwise swap (recursive):\n");
                displayList(head);
                break;
                
            case 6:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
                
            case 7:
                if (head != NULL) {
                    freeList(head);
                }
                head = createSampleList();
                displayList(head);
                break;
                
            case 8:
                if (head == NULL) {
                    printf("List is empty! Creating sample list first.\n");
                    head = createSampleList();
                }
                demonstrateAllMethods(head);
                break;
                
            case 9:
                if (head != NULL) {
                    freeList(head);
                    head = NULL;
                }
                printf("List cleared!\n");
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
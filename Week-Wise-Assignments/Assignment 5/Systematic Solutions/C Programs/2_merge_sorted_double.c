#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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

// Function to insert at end (for creating sorted lists)
void insertAtEnd(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Function to display doubly linked list
void display(struct Node* head, const char* listName) {
    if (head == NULL) {
        printf("%s: Empty list\n", listName);
        return;
    }
    
    printf("%s: ", listName);
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

// Algorithm for Merging Two Sorted Doubly Linked Lists:
// 1. Create a dummy node to simplify edge cases
// 2. Use two pointers to traverse both lists
// 3. Compare nodes and add smaller one to result
// 4. Properly maintain both next and prev pointers
// 5. Handle remaining nodes from non-exhausted list
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    printf("\n=== Merge Two Sorted Doubly Linked Lists ===\n");
    printf("Algorithm: Compare nodes and maintain bidirectional links\n\n");
    
    if (list1 == NULL) {
        printf("List 1 is empty, returning List 2\n");
        return list2;
    }
    if (list2 == NULL) {
        printf("List 2 is empty, returning List 1\n");
        return list1;
    }
    
    struct Node* dummy = createNode(0);
    struct Node* tail = dummy;
    struct Node* p1 = list1;
    struct Node* p2 = list2;
    int step = 1;
    
    printf("Step-by-step merging process:\n");
    
    while (p1 != NULL && p2 != NULL) {
        printf("Step %d: Comparing %d and %d\n", step, p1->data, p2->data);
        
        if (p1->data <= p2->data) {
            printf("         %d is smaller/equal, adding to result\n", p1->data);
            tail->next = p1;
            p1->prev = tail;
            p1 = p1->next;
        } else {
            printf("         %d is smaller, adding to result\n", p2->data);
            tail->next = p2;
            p2->prev = tail;
            p2 = p2->next;
        }
        
        tail = tail->next;
        step++;
        printf();
    }
    
    // Add remaining nodes
    if (p1 != NULL) {
        printf("Adding remaining nodes from List 1\n");
        tail->next = p1;
        p1->prev = tail;
    } else if (p2 != NULL) {
        printf("Adding remaining nodes from List 2\n");
        tail->next = p2;
        p2->prev = tail;
    }
    
    struct Node* result = dummy->next;
    if (result != NULL) {
        result->prev = NULL;  // Remove connection to dummy node
    }
    free(dummy);
    
    printf("Merge completed successfully!\n");
    return result;
}

// Function to input a sorted list
void inputSortedList(struct Node** head, struct Node** tail, int listNum) {
    int n, data;
    
    printf("\nEnter number of elements for List %d: ", listNum);
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("List %d will be empty.\n", listNum);
        return;
    }
    
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(head, tail, data);
    }
    
    printf("List %d created successfully!\n", listNum);
}

// Function to free the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to copy a list (to preserve original lists)
struct Node* copyList(struct Node* head) {
    if (head == NULL) return NULL;
    
    struct Node* newHead = NULL;
    struct Node* newTail = NULL;
    struct Node* temp = head;
    
    while (temp != NULL) {
        insertAtEnd(&newHead, &newTail, temp->data);
        temp = temp->next;
    }
    
    return newHead;
}

int main() {
    struct Node* list1_head = NULL, *list1_tail = NULL;
    struct Node* list2_head = NULL, *list2_tail = NULL;
    struct Node* merged_head = NULL;
    int choice;
    
    printf("=== Merge Two Sorted Doubly Linked Lists ===\n");
    printf("This program merges two sorted doubly linked lists\n");
    printf("maintaining the sorted order and bidirectional links.\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Input List 1 (sorted)\n");
        printf("2. Input List 2 (sorted)\n");
        printf("3. Display both lists\n");
        printf("4. Merge lists\n");
        printf("5. Clear lists\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (list1_head != NULL) {
                    freeList(list1_head);
                    list1_head = list1_tail = NULL;
                }
                inputSortedList(&list1_head, &list1_tail, 1);
                break;
                
            case 2:
                if (list2_head != NULL) {
                    freeList(list2_head);
                    list2_head = list2_tail = NULL;
                }
                inputSortedList(&list2_head, &list2_tail, 2);
                break;
                
            case 3:
                printf("\nCurrent Lists:\n");
                display(list1_head, "List 1");
                display(list2_head, "List 2");
                if (merged_head != NULL) {
                    display(merged_head, "Merged List");
                }
                break;
                
            case 4:
                if (list1_head == NULL && list2_head == NULL) {
                    printf("Both lists are empty!\n");
                } else {
                    printf("\nOriginal Lists:\n");
                    display(list1_head, "List 1");
                    display(list2_head, "List 2");
                    
                    // Create copies to preserve original lists
                    struct Node* list1_copy = copyList(list1_head);
                    struct Node* list2_copy = copyList(list2_head);
                    
                    if (merged_head != NULL) {
                        freeList(merged_head);
                    }
                    merged_head = mergeSortedLists(list1_copy, list2_copy);
                    
                    printf("\nResult:\n");
                    display(merged_head, "Merged List");
                }
                break;
                
            case 5:
                if (list1_head != NULL) {
                    freeList(list1_head);
                    list1_head = list1_tail = NULL;
                }
                if (list2_head != NULL) {
                    freeList(list2_head);
                    list2_head = list2_tail = NULL;
                }
                if (merged_head != NULL) {
                    freeList(merged_head);
                    merged_head = NULL;
                }
                printf("All lists cleared!\n");
                break;
                
            case 6:
                printf("Exiting program...\n");
                freeList(list1_head);
                freeList(list2_head);
                freeList(merged_head);
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
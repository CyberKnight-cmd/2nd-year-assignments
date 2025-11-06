#include <stdio.h>
#include <stdlib.h>

// Node structure for single linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/*
ALGORITHM FOR MERGING TWO SORTED LINKED LISTS:

1. Create a dummy node to simplify the merging process
2. Initialize a tail pointer to track the end of merged list
3. While both lists have nodes:
   a. Compare the data of current nodes
   b. Attach the smaller node to the merged list
   c. Move the pointer of the list from which node was taken
   d. Move the tail pointer
4. Attach remaining nodes from the non-empty list
5. Return the merged list (dummy->next)

Time Complexity: O(m + n) where m and n are lengths of the lists
Space Complexity: O(1) - only using pointers
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

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* list1, Node* list2) {
    // Create a dummy node to simplify merging
    Node* dummy = createNode(0);
    if (dummy == NULL) return NULL;
    
    Node* tail = dummy;
    
    printf("Merging two sorted lists:\n");
    
    // Merge nodes while both lists have elements
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            printf("Taking %d from list1\n", list1->data);
            tail->next = list1;
            list1 = list1->next;
        } else {
            printf("Taking %d from list2\n", list2->data);
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    // Attach remaining nodes from non-empty list
    if (list1 != NULL) {
        printf("Attaching remaining nodes from list1\n");
        tail->next = list1;
    } else if (list2 != NULL) {
        printf("Attaching remaining nodes from list2\n");
        tail->next = list2;
    }
    
    // Store the merged list head
    Node* mergedHead = dummy->next;
    
    // Free the dummy node
    free(dummy);
    
    printf("Merge completed successfully!\n");
    return mergedHead;
}

// Function to merge two sorted lists recursively
Node* mergeSortedListsRecursive(Node* list1, Node* list2) {
    // Base cases
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    // Choose the smaller node and recursively merge the rest
    if (list1->data <= list2->data) {
        list1->next = mergeSortedListsRecursive(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeSortedListsRecursive(list1, list2->next);
        return list2;
    }
}

// Function to check if list is sorted
int isSorted(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 1; // Empty or single node list is sorted
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->data > temp->next->data) {
            return 0; // Not sorted
        }
        temp = temp->next;
    }
    return 1; // Sorted
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
}

// Function to create sample sorted lists
void createSampleLists(Node** list1, Node** list2) {
    // Create first sorted list: 1, 3, 5, 7
    *list1 = NULL;
    int values1[] = {1, 3, 5, 7};
    int size1 = sizeof(values1) / sizeof(values1[0]);
    
    printf("Creating first sorted list: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", values1[i]);
        *list1 = insertAtEnd(*list1, values1[i]);
    }
    printf("\n");
    
    // Create second sorted list: 2, 4, 6, 8
    *list2 = NULL;
    int values2[] = {2, 4, 6, 8};
    int size2 = sizeof(values2) / sizeof(values2[0]);
    
    printf("Creating second sorted list: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", values2[i]);
        *list2 = insertAtEnd(*list2, values2[i]);
    }
    printf("\n");
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* mergedList = NULL;
    int choice, data, listChoice;
    
    printf("=== Merge Two Sorted Linked Lists Program ===\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Node to List 1\n");
        printf("2. Insert Node to List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Display Merged List\n");
        printf("6. Merge Lists (Iterative)\n");
        printf("7. Merge Lists (Recursive)\n");
        printf("8. Check if Lists are Sorted\n");
        printf("9. Create Sample Lists\n");
        printf("10. Clear All Lists\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert in List 1: ");
                scanf("%d", &data);
                list1 = insertAtEnd(list1, data);
                printf("Inserted %d into List 1\n", data);
                break;
                
            case 2:
                printf("Enter data to insert in List 2: ");
                scanf("%d", &data);
                list2 = insertAtEnd(list2, data);
                printf("Inserted %d into List 2\n", data);
                break;
                
            case 3:
                printf("List 1:\n");
                displayList(list1);
                printf("Nodes: %d, Sorted: %s\n", countNodes(list1), 
                       isSorted(list1) ? "Yes" : "No");
                break;
                
            case 4:
                printf("List 2:\n");
                displayList(list2);
                printf("Nodes: %d, Sorted: %s\n", countNodes(list2), 
                       isSorted(list2) ? "Yes" : "No");
                break;
                
            case 5:
                printf("Merged List:\n");
                displayList(mergedList);
                if (mergedList != NULL) {
                    printf("Nodes: %d, Sorted: %s\n", countNodes(mergedList), 
                           isSorted(mergedList) ? "Yes" : "No");
                }
                break;
                
            case 6:
                if (!isSorted(list1) || !isSorted(list2)) {
                    printf("Warning: One or both lists are not sorted!\n");
                    printf("Merge result may not be sorted.\n");
                }
                
                printf("Before merging:\n");
                printf("List 1: "); displayList(list1);
                printf("List 2: "); displayList(list2);
                
                if (mergedList != NULL) {
                    freeList(mergedList);
                }
                mergedList = mergeSortedLists(list1, list2);
                
                printf("After merging:\n");
                displayList(mergedList);
                break;
                
            case 7:
                if (!isSorted(list1) || !isSorted(list2)) {
                    printf("Warning: One or both lists are not sorted!\n");
                    printf("Merge result may not be sorted.\n");
                }
                
                printf("Before merging (recursive):\n");
                printf("List 1: "); displayList(list1);
                printf("List 2: "); displayList(list2);
                
                if (mergedList != NULL) {
                    freeList(mergedList);
                }
                mergedList = mergeSortedListsRecursive(list1, list2);
                
                printf("After merging (recursive):\n");
                displayList(mergedList);
                break;
                
            case 8:
                printf("List 1 is %s\n", isSorted(list1) ? "sorted" : "not sorted");
                printf("List 2 is %s\n", isSorted(list2) ? "sorted" : "not sorted");
                if (mergedList != NULL) {
                    printf("Merged list is %s\n", isSorted(mergedList) ? "sorted" : "not sorted");
                }
                break;
                
            case 9:
                if (list1 != NULL) freeList(list1);
                if (list2 != NULL) freeList(list2);
                if (mergedList != NULL) freeList(mergedList);
                
                createSampleLists(&list1, &list2);
                mergedList = NULL;
                
                printf("Sample lists created!\n");
                printf("List 1: "); displayList(list1);
                printf("List 2: "); displayList(list2);
                break;
                
            case 10:
                if (list1 != NULL) { freeList(list1); list1 = NULL; }
                if (list2 != NULL) { freeList(list2); list2 = NULL; }
                if (mergedList != NULL) { freeList(mergedList); mergedList = NULL; }
                printf("All lists cleared!\n");
                break;
                
            case 11:
                printf("Exiting...\n");
                if (list1 != NULL) freeList(list1);
                if (list2 != NULL) freeList(list2);
                if (mergedList != NULL) freeList(mergedList);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 11);
    
    return 0;
}
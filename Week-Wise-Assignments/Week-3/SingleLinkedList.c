#include <stdio.h>
#include <stdlib.h>  // For malloc() and exit()

// Define the structure with typedef correctly
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create a linked list by inserting at the end
node* createNodeEnd() {
    node *head = NULL, *nw, *tail = NULL;
    char ans;

    do {
        nw = (node*)malloc(sizeof(node));
        if (nw == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("Enter the data: ");
        scanf("%d", &nw->data);
        nw->next = NULL;

        if (head == NULL) {
            head = tail = nw;  // First node
        } else {
            tail->next = nw;
            tail = nw;
        }

        printf("Do you want to enter more nodes (Y/N): ");
        getchar();  // Clear newline left in buffer
        scanf("%c", &ans);

    } while (ans != 'n' && ans != 'N');

    return head;
}

// Function to display the linked list
void display(node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to count number of nodes
int countNode(node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to count nodes and calculate even/odd indexed sums
int* countNodeWithSum(node *head) {
    int count = 0, evenSum = 0, oddSum = 0;

    while (head != NULL) {
        if (count % 2 == 0)
            evenSum += head->data;
        else
            oddSum += head->data;
        count++;
        head = head->next;
    }

    int *arr = (int*)malloc(sizeof(int) * 3);
    arr[0] = count;
    arr[1] = evenSum;
    arr[2] = oddSum;
    return arr;
}

// Reversing the list (in-place)
void reverse(node **head) {
    node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;     // store next node
        curr->next = prev;     // reverse the link
        prev = curr;           // move prev forward
        curr = next;           // move curr forward
    }

    *head = prev; // update head
}

// Printing list in reverse order without modifying actual links
void printReverse(node* head) {
    if (head == NULL) return;
    printReverse(head->next);
    printf("%d -> ", head->data);
}

// Main function
int main() {
    node *head = createNodeEnd();
    display(head);

    printf("Reversed printing (without modifying list): ");
    printReverse(head);
    printf("NULL\n");

    int *result = countNodeWithSum(head);
    printf("Total Nodes: %d\n", result[0]);
    printf("Sum at Even Indices: %d\n", result[1]);
    printf("Sum at Odd Indices: %d\n", result[2]);
    free(result);

    reverse(&head);
    printf("List after actual reversal: ");
    display(head);

    return 0;
}

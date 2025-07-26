#include <stdio.h>
#include <stdlib.h>  // For malloc() and exit()

// Define the structure with typedef correctly
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create node at the beginning 
node* createNodeBeginning() {
    node *head = NULL, *nw;
    char ans;

    do {
        nw = (node*)malloc(sizeof(node));
        if (nw == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("Enter the data: ");
        scanf("%d", &nw->data);

        nw->next = head;  // Insert at beginning
        head = nw;

        // Clear input buffer and take answer
        printf("Do you want to enter more nodes (Y/N): ");
        getchar();  // To consume leftover newline
        scanf("%c", &ans);

    } while (ans != 'n' && ans != 'N');

    return head;
}


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
        getchar();
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

// Function to count nodes
int countNode(node *head){
    int count = 0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
    return count;
}

// Function to return total nodes, even index elements sum, odd index elements sum
int* countNodeWithSum(node *head){
    int count = 0, evenSum = 0, oddSum = 0;
    while(head!=NULL){
        count++;
        if(count%2) oddSum+=head->data;
        else evenSum += head->data;
        head = head->next;
    }

    int *arr = (int*)malloc(sizeof(int)*3);
    arr[0] = count;
    arr[1] = evenSum;
    arr[2] = oddSum;
    return arr;
}


// Reversing a list (in a single pass)
void reverse(node **head) {
    node *prev = NULL, *curr = *head, *next = NULL;
    
    while (curr != NULL) {
        next = curr->next;    // store next
        curr->next = prev;    // reverse the link
        prev = curr;          // move prev to current
        curr = next;          // move current to next
    }
    
    *head = prev; // update the head to new first node
}


// Printing in reversed form without affecting the linking
void printReverse(node* head){
    if(head->next!=NULL)
        printReverse(head->next);
    printf("%d -> ", head->data);
}


// Main function
int main() {
    node *head = createNodeEnd();
    display(head);
    printReverse(head);
    return 0;
}

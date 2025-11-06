#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Stack ADT for characters
typedef struct {
    char *data;
    int top;
    int capacity;
} CharStack;

// Initialize character stack
CharStack* createCharStack(int capacity) {
    CharStack* stack = (CharStack*)malloc(sizeof(CharStack));
    if (!stack) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    stack->data = (char*)malloc(capacity * sizeof(char));
    if (!stack->data) {
        printf("Memory allocation failed!\n");
        free(stack);
        return NULL;
    }
    
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Check if stack is empty
bool isEmpty(CharStack* stack) {
    return stack->top == -1;
}

// Check if stack is full
bool isFull(CharStack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push character to stack
void push(CharStack* stack, char ch) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = ch;
}

// Pop character from stack
char pop(CharStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Reverse string using stack ADT
char* reverseString(char* str) {
    int len = strlen(str);
    if (len == 0) return str;
    
    // Create stack with capacity equal to string length
    CharStack* stack = createCharStack(len);
    if (!stack) return NULL;
    
    // Push all characters to stack
    printf("Pushing characters to stack: ");
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
        printf("'%c' ", str[i]);
    }
    printf("\n");
    
    // Pop all characters and store back in string
    printf("Popping characters from stack: ");
    for (int i = 0; i < len; i++) {
        str[i] = pop(stack);
        printf("'%c' ", str[i]);
    }
    printf("\n");
    
    // Free stack memory
    free(stack->data);
    free(stack);
    
    return str;
}

// Alternative method: Reverse without modifying original string
char* reverseStringCopy(char* str) {
    int len = strlen(str);
    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    if (!reversed) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    CharStack* stack = createCharStack(len);
    if (!stack) {
        free(reversed);
        return NULL;
    }
    
    // Push all characters to stack
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }
    
    // Pop all characters to create reversed string
    for (int i = 0; i < len; i++) {
        reversed[i] = pop(stack);
    }
    reversed[len] = '\0';
    
    // Free stack memory
    free(stack->data);
    free(stack);
    
    return reversed;
}

int main() {
    char str[1000];
    int choice;
    
    do {
        printf("\n=== String Reversal Using Stack ADT ===\n");
        printf("1. Reverse string (modify original)\n");
        printf("2. Reverse string (create new copy)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline
        
        switch (choice) {
            case 1:
                printf("Enter string to reverse: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; // remove newline
                
                printf("Original string: \"%s\"\n", str);
                reverseString(str);
                printf("Reversed string: \"%s\"\n", str);
                break;
                
            case 2:
                printf("Enter string to reverse: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; // remove newline
                
                printf("Original string: \"%s\"\n", str);
                char* reversed = reverseStringCopy(str);
                if (reversed) {
                    printf("Reversed string: \"%s\"\n", reversed);
                    printf("Original string unchanged: \"%s\"\n", str);
                    free(reversed);
                }
                break;
                
            case 3:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Stack ADT for characters
typedef struct {
    char *data;
    int top;
    int capacity;
} CharStack;

// Initialize character stack
CharStack* createCharStack(int capacity) {
    CharStack* stack = (CharStack*)malloc(sizeof(CharStack));
    if (!stack) return NULL;
    
    stack->data = (char*)malloc(capacity * sizeof(char));
    if (!stack->data) {
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

// Push character to stack
void push(CharStack* stack, char ch) {
    if (stack->top < stack->capacity - 1) {
        stack->data[++stack->top] = ch;
    }
}

// Pop character from stack
char pop(CharStack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

// Free stack memory
void destroyCharStack(CharStack* stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}

// Check if character is alphanumeric
bool isAlphaNumeric(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

// Powerful palindrome function using stack ADT
bool is_palindrome(char *text) {
    if (text == NULL) return true;
    
    int len = strlen(text);
    if (len <= 1) return true;
    
    // Create stack with sufficient capacity
    CharStack* stack = createCharStack(len);
    if (!stack) return false;
    
    // First pass: Push only alphanumeric characters (lowercase) to stack
    for (int i = 0; i < len; i++) {
        if (isAlphaNumeric(text[i])) {
            push(stack, tolower(text[i]));
        }
    }
    
    // Second pass: Compare with stack contents
    for (int i = 0; i < len; i++) {
        if (isAlphaNumeric(text[i])) {
            char stackChar = pop(stack);
            if (tolower(text[i]) != stackChar) {
                destroyCharStack(stack);
                return false;
            }
        }
    }
    
    destroyCharStack(stack);
    return true;
}

// Test function to demonstrate palindrome checking
void testPalindrome(char* text) {
    printf("Testing: \"%s\"\n", text);
    printf("Result: %s\n", is_palindrome(text) ? "PALINDROME" : "NOT PALINDROME");
    printf("---\n");
}

int main() {
    printf("=== Palindrome Checker Using Stack ADT ===\n\n");
    
    // Test cases as specified in the problem
    printf("Testing predefined examples:\n\n");
    
    testPalindrome("");
    testPalindrome("a");
    testPalindrome("aa");
    testPalindrome("aaa");
    testPalindrome("aba");
    testPalindrome("abba");
    testPalindrome("Taco cat");
    testPalindrome("Madam, I'm Adam");
    testPalindrome("A man, a plan, a canal: Panama");
    testPalindrome("Doc, note: I dissent. A fast never prevents a fatness. I diet on cod.");
    
    // Test some non-palindromes
    printf("\nTesting non-palindromes:\n\n");
    testPalindrome("hello");
    testPalindrome("world");
    testPalindrome("programming");
    testPalindrome("Almost a palindrome");
    
    // Interactive testing
    char input[1000];
    int choice;
    
    do {
        printf("\n=== Interactive Palindrome Testing ===\n");
        printf("1. Test custom string\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline
        
        switch (choice) {
            case 1:
                printf("Enter string to test: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // remove newline
                
                printf("\nAnalyzing: \"%s\"\n", input);
                
                // Show processed characters
                printf("Processed characters: ");
                for (int i = 0; i < strlen(input); i++) {
                    if (isAlphaNumeric(input[i])) {
                        printf("%c", tolower(input[i]));
                    }
                }
                printf("\n");
                
                testPalindrome(input);
                break;
                
            case 2:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 2);
    
    return 0;
}
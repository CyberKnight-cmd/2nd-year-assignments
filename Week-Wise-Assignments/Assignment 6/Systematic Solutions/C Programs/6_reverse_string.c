#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Stack {
    char data[MAX_SIZE];
    int top;
};

// Initialize stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push character to stack
void push(struct Stack* stack, char ch) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = ch;
}

// Pop character from stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Display stack contents
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack contents (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        if (stack->data[i] == ' ') {
            printf("[SPACE] ");
        } else {
            printf("'%c' ", stack->data[i]);
        }
    }
    printf("\n");
}

// Algorithm for String Reversal using Stack:
// 1. Push all characters of the string onto the stack
// 2. Pop all characters from the stack to get reversed string
// 3. LIFO property of stack naturally reverses the order
void reverseString(char* original, char* reversed) {
    struct Stack stack;
    initStack(&stack);
    
    int length = strlen(original);
    
    printf("\n=== String Reversal using Stack ===\n");
    printf("Original string: \"%s\"\n", original);
    printf("String length: %d\n", length);
    printf("Algorithm: Push all characters, then pop to get reverse\n\n");
    
    // Phase 1: Push all characters onto stack
    printf("Phase 1: Pushing characters onto stack\n");
    for (int i = 0; i < length; i++) {
        push(&stack, original[i]);
        printf("Step %d: Pushed '%c'\n", i + 1, original[i]);
        
        if (length <= 10) { // Show stack state for short strings
            printf("         ");
            displayStack(&stack);
        }
        printf("\n");
    }
    
    printf("All characters pushed to stack.\n");
    if (length <= 20) {
        displayStack(&stack);
    }
    
    // Phase 2: Pop all characters to create reversed string
    printf("\nPhase 2: Popping characters to create reversed string\n");
    int index = 0;
    while (!isEmpty(&stack)) {
        char ch = pop(&stack);
        reversed[index] = ch;
        printf("Step %d: Popped '%c' -> reversed[%d] = '%c'\n", 
               index + 1, ch, index, ch);
        
        if (length <= 10) { // Show remaining stack for short strings
            printf("         Remaining stack: ");
            displayStack(&stack);
        }
        
        index++;
        printf("\n");
    }
    
    reversed[index] = '\0'; // Null terminate
    
    printf("String reversal completed!\n");
    printf("Reversed string: \"%s\"\n", reversed);
}

// Reverse only words in a string (keep word order, reverse each word)
void reverseWords(char* original, char* result) {
    struct Stack stack;
    initStack(&stack);
    
    int len = strlen(original);
    int resultIndex = 0;
    
    printf("\n=== Reverse Words using Stack ===\n");
    printf("Original: \"%s\"\n", original);
    printf("Algorithm: Reverse each word individually using stack\n\n");
    
    for (int i = 0; i <= len; i++) {
        if (original[i] != ' ' && original[i] != '\0') {
            // Push character to stack
            push(&stack, original[i]);
            printf("Pushed '%c' to stack\n", original[i]);
        } else {
            // End of word or string, pop all characters
            if (!isEmpty(&stack)) {
                printf("End of word reached, popping characters:\n");
                while (!isEmpty(&stack)) {
                    char ch = pop(&stack);
                    result[resultIndex++] = ch;
                    printf("Popped '%c'\n", ch);
                }
            }
            
            // Add space if not end of string
            if (original[i] == ' ') {
                result[resultIndex++] = ' ';
                printf("Added space\n");
            }
            printf("\n");
        }
    }
    
    result[resultIndex] = '\0';
    printf("Result: \"%s\"\n", result);
}

// Check if string is palindrome using stack
int isPalindrome(char* str) {
    struct Stack stack;
    initStack(&stack);
    
    int len = strlen(str);
    
    printf("\n=== Palindrome Check using Stack ===\n");
    printf("String: \"%s\"\n", str);
    printf("Algorithm: Push first half, compare with second half\n\n");
    
    // Push first half of string
    int mid = len / 2;
    printf("Pushing first half (%d characters):\n", mid);
    for (int i = 0; i < mid; i++) {
        push(&stack, str[i]);
        printf("Pushed '%c'\n", str[i]);
    }
    
    // Start comparing from middle (skip middle character for odd length)
    int start = (len % 2 == 0) ? mid : mid + 1;
    printf("\nComparing with second half (starting from index %d):\n", start);
    
    for (int i = start; i < len; i++) {
        if (isEmpty(&stack)) {
            printf("Stack empty but string continues - Not palindrome\n");
            return 0;
        }
        
        char stackChar = pop(&stack);
        printf("Comparing '%c' (from stack) with '%c' (from string)\n", stackChar, str[i]);
        
        if (stackChar != str[i]) {
            printf("Mismatch found - Not palindrome\n");
            return 0;
        }
    }
    
    if (!isEmpty(&stack)) {
        printf("Stack not empty - Not palindrome\n");
        return 0;
    }
    
    printf("All characters matched - Is palindrome!\n");
    return 1;
}

// Remove spaces and convert to lowercase for better palindrome checking
void preprocessString(char* original, char* processed) {
    int j = 0;
    for (int i = 0; original[i]; i++) {
        if (original[i] != ' ') {
            processed[j++] = (original[i] >= 'A' && original[i] <= 'Z') ? 
                           original[i] + 32 : original[i];
        }
    }
    processed[j] = '\0';
}

int main() {
    char original[MAX_SIZE];
    char reversed[MAX_SIZE];
    char processed[MAX_SIZE];
    int choice;
    
    printf("=== String Reversal using Stack ===\n");
    printf("This program demonstrates various string operations using stack\n");
    printf("Stack's LIFO property naturally reverses the order of elements\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Reverse entire string\n");
        printf("2. Reverse words in string\n");
        printf("3. Check if string is palindrome\n");
        printf("4. Demonstrate with sample strings\n");
        printf("5. Show algorithm explanation\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter a string to reverse: ");
                fgets(original, sizeof(original), stdin);
                original[strcspn(original, "\n")] = 0; // Remove newline
                
                if (strlen(original) == 0) {
                    printf("Empty string!\n");
                    break;
                }
                
                reverseString(original, reversed);
                break;
                
            case 2:
                printf("Enter a string to reverse words: ");
                fgets(original, sizeof(original), stdin);
                original[strcspn(original, "\n")] = 0; // Remove newline
                
                if (strlen(original) == 0) {
                    printf("Empty string!\n");
                    break;
                }
                
                reverseWords(original, reversed);
                break;
                
            case 3:
                printf("Enter a string to check palindrome: ");
                fgets(original, sizeof(original), stdin);
                original[strcspn(original, "\n")] = 0; // Remove newline
                
                if (strlen(original) == 0) {
                    printf("Empty string!\n");
                    break;
                }
                
                // Check with original string
                int result1 = isPalindrome(original);
                
                // Check with preprocessed string (no spaces, lowercase)
                preprocessString(original, processed);
                printf("\nChecking preprocessed string (no spaces, lowercase): \"%s\"\n", processed);
                int result2 = isPalindrome(processed);
                
                printf("\nResults:\n");
                printf("Original string: %s\n", result1 ? "Palindrome" : "Not palindrome");
                printf("Preprocessed string: %s\n", result2 ? "Palindrome" : "Not palindrome");
                break;
                
            case 4:
                printf("\n=== Sample Demonstrations ===\n");
                
                char* samples[] = {
                    "hello",
                    "racecar",
                    "A man a plan a canal Panama",
                    "hello world",
                    "12321"
                };
                
                int numSamples = sizeof(samples) / sizeof(samples[0]);
                
                for (int i = 0; i < numSamples; i++) {
                    printf("\n--- Sample %d ---\n", i + 1);
                    strcpy(original, samples[i]);
                    reverseString(original, reversed);
                    
                    // Also check if palindrome
                    preprocessString(original, processed);
                    int isPalin = isPalindrome(processed);
                    printf("Is palindrome (preprocessed): %s\n", isPalin ? "Yes" : "No");
                }
                break;
                
            case 5:
                printf("\n=== Algorithm Explanation ===\n");
                printf("String Reversal using Stack:\n");
                printf("1. Push all characters of string onto stack (LIFO)\n");
                printf("2. Pop all characters from stack to get reversed order\n");
                printf("3. Time Complexity: O(n), Space Complexity: O(n)\n\n");
                
                printf("Why Stack Works for Reversal:\n");
                printf("- Last In, First Out (LIFO) property\n");
                printf("- First character pushed becomes last character popped\n");
                printf("- Natural reversal without additional logic\n\n");
                
                printf("Applications:\n");
                printf("- Undo operations in text editors\n");
                printf("- Expression evaluation (postfix)\n");
                printf("- Palindrome checking\n");
                printf("- Backtracking algorithms\n");
                break;
                
            case 6:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
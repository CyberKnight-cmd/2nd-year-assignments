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
        return '\0';
    }
    return stack->data[stack->top--];
}

// Peek top character
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->data[stack->top];
}

// Check if character is opening bracket
int isOpeningBracket(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

// Check if character is closing bracket
int isClosingBracket(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

// Get matching opening bracket for a closing bracket
char getMatchingOpening(char closing) {
    switch (closing) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return '\0';
    }
}

// Get matching closing bracket for an opening bracket
char getMatchingClosing(char opening) {
    switch (opening) {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        default: return '\0';
    }
}

// Display stack contents
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Empty");
        return;
    }
    
    printf("Bottom -> ");
    for (int i = 0; i <= stack->top; i++) {
        printf("'%c' ", stack->data[i]);
    }
    printf("<- Top");
}

// Algorithm for Parenthesis Validation:
// 1. Scan expression from left to right
// 2. If opening bracket, push to stack
// 3. If closing bracket, check if it matches top of stack
// 4. If matches, pop from stack; if not, expression is invalid
// 5. At end, stack should be empty for valid expression
int validateParentheses(char* expression) {
    struct Stack stack;
    initStack(&stack);
    
    int length = strlen(expression);
    
    printf("\n=== Parenthesis Validation Process ===\n");
    printf("Expression: %s\n", expression);
    printf("Algorithm: Use stack to match opening and closing brackets\n\n");
    
    printf("Step-by-step validation:\n");
    
    for (int i = 0; i < length; i++) {
        char ch = expression[i];
        
        printf("Step %d: Processing '%c' at position %d\n", i + 1, ch, i);
        
        if (isOpeningBracket(ch)) {
            push(&stack, ch);
            printf("         Opening bracket found, pushed to stack\n");
        }
        else if (isClosingBracket(ch)) {
            printf("         Closing bracket found\n");
            
            if (isEmpty(&stack)) {
                printf("         ERROR: No matching opening bracket (stack is empty)\n");
                printf("         Expression is INVALID\n");
                return 0;
            }
            
            char top = peek(&stack);
            char expected = getMatchingOpening(ch);
            
            printf("         Top of stack: '%c', Expected: '%c'\n", top, expected);
            
            if (top == expected) {
                pop(&stack);
                printf("         Match found! Popped '%c' from stack\n", top);
            } else {
                printf("         ERROR: Mismatch! Found '%c' but expected '%c'\n", top, expected);
                printf("         Expression is INVALID\n");
                return 0;
            }
        }
        else {
            printf("         Non-bracket character, ignoring\n");
        }
        
        printf("         Stack status: ");
        displayStack(&stack);
        printf("\n\n");
    }
    
    // Check if stack is empty at the end
    if (isEmpty(&stack)) {
        printf("Final check: Stack is empty - Expression is VALID\n");
        return 1;
    } else {
        printf("Final check: Stack is not empty - Expression is INVALID\n");
        printf("Unmatched opening brackets: ");
        displayStack(&stack);
        printf("\n");
        return 0;
    }
}

// Find and report all bracket errors
void detailedValidation(char* expression) {
    struct Stack stack;
    initStack(&stack);
    
    int length = strlen(expression);
    int errorCount = 0;
    
    printf("\n=== Detailed Error Analysis ===\n");
    printf("Expression: %s\n", expression);
    
    // Track positions for better error reporting
    int positions[MAX_SIZE];
    int posTop = -1;
    
    for (int i = 0; i < length; i++) {
        char ch = expression[i];
        
        if (isOpeningBracket(ch)) {
            push(&stack, ch);
            positions[++posTop] = i;
        }
        else if (isClosingBracket(ch)) {
            if (isEmpty(&stack)) {
                printf("Error %d: Unmatched closing '%c' at position %d\n", 
                       ++errorCount, ch, i);
            } else {
                char top = peek(&stack);
                char expected = getMatchingOpening(ch);
                
                if (top == expected) {
                    pop(&stack);
                    posTop--;
                } else {
                    printf("Error %d: Mismatched brackets - '%c' at position %d doesn't match '%c' at position %d\n", 
                           ++errorCount, ch, i, top, positions[posTop]);
                    pop(&stack);
                    posTop--;
                }
            }
        }
    }
    
    // Report unmatched opening brackets
    while (!isEmpty(&stack)) {
        char unmatched = pop(&stack);
        printf("Error %d: Unmatched opening '%c' at position %d\n", 
               ++errorCount, unmatched, positions[posTop--]);
    }
    
    if (errorCount == 0) {
        printf("No errors found - Expression is valid!\n");
    } else {
        printf("Total errors found: %d\n", errorCount);
    }
}

// Generate suggestions for fixing bracket errors
void suggestFixes(char* expression) {
    printf("\n=== Fix Suggestions ===\n");
    
    struct Stack stack;
    initStack(&stack);
    
    int length = strlen(expression);
    int openCount[3] = {0}; // (, [, {
    int closeCount[3] = {0}; // ), ], }
    
    // Count different types of brackets
    for (int i = 0; i < length; i++) {
        switch (expression[i]) {
            case '(': openCount[0]++; break;
            case ')': closeCount[0]++; break;
            case '[': openCount[1]++; break;
            case ']': closeCount[1]++; break;
            case '{': openCount[2]++; break;
            case '}': closeCount[2]++; break;
        }
    }
    
    char* brackets[] = {"()", "[]", "{}"};
    
    for (int i = 0; i < 3; i++) {
        if (openCount[i] != closeCount[i]) {
            if (openCount[i] > closeCount[i]) {
                printf("Add %d closing '%c' bracket(s)\n", 
                       openCount[i] - closeCount[i], brackets[i][1]);
            } else {
                printf("Remove %d closing '%c' bracket(s) or add %d opening '%c' bracket(s)\n", 
                       closeCount[i] - openCount[i], brackets[i][1],
                       closeCount[i] - openCount[i], brackets[i][0]);
            }
        }
    }
}

int main() {
    char expression[MAX_SIZE];
    int choice;
    
    printf("=== Parenthesis Validation using Stack ===\n");
    printf("This program validates balanced parentheses, brackets, and braces\n");
    printf("Supported brackets: (), [], {}\n");
    printf("Stack is used to match opening and closing brackets\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Validate expression\n");
        printf("2. Detailed error analysis\n");
        printf("3. Test with sample expressions\n");
        printf("4. Show algorithm explanation\n");
        printf("5. Generate fix suggestions\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter expression to validate: ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = 0; // Remove newline
                
                if (strlen(expression) == 0) {
                    printf("Empty expression is considered valid!\n");
                    break;
                }
                
                int isValid = validateParentheses(expression);
                printf("\nResult: Expression is %s\n", isValid ? "VALID" : "INVALID");
                break;
                
            case 2:
                printf("Enter expression for detailed analysis: ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = 0; // Remove newline
                
                if (strlen(expression) == 0) {
                    printf("Empty expression!\n");
                    break;
                }
                
                detailedValidation(expression);
                break;
                
            case 3:
                printf("\n=== Sample Expression Tests ===\n");
                
                char* samples[] = {
                    "()",
                    "()[]{}",
                    "([{}])",
                    "((()))",
                    "([)]",
                    "(((",
                    ")))",
                    "{[}]",
                    "a(b[c{d}e]f)g",
                    "if(x>0){print(\"positive\");}"
                };
                
                int numSamples = sizeof(samples) / sizeof(samples[0]);
                
                for (int i = 0; i < numSamples; i++) {
                    printf("\n--- Sample %d ---\n", i + 1);
                    strcpy(expression, samples[i]);
                    int result = validateParentheses(expression);
                    printf("Result: %s\n", result ? "VALID" : "INVALID");
                }
                break;
                
            case 4:
                printf("\n=== Algorithm Explanation ===\n");
                printf("Parenthesis Validation Algorithm:\n");
                printf("1. Initialize empty stack\n");
                printf("2. Scan expression from left to right:\n");
                printf("   - If opening bracket: push to stack\n");
                printf("   - If closing bracket: check if matches top of stack\n");
                printf("     * If matches: pop from stack\n");
                printf("     * If doesn't match or stack empty: invalid\n");
                printf("3. After scanning: stack should be empty for valid expression\n\n");
                
                printf("Time Complexity: O(n) - single pass through expression\n");
                printf("Space Complexity: O(n) - worst case all opening brackets\n\n");
                
                printf("Why Stack Works:\n");
                printf("- LIFO property matches bracket nesting structure\n");
                printf("- Most recent opening bracket should match first closing bracket\n");
                printf("- Natural handling of nested structures\n");
                break;
                
            case 5:
                printf("Enter expression for fix suggestions: ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = 0; // Remove newline
                
                if (strlen(expression) == 0) {
                    printf("Empty expression!\n");
                    break;
                }
                
                suggestFixes(expression);
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
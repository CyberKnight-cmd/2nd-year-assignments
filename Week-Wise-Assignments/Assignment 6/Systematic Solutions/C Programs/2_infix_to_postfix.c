#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

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

// Push element to stack
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Pop element from stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Peek top element
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->data[stack->top];
}

// Check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

// Get precedence of operator
int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Check if operator is right associative
int isRightAssociative(char operator) {
    return operator == '^';
}

// Algorithm for Infix to Postfix Conversion:
// 1. Scan infix expression from left to right
// 2. If operand, add to output
// 3. If '(', push to stack
// 4. If ')', pop until '(' and add to output
// 5. If operator, pop operators with higher/equal precedence and add to output, then push current operator
// 6. After scanning, pop all remaining operators
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    
    printf("\n=== Infix to Postfix Conversion Process ===\n");
    printf("Infix Expression: %s\n", infix);
    printf("Algorithm: Use stack to handle operator precedence and associativity\n\n");
    
    int len = strlen(infix);
    int postfixIndex = 0;
    int step = 1;
    
    printf("Step-by-step conversion:\n");
    
    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        
        if (ch == ' ') continue; // Skip spaces
        
        printf("Step %d: Processing '%c'\n", step++, ch);
        
        if (isalnum(ch)) {
            printf("         Operand found, adding to output\n");
            postfix[postfixIndex++] = ch;
            postfix[postfixIndex++] = ' '; // Add space for readability
        }
        else if (ch == '(') {
            printf("         Opening parenthesis, pushing to stack\n");
            push(&stack, ch);
        }
        else if (ch == ')') {
            printf("         Closing parenthesis, popping until '('\n");
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                char op = pop(&stack);
                printf("         Popped '%c' and added to output\n", op);
                postfix[postfixIndex++] = op;
                postfix[postfixIndex++] = ' ';
            }
            if (!isEmpty(&stack)) {
                pop(&stack); // Remove '('
                printf("         Removed '(' from stack\n");
            }
        }
        else if (isOperator(ch)) {
            printf("         Operator found: %c (precedence: %d)\n", ch, getPrecedence(ch));
            
            while (!isEmpty(&stack) && peek(&stack) != '(' &&
                   ((getPrecedence(peek(&stack)) > getPrecedence(ch)) ||
                    (getPrecedence(peek(&stack)) == getPrecedence(ch) && !isRightAssociative(ch)))) {
                char op = pop(&stack);
                printf("         Popped '%c' (higher/equal precedence) and added to output\n", op);
                postfix[postfixIndex++] = op;
                postfix[postfixIndex++] = ' ';
            }
            
            printf("         Pushing '%c' to stack\n", ch);
            push(&stack, ch);
        }
        else {
            printf("         Invalid character '%c' ignored\n", ch);
        }
        
        // Display current stack status
        printf("         Stack: ");
        if (isEmpty(&stack)) {
            printf("Empty");
        } else {
            for (int j = 0; j <= stack.top; j++) {
                printf("%c ", stack.data[j]);
            }
        }
        printf("\n");
        
        // Display current output
        printf("         Output: ");
        for (int j = 0; j < postfixIndex; j++) {
            printf("%c", postfix[j]);
        }
        printf("\n\n");
    }
    
    // Pop remaining operators
    printf("Popping remaining operators from stack:\n");
    while (!isEmpty(&stack)) {
        char op = pop(&stack);
        printf("Popped '%c' and added to output\n", op);
        postfix[postfixIndex++] = op;
        postfix[postfixIndex++] = ' ';
    }
    
    // Remove trailing space and null terminate
    if (postfixIndex > 0 && postfix[postfixIndex - 1] == ' ') {
        postfixIndex--;
    }
    postfix[postfixIndex] = '\0';
}

// Function to validate infix expression
int isValidInfix(char* expression) {
    struct Stack stack;
    initStack(&stack);
    
    int len = strlen(expression);
    int operandCount = 0;
    int operatorCount = 0;
    
    for (int i = 0; i < len; i++) {
        char ch = expression[i];
        
        if (ch == ' ') continue;
        
        if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            if (isEmpty(&stack)) {
                printf("Error: Unmatched closing parenthesis\n");
                return 0;
            }
            pop(&stack);
        }
        else if (isalnum(ch)) {
            operandCount++;
        }
        else if (isOperator(ch)) {
            operatorCount++;
        }
        else {
            printf("Error: Invalid character '%c'\n", ch);
            return 0;
        }
    }
    
    if (!isEmpty(&stack)) {
        printf("Error: Unmatched opening parenthesis\n");
        return 0;
    }
    
    if (operandCount != operatorCount + 1) {
        printf("Error: Invalid number of operands and operators\n");
        return 0;
    }
    
    return 1;
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE * 2];
    int choice;
    
    printf("=== Infix to Postfix Conversion ===\n");
    printf("This program converts infix expressions to postfix using stack\n");
    printf("Supported operators: +, -, *, /, %%, ^ with proper precedence\n");
    printf("Parentheses are supported for grouping\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Convert infix to postfix\n");
        printf("2. Show example conversions\n");
        printf("3. Show operator precedence\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                fgets(infix, sizeof(infix), stdin);
                infix[strcspn(infix, "\n")] = 0; // Remove newline
                
                if (strlen(infix) == 0) {
                    printf("Empty expression!\n");
                    break;
                }
                
                if (!isValidInfix(infix)) {
                    printf("Invalid infix expression!\n");
                    break;
                }
                
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;
                
            case 2:
                printf("\n=== Example Conversions ===\n");
                printf("1. Infix:  A + B\n");
                printf("   Postfix: A B +\n\n");
                printf("2. Infix:  A + B * C\n");
                printf("   Postfix: A B C * +\n\n");
                printf("3. Infix:  (A + B) * C\n");
                printf("   Postfix: A B + C *\n\n");
                printf("4. Infix:  A + B * C - D\n");
                printf("   Postfix: A B C * + D -\n\n");
                printf("5. Infix:  A ^ B ^ C\n");
                printf("   Postfix: A B C ^ ^\n\n");
                break;
                
            case 3:
                printf("\n=== Operator Precedence (Higher number = Higher precedence) ===\n");
                printf("1. + - (Addition, Subtraction)\n");
                printf("2. * / %% (Multiplication, Division, Modulo)\n");
                printf("3. ^ (Exponentiation - Right Associative)\n");
                printf("\nParentheses () have highest precedence\n");
                break;
                
            case 4:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
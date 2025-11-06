#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
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
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = value;
    printf("Pushed %d to stack\n", value);
}

// Pop element from stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    int value = stack->data[stack->top--];
    printf("Popped %d from stack\n", value);
    return value;
}

// Peek top element
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->data[stack->top];
}

// Check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

// Perform arithmetic operation
int performOperation(int operand1, int operand2, char operator) {
    printf("Performing: %d %c %d = ", operand1, operator, operand2);
    
    switch (operator) {
        case '+':
            printf("%d\n", operand1 + operand2);
            return operand1 + operand2;
        case '-':
            printf("%d\n", operand1 - operand2);
            return operand1 - operand2;
        case '*':
            printf("%d\n", operand1 * operand2);
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero!\n");
                return 0;
            }
            printf("%d\n", operand1 / operand2);
            return operand1 / operand2;
        case '%':
            if (operand2 == 0) {
                printf("Error: Modulo by zero!\n");
                return 0;
            }
            printf("%d\n", operand1 % operand2);
            return operand1 % operand2;
        case '^':
            {
                int result = 1;
                for (int i = 0; i < operand2; i++) {
                    result *= operand1;
                }
                printf("%d\n", result);
                return result;
            }
        default:
            printf("Error: Invalid operator!\n");
            return 0;
    }
}

// Algorithm for Postfix Evaluation:
// 1. Scan the postfix expression from left to right
// 2. If operand, push to stack
// 3. If operator, pop two operands, perform operation, push result
// 4. Final result is the only element left in stack
int evaluatePostfix(char* expression) {
    struct Stack stack;
    initStack(&stack);
    
    printf("\n=== Postfix Evaluation Process ===\n");
    printf("Expression: %s\n", expression);
    printf("Algorithm: Scan left to right, push operands, pop for operators\n\n");
    
    int len = strlen(expression);
    int step = 1;
    
    for (int i = 0; i < len; i++) {
        char ch = expression[i];
        
        if (ch == ' ') continue; // Skip spaces
        
        printf("Step %d: Processing '%c'\n", step++, ch);
        
        if (isdigit(ch)) {
            // Extract multi-digit number
            int num = 0;
            while (i < len && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Adjust for loop increment
            
            printf("         Operand found: %d\n", num);
            push(&stack, num);
        }
        else if (isOperator(ch)) {
            printf("         Operator found: %c\n", ch);
            
            if (stack.top < 1) {
                printf("Error: Insufficient operands for operator %c\n", ch);
                return -1;
            }
            
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            
            int result = performOperation(operand1, operand2, ch);
            push(&stack, result);
        }
        else {
            printf("Error: Invalid character '%c' in expression\n", ch);
            return -1;
        }
        
        printf("         Stack status: ");
        if (isEmpty(&stack)) {
            printf("Empty\n");
        } else {
            printf("Top = %d\n", peek(&stack));
        }
        printf("\n");
    }
    
    if (stack.top != 0) {
        printf("Error: Invalid postfix expression - multiple values left in stack\n");
        return -1;
    }
    
    return pop(&stack);
}

// Function to display stack contents
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack contents (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    char expression[MAX_SIZE];
    int choice;
    
    printf("=== Postfix Expression Evaluation ===\n");
    printf("This program evaluates postfix expressions using stack\n");
    printf("Supported operators: +, -, *, /, %%, ^\n");
    printf("Example: 5 3 + 2 * (means (5+3)*2 = 16)\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Evaluate postfix expression\n");
        printf("2. Show example expressions\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter postfix expression (separate numbers and operators with spaces): ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = 0; // Remove newline
                
                if (strlen(expression) == 0) {
                    printf("Empty expression!\n");
                    break;
                }
                
                int result = evaluatePostfix(expression);
                if (result != -1) {
                    printf("Final Result: %d\n", result);
                } else {
                    printf("Evaluation failed due to errors.\n");
                }
                break;
                
            case 2:
                printf("\n=== Example Postfix Expressions ===\n");
                printf("1. \"5 3 +\" = 8 (equivalent to 5+3)\n");
                printf("2. \"5 3 + 2 *\" = 16 (equivalent to (5+3)*2)\n");
                printf("3. \"15 7 1 1 + - / 3 * 2 1 1 + + -\" = 5\n");
                printf("4. \"5 1 2 + 4 * + 3 -\" = 14\n");
                printf("5. \"2 3 ^\" = 8 (equivalent to 2^3)\n");
                printf("6. \"10 2 8 * + 3 -\" = 23\n");
                break;
                
            case 3:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }
char peek() { return top == -1 ? '\0' : stack[top]; }

int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (peek() != '(') postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(infix[i]) && peek() != '(')
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1) postfix[j++] = pop();
    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
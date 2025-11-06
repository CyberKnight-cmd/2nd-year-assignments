#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[100], top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int evaluate(char* expr) {
    for (int i = 0; expr[i]; i++) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            int b = pop(), a = pop();
            switch (expr[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char expr[100];
    printf("Enter postfix expression: ");
    scanf("%s", expr);
    printf("Result: %d\n", evaluate(expr));
    return 0;
}
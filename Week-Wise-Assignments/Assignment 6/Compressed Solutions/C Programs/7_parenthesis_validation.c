#include <stdio.h>
#include <string.h>

char stack[1000];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return top >= 0 ? stack[top--] : '\0'; }

int isValid(char* expr) {
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            char top_char = pop();
            if ((expr[i] == ')' && top_char != '(') ||
                (expr[i] == ']' && top_char != '[') ||
                (expr[i] == '}' && top_char != '{')) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char expr[1000];
    printf("Enter expression: ");
    gets(expr);
    printf("Result: %s\n", isValid(expr) ? "Valid" : "Invalid");
    return 0;
}
#include <stdio.h>
#include <string.h>

char stack[1000];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) push(str[i]);
    for (int i = 0; i < len; i++) str[i] = pop();
}

int main() {
    char str[1000];
    printf("Enter string: ");
    gets(str);
    reverse(str);
    printf("Reversed: %s\n", str);
    return 0;
}
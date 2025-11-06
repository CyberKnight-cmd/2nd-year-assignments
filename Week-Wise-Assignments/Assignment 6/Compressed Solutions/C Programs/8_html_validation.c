#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][50];
int top = -1;

void push(char* tag) { strcpy(stack[++top], tag); }
char* pop() { return top >= 0 ? stack[top--] : ""; }

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
}

int isSelfClosing(char* tag) {
    char* selfClosing[] = {"br", "hr", "img", "input", "meta", "link"};
    for (int i = 0; i < 6; i++)
        if (strcmp(tag, selfClosing[i]) == 0) return 1;
    return 0;
}

int validateHTML(char* html) {
    int len = strlen(html);
    for (int i = 0; i < len; i++) {
        if (html[i] == '<') {
            char tag[50] = "";
            int j = 0, start = i + 1;
            
            if (html[start] == '/') start++;
            
            while (i < len && html[i] != '>' && html[i] != ' ') i++;
            
            strncpy(tag, html + start, i - start);
            tag[i - start] = '\0';
            toLowerCase(tag);
            
            while (i < len && html[i] != '>') i++;
            
            if (html[start - 1] == '/') {
                if (top == -1 || strcmp(pop(), tag) != 0) return 0;
            } else if (!isSelfClosing(tag)) {
                push(tag);
            }
        }
    }
    return top == -1;
}

int main() {
    char html[1000];
    printf("Enter HTML: ");
    gets(html);
    printf("Result: %s\n", validateHTML(html) ? "Valid" : "Invalid");
    return 0;
}
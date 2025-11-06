#include <stdio.h>

int stack[100], top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

long long factorial(int n) {
    if (n <= 1) return 1;
    
    for (int i = n; i >= 1; i--) push(i);
    
    long long result = 1;
    while (top != -1) result *= pop();
    
    return result;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Factorial: %lld\n", factorial(n));
    return 0;
}
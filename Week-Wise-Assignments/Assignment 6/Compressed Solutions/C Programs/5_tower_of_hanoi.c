#include <stdio.h>

int A[100], B[100], C[100];
int topA = -1, topB = -1, topC = -1;

void push(int tower[], int* top, int disk) { tower[++(*top)] = disk; }
int pop(int tower[], int* top) { return (*top) >= 0 ? tower[(*top)--] : -1; }

void move(int from[], int* fromTop, int to[], int* toTop, char fromName, char toName) {
    int disk = pop(from, fromTop);
    push(to, toTop, disk);
    printf("Move disk %d from %c to %c\n", disk, fromName, toName);
}

void hanoi(int n) {
    for (int i = n; i >= 1; i--) push(A, &topA, i);
    
    int total = (1 << n) - 1;
    if (n % 2 == 0) { int* temp = &topB; topB = topC; topC = *temp; }
    
    for (int i = 1; i <= total; i++) {
        if (i % 3 == 1) {
            if (topA == -1 || (topC >= 0 && A[topA] > C[topC]))
                move(C, &topC, A, &topA, 'C', 'A');
            else
                move(A, &topA, C, &topC, 'A', 'C');
        } else if (i % 3 == 2) {
            if (topA == -1 || (topB >= 0 && A[topA] > B[topB]))
                move(B, &topB, A, &topA, 'B', 'A');
            else
                move(A, &topA, B, &topB, 'A', 'B');
        } else {
            if (topB == -1 || (topC >= 0 && B[topB] > C[topC]))
                move(C, &topC, B, &topB, 'C', 'B');
            else
                move(B, &topB, C, &topC, 'B', 'C');
        }
    }
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi(n);
    return 0;
}
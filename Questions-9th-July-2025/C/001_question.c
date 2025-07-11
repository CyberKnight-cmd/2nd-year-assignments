#include <stdio.h>

int main() {
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    printf((num%2) ? "Odd number" : "Even number");
    return 0;
}

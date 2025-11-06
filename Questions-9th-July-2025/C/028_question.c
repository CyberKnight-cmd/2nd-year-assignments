#include <stdio.h>

int main() {
    // TODO: Implement solution here

    int num1 = 0;
    int num2 = 0;
    scanf("%d %d", &num1, &num2);
    int carry = 0;

    do{
        carry = num1&num2;
        num1 = num1^num2;
        num2 = carry<<1;
    }while(num2);

    printf("%d", num1);
    return 0;
}

#include <stdio.h>

int main() {
    // TODO: Implement solution here
    int n = 0, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if(n<0){
        printf("OUT OF GIVEN CONSTRAINT.");
        return 1;
    }
    while(n){
        sum += n%10;
        n /= 10;
    }
    printf("Sum of digits: %d", sum);
    return 0;
}

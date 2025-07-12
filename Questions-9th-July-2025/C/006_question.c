#include <stdio.h>

int main() {
    // TODO: Implement solution here

    int n = 0, iter = 0, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    

    // Checking for constraint
    if(n<0){
        printf("OUT OF GIVEN CONSTRAINT.");
        return 1;
    }

    // Calculating even digits sum
    while(n){
        iter = n%10;
        if(!(iter%2))   sum += iter;
        n /= 10;
    }
    printf("Sum : %d", sum);
    return 0;
}

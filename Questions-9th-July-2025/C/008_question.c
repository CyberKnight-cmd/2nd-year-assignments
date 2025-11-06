#include <stdio.h>
#include<math.h>

int main() {
    // TODO: Implement solution here
    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Check for constraint
    if(n<=1){
        printf("OUT OF GIVEN CONSTRAINT.");
        return 1;
    }

    int checkValue = sqrt(n) + 1;
    for(int i = 2; i < checkValue; i++){
        if(!(n%i)){
            printf("Not a Prime number : %d x %d = %d", i, n/i, n);
            return 1;
        }
    }
    printf("%d is a prime number", n);
    return 0;
}

#include <stdio.h>
#include<math.h>
int main() {
    // TODO: Implement solution here
    int b = 0;
    printf("Enter a number: ");
    scanf("%d", &b);
    
    // Checking for constraint
    if(b<=0){
        printf("OUT OF GIVEN CONSTRAINT.");
        return 1;
    }

    // Printing digits in correct order as entered rather than printing them backwards (Too easy if done in reverse order)
    int largestMultiple = (int)pow(10, (int)log10(b));
    while(largestMultiple){
        printf("%d ", b/largestMultiple);
        b %= largestMultiple;
        largestMultiple/=10;
        
    }
    return 0;
}

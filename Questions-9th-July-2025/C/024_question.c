#include <stdio.h>

int main() {
    // TODO: Implement solution here
    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Constraint
    if(n<0){
        printf("OUT OF GIVEN CONSTRAINT.");
        return 1;
    }
    int number = 1, subtractValue = 0, addValue = 0;
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", number);
        if(i%2==0)
            number += addValue++;
        else
            number -= subtractValue++;
    }
    
    return 0;
}

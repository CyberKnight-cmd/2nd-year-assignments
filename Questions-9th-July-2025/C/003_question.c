#include <stdio.h>

int main() {
    // TODO: Implement solution here
    int n = 0;
    printf("Enter the number of coffee cups: ");
    scanf("%d", &n);
    
    // Checking the constraint first
    if(n<1){
        printf("OUT OF GIVEN CONSTRAINT.");
        return 1;
    }
    int nearestMultiple = n - n%6;
    // Modifying total cups
    n += nearestMultiple/6;

    printf("\nTotal number of cups : %d", n);
    return 0;
}

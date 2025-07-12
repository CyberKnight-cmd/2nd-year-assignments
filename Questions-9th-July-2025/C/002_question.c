#include <stdio.h>

int main() {
    // TODO: Implement solution here
    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Following the constraint first
    if(n<1 || n>100)    printf("OUT OF CONSTRAINT.");
    // Now checking for conditions
    if(n%2) printf("Weird.");
    else{
        if(n>=2 && n<=5)    printf("Not Weird.");
        else if(n>=6 && n<=20)  printf("Weird.");
        else printf("Not Weird.");
    }
    return 0;
}

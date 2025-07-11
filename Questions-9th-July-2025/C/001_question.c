#include <stdio.h>

int main() {
    int num;
    printf("Enter the number : ");
    do{
        scanf("%d", &num);
        if(num<0) printf("Negative value entered!! Try Again\n");
    }while(num<0);    
    printf((num%2) ? "Odd number" : "Even number");
    return 0;
}

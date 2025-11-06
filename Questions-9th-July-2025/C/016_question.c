#include <stdio.h>

int main() {
    // TODO: Implement solution here
    int num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    int finalNum = 0; int iterative = 1;

    while(num!=0){
        int current = num%10;
        if(current)
            finalNum =  current*iterative + finalNum;
        else
            finalNum = 1*iterative + finalNum;
        num /= 10;
        iterative*=10;
    }

    printf("%d", finalNum);
    return 0;
}

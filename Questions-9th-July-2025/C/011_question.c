#include <stdio.h>
int main() {
    // TODO: Implement solution here
    int n = 0, sum = 0;

    if(n<0) return 10;
    int arr[10] = {0,0,2,3,0,5,0,7,0,0};
    printf("Enter a number: ");
    scanf("%d", &n);
    
    while(n!=0){
        sum += arr[n%10];
        n/=10;
    }
    printf("%d", sum);
    return 0;
}

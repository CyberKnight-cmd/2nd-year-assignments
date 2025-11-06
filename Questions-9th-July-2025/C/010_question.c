#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int n){
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    int limit = sqrt(n);
    for(int i = 3; i <= limit; i += 2){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n = 0, count = -1, current = 1; // count = -1 so that first prime (2) is at index 0
    printf("Enter a number: ");
    scanf("%d", &n);

    while(count < n){
        current++;
        if(isPrime(current)){
            count++;
        }
    }

    printf("The %dth prime number is %d\n", n, current);
    return 0;
}

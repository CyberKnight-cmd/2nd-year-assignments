#include <stdio.h>
#include <math.h>

void printPrime(int n){
    int checkValue = sqrt(n) + 2;
    for(int i = 2; i < checkValue; i++){
        if(!(n%i)){
            return;
        }
    }
    printf("%d ", n);
}

int main() {
    // TODO: Implement solution here
    int m, n;
    printf("Enter the range : ");
    scanf("%d %d", &m, &n);

    // Checking for constraints
    if(m<2 || n<2){
        printf("INVALID RANGE!!!");
        return 1;
    }

    // Determining the lower and higher range
    int lower = m<n ? m : n;
    int upper = lower==m ? n : m;

    // Printing primes
    while(lower<=upper) printPrime(lower++);
    return 0;
}

// Do this for higher range later on Using Sieve of Eratosthenes

#include<stdio.h>

int main(){
    const int num = 50;
    printf("%d\n",num);
    
    int *ptr = (int*)&num;
    *ptr = 20;
    printf("%d", num);
    return 0;
}
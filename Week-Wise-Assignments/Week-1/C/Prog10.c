#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int n, char s[]){
    printf("%s", s);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter initial size = ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        printf("%d : ", i);
        scanf("%d", arr+i);
    }

    // Printing current Array
    printArray(arr,n, "The array before modifying : ");

    printf("Enter the number of extra elements to be added : ");
    int m = 0;
    scanf("%d", &m);
    n+=m;
    arr = (int*)realloc(arr, n*sizeof(int));
    for(int i = n-m; i < n; i++){
        printf("%d : ", i);
        scanf("%d", &arr[i]);
    }

    printArray(arr,n, "The array after modifying : ");
    return 0;
}
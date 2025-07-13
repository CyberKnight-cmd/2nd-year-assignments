#include<stdio.h>
#include<stdlib.h>

void linearSearch(int *arr, int n, int key){
    for(int i = 0; i < n; i++){
        if(*(arr+i) == key){
            printf("%d found at index %d.", key, i);
            return;
        }
    }
    printf("%d not found", key);
}


int main(){
    int n = 0;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    
    // Dynamically allocating the array
    int *arr = (int*)malloc(n*sizeof(int));

    // Checking for NULL pointer (i.e. negative n or invalid n)
    if(arr == NULL){
        printf("Memory allocation failed.");
        return 1;
    }

    // Getting Array elements
    for(int i = 0; i < n; i++){
        printf("%d : ", i);
        scanf("%d", arr+i);
    }

    // Getting key value
    int key = 0;
    printf("Enter an element to search : ");
    scanf("%d", &key);
    
    linearSearch(arr, n , key);
    free(arr); // Preventing memory leaks

    return 0;
    
}
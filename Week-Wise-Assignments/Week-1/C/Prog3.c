#include<stdio.h>
#include<stdlib.h>

// kth minimum element

int main(){
    int n = 0, size = 0;
    printf("Enter n : ");
    scanf("%d", &n);
    // Taking all the elements
    int *arr = (int*)malloc(n*sizeof(int)), *hashMap = NULL;
    // Initializing array and hashmap
    for(int i = 0; i < n; i++){
        printf("%d : ", i);
        scanf("%d", arr+i);
        if (*(arr+i)>=size){
            int newSize = *(arr+i) + 1;
            hashMap = (int*)realloc(hashMap, newSize*sizeof(int));
            // Initializing new slots to 0
            for(; size < newSize; size++){
                hashMap[size] = 0;
            }
        }
        hashMap[*(arr+i)] = 1;
    }

    // Fetching kth minimum 
    int k = 0;
    printf("Enter kth minimum element to be searched: ");
    scanf("%d", &k);
    for(int i = 0; i < size; i++){
        if(hashMap[i]){
            if(--k == 0){
                printf("%d is the minimum kth number", i);
            }
        }
    }    
    return 0;
}
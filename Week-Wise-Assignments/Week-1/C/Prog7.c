#include<stdio.h>
#include<stdlib.h>

int main(){
    int m, n, size;
    printf("Enter the size of 1st array : ");
    scanf("%d", &m);

    int* arr1 = (int*)malloc(m * sizeof(int));
    for(int i = 0; i < m; i++){
        printf("%d : ", i);
        scanf("%d", arr1 + i);
    }

    printf("Enter the size of 2nd array : ");
    scanf("%d", &n);
    int* arr2 = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("%d : ", i);
        scanf("%d", arr2 + i);
    }

    size = m + n;
    int* arr = (int*)malloc(size * sizeof(int));
    int i = 0, j = 0, k = 0;

    while(i < m && j < n){
        if(arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }

    while(i < m){
        arr[k++] = arr1[i++];
    }

    while(j < n){
        arr[k++] = arr2[j++];
    }

    printf("Merged array:\n");
    for(int x = 0; x < size; x++){
        printf("%d ", arr[x]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(arr);

    return 0;
}

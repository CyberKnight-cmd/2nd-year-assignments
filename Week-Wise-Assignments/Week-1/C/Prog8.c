#include<stdio.h>
#include<stdlib.h>

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int placePivot(int* arr, int low, int high){
    int pivot = low;
    int i = low, j = high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i < high)
            i++;
        while(arr[j]>arr[pivot] && j>=low)
            j--;
        if(i<j) swap(arr, i, j);
    }
    swap(arr, pivot, j);
    return j;
}

void quickSort(int* arr, int low, int high){
    if(low<=high){
        int pIndex = placePivot(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
    }
}


int main(){
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);
    int size = m + n;
    int *mergedArr = (int*)malloc(size*sizeof(int));

    int *arr1 = (int*)malloc(m*sizeof(int));
    for(int i = 0; i < m; i++){
        printf("%d : ", i);
        scanf("%d", arr1 + i);
        mergedArr[i] = arr1[i];
    }

    int *arr2 = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        printf("%d : ", i);
        scanf("%d", arr2 + i);
        mergedArr[m+i] = arr2[i];
    }

    // Sorting
    quickSort(mergedArr,0,size-1);
    // Printing
    for(int i = 0; i < size; i++){
        printf("%d ", mergedArr[i]);
    }
    return 0;
}
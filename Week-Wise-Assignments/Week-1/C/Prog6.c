#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
    int m = 0, n = 0, max = INT_MIN;
    printf("Enter m,n : ");
    scanf("%d %d", &m, &n);
    
    int **arr = (int**)malloc(m*sizeof(int*));
    int *data = (int*)malloc(m*n*sizeof(int));

    // Matrix input
    for(int i = 0; i < m; i++){
        arr[i] = data + i*n;
        for(int j = 0; j < n; j++){
            printf("%d, %d : ", i, j);
            scanf("%d", &arr[i][j]);
            if(arr[i][j]>max)
                max = arr[i][j];
        }
    }

    printf("%d is the maximum element.", max);
    return 0;
}
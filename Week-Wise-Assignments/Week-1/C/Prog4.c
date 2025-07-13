#include <stdio.h>
#include <stdlib.h>

int main() {
    int m = 0, n = 0;
    printf("Enter m,n = : ");
    scanf("%d %d", &m, &n);
    
    

    //Allocate array of int* pointers (rows)
    int **arr = (int**)malloc(m * sizeof(int*));

    //Allocate single contiguous block for all elements
    int *data = (int*)malloc(m * n * sizeof(int));

    //Set up row pointers to correct positions in the block while taking input
    for (int i = 0; i < m; i++) {
        arr[i] = data + i * n;
        for(int j = 0;j<n;j++){
            printf("%d, %d : ",i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int key = 0;
    printf("Enter the key: ");
    scanf("%d", &key);
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(key==arr[i][j]){
                printf("%d FOUND AT %d,%d", key, i, j);
                // Free memory
                free(data);
                free(arr);
                return 0;
            }
        }
    }
    printf("... element not found.. exiting");

    // Free memory
    free(data);
    free(arr);

    return 0;
}

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* Write Code Here */
long long matrixSum(int n, int operations_size_row, int operations_size_cols, int** operations) {
    long long a=0;
    int nums[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            nums[i][j]=0;
        }
    }
    for(int i=0;i<operations_size_row;i++){
        int index=operations[i][1];
        if(operations[i][0]==0){
            for(int j=0;j<n;j++){
                nums[index][j]=operations[i][2];
            }
        }else{
            for(int j=0;j<n;j++){
                nums[j][index]=operations[i][2];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a+=nums[i][j];
        }
    }
    return a;
}
int main() {
    long long res;

    int n;
    scanf("%d", &n);

    int operations_rows = 0;
    int operations_cols = 0;
    scanf("%d", &operations_rows);
    scanf("%d", &operations_cols);
    
    int** operations = (int**)malloc(operations_rows*sizeof(int*));
    int operations_init_i=0;
    for(operations_init_i=0 ; operations_init_i<operations_rows ; ++operations_init_i)
    {
        operations[operations_init_i] = (int*)malloc(operations_cols*(sizeof(int)));
    }
    
    int operations_i, operations_j;
    for(operations_i = 0; operations_i < operations_rows; operations_i++) {
        for(operations_j = 0; operations_j < operations_cols; operations_j++) {
            int operations_item;
            scanf("%d", &operations_item);
            
            operations[operations_i][operations_j] = operations_item;
        }
    }
    res = matrixSum(n, operations_rows, operations_cols, operations);
    printf("%ld\n", res);
    
    return 0;

}

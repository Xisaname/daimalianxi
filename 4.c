#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 计算陡峭值的函数
int calculate_steepness(int* arr, int n) {
    int steepness = 0;
    for (int i = 1; i < n; i++) {
        steepness += abs(arr[i] - arr[i - 1]);
    }
    return steepness;
}

// 交换函数
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 生成排列的递归函数
void permute(int* arr, int left, int right, int* best_steepness, int* best_perm, int n) {
    if (left == right) {
        int current_steepness = calculate_steepness(arr, n);
        if (current_steepness > *best_steepness) {
            *best_steepness = current_steepness;
            memcpy(best_perm, arr, n * sizeof(int));
        }
    }
    else {
        for (int i = left; i <= right; i++) {
            swap(&arr[left], &arr[i]);
            permute(arr, left + 1, right, best_steepness, best_perm, n);
            swap(&arr[left], &arr[i]); // 回溯
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    int* best_perm = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int best_steepness = -1;

    permute(arr, 0, n - 1, &best_steepness, best_perm, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", best_perm[i]);
    }
    printf("\n");

    free(arr);
    free(best_perm);

    return 0;
}

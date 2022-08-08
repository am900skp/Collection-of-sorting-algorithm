#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

//排序后的打印的辅助函数
void PrintArray(int* arr, int len, void (*pFun)(int*, int)) {
    pFun(arr, len);  
    for (int i = 0; i < len; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void SelectSort(int* arr, int len) {
    int min_idx;
    int tmp;
    for (int i = 0; i < len - 1; ++i) {
        min_idx = i;
        for (int j = i + 1; j < len; ++j) {
            min_idx = ((arr[min_idx] < arr[j]) ? min_idx : j);
        }
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
        // TraverArray(arr, len, false);
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {19, 0, 5, 7, 2, 44, 3, 6, 88, 8};
    PrintArray(arr, 10, SelectSort);
    return 0;
}
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

void InsertSort(int* arr, int len) {
    int pre_idx;                     
    int current;                     
    for (int i = 1; i < len; ++i) {  
        pre_idx = i - 1;            
        current = arr[i];            
        while (pre_idx >= 0 && arr[pre_idx] > current) {
            arr[pre_idx + 1] = arr[pre_idx];
            pre_idx--;
        }
        arr[pre_idx + 1] = current;
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {19, 0, 5, 7, 2, 44, 3, 6, 88, 8};
    PrintArray(arr, 10, InsertSort);
    return 0;
}
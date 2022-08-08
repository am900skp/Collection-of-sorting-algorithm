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

void BubbleSort(int* arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {19, 0, 5, 7, 2, 44, 3, 6, 88, 8};
    PrintArray(arr, 10, BubbleSort);
    return 0;
}
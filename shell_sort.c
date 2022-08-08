#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

//排序后的打印的辅助函数
void PrintArray(int* arr, int len, void (*pFun)(int*, int)) {
    pFun(arr, len);  //排序
    for (int i = 0; i < len; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void ShellSort(int* arr, int len) {
    for (int grap = len / 2; grap > 0; grap /= 2) {
        for (int i = grap; i < len; ++i) {
            int j = i;
            int current = arr[i];
            while (j - grap >= 0 && current < arr[j - grap]) {
                arr[j] = arr[j - grap];
                j = j - grap;
            }
            arr[j] = current;
        }
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {19, 0, 5, 7, 2, 44, 3, 6, 88, 8};
    PrintArray(arr, 10, ShellSort);
    return 0;
}
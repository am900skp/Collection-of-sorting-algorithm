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

//普通的归并排序
void BasicMerge(int* arr, int f_begin, int f_end, int s_begin, int s_end,
                int* new_arr) {
    int index = f_begin;
    int f = f_begin;
    int s = s_begin;
    while (f <= f_end && s <= s_end) {
        if (arr[f] <= arr[s]) {
            new_arr[++index] = arr[++f];
        } else {
            new_arr[++index] = arr[++s];
        }
    }
    //处理剩下元素
    while (f <= f_end) {
        new_arr[++index] = arr[++f];
    }
    while (s <= s_end) {
        new_arr[++index] = arr[++s];
    }
    // 1 2 3  3-1 = 2  其实元素有三个
    memcpy(arr + f_begin, new_arr + f_begin,
           sizeof(int) * (s_end - f_begin + 1));
}

void Merge(int* arr, int left, int right, int* new_arr) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    Merge(arr, left, mid, new_arr);
    Merge(arr, mid + 1, right, new_arr);
    BasicMerge(arr, left, mid, mid + 1, right, new_arr);
}

//统一接口
void MergeSort(int* arr, int len) {
    int* tmp = (int*)malloc(sizeof(int) * len);
    Merge(arr, 0, len - 1, tmp);
    free(tmp);
}

int main(int argc, char* argv[]) {
    int arr[] = {19, 0, 5, 7, 2, 44, 3, 6, 88, 8};
    PrintArray(arr, 10, MergeSort);
    return 0;
}
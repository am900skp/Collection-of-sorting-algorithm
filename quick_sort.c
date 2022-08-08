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

//交换辅助函数
void Swap(int* arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

//改变基准
int Partition(int* arr, int left, int right) {
    int pivot = left;
    int index = pivot + 1;
    for (int i = index; i <= right; ++i) {
        if (arr[i] < arr[pivot]) {
            Swap(arr, i, index);
            index++;
        }
    }
    Swap(arr, pivot, index - 1);
    return index - 1;
}

void Quick(int* arr, int left, int right) {
    if (left < right) {
        int partition_index = Partition(arr, left, right);
        Quick(arr, left, partition_index - 1);
        Quick(arr, partition_index + 1, right);
    }
}

//统一接口
void QuickSort(int* arr, int len) { 
    Quick(arr, 0, len - 1); 
}

int main(int argc, char* argv[]) {
    int arr[] = {19, 0, 5, 7, 2, 44, 3, 6, 88, 8};
    PrintArray(arr, 10, QuickSort);
    return 0;
}
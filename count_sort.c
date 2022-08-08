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

void CountSort(int* arr, int len) {
    int* count_arr = (int*)calloc(sizeof(int), 100);
    assert(count_arr);
    for (int i = 0; i < len; ++i) {
        count_arr[arr[i]]++;  //把数据当做数组下标去记录当前数据的个数
    }
    int* sort_arr = (int*)malloc(sizeof(int) * len);
    assert(sort_arr);
    for (int i = 1; i < 100; ++i) {
        //求和
        count_arr[i] += count_arr[i - 1];
    }
    //取数据
    for (int i = len; i > 0; --i) {
        sort_arr[count_arr[arr[i - 1]] - 1] = arr[i - 1];
        count_arr[arr[i - 1]]--;
    }
    memcpy(arr, sort_arr, len * sizeof(int));
    free(count_arr);
    free(sort_arr);
}

int main(int argc, char* argv[]) {
    int arr[] = {19, 0, 5, 7, 2, 44, 3, 6, 88, 8};
    PrintArray(arr, 10, CountSort);
    return 0;
}
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

//排序后的打印的辅助函数
void Printarr(int* arr, int len, void (*pFun)(int*, int)) {
    pFun(arr, len);  
    for (int i = 0; i < len; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

//获取当前数字的任意位上的数字
int GetPosNumber(int num, int pos) {
    int tmp = 1;
    for (int i = 0; i < pos - 1; ++i) {
        tmp *= 10;
    }
    return (num / tmp) % 10;
}

//获取数组最大值
int GetMaxNumber(int* arr, int len) {
    int max = arr[0];
    for (int i = 0; i < len; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

//求最大值的位数
int GetMaxNumberCount(int num) {
    int count = 1;
    while (num / 10) {
        count++;
        num /= 10;
    }
    return count;
}

//桶排序
void BucketSort(int* arr, int len, int pos) {
    int* bucket_arr[10] = {NULL};
    for (int i = 0; i < 10; i++) {
        //初始化为0 如果数据中有0的数据，换一个标记
        bucket_arr[i] = (int*)calloc(sizeof(int), len);
        assert(bucket_arr[i]);
    }
    //装桶
    for (int i = 0; i < len; ++i) {
        int index = GetPosNumber(arr[i], pos);
        for (int j = 0; j < len; ++j) {
            if (bucket_arr[index][j] == 0) {
                bucket_arr[index][j] = arr[i];
                break;
            }
        }
    }
    //出桶
    int k = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < len; ++j) {
            if (bucket_arr[i][j] != 0) {
                arr[k] = bucket_arr[i][j];
                bucket_arr[i][j] = 0;
                k++;
            }
        }
    }
}

//基数排序
void RadixSort(int* arr, int len) {
    int max_num = GetMaxNumber(arr, len);
    int loop = GetMaxNumberCount(max_num);
    for (int i = 1; i <= loop; ++i) {
        BucketSort(arr, len, i);
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {19, 1, 5, 7, 2, 44, 3, 6, 88, 8};
    //因为0是用作标记的,所以数据当中我没有使用0
    Printarr(arr, 10, RadixSort);
    return 0;
}
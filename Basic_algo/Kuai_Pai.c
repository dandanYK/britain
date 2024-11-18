// Created by 黄展博 on 2024/11/17.
#include <stdio.h>
#include <stdbool.h>
#include <mm_malloc.h>

// 交换两个数
void swap(int * a, int * b)
{
    int temp = * a;
    * a = * b;
    * b = temp;
}

// 快速排序的分区函数
int partition(int arr[], int low,int high)
{
    int piovt = arr[high];
    int i = low - 1;

    for (int j = 0; j < high; j++)
    {
        if (arr[j] <= piovt)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

//递归调用快速排序
void quickSort(int arr[], int low,int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1,high);
    }
}

// 打印数组
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

// 输入数组
void inputArray(int arr[], int size)
{
    for (int a = 0; a < size; a++)
    {
        printf("请输入第%d项的值：", a + 1);
        scanf("%d", &arr[a]);
    }
}

int main(void)
{
    int a;
    printf("请输入你要排序的数组长度：\n");
    scanf("%d", &a);
    int arr[a];
    inputArray(arr, a);
    printArray(arr, a);
    quickSort(arr , 0, a - 1);
    printf("下面是排序后的数组：\n");
    printArray(arr, a);
    return 0;
}
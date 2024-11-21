// Created by 黄展博 on 2024/11/20.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b);

void sort(int arr[], int n)
{
     int SortedIndex = 1;
     int i;
     while (SortedIndex < n)
     {
         //从SortedIndex开始，一直到数组末尾，进行排序,i就是控制这个循环的变量
         for (i = SortedIndex; i > 0; i--)
         {
             //每次进行比较就是看前一个数是否比后一个数小，如果小，就交换位置，所以应该是i < i - 1
             if (arr[i] < arr[i - 1])
             {
                 swap(&arr[i], &arr[i - 1]);
             }
             else
                 break;
         }
         SortedIndex++;
     }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int main()
{
    int arr[] = { 5, 2, 8, 3, 9, 1, 7, 4, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    sort(arr, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
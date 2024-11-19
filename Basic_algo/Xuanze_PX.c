#include <stdio.h>

void sort(int arr[], int n)
{
    int min, swap;
    for (int i = 0; i < n - 1; i++)
    {
        min = i; // 假设当前元素是最小的
        // 遍历数组，寻找最小元素的索引，本来自己写的时候忘记写一个for循环了，导致出错。
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j; // 找到更小的元素，更新最小元素的索引
            }
        }
        // 将找到的最小元素与当前元素交换
        swap = arr[i];
        arr[i] = arr[min];
        arr[min] = swap;
    }
}

int main()
{
    int arr[] = {5, 2, 8, 3, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

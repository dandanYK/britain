// Created by 黄展博 on 2024/11/16.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct HArray
{
    //元素数
    int HArray_size;
    //数组空间容量
    int HArray_length;
    //数组的指向
    int *HArray_data;
};
typedef struct HArray HArray; //重命名HArray类型

//扩容函数
bool Expand_HArray(HArray *pHArray)
{
    //将数组长度翻倍
    int new_length = pHArray->HArray_length * 2;
    int *new_data = (int *)malloc(new_length * sizeof(int));
    //分配内存失败
    if (new_data == NULL)
    {
        return false;
    }
    //复制原数组数据
    memcpy(new_data, pHArray->HArray_data, pHArray->HArray_size * sizeof(int));
    //释放原数组内存
    free(pHArray->HArray_data);
    //更新数组长度和数据指针
    pHArray->HArray_length = new_length;
    pHArray->HArray_data = new_data;
    return true;
}

HArray * Create_HArray(int size)
{
    HArray *pHArray = (HArray *)malloc(sizeof(HArray));
    //分配内存失败
    if (pHArray == NULL)
    {
        return 0;
    }
    pHArray->HArray_size = 0;
    pHArray->HArray_length = size;
    pHArray->HArray_data = (int *)malloc(size * sizeof(int));
    //分配内存失败
    if (pHArray->HArray_data == NULL)
    {
        //释放指针的内存
        free(pHArray);
        return 0;
    }
    //初始化数组
    for (int i = 0; i < size; i++) {
        pHArray->HArray_data[i] = 0;
        pHArray->HArray_size++;
    }
    //返回数组指针
    return pHArray;
}

//插入元素在数组末尾
bool Add_HArray(HArray *pHArray, int value)
{
    if (pHArray->HArray_size >= pHArray->HArray_length)
    {
        //数组已满，扩容
        if (Expand_HArray(pHArray))
        {
            //插入元素
            pHArray->HArray_data[pHArray->HArray_size] = value;
            pHArray->HArray_size++;
            return true;
        }
    }
    else
    {
        //插入元素
        pHArray->HArray_data[pHArray->HArray_size] = value;
        pHArray->HArray_size++;
        return true;
    }
}


//插入元素在数组之间
bool Insert_HArray(HArray *pHArray, int site,int value)
{
    //判断是否已满
    if (pHArray->HArray_size >= pHArray->HArray_length)
        {
            //数组已满，扩容
            if (Expand_HArray(pHArray))
            {
                //插入元素
                for (int i = 0; i >= site; i--)
                {
                    pHArray->HArray_data[i + 1] = pHArray->HArray_data[i];
                }
                pHArray->HArray_data[site] = value;
                pHArray->HArray_size++;
                return true;
            }
        }
    else
    {
        //插入元素
        for (int i = pHArray->HArray_size - 1; i >= site; i--) {
            pHArray->HArray_data[i + 1] = pHArray->HArray_data[i];
        }
        pHArray->HArray_data[site] = value;
        pHArray->HArray_size++;
        return true;
    }
}

int main()
{
    HArray *pHArray = Create_HArray(10);

    printf("HArray size: %d\n", pHArray->HArray_size);
    for (int i = 0; i < pHArray->HArray_size; i++)
    {
        printf("%d ", pHArray->HArray_data[i]);
    }
    printf("\n");

    Add_HArray(pHArray, 10);
    printf("HArray size: %d\n", pHArray->HArray_size);
    for (int i = 0; i < pHArray->HArray_size; i++)
    {
        printf("%d ", pHArray->HArray_data[i]);
    }
    printf("\n");

    Insert_HArray(pHArray, 2, 20);
    printf("HArray size: %d\n", pHArray->HArray_size);
    for (int i = 0; i < pHArray->HArray_size; i++)
    {
        printf("%d ", pHArray->HArray_data[i]);
    }

    //释放内存
    free(pHArray->HArray_data);
    free(pHArray);
    return 0;
}


//
// Created by 黄展博 on 2024/11/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义动态数组结构体
typedef struct {
    int* data;  // 指向存储数据的数组
    int size;   // 当前元素个数
    int capacity; // 当前容量
} MyArrayList;

// 初始化动态数组
void initMyArrayList(MyArrayList* list, int initCapacity) {
    list->data = (int*)malloc(initCapacity * sizeof(int));
    list->size = 0;
    list->capacity = initCapacity;
}

// 扩容
void resize(MyArrayList* list, int newCapacity) {
    int* temp = (int*)malloc(newCapacity * sizeof(int));
    for (int i = 0; i < list->size; i++) {
        temp[i] = list->data[i];
    }
    free(list->data);
    list->data = temp;
    list->capacity = newCapacity;
}

// 添加元素到尾部
void addLast(MyArrayList* list, int element) {
    if (list->size == list->capacity) {
        resize(list, 2 * list->capacity);
    }
    list->data[list->size] = element;
    list->size++;
}

// 在指定位置插入元素
void add(MyArrayList* list, int index, int element) {
    if (index < 0 || index > list->size) {
        printf("Index out of bounds\n");
        return;
    }

    if (list->size == list->capacity) {
        resize(list, 2 * list->capacity);
    }

    for (int i = list->size - 1; i >= index; i--) {
        list->data[i + 1] = list->data[i];
    }

    list->data[index] = element;
    list->size++;
}

// 删除尾部元素
int removeLast(MyArrayList* list) {
    if (list->size == 0) {
        printf("NoSuchElementException\n");
        return -1;
    }

    if (list->size == list->capacity / 4) {
        resize(list, list->capacity / 2);
    }

    int deletedVal = list->data[list->size - 1];
    list->size--;

    return deletedVal;
}

// 删除指定位置的元素
int remove(MyArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return -1;
    }

    if (list->size == list->capacity / 4) {
        resize(list, list->capacity / 2);
    }

    int deletedVal = list->data[index];

    for (int i = index + 1; i < list->size; i++) {
        list->data[i - 1] = list->data[i];
    }

    list->size--;

    return deletedVal;
}

// 获取指定位置的元素
int get(MyArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return -1;
    }

    return list->data[index];
}

// 修改指定位置的元素
int set(MyArrayList* list, int index, int element) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return -1;
    }

    int oldVal = list->data[index];
    list->data[index] = element;

    return oldVal;
}

// 获取当前元素个数
int getSize(MyArrayList* list) {
    return list->size;
}

// 检查数组是否为空
bool isEmpty(MyArrayList* list) {
    return list->size == 0;
}

// 显示数组内容
void display(MyArrayList* list) {
    printf("size = %d, capacity = %d\n", list->size, list->capacity);
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 释放动态数组内存
void freeMyArrayList(MyArrayList* list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

int main() {
    // 初始容量设置为 3
    MyArrayList arr;
    initMyArrayList(&arr, 3);

    // 添加 5 个元素
    for (int i = 1; i <= 5; i++) {
        addLast(&arr, i);
    }

    remove(&arr, 3);
    add(&arr, 1, 9);
    add(&arr, 0, 100);
    int val = removeLast(&arr);

    // 100 1 9 2 3
    for (int i = 0; i < getSize(&arr); i++) {
        printf("%d\n", get(&arr, i));
    }

    freeMyArrayList(&arr);

    return 0;
}

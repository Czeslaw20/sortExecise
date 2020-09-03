#pragma once
#include "sqList.h"

class SortAlgorithm
{
public:
    //第1种：最简单的冒泡排序
    void bubbleSort_1(SqList &li);

    //第2种：正宗冒泡排序
    void bubbleSort_2(SqList &li);

    //第3种：优化冒泡排序
    void bubbleSort_3(SqList &li);

    //第4种：简单选择排序
    void simpleSelectionSort(SqList &li);

    //第5种：直接插入排序
    void straightInsertSort(SqList &li);

    //第6种：希尔排序

    //第7种：堆排序

    //第8种：归并排序

    //第9种：快速排序
};

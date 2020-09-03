#include "sortAlgorithm.h"
#include <iostream>
using namespace std;

//第1种：最简单的冒泡排序
void SortAlgorithm::bubbleSort_1(SqList &li)
{
    cout << "正在进行第1种冒泡排序……" << endl;

    int i, j;
    for (i = 0; i < li.v.size() - 1; ++i)
    {
        for (j = i + 1; j < li.v.size(); ++j)
        {
            if (li.v[i] > li.v[j])
            {
                li.swap(i, j);
            }
        }
    }
}

//第2种：正宗冒泡排序
void SortAlgorithm::bubbleSort_2(SqList &li)
{
    cout << "正在进行第2种冒泡排序……" << endl;

    int i, j;
    for (i = 0; i < li.v.size() - 1; ++i)
    {
        for (j = li.v.size() - 1; j >= i; --j)
        {
            if (li.v[j] > li.v[j + 1])
            {
                li.swap(j, j + 1);
            }
        }
    }
}

//第3种：优化冒泡排序
//增加了flag标记上一轮循环中是否进行了交换
//若没有，说明序列已经有序
void SortAlgorithm::bubbleSort_3(SqList &li)
{
    cout << "正在进行第3种冒泡排序……" << endl;
    int i, j;
    bool flag = true;
    for (i = 0; i < li.v.size() - 1 && flag; ++i)
    {
        flag = false;
        for (j = li.v.size() - 1; j >= i; --j)
        {
            if (li.v[j] > li.v[j + 1])
            {
                li.swap(j, j + 1);
                flag = true;
            }
        }
    }
}

//第4种：简单选择排序
void SortAlgorithm::simpleSelectionSort(SqList &li)
{
    cout << "正在进行第4种:简单选择排序……" << endl;
    int i, j, min;
    for (i = 0; i < li.v.size() - 1; ++i)
    {
        min = i;
        //cout << "开始min=" << min << "的循环……" << endl;
        for (j = i + 1; j < li.v.size(); ++j)
        {
            if (li.v[min] > li.v[j])
            {
                min = j;
                //cout << "min = " << min << endl;
            }
        }
        if (min != i)
        {
            li.swap(min, i);
        }
    }
}

//第5种：直接插入排序
void SortAlgorithm::straightInsertSort(SqList &li)
{
    cout << "正在进行第5种:直接插入排序……" << endl;
    int i, j;
    for (i = 1; i < li.v.size(); ++i)
    {
        if (li.v[i] < li.v[i - 1])
        {
            int tmp = li.v[i];
            for (j = i - 1; li.v[j] > tmp; j--) //注意：li.v[j] > tmp；！！！！！
            {
                li.v[j + 1] = li.v[j];
            }
            li.v[j + 1] = tmp;
        }
    }
}

//第6种：希尔排序

//第7种：堆排序

//第8种：归并排序

//第9种：快速排序
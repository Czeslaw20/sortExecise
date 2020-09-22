#include <iostream>
using namespace std;
#include "sortAlgorithm.h"
#include <unistd.h>

void test01()
{
    SqList li;
    //生成随机数组
    li.genRandomList();
    li.printR();

    SortAlgorithm sort;

    //第1种：最简单的冒泡排序
    // sort.bubbleSort_1(li);

    //第2种：正宗冒泡排序
    // sort.bubbleSort_2(li);

    //第3种：优化冒泡排序
    // sort.bubbleSort_3(li);

    //第4种：简单选择排序
    // sort.simpleSelectionSort(li);

    //第5种：直接插入排序
    // sort.straightInsertSort(li);

    //第6种：希尔排序
    // sort.shellSort(li);

    //第7种：堆排序
    // sort.heapSort(li);

    //第8种：归并排序
    // sort.mergeSort(li);

    //第9种：快速排序
    // sort.quickSort(li);

    //第10种：基数排序
    // sort.radixSort(li);

    //第11种：桶排序
    sort.bucketSort(li);

    li.printR();
}

int main()
{
    test01();
    //system("pause");
    //system是windows系统api,在linux系统中无法使用，也无须使用
    //如需进程休眠，可使用:
    //pause();
    return EXIT_SUCCESS;
}
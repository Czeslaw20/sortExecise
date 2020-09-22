#include "sortAlgorithm.h"
#include <iostream>
#include <algorithm>
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
        int tmp = li.v[i];
        for (j = i; j > 0 && li.v[j - 1] > tmp; j = j - 1)
        {
            li.v[j] = li.v[j - 1];
        };
        li.v[j] = tmp;
    }
}

//第6种：希尔排序
void SortAlgorithm::shellSort(SqList &li)
{
    cout << "正在进行第6种：希尔排序……" << endl;
    int n = li.v.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; ++i)
        {
            int tmp = li.v[i];
            int j;
            for (j = i; j > gap - 1 && li.v[j - gap] > tmp; j = j - gap)
            {
                li.v[j] = li.v[j - gap];
            }
            li.v[j] = tmp;
        }
    }
}

//第7种：堆排序
//建立堆函数
void heapify(SqList &li, int n, int i)
{
    int largest = i; //将最大元素设置为堆顶元素
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    //如果left比root大
    if (l < n && li.v[l] > li.v[largest])
    {
        largest = l;
    }
    //如果right比root大
    if (r < n && li.v[r] > li.v[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        li.swap(i, largest);

        //递归地定义子堆
        heapify(li, n, largest);
    }
}
//堆排序
void SortAlgorithm::heapSort(SqList &li)
{
    int n = li.v.size();
    //建立堆
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(li, n, i);
    }
    //一个一个从堆顶取出元素
    for (int i = n - 1; i >= 0; i--)
    {
        li.swap(0, i);
        heapify(li, i, 0);
    }
}

//第8种：归并排序
void mergeS(vector<int> &v)
{
    int len = v.size();
    if (len <= 1)
    {
        return;
    }
    vector<int> left(v.begin(), v.begin() + len / 2);
    vector<int> right(v.begin() + len / 2, v.end());

    mergeS(left);
    mergeS(right);

    v.clear();
    int lindex = 0;
    int rindex = 0;
    while (lindex < left.size() && rindex < right.size())
    {
        if (left[lindex] <= right[rindex])
        {
            v.push_back(left[lindex]);
            lindex++;
        }
        else
        {
            v.push_back(right[rindex]);
            rindex++;
        }
    }
    v.insert(v.end(), left.begin() + lindex, left.end());
    v.insert(v.end(), right.begin() + rindex, right.end());
}

void SortAlgorithm::mergeSort(SqList &li)
{
    mergeS(li.v);
}

//第9种：快速排序
void quickS(vector<int> &v, int start, int end)
{
    if (end - start <= 1)
    {
        return;
    }
    int head = start;
    int tail = end - 1;
    int pivot = (head + tail) / 2;
    while (tail > head)
    {
        while (head < pivot && v[head] <= v[pivot])
        {
            head++;
        }
        int temp = v[head];
        v[head] = v[pivot];
        v[pivot] = temp;
        pivot = head;

        while (tail > pivot && v[tail] >= v[pivot])
        {
            tail--;
        }
        temp = v[tail];
        v[tail] = v[pivot];
        v[pivot] = temp;
        pivot = tail;
    }

    quickS(v, start, pivot);
    quickS(v, pivot + 1, end);
}
void SortAlgorithm::quickSort(SqList &li)
{
    quickS(li.v, 0, li.v.size());
}

//第10种：基数排序
int getMax(SqList &li, int n)
{
    int mx = li.v[0];
    for (int i = 1; i < n; ++i)
    {
        if (li.v[i] > mx)
        {
            mx = li.v[i];
        }
    }
    return mx;
}
void countSort(SqList &li, int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; ++i)
    {
        count[(li.v[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; --i)
    {
        output[count[(li.v[i] / exp) % 10] - 1] = li.v[i];
        count[(li.v[i] / exp) % 10]--;
    }
    for (i = 0; i < n; ++i)
    {
        li.v[i] = output[i];
    }
}
void SortAlgorithm::radixSort(SqList &li)
{
    int n = li.v.size();
    int m = getMax(li, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(li, n, exp);
    }
}

//第11种：桶排序
void SortAlgorithm::bucketSort(SqList &li)
{
    // int n = li.v.size();
    // vector<float> b[n];

    // for (int i = 0; i < n; i++)
    // {
    //     int bi = n * li.v[i];
    //     b[bi].push_back(li.v[i]);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     sort(b[i].begin(), b[i].end());
    // }

    // int index = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < b[i].size(); j++)
    //     {
    //         li.v[index++] = b[i][j];
    //     }
    // }
}

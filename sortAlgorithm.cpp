#include "sortAlgorithm.h"

//最简单的冒泡排序
void SortAlgorithm::bubbleSort_1(SqList li)
{
    int i, j;
    for (i = 1; i < li.v.size(); ++i)
    {
        for (j = i + 1; j < li.v.size(); ++j)
        {
            if (li.v[i] < li.v[j])
            {
                li.swap(li.v[i], li.v[j]);
            }
        }
    }
}
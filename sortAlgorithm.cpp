#include "sortAlgorithm.h"

//最简单的排序
void SortAlgorithm::bubbleSort_1(SqList &li)
{
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
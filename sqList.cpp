#include "sqList.h"
#include <iostream>

//交换元素
void SqList::swap(int i, int j)
{
    int temp = this->r[i];
    this->r[i] = this->r[j];
    this->r[j] = temp;
}
//打印
void SqList::printR()
{
    for (int i : this->r)
    {
        cout << this->r[i] << " ";
    }
    cout << endl;
}
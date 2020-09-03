#include "sqList.h"
#include <iostream>
using namespace std;

//交换元素
void SqList::swap(int i, int j)
{
    int temp = this->v[i];
    this->v[i] = this->v[j];
    this->v[j] = temp;
}
//打印
void SqList::printR()
{
    for (auto i : this->v)
    {
        cout << i << " ";
    }
    cout << endl;
}
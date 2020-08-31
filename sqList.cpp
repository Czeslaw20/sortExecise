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
    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    // {
    //     cout << *it << " ";
    // }
    for (auto i : this->v)
    {
        cout << i << " ";
        //使用范围for循环时，i本身就是v中的元素
    }
    cout << endl;
}
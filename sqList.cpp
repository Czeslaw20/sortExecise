#include "sqList.h"
#include <iostream>
#include <random>
#include <chrono>
using namespace std;

static default_random_engine e;
static uniform_int_distribution<unsigned> u(0, 150);

//生成随机数组
void SqList::genRandomList()
{
    v.clear();

    //设置毫秒级随机数种子
    auto timeNow = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    e.seed(timeNow.count());

    for (int i = 0; i < 30; i++)
    {
        int num = u(e);
        v.push_back(num);
    }
}

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
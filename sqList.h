#pragma once
#include <vector>
using namespace std;

class SqList
{
public:
    vector<int> v;

    //生成随机数组
    void genRandomList();
    //交换元素
    void swap(int i, int j);
    //打印数组
    void printR();
};
#pragma once
const int MAXSIZE = 10;
class SqList
{
public:
    int r[MAXSIZE + 1];
    //用于存储要排序数组，r[0]用作哨兵或临时变量
    int length;
    //用于记录顺序表的长度

    //交换元素
    void swap(int i, int j);
    //打印数组
    void printR();
};
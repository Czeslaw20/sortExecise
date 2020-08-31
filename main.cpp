#include <iostream>
using namespace std;
#include "sortAlgorithm.h"
#include <unistd.h>

void test01()
{
    SqList li;
    li.v = {5, 7, 9, 3, 8, 0, 4, 1, 6, 2};
    li.printR();

    SortAlgorithm sort;

    //第1种：最简单的冒泡排序
    sort.bubbleSort_1(li);

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
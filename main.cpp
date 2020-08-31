#include <iostream>
using namespace std;
#include "sortAlgorithm.h"

void test01()
{
    SqList li;
    li.v = {5, 7, 9, 3, 8, 0, 4, 1, 6, 2};
    li.printR();

    SortAlgorithm bub_1;
    bub_1.bubbleSort_1(li);

    li.printR();
}

int main()
{
    test01();

    return EXIT_SUCCESS;
}
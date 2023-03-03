#include <iostream>
#include "HeapSort.h"

using namespace std;

int main()
{
    int *a = new int[11]{0, 3, 9, 2, 0, 4, 5, 6, 7, 1, 8};

    PrintArr<int>(a, 11);
    HeapSort<int>(a, 11);
    PrintArr<int>(a, 11);

    system("pause");
    return 0;
}
#include "HeapSort.h"
#include <iostream>

template<class T>
void PrintArr(T *a, const int n)
{
    std::cout << a[0];
    for(int i = 1; i < n; i++)
    {
        std::cout << ' ' << a[i];
    }
    std::cout << std::endl;
}

template<class T>
void Adjust(T *a, const int root, const int n)
{
	T e = a[root]; // tree是存放node的array
	int j;
    for(j = 2 * root; j <= n; j *= 2) // 應該是因為這樣的撰寫方式，我們資料從arr的index=1開始放。
	{
		if(j < n && a[j] < a[j + 1]) j++;
        if(e >= a[j]) break;
        a[j / 2] = a[j];
	}
    a[j / 2] = e;
}

template<class T>
void HeapSort(T *a, const int n)
{
    for(int i = n / 2; i >= 1; i--)
    {
        Adjust(a, i, n);
    }
    
    int tmp;

    for(int i = n - 1; i >= 1; i--)
    {
        // swap(a[1], a[i + 1]);
        tmp = a[1];
        a[1] = a[i + 1];
        a[i + 1] = tmp;

        Adjust(a, 1, i);
    }
}


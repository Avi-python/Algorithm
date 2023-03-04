#ifndef HEAPSORT_H
#define HEAPSORT_H

template<class T>
void PrintArr(T *a, const int n);

template<class T> 
void Adjust(T *a, const int root, const int n);

template<class T>
void HeapSort(T *a, const int n);

#include "HeapSort_impl.h"

#endif
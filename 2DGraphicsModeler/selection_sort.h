#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include "shape.h"
#include <utility>
#include "vector.h"
template<class T>
void selectionSort(T first,T last)
{
    T i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (T i = first; i < last-1; ++i)
    {
        min_idx = i;
        for (j = i +1; j!=last; j++)
            if(**j<**min_idx)
                min_idx= j;
        mySwap(min_idx,i);
    }
}

template<class T, class H>
void selectionSort(T first,T last,H pred)
{
    T i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (T i = first; i < last-1; ++i)
    {
        //find min element in this range
        min_idx = i;
        for (j = i +1; j!=last; j++)
        {
            if(pred(*j,*min_idx))
                min_idx= j;
        }
        mySwap(min_idx,i);
    }
}
template<class T>
void mySwap(T x, T y)
{
    auto temp = *x;
    *x = *y;
    *y = temp;
}
#endif // SELECTION_SORT_H

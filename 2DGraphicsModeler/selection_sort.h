#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include "shape.h"
#include <utility>
#include "vector.h"
template<class T, class H>
void selectionSort(T first,T last,H pred)
{
    for (T i = first; i < last; ++i) {
        for (T j = i; j < last-2; ++j)
        {
            if((*j<*(j+1)))
            {

            }
            else
            {
                 std::swap(*j,*(j+1));
            }
        }
    }
}
#endif // SELECTION_SORT_H

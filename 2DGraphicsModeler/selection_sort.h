#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include "shape.h"
#include "vector.h"
template<class T>
void selectionSort(T* itertatorFirst,T* iteratorLast, bool *compFunc(T* arg1,T* arg2))
{
    for (T* i = itertatorFirst; i != iteratorLast; i++) {
        for (T* j = itertatorFirst; j != iteratorLast; j++) {
           if(compFunc(i,j))
               i=j;
        }
    }
}

template <class T>
class compare_shape_perimeter
{
public:
    compare_shape_perimeter(custom::vector<T> shapeVector);
    bool operator()(T* arg1, T* arg2)
    {
        return arg1 <= arg2;
    }
//selectionSort (x.begin(),x.end(),compare_shape_perimeter(x))

};
#endif // SELECTION_SORT_H

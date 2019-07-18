#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

template<class T>
void SelectionSort(T* itertatorFirst,T* iteratorLast, bool *compFunc(T* arg1,T* arg2))
{
    for (T* i = itertatorFirst; i != iteratorLast; i++) {
        for (T* j = itertatorFirst; j != iteratorLast; j++) {
           if(compFunc(i,j))
               i=j;
        }
    }
}

template <class T>
bool compare_shape_perimeter(T* arg1, T* arg2)
{
    arg1!=arg2;


}
#endif // SELECTION_SORT_H

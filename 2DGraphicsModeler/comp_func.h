#ifndef COM_FUNC_H
#define COM_FUNC_H
#include "shape.h"
class compare_shape_perimeter
{
public:
    bool operator()(Shape* x,Shape* y){ return x->area() < y->area();}
private:
};

class compare_shape_area
{
public:
    bool operator()(Shape* x,Shape* y){ return x->perimeter() < y->perimeter();}
private:
};
#endif // COM_FUNC_H

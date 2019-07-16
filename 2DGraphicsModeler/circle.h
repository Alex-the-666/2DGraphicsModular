#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"


class Circle : public Ellipse
{
public:
    Circle()=delete;
    Circle(QPaintDevice * parent,ShapeBuffer);
    ~Circle() override {}
    void setDimension(int x, int y, int r1, int r2);
    double area() const override;
    double perimeter() const override;
};

#endif // CIRCLE_H

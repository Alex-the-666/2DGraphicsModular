#ifndef POLYLINE_H
#define POLYLINE_H
#include "shape.h"

class Polyline : public Shape
{
public:
    Polyline()=delete;
    Polyline(QPaintDevice * parent,ShapeBuffer );
    void draw(const int x, const int y) override;
    void move(const int x, const int y)override;
    double area() const override;
    double perimeter() const override;


private:
    custom::vector<QPoint> qPointVector;
};

#endif // POLYLINE_H

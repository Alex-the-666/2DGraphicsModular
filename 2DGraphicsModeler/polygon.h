#ifndef POLYGON_H
#define POLYGON_H


#include "shape.h"
#include <cmath>
class Polygon : public Shape
{
public:
    Polygon() = delete;
    Polygon(QPaintDevice * parent, const ShapeBuffer& buffer );
    void draw(const int x, const int y) override;
    void move(const int x, const int y)override;
    double area() const override;
    double perimeter() const override;


private:
    QPolygon polygon;
};




#endif // POLYGON_H

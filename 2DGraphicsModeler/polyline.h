#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"



class PolyLine: public Shape
{
public:
    PolyLine() = delete;

    PolyLine(QPaintDevice *parent, ShapeBuffer arg);

    virtual ~PolyLine()override;

    void setDimension(int x, int y);

    void draw (const int x, const int y)override;
    void move(int x, int y) override;
    double area() const override;
    double perimeter() const override;

private:
    QPolygon qPolygon;
};



#endif // POLYLINE_H

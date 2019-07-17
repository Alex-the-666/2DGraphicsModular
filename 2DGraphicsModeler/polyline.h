#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"


class PolyLine: public Shape
{
public:
    PolyLine() = delete;

    PolyLine(const ShapeBuffer& arg);

     ~PolyLine() override {}

    void draw (const int x, const int y)override;
    void draw () override;
    void move(int x, int y) override;
    double area() const override;
    double perimeter() const override;
    void drawID();

private:
    QPolygon qPolygon;
    QString stringID;
};



#endif // POLYLINE_H

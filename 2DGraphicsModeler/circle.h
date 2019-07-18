#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"


class Circle : public Ellipse
{
public:
    Circle():Ellipse(){setShape(CIRCLE);}
    Circle(const ShapeBuffer&);
    ~Circle() override {}
    void setDimension(int x, int y, int r1, int r2);
    void draw(const int x, const int y) override;
    void draw()override;
    void move(const int x, const int y) override;
    double area() const override;
    double perimeter() const override;
};

#endif // CIRCLE_H

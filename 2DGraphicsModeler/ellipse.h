#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

class Ellipse : public Shape
{
public:
    Ellipse():Shape(){setShape(ELLIPSE);}
    Ellipse(const ShapeBuffer&);
    ~Ellipse() override {}
    void setDimension(int x, int y, int r1, int r2);
    void draw(const int x, const int y) override;
    void draw()override;
    void move(const int x, const int y) override;
    double area() const override;
    double perimeter() const override;


protected:
    int radius1;
    int radius2;
    int x;
    int y;
    QRect myRect;
};

#endif // ELLIPSE_H

#include "circle.h"
#include <QtMath>

Circle::Circle(const ShapeBuffer& arg): Ellipse(arg)
{
    radius2 = radius1;
}

void Circle::setShapeBuffer(ShapeBuffer &temp)
{
   Ellipse::setShapeBuffer(temp);
}

void Circle::draw(const int x, const int y)
{
    Ellipse::draw(x,y);
}

void Circle::draw()
{
    Ellipse::draw();
}

void Circle::move(const int x, const int y)
{
    Ellipse::move(x,y);
}

double Circle::perimeter() const
{
    return 2 * M_PI * radius1;
}

double Circle::area() const
{
    return M_PI * radius1 * radius1;
}



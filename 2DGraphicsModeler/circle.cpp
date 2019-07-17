#include "circle.h"
#include <QtMath>

Circle::Circle(const ShapeBuffer& arg): Ellipse(arg)
{
    radius2 = radius1;
}

void Circle::draw(const int, const int)
{
    passQPainter(nullptr);
}

void Circle::draw()
{
    passQPainter(nullptr);
}

void Circle::move(const int x, const int y)
{

}

double Circle::perimeter() const
{
    return 2 * M_PI * radius1;
}

double Circle::area() const
{
    return M_PI * radius1 * radius1;
}



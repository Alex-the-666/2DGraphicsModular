#include "ellipse.h"
#include <QtMath>


Ellipse::Ellipse(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
{
    x = arg.qRect.x();
    y = arg.qRect.x();
    radius1 = arg.qRect.width();
    radius2 = arg.qRect.height();
}

void Ellipse::draw(const int x, const int y)
{
    QPainter& painter = getQPainter();
    painter.drawEllipse(x, y, radius1, radius2);
}

void Ellipse::move(const int x, const int y)
{
    if(radius1 + x < 1000 && radius1 + y < 500 &&\
       radius2 + x < 1000 && radius2 + y < 500 )
    {
        this -> x = x;
        this -> y = y;
    }
}

double Ellipse::perimeter() const
{
    return M_PI * ((3 *(radius1 + radius2)) - sqrt((3*radius1 + radius2)*(radius1 + (3 * radius2))));
}

double Ellipse::area() const
{
    return M_PI * radius1 * radius2;
}

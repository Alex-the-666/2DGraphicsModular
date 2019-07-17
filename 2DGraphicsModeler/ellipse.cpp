#include "ellipse.h"
#include <QtMath>

// Arthur: For the constructor, I only need a qRect
Ellipse::Ellipse(const ShapeBuffer& arg): Shape(arg)
{
    QRect qRect = arg.getQRect();
    x = qRect.x();
    y = qRect.x();
    radius1 = qRect.width();
    radius2 = qRect.height();
}

void Ellipse::draw(const int x, const int y)
{
    /*
    QPainter& painter = getQPainter();
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawEllipse(x, y, radius1, radius2);
    painter.end();*/
}
void Ellipse::draw()
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->drawEllipse(x, y, radius1, radius2);
    passQPainter(nullptr);
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

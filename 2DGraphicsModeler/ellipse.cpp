#include "ellipse.h"
#include <QtMath>

// Arthur: For the constructor, I only need a qRect
Ellipse::Ellipse(const ShapeBuffer& arg): Shape(arg)
{
    myRect = arg.getQRect();
    QRect qRect = arg.getQRect();
    x = qRect.x();
    y = qRect.x();
    radius1 = qRect.width();
    radius2 = qRect.height();

    stringID = QString::number(arg.getShapeID());
}

void Ellipse::draw(const int, const int)
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    //getQPainter()->drawEllipse(x, y, radius1, radius2);
    getQPainter()->drawEllipse(myRect);
    passQPainter(nullptr);
}
void Ellipse::draw()
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    //getQPainter()->drawEllipse(x, y, radius1, radius2);
    drawID();
    getQPainter()->drawEllipse(myRect);
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

void Ellipse::drawID()
{
    const int VERTICAL_BUFFER = 5;
    getQPainter()->drawText(x, y - VERTICAL_BUFFER, stringID);
}

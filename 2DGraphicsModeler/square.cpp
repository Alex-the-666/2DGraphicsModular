#include "square.h"

Square::Square(const ShapeBuffer& arg): Shape(arg)
{
    QRect qRect = arg.getQRect();
    side = qRect.width();
    side = qRect.height();

    _x = qRect.x();
    _y = qRect.y();
}
void Square::draw(const int, const int)
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->drawRect(_x,_y,side,side);
    passQPainter(nullptr);
}

void Square::draw()
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->drawRect(_x,_y,side,side);
    passQPainter(nullptr);
}

double Square::area() const
{
    return side*side;
}

void Square::move(int x, int y)
{
    if ((0.5*side + x) > 1000 || (0.5*side + y) > 500 )
    {
       _x = x;
       _y = y;
    }
}

double Square::perimeter() const
{
    double perimeter;
    perimeter = 0;

    perimeter =  side + side + side +side;

    return perimeter;
}



#include "square.h"

Square::Square(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
{
    side = arg.qRect.width();
    side = arg.qRect.height();


    _x = arg.qRect.x();
    _y = arg.qRect.y();
}
void Square::draw(const int, const int)
{
    QPainter& painter = getQPainter();
        setPen(Qt::black,4,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin);
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawRect(_x,_y,side,side);
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



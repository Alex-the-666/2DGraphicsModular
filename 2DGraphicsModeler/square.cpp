#include "square.h"

Square::Square(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
{
    QRect qRect = arg.getQRect();
    side = qRect.width();
    side = qRect.height();


    _x = qRect.x();
    _y = qRect.y();
}
void Square::draw(const int, const int)
{
    QPainter& painter = getQPainter();
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawRect(_x,_y,side,side);
    painter.end();
}

void Square::draw(QPaintDevice * parent)
{
    QPainter& painter = getQPainter();
    painter.begin(parent);
    setPen(Qt::red,4,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin);
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawRect(_x,_y,side,side);
    painter.end();

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



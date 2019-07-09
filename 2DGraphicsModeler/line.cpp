#include "line.h"

Line::Line(QPaintDevice *parent): Shape(parent),\
    one(0,0), two(100,100)
{

}

Line::Line(QPaintDevice* parent, ShapeType arg, Qt::GlobalColor gc1, double width,\
           Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
           Qt::GlobalColor gc2, Qt::BrushStyle bs):\
    Shape(parent, arg, gc1, width,\
          ps, pcs, pjs,\
          gc2, bs),\
    one(0,0), two(100,100)
{}

Line::Line(QPaintDevice *parent, ShapeType arg,\
           QPen rhsPen, QBrush rhsBrush):\
        Shape(parent,arg,rhsPen,rhsBrush),\
        one(0,0), two(100,100)
{}

Line::~Line()

{

}

void Line::setDimension(int x, int y, int x2, int y2)
{
    one.setX(x);
    one.setY(y);
    two.setX(x2);
    two.setY(y2);
}

void Line::draw(const int x, const int y)
{
    QPainter& painter = getQPainter();
    painter.drawLine(one,two);

}

void Line::move(int x, int y)
{
    "I do nothing right now XD";
}

double Line::area() const
{
    return 0;
}

double Line::perimeter() const
{
    return sqrt(QPoint::dotProduct(one,two));
}

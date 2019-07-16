#include "line.h"
#include <cmath>

Line::Line(QPaintDevice *parent,\
           const ShapeBuffer& buffer): Shape(parent, buffer)
{
    //Sanity Check here
    if(buffer.getShape()==LINE)
    {
        one = buffer.getQPointOne();
        two = buffer.getQPointTwo();
    }
    else {
        //should throw an exception here
    }
}

Line::~Line()

{

}

QPoint Line::getQPointOne() const
{
    return one;
}

QPoint Line::getQPointTwo() const
{
 return two;
}

void Line::draw(const int, const int)
{
    QPainter& painter = getQPainter();
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawLine(one,two);
    painter.end();
}

void Line::draw(QPaintDevice * parent)
{
    QPainter& painter = getQPainter();
    painter.begin(parent);
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawLine(one,two);
    painter.end();
}

void Line::move(int x, int y)
{
    if(one.x()+x<1000 && one.y()+y< 500 &&\
        two.x()+x<1000 && two.y()+y<500 )
    {
        one.setX(one.x()+x);
        one.setY(one.y()+y);
        one.setX(one.x()+x);
        one.setY(one.y()+y);
    }
}

double Line::area() const
{
    return 0;
}

double Line::perimeter() const
{
    return sqrt(QPoint::dotProduct(one,two));
}

#include "line.h"
#include <cmath>

Line::Line(const ShapeBuffer& buffer): Shape(buffer)
{
    //Sanity Check here
    if(buffer.getShape()==LINE)
    {
        one = buffer.getQPointOne();
        two = buffer.getQPointTwo();
        stringID = QString::number(buffer.getShapeID());
    }
    else {
        //should throw an exception here
    }
}

Line::~Line()

{

}

void Line::setShapeBuffer(ShapeBuffer & temp)
{
    Shape::setShapeBuffer(temp);
    temp.one = one;
    temp.two = two;
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
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->drawLine(one,two);
}

void Line::draw()
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    drawID();
    getQPainter()->drawLine(one,two);
    passQPainter(nullptr);
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

void Line::drawID()
{
    //! Int variables that hold the coordinates for left most point of the object
    int leftmostPoint;  /*! < leftmostpoint holds the x- axis value*/
    int upmostPoint;    /*! < upmostPoint holds the y- axis value*/

    const int VERTICAL_BUFFER = 5; /*! <Vertical Buffer for Drawing ID*/

    one.rx() < two.rx()? leftmostPoint = one.rx() : leftmostPoint = two.rx();
    one.ry() < two.ry()? upmostPoint = one.ry() : upmostPoint = two.ry();
    getQPainter()->drawText(leftmostPoint, upmostPoint - VERTICAL_BUFFER, stringID);
}

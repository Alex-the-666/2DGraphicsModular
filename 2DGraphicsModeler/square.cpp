#include "square.h"

Square::Square(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
{


}

void Square::draw(const int, const int)
{
    QPainter& painter = getQPainter();
    //painter.draw
}

double Square::area() const
{
    return 0;
}

void Square::move(int x, int y)
{
    bool allowMove = true;

//        if ((qPolygon.point(i).x() + x) > 1000 || (qPolygon.point(i).y() + y > 500))
//        {
//            allowMove = false;
//        }


    if (allowMove)
    {
        //qPolygon.translate(x,y);
    }
}


double Square::perimeter() const
{
    double perimeter;
    perimeter = 0;

    return perimeter;
}



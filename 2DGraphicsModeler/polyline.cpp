#include "polyline.h"
#include "vector.h"




polyLine::polyLine(QPaintDevice *parent): Shape(parent)
{

}

polyLine::polyLine(QPaintDevice* parent, ShapeType arg, Qt::GlobalColor gc1, double width,\
           Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
           Qt::GlobalColor gc2, Qt::BrushStyle bs):
    Shape(parent, arg, gc1, width,
          ps, pcs, pjs,
          gc2, bs)
{

}


polyLine::polyLine(QPaintDevice *parent, ShapeType arg,\
           QPen rhsPen, QBrush rhsBrush):\
        Shape(parent,arg,rhsPen,rhsBrush)

{

}
void polyLine::set_point(const QPoint& point)
{


 //shapeDimensions.push_back(point);
}

polyLine::~polyLine()

{

}

void polyLine::setDimension(int x, int y)
{
   // shapeDimensions.push_back(QPoint(x,y));
}

 void polyLine::draw(const int x, const int y,)
{
    QPainter& painter = getQPainter();


    painter.drawPolyline(const QPointF * points, int pointCount);



}

void polyLine::move(const int x, const int y)
{
}

double polyLine::area() const
{
    return 0;
}

double polyLine::perimeter() const
{

}

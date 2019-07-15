#include "polyline.h"
#include "vector.h"




PolyLine::PolyLine(QPaintDevice *parent): Shape(parent)
{

}

PolyLine::PolyLine(QPaintDevice* parent, ShapeType arg, Qt::GlobalColor gc1, double width,\
           Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
           Qt::GlobalColor gc2, Qt::BrushStyle bs):
    Shape(parent, arg, gc1, width,
          ps, pcs, pjs,
          gc2, bs)
{

}


PolyLine::PolyLine(QPaintDevice *parent, ShapeType arg,\
           QPen rhsPen, QBrush rhsBrush):\
        Shape(parent,arg,rhsPen,rhsBrush)

{
}



Polyline::Polyline(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
{
 //   qPolygon = arg.qPolygon;
test=4;
}


PolyLine::~PolyLine()

{

}

void PolyLine::setDimension(int, int)
{
   // shapeDimensions.push_back(QPoint(x,y));
}

 void PolyLine::draw(const int, const int)
{
    QPainter& painter = getQPainter();
    painter.drawPolyline(qPolygon);
}

void PolyLine::move(const int x, const int y)
{
}

double PolyLine::area() const
{
    return 0;
}

double PolyLine::perimeter() const
{
    return 0;

}

void Polyline::draw(const int, const int)
{


}

void Polyline::move(const int, const int)
{

}

double Polyline::area() const
{

}

double Polyline::perimeter() const
{

}



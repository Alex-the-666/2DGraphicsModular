#include "polyline.h"
#include "vector.h"




//polyLine::polyLine(QPaintDevice *parent): Shape(parent)
//{

////}
//Polyline::Polyline(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
//{
//    poly = arg.qPolygon;
//}


polyLine::polyLine(QPaintDevice* parent, ShapeType arg, Qt::GlobalColor gc1, double width,\
           Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
           Qt::GlobalColor gc2, Qt::BrushStyle bs):
    Shape(parent, arg, gc1, width,
          ps, pcs, pjs,
          gc2, bs)
{

}


polyLine::polyLine(QPaintDevice *parent, ShapeType arg,\
           QPen rhsPen, QBrush rhsBrush, QPolygon poly):\
        Shape(parent,arg,rhsPen,rhsBrush)

{
  poly = arg.qPolygon;
}
void polyLine::set_point(const QPoint& point)
{


 //QPolygonpush_back(point);
}

polyLine::~polyLine()

{

}

void polyLine::setDimension(int x, int y)
{
   // shapeDimensions.push_back(QPoint(x,y));
}

void polyLine::draw(const int x, const int y)
{
    QPainter& painter = getQPainter();


        QPolygon poly;

//        poly << QPoint(0, 85) << QPoint(75, 75)
//             << QPoint(100, 10) << QPoint(125, 75)
//             << QPoint(200, 85) << QPoint(150, 125);

   painter.drawPolyline(poly);

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
return 0;
}

//Polyline::Polyline(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
//{
//    poly = arg.qPolygon;
//}

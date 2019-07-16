#include "polyline.h"
#include "vector.h"




PolyLine::PolyLine(QPaintDevice *parent): Shape(parent)
{

//Polyline::Polyline(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
//{
//    poly = arg.qPolygon;
//}
}


PolyLine::PolyLine(QPaintDevice *parent, ShapeType arg,\
           QPen rhsPen, QBrush rhsBrush):\
        Shape(parent,arg,rhsPen,rhsBrush)

{



Polyline::Polyline(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
{
 //   qPolygon = arg.qPolygon;
test=4;
 //QPolygonpush_back(point);
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
void polyLine::draw(const int x, const int y)
{
    QPainter& painter = getQPainter();


//        poly << QPoint(0, 85) << QPoint(75, 75)
//             << QPoint(100, 10) << QPoint(125, 75)
//             << QPoint(200, 85) << QPoint(150, 125);

   painter.drawPolyline(poly);

}

void Polyline::move(const int, const int)
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

double polyLine::perimeter() const
{
    double perimeter;
    perimeter = 0;
    for (int i = 0; i < poly.size(); i++)
    {
        perimeter += sqrt((((poly.point((i + 1) % poly.size()).rx()) - poly.point(i).rx())
                         * ((poly.point((i + 1) % poly.size()).rx()) - poly.point(i).rx()))
                        + (((poly.point((i + 1) % poly.size()).ry()) - poly.point(i).ry())
                         * ((poly.point((i + 1) % poly.size()).ry()) - poly.point(i).ry())));
    }
    return perimeter;
}


//Polyline::Polyline(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
//{

//    qPointArray = new QPoint[3];
//}



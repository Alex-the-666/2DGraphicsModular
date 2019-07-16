#include "polyline.h"
#include "vector.h"





//Polyline::Polyline(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
//{
//    poly = arg.qPolygon;
//}


polyLine::polyLine(QPaintDevice* parent, ShapeType arg, Qt::GlobalColor gc1, double width,\
           Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
           Qt::GlobalColor gc2, Qt::BrushStyle bs, QPolygon poly,const ShapeBuffer &buff):
    Shape(parent, arg, gc1, width,
          ps, pcs, pjs,
          gc2, bs)
{
poly = buff.qPolygon;
}


polyLine::polyLine(QPaintDevice *parent, ShapeType arg,\
           QPen rhsPen, QBrush rhsBrush, QPolygon poly,const ShapeBuffer &buff):\
        Shape(parent,arg,rhsPen,rhsBrush)

{
  poly = buff.qPolygon;
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


//        poly << QPoint(0, 85) << QPoint(75, 75)
//             << QPoint(100, 10) << QPoint(125, 75)
//             << QPoint(200, 85) << QPoint(150, 125);

   painter.drawPolyline(poly);

}

void polyLine::move(int x, int y)
{
    bool allowMove = true;
    for (int i = 0; i < poly.size(); i++)
    {
        if ((poly.point(i).rx() + x) > 1000 || (poly.point(i).ry() + y > 500))
        {
            allowMove = false;
        }
    }

    if (allowMove)
    {
        poly.translate(x,y);
    }
}

double polyLine::area() const
{
    return 0;
}

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



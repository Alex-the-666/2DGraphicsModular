#include "polyline.h"

PolyLine::PolyLine(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
{
    qPolygon = arg.qPolygon;
    qPolygon << QPoint(0, 85) << QPoint(75, 75)
            << QPoint(100, 10) << QPoint(125, 75)
            << QPoint(200, 85) << QPoint(150, 125)
            << QPoint(160, 190) << QPoint(100, 150)
            << QPoint(40, 190) << QPoint(50, 125)\
            << QPoint(0, 85);

}

void PolyLine::draw(const int, const int)
{
    QPainter& painter = getQPainter();

    painter.drawPolyline(qPolygon);
}

double PolyLine::area() const
{
    return 0;
}

//void PolyLine::setDimensions(int x, int y)
//{
// qPolygon.putPoints(;
void PolyLine::draw(QPaintDevice * x)
{
    QPainter& painter = getQPainter();
    painter.begin(x);

    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawPolyline(qPolygon);
    painter.end();


}
//}
void PolyLine::move(int x, int y)
{
    bool allowMove = true;
    for (int i = 0; i < qPolygon.size(); i++)
    {
        if ((qPolygon.point(i).x() + x) > 1000 || (qPolygon.point(i).y() + y > 500))
        {
            allowMove = false;
        }
    }

    if (allowMove)
    {
        qPolygon.translate(x,y);
    }
}


double PolyLine::perimeter() const
{
    double perimeter;
    perimeter = 0;
    for (int i = 0; i < qPolygon.size(); i++)
    {
        perimeter += sqrt((((qPolygon.point((i + 1) % qPolygon.size()).rx()) - qPolygon.point(i).rx())
                         * ((qPolygon.point((i + 1) % qPolygon.size()).rx()) - qPolygon.point(i).rx()))
                        + (((qPolygon.point((i + 1) % qPolygon.size()).ry()) - qPolygon.point(i).ry())
                         * ((qPolygon.point((i + 1) % qPolygon.size()).ry()) - qPolygon.point(i).ry())));
    }
    return perimeter;
}



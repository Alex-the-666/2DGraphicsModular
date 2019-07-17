#include "polyline.h"

PolyLine::PolyLine(const ShapeBuffer& arg): Shape(arg)
{
    qPolygon = arg.getQPolygon();
    stringID = QString::number(arg.getShapeID());

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
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->drawPolyline(qPolygon);
    passQPainter(nullptr);
}

void PolyLine::draw()
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    drawID();
    getQPainter()->drawPolyline(qPolygon);
    passQPainter(nullptr);
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
    double perimeter = 0;
    for (int i = 0; i < qPolygon.size(); i++)
    {
        perimeter += sqrt((((qPolygon.point((i + 1) % qPolygon.size()).rx()) - qPolygon.point(i).rx())
                         * ((qPolygon.point((i + 1) % qPolygon.size()).rx()) - qPolygon.point(i).rx()))
                        + (((qPolygon.point((i + 1) % qPolygon.size()).ry()) - qPolygon.point(i).ry())
                         * ((qPolygon.point((i + 1) % qPolygon.size()).ry()) - qPolygon.point(i).ry())));
    }
    return perimeter;
}

void PolyLine::drawID()
{
    int leftmostPoint = qPolygon.point(0).rx();
    int upmostPoint = qPolygon.point(0).ry();

    for (int i = 1; i < qPolygon.size(); i++)
    {
        if (qPolygon.point(i).rx() < leftmostPoint)
        {
            leftmostPoint = qPolygon.point(i).rx();
        }

        if (qPolygon.point(i).ry() < upmostPoint)
        {
            upmostPoint = qPolygon.point(i).ry();
        }

    }
    getQPainter()->drawText(leftmostPoint, upmostPoint - 5, stringID);
}



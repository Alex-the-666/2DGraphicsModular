#include "polyline.h"

PolyLine::PolyLine():Shape(), qPolygon(G_DEFAULTQRECT)
{
    setShape(POLYLINE);

}
PolyLine::PolyLine(const ShapeBuffer& arg): Shape(arg)
{
    qPolygon = arg.getQPolygon();
    stringID = QString::number(arg.getShapeID());
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
    const int VERTICAL_BUFFER = 5;
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
    getQPainter()->drawText(leftmostPoint, upmostPoint - VERTICAL_BUFFER, stringID);
}



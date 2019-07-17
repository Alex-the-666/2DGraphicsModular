#include "polyline.h"

PolyLine::PolyLine(const ShapeBuffer& arg): Shape(arg)
{
    qPolygon = arg.getQPolygon();
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



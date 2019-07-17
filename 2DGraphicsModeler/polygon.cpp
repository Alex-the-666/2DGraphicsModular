#include "polygon.h"

Polygon::Polygon(const ShapeBuffer& buffer)
        : Shape(buffer)
{
    polygon = buffer.getQPolygon();
    stringID = QString::number(buffer.getShapeID());
}

void Polygon::draw(const int, const int)
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->drawPolygon(polygon);
    passQPainter(nullptr);
}

void Polygon::draw()
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    drawID();
    getQPainter()->drawPolygon(polygon);
    passQPainter(nullptr);

}

void Polygon::move(int x, int y)
{
    bool allowMove = true;
    for (int i = 0; i < polygon.size(); i++)
    {
        if ((polygon.point(i).rx() + x) > 1000 || (polygon.point(i).ry() + y > 500))
        {
            allowMove = false;
        }
    }

    if (allowMove)
    {
        polygon.translate(x,y);
    }
}

double Polygon::area() const
{
      double area;
      area = 0;
      int j = polygon.size() - 1;

      for (int i=0; i < polygon.size(); i++)
      {
          area += (polygon.point(j).rx()+polygon.point(i).rx()) * (polygon.point(j).ry()-polygon.point(i).ry());
          j = i;
      }
      return area/2;
}

double Polygon::perimeter() const
{
    double perimeter;
    perimeter = 0;
    for (int i = 0; i < polygon.size(); i++)
    {
        perimeter += sqrt((((polygon.point((i + 1) % polygon.size()).rx()) - polygon.point(i).rx())
                         * ((polygon.point((i + 1) % polygon.size()).rx()) - polygon.point(i).rx()))
                        + (((polygon.point((i + 1) % polygon.size()).ry()) - polygon.point(i).ry())
                         * ((polygon.point((i + 1) % polygon.size()).ry()) - polygon.point(i).ry())));
    }

    return 0;

}

void Polygon::drawID()
{
    int leftmostPoint = polygon.point(0).rx();
    int upmostPoint = polygon.point(0).ry();

    for (int i = 1; i < polygon.size(); i++)
    {
        if (polygon.point(i).rx() < leftmostPoint)
        {
            leftmostPoint = polygon.point(i).rx();
        }

        if (polygon.point(i).ry() < upmostPoint)
        {
            upmostPoint = polygon.point(i).ry();
        }

    }
    getQPainter()->drawText(leftmostPoint, upmostPoint - 5, stringID);
}

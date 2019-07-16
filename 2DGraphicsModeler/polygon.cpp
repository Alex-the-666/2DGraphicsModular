#include "polygon.h"

Polygon::Polygon(QPaintDevice * parent, const ShapeBuffer& buffer)
        : Shape(parent, buffer)
{
    polygon = buffer.getQPolygon();
}

void Polygon::draw(const int, const int)
{
    QPainter& painter = getQPainter();
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawPolygon(polygon);
    painter.end();
}

void Polygon::draw(QPaintDevice* x)
{
    QPainter& painter = getQPainter();
    painter.begin(x);
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawPolygon(polygon);
    painter.end();

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

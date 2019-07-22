#include "polygon.h"

Polygon::Polygon(const ShapeBuffer& buffer)
        : Shape(buffer)
{
    polygon = buffer.getQPolygon();
    stringID = QString::number(buffer.getShapeID());
}

void Polygon::setShapeBuffer(ShapeBuffer &temp)
{
    Shape::setShapeBuffer(temp);
    temp.qPolygon = polygon;
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
    /*VECTOR TO STORE DISTANCES RELATIVE TO STARTING POINT*/
    QPolygon relDistance;

    for (int i = 0; i < polygon.size() - 1; ++i)
        relDistance << QPoint(polygon.point(i+1) - polygon.point(0));

    /*RESETTING STARTING POINT OF SHAPE TO COORDINATES IN PARAMETER*/
    polygon.setPoint(0,QPoint (x,y));

    /*RESETTING ALL OTHER POINTS OF SHAPE RELATIVE TO STARTING POINT*/
    for (int i = 0; i < relDistance.size(); ++i)
        polygon.setPoint ((i + 1), QPoint (polygon.point (0) + relDistance.point(i)));
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
      return abs(area/2);
}

int Polygon::getX() const {
    return polygon.point(0).rx();
}

int Polygon::getY() const {
    return polygon.point(0).ry();
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

    return perimeter;

}

void Polygon::drawID()
{
    const int VERTICAL_BUFFER = 5;

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
    getQPainter()->drawText(leftmostPoint, upmostPoint - VERTICAL_BUFFER, stringID);
}

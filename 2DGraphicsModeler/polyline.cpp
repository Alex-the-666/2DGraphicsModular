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

void PolyLine::setShapeBuffer(ShapeBuffer &temp)
{
    Shape::setShapeBuffer(temp);
    temp.qPolygon = qPolygon;
}

void PolyLine::draw(const int, const int)
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->drawPolyline(qPolygon);
    passQPainter(nullptr);
}

int PolyLine::getX() const {
    return qPolygon.point(0).rx();
}

int PolyLine::getY() const {
    return qPolygon.point(0).ry();
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
    /*VECTOR TO STORE DISTANCES RELATIVE TO STARTING POINT*/
    QPolygon relDistance;

    for (int i = 0; i < qPolygon.size() - 1; ++i)
        relDistance << QPoint(qPolygon.point(i+1) - qPolygon.point(0));

    /*RESETTING STARTING POINT OF SHAPE TO COORDINATES IN PARAMETER*/
    qPolygon.setPoint(0,QPoint (x,y));

    /*RESETTING ALL OTHER POINTS OF SHAPE RELATIVE TO STARTING POINT*/
    for (int i = 0; i < relDistance.size(); ++i)
        qPolygon.setPoint ((i + 1), QPoint (qPolygon.point (0) + relDistance.point(i)));
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

    /*testing purposes */
    QString temp = QString::number (leftmostPoint) + " " + QString::number (upmostPoint);

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



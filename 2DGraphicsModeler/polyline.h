#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"



class PolyLine: public Shape
{
public:
    PolyLine() = delete;
    PolyLine (QPaintDevice *parent);

    PolyLine(QPaintDevice *parent, ShapeType arg, QPen rhsPen, QBrush rhsBrush);
    PolyLine(QPaintDevice *parent, ShapeType arg);

    virtual ~PolyLine()override;

    void setDimension(int x, int y);

    void draw (const int x, const int y)override;
    void move(int x, int y) override;
    double area() const override;
    double perimeter() const override;

private:
    QPolygon qPolygon;
    int test;
    QPoint *points;
    int pointsCounter;
    QPolygon poly;

};




//#include "shape.h"

//class Polyline : public Shape
//{
//public:
//    Polyline()=delete;
//    Polyline(QPaintDevice * parent,ShapeBuffer );
//    void draw(const int, const int) override;
//    void move(const int x, const int y)override;
//    double area() const override;
//    double perimeter() const override;


//private:
//    custom::vector<QPoint> qPointVector;

//    QPoint* qPointArray;
//};

#endif // POLYLINE_H

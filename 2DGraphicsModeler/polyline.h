#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"



class PolyLine: public Shape
{
public:
    PolyLine() = delete;
    PolyLine (QPaintDevice *parent);
    polyLine() = delete;
    //polyLine (QPaintDevice *parent);

    PolyLine(QPaintDevice* parent, ShapeType arg, Qt::GlobalColor gc1, double width,\
               Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
               Qt::GlobalColor gc2, Qt::BrushStyle bs, QPolygon poly,const ShapeBuffer &buff);

    PolyLine(QPaintDevice *parent, ShapeType arg, QPen rhsPen, QBrush rhsBrush);
    PolyLine(QPaintDevice *parent, ShapeType arg);
    polyLine(QPaintDevice *parent, ShapeType arg, QPen rhsPen, QBrush rhsBrush, QPolygon poly,const ShapeBuffer &buff);

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

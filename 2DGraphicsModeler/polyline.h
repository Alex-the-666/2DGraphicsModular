#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"



class polyLine: public Shape
{
public:
    polyLine() = delete;
    polyLine (QPaintDevice *parent);

    polyLine(QPaintDevice* parent, ShapeType arg, Qt::GlobalColor gc1, double width,\
               Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
               Qt::GlobalColor gc2, Qt::BrushStyle bs);

    polyLine(QPaintDevice *parent, ShapeType arg, QPen rhsPen, QBrush rhsBrush);

    virtual ~polyLine()override;
    

    void set_point(const QPoint & point);

    void setDimension(int x, int y);

    void draw (const int x, const int y)override;
    void move(int x, int y) override;
    double area() const override;
    double perimeter() const override;

private:
    QPoint *points;

};




#endif // POLYLINE_H

#ifndef LINE_H
#define LINE_H

#include "shape.h"
class Line: public Shape
{
public:
    Line() = delete;
    Line (QPaintDevice *parent);
    Line(QPaintDevice* parent, ShapeType arg, Qt::GlobalColor gc1, double width,\
               Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
               Qt::GlobalColor gc2, Qt::BrushStyle bs);
    Line(QPaintDevice *parent, ShapeType arg,\
         QPen rhsPen, QBrush rhsBrush);
    virtual ~Line()override;

    void setDimension(int x,int y,int x2,int y2);

    void draw (const int x, const int y)override;
    void move(int x, int y) override;
    double area() override;
    double perimeter() override;

private:
    QPoint one,two;
};

#endif // LINE_H

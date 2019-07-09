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
         QPen rhsPen, QBrush rhsBrush):\
        Shape(parent,arg,rhsPen,rhsBrush);
    virtual ~Line();
private:
    QPoint one,two;
};

#endif // LINE_H

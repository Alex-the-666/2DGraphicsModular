#include "line.h"

Line::Line(QPaintDevice *parent): Shape(parent),\
    one(0,0), two(100,100)
{

}

Line::Line(QPaintDevice* parent, ShapeType arg, Qt::GlobalColor gc1, double width,\
           Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
           Qt::GlobalColor gc2, Qt::BrushStyle bs):\
    Shape(parent, arg, gc1, width,\
          ps, pcs, pjs,\
          gc2, bs),\
    one(0,0), two(100,100)
{}

Line::Line(QPaintDevice *parent, ShapeType arg,\
           QPen rhsPen, QBrush rhsBrush):\
        Shape(parent,arg,rhsPen,rhsBrush)
{}

Line::~Line()

{

}

#include "shape.h"

Shape::Shape(): shapeId {0},\
    shape {NONE}, pen(),brush()
{}
Shape::~Shape()
{}
void Shape::setShape(ShapeType rhs)
{
    shape=rhs;
}

void Shape::setPen(Qt::GlobalColor gc, int width, Qt::PenStyle ps,\
                   Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs)
{
    pen.setColor(gc);
    pen.setWidth(width);
    pen.setStyle(ps);
    pen.setCapStyle(pcs);
    pen.setJoinStyle(pjs);
}

void Shape::setBrush(Qt::GlobalColor gc, Qt::BrushStyle bs)
{
    brush.setColor(gc);
    brush.setStyle(bs);
}

void Shape::defaultStyle()
{
    pen.setColor(Qt::black);
    pen.setWidth(0);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::RoundJoin);
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
}

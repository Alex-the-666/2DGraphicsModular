#include "shape.h"

Shape::Shape(QPaintDevice *parent, const ShapeBuffer& buffer):painter(parent)
{
    shape = buffer.getShape();
    shapeId= buffer.getShapeID();
    brush = buffer.getBrush();
    pen = buffer.getPen();
}


Shape::~Shape(){}

ShapeType Shape::getShape() const{
    return shape;
}
const QBrush& Shape::getBrush()const{
    return brush;
}
const QPen& Shape::getPen()const{
    return pen;
}

void Shape::setShape(ShapeType arg){
    shape = arg;
}

void Shape::setPen(Qt::GlobalColor gc, int width,\
                    Qt::PenStyle ps, Qt::PenCapStyle pcs,\
                    Qt::PenJoinStyle pjs)
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


QPainter& Shape::getQPainter()
{
    return painter;
}


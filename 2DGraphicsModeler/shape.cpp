#include "shape.h"
#include <QCursor>

Shape::Shape(const ShapeBuffer & buffer)
{
    painter=  nullptr;
    shape = buffer.getShape();
    shapeId= buffer.getShapeID();
    brush = buffer.getBrush();
    pen = buffer.getPen();
    getCount();
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

QPainter *Shape::getQPainter()
{   
   return painter;
}

int Shape::getCount()

{
    int static count = 0;
    count ++;
    return count;
}

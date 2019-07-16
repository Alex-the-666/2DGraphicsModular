#include "shape.h"

Shape::Shape(QPaintDevice *parent, const ShapeBuffer& buffer):painter(parent)
{
    shape = buffer.shape;
    shapeId= buffer.shapeID;
    brush = buffer.brush;
    pen = buffer.pen;
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
    shape=arg;
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


void Shape::setBrush(QBrush arg)
{
    brush.setColor(arg.color());
    brush.setStyle(arg.style());

}

void Shape::defaultStyle()
{
    pen.setColor(Qt::red);
    pen.setWidth(0);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::RoundJoin);
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
}


QPainter& Shape::getQPainter()
{
    return painter;
}


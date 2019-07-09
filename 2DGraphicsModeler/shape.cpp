#include "shape.h"

Shape::Shape(QPaintDevice* parent): painter(parent)
{}

Shape::~Shape(){}

ShapeType Shape::get_shape() const{
    return shape;
}
const QBrush& Shape::get_brush()const{
    return brush;
}
const QPen& Shape::get_pen()const{
    return pen;
}

void Shape::set_shape(ShapeType arg){
    shape=arg;
}

void Shape::set_pen(Qt::GlobalColor gc, int width,\
                    Qt::PenStyle ps, Qt::PenCapStyle pcs,\
                    Qt::PenJoinStyle pjs)
{
   pen.setColor(gc);
   pen.setWidth(width);
   pen.setStyle(ps);
   pen.setCapStyle(pcs);
   pen.setJoinStyle(pjs);
}


void Shape::set_brush(Qt::GlobalColor gc, Qt::BrushStyle bs)
{
    brush.setColor(gc);
    brush.setStyle(bs);
}

QPainter& Shape::get_qpainter()
{
    return painter;
}



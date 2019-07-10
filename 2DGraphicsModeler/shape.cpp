#include "shape.h"

Shape::Shape(QPaintDevice* parent): painter(parent)
{}

Shape::Shape(QPaintDevice *parent, ShapeType arg,\
             Qt::GlobalColor gc1, double width, Qt::PenStyle ps,\
             Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
             Qt::GlobalColor gc2, Qt::BrushStyle bs):\
    painter(parent),shape {arg},
    pen(gc1,width,ps,pcs,pjs),\
    brush(gc2,bs)
{}

Shape::Shape(QPaintDevice *parent, ShapeType arg,\
             QPen rhsPen, QBrush rhsBrush):\
    painter(parent), shape {arg},\
    pen(rhsPen), brush (rhsBrush)
{

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

void Shape::defaultStyle()
{
    pen.setColor(Qt::black);
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

void Shape::write(ostream &os){
    os << SHAPE_IDENTIFIERS[shape];
}

void Shape::read(istream &is){

}

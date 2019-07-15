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

{
    painter.setPen(pen);
    painter.setBrush(brush);
}
Shape::Shape(QPaintDevice *parent, ShapeType arg,\
             QPen rhsPen, QBrush rhsBrush):\
    painter(parent), shape {arg},\
    pen(rhsPen), brush (rhsBrush)
{
    painter.setPen(pen);
    painter.setBrush(brush);
}

Shape::Shape(QPaintDevice *parent, const ShapeBuffer& buffer):painter(parent)
{
    shape = buffer.shape;
    brush = buffer.brush;
    pen = buffer.pen;
    painter.setPen(pen);
    painter.setBrush(brush);
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

void Shape::write(std::ostream &os){
    os << shapeId << std::endl;
    std::string shapeTypeStr;
    if(shape == LINE){
        shapeTypeStr = SHAPE_IDENTIFIERS[0];
    }
    os << shapeTypeStr << std::endl;
}

void Shape::read(std::istream &is){
   std::string readShapeTypeStr;
   is >> readShapeTypeStr;//ok to use >> operator as shapes are just one word
   this->shape = getShapeFromString(readShapeTypeStr);
   is >> this->shapeId;

}

ShapeType Shape::getShapeFromString(std::string name){
    for(int i = 0; i < 6; i++){
        if(name.compare(SHAPE_IDENTIFIERS[i]) == 0){
            return static_cast<ShapeType>(i);
        }
    }
    return LINE;
}

#include "shape.h"

//Shape::Shape():  qpainter{nullptr},
//    shapeId{0},shape{NONE}, pen{NONE},brush{NONE}
//{
//}

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
//const Shape::QPencil& get_pencil()const{
//    return pencil;
//}

void Shape::set_shape(ShapeType shapeIn){
    shape=shapeIn;
}

void Shape::set_pen(Qt::GlobalColor , int penWidth, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle )
{

   pen.setColor(penColor);
   pen.setWidth(penWidth);
   pen.setStyle(penStyle);
   pen.setCapStyle(penCapStyle);
   pen.setJoinStyle(penJoinStyle);

}
//void set_pencil(Qt::GlobalColor);


void Shape::set_brush(Qt::GlobalColor, Qt::BrushStyle)
{
    brush.setColor(brushColor);
    brush.setStyle(brushStyle);
}

QPainter& Shape::get_qpainter()
{
    return qpainter;
}
//void default_style();


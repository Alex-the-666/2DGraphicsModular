#include "shapebuffer.h"

ShapeBuffer::ShapeBuffer()
{
    shape=LINE;
}

void ShapeBuffer::reset()
{
    shape=LINE;
    qPointVector.resize(0);
    qRect.setRect(0,0,0,0);
    //qPolygon.set
    //I don't know how to use QPolygon
    defaultStyle();

}

void ShapeBuffer::defaultStyle()
{
    pen.setColor(Qt::black);
    pen.setWidth(0);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::RoundJoin);
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    //Going to need default QFont

}

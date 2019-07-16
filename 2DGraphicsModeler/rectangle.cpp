#include "rectangle.h"

Rectangle::Rectangle (QPaintDevice* parent, ShapeBuffer arg) :
    Shape (parent, arg)
{
    QRect qRect= arg.getQRect();
    /*SETTING CENTER COORDINATES FROM 'SHAPEBUFFER' ARG*/
    x = qRect.x();
    y = qRect.y();

    /*SETTING DIMENSIONS FROM 'SHAPEBUFFER' ARG*/
    width = qRect.width();
    height = qRect.height();
}

Rectangle::~Rectangle () {}

double Rectangle::area () const
{
    return height * width;
}

double Rectangle::perimeter () const
{
    return (2*height) + (2*width);
}

void Rectangle::draw (int x, int y)
{
    QPainter& painter = getQPainter();
    painter.setPen(getPen());
    painter.setBrush(getBrush());

    /* DRAW SHAPE BASED ON INTERNAL PRIVATE VARIABLES */
    painter.drawRect (x,y,width,height);
    painter.end();
}

void Rectangle::draw(QPaintDevice * parent)
{
    QPainter& painter = getQPainter();
    painter.begin(parent);
    painter.setPen(getPen());
    painter.setBrush(getBrush());

    /* DRAW SHAPE BASED ON INTERNAL PRIVATE VARIABLES */
    painter.drawRect(x,y,width,height);
    painter.end();
}

void Rectangle::move (int px, int py)
{
    /*SANITY CHECK: MAKES SURE NEW/PROPOSED CENTER OF SHAPE + CURRENT DIMENSIONS
      DO NOT EXCEED BOUNDARIES OF CANVAS */
    if ( (px + 0.5*width) > 1000 || (py + 0.5*height) > 500 )
    {
        x = px;
        y = py;
    }
}

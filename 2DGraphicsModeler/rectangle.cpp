#include "rectangle.h"

Rectangle::Rectangle (QPaintDevice* parent, ShapeBuffer arg) :
    Shape (parent, arg)
{
    /*SETTING CENTER COORDINATES FROM 'SHAPEBUFFER' ARG*/
    x = arg.qRect.x();
    y = arg.qRect.y();

    /*SETTING DIMENSIONS FROM 'SHAPEBUFFER' ARG*/
    width = arg.qRect.width();
    height = arg.qRect.height();
}

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

    /* DRAW SHAPE BASED ON INTERNAL PRIVATE VARIABLES */
    painter.drawRect (x,y,width,height);
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

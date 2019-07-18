#include "rectangle.h"

Rectangle::Rectangle (const ShapeBuffer& arg) :\
    Shape (arg)
{
    QRect qRect= arg.getQRect();
    /*SETTING CENTER COORDINATES FROM 'SHAPEBUFFER' ARG*/
    x = qRect.x();
    y = qRect.y();

    /*SETTING DIMENSIONS FROM 'SHAPEBUFFER' ARG*/
    width = qRect.width();
    height = qRect.height();

    stringID = QString::number(arg.getShapeID());
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
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());

    /* DRAW SHAPE BASED ON INTERNAL PRIVATE VARIABLES */
    getQPainter()->drawRect (x,y,width,height);
}

void Rectangle::draw()
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());

    /* DRAW SHAPE BASED ON INTERNAL PRIVATE VARIABLES */
     drawID();
     getQPainter()->drawRect (x,y,width,height);

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

void Rectangle::drawID()
{
    const int VERTICAL_BUFFER = 5;
    getQPainter()->drawText(x, y - VERTICAL_BUFFER, stringID);
}

#include "rectangle.h"

Rectangle::Rectangle (const ShapeBuffer& arg) :\
    Shape (arg)
{
  /*testing purposes: ASSIGN DIMENSIONS FROM SHAPEBUFFER OBJECT TO INTERNAL QRECT*/
  xyWH = arg.getQRect ();

  /*ASSIGN DIMENSIONS FROM SHAPEBUFFER OBJECT TO INTERNAL VARIABLES*/
  x = xyWH.x();
  y = xyWH.y();
  width = xyWH.width();
  height = xyWH.height();

  stringID = QString::number(arg.getShapeID());
}

Rectangle::~Rectangle () {}

void Rectangle::setShapeBuffer(ShapeBuffer &temp)
{
    Shape::setShapeBuffer(temp);
    temp.qRect.setRect(x,y,width,height);
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
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());

    /* DRAW SHAPE BASED ON INTERNAL PRIVATE VARIABLES */
    getQPainter()->drawRect (x,y,width,height);
}

void Rectangle::draw()
{
  getQPainter()->setPen(getPen());
  getQPainter()->setBrush(getBrush());

  /* DRAW SHAPE BASED ON INTERNAL VARIABLES */
   drawID();
   getQPainter()->drawRect (x, y, width, height);
   passQPainter(nullptr);
 }

void Rectangle::move (int px, int py)
{
  /* BOUNDARY CHECKING */
  if (!(px + width > 1000 || py + height > 500))
  {
      x = px;
      y = py;
  }
}

void Rectangle::drawID()
{
  /* testing purposes */
  QString temp = QString::number (x) + " " + QString::number (y);

    const int VERTICAL_BUFFER = 5;
    getQPainter()->drawText(x, y - VERTICAL_BUFFER, stringID);
}

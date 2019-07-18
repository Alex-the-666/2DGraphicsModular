#include "ellipse.h"
#include <QtMath>

Ellipse::Ellipse(const ShapeBuffer& arg): Shape(arg)
{
  /*ASSIGNING DIMENSIONS FROM SHAPEBUFFER OBJECT TO INTERNAL QRECT*/
  myRect = arg.getQRect();

  /*ASSIGNING DIMENSIONS TO INTERNAL VARIABLES*/
  x = myRect.x();
  y = myRect.y();
  radius1 = myRect.width();
  radius2 = myRect.height();

  stringID = QString::number (arg.getShapeID());
}

void Ellipse::setShapeBuffer(ShapeBuffer & temp)
{
    Shape::setShapeBuffer(temp);
    temp.qRect = myRect;
}

void Ellipse::draw(const int, const int)
{
  getQPainter()->setPen(getPen());
  getQPainter()->setBrush(getBrush());

  /*DRAW USING INTERNAL QRECT*/
  drawID ();
  getQPainter()->drawEllipse(myRect);
  passQPainter(nullptr);
}

void Ellipse::draw()
{
  getQPainter()->setPen(getPen());
  getQPainter()->setBrush(getBrush());

  /*DRAW USING INTERNAL VARIABLES*/
  drawID ();
  getQPainter()->drawEllipse(x, y, radius1, radius2);
  passQPainter(nullptr);
}

void Ellipse::move(const int x, const int y)
{
    if(radius1 + x < 1000 && radius1 + y < 500 &&\
       radius2 + x < 1000 && radius2 + y < 500 )
    {
        this -> x = x;
        this -> y = y;
    }
}

double Ellipse::perimeter() const
{
    return M_PI * ((3 *(radius1 + radius2)) - sqrt((3*radius1 + radius2)*(radius1 + (3 * radius2))));
}

double Ellipse::area() const
{
    return M_PI * radius1 * radius2;
}

void Ellipse::drawID()
{
  /* testing purposes */
  QString temp = QString::number (x) + " " + QString::number (y);

  const int VERTICAL_BUFFER = 5;
  getQPainter()->drawText(x, y - VERTICAL_BUFFER, stringID);
}

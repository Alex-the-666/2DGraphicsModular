#include "square.h"

Square::Square(const ShapeBuffer& arg): Shape(arg)
{
    QRect qRect = arg.getQRect();
    side = qRect.width();
    side = qRect.height();

    _x = qRect.x();
    _y = qRect.y();
    stringID = QString::number(arg.getShapeID());
}

void Square::setShapeBuffer(ShapeBuffer &temp)
{
    Shape::setShapeBuffer(temp);
    temp.qRect.setRect(_x,_y,side,side);
}
void Square::draw(const int, const int)
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->drawRect(_x,_y,side,side);
    getQPainter()->end();
}

void Square::draw()
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());

    drawID();
    getQPainter()->drawRect(_x,_y,side,side);
    passQPainter(nullptr);
}

double Square::area() const
{
    return side*side;
}

void Square::move(int x, int y)
{
  /* BOUNDARY CHECKING */
  if (!(x + side > 1000 || y + side > 500))
  {
     _x = x;
     _y = y;
  }
}

double Square::perimeter() const
{
  return 4*side;
}

void Square::drawID()
{
  /* testing purposes */
  QString temp = QString::number (_x) + " " + QString::number (_y);

    const int VERTICAL_BUFFER = 5;
    getQPainter()->drawText(_x, _y - VERTICAL_BUFFER, stringID);
}

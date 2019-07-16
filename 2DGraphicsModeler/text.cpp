#include "text.h"

// just need the qrect for the constructor: x, y, height, width

Text::Text(QPaintDevice * parent, const ShapeBuffer& arg) : Shape(parent, arg)
{
    QRect qRect = arg.getQRect();
      x = qRect.x();
      y = qRect.x();
      wide = qRect.width();
      tall = qRect.height();
      font = arg.getQFont();
      alignFlag = arg.getAlignFlag();
      qStringText = arg.getQStringText();
}

void Text::draw(const int x, const int y){

      QPainter& painter = getQPainter();
      const QRect rectangle = QRect(x, y, wide, tall);
      painter.setPen(getPen());
      painter.setBrush(getBrush());

      painter.drawText(rectangle, alignFlag, qStringText);
      painter.end();
}

void Text::draw(QPaintDevice * parent)
{
    QPainter& painter = getQPainter();
    painter.begin(parent);
    const QRect rectangle = QRect(x, y, wide, tall);
    painter.setPen(getPen());
    painter.setBrush(getBrush());

    painter.drawText(rectangle, alignFlag, qStringText);
    painter.end();
}

void Text::move(const int x, const int y){

      if(wide + x < 1000 && wide + y < 500 &&\
         tall + x < 1000 && tall + y < 500 )
      {
          this -> x = x;
          this -> y = y;
      }
}

double Text::area () const{

      return (wide * tall);
}

double Text::perimeter() const{

      return (2 * (wide + tall));

}

#include "text.h"

// just need the qrect for the constructor: x, y, height, width

Text::Text(QPaintDevice * parent, const ShapeBuffer& arg) : Shape(parent, arg)
{
      x = arg.qRect.x();
      y = arg.qRect.x();
      wide = arg.qRect.width();
      tall = arg.qRect.height();
      font = arg.font;
      alignFlag = arg.alignFlag;
}

void Text::draw(const int x, const int y){

      QPainter& painter = getQPainter();
      const QRect rectangle = QRect(x, y, wide, tall);

     painter.drawText(rectangle, Qt::AlignVCenter, QString("Test"));
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

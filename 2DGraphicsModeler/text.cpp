#include "text.h"

// just need the qrect for the constructor: x, y, height, width


Text::Text(QPaintDevice * parent, const ShapeBuffer& arg) : Shape(parent, arg)
{
      x = arg.qRect.x();
      y = arg.qRect.x();
      wide = arg.qRect.width();
      tall = arg.qRect.height();
}

void Text::draw(const int x, const int y){

      QPainter& painter = getQPainter();
      const QRect rectangle = QRect(x, y, wide, tall);

     painter.drawText(rectangle, Qt::AlignVCenter, QString("Test"));
}

void Text::move(const int x, const int y){
      const int MAXX = 1000;
      const int MAXY = 500;

      if(wide + x < MAXX && wide + y < MAXY &&\
         tall + x < MAXX && tall + y < MAXY )
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

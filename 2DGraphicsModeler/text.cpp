#include "text.h"

// just need the qrect for the constructor: x, y, height, width

Text::Text(QPaintDevice * parent, const ShapeBuffer& arg) : Shape(parent, arg)
{
      x = arg.qRect.x();
      y = arg.qRect.y();
      wide = arg.qRect.width();
      tall = arg.qRect.height();
}

void Text::draw(const int x, const int y){

      QPainter& painter = getQPainter();

      const QRect rectangle = QRect(x, y, wide, tall);

     painter.drawText(rectangle, Qt::AlignVCenter, QString("Test"));
}

void Text::move(const int x1, const int y1){
      const int MAXX = 1000;
      const int MAXY = 500;

      if(wide + x1 < MAXX && wide + y1 < MAXY &&\
         tall + x1 < MAXX && tall + y1 < MAXY )
      {
          x = x1;
          y = y1;
      }
}

double Text::area () const{

      return (wide * tall);
}

double Text::perimeter() const{

      return (2 * (wide + tall));

}

Text::~Text(){}

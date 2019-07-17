#include "text.h"

// just need the qrect for the constructor: x, y, height, width
Text::Text(QPaintDevice * parent, const ShapeBuffer& arg) : Shape(parent, arg) {
      
      QRect qRect = arg.getQRect();
      
      x = arg.qRect.x();
      y = arg.qRect.y();
      wide = arg.qRect.width();
      tall = arg.qRect.height();
}

void Text::draw(const int x, const int y){

      QPainter& painter = getQPainter();

      const QRect rectangle = QRect(x, y, wide, tall);

      QFont font = painter.font();
          font.setPixelSize(14);
          font.setFamily("Arial");
          painter.setFont(font);

      QColor color(0, 0, 255, 1);   //RGBA

      QPen pen = painter.pen();
          pen.setStyle(Qt::SolidLine);
          pen.setColor(color);
          painter.setPen(pen);

      QRect boundingRect;

          painter.drawText(rectangle, Qt::AlignVCenter, QObject::tr("CS1C: Ratatouille Group Project"), &boundingRect);
}

void Text::move(const int x1, const int y1) {
      const int MAXX = 1000;    //largest x-axis value to remain on screen
      const int MAXY = 500;     //largest y-axis value to remain on screen

          if (wide + x1 < MAXX && wide + y1 < MAXY && tall + x1 < MAXX && tall + y1 < MAXY ) {
              x = x1;
              y = y1;
              //draw(x, y)?
          }
}

double Text::area () const {

      return (wide * tall);
}

double Text::perimeter() const {

      return (2 * (wide + tall));
}

Text::~Text(){}

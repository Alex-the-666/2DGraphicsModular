#include "text.h"

// just need the qrect for the constructor: x, y, height, width
Text::Text(const ShapeBuffer& arg) : Shape(arg) {
      myRect = arg.getQRect();
      QRect qRect = arg.getQRect();

      x = qRect.x();
      y = qRect.y();
      wide = qRect.width();
      tall = qRect.height();
      alignFlag = arg.getAlignFlag();
      myQString = arg.getQStringText();
      font = arg.getQFont();

}

void Text::draw(const int x, const int y){
/*
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->setFont(font); */
    const QRect rectangle = QRect(x, y, wide, tall);

/*     QFont font = painter.font();
          font.setPixelSize(14);
          font.setFamily("Arial");
          painter.setFont(font);
  QColor color(0, 0, 255, 1);   //RGsBA*/

      //QRect boundingRect;
      getQPainter()->drawText(myRect,alignFlag,myQString);
     passQPainter(nullptr);
}

void Text::draw(){

    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->setFont(font);
    //const QRect rectangle = QRect(x, y, wide, tall);
    //QRect boundingRect;
    getQPainter()->drawText(myRect,alignFlag,myQString);
    passQPainter(nullptr);
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

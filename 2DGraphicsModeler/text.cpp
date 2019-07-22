#include "text.h"

// just need the qrect for the constructor: x, y, height, width
Text::Text(const ShapeBuffer& arg) : Shape(arg) {
      myRect = arg.getQRect();

      x = myRect.x();
      y = myRect.y();
      wide = myRect.width();
      tall = myRect.height();
      alignFlag = arg.getAlignFlag();
      myQString = arg.getQStringText();
      font = arg.getQFont();

}

void Text::setShapeBuffer(ShapeBuffer &temp)
{
    Shape::setShapeBuffer(temp);
    temp.alignFlag=alignFlag;
    temp.qStringText=myQString;
    temp.font = font;
    temp.qRect = myRect;
}

void Text::draw(const int, const int){

    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->setFont(font);
    getQPainter()->drawText(myRect,alignFlag,myQString);
}

void Text::draw(){

    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->setFont(font);
    getQPainter()->drawText(myRect,alignFlag,myQString);

    QString temp = QString::number (x) + " " + QString::number (y);
    getQPainter()->drawText(myRect.x(), myRect.y() - 5, QVariant(Shape::getID()).toString());
    passQPainter(nullptr);
}

void Text::move(const int x1, const int y1) {
      const int MAXX = 1000;    //largest x-axis value to remain on screen
      const int MAXY = 500;     //largest y-axis value to remain on screen

//          if (wide + x1 < MAXX && wide + y1 < MAXY && tall + x1 < MAXX && tall + y1 < MAXY ) {
//              x = x1;
//              y = y1;
//              //draw(x, y)?
//          }
    /* BOUNDARY CHECKING */
    if (!(x1 + wide > MAXX || y1 + tall > MAXY))
    {
        myRect.moveTo(x1,y1);
    }

}

double Text::area () const {

      return (wide * tall);
}

double Text::perimeter() const {

      return (2 * (wide + tall));
}

Text::~Text(){}

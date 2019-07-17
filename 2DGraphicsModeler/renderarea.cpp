#include "renderarea.h"
const QSize minSize(1000,500);

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(minSize);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    move(0, 36);
}

void RenderArea::createShapeBuffer(QTextStream)
{
   buffer.resize(0);
    while(!is.atEnd())
    {
        ShapeBuffer x;
        x.readIn(is);
        if(!is.atEnd())
            buffer.push_back(x);

        is.readLine();//get rid of the space
        is.flush();
    }
   shapeBufferReady=true;
}

void RenderArea::transferToShapes()
{
   for(auto sbIt = buffer.begin();\
       sbIt != buffer.end(); sbIt++)
   {
       ShapeType shapeType = sbIt->getShape();
       switch(shapeType)
       {
       case LINE: shapeVector.push_back(new Line(*sbIt));
           break;
       case POLYLINE: shapeVector.push_back(new PolyLine(*sbIt));
           break;
       case POLYGON: shapeVector.push_back(new Polygon(*sbIt));
           break;
       case RECTANGLE: shapeVector.push_back(new Rectangle(*sbIt));
           break;
       case SQUARE: shapeVector.push_back(new Square(*sbIt));
           break;
       case ELLIPSE: shapeVector.push_back(new Ellipse(*sbIt));
           break;
       case CIRCLE:shapeVector.push_back(new Circle(*sbIt));
           break;
       case TEXT: shapeVector.push_back(new Text(*sbIt));
           break;
       }//end of switch

   }// end of for loop

}

void RenderArea::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    if(shapeBufferReady == true)
    {
          transferToShapes();
          shapeBufferReady=false;
    }
        for (auto it = shapeVector.begin(); it != shapeVector.end(); it++)
        {
            (*it)->passQPainter(&painter);
            (*it)->draw();
        }

}

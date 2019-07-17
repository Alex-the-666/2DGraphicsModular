#include "renderarea.h"
const QSize minSize(1000,500);

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(minSize);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    move(0, 36);
}

void RenderArea::createShapeBuffer(QTextStream& is)
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
       case LINE: shapeVector.push_back(new Line(&dummy,*sbIt));
           break;
       case POLYLINE: shapeVector.push_back(new PolyLine(&dummy,*sbIt));
           break;
       case POLYGON: shapeVector.push_back(new Polygon(&dummy,*sbIt));
           break;
       case RECTANGLE: shapeVector.push_back(new Rectangle(&dummy,*sbIt));
           break;
       case SQUARE: shapeVector.push_back(new Square(&dummy,*sbIt));
           break;
       case ELLIPSE: shapeVector.push_back(new Ellipse(&dummy,*sbIt));
           break;
       case CIRCLE:shapeVector.push_back(new Circle(&dummy,*sbIt));
           break;
       case TEXT: shapeVector.push_back(new Text(&dummy,*sbIt));
           break;
       }//end of switch

   }// end of for loop

}

void RenderArea::paintEvent(QPaintEvent*)
{
    if(shapeBufferReady == true)

    {
          transferToShapes();

          for (auto it = shapeVector.begin(); it != shapeVector.end(); it++)
          {
              it=it+3;
              (*it)->draw(0,0);
              (*it)->draw(this);

          }
          shapeBufferReady= false;


    }
    else {
        for (auto it = shapeVector.begin(); it != shapeVector.end(); it++)
        {
                it= it+3;


            (*it)->draw(this);

        }
    }

    //shapeVector.resize(0);



}

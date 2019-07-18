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

custom::vector<Shape*>& RenderArea::getShapeVector(){
    return shapeVector;
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

void RenderArea::readOut(QTextStream& textStream)
{
    for (auto it = buffer.begin(); it != buffer.end(); it++)
    {
        textStream << "ShapeId: " << (*it).getShapeID() << endl
                   << "ShapeType: " << (*it).getShape() << endl
                   << "Shape Dimensions: ";
        switch ((*it).getShape())
        {
            case LINE: textStream << (*it).getQPointOne().rx() << ", "
                                  << (*it).getQPointOne().rx() << ", "
                                  << (*it).getQPointTwo().rx() << ", "
                                  << (*it).getQPointTwo().ry();
                       break;

            case POLYLINE:  for (int i = 0; i < it->getQPolygon().size(); i++)
                            {
                                textStream << (*it).getQPolygon().point(i).rx();

                            }
        }
    }
}


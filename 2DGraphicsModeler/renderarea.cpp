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
       ShapeType shapeType = sbIt->shape;
       switch(shapeType)
       {
       case LINE: shapeVector.push_back(new Line(this,*sbIt));
           break;
       case POLYLINE: shapeVector.push_back(new PolyLine(this,*sbIt));
           break;
       case POLYGON: shapeVector.push_back(new Polygon(this,*sbIt));
           break;
       case RECTANGLE: shapeVector.push_back(new Rectangle(this,*sbIt));
           break;
       case SQUARE: shapeVector.push_back(new Square(this,*sbIt));
           break;
       case ELLIPSE: shapeVector.push_back(new Ellipse(this,*sbIt));
           break;
       case CIRCLE:shapeVector.push_back(new Circle(this,*sbIt));
           break;
       case TEXT: shapeVector.push_back(new Text(this,*sbIt));
           break;
       }//end of switch

   }// end of for loop
    buffer.resize(0);//reset the shape buffer
}






void RenderArea::paintEvent(QPaintEvent*)
{
    Line temp(this);
    temp.setPen(Qt::red,4,Qt::SolidLine,Qt::FlatCap,Qt::MiterJoin);

    temp.setPointOne(10,10);
    temp.setPointTwo(900,900);
    temp.draw(0,0);
    if(shapeBufferReady == true)

    {

        //  transferToShapes();
    }


    for (auto it = shapeVector.begin();\
         it != shapeVector.end(); it++)
        (*it)->draw(0,0);

    shapeBufferReady=false;



}

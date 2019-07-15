#include "renderarea.h"
const QSize minSize(1000,500);

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(minSize);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    move(0, 36);


}

void RenderArea::passBuffer(const ShapeBuffer &fromParent)
{
    buffer = fromParent;

}

void RenderArea::tripFlag()
{
 add = true;
}

void RenderArea::addShape(const ShapeBuffer& buffer)
{
    switch(buffer.shape)
    {
    case LINE:
    {
        Line* temp = new Line(this,buffer);
        shapeVector.push_back(temp);
        temp = nullptr;
    }
        break;
    case POLYLINE:
       {

       }
        break;
    case POLYGON:
        break;
    case RECTANGLE:
        break;
    case ELLIPSE:
        break;
    case TEXT:
        break;
    }
}

custom::vector<Shape*> RenderArea::getShapeVector(){
   return shapeVector;
}

void RenderArea::testAddLines()
{
    if(add == true)
    {
    Line *line1 = new Line(this);
    line1->setDimension(10,10,100+offset,40+offset);

    shapeVector.push_back(line1);
    if(offset<300)
        offset +=30;
    }
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Line asdf(this);
    polyLine obj(this);
    asdf.setDimension(10,10,400,400);
   // asdf.draw(100,100);
    Line* aser = &asdf;
    addShape(aser);
    custom::vector<Shape*>::iterator it = shapeVector.begin();
    Shape* qwer =(*it);
    //qwer->draw(34,34);
    //Crashing here.
  //for(int i =0; i<5;i++)
  //{}
    testAddLines();
    for (custom::vector<Shape*>::iterator it = shapeVector.begin();\
         it != shapeVector.end(); it++)
        (*it)->draw(0,0);

}

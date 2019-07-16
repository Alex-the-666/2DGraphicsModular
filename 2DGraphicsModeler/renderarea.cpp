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

void RenderArea::addShape(const ShapeBuffer&)
{
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

void RenderArea::paintEvent(QPaintEvent*)
{
    Line asdf(this);
    PolyLine obj(this);

    testAddLines();
    for (custom::vector<Shape*>::iterator it = shapeVector.begin();\
         it != shapeVector.end(); it++)
        (*it)->draw(0,0);

}

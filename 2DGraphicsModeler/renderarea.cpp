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
        buffer.push_back(x);

        is.readLine();//get rid of the space
    }
}



void RenderArea::addShape(const ShapeBuffer&)
{
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

    testAddLines();
    for (custom::vector<Shape*>::iterator it = shapeVector.begin();\
         it != shapeVector.end(); it++)
        (*it)->draw(0,0);

}

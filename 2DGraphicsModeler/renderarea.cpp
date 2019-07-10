#include "renderarea.h"
const QSize minSize(1000,500);

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(minSize);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    move(0, 36);


}

void RenderArea::addShape(Shape* rhs)
{
    switch(rhs->getShape())
    {
    case LINE:
    {
        Line* temp = new Line(this, rhs->getPen(), rhs->getBrush());
        temp->setDimension(dynamic_cast<Line*>(rhs)->getQPointOne(),\
                           dynamic_cast<Line*>(rhs)->getQPointTwo());
        shapeVector.push_back(temp);
        temp = nullptr;
    }

        break;
    case POLYLINE:
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

void RenderArea::paintEvent(QPaintEvent *event)
{
    if(arthurTest==true)
    {

        Line *line1 = new Line(this);
        line1->setDimension(10,10,100+offset,40+offset);
        addShape(line1);


        shapeVector.push_back(line1);
        line1 = nullptr;

        arthurTest=false;
        if(offset<300)
            offset +=30;
}

     custom::vector<Shape*>::iterator it;
    for (it = shapeVector.begin(); it != shapeVector.end(); it++)
    {
        (*it)->draw(0,0);
    }

}

#include "renderarea.h"
const QSize minSize(1000,500);

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(minSize);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void RenderArea::addShape(Shape* rhs)
{
    switch(rhs->getShape())
    {
    case LINE:
    {
        Line* temp = new Line(this, LINE, rhs->getPen(), rhs->getBrush());
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
    Line line1(this);
    line1.setShape(LINE);
    line1.setDimension(10,10,400,400);
    line1.draw(100,100);
    addShape(&line1);
    custom::vector<Shape*>::iterator it = shapeVector.begin();
    (*it)->draw(30,30);

    //Crashing here.
}

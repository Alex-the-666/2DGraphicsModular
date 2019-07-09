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
    Line asdf(this);
    asdf.setDimension(10,10,400,400);
   // asdf.draw(100,100);
    Line* aser = &asdf;
    addShape(aser);
    custom::vector<Shape*>::iterator it = shapeVector.begin();
    Shape* qwer =(*it);
    //qwer->draw(34,34);
    //Crashing here.
}

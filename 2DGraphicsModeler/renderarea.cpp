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
       {
        polyLine* temp1 = new polyLine(this, POLYLINE, rhs->getPen(), rhs->getBrush());

        temp1->set_point(QPoint(2,7));
         temp1->set_point(QPoint(6,38));
          temp1->set_point(QPoint(8,25));
           temp1->set_point(QPoint(2,73));
            temp1->set_point(QPoint(21,12));

            temp1->draw(shapeDimensions);


        temp1 = nullptr;
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
}

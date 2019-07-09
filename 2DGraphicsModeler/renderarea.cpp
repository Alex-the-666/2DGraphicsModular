#include "renderarea.h"
const QSize minSize(1000,500);

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(minSize);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void RenderArea::addShape(const Shape & rhs)
{
    Shape* temp = nullptr;
    switch(rhs.getShape())
    {
    case LINE:
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

    shapeVector.push_back( nullptr);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Line test(this);
    test.draw(3,4);
}

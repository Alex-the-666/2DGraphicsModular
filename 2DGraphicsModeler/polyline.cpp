#include "polyline.h"

Polyline::Polyline(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
{

    qPointArray = new QPoint[3];
}

void Polyline::draw(const int, const int)
{


}

void Polyline::move(const int, const int)
{

}

double Polyline::area() const
{

}

double Polyline::perimeter() const
{

}



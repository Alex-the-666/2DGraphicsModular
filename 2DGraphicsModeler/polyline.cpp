#include "polyline.h"

Polyline::Polyline(QPaintDevice *parent, ShapeBuffer arg): Shape(parent, arg)
{
    qPointVector = arg.qPointVector;
}

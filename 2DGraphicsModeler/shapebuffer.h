#ifndef SHAPEBUFFER_H
#define SHAPEBUFFER_H

#include "vector.h"
#include <QBrush>
#include <QPen>
#include <QFont>

enum ShapeType{LINE, POLYLINE, POLYGON, RECTANGLE, ELLIPSE, TEXT};

class ShapeBuffer
{

public:
    ShapeBuffer();


    void reset();
    void defaultStyle();

    //buffer variables
    ShapeType shape;
    custom::vector<QPoint> qPointVector;
    QRect qRect;
    QPolygon qPolygon;

    QBrush brush;
    QPen pen;
    QFont font;


};

#endif // SHAPEBUFFER_H

#ifndef SHAPEBUFFER_H
#define SHAPEBUFFER_H

#include "vector.h"
#include <QBrush>
#include <QPen>
#include <QFont>
#include <QFile>
#include <QTextStream>

enum ShapeType{LINE, POLYLINE, POLYGON, RECTANGLE,\
               SQUARE, ELLIPSE, CIRCLE, TEXT};

class ShapeBuffer
{

public:
    ShapeBuffer();


    void reset();
    void defaultStyle();

    void readIn(QTextStream&);

    //buffer variables
    int shapeID=0;
    ShapeType shape;
    custom::vector<QPoint> qPointVector;
    QRect qRect;
    QPolygon qPolygon;

    QBrush brush;
    QPen pen;
    QFont font;


};

#endif // SHAPEBUFFER_H

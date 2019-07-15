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
class MyException
{};

class ShapeBuffer
{

public:
    ShapeBuffer();

    void reset();
    void defaultStyle();

    void readIn(QTextStream&);
protected:
    ShapeType setShape(QString&) const;
    //Pen Width
    Qt::PenStyle setPenStyle(QString&)const;
    Qt::PenCapStyle setPenCapStyle(QString&)const;
    Qt::PenJoinStyle setPenJoinStyle(QString&)const;
    Qt::GlobalColor setColor(QString&)const;
    Qt::BrushStyle setBrushStyle(QString&)const;
    Qt::AlignmentFlag setTextAlignment(QString&)const;
    //Textpoint size
    //TextFontFamily
    QFont::Style getTextFontStyle(QString&)const;
    QFont::Weight getTextFontWeight(QString&)const;
private:
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

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

    int shapeID=0;
    ShapeType shape;

    QPoint one,two;
    QRect qRect;
    QPolygon qPolygon;

    QBrush brush;
    QPen pen;

    QFont font;
    QString qStringText;
    Qt::AlignmentFlag alignFlag;
protected:
    int setInt(QString&)const;
    ShapeType setShape(QString&) const;

    Qt::PenStyle setPenStyle(QString&)const;
    Qt::PenCapStyle setPenCapStyle(QString&)const;
    Qt::PenJoinStyle setPenJoinStyle(QString&)const;
    Qt::GlobalColor setColor(QString&)const;
    Qt::BrushStyle setBrushStyle(QString&)const;
    Qt::AlignmentFlag setTextAlignment(QString&)const;

    QFont::Style getTextFontStyle(QString&)const;
    QFont::Weight getTextFontWeight(QString&)const;

     void getLineDimensions(QString&, QPoint&,QPoint&);
     QPolygon getPolygonDimensions(QString&)const;
     QRect getQRect(QString&)const;
     QRect getEllipseOrSquare(QString&)const;
     QString getQStringText(QString&)const;
};


#endif // SHAPEBUFFER_H

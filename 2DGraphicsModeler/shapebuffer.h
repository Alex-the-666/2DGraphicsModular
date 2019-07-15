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


    int setID(QString&)const;
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

     custom::vector<QPoint> getLineDimensions(QString&)const;
     QPolygon getPolygonDimensions(QString&)const;
     QRect getQRect(QString&)const;
     QRect getEllipseOrSquare(QString&)const;
     QString getQStringText(QString&)const;

    int shapeID=0;
    ShapeType shape;
    //Discontinue QPoint vector
    custom::vector<QPoint> qPointVector;
    //Don't use Qpoint vector
    QRect qRect;
    QPolygon qPolygon;

    QBrush brush;
    QPen pen;
    QFont font;
    QString qStringText;
};


#endif // SHAPEBUFFER_H

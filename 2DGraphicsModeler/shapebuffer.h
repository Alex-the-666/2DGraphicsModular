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
class MyException{};

class Shape;
class ShapeBuffer
{
friend class Shape;

public:
    ShapeBuffer();

    void readIn(QTextStream&);

    int getShapeID()const{return shapeID;}
    ShapeType getShape()const{return shape;}
    QPen getPen()const{return pen;}
    QBrush getBrush()const{return brush;}

    QPoint getQPointOne()const{return one;}
    QPoint getQPointTwo()const{return two;}
    QPolygon getQPolygon()const{return qPolygon;}
    QRect getQRect()const{return qRect;}

    QFont getQFont()const{return font;}
    QString getQStringText()const{return qStringText;}
    Qt::AlignmentFlag getAlignFlag()const{return alignFlag;}




protected:
    int setInt(QString&)const;
    ShapeType setShape(QString&) const;

    Qt::PenStyle setPenStyle(QString&)const;
    Qt::PenCapStyle setPenCapStyle(QString&)const;
    Qt::PenJoinStyle setPenJoinStyle(QString&)const;
    Qt::GlobalColor setColor(QString&)const;
    Qt::BrushStyle setBrushStyle(QString&)const;
    Qt::AlignmentFlag setTextAlignment(QString&)const;

    QFont::Style setTextFontStyle(QString&)const;
    QFont::Weight setTextFontWeight(QString&)const;

     void setLineDimensions(QString&, QPoint&,QPoint&);
     QPolygon setPolygonDimensions(QString&)const;
     QRect setQRect(QString&)const;
     QRect setEllipseOrSquare(QString&)const;
     QString setQStringText(QString&)const;
private:

     int shapeID=0;
     ShapeType shape;
     QBrush brush;
     QPen pen;

     QPoint one,two;
     QRect qRect;
     QPolygon qPolygon;

     QFont font;
     QString qStringText;
     Qt::AlignmentFlag alignFlag;
};


#endif // SHAPEBUFFER_H

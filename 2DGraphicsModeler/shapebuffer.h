#ifndef SHAPEBUFFER_H
#define SHAPEBUFFER_H

#include "vector.h"
#include <QBrush>
#include <QPen>
#include <QFont>
<<<<<<< HEAD
<<<<<<< HEAD
#include <QTextStream>

enum ShapeType{LINE, POLYLINE, POLYGON, RECTANGLE,\
               SQUARE, ELLIPSE, CIRCLE, TEXT};

class MyException
{};
=======

enum ShapeType{LINE,POLYLINE, POLYGON,RECTANGLE,ELLIPSE, TEXT};
>>>>>>> parent of cc1c7ec... Merge branch 'master' of https://github.com/Alex-the-666/2DGraphicsModular
=======
#include <QFile>
#include <QTextStream>

enum ShapeType{LINE, POLYLINE, POLYGON, RECTANGLE,\
               SQUARE, ELLIPSE, CIRCLE, TEXT};
class MyException
{};
>>>>>>> parent of 34d0ab8... Revert "Merge branch 'master' of https://github.com/Alex-the-666/2DGraphicsModular"

class ShapeBuffer
{

public:
    ShapeBuffer();

    void reset();
    void defaultStyle();

    void readIn(QTextStream&);
    //buffer variables
<<<<<<< HEAD
<<<<<<< HEAD
    int ShapeID=0;
=======

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
>>>>>>> parent of 34d0ab8... Revert "Merge branch 'master' of https://github.com/Alex-the-666/2DGraphicsModular"
    ShapeType shape;

=======
    ShapeType shape;
>>>>>>> parent of cc1c7ec... Merge branch 'master' of https://github.com/Alex-the-666/2DGraphicsModular
    custom::vector<QPoint> qPointVector;
    QRect qRect;
    QPolygon qPolygon;

    QBrush brush;
    QPen pen;
    QFont font;

<<<<<<< HEAD
       void readIn(QTextStream&);

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
=======

>>>>>>> parent of cc1c7ec... Merge branch 'master' of https://github.com/Alex-the-666/2DGraphicsModular
};


#endif // SHAPEBUFFER_H

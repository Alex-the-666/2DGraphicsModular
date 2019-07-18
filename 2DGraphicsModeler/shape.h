#ifndef SHAPE_H
#define SHAPE_H
#include <Qt>
#include <QFont>
#include <QPainter>
#include "vector.h"
#include <cmath>
#include "shapebuffer.h"

class Shape
{
public:
    Shape() = delete;
    Shape(Shape&) = delete;
    Shape& operator =(Shape&)= delete;

    Shape(QPaintDevice *): shapeId {0} {}
    Shape(const ShapeBuffer&);

    bool operator ==(Shape& rhs){return (shapeId==rhs.shapeId);}
    bool operator <=(Shape& rhs){return (shapeId<=rhs.shapeId);}


    virtual ~Shape();

    ShapeType getShape() const;
    const QBrush& getBrush()const;
    const QPen& getPen()const;
    void passQPainter(QPainter* arg ){painter=arg;}

    void setShape(ShapeType arg);
    void setPen(Qt::GlobalColor gc1, int width,\
                 Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs);
    void setBrush(Qt::GlobalColor gc2, Qt::BrushStyle bs);

    virtual void draw(const int x, const int y) = 0;
    virtual void draw()=0;
    virtual void move(const int x,const int y) = 0;
    virtual double area() const = 0;
    virtual double perimeter() const =0;
protected:
    QPainter* getQPainter();

private:
    QPainter* painter;
    int shapeId;
    ShapeType shape;
    QPen pen;
    QBrush brush;
};

#endif // SHAPE_H

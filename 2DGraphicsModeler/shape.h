#ifndef SHAPE_H
#define SHAPE_H
#include <Qt>
#include <QFont>
#include <QPainter>
#include "vector.h"
#include <cmath>
#include "shapebuffer.h"

const std::string SHAPE_IDENTIFIERS[] = {"LINE", "POLYLINE", "POLYGON", "RECTANGLE", "ELIPSE", "TEXT"};

class Shape
{
public:
    Shape() = delete;

    Shape(QPaintDevice *parent, const ShapeBuffer& buffer);

    Shape(Shape&) = delete;
    Shape& operator =(Shape&)= delete;

    virtual ~Shape();

    ShapeType getShape() const;
    const QBrush& getBrush()const;
    const QPen& getPen()const;


    void setShape(ShapeType arg);
    void setPen(Qt::GlobalColor gc1, int width,\
                 Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs);
    void setBrush(Qt::GlobalColor gc2, Qt::BrushStyle bs);

    void defaultStyle();

    virtual void draw(const int x, const int y) = 0;
    virtual void move(const int x,const int y) = 0;
    virtual double area() const = 0;
    virtual double perimeter() const =0;
protected:
    QPainter& getQPainter();


private:

    QPainter painter;
    int shapeId;
    ShapeType shape;
    QPen pen;
    QBrush brush;
};

#endif // SHAPE_H

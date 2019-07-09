#ifndef SHAPE_H
#define SHAPE_H
#include <Qt>
#include <QFont>
#include <QPainter>
#include "vector.h"

using namespace std;

enum ShapeType{LINE,POLYLINE, POLYGON,RECTANGLE,SQUARE, ELLIPSE};
class Shape
{
public:
    Shape() = delete;
    Shape(QPaintDevice* parent);

    virtual ~Shape();

    ShapeType get_shape() const;
    const QBrush& get_brush()const;
    const QPen& get_pen()const;


    void set_shape(ShapeType arg);
    void set_pen(Qt::GlobalColor, int width,\
                 Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void set_brush(Qt::GlobalColor, Qt::BrushStyle);

    void default_style();

    virtual void draw(const int x, const int y)=0;
   virtual void move(int xIn, int yIn) = 0;

protected:
    QPainter& get_qpainter();


private:
    QPainter painter;
    int shapeId;
    ShapeType shape;
    QPen pen;
    QBrush brush;
};

#endif // SHAPE_H

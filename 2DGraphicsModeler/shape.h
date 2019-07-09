#ifndef SHAPE_H
#define SHAPE_H
#include <Qt>
#include <QFont>
#include <QPainter>
#include "vector.h"

using namespace std;

struct ShapeDimensions
{
   int length;
   int width;
};

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
   //const QPencil& get_pencil()const;

    void set_shape(ShapeType shapeIn);
    void set_pen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
   // void set_pencil(Qt::GlobalColor);
    void set_brush(Qt::GlobalColor, Qt::BrushStyle);

    void default_style();

    virtual void draw(const int x, const int y)=0;
   virtual void move(int xIn, int yIn) = 0;
    virtual void area(ShapeDimensions dimensions)=0;
    virtual void perimeter(ShapeDimensions dimensions)=0;
protected:
    QPainter& get_qpainter();


private:
    QPainter painter;
    int shapeId;
    ShapeType shape;
    QPen pen;
    QBrush brush;


    ShapeDimensions dimensions;


    std::string shapeType;
   //vector<vector<int>> shapeDimensions;

    Qt::GlobalColor penColor;
    int penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;

    Qt::GlobalColor brushColor;
    Qt::BrushStyle brushStyle;

    std::string textString;
    Qt::GlobalColor textColor;
    Qt::AlignmentFlag textAlignment;
    int textPointSize;
    std::string textFontFamily;
    QFont::Style textFontStyle;
    QFont::Weight textFontWeight;
};

#endif // SHAPE_H

#include "line.h"
#include <cmath>

Line::Line(QPaintDevice *parent): Shape(parent),\
    one(0,0), two(100,100)
{

}

Line::Line(QPaintDevice* parent, Qt::GlobalColor gc1, double width,\
           Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
           Qt::GlobalColor gc2, Qt::BrushStyle bs):\
    Shape(parent, LINE, gc1, width,\
          ps, pcs, pjs,\
          gc2, bs),\
    one(0,0), two(100,100)
{}

Line::Line(QPaintDevice *parent,\
           QPen rhsPen, QBrush rhsBrush):\
        Shape(parent,LINE,rhsPen,rhsBrush),\
        one(0,0), two(100,100)
{}

Line::~Line()

{

}

void Line::setDimension(int x, int y, int x2, int y2)
{
    one.setX(x);
    one.setY(y);
    two.setX(x2);
    two.setY(y2);
}

void Line::setDimension(QPoint rhs1, QPoint rhs2)
{
    one = rhs1;
    two = rhs2;
}

QPoint Line::getQPointOne() const
{
    return one;
}

QPoint Line::getQPointTwo() const
{
 return two;
}

void Line::draw(const int x, const int y)
{
    QPainter& painter = getQPainter();
    painter.drawLine(one,two);

}

void Line::move(int x, int y)
{
    "I do nothing right now XD";
}

double Line::area() const
{
    return 0;
}

double Line::perimeter() const
{
    return sqrt(QPoint::dotProduct(one,two));
}

void Line::write(ostream &os){
    Line::write(os);
    os << one.x() << endl << one.y() << endl;
    os << two.x() << endl << two.y() << endl;
}

void Line::read(istream &is){
   Shape::read(is);
   int x1;
   int x2;
   int y1;
   int y2;
   is >> x1;
   is >> y1;
   is >> x2;
   is >>y2;
   setDimension(x1, y1, x2, y2);
}

#ifndef LINE_H
#define LINE_H

#include "shape.h"
class Line: public Shape
{
public:
    Line() = delete;
    Line (QPaintDevice *parent);
    Line(QPaintDevice* parent, Qt::GlobalColor gc1, double width,\
               Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs,\
               Qt::GlobalColor gc2, Qt::BrushStyle bs);
    Line(QPaintDevice *parent,\
         QPen rhsPen, QBrush rhsBrush);
    virtual ~Line()override;

    void setDimension(int x,int y,int x2,int y2);
    void setDimension(QPoint one,QPoint two);

    QPoint getQPointOne()const;
    QPoint getQPointTwo()const;

    void draw (const int x, const int y)override;
    void move(const int x,const int y) override;
    double area() const override;
    double perimeter() const override;
    void write(ostream& os) override;
    void read(istream& is) override;

private:
    QPoint one,two;
};

#endif // LINE_H

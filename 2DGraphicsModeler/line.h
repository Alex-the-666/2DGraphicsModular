#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line: public Shape
{
public:
    Line() = delete;
    Line(QPaintDevice *parent, const ShapeBuffer& buffer);
    virtual ~Line()override;

    void setDimension(int x,int y,int x2,int y2);
    void setDimension(QPoint one,QPoint two);

    QPoint getQPointOne()const;
    QPoint getQPointTwo()const;

    void draw (const int x, const int y)override;
    void draw(QPaintDevice * parent);
    void move(const int x,const int y) override;
    double area() const override;
    double perimeter() const override;
    void write(std::ostream& os) override;
    void read(std::istream& is) override;

private:
    QPoint one,two;
};

#endif // LINE_H

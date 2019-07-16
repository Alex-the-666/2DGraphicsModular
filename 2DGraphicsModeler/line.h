#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line: public Shape
{
public:
    Line() = delete;
    Line(QPaintDevice *parent, const ShapeBuffer& buffer);
    virtual ~Line()override;

    QPoint getQPointOne()const;
    QPoint getQPointTwo()const;

    void draw (const int x, const int y)override;
    void move(const int x,const int y) override;
    double area() const override;
    double perimeter() const override;

private:
    QPoint one,two;
};

#endif // LINE_H

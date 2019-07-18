#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line: public Shape
{
public:
    Line():Shape(){setShape(LINE);}
    Line(const ShapeBuffer& buffer);
    virtual ~Line()override;

    QPoint getQPointOne()const;
    QPoint getQPointTwo()const;

    void setPointOne(int x,int y){one.setX(x); one.setY(y);}
    void setPointTwo(int x,int y){two.setX(x); two.setY(y);}

    void draw (const int x, const int y)override;
    void draw()override;
    void move(const int x,const int y) override;
    double area() const override;
    double perimeter() const override;

    void drawID();

private:
    QPoint one,two;
    QString stringID;
};

#endif // LINE_H

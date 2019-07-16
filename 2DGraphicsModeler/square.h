#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"


class Square: public Shape
{
public:   
    Square() = delete;

    Square(QPaintDevice *parent, ShapeBuffer arg);

    virtual ~Square()override;

    void setDimension(int x, int y);

    void draw (const int x, const int y)override;
    void move(int x, int y) override;
    double area() const override;
    double perimeter() const override;

private:
};

#endif // SQUARE_H

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
private:
    int width;
    int height;
    int x;
    int y;

public:
    /*CONSTRUCTORS*/
    Rectangle () = delete;
    Rectangle (QPaintDevice* parent, const ShapeBuffer& arg);

    /*DESTRUCTOR*/
    ~Rectangle ()override;

    void draw (int, int)override;
    void draw(QPaintDevice*)override;

    void move (int, int)override;
    double area () const override;
    double perimeter () const override;
};

#endif // RECTANGLE_H

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
    QString stringID;

public:
    /*CONSTRUCTORS*/
    Rectangle () = delete;
    Rectangle (const ShapeBuffer& arg);

    /*DESTRUCTOR*/
    ~Rectangle ()override;

    void draw (int, int)override;
    void draw()override;

    void move (int, int)override;
    double area () const override;
    double perimeter () const override;

    void drawID();
};

#endif // RECTANGLE_H
